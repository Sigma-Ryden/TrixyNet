#include <cstdlib> // rand, srand, size_t
#include <ctime> // time
#include <iostream> // cin, cout
#include <fstream> // ifstream, ofstream
#include <iomanip> // setprecision, fixed

#include "Trixy/Lique/lique_linear.hpp" // Linear
#include "Trixy/Lique/lique_matrix.hpp" // Matrix
#include "Trixy/Lique/lique_vector.hpp" // Vector

#include "Trixy/Neuro/neuro_core.hpp" // Neuro, Activation, Loss, Optimization
#include "Trixy/Neuro/neuro_functional.hpp" // NeuroManager, NeuroSerializer

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
void simple_test_des()
{
    using namespace trixy::function;

    using NeuralFeedForward = tr::Neuro<li::Vector, li::Matrix, li::Linear, Container, Precision>;
    using NeuralManager     = tr::NeuroManager<li::Vector, li::Matrix, Precision>;
    using NeuralSerializer  = tr::NeuroSerializer<li::Vector, li::Matrix, Container, Precision>;

    std::ifstream in("D:\\test_new.bin", std::ios::binary);
    if(!in.is_open()) return;

    NeuralSerializer sr;

    sr.deserialize(in);

    NeuralFeedForward net = sr.getTopology();
    NeuralManager manage;

    net.initializeInnerStruct(sr.getBias(), sr.getWeight());

    net.setActivationFunction(manage.template get<Activation>(sr.getActivationId()));
    net.setNormalizationFunction(manage.template get<Activation>(sr.getNormalizationId()));
    net.setLossFunction(manage.template get<Loss>(sr.getLossId()));

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

    utils::testNeuro(net, train_in, train_out);

    std::cout << "Loss: " << net.loss(train_in, train_out) << '\n';
    std::cout << "Normal accuracy: " << net.accuracy(train_in, train_out) << '\n';
    std::cout << "Global accuracy: " << net.globalAccuracy(train_in, train_out, 0.05) << '\n';
    std::cout << "Full accuracy: " << net.fullAccuracy(train_in, train_out, 0.05) << '\n';
}

template <typename Precision>
void simple_test()
{
    using namespace trixy::function;

    using NeuralFeedForward = tr::Neuro<li::Vector, li::Matrix, li::Linear, Container, Precision>;
    using NeuralManager     = tr::NeuroManager<li::Vector, li::Matrix, Precision>;
    using NeuralSerializer  = tr::NeuroSerializer<li::Vector, li::Matrix, Container, Precision>;

    NeuralFeedForward net({4, 4, 5, 4, 3});
    NeuralManager manage;

    net.initializeInnerStruct(random_real);

    net.setActivationFunction(manage.template get<Activation>(activation_id::relu));
    net.setNormalizationFunction(manage.template get<Activation>(activation_id::softmax));

    net.setLossFunction(manage.template get<Loss>(loss_id::CCE));
    //net.setOptimizationFunction(manage.template get<Optimization>(optimization_id::ada_grad));

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
    //net.trainBatch(train_in, train_out, 0.15, 100000);
    //net.trainMiniBatch(train_in, train_out, 0.15, 100000, 2, std::rand);
    net.trainStochastic(train_in, train_out, 0.15, 1000, std::rand);
    //
    //net.trainOptimize(train_in, train_out, 0.1, 500, 6, std::rand);
    /*
    for(int i = 1; i <= 10; ++i)
    {
        net.trainOptimize(train_in, train_out, 0.1, 100, 6, std::rand);
        std::cout << '<' << i << "> Loss: " << net.loss(train_in, train_out) << '\n';
    }
    */
    std::cout << t.elapsed() << '\n';
    std::cout << "After train\n";

    utils::testNeuro(net, train_in, train_out);
    std::cout << "Normal accuracy: " << net.accuracy(train_in, train_out) << '\n';
    std::cout << "Global accuracy: " << net.globalAccuracy(train_in, train_out, 0.05) << '\n';
    std::cout << "Full accuracy: " << net.fullAccuracy(train_in, train_out, 0.05) << '\n';
    std::cout << "Loss: " << net.loss(train_in, train_out) << '\n';

    std::ofstream out("D:\\test_new.bin", std::ios::binary);
    if(!out.is_open()) return;

    NeuralSerializer sr;

    sr.prepare(net);
    sr.serialize(out);

    std::cout << "END\n";
}

void simple_test2_des()
{
    using namespace trixy::function;

    using NeuralFeedForward = tr::Neuro<li::Vector, li::Matrix, li::Linear, Container, float>;
    using NeuralManager     = tr::NeuroManager<li::Vector, li::Matrix, float>;
    using NeuralSerializer  = tr::NeuroSerializer<li::Vector, li::Matrix, Container, float>;

    std::ifstream in("D:\\simple_test2.bin");

    if (!in.is_open()) return;

    NeuralSerializer sr;

    sr.deserialize(in);

    NeuralFeedForward net = sr.getTopology();
    NeuralManager manage;

    net.initializeInnerStruct(sr.getBias(), sr.getWeight());

    net.setActivationFunction(manage.get<Activation>(sr.getActivationId()));
    net.setNormalizationFunction(manage.get<Activation>(sr.getNormalizationId()));
    net.setLossFunction(manage.get<Loss>(sr.getLossId()));

    // Train set (in/out)
    Container<li::Vector<float>> train_in
    {
        {-2, -1},
        {23, 6},
        {10, 4},
        {-15, -6}
    };
    Container<li::Vector<float>> train_out
    {
        {1, 0},
        {0, 1},
        {0, 1},
        {1, 0}
    };

    for(std::size_t i = 0; i < train_in.size(); ++i)
        train_in[i].apply([] (float x) -> float { return x / 25.0; });

    utils::testNeuro(net, train_in, train_out);

    std::cout << "NNetwork tarin normal accuracy: " << net.accuracy(train_in, train_out) << '\n';
    std::cout << "NNetwork tarin global accuracy: " << net.globalAccuracy(train_in, train_out, 0.05) << '\n';
    std::cout << "NNetwork tarin full accuracy: " << net.fullAccuracy(train_in, train_out, 0.05) << '\n';
    std::cout << "NNetwork tarin Loss: " << net.loss(train_in, train_out) << '\n';
}

void simple_test2()
{
    using namespace trixy::function;

    using NeuralFeedForward = tr::Neuro<li::Vector, li::Matrix, li::Linear, Container, float>;
    using NeuralManager     = tr::NeuroManager<li::Vector, li::Matrix, float>;
    using NeuralSerializer  = tr::NeuroSerializer<li::Vector, li::Matrix, Container, float>;

    NeuralFeedForward net({2, 2, 2});
    NeuralManager manage;

    net.initializeInnerStruct(random_real);

    net.setActivationFunction(manage.get<Activation>(activation_id::relu));
    net.setNormalizationFunction(manage.get<Activation>(activation_id::softmax));

    net.setLossFunction(manage.get<Loss>(loss_id::CCE));
    net.setOptimizationFunction(manage.get<Optimization>(optimization_id::ada_grad));

    // Train set (in/out)
    Container<li::Vector<float>> train_in
    {
        {-2, -1},
        {23, 6},
        {10, 4},
        {-15, -6}
    };
    Container<li::Vector<float>> train_out
    {
        {1, 0},
        {0, 1},
        {0, 1},
        {1, 0}
    };

    for(std::size_t i = 0; i < train_in.size(); ++i)
        train_in[i].apply([] (float x) -> float { return x / 25.0; });

    // Full processing
    Timer t;
    net.trainOptimize(train_in, train_out, 0.1, 1000, 2, std::rand);
    std::cout << t.elapsed() << '\n';

    utils::testNeuro(net, train_in, train_out);

    std::cout << "NNetwork tarin normal accuracy: " << net.accuracy(train_in, train_out) << '\n';
    std::cout << "NNetwork tarin global accuracy: " << net.globalAccuracy(train_in, train_out, 0.05) << '\n';
    std::cout << "NNetwork tarin full accuracy: " << net.fullAccuracy(train_in, train_out, 0.05) << '\n';
    std::cout << "NNetwork tarin Loss: " << net.loss(train_in, train_out) << '\n';
}

//
int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::cout << std::fixed << std::setprecision(6);

    simple_test_des<float>();
    //simple_test2();

    std::cin.get();

    return 0;
}
//
