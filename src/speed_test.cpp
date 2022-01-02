#include "Trixy/Neuro/neuro_core.hpp" // FeedForwardNeuro, Functional, Serializer
#include "Trixy/Lique/lique_core.hpp" // Vector, Matrix, Linear

#include "Trixy/Container/container.hpp" // Container
#include "Utility/util.hpp" // Timer, test_neuro, check_neuro

#include <cstdlib> // rand, srand, size_t
#include <ctime> // time
#include <iostream> // cin, cout
#include <fstream> // ifstream, ofstream
#include <iomanip> // setprecision, fixed

namespace tr = trixy;
namespace li = lique;

using namespace tr::function;

static li::Linear<li::Vector, li::Matrix, double> linear;

float random_real() noexcept
{
    static constexpr int range = 1000;
    return static_cast<float>(std::rand() % (2 * range + 1) - range) / range;
}

float random_normal() noexcept
{
    static constexpr int range = 1000;
    static constexpr float pi = 3.14159265;

    static float x;

    x = static_cast<float>(std::rand() % (2 * range + 1) - range) / range;

    return std::exp(- x * x) / std::sqrt(2 * pi);
}
//
void speed_test_deserialization()
{
    using NeuralNetwork    = tr::FeedForwardNeuro<li::Vector, li::Matrix, li::Linear, tr::Container, float>;
    using NeuralFunctional = tr::Functional<NeuralNetwork>;
    using NeuralSerializer = tr::Serializer<NeuralNetwork>;

    std::ifstream in("D:\\Serialized\\speed_test.bin", std::ios::binary);
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
//
void speed_test()
{
    using NeuralNetwork    = tr::FeedForwardNeuro<li::Vector, li::Matrix, li::Linear, tr::Container, float>;
    using NeuralFunctional = tr::Functional<NeuralNetwork>;
    using NeuralSerializer = tr::Serializer<NeuralNetwork>;

    NeuralNetwork net({4, 4, 5, 4, 3});
    NeuralFunctional manage;

    net.initializeInnerStruct(random_real);

    net.function.setActivation(manage.get<ActivationId::relu>());
    net.function.setNormalization(manage.get<ActivationId::softmax>());
    net.function.setLoss(manage.get<LossId::CCE>());

    auto optimizer = manage.get<OptimizationId::adam>(net, 0.001);

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
    net.trainBatch(train_in, train_out, 100000, manage.get<OptimizationId::grad_descent>(net, 0.1));

    net.trainMiniBatch(train_in, train_out, 100000, 2, std::rand, optimizer);

    optimizer.reset();
    net.trainStochastic(train_in, train_out, 100000, std::rand, optimizer);
    //
    std::cout << "Train time: " << t.elapsed() << '\n';

    std::cout << "After train\n";
    util::test_neuro(net, train_in, train_out);
    util::check_neuro(net, train_in, train_out);

    std::ofstream out("D:\\Serialized\\speed_test.bin", std::ios::binary);
    if(!out.is_open()) return;

    NeuralSerializer sr;
    sr.prepare(net);
    sr.serialize(out);
    out.close();

    std::cout << "End of serialization\n";
}
//

//
int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::cout << std::fixed << std::setprecision(6);

    speed_test();
    //speed_test_deserialization();

    return 0;
}
//
/*
struct A
{
    // will work
    void f(int N) { std::cout << N; }
    template <int N>
    void f() { f(N); }
    //
    // wont work
    template <int N>
    void f() { std::cout << N; }

    void f(int N) { f<N>(); }
    //
};
*/
