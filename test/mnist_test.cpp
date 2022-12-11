#include <Trixy/Core.hpp>
// TrixyNet, Functional, Optimizer, Training
// Serializer, Tensor, Linear, Container, Random

#include <Utility/Core.hpp> // Timer, operator<<
#include <Utility/mnist_reader.hpp> // read_dataset

#include <iostream> // cin, cout
#include <iomanip> // setprecision, fixed
#include <fstream> // ifstream, ofstream
#include <vector> // vector

namespace tr = trixy;
namespace li = tr::lique;

using namespace tr;
using namespace tr::functional;
using namespace tr::train;
using namespace tr::utility;

using precision_type = float;
using size_type      = std::size_t;

using Core    = tr::TypeSet<precision_type>;
using FeedNet = tr::FeedForwardNet<Core>;

template <class Net, class ImageType = typename Net::Vector>
void show_image(const ImageType& image) noexcept
{
    for (size_type i = 0; i < image.size(); ++i)
    {
        if (i % 28 == 0) std::cout << '\n';
        std::cout << (image(i) > 0.5 ? '#' : image(i) > 0.05 ? '*' : '.') << ' ';
    }
}

template <class Net, class ImageDataType = typename Net::template Container<typename Net::Vector>>
void show_image_batch(const ImageDataType& data) noexcept
{
    for (const auto& image : data)
    {
        show_image(image);
        std::cout << '\n';
    }
}

template <class Net, class ImageDataType = typename Net::template Container<typename Net::Vector>>
void test_image_batch(const Net& net, const ImageDataType& data, const ImageDataType& target) noexcept
{
    typename Net::Vector prediction(net.inner.topology.back());

    for (size_type i = 0; i < data.size(); ++i)
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

    for (size_type i = 0; i < batch_size; ++i)
        input_batch.emplace_back(input_size);

    for (size_type i = 0; i < batch_size; ++i)
        for (size_type j = 0; j < input_size; ++j)
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

    for (size_type i = 0; i < batch_size; ++i)
        for (size_type j = 0; j < output_size; ++j)
            output_batch[i](j) = (data[i] == j) ? 1.0 : 0.0;

    return output_batch;
}

void mnist_test_deserialization()
{
    // Data preparing:
    auto dataset = mnist::read_dataset("C:/mnist_data/");

    size_type train_batch_size = 60000; // max 60 000
    size_type test_batch_size  = 10000;
    size_type input_size  = 784;
    size_type output_size = 10;

    // Train batch initialize:
    auto train_idata = get_idata<FeedNet>(dataset.training_images, train_batch_size, input_size);
    auto train_odata = get_odata<FeedNet>(dataset.training_labels, train_batch_size, output_size);

    // Test batch initialize:
    auto test_idata = get_idata<FeedNet>(dataset.test_images, test_batch_size, input_size);
    auto test_odata = get_odata<FeedNet>(dataset.test_labels, test_batch_size, output_size);

    std::ifstream file("D:\\Serialized\\mnist_test.bin", std::ios::binary);
    if (not file.is_open()) return;

    // NeuralNetwork preparing:
    Serializer<FeedNet> sr;
    sr.deserialize(file);
    file.close();

    FeedNet net(sr.topology());
    Functional<FeedNet> manage;

    net.inner.init(sr.bias(), sr.weight());

    net.function.activation(manage.get(sr.all_activation_id()));
    net.function.loss(manage.get(sr.loss_id()));

    auto error = net.function.loss().f;

    Checker<FeedNet> check(net);
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
    size_type input_size  = 784;
    size_type output_size = 10;

    // Train batch initialize:
    auto train_idata = get_idata<FeedNet>(dataset.training_images, train_batch_size, input_size);
    auto train_odata = get_odata<FeedNet>(dataset.training_labels, train_batch_size, output_size);

    // Test batch initialize:
    auto test_idata = get_idata<FeedNet>(dataset.test_images, test_batch_size, input_size);
    auto test_odata = get_odata<FeedNet>(dataset.test_labels, test_batch_size, output_size);

    // Show image:
    //show_image_batch(train_file);

    // NeuralNetwork topology:
    FeedNet net({ input_size, 256, output_size });
    Functional<FeedNet> manage;
    Training<FeedNet> teach(net);
    Checker<FeedNet> check(net);

    RandomFloating<precision_type> random;
    net.inner.init([&] { return random(-.25, .25); });

    net.function.activation(manage.get<ActivationId::relu>());
    net.function.normalization(manage.get<ActivationId::softmax>());

    net.function.loss(manage.get<LossId::CCE>());

    auto optimizer = manage.get<OptimizationId::adam>(net, 0.01);

    // Train network:
    Timer t;
    //
    size_type times = 10;
    for (size_type i = 1; i <= times; ++i)
    {
        std::cout << "start train [" << i << "]:\n";
        teach.mini_batch(train_idata, train_odata, optimizer, 1, 40);
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

    std::ofstream file("D:\\Serialized\\mnist_test.bin", std::ios::binary);
    if (not file.is_open()) return;

    Serializer<FeedNet> sr;
    sr.serialize(file, net);
    file.close();

    std::cout << "End of serialization\n";
}
//
int main()
{
    std::cout << std::fixed << std::setprecision(6);

    //mnist_test();
    mnist_test_deserialization();

    std::cin.get();

    return 0;
}
//
