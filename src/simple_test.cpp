#include "Trixy/Neuro/NeuroCore.hpp" // FeedForwardNet, Functional, Training, Serializer
#include "Trixy/Lique/LiqueCore.hpp" // Vector, Matrix, Linear

#include "Trixy/Container/Container.hpp" // Container
#include "Utility/util.hpp" // Timer, test_neuro, check_neuro

#include <iostream> // cin, cout
#include <iomanip> // setprecision, fixed
#include <fstream> // ifstream, ofstream
#include <random> // mt19937

namespace tr = trixy;
namespace li = trixy::lique;

int generator()
{
    static std::mt19937 gen;

    return static_cast<int>(gen());
}

template <typename Precision>
tr::Container<li::Vector<Precision>> get_simple_test_idata()
{
    return
    {
        {-0.08, 0.04},
        {0.92,  0.24},
        {0.4,   0.16},
        {-0.0, -0.24}
    };
}

template <typename Precision>
tr::Container<li::Vector<Precision>> get_simple_test_odata()
{
    return
    {
        {1, 0},
        {0, 1},
        {0, 1},
        {1, 0}
    };
}

template <typename Precision>
void simple_test_deserialization()
{
    using namespace tr::functional;

    using TrixyNet           = tr::FeedForwardNet<li::Vector, li::Matrix, li::Linear, tr::Container, Precision>;
    using TrixyNetFunctional = tr::Functional<TrixyNet>;
    using TrixyNetSerializer = tr::Serializer<TrixyNet>;

    std::ifstream in("D:\\Serialized\\simple_test.bin");
    if (!in.is_open()) return;

    auto train_in = get_simple_test_idata<Precision>();
    auto train_out = get_simple_test_odata<Precision>();

    TrixyNetSerializer sr;
    sr.deserialize(in);
    in.close();

    TrixyNet net = sr.getTopology();
    TrixyNetFunctional manage;

    net.initializeInnerStruct(sr.getBias(), sr.getWeight());

    net.function.setAllActivation(manage.get(sr.getAllActivationId()));
    net.function.setLoss(manage.get(sr.getLossId()));

    util::test_neuro(net, train_in, train_out);
    util::check_neuro(net, train_in, train_out);
}

template <typename Precision>
void simple_test()
{
    using namespace tr::functional;

    using TrixyNet           = tr::FeedForwardNet<li::Vector, li::Matrix, li::Linear, tr::Container, Precision>;
    using TrixyNetFunctional = tr::Functional<TrixyNet>;
    using TrixyNetTraining   = tr::train::Training<TrixyNet>;
    using TrixyNetSerializer = tr::Serializer<TrixyNet>;

    auto train_in = get_simple_test_idata<Precision>();
    auto train_out = get_simple_test_odata<Precision>();

    TrixyNet net({2, 2, 2});
    TrixyNetFunctional manage;
    TrixyNetTraining teach(net);

    net.initializeInnerStruct([]() -> Precision {
        static constexpr int range = 1000;
        return static_cast<Precision>(generator() % (2 * range + 1) - range) / range;
    });

    net.function.setActivation(manage.template get<ActivationId::relu>());
    net.function.setNormalization(manage.template get<ActivationId::softmax>());

    net.function.setLoss(manage.template get<LossId::CCE>());

    auto optimizer = manage.template get<OptimizationId::adam>(net, 0.01);

    util::Timer t;
    teach.trainStochastic(train_in, train_out, 1000, generator, optimizer);
    std::cout << "Train time: " << t.elapsed() << '\n';

    util::test_neuro(net, train_in, train_out);
    util::check_neuro(net, train_in, train_out);

    std::ofstream out("D:\\Serialized\\simple_test.bin");
    if(!out.is_open()) return;

    TrixyNetSerializer sr;
    sr.prepare(net);
    sr.serialize(out);
    out.close();

    std::cout << "End of serialization\n";
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
