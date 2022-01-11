#include "Trixy/Neuro/neuro_core.hpp" // FeedForwardNeuro, Functional, Serializer
#include "Trixy/Lique/lique_core.hpp" // Vector, Matrix, Linear

#include "Trixy/Container/container.hpp" // Container
#include "Utility/util.hpp" // Timer, test_neuro, check_neuro

#include <cstdlib> // rand, srand, size_t
#include <ctime> // time
#include <iostream> // cin, cout
#include <fstream> // ifstream, ofstream
#include <iomanip> // setprecision, fixed

namespace tr = trixy;
namespace li = lique;

static li::Linear<li::Vector, li::Matrix, double> linear;

float random_real() noexcept
{
    static constexpr int range = 1000;
    return static_cast<float>(std::rand() % (2 * range + 1) - range) / range;
}

float random_normal() noexcept
{
    static constexpr int range = 1000;
    static constexpr float pi = 3.14159265;

    static float x;

    x = static_cast<float>(std::rand() % (2 * range + 1) - range) / range;

    return std::exp(- x * x) / std::sqrt(2 * pi);
}

tr::Container<li::Vector<float>> get_speed_test_idata()
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

tr::Container<li::Vector<float>> get_speed_test_odata()
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
    using namespace tr::functional;

    using TrixyNet           = tr::FeedForwardNet<li::Vector, li::Matrix, li::Linear, tr::Container, float>;
    using TrixyNetFunctional = tr::Functional<TrixyNet>;
    using TrixyNetSerializer = tr::Serializer<TrixyNet>;

    std::ifstream in("D:\\Serialized\\speed_test.bin", std::ios::binary);
    if(!in.is_open()) return;

    auto train_in = get_speed_test_idata();
    auto train_out = get_speed_test_odata();

    TrixyNetSerializer sr;
    sr.deserialize(in);
    in.close();

    TrixyNet net = sr.getTopology();
    TrixyNetFunctional manage;

    net.initializeInnerStruct(sr.getBias(), sr.getWeight());

    net.function.setActivation(manage.get(sr.getActivationId()));
    net.function.setNormalization(manage.get(sr.getNormalizationId()));
    net.function.setLoss(manage.get(sr.getLossId()));
    li::Vector<double> a;

    util::test_neuro(net, train_in, train_out);
    util::check_neuro(net, train_in, train_out);
}

void speed_test()
{
    using namespace tr::functional;

    using TrixyNet           = tr::FeedForwardNet<li::Vector, li::Matrix, li::Linear, tr::Container, float>;
    using TrixyNetFunctional = tr::Functional<TrixyNet>;
    using TrixyNetSerializer = tr::Serializer<TrixyNet>;

    auto train_in = get_speed_test_idata();
    auto train_out = get_speed_test_odata();

    TrixyNet net({4, 4, 5, 4, 3});
    TrixyNetFunctional manage;

    net.initializeInnerStruct(random_real);

    net.function.setActivation(manage.get<ActivationId::relu>());
    net.function.setNormalization(manage.get<ActivationId::softmax>());
    net.function.setLoss(manage.get<LossId::CCE>());

    auto optimizer = manage.get<OptimizationId::grad_descent>(net, 0.1);

    std::cout << "Before train\n";
    util::test_neuro(net, train_in, train_out);
    util::check_neuro(net, train_in, train_out);

    util::Timer t;
    //
    net.trainBatch(train_in, train_out, 100000,optimizer);
    net.trainStochastic(train_in, train_out, 100000, std::rand, manage.get<OptimizationId::adam>(net, 0.001));
    net.trainMiniBatch(train_in, train_out, 100000 / 6, 2, optimizer);
    //
    std::cout << "Train time: " << t.elapsed() << '\n';

    std::cout << "After train\n";
    util::test_neuro(net, train_in, train_out);
    util::check_neuro(net, train_in, train_out);

    std::ofstream out("D:\\Serialized\\speed_test.bin", std::ios::binary);
    if(!out.is_open()) return;

    TrixyNetSerializer sr;
    sr.prepare(net);
    sr.serialize(out);
    out.close();

    std::cout << "End of serialization\n";
}

int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    std::cout << std::fixed << std::setprecision(6);

    //speed_test();
    speed_test_deserialization();

    return 0;
}
//
/*
li::Matrix<float> a(2, 2);
a.copy({1, 2, 3, 4});
std::cout << lique::mean(a, Axis::Y);
*/
/*
li::Matrix<float> a(2, 3);
a.copy({1, 5, 9, 7, 15, 22});

std::cout << a << '\n';
std::cout << lique::std(a, Axis::X, true);
*/
/*
li::Matrix<float> m(1000, 1000, 3.14);
li::Vector<float> v(1000, 2.17);
li::Vector<float> buff(1000);

util::Timer t;
// V*M : 0.062484
// M*V : 0.140612
for(int i = 0; i < 100; ++i)
    lique::dot(buff, m, v);

std::cout << t.elapsed() << '\n';
*/
/*
li::Matrix<int> m(3, 2);
li::Vector<int> v(3);
m.copy({1, 2, -1, 0, -2, 1});
v.copy({-1, 0, 1});

std::cout << lique::dot(v, m);
*/
/*
using util::operator<<;

li::Matrix<int> a(2, 4);

a.copy({0, 1, 2, 3, 4, 5, 6, 7});

std::cout << a << '\n';
std::cout << const_cast<li::Matrix<int>&>(a).transpose()  << '\n';
*/
/*
struct A
{
    // will work
    void f(int N) { std::cout << N; }
    template <int N>
    void f() { f(N); }
    //
    // wont work
    template <int N>
    void f() { std::cout << N; }

    void f(int N) { f<N>(); }
    //
};
*/
