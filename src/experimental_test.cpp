#include <Trixy/Core.hpp>
// TrixyNet, Functional, Optimizer, Training
// Serializer, Tensor, Linear, Container, Random

#include <Utility/utility.hpp> // Timer, statistic

#include <iostream> // cin, cout
#include <iomanip> // setprecision, fixed

namespace tr = trixy;
namespace li = trixy::lique;

using namespace tr::functional;
using namespace tr::functional::activation;
using namespace tr::functional::loss;

using namespace tr::train;

using namespace utility;

using Core    = tr::TypeSet<float>;

using FeedNet = tr::FeedForwardNet<Core>;
using UniNet  = tr::TrixyNet<Core>;

using RandomIntegral = tr::utility::RandomIntegral<>;
using RandomFloating = tr::utility::RandomFloating<>;

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
    // Preparing train data
    auto idata = get_speed_test_idata<FeedNet>();
    auto odata = get_speed_test_odata<FeedNet>();

    RandomFloating random;
    auto generator = [&] { return random(-.5, .5); };

    constexpr int epochs = 1000;

    // Preparing first model
    {
        FeedNet net({4, 4, 5, 4, 3});

        net.inner.initialize(generator);

        tr::Functional<FeedNet> manage;

        net.function.activation(manage.get<ActivationId::relu>());
        net.function.normalization(manage.get<ActivationId::softmax>());
        net.function.loss(manage.get<LossId::CCE>());

        Training<FeedNet> teach(net);

        auto grad = GradDescentOptimizer(net, 0.1);

        Timer t;
        teach.trainBatch(idata, odata, grad, epochs);
        std::cout << "Train first net time: " << t.elapsed() << '\n';

        utility::statistic(net, idata, odata);
    }

    // Preparing second model
    {
        using FullyConnected = tr::layer::FullyConnected<UniNet>;

        UniNet net;

        auto relu = ReLU<float>();
        auto soft_max = SoftMax<float>();

        net.add(new FullyConnected(4, 4, &relu))
           .add(new FullyConnected(4, 5, &relu))
           .add(new FullyConnected(5, 4, &relu))
           .add(new FullyConnected(4, 3, &soft_max));

        net.init(generator);

        auto mse = MSE<float>();
        auto grad = GradDescentOptimizer_(net, 0.1);

        Training<UniNet> teach(net);

        teach.loss(&mse);

        Timer t;
        teach.trainBatch(idata, odata, grad, epochs);
        std::cout << "Train second net time: " << t.elapsed() << '\n';

        utility::statistic(net, idata, odata);
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
