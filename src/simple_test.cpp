#include "Trixy/Neuro/NeuroCore.hpp" // FeedForwardNet, Functional, Serializer
#include "Trixy/Lique/LiqueCore.hpp" // Vector, Matrix, Linear

#include "Trixy/Container/Container.hpp" // Container
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

tr::Container<li::Vector<float>> get_simple_test_idata()
{
    return
    {
        {-0.08, 0.04},
        {0.92,  0.24},
        {0.4,   0.16},
        {-0.0, -0.24}
    };
}

tr::Container<li::Vector<float>> get_simple_test_odata()
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

    using TrixyNet           = tr::FeedForwardNet<li::Vector, li::Matrix, li::Linear, tr::Container, float>;
    using TrixyNetFunctional = tr::Functional<TrixyNet>;
    using TrixyNetSerializer = tr::Serializer<TrixyNet>;

    std::ifstream in("D:\\Serialized\\simple_test.bin");
    if (!in.is_open()) return;

    auto train_in = get_simple_test_idata();
    auto train_out = get_simple_test_odata();

    TrixyNetSerializer sr;
    sr.deserialize(in);
    in.close();

    TrixyNet net = sr.getTopology();
    TrixyNetFunctional manage;

    net.initializeInnerStruct(sr.getBias(), sr.getWeight());

    net.function.setActivation(manage.get(sr.getActivationId()));
    net.function.setNormalization(manage.get(sr.getNormalizationId()));
    net.function.setLoss(manage.get(sr.getLossId()));

    util::test_neuro(net, train_in, train_out);
    util::check_neuro(net, train_in, train_out);
}

template <typename Precision>
void simple_test()
{
    using namespace tr::functional;

    using TrixyNet           = tr::FeedForwardNet<li::Vector, li::Matrix, li::Linear, tr::Container, float>;
    using TrixyNetFunctional = tr::Functional<TrixyNet>;
    using TrixyNetSerializer = tr::Serializer<TrixyNet>;

    auto train_in = get_simple_test_idata();
    auto train_out = get_simple_test_odata();

    TrixyNet net({2, 2, 2});
    TrixyNetFunctional manage;

    net.initializeInnerStruct([]() -> Precision {
        static constexpr int range = 1000;
        return static_cast<Precision>(generator() % (2 * range + 1) - range) / range;
    });

    net.function.setActivation(manage.template get<ActivationId::relu>());
    net.function.setNormalization(manage.template get<ActivationId::softmax>());

    net.function.setLoss(manage.template get<LossId::CCE>());

    auto optimizer = manage.template get<OptimizationId::grad_descent>(net, 0.1);

    util::Timer t;
    net.trainStochastic(train_in, train_out, 1000, generator, optimizer);
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
