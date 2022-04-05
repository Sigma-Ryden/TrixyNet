#include <Trixy/Neuro/Core.hpp> // TrixyNet, Functional, Optimizer, Training, Serializer
#include <Trixy/Lique/Core.hpp> // Tensor, Linear

#include <Trixy/Container/Container.hpp> // Container

#include <Utility/util.hpp> // Timer, max, operator<<
#include <Utility/mnist_reader.hpp> // read_dataset

#include <cstdlib> // rand, srand, size_t
#include <ctime> // time
#include <iostream> // cin, cout
#include <iomanip> // setprecision, fixed
#include <fstream> // ifstream, ofstream
#include <vector> // vector

namespace tr = trixy;
namespace li = trixy::lique;

using namespace tr::functional;

using TrixyNet = tr::FeedForwardNet<li::Vector, li::Matrix, li::Linear, tr::Container, float>;

using TrixyNetFunctional = tr::Functional<TrixyNet>;
using TrixyNetTraining   = tr::train::Training<TrixyNet>;
using TrixyNetSerializer = tr::Serializer<TrixyNet>;

using size_type = std::size_t;

using util::operator<<;

template <class Net, class ImageType = typename Net::Vector>
void show_image(const ImageType& image) noexcept
{
    for(size_type i = 0; i < image.size(); ++i)
    {
        if(i % 28 == 0) std::cout << '\n';
        std::cout << (image(i) > 0.5 ? '#' : image(i) > 0.05 ? '*' : '.') << ' ';
    }
}

template <class Net, class ImageDataType = typename Net::template Container<typename Net::Vector>>
void show_image_batch(const ImageDataType& data) noexcept
{
    for(const auto& image : data)
    {
        show_image(image);
        std::cout << '\n';
    }
}

template <class Net, class ImageDataType = typename Net::template Container<typename Net::Vector>>
void test_image_batch(const Net& net, const ImageDataType& data, const ImageDataType& target) noexcept
{
    typename Net::Vector prediction(net.inner.topology.back());

    for(size_type i = 0; i < data.size(); ++i)
    {
        show_image<Net>(data[i]);

        prediction.copy(net.feedforward(data[i]));

        std::cout << "\nTRUE: " << li::argmax(target[i])
                  << "\nPRED: " << li::argmax(prediction) << '\n'; // << prediction << '\n';

        std::cin.get();
    }
}

template <class Net, class ImageDataType = typename Net::template Container<typename Net::Vector>>
ImageDataType initialize_i(
    const std::vector<std::vector<unsigned char>>& data, std::size_t batch_size, std::size_t input_size)
{
    ImageDataType input_batch;
    input_batch.reserve(batch_size);

    for(size_type i = 0; i < batch_size; ++i)
        input_batch.emplace_back(input_size);

    for(size_type i = 0; i < batch_size; ++i)
        for(size_type j = 0; j < input_size; ++j)
            input_batch[i](j) = data[i][j] / 255.0;

    return input_batch;
}

template <class Net, class ImageDataType = typename Net::template Container<typename Net::Vector>>
ImageDataType initialize_o(
    const std::vector<unsigned char>& data, std::size_t batch_size, std::size_t output_size)
{
    ImageDataType output_batch;
    output_batch.reserve(batch_size);

    for(size_type i = 0; i < batch_size; ++i)
        output_batch.emplace_back(output_size);

    for(size_type i = 0; i < batch_size; ++i)
        for(size_type j = 0; j < output_size; ++j)
            output_batch[i](j) = (data[i] == j) ? 1.0 : 0.0;

    return output_batch;
}

void mnist_test_deserialization()
{
    // Data preparing:
    auto dataset = mnist::read_dataset("C:/mnist_data/");

    size_type train_batch_size = 60000; // max 60 000
    size_type test_batch_size  = 10000;
    size_type input_size = 784;
    size_type out_size   = 10;

    // Train batch initialize:
    auto train_in  = initialize_i<TrixyNet>(dataset.training_images, train_batch_size, input_size);
    auto train_out = initialize_o<TrixyNet>(dataset.training_labels, train_batch_size, out_size);

    // Test batch initialize:
    auto test_in  = initialize_i<TrixyNet>(dataset.test_images, test_batch_size, input_size);
    auto test_out = initialize_o<TrixyNet>(dataset.test_labels, test_batch_size, out_size);

    std::ifstream in("D:\\Serialized\\mnist_test.bin", std::ios::binary);
    if(!in.is_open()) return;

    // NeuralNetwork preparing:
    TrixyNetSerializer sr;
    sr.deserialize(in);
    in.close();

    TrixyNet net(sr.getTopology());
    TrixyNetFunctional manage;

    net.initInnerStruct(sr.getBias(), sr.getWeight());

    net.function.setAllActivation(manage.get(sr.getAllActivationId()));
    net.function.setLoss(manage.get(sr.getLossId()));
    //
    std::cout << "NEURO TRAIN_SET ACCURACY: " << net.accuracy(train_in, train_out)
              << "\nNEURO TRAIN_SET LOSS: " << net.loss(train_in, train_out) << '\n'
              << "NEURO TEST_SET ACCURACY: " << net.accuracy(test_in, test_out)
              << "\nNEURO TEST_SET LOSS: " << net.loss(test_in, test_out) << '\n';
    //
    //
    std::cout << "TESTING TRAIN_SET\n";
    test_image_batch(net, train_in, train_out);
    //
    //
    std::cout << "TESTING TEST_SET\n";
    test_image_batch(net, test_in, test_out);
    //
}

void mnist_test()
{
    // Data preparing:
    auto dataset = mnist::read_dataset("C:/mnist_data/");

    size_type train_batch_size = 60000; // max 60 000
    size_type test_batch_size  = 10000;
    size_type input_size = 784;
    size_type out_size   = 10;

    // Train batch initialize:
    auto train_in  = initialize_i<TrixyNet>(dataset.training_images, train_batch_size, input_size);
    auto train_out = initialize_o<TrixyNet>(dataset.training_labels, train_batch_size, out_size);

    // Test batch initialize:
    auto test_in  = initialize_i<TrixyNet>(dataset.test_images, test_batch_size, input_size);
    auto test_out = initialize_o<TrixyNet>(dataset.test_labels, test_batch_size, out_size);

    // Show image:
    //show_image_batch(train_in);

    // NeuralNetwork topology:
    TrixyNet net({ input_size, 256, out_size });
    TrixyNetFunctional manage;
    TrixyNetTraining teach(net);

    constexpr int range = 1000;
    net.initInnerStruct([]
    {
        return float(std::rand() % (2 * range + 1) - range) / (range * range);
    });

    net.function.setActivation(manage.get<ActivationId::relu>());
    net.function.setNormalization(manage.get<ActivationId::softmax>());

    net.function.setLoss(manage.get<LossId::CCE>());

    auto optimizer = manage.get<OptimizationId::adam>(net, 0.01);

    std::cout << std::fixed << std::setprecision(6);
    // Train network:
    util::Timer t;
    //
    size_type times = 10;
    for(size_type i = 1; i <= times; ++i)
    {
        std::cout << "start train [" << i << "]:\n";
        //teach.trainBatch(train_in, train_out, 10, optimizer);
        //teach.trainStochastic(train_in, train_out, 5000, std::rand, optimizer);
        teach.trainMiniBatch(train_in, train_out, 1, 40, optimizer);
        std::cout << "Accuracy: " << net.accuracy(train_in, train_out) << '\n';
    }
    std::cout << "Train time: " << t.elapsed() << '\n';
    t.reset();

    // Test train_batch after train
    std::cout
        << "Network train set loss: " << net.loss(train_in, train_out) << '\n'
        << "Network tarin set normal accuracy: " << net.accuracy(train_in, train_out) << '\n'
    // Test test_batch after train
        << "Network test set loss: " << net.loss(test_in, test_out) << '\n'
        << "Network test set normal accuracy: " << net.accuracy(test_in, test_out) << '\n'
        << "Check time: " << t.elapsed() << '\n';

    std::ofstream out("D:\\Serialized\\mnist_test.bin", std::ios::binary);
    if(!out.is_open()) return;

    TrixyNetSerializer sr;
    sr.serialize(out, net);
    out.close();

    std::cout << "End of serialization\n";
}
/*
int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    std::cout << std::fixed << std::setprecision(6);

    //mnist_test();
    mnist_test_deserialization();

    std::cin.get();

    return 0;
}
*/
