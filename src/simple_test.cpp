#include <cstdlib> // rand, srand, size_t
#include <ctime> // time
#include <iostream> // cin, cout
#include <iomanip> // setprecision, fixed

#include "Trixy/Lique/lique_linear.hpp" // Linear
#include "Trixy/Lique/lique_matrix.hpp" // Matrix
#include "Trixy/Lique/lique_vector.hpp" // Vector

#include "Trixy/Neuro/neuro_core.hpp" // Neuro, Activation, Loss, Optimization
#include "Trixy/Neuro/neuro_functional.hpp" // NeuroManager

#include "Trixy/Container/container.hpp" // Container

#include "MnistMaster/mnist_reader.hpp" // read_dataset
#include "Timer/timer.h" // Timer
#include "UtilityMaster/utils.hpp" // testNeuro

namespace tr = trixy;
namespace li = lique;

template <typename Precision>
Precision random_real() noexcept
{
    static int within = 1000;
    return static_cast<Precision>(std::rand() % (2 * within + 1) - within) / within;
}
template <typename Precision>
Precision random_normal() noexcept
{
    static int within = 1000;
    static double pi = 3.14159265;
    Precision x = static_cast<Precision>(std::rand() % (2 * within + 1) - within) / within;

    return std::exp(- x * x) / std::sqrt(2 * pi);
}

template <typename Precision>
void simple_test()
{
    using namespace trixy::function;

    using NeuralFeedForward = tr::Neuro<li::Vector, li::Matrix, li::Linear, Container, Precision>;
    using NeuralManager     = tr::NeuroManager<li::Vector, li::Matrix, Precision>;

    NeuralFeedForward net = {4, 4, 5, 4, 3};
    NeuralManager manage;

    net.initializeInnerStruct(random_real);

    net.setActivationFunction(manage.template get<Activation>("relu"));
    net.setNormalizationFunction(manage.template get<Activation>("softmax"));

    net.setLossFunction(manage.template get<Loss>("CCE"));
    net.setOptimizationFunction(manage.template get<Optimization>("momentum"));

    Container<li::Vector<Precision>> train_in
    {
        {1, 0, 1, 1},
        {1, 1, 1, 0},
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {1, 0, 1, 0},
        {0, 0, 1, 1}
    };
    Container<li::Vector<Precision>> train_out
    {
        {1, 0, 0},
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 1},
        {0, 1, 0},
        {1, 0, 0}
    };

    std::cout << "Before train\n";
    utils::testNeuro(net, train_in, train_out);

    Timer t;
    //
    net.trainBatch(train_in, train_out, 0.15, 100000);
    net.trainMiniBatch(train_in, train_out, 0.15, 100000, 2, std::rand);
    net.trainStochastic(train_in, train_out, 0.1, 100000, std::rand);
    //
    /*
    for(int i = 1; i <= 4; ++i)
    {

        net.trainOptimize(train_in, train_out, 0.15, 500, 6, std::rand);
        //std::cout << '<' << i << "> Loss: " << net.loss(train_in_set, train_out_set) << '\n';
    }
    */
    std::cout << t.elapsed() << '\n';
    std::cout << "After train\n";

    utils::testNeuro(net, train_in, train_out);
    std::cout << "Normal accuracy: " << net.accuracy(train_in, train_out) << '\n';
    std::cout << "Global accuracy: " << net.globalAccuracy(train_in, train_out, 0.05) << '\n';
    std::cout << "Full accuracy: " << net.fullAccuracy(train_in, train_out, 0.05) << '\n';
    std::cout << "Loss: " << net.loss(train_in, train_out) << '\n';
}

void simple_test2()
{
    // Creating Neural Network
    using namespace trixy::function;

    tr::Neuro<li::Vector, li::Matrix, li::Linear, Container, double> net = {2, 2, 2};
    tr::NeuroManager<li::Vector, li::Matrix, double> manage;

    net.initializeInnerStruct(random_real);

    net.setActivationFunction(manage.get<Activation>("relu"));
    net.setNormalizationFunction(manage.get<Activation>("softmax"));
    net.setLossFunction(manage.get<Loss>("CCE"));
    net.setOptimizationFunction(manage.get<Optimization>("ada_grad"));

    // Train set (in/out)
    Container<li::Vector<double>> train_in
    {
        {-2, -1},
        {23, 6},
        {10, 4},
        {-15, -6}
    };

    Container<li::Vector<double>> train_out
    {
        {1, 0},
        {0, 1},
        {0, 1},
        {1, 0}
    };
    for(std::size_t i = 0; i < train_in.size(); ++i)
        train_in[i].apply([] (double x) -> double { return x / 25.0; });

    // Full processing
    Timer t;
    net.trainOptimize(train_in, train_out, 0.1, 1000, 2, std::rand);
    std::cout << t.elapsed() << '\n';
    utils::testNeuro(net, train_in, train_out);
    std::cout << "NNetwork tarin normal accuracy: " << net.accuracy(train_in, train_out) << '\n';
    std::cout << "NNetwork tarin global accuracy: " << net.globalAccuracy(train_in, train_out, 0.05) << '\n';
    std::cout << "NNetwork tarin full accuracy: " << net.fullAccuracy(train_in, train_out, 0.05) << '\n';
}

/*
int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::cout << std::fixed << std::setprecision(6);

    simple_test<double>();
    //simple_test2();

    std::cin.get();

    return 0;
}
*/
