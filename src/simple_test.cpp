#include <Trixy/Core.hpp>
// TrixyNet, Functional, Optimizer, Training
// Serializer, Tensor, Linear, Container, Random

#include <Utility/utility.hpp> // Timer, statistic

#include <iostream> // cin, cout
#include <iomanip> // setprecision, fixed
#include <fstream> // ifstream, ofstream

namespace tr = trixy;
namespace li = trixy::lique;

using namespace tr::functional;

using namespace utility;

using TrixyNet = tr::FeedForwardNet<tr::TypeSet<float>>;

using TrixyNetFunctional = tr::Functional<TrixyNet>;
using TrixyNetTraining   = tr::train::Training<TrixyNet>;
using TrixyNetSerializer = tr::Serializer<TrixyNet>;

using RandomIntegral     = tr::utility::RandomIntegral<>;
using RandomFloating     = tr::utility::RandomFloating<>;

template <class Net>
typename Net::template Container<typename Net::Vector> get_simple_test_idata()
{
    return
    {
        {-0.08, 0.04},
        { 0.92, 0.24},
        { 0.4,  0.16},
        {-0.0, -0.24}
    };
}

template <class Net>
typename Net::template Container<typename Net::Vector> get_simple_test_odata()
{
    return
    {
        {1, 0},
        {0, 1},
        {0, 1},
        {1, 0}
    };
}

void simple_test_deserialization()
{
    std::ifstream file("D:\\Serialized\\simple_test.bin", std::ios::binary);
    if (not file.is_open()) return;

    auto idata = get_simple_test_idata<TrixyNet>();
    auto odata = get_simple_test_odata<TrixyNet>();

    TrixyNetSerializer sr;
    sr.deserialize(file);
    file.close();

    TrixyNet net(sr.getTopology());
    TrixyNetFunctional manage;

    net.inner.initialize(sr.getBias(), sr.getWeight());

    net.function.activationSet(manage.get(sr.getAllActivationId()));
    net.function.loss(manage.get(sr.getLossId()));

    utility::statistic(net, idata, odata);
}

void simple_test()
{
    auto idata = get_simple_test_idata<TrixyNet>();
    auto odata = get_simple_test_odata<TrixyNet>();

    TrixyNet net({2, 2, 2});
    TrixyNetFunctional manage;
    TrixyNetTraining teach(net);

    net.inner.initialize(RandomFloating{});

    net.function.activation(manage.get<ActivationId::relu>());
    net.function.normalization(manage.get<ActivationId::softmax>());

    net.function.loss(manage.get<LossId::CCE>());

    auto optimizer = manage.get<OptimizationId::adam>(net, 0.01);

    utility::Timer t;
    teach.trainStochastic(idata, odata, optimizer, 2000, RandomIntegral{});
    std::cout << "Train time: " << t.elapsed() << '\n';

    utility::statistic(net, idata, odata);

    std::ofstream file("D:\\Serialized\\simple_test.bin", std::ios::binary);
    if (not file.is_open()) return;

    TrixyNetSerializer sr;

    sr.prepare(net);
    sr.serialize(file);
    file.close();

    std::cout << "End of serialization\n";
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
