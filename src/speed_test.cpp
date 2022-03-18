#include "Trixy/Neuro/NeuroCore.hpp" // TrixyNet, Functional, Optimizer, Training, Serializer
#include "Trixy/Lique/LiqueCore.hpp" // Tensor, Linear

#include "Trixy/Container/Container.hpp" // Container
#include "Trixy/Locker/LockerCore.hpp" // Locker
#include "Utility/util.hpp" // Timer, test_neuro, check_neuro

#include <cstdlib> // rand, srand, size_t
#include <ctime> // time
#include <iostream> // cin, cout
#include <fstream> // ifstream, ofstream
#include <iomanip> // setprecision, fixed

namespace tr = trixy;
namespace li = trixy::lique;

float random() noexcept
{
    static constexpr int range = 1000;
    return float(std::rand() % (2 * range + 1) - range) / range;
}

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
    using namespace tr::functional;

    using TrixyNet           = tr::FeedForwardNet<li::Vector, li::Matrix, li::Linear, tr::Container, double>;
    using TrixyNetFunctional = tr::Functional<TrixyNet>;
    using TrixyNetSerializer = tr::Serializer<TrixyNet>;

    std::ifstream in("D:\\Serialized\\speed_test.bin", std::ios::binary);
    if(!in.is_open()) return;

    auto train_in  = get_speed_test_idata<TrixyNet>();
    auto train_out = get_speed_test_odata<TrixyNet>();

    TrixyNetSerializer sr;
    sr.deserialize(in);
    in.close();

    TrixyNet net(sr.getTopology());
    TrixyNetFunctional manage;

    net.initializeInnerStruct(sr.getBias(), sr.getWeight());

    net.function.setAllActivation(manage.get(sr.getAllActivationId()));
    net.function.setLoss(manage.get(sr.getLossId()));

    //util::show_inner_struct(net);
    util::test_neuro(net, train_in, train_out);
    util::check_neuro(net, train_in, train_out);
}

void speed_test()
{
    using namespace tr::functional;

    using TrixyNet           = tr::FeedForwardNet<li::Vector, li::Matrix, li::Linear, tr::Container, float>;
    using TrixyNetFunctional = tr::Functional<TrixyNet>;
    using TrixyNetTraining   = tr::train::Training<TrixyNet>;
    using TrixyNetSerializer = tr::Serializer<TrixyNet>;

    auto train_in  = get_speed_test_idata<TrixyNet>();
    auto train_out = get_speed_test_odata<TrixyNet>();

    TrixyNet net({4, 4, 5, 4, 3});

    TrixyNetFunctional manage;
    TrixyNetTraining teach(net);

    net.initializeInnerStruct(random);

    net.function.setActivation(manage.get<ActivationId::relu>());
    net.function.setNormalization(manage.get<ActivationId::softmax>());
    net.function.setLoss(manage.get<LossId::CCE>());

    auto grad = manage.get<OptimizationId::grad_descent>(net, 0.1);
    auto adam = manage.get<OptimizationId::adam>(net, 0.001);

    std::cout << "Before train\n";
    util::test_neuro(net, train_in, train_out);
    util::check_neuro(net, train_in, train_out);

    util::Timer t;
    teach.trainBatch(train_in, train_out, 100000, grad);
    teach.trainStochastic(train_in, train_out, 100000, std::rand, grad);
    teach.trainMiniBatch(train_in, train_out, 100000 / 6, 2, adam);

    std::cout << "Train time: " << t.elapsed() << '\n';

    std::cout << "After train\n";
    util::test_neuro(net, train_in, train_out);
    util::check_neuro(net, train_in, train_out);

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
/*
#include <thread>
#include <numeric>
#include <algorithm>
#include <functional>

template <typename Iterator, typename T>
void accumulate_block(Iterator first, Iterator last, T& result)
{
    result = std::accumulate(first,last,result);
}

template <typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init)
{
    const std::size_t length = std::distance(first, last);

    if(not length) return init;

    const std::size_t min_per_thread = 25;
    const std::size_t max_threads = (length + min_per_thread - 1) / min_per_thread;
    const std::size_t hardware_threads = std::thread::hardware_concurrency();

    const std::size_t num_threads=
        std::min(hardware_threads != 0 ? hardware_threads : 2,
                 max_threads);

    const std::size_t block_size = length / num_threads;

    tr::Container<T> results(num_threads);

    tr::Container<std::thread> threads;

    threads.reserve(num_threads - 1);

    Iterator block_start = first;
    for(std::size_t i = 0; i < (num_threads - 1); ++i)
    {
        Iterator block_end=block_start;
        std::advance(block_end, block_size);

        threads.emplace_back(
            accumulate_block<Iterator, T>,
            block_start, block_end,
            std::ref(results[i])
        );

        block_start = block_end;
    }

    accumulate_block(
        block_start, last, results[num_threads - 1]
    );

    std::for_each(
        threads.begin(), threads.end(),
        std::mem_fn(&std::thread::join)
    );

    return std::accumulate(results.begin(), results.end(), init);
}

int main()
{
    constexpr int million = 1e6;

    li::Vector<double> x(100 * million, 0.000123);
    double result = 0.;
    util::Timer t;
    //accumulate_block(li::first(x), li::last(x), result);
    result = parallel_accumulate(li::first(x), li::last(x), result);
    std::cout << "Perfomance: " << t.elapsed() << '\n';
    std::cout << "Result: " << result << '\n';

    return 0;
}
*/
