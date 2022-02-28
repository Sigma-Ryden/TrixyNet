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

    using TrixyNet           = tr::FeedForwardNet<li::Vector, li::Matrix, li::Linear, tr::Container, float>;
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

    auto grad_descent = manage.get<OptimizationId::grad_descent>(net, 0.1);
    auto adam         = manage.get<OptimizationId::adam>(net, 0.001);

    std::cout << "Before train\n";
    util::test_neuro(net, train_in, train_out);
    util::check_neuro(net, train_in, train_out);

    util::Timer t;
    teach.trainBatch(train_in, train_out, 100000, grad_descent);
    teach.trainStochastic(train_in, train_out, 100000, std::rand, adam);
    teach.trainMiniBatch(train_in, train_out, 100000 / 6, 2, grad_descent);

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
#include <cstring>

using size_type = std::conditional<0, std::size_t, unsigned int>::type;
using byte_type = char;

template <size_type N>
class Buff
{
private:
    byte_type data_[N];

public:
    byte_type* data() noexcept
    {
        return data_;
    }

    const byte_type* data() const noexcept
    {
        return data_;
    }

    template <typename OutData,
              typename = typename std::enable_if<(sizeof(OutData) <= N)>::type>
    void copy(OutData& dst)
    {
        std::memcpy(&dst, data_, sizeof(dst));
    }

    template <typename InData,
              typename = typename std::enable_if<(sizeof(InData) <= N)>::type>
    void put(const InData& src)
    {
        std::memcpy(data_, &src, sizeof(src));
    }
};

byte_type powerof2(byte_type base2)
{
    byte_type pow = 0;

    while((base2 >>= 1) != 0)
    {
        ++pow;
    }

    return pow;
}

void w()
{
    std::ofstream out("D:\\temp.bin");

    byte_type sizeof_size_type = 16;
    byte_type sizeof_precision_type = 4;
    byte_type sizeof_activation_id = 8;
    byte_type sizeof_loss_id = 2;

    byte_type meta;

    // each 4 bits in first 2nd bytes of serialized binary file
    // using for writing meta-value 'n' where
    // 'n' is position of binary 1 in each variables sizeof_'name'

    // writing first 4 bits of sizeof_'size_type',
    // and second 4 bits of sizeof_'precision_type'
    meta = (powerof2(sizeof_size_type) << 4) + powerof2(sizeof_precision_type);

    out.write(reinterpret_cast<const byte_type*>(&meta), 1);

    // writing first 4 bits of sizeof_'size_type',
    // and second 4 bits of sizeof_'precision_type'
    meta = (powerof2(sizeof_activation_id) << 4) + powerof2(sizeof_loss_id);

    out.write(reinterpret_cast<const byte_type*>(&meta), 1);

    out.close();
}

void r()
{
    std::ifstream out("D:\\temp.bin");

    byte_type size = 0x01;

    byte_type meta;

    byte_type sizeof_size_type;
    byte_type sizeof_precision_type;
    byte_type sizeof_activation_id;
    byte_type sizeof_loss_id;

    // reading first 2 meta-data bytes in deserializing binary file
    out.read(reinterpret_cast<byte_type*>(&meta), 1);

    // set first 4 bits of meta-data for sizeof_size_type,
    // and second 4 bits for sizeof_precision_type
    sizeof_size_type = size << (meta >> 4);
    sizeof_precision_type = size << (meta & 0x0F);

    out.read(reinterpret_cast<byte_type*>(meta), 1);

    // set first 4 bits of meta-data for sizeof_size_type,
    // and second 4 bits for sizeof_precision_type
    sizeof_activation_id = size << (meta >> 4);
    sizeof_loss_id = size << (meta & 0x0F);

    out.close();
}
*/
