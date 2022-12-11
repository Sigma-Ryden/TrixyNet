#include <Trixy/Core.hpp>
// TrixyNet, Functional, Optimizer, Training
// Serializer, Tensor, Linear, Container, Random

#include <Utility/Core.hpp> // Timer, statistic

#include <fstream> // ifstream, ofstream
#include <iostream> // cin, cout
#include <iomanip> // setprecision, fixed

namespace tr = trixy;
namespace li = trixy::lique;

using namespace tr::functional;
using namespace tr::train;

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
    std::ifstream file("D:\\Serialized\\speed_test.bin", std::ios::binary);
    if (not file.is_open()) return;

    auto idata = get_speed_test_idata<TrixyNet>();
    auto odata = get_speed_test_odata<TrixyNet>();

    TrixyNetSerializer sr;
    sr.deserialize(file);
    file.close();

    TrixyNet net(sr.topology());
    TrixyNetFunctional manage;

    net.inner.init(sr.bias(), sr.weight());

    net.function.activation(manage.get(sr.all_activation_id()));
    net.function.loss(manage.get(sr.loss_id()));

    statistic(net, idata, odata);
}

void speed_test()
{
    auto idata = get_speed_test_idata<TrixyNet>();
    auto odata = get_speed_test_odata<TrixyNet>();

    TrixyNet net({4, 4, 5, 4, 3});

    TrixyNetFunctional manage;
    TrixyNetTraining train(net);

    RandomFloating random;
    net.inner.init([&] { return random(-.5, .5); });

    net.function.activation(manage.get<ActivationId::relu>());
    net.function.normalization(manage.get<ActivationId::softmax>());

    net.function.loss(manage.get<LossId::CCE>());

    auto grad = GradDescentOptimizer(net, 0.1); // new style
    auto adam = manage.get<OptimizationId::adam>(net, 0.001);

    statistic(net, idata, odata);

    Timer t;
    train.batch(idata, odata, grad, 100000);
    train.stochastic(idata, odata, grad, 100000, RandomIntegral{});
    train.mini_batch(idata, odata, adam, 15000, 2);

    std::cout << "Train time: " << t.elapsed() << '\n';

    std::cout << "After train\n";
    statistic(net, idata, odata);

    std::ofstream file("D:\\Serialized\\speed_test.bin", std::ios::binary);
    if (not file.is_open()) return;

    TrixyNetSerializer sr;
    sr.serialize(file, net);
    file.close();

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
