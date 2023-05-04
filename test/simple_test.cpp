#include <Trixy/Core.hpp>
// TrixyNet, Functional, Optimizer, Training
// Serializer, Tensor, Linear, Container, Random

#include <Utility/Core.hpp> // Timer, statistic

#include <iostream> // cin, cout
#include <iomanip> // setprecision, fixed

using Core = trixy::TypeSet<float>;
using Net = trixy::TrixyNet<Core>;

using FullyConnected = trixy::layer::FullyConnected<Net>;

using ReLU = trixy::functional::activation::ReLU<Core::precision_type>;
using SoftMax = trixy::functional::activation::SoftMax<Core::precision_type>;

using CCE = trixy::functional::loss::CCE<Core::precision_type>;

Core::Container<Core::Tensor> get_simple_test_idata()
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

Core::Container<Core::Tensor> get_simple_test_odata()
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

void simple_test_deserialization()
{
    std::ifstream file("simple_test.bin", std::ios::binary);
    if (not file.is_open()) return;

    Net net;

    trixy::Serializer<Net> sr;
    sr.deserialize(file, net);

    file.close();

    auto idata = get_simple_test_idata();
    auto odata = get_simple_test_odata();

    statistic(net, idata, odata);
}

void simple_test()
{
    trixy::utility::RandomFloating<Core::precision_type> random;
    auto generator = [&random] { return random(-0.5f, 0.5f); };

    // Preparing train data
    auto idata = get_simple_test_idata();
    auto odata = get_simple_test_odata();

    Net net;

    net.add(new FullyConnected(4, 4, new ReLU))
       .add(new FullyConnected(4, 5, new ReLU))
       .add(new FullyConnected(5, 4, new ReLU))
       .add(new FullyConnected(4, 3, new SoftMax));

    net.init(generator);

    trixy::train::Training<Net> train(net);

    train.loss(new CCE);

    auto optimizer = trixy::train::AdamOptimizer(net, 0.01f);

    Timer t;
    train.batch(idata, odata, optimizer, 1000);
    std::cout << "Train second net time: " << t.elapsed() << '\n';

    statistic(net, idata, odata);

    std::ofstream file("simple_test.bin", std::ios::binary);
    if (not file.is_open()) return;

    trixy::Serializer<Net> sr;
    sr.serialize(file, net);

    file.close();
}

int main()
{
    sf::serializable<FullyConnected>();
    sf::serializable<ReLU>();
    sf::serializable<SoftMax>();

    std::cout << std::fixed << std::setprecision(6);

    //simple_test();
    simple_test_deserialization();

    return 0;
}
