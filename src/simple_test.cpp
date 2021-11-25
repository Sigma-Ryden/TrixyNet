#include <iostream> // cin, cout
#include <iomanip> // setprecision, fixed
#include <fstream> // ifstream, ofstream
#include <random> // mt19937

#include "Trixy/Lique/lique_linear.hpp" // Linear
#include "Trixy/Lique/lique_matrix.hpp" // Matrix
#include "Trixy/Lique/lique_vector.hpp" // Vector

#include "Trixy/Neuro/neuro_core.hpp" // Neuro, Activation, Loss, Optimization
#include "Trixy/Neuro/neuro_functional.hpp" // NeuroManager, NeuroSerializer

#include "Trixy/Container/container.hpp" // Container

#include "Timer/timer.h" // Timer
#include "UtilityMaster/util.hpp" // testNeuro

namespace tr = trixy;
namespace li = lique;

int random()
{
    static std::mt19937 gen;

    return static_cast<int>(gen());
}

template <typename Precision>
void simple_test_deserialization()
{
    using namespace tr::function;

    using NeuralFeedForward = tr::Neuro<li::Vector, li::Matrix, li::Linear, Container, Precision>;
    using NeuralFunctional  = tr::FunctionalManager<li::Vector, li::Matrix, Precision>;
    using NeuralSerializer  = tr::NeuroSerializer<li::Vector, li::Matrix, Container, Precision>;

    std::ifstream in("D:\\simple_test.bin");
    if (!in.is_open()) return;

    NeuralFunctional sr;

    sr.deserialize(in);
    in.close();

    NeuralFeedForward net = sr.getTopology();
    NeuralFunctional manage;

    net.initializeInnerStruct(sr.getBias(), sr.getWeight());

    net.function.setActivation(manage.template get<Activation>(sr.getActivationId()));
    net.function.setNormalization(manage.template get<Activation>(sr.getNormalizationId()));
    net.function.setLoss(manage.template get<Loss>(sr.getLossId()));

    Container<li::Vector<Precision>> train_in
    {
        {-0.08, 0.04},
        {0.92,  0.24},
        {0.4,   0.16},
        {-0.0, -0.24}
    };
    Container<li::Vector<Precision>> train_out
    {
        {1, 0},
        {0, 1},
        {0, 1},
        {1, 0}
    };

    util::testNeuro(net, train_in, train_out);
    util::checkNeuro(net, train_in, train_out);
}

template <typename Precision>
void simple_test()
{
    using namespace tr::function;

    using NeuralFeedForward = tr::Neuro<li::Vector, li::Matrix, li::Linear, Container, Precision>;
    using NeuralManager     = tr::FunctionalManager<li::Vector, li::Matrix, Precision>;
    using NeuralSerializer  = tr::NeuroSerializer<li::Vector, li::Matrix, Container, Precision>;

    NeuralFeedForward net({2, 2, 2});
    NeuralManager manage;

    net.initializeInnerStruct([]() -> Precision {
        static int range = 1000;
        return static_cast<Precision>(random() % (2 * range + 1) - range) / range;
    });

    net.function.setActivation(manage.template get<Activation>(activation_id::relu));
    net.function.setNormalization(manage.template get<Activation>(activation_id::softmax));

    net.function.setLoss(manage.template get<Loss>(loss_id::CCE));

    Container<li::Vector<Precision>> train_in
    {
        {-0.08, 0.04},
        {0.92,  0.24},
        {0.4,   0.16},
        {-0.0, -0.24}
    };
    Container<li::Vector<Precision>> train_out
    {
        {1, 0},
        {0, 1},
        {0, 1},
        {1, 0}
    };

    Timer t;
    net.trainStochastic(train_in, train_out, 0.1, 1000, random);
    std::cout << "Train time: " << t.elapsed() << '\n';

    util::testNeuro(net, train_in, train_out);
    util::checkNeuro(net, train_in, train_out);

    std::ofstream out("D:\\simple_test.bin");
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

    simple_test();
    simple_test_deserialization();

    return 0;
}
*/
