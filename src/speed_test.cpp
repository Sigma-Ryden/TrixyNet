#include <Trixy/Neuro/Core.hpp> // TrixyNet, Functional, Optimizer, Training, Serializer
#include <Trixy/Lique/Core.hpp> // Tensor, Linear

#include <Trixy/Container/Container.hpp> // Container
#include <Utility/util.hpp> // Timer, test_neuro, check_neuro

#include <cstdlib> // rand, srand, size_t
#include <ctime> // time
#include <iostream> // cin, cout
#include <fstream> // ifstream, ofstream
#include <iomanip> // setprecision, fixed

namespace tr = trixy;
namespace li = trixy::lique;

using namespace tr::functional;

using TrixyNet = tr::FeedForwardNet<li::Vector, li::Matrix, li::Linear, tr::Container, float>;

using TrixyNetFunctional = tr::Functional<TrixyNet>;
using TrixyNetTraining   = tr::train::Training<TrixyNet>;
using TrixyNetSerializer = tr::Serializer<TrixyNet>;

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
    if(!in.is_open()) return;

    auto idata = get_speed_test_idata<TrixyNet>();
    auto odata = get_speed_test_odata<TrixyNet>();

    TrixyNetSerializer sr;
    sr.deserialize(in);
    in.close();

    TrixyNet net(sr.getTopology());
    TrixyNetFunctional manage;

    net.initInnerStruct(sr.getBias(), sr.getWeight());

    net.function.setAllActivation(manage.get(sr.getAllActivationId()));
    net.function.setLoss(manage.get(sr.getLossId()));

    //util::show_inner_struct(net);
    util::test_neuro(net, idata, odata);
    util::check_neuro(net, idata, odata);
}

void speed_test()
{
    auto idata = get_speed_test_idata<TrixyNet>();
    auto odata = get_speed_test_odata<TrixyNet>();

    TrixyNet net({4, 4, 5, 4, 3});

    TrixyNetFunctional manage;
    TrixyNetTraining teach(net);

    net.initInnerStruct([]
    {
        constexpr int range = 1000;
        return float(std::rand() % (2 * range + 1) - range) / float(range);
    });

    net.function.setActivation(manage.get<ActivationId::relu>());
    net.function.setNormalization(manage.get<ActivationId::softmax>());
    net.function.setLoss(manage.get<LossId::CCE>());

    auto grad = manage.get<OptimizationId::grad_descent>(net, 0.1);
    auto adam = manage.get<OptimizationId::adam>(net, 0.001);

    std::cout << "Before train\n";
    util::test_neuro(net, idata, odata);
    util::check_neuro(net, idata, odata);

    util::Timer t;
    teach.trainBatch(idata, odata, 100000, grad);
    teach.trainStochastic(idata, odata, 100000, std::rand, grad);
    teach.trainMiniBatch(idata, odata, 15000, 2, adam);

    std::cout << "Train time: " << t.elapsed() << '\n';

    std::cout << "After train\n";
    util::test_neuro(net, idata, odata);
    util::check_neuro(net, idata, odata);

    std::ofstream out("D:\\Serialized\\speed_test.bin", std::ios::binary);
    if(!out.is_open()) return;

    TrixyNetSerializer sr;
    sr.serialize(out, net);
    out.close();

    std::cout << "End of serialization\n";
}
//
int main()
{
    std::srand(unsigned(std::time(nullptr)));
    std::cout << std::fixed << std::setprecision(6);

    speed_test();
    speed_test_deserialization();

    //std::cin.get();

    return 0;
}
//
