#include "Trixy/Lique/lique_vector.hpp" // Vector
#include "Trixy/Lique/lique_matrix.hpp" // Matrix
#include "Trixy/Lique/lique_linear.hpp" // Linear

#include "Trixy/Container/container.hpp" // Container
#include "Trixy/Neuro/FFNN_functional.hpp" // FFNNFunctional
#include "Trixy/Neuro/FFNN_serializer.hpp" // FFNNSerializer
#include "Trixy/Neuro/Network/FFNN.hpp" // FeedForwardNeuro

#include "MnistMaster/mnist_reader.hpp" // read_dataset
#include "Timer/timer.h" // Timer
#include "Utility/util.hpp" // test_neuro, check_neuro

#include <cstdlib> // rand, srand, size_t
#include <ctime> // time
#include <iostream> // cin, cout
#include <fstream> // ifstream, ofstream
#include <iomanip> // setprecision, fixed

namespace tr = trixy;
namespace li = lique;

using namespace tr::function;

float random_real() noexcept
{
    static int range = 1000;
    return static_cast<float>(std::rand() % (2 * range + 1) - range) / range;
}

float random_normal() noexcept
{
    static const int range = 1000;
    static const float pi = 3.14159265;

    static float x;

    x = static_cast<float>(std::rand() % (2 * range + 1) - range) / range;

    return std::exp(- x * x) / std::sqrt(2 * pi);
}

void speed_test_deserialization()
{
    using NeuralNetwork    = tr::FeedForwardNeuro<li::Vector, li::Matrix, li::Linear, tr::Container, float>;
    using NeuralSerializer = tr::FFNNSerializer<li::Vector, li::Matrix, tr::Container, float>;
    using NeuralFunctional = tr::FFNNFunctional<NeuralNetwork>;

    std::ifstream in("D:\\speed_test.bin", std::ios::binary);
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

    tr::Container<li::Vector<float>> train_in
    {
        {1, 0, 1, 1},
        {1, 1, 1, 0},
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {1, 0, 1, 0},
        {0, 0, 1, 1}
    };
    tr::Container<li::Vector<float>> train_out
    {
        {1, 0, 0},
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 1},
        {0, 1, 0},
        {1, 0, 0}
    };

    util::test_neuro(net, train_in, train_out);
    util::check_neuro(net, train_in, train_out);
}

void speed_test()
{
    using NeuralNetwork    = tr::FeedForwardNeuro<li::Vector, li::Matrix, li::Linear, tr::Container, float>;
    using NeuralSerializer = tr::FFNNSerializer<li::Vector, li::Matrix, tr::Container, float>;
    using NeuralFunctional = tr::FFNNFunctional<NeuralNetwork>;

    NeuralNetwork net({4, 4, 5, 4, 3});
    NeuralFunctional manage;

    net.initializeInnerStruct(random_real);

    net.function.setActivation(manage.get(ActivationId::relu));
    net.function.setNormalization(manage.get(ActivationId::softmax));
    net.function.setLoss(manage.get(LossId::CCE));

    //net.function.setOptimization(manage.get(OptimizationId::ada_grad));

    tr::Container<li::Vector<float>> train_in
    {
        {1, 0, 1, 1},
        {1, 1, 1, 0},
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {1, 0, 1, 0},
        {0, 0, 1, 1}
    };
    tr::Container<li::Vector<float>> train_out
    {
        {1, 0, 0},
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 1},
        {0, 1, 0},
        {1, 0, 0}
    };

    std::cout << "Before train\n";
    util::test_neuro(net, train_in, train_out);
    util::check_neuro(net, train_in, train_out);

    util::Timer t;
    //
    net.trainBatch(train_in, train_out, 0.1, 100000);
    net.trainMiniBatch(train_in, train_out, 0.1, 100000, 2, std::rand);
    net.trainStochastic(train_in, train_out, 0.15, 100000, std::rand);
    //
    //net.trainOptimize(train_in, train_out, 0.1, 1000, 6, std::rand);
    std::cout << "Train time: " << t.elapsed() << '\n';

    std::cout << "After train\n";
    util::test_neuro(net, train_in, train_out);
    util::check_neuro(net, train_in, train_out);

    std::ofstream out("D:\\speed_test.bin", std::ios::binary);
    if(!out.is_open()) return;

    NeuralSerializer sr;

    sr.prepare(net);
    sr.serialize(out);
    out.close();

    std::cout << "End serialization\n";
}

//
int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::cout << std::fixed << std::setprecision(6);

    //speed_test();
    speed_test_deserialization();

    return 0;
}
//
