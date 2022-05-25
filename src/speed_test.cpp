#include <Trixy/Core.hpp>
// TrixyNet, Functional, Optimizer, Training
// Serializer, Tensor, Linear, Container, Random

#include <Utility/utility.hpp> // Timer, statistic

#include <fstream> // ifstream, ofstream
#include <iostream> // cin, cout
#include <iomanip> // setprecision, fixed

namespace tr = trixy;
namespace li = trixy::lique;

using namespace tr::functional;
using namespace tr::train;

using namespace utility;

using TrixyNet = tr::FeedForwardNet<tr::TypeSet<float>>;

using TrixyNetFunctional = tr::Functional<TrixyNet>;
using TrixyNetTraining   = tr::train::Training<TrixyNet>;
using TrixyNetSerializer = tr::Serializer<TrixyNet>;

using RandomIntegral     = tr::utility::RandomIntegral<>;
using RandomFloating     = tr::utility::RandomFloating<>;

template <class Net>
typename Net::template Container<typename Net::Vector> get_speed_test_idata()
{
    return
    {
        {1, 0, 1, 1},
        {1, 1, 1, 0},
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {1, 0, 1, 0},
        {0, 0, 1, 1}
    };
}

template <class Net>
typename Net::template Container<typename Net::Vector> get_speed_test_odata()
{
    return
    {
        {1, 0, 0},
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 1},
        {0, 1, 0},
        {1, 0, 0}
    };
}

void speed_test_deserialization()
{
    std::ifstream in("D:\\Serialized\\speed_test.bin", std::ios::binary);
    if (not in.is_open()) return;

    auto idata = get_speed_test_idata<TrixyNet>();
    auto odata = get_speed_test_odata<TrixyNet>();

    TrixyNetSerializer sr;
    sr.deserialize(in);
    in.close();

    TrixyNet net(sr.getTopology());
    TrixyNetFunctional manage;

    net.inner.initialize(sr.getBias(), sr.getWeight());

    net.function.activationSet(manage.get(sr.getAllActivationId()));
    net.function.loss(manage.get(sr.getLossId()));

    utility::statistic(net, idata, odata);
}

void speed_test()
{
    auto idata = get_speed_test_idata<TrixyNet>();
    auto odata = get_speed_test_odata<TrixyNet>();

    TrixyNet net({4, 4, 5, 4, 3});

    TrixyNetFunctional manage;
    TrixyNetTraining teach(net);

    RandomFloating random;
    net.inner.initialize([&] { return random(-.5, .5); });

    net.function.activation(manage.get<ActivationId::relu>());
    net.function.normalization(manage.get<ActivationId::softmax>());
    net.function.loss(manage.get<LossId::CCE>());

    auto grad = GradDescentOptimizer(net, 0.1); // new style
    auto adam = manage.get<OptimizationId::adam>(net, 0.001);

    utility::statistic(net, idata, odata);

    utility::Timer t;
    teach.trainBatch(idata, odata, grad, 100000);
    teach.trainStochastic(idata, odata, grad, 100000, RandomIntegral{});
    teach.trainMiniBatch(idata, odata, adam, 15000, 2);

    std::cout << "Train time: " << t.elapsed() << '\n';

    std::cout << "After train\n";
    utility::statistic(net, idata, odata);

    std::ofstream out("D:\\Serialized\\speed_test.bin", std::ios::binary);
    if (not out.is_open()) return;

    TrixyNetSerializer sr;
    sr.serialize(out, net);
    out.close();

    std::cout << "End of serialization\n";
}
//
int main()
{
    std::cout << std::fixed << std::setprecision(6);

    speed_test();
    speed_test_deserialization();

    //std::cin.get();

    return 0;
}
//
