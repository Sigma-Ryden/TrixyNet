#ifndef TRIXY_NETWORK_UNIFIED_NET_HPP
#define TRIXY_NETWORK_UNIFIED_NET_HPP

#include <Trixy/Neuro/Network/Base.hpp>
#include <Trixy/Neuro/Network/Require.hpp>

#include <Trixy/Neuro/Network/Layer/Base.hpp>

#include <Trixy/Serializer/Core.hpp>

#include <Trixy/Locker/Core.hpp>

#include <Trixy/Neuro/Detail/TrixyNetMeta.hpp>
#include <Trixy/Neuro/Detail/MacroScope.hpp>

namespace trixy
{

TRIXY_NET_TEMPLATE()
using UnifiedNed = TrixyNet<TypeSet>;

TRIXY_NET_TEMPLATE()
class TrixyNet<TypeSet>
    : public guard::TrixyNetRequire<TypeSet>::type
{
    SERIALIZABLE_ACCESS()

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

public:
    Linear linear;

public:
    TrixyNet(size_type reserve_size = 8)
    {
        inner_.reserve(reserve_size);
    }

    TrixyNet(const Topology& topology)
    {
        inner_ = topology;
    }

    ~TrixyNet()
    {
        for (size_type i = 0; i < inner_.size(); ++i)
            delete inner_[i];
    }

    TrixyNet& add(ILayer* layer)
    {
        inner_.emplace_back(layer);
        return *this;
    }

    bool remove(ILayer* layer)
    {
        Topology inner;
        inner.reserve(inner_.capacity());

        for (auto ilayer : inner_)
            if (ilayer != layer) inner.emplace_back(ilayer);

        inner_ = std::move(inner);

        return *this;
    }

    const Topology& inner() const noexcept { return inner_; }
    ILayer& layer(size_type i) noexcept { return *inner_[i]; }

    size_type size() const noexcept { return inner_.size(); }

    const Tensor& feedforward(const Tensor& sample) noexcept
    {
        layer(0).forward(sample);

        for (size_type i = 1; i < inner_.size(); ++i)
            layer(i).forward(layer(i - 1).value());

        return layer(inner_.size() - 1).value();
    }

    const Tensor& operator() (const Tensor& sample) noexcept
    {
        return feedforward(sample);
    }

    template <class FloatGenerator>
    void init(FloatGenerator functor) noexcept
    {
        typename ILayer::Generator generator{functor};

        for (size_type i = 0; i < inner_.size(); ++i)
            layer(i).init(generator);
    }
};

} // namespace trixy

CONDITIONAL_SERIALIZABLE_DECLARATION(trixy::meta::is_unified_net<S>::value)
SERIALIZABLE_DECLARATION_INIT()

CONDITIONAL_SERIALIZABLE(saveload, self, trixy::meta::is_unified_net<S>::value)
    SERIALIZATION
    (
        archive & self.inner_;
    )
SERIALIZABLE_INIT()

#endif // TRIXY_NETWORK_UNIFIED_NET_HPP
