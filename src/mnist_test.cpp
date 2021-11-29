#include "Trixy/Neuro/neuro_core.hpp" // FeedForwardNeuro, FFNNFunctional, FFNNSerializer
#include "Trixy/Lique/lique_core.hpp" // Vector, Matrix, Linear

#include "Trixy/Container/container.hpp" // Container
#include "Utility/util.hpp" // Timer, max, operator<<

#include "MnistMaster/mnist_reader.hpp" // read_dataset

#include <cstdlib> // rand, srand, size_t
#include <ctime> // time
#include <iostream> // cin, cout
#include <iomanip> // setprecision, fixed
#include <fstream> // ifstream, ofstream

namespace tr = trixy;
namespace li = lique;

using util::operator<<;

tr::Container<li::Vector<float>> initialize_i(
    const std::vector<std::vector<unsigned char>>& data, std::size_t batch_size, std::size_t input_size)
{
    tr::Container<li::Vector<float>> input_batch(batch_size);

    for(std::size_t i = 0; i < batch_size; ++i)
        input_batch[i].resize(input_size);

    for(std::size_t i = 0; i < batch_size; ++i)
        for(std::size_t j = 0; j < input_size; ++j)
            input_batch[i](j) = data[i][j] / 255.0;

    return input_batch;
}

tr::Container<li::Vector<float>> initialize_o(
    const std::vector<unsigned char>& data, std::size_t batch_size, std::size_t output_size)
{
    tr::Container<li::Vector<float>> output_batch(batch_size);

    for(std::size_t i = 0; i < batch_size; ++i)
        output_batch[i].resize(output_size);

    for(std::size_t i = 0; i < batch_size; ++i)
        for(std::size_t j = 0; j < output_size; ++j)
            output_batch[i](j) = data[i] == j ? 1.0 : 0.0;

    return output_batch;
}

void show_image(const li::Vector<float>& vector) noexcept
{
    for(std::size_t i = 0; i < vector.size(); ++i)
    {
        if(i % 28 == 0) std::cout << '\n';
        std::cout << (vector(i) > 0.5 ? '#' : vector(i) > 0.05 ? '*' : '.') << ' ';
    }
}

void show_image_batch(const tr::Container<li::Vector<float>>& data) noexcept
{
    for(std::size_t i = 0; i < data.size(); ++i)
    {
        show_image(data[i]);
        std::cout << '\n';
    }
}

void mnist_test_deserialization()
{
    using namespace tr::function;

    using NeuralNetwork    = tr::FeedForwardNeuro<li::Vector, li::Matrix, li::Linear, tr::Container, float>;
    using NeuralSerializer = tr::FFNNSerializer<li::Vector, li::Matrix, tr::Container, float>;
    using NeuralFunctional = tr::FFNNFunctional<NeuralNetwork>;

    // Data preparing:
    auto dataset = mnist::read_dataset<std::vector, std::vector, uint8_t, uint8_t>("C:/mnist_data/");

    std::size_t train_batch_size = 60000; // max 60 000
    std::size_t test_batch_size  = 10000;
    std::size_t input_size = 784;
    std::size_t out_size   = 10;

    // Train batch initialize:
    tr::Container<li::Vector<float>> train_in  = initialize_i(dataset.training_images, train_batch_size, input_size);
    tr::Container<li::Vector<float>> train_out = initialize_o(dataset.training_labels, train_batch_size, out_size);

    // Test batch initialize:
    tr::Container<li::Vector<float>> test_in  = initialize_i(dataset.test_images, test_batch_size, input_size);
    tr::Container<li::Vector<float>> test_out = initialize_o(dataset.test_labels, test_batch_size, out_size);

    // NeuralNetwork preparing:

    // NeuralNetwork topology:
    std::ifstream in("D:\\mnist_experimental.bin", std::ios::binary);
    if(!in.is_open()) return;

    NeuralSerializer sr;
    sr.deserialize(in);
    in.close();

    NeuralNetwork net = sr.getTopology();
    NeuralFunctional manage;

    net.initializeInnerStruct(sr.getBias(), sr.getWeight());

    net.function.setActivation(manage.get(sr.getActivationId()));
    net.function.setNormalization(manage.get(sr.getNormalizationId()));
    net.function.setLoss(manage.get(sr.getLossId()));

    //
    std::cout << "NEURO TRAIN_SET ACCURACY: " << net.accuracy(train_in, train_out)
              << "\nNEURO TRAIN_SET LOSS: " << net.loss(train_in, train_out) << '\n';

    std::cout << "NEURO TEST_SET ACCURACY: " << net.accuracy(test_in, test_out)
              << "\nNEURO TEST_SET LOSS: " << net.loss(test_in, test_out) << '\n';
    //
    std::cout << "TESTING TRAIN_SET\n";
    for(std::size_t i = 0; i < train_in.size(); ++i)
    {
        show_image(train_in[i]);
        std::cout << "\nTRUE: " << util::max(train_out[i])
                  << "\nPRED: " << util::max(net.feedforward(train_in[i])) << '\n';
        std::cin.get();
    }
    //
    //
    std::cout << "TESTING TEST_SET\n";
    for(std::size_t i = 0; i < test_in.size(); ++i)
    {
        show_image(test_in[i]);
        std::cout << "\nTRUE: " << util::max(test_out[i])
                  << "\nPRED: " << util::max(net.feedforward(test_in[i])) << '\n';
        std::cin.get();
    }
    //
}

void mnist_test()
{
    using namespace tr::function;

    using NeuralNetwork    = tr::FeedForwardNeuro<li::Vector, li::Matrix, li::Linear, tr::Container, float>;
    using NeuralSerializer = tr::FFNNSerializer<li::Vector, li::Matrix, tr::Container, float>;
    using NeuralFunctional = tr::FFNNFunctional<NeuralNetwork>;

    // Data preparing:
    auto dataset = mnist::read_dataset<std::vector, std::vector, uint8_t, uint8_t>("C:/mnist_data/");

    std::size_t train_batch_size = 60000; // max 60 000
    std::size_t test_batch_size  = 10000;
    std::size_t input_size = 784;
    std::size_t out_size   = 10;

    // Train batch initialize:
    tr::Container<li::Vector<float>> train_in  = initialize_i(dataset.training_images, train_batch_size, input_size);
    tr::Container<li::Vector<float>> train_out = initialize_o(dataset.training_labels, train_batch_size, out_size);

    // Test batch initialize:
    tr::Container<li::Vector<float>> test_in  = initialize_i(dataset.test_images, test_batch_size, input_size);
    tr::Container<li::Vector<float>> test_out = initialize_o(dataset.test_labels, test_batch_size, out_size);

    // Show image:
    //show_image_batch(train_in);

    // NeuralNetwork topology:
    NeuralNetwork net({ input_size, 256, out_size });
    NeuralFunctional manage;

    net.initializeInnerStruct([] () -> float {
        static int range = 1000;
        return static_cast<float>(std::rand() % (2 * range + 1) - range) / (range * range);
    });

    net.function.setActivation(manage.get(ActivationId::relu));
    net.function.setNormalization(manage.get(ActivationId::softmax));

    net.function.setLoss(manage.get(LossId::CCE));
    net.function.setOptimization(manage.get(OptimizationId::momentum));

    // Train network:
    util::Timer t;
    //
    std::size_t times = 200;
    for(std::size_t i = 1; i <= times; ++i)
    {
        std::cout << "start train [" << i << "]:\n";
        //net.trainBatch(train_in, train_out, 0.1, 10);
        //net.trainStochastic(train_in, train_out, 0.1, 5000, std::rand);
        //net.trainMiniBatch(train_in, train_out, 0.1, 40, 64, std::rand);
        net.trainOptimize(train_in, train_out, 0.1, 50, 32, std::rand);
        if (i % 50 == 0) std::cout << "Accuracy: " << net.accuracy(train_in, train_out) << '\n';
    }
    std::cout << "Train time: " << t.elapsed() << '\n';
    t.reset();

    // Test train_batch aft
    std::cout << "NNetwork train loss: " << net.loss(train_in, train_out) << '\n';
    std::cout << "NNetwork tarin normal accuracy: " << net.accuracy(train_in, train_out) << '\n';
    //std::cout << "NNetwork tarin global accuracy: " << net.accuracyg(train_in, train_out, 0.25) << '\n';
    //std::cout << "NNetwork tarin full accuracy: " << net.accuracyf(train_in, train_out, 0.25) << '\n';
    // Test test_batch aft
    std::cout << "NNetwork test loss: " << net.loss(test_in, test_out) << '\n';
    std::cout << "NNetwork test normal accuracy: " << net.accuracy(test_in, test_out) << '\n';
    //std::cout << "NNetwork test global accuracy: " << net.accuracyg(test_in, test_out, 0.25) << '\n';
    //std::cout << "NNetwork test full accuracy: " << net.accuracyf(test_in, test_out, 0.25) << '\n';
    std::cout << "Check time: " << t.elapsed() << '\n';

    std::ofstream out("D:\\mnist_test.bin", std::ios::binary);
    if(!out.is_open()) return;

    NeuralSerializer sr;
    sr.prepare(net);
    sr.serialize(out);
    out.close();

    std::cout << "End serialization\n";
}

/*
int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::cout << std::fixed << std::setprecision(6);

    //mnist_test();
    mnist_test_deserialization();

    std::cin.get();

    return 0;
}
*/
