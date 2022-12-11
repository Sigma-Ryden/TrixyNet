#include <Trixy/Core.hpp>
// TrixyNet, Functional, Optimizer, Training
// Serializer, Tensor, Linear, Container, Random

#include <Utility/Core.hpp> // Timer, statistic

#include <iostream> // cin, cout
#include <iomanip> // setprecision, fixed

namespace tr = trixy;

using namespace tr::functional;
using namespace tr::train;

using namespace tr::set;

using namespace tr::utility;
using namespace tr::meta;

using precision_type = float;
using size_type      = std::size_t;

using Core     = tr::TypeSet<precision_type>;

using FeedNet  = tr::FeedForwardNet<Core>;
using TrixyNet = tr::TrixyNet<Core>;

template <class Net, class Sample =
    if_<is_feedforward_net<Net>::value, Core::Vector, Core::Tensor>>
Core::Container<Sample> get_speed_test_idata()
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

template <class Net, class Target =
    if_<is_feedforward_net<Net>::value, Core::Vector, Core::Tensor>>
Core::Container<Target> get_speed_test_odata()
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
    RandomFloating<precision_type> random;
    auto generator = [&] { return random(-.5, .5); };

    constexpr size_type epochs = 1000;

    // Preparing first model
    {
        // Preparing train data
        auto idata = get_speed_test_idata<FeedNet>();
        auto odata = get_speed_test_odata<FeedNet>();

        FeedNet net({4, 4, 5, 4, 3});

        net.inner.init(generator);

        tr::Functional<FeedNet> manage;

        net.function.activation(manage.get<ActivationId::relu>());
        net.function.normalization(manage.get<ActivationId::softmax>());

        net.function.loss(manage.get<LossId::CCE>());

        Training<FeedNet> train(net);

        auto optimizer = AdamOptimizer(net, 0.01);

        Timer t;
        train.batch(idata, odata, optimizer, epochs);
        std::cout << "Train first net time: " << t.elapsed() << '\n';

        statistic(net, idata, odata);
    }

    // Preparing second model
    {
        using FullyConnected = tr::layer::FullyConnected<TrixyNet>;

        // Preparing train data
        auto idata = get_speed_test_idata<TrixyNet>();
        auto odata = get_speed_test_odata<TrixyNet>();

        TrixyNet net;

        using ReLU = activation::ReLU<precision_type>;
        using SoftMax = activation::SoftMax<precision_type>;

        net.add(new FullyConnected(4, 4, new ReLU))
           .add(new FullyConnected(4, 5, new ReLU))
           .add(new FullyConnected(5, 4, new ReLU))
           .add(new FullyConnected(4, 3, new SoftMax));

        net.init(generator);

        Training<TrixyNet> train(net);

        using CCE = loss::CCE<precision_type>;
        train.loss(new CCE);

        auto optimizer = AdamOptimizer(net, 0.01);

        Timer t;
        train.batch(idata, odata, optimizer, epochs);
        std::cout << "Train second net time: " << t.elapsed() << '\n';

        statistic(net, idata, odata);
    }
}
//
int main()
{
    std::cout << std::fixed << std::setprecision(6);

    experimental_test();

    return 0;
}
//
