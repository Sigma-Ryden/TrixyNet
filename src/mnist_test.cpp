#include <cstdlib> // rand, srand, size_t
#include <ctime> // time
#include <iostream> // cin, cout
#include <iomanip> // setprecision, fixed

#include "Trixy/Lique/lique_linear.hpp" // Linear
#include "Trixy/Lique/lique_matrix.hpp" // Matrix
#include "Trixy/Lique/lique_vector.hpp" // Vector

#include "Trixy/Container/container.hpp" // Container

#include "Trixy/Neuro/neuro_core.hpp" // Neuro, Activation, Loss, Optimization
#include "Trixy/Neuro/neuro_functional.hpp" // NeuroManager
#include "MnistMaster/mnist_reader.hpp" // read_dataset

#include "Timer/timer.h" // Timer
#include "UtilityMaster/utils.hpp" // operator<<

namespace tr = trixy;
namespace li = lique;

template <typename Precision>
Precision random_real() noexcept
{
    static int within = 1000;
    return static_cast<Precision>(std::rand() % (2 * within + 1) - within) / (within * within);
}

template <typename Precision>
Container<li::Vector<Precision>> initialize_i(
    const std::vector<std::vector<unsigned char>>& data, std::size_t batch_size, std::size_t input_size)
{
    Container<li::Vector<Precision>> input_batch(batch_size);
    for(std::size_t i = 0; i < batch_size; ++i)
        input_batch[i] = li::Vector<Precision>(input_size);

    for(std::size_t i = 0; i < batch_size; ++i)
        for(std::size_t j = 0; j < input_size; ++j)
            input_batch[i](j) = data[i][j] / 255.0;

    return input_batch;
}

template <typename Precision>
Container<li::Vector<Precision>> initialize_o(
    const std::vector<unsigned char>& data, std::size_t batch_size, std::size_t output_size)
{
    Container<li::Vector<Precision>> output_batch(batch_size);
    for(std::size_t i = 0; i < batch_size; ++i)
        output_batch[i] = li::Vector<Precision>(output_size);

    for(std::size_t i = 0; i < batch_size; ++i)
        for(std::size_t j = 0; j < output_size; ++j)
            if(data[i] == j) output_batch[i](j) = 1;
            else output_batch[i](j) = 0;

    return output_batch;
}

template <typename Precision>
void show_image(const li::Vector<Precision>& vector) noexcept
{
    for(std::size_t j = 0; j < vector.size(); ++j)
    {
        if(j % 28 == 0) std::cout << '\n';
        std::cout << (vector(j) != 0 ? '#' : '.') << ' ';
    }
}

template <typename Precision>
void show_image_batch(const Container<li::Vector<Precision>>& data) noexcept
{
    for(std::size_t i = 0; i < data.size(); ++i)
    {
        show_image(data[i]);
        std::cout << '\n';
    }
}

template <typename Precision>
void mnist_test()
{
    // Data preparing:
    auto dataset = mnist::read_dataset<std::vector, std::vector, uint8_t, uint8_t>("C:/mnist_data/");

    std::size_t train_batch_size = 60000;
    std::size_t test_batch_size  = 10000;
    std::size_t input_size = 784;
    std::size_t out_size   = 10;

    // Train batch initialize:
    Container<li::Vector<Precision>> train_in = initialize_i<Precision>(dataset.training_images, train_batch_size, input_size);
    Container<li::Vector<Precision>> train_out = initialize_o<Precision>(dataset.training_labels, train_batch_size, out_size);

    // Test batch initialize:
    Container<li::Vector<Precision>> test_in = initialize_i<Precision>(dataset.test_images, test_batch_size, input_size);
    Container<li::Vector<Precision>> test_out = initialize_o<Precision>(dataset.test_labels, test_batch_size, out_size);

    // Show image:
    //show_image_batch(train_in);

    // NeuralNetwork preparing:
    using NeuralFeedForward = trixy::Neuro<li::Vector, li::Matrix, li::Linear, Container, Precision>;
    using NeuralManager     = trixy::NeuroManager<li::Vector, li::Matrix, Precision>;

    // NeuralNetwork topology:
    NeuralFeedForward net = { input_size, 256, out_size };
    NeuralManager manage;

    net.initializeInnerStruct(random_real);

    net.setActivationFunction(manage.template get<tr::function::Activation>("relu"));
    net.setNormalizationFunction(manage.template get<tr::function::Activation>("softmax"));

    net.setLossFunction(manage.template get<tr::function::Loss>("CCE"));
    net.setOptimizationFunction(manage.template get<tr::function::Optimization>("rms_prop"));

    // Train network:
    Timer t;
    //
    std::size_t times = 32;
    for(std::size_t i = 1; i <= times; ++i)
    {
        std::cout << "start train [" << i << "]:\n";
        //net.trainMiniBatch(train_in, train_out, 0.1, 50, 64, std::rand);
        net.trainOptimize(train_in, train_out, 0.01, 35, 64, std::rand);
        if (i % 5 == 0) std::cout << "Accuracy: " << net.accuracy(train_in, train_out) << '\n';
        //net.trainStochastic(train_in, train_out, 0.5, 1000, std::rand);
    }
    std::cout << t.elapsed() << '\n';
    t.reset();

    // Test train_batch aft
    std::cout << "NNetwork train loss: " << net.loss(train_in, train_out) << '\n';
    std::cout << "NNetwork tarin normal accuracy: " << net.accuracy(train_in, train_out) << '\n';
    //std::cout << "NNetwork tarin global accuracy: " << net.globalAccuracy(train_in, train_out, 0.25) << '\n';
    //std::cout << "NNetwork tarin full accuracy: " << net.fullAccuracy(train_in, train_out, 0.25) << '\n';
    // Test test_batch aft
    std::cout << "NNetwork test loss: " << net.loss(test_in, test_out) << '\n';
    std::cout << "NNetwork test normal accuracy: " << net.accuracy(test_in, test_out) << '\n';
    //std::cout << "NNetwork test global accuracy: " << net.globalAccuracy(test_in, test_out, 0.25) << '\n';
    //std::cout << "NNetwork test full accuracy: " << net.fullAccuracy(test_in, test_out, 0.25) << '\n';
    std::cout << t.elapsed() << '\n';
}

/*
int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout << std::fixed << std::setprecision(6);

    mnist_test<float>();

    std::cin.get();

    return 0;
}
*/
/*
DEPRECATED!!!
FLOAT:
4.810986
NNetwork tarin normal accuracy: 0.809367
25.023176
NNetwork test normal accuracy: 0.810200
4.186155

DOUBLE:
7.028966
NNetwork tarin normal accuracy: 0.749817
27.647358
NNetwork test normal accuracy: 0.753600
4.607892
*/
