#include <Trixy/Core.hpp>
// FeedNet, Functional, Optimizer, Training
// Serializer, Tensor, Linear, Container, Random

#include <Utility/Core.hpp> // Timer, statistic

#include <cstddef> // size_t
#include <iostream> // cin, cout
#include <iomanip> // setprecision, fixed
#include <fstream> // ifstream, ofstream

using namespace trixy;
using namespace trixy::functional;
using namespace trixy::train;
using namespace trixy::utility;

using precision_type = float;
using size_type      = std::size_t;

using Core    = TypeSet<precision_type>;
using FeedNet = FeedForwardNet<Core>;

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

    auto idata = get_simple_test_idata<FeedNet>();
    auto odata = get_simple_test_odata<FeedNet>();

    Serializer<FeedNet> sr;
    sr.deserialize(file);
    file.close();

    FeedNet net(sr.topology());
    Functional<FeedNet> manage;

    net.inner.init(sr.bias(), sr.weight());

    net.function.activation(manage.get(sr.all_activation_id()));
    net.function.loss(manage.get(sr.loss_id()));

    statistic(net, idata, odata);
}

void simple_test()
{
    using RandomFloating = RandomFloating<precision_type>;
    using RandomIntegral = RandomIntegral<size_type>;

    auto idata = get_simple_test_idata<FeedNet>();
    auto odata = get_simple_test_odata<FeedNet>();

    FeedNet net({2, 2, 2});
    Functional<FeedNet> manage;
    Training<FeedNet> teach(net);

    net.inner.init(RandomFloating{});

    net.function.activation(manage.get<ActivationId::relu>());
    net.function.normalization(manage.get<ActivationId::softmax>());

    net.function.loss(manage.get<LossId::CCE>());

    auto optimizer = manage.get<OptimizationId::adam>(net, 0.01);

    Timer t;
    teach.stochastic(idata, odata, optimizer, 2000, RandomIntegral{});
    std::cout << "Train time: " << t.elapsed() << '\n';

    statistic(net, idata, odata);

    std::ofstream file("D:\\Serialized\\simple_test.bin", std::ios::binary);
    if (not file.is_open()) return;

    Serializer<FeedNet> sr;

    sr.prepare(net);
    sr.serialize(file);
    file.close();

    std::cout << "End of serialization\n";
}
//
int main()
{
    std::cout << std::fixed << std::setprecision(6);

    simple_test();
    simple_test_deserialization();

    return 0;
}
//
