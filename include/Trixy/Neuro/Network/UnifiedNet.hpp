#ifndef TRIXY_NETWORK_UNIFIED_NET_HPP
#define TRIXY_NETWORK_UNIFIED_NET_HPP

#include <Trixy/Neuro/Network/Base.hpp>
#include <Trixy/Neuro/Network/Require.hpp>

#include <Trixy/Neuro/Network/Layer/Base.hpp>

#include <Trixy/Locker/Core.hpp>

#include <Trixy/Neuro/Detail/MacroScope.hpp>

namespace trixy
{

TRIXY_NET_TPL_DECLARATION
class TRIXY_NET_TPL(TrixyNetType::Unified)
    : public guard::TRIXY_NET_REQUIRE_TPL(TrixyNetType::Unified)::type
{
public:
    template <typename T>
    using Container                 = typename TypeSet::template Container<T>;

    using Vector                    = typename TypeSet::Vector;
    using Matrix                    = typename TypeSet::Matrix;
    using Tensor                    = typename TypeSet::Tensor;

    template <typename T>
    using XContainer                = memory::ContainerLocker<Container<T>>;

    using XVector                   = memory::VectorLocker<Vector>;
    using XMatrix                   = memory::MatrixLocker<Matrix>;
    using XTensor                   = memory::TensorLocker<Tensor>;

    using precision_type            = typename TypeSet::precision_type;
    using size_type                 = typename TypeSet::size_type;

    using Linear                    = typename TypeSet::Linear;

    using ILayer                    = layer::ILayer<TrixyNet>;
    using ITrainLayer               = layer::ITrainLayer<TrixyNet>;

    using Topology                  = Container<ILayer*>;

private:
    Topology inner_;
    size_type size_;

public:
    Linear linear;

public:
    TrixyNet(size_type reserve_size = 8);
    ~TrixyNet();

    auto add(ILayer* layer) -> TrixyNet&;

    auto inner() const noexcept -> const Topology& { return inner_; }
    auto layer(size_type i) noexcept -> ILayer& { return *inner_[i]; }

    auto size() const noexcept -> const size_type& { return size_; }

    auto feedforward(const Vector& sample) noexcept -> const Vector&;

    auto operator() (const Vector& sample) noexcept -> const Vector&
    { return feedforward(sample); }

    template <class FloatGenerator,
              meta::require<meta::is_callable<FloatGenerator>::value> = 0>
    void init(FloatGenerator generator) noexcept;
};

TRIXY_NET_TPL_DECLARATION
TRIXY_NET_TPL(TrixyNetType::Unified)::TrixyNet(size_type reserve_size) : size_(0)
{
    inner_.reserve(reserve_size);
}

TRIXY_NET_TPL_DECLARATION
TRIXY_NET_TPL(TrixyNetType::Unified)::~TrixyNet()
{
    for (size_type i = 0; i < size_; ++i)
        delete inner_[i];
}

TRIXY_NET_TPL_DECLARATION
auto TRIXY_NET_TPL(TrixyNetType::Unified)::add(ILayer* layer) -> TrixyNet&
{
    inner_.emplace_back(layer);

    ++size_;

    return *this;
}

TRIXY_NET_TPL_DECLARATION
auto TRIXY_NET_TPL(TrixyNetType::Unified)::feedforward(
    const Vector& sample) noexcept -> const Vector&
{
    layer(0).forward(sample);

    for (size_type i = 1; i < size_; ++i)
        layer(i).forward(layer(i - 1).value());

    return layer(size_ - 1).value();
}

TRIXY_NET_TPL_DECLARATION
template <class FloatGenerator,
          meta::require<meta::is_callable<FloatGenerator>::value>>
void TRIXY_NET_TPL(TrixyNetType::Unified)::init(FloatGenerator generator) noexcept
{
    std::function<precision_type()> gen = generator;

    for (size_type i = 0; i < size_; ++i)
        layer(i).init(gen);
}

} // namespace trixy

#include <Trixy/Neuro/Detail/MacroUnscope.hpp>

#endif // TRIXY_NETWORK_UNIFIED_NET_HPP
