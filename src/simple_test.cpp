#include "Trixy/Neuro/neuro_core.hpp" // FeedForwardNeuro, FFNNFunctional, FFNNSerializer
#include "Trixy/Lique/lique_core.hpp" // Vector, Matrix, Linear

#include "Trixy/Container/container.hpp" // Container
#include "Utility/util.hpp" // Timer, test_neuro, check_neuro

#include <iostream> // cin, cout
#include <iomanip> // setprecision, fixed
#include <fstream> // ifstream, ofstream
#include <random> // mt19937

namespace tr = trixy;
namespace li = lique;

int generator()
{
    static std::mt19937 gen;

    return static_cast<int>(gen());
}

template <typename Precision>
void simple_test_deserialization()
{
    using namespace tr::function;

    using NeuralNetwork    = tr::FeedForwardNeuro<li::Vector, li::Matrix, li::Linear, tr::Container, Precision>;
    using NeuralSerializer = tr::Serializer<NeuralNetwork>;
    using NeuralFunctional = tr::Functional<NeuralNetwork>;

    std::ifstream in("D:\\Serialized\\simple_test.bin");
    if (!in.is_open()) return;

    NeuralFunctional sr;

    sr.deserialize(in);
    in.close();

    NeuralNetwork net = sr.getTopology();
    NeuralFunctional manage;

    net.initializeInnerStruct(sr.getBias(), sr.getWeight());

    net.function.setActivation(manage.get(sr.getActivationId()));
    net.function.setNormalization(manage.get(sr.getNormalizationId()));
    net.function.setLoss(manage.get(sr.getLossId()));

    tr::Container<li::Vector<Precision>> train_in
    {
        {-0.08, 0.04},
        {0.92,  0.24},
        {0.4,   0.16},
        {-0.0, -0.24}
    };
    tr::Container<li::Vector<Precision>> train_out
    {
        {1, 0},
        {0, 1},
        {0, 1},
        {1, 0}
    };

    util::test_neuro(net, train_in, train_out);
    util::check_neuro(net, train_in, train_out);
}

template <typename Precision>
void simple_test()
{
    using namespace tr::function;

    using NeuralNetwork    = tr::FeedForwardNeuro<li::Vector, li::Matrix, li::Linear, tr::Container, Precision>;
    using NeuralSerializer = tr::Serializer<NeuralNetwork>;
    using NeuralFunctional = tr::Functional<NeuralNetwork>;

    NeuralNetwork net({2, 2, 2});
    NeuralFunctional manage;

    net.initializeInnerStruct([]() -> Precision {
        static int range = 1000;
        return static_cast<Precision>(generator() % (2 * range + 1) - range) / range;
    });

    net.function.setActivation(manage.get(ActivationId::relu));
    net.function.setNormalization(manage.get(ActivationId::softmax));

    net.function.setLoss(manage.get(LossId::CCE));

    tr::Container<li::Vector<Precision>> train_in
    {
        {-0.08, 0.04},
        {0.92,  0.24},
        {0.4,   0.16},
        {-0.0, -0.24}
    };
    tr::Container<li::Vector<Precision>> train_out
    {
        {1, 0},
        {0, 1},
        {0, 1},
        {1, 0}
    };

    util::Timer t;
    net.trainStochastic(train_in, train_out, 0.1, 1000, generator);
    std::cout << "Train time: " << t.elapsed() << '\n';

    util::test_neuro(net, train_in, train_out);
    util::check_neuro(net, train_in, train_out);

    std::ofstream out("D:\\Serialized\\simple_test.bin");
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
    std::cout << std::fixed << std::setprecision(6);

    simple_test<double>();
    simple_test_deserialization<double>();

    return 0;
}
*/
