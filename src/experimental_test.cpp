#include <Trixy/Core.hpp>
// TrixyNet, Functional, Optimizer, Training
// Serializer, Tensor, Linear, Container, Random

#include <Utility/utility.hpp> // Timer, statistic

#include <iostream> // cin, cout
#include <iomanip> // setprecision, fixed

#include <Trixy/Neuro/Network/ExperimentalNet.hpp> // Ex

namespace tr = trixy;
namespace li = trixy::lique;

using namespace tr::functional;
using namespace tr::functional::activation;
using namespace tr::train;

using namespace utility;

using TrixyNet = tr::FeedForwardNet<tr::TypeSet<float>>;
using ExNet = tr::Ex<tr::TypeSet<float>>;

using TrixyNetFunctional = tr::Functional<TrixyNet>;
using TrixyNetTraining   = tr::train::Training<TrixyNet>;
using TrixyNetSerializer = tr::Serializer<TrixyNet>;

using RandomIntegral     = tr::RandomIntegral<>;
using RandomFloating     = tr::RandomFloating<>;

template <class Activation>
using FullyConnected = tr::layer::FullyConnected<ExNet, Activation>;

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

void experimental_test()
{
    auto idata = get_speed_test_idata<TrixyNet>();
    auto odata = get_speed_test_odata<TrixyNet>();

    TrixyNet net1({4, 4, 5, 4, 3});
    ExNet net2;

    net2.add(new FullyConnected<ReLU>(4, 4));
    net2.add(new FullyConnected<ReLU>(4, 5));
    net2.add(new FullyConnected<ReLU>(5, 4));
    net2.add(new FullyConnected<SoftMax>(4, 3));

    TrixyNetFunctional manage;
    TrixyNetTraining teach(net1);

    RandomFloating random;

    net1.inner.initialize([&] { return random(-.5, .5); });
    net2.init(net1.inner.B.base(), net1.inner.W.base());

    net1.function.activation(manage.get<ActivationId::relu>());
    net1.function.normalization(manage.get<ActivationId::softmax>());
    net1.function.loss(manage.get<LossId::CCE>());

    auto grad = GradDescentOptimizer(net1, 0.1); // new style

    utility::statistic(net1, idata, odata);
    utility::statistic(net2, idata, odata);

    constexpr int epoch = 1;

    utility::Timer t;

    teach.trainBatch(idata, odata, grad, epoch);
    std::cout << "Train net1 time: " << t.elapsed() << '\n';

    net2.train(idata, odata, epoch, 0.1);
    std::cout << "Train net2 time: " << t.elapsed() << '\n';

    utility::statistic(net1, idata, odata);
    utility::statistic(net2, idata, odata);
}
/*
int main()
{
    std::cout << std::fixed << std::setprecision(6);

    experimental_test();

    return 0;
}
*/
