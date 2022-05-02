#include <Trixy/Core.hpp>
// TrixyNet, Functional, Optimizer, Training
// Serializer, Tensor, Linear, Container, Random

#include <Utility/utility.hpp> // Timer, max, operator<<
#include <Utility/mnist_reader.hpp> // read_dataset

#include <iostream> // cin, cout
#include <iomanip> // setprecision, fixed
#include <fstream> // ifstream, ofstream
#include <vector> // vector

namespace tr = trixy;
namespace li = trixy::lique;

using namespace tr::functional;
using namespace utility; // Core

using TrixyNet = tr::FeedForwardNet<tr::TypeSet<float>>;

using TrixyNetFunctional = tr::Functional<TrixyNet>;
using TrixyNetTraining   = tr::train::Training<TrixyNet>;
using TrixyNetSerializer = tr::Serializer<TrixyNet>;
using TrixyNetChecker    = tr::Checker<TrixyNet>;

using RandomIntegral     = tr::RandomIntegral<>;
using RandomFloating     = tr::RandomFloating<>;

using size_type = std::size_t;

using utility::operator<<;

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
ImageDataType get_idata(
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
ImageDataType get_odata(
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
    auto train_idata = get_idata<TrixyNet>(dataset.training_images, train_batch_size, input_size);
    auto train_odata = get_odata<TrixyNet>(dataset.training_labels, train_batch_size, out_size);

    // Test batch initialize:
    auto test_idata = get_idata<TrixyNet>(dataset.test_images, test_batch_size, input_size);
    auto test_odata = get_odata<TrixyNet>(dataset.test_labels, test_batch_size, out_size);

    std::ifstream in("D:\\Serialized\\mnist_test.bin", std::ios::binary);
    if (not in.is_open()) return;

    // NeuralNetwork preparing:
    TrixyNetSerializer sr;
    sr.deserialize(in);
    in.close();

    TrixyNet net(sr.getTopology());
    TrixyNetFunctional manage;

    net.inner.initialize(sr.getBias(), sr.getWeight());

    net.function.activationSet(manage.get(sr.getAllActivationId()));
    net.function.loss(manage.get(sr.getLossId()));

    auto error = net.function.loss().f;

    TrixyNetChecker check(net);
    //
    std::cout << "NEURO TRAIN_SET ACCURACY: " << check.accuracy(train_idata, train_odata)
              << "\nNEURO TRAIN_SET LOSS: " << check.loss(train_idata, train_odata, error) << '\n'
              << "NEURO TEST_SET ACCURACY: " << check.accuracy(test_idata, test_odata)
              << "\nNEURO TEST_SET LOSS: " << check.loss(test_idata, test_odata, error) << '\n';
    //
    //
    std::cout << "TESTING TRAIN_SET\n";
    test_image_batch(net, train_idata, train_odata);
    //
    //
    std::cout << "TESTING TEST_SET\n";
    test_image_batch(net, test_idata, test_odata);
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
    auto train_idata = get_idata<TrixyNet>(dataset.training_images, train_batch_size, input_size);
    auto train_odata = get_odata<TrixyNet>(dataset.training_labels, train_batch_size, out_size);

    // Test batch initialize:
    auto test_idata = get_idata<TrixyNet>(dataset.test_images, test_batch_size, input_size);
    auto test_odata = get_odata<TrixyNet>(dataset.test_labels, test_batch_size, out_size);

    // Show image:
    //show_image_batch(train_in);

    // NeuralNetwork topology:
    TrixyNet net({ input_size, 256, out_size });
    TrixyNetFunctional manage;
    TrixyNetTraining teach(net);
    TrixyNetChecker check(net);

    RandomFloating gen;
    net.inner.initialize([&gen] { return gen(-.25, .25); });

    net.function.activation(manage.get<ActivationId::relu>());
    net.function.normalization(manage.get<ActivationId::softmax>());

    net.function.loss(manage.get<LossId::CCE>());

    auto optimizer = manage.get<OptimizationId::adam>(net, 0.01);

    // Train network:
    utility::Timer t;
    //
    size_type times = 10;
    for (size_type i = 1; i <= times; ++i)
    {
        std::cout << "start train [" << i << "]:\n";
        teach.trainMiniBatch(train_idata, train_odata, optimizer, 1, 40);
        std::cout << "Accuracy: " << check.accuracy(train_idata, train_odata) << '\n';
    }
    std::cout << "Train time: " << t.elapsed() << '\n';
    t.reset();

    // Test train_batch after train
    std::cout
        << "Network train set loss: " << teach.loss(train_idata, train_odata) << '\n'
        << "Network tarin set normal accuracy: " << check.accuracy(train_idata, train_odata) << '\n'
    // Test test_batch after train
        << "Network test set loss: " << teach.loss(test_idata, test_odata) << '\n'
        << "Network test set normal accuracy: " << check.accuracy(test_idata, test_odata) << '\n'
        << "Check time: " << t.elapsed() << '\n';

    std::ofstream out("D:\\Serialized\\mnist_test.bin", std::ios::binary);
    if (not out.is_open()) return;

    TrixyNetSerializer sr;
    sr.serialize(out, net);
    out.close();

    std::cout << "End of serialization\n";
}
/*
int main()
{
    std::cout << std::fixed << std::setprecision(6);

    //mnist_test();
    mnist_test_deserialization();

    std::cin.get();

    return 0;
}
*/
