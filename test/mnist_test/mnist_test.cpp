#include <Automation/Core.hpp>

#include <Trixy/Core.hpp>
// TrixyNet, Functional, Optimizer, Training
// Serializer, Tensor, Linear, Container, Random

#include <debug_tools.hpp> // Timer, operator<<
#include <mnist_test/mnist_reader.hpp> // read_dataset

#include <iostream> // cin, cout
#include <iomanip> // setprecision, fixed
#include <fstream> // ifstream, ofstream
#include <vector> // vector

using Core = trixy::TypeSet<float>;
using Net = trixy::TrixyNet<Core>;

using FullyConnected = trixy::layer::FullyConnected<Net>;

using ReLU = trixy::functional::activation::ReLU<Core::precision_type>;
using SoftMax = trixy::functional::activation::SoftMax<Core::precision_type>;

using CCE = trixy::functional::loss::CCE<Core::precision_type>;

void show_image(const Core::Tensor& image) noexcept
{
    for (Core::size_type i = 0; i < image.size(); ++i)
    {
        if (i % 28 == 0) std::cout << '\n';
        std::cout << (image(i) > 0.5 ? '#' : image(i) > 0.05 ? '*' : '.') << ' ';
    }
}

void show_image_batch(const Core::Container<Core::Tensor>& data) noexcept
{
    for (const auto& image : data)
    {
        show_image(image);
        std::cout << '\n';
    }
}

void test_image_batch(Net& net, Core::Container<Core::Tensor>& data, Core::Container<Core::Tensor>& target) noexcept
{
    for (Core::size_type i = 0; i < data.size(); ++i)
    {
        show_image(data[i]);

        std::cout << "\nTRUE: " << trixy::lique::argmax(target[i])
                  << "\nPRED: " << trixy::lique::argmax(net.feedforward(data[i])) << '\n';

        std::cin.get();
    }
}

Core::Container<Core::Tensor> get_idata(
    const std::vector<std::vector<unsigned char>>& data, std::size_t batch_size, std::size_t input_size)
{
    Core::Container<Core::Tensor> input_batch;
    input_batch.reserve(batch_size);

    if (data.empty()) return input_batch;

    for (Core::size_type i = 0; i < batch_size; ++i)
        input_batch.emplace_back(1, 1, input_size);

    for (Core::size_type i = 0; i < batch_size; ++i)
        for (Core::size_type j = 0; j < input_size; ++j)
            input_batch[i](j) = data[i][j] / 255.0;

    return input_batch;
}

Core::Container<Core::Tensor> get_odata(
    const std::vector<unsigned char>& data, std::size_t batch_size, std::size_t output_size)
{
    Core::Container<Core::Tensor> output_batch;
    output_batch.reserve(batch_size);

    if (data.empty()) return output_batch;

    for(Core::size_type i = 0; i < batch_size; ++i)
        output_batch.emplace_back(1, 1, output_size);

    for (Core::size_type i = 0; i < batch_size; ++i)
        for (Core::size_type j = 0; j < output_size; ++j)
            output_batch[i](j) = (data[i] == j) ? 1.0 : 0.0;

    return output_batch;
}

void mnist_test_deserialization()
{
    // Data preparing:
    auto dataset = mnist::read_dataset("mnist");

    Core::size_type train_batch_size = 60000; // max 60 000
    Core::size_type test_batch_size  = 10000;
    Core::size_type input_size  = 784;
    Core::size_type output_size = 10;

    // Train batch initialize:
    auto train_idata = get_idata(dataset.training_images, train_batch_size, input_size);
    auto train_odata = get_odata(dataset.training_labels, train_batch_size, output_size);

    // Test batch initialize:
    auto test_idata = get_idata(dataset.test_images, test_batch_size, input_size);
    auto test_odata = get_odata(dataset.test_labels, test_batch_size, output_size);

    std::ifstream file("mnist_test.bin", std::ios::binary);
    if (not file.is_open()) return;

    // NeuralNetwork preparing:
    Net net;

    trixy::Serializer<Net> sr;
    sr.deserialize(file, net);

    file.close();

    trixy::Checker<Net> check(net);
    //
    std::cout << "NEURO TRAIN_SET ACCURACY: " << check.accuracy(train_idata, train_odata)
              << "\nNEURO TRAIN_SET LOSS: " << check.loss(train_idata, train_odata, CCE()) << '\n'
              << "NEURO TEST_SET ACCURACY: " << check.accuracy(test_idata, test_odata)
              << "\nNEURO TEST_SET LOSS: " << check.loss(test_idata, test_odata, CCE()) << '\n';
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
    trixy::utility::RandomFloating<Core::precision_type> random;
    auto generator = [&random] { return random(-0.25f, 0.25f); };

    // Data preparing:
    auto dataset = mnist::read_dataset("mnist");

    Core::size_type train_batch_size = 60000; // max 60 000
    Core::size_type test_batch_size  = 10000;
    Core::size_type input_size  = 784;
    Core::size_type output_size = 10;

    // Train batch initialize:
    auto train_idata = get_idata(dataset.training_images, train_batch_size, input_size);
    auto train_odata = get_odata(dataset.training_labels, train_batch_size, output_size);

    // Test batch initialize:
    auto test_idata = get_idata(dataset.test_images, test_batch_size, input_size);
    auto test_odata = get_odata(dataset.test_labels, test_batch_size, output_size);

    // Show image:
    //show_image_batch(train_file);

    // NeuralNetwork topology:
    Net net;

    net.add(new FullyConnected(input_size, 256, new ReLU))
       .add(new FullyConnected(256, output_size, new SoftMax));

    net.init(generator);

    // Train network:
    trixy::train::Training<Net> teach(net);
    trixy::Checker<Net> check(net);

    teach.loss(new CCE);

    auto optimizer = trixy::train::AdamOptimizer(net, 0.01f);


    Timer t;
    //
    Core::size_type times = 10;
    for (Core::size_type i = 1; i <= times; ++i)
    {
        std::cout << "start train [" << i << "]:\n";
        teach.mini_batch(train_idata, train_odata, optimizer, 1, 10);
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

    std::ofstream file("mnist_test.bin", std::ios::binary);
    if (not file.is_open()) return;

    trixy::Serializer<Net> sr;
    sr.serialize(file, net);

    file.close();

    std::cout << "End of serialization\n";
}

TEST(TestExample, TestMNIST)
{
    return;
    sf::serializable<FullyConnected>();
    sf::serializable<ReLU>();
    sf::serializable<SoftMax>();

    std::cout << std::fixed << std::setprecision(6);

    mnist_test();
    mnist_test_deserialization();
}
