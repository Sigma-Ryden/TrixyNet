#ifndef TRIXY_NETWORK_FEED_FORWARD_NET_HPP
#define TRIXY_NETWORK_FEED_FORWARD_NET_HPP

#include <cstddef> // size_t
#include <cstdint> // uint8_t

#include <Trixy/Neuro/Network/Base.hpp>
#include <Trixy/Neuro/Network/Require.hpp>

#include <Trixy/Neuro/Training/Base.hpp>
#include <Trixy/Neuro/Functional/Id.hpp>

#include <Trixy/Locker/Vector.hpp>
#include <Trixy/Locker/Matrix.hpp>
#include <Trixy/Locker/Container.hpp>

#include <Trixy/Detail/TrixyMeta.hpp>

#include <Trixy/Neuro/Detail/MacroScope.hpp>

namespace trixy
{

TRIXY_NET_TPL_DECLARATION
using FeedForwardNet = TRIXY_NET_TPL(TrixyNetType::FeedForward);

TRIXY_NET_TPL_DECLARATION
class TRIXY_NET_TPL(TrixyNetType::FeedForward) :
    public TRIXY_NET_REQUIRE_TPL(TrixyNetType::FeedForward)::type
{
public:
    class InnerStruct;

    struct ActivationFunction;
    struct LossFunction;

    class Builder;

private:
    class InnerFunctional;

public:
    template <typename T>
    using Container                 = ContainerType<T>;

    template <typename T>
    using XContainer                = ContainerLocker<Container<T>>;

    using Vector                    = VectorType<PrecisionType, Pack...>;
    using Matrix                    = MatrixType<PrecisionType, Pack...>;

    using XVector                   = VectorLocker<Vector>;
    using XMatrix                   = MatrixLocker<Matrix>;

    using precision_type            = PrecisionType;
    using size_type                 = std::size_t;

    using TensorOperation           = LinearType<PrecisionType>;

    using InnerBuffer               = XContainer<XVector>;
    using InnerTopology             = ContainerType<std::size_t>;

    using ActivationId              = functional::ActivationId;
    using LossId                    = functional::LossId;

private:
    mutable InnerBuffer buff;       ///< 1D buffer for handle

public:
    InnerStruct inner;              ///< Network set of bias and weight

    InnerFunctional function;       ///< Functional object for setup inner network function
    TensorOperation linear;         ///< Linear class for tensor calculate

public:
    TrixyNet(const InnerTopology& topology);

    // operator= for copy and move TrixyNet object will not implicit generate
    TrixyNet(const TrixyNet&) = default;
    TrixyNet(TrixyNet&&) noexcept = default;

    const Vector& feedforward(const Vector& sample) const noexcept;

public:
    const Container<XVector>& getInnerBias() const noexcept { return inner.B.base(); }
    const Container<XMatrix>& getInnerWeight() const noexcept { return inner.W.base(); }
    const InnerTopology& getTopology() const noexcept { return inner.topology; }
};

TRIXY_NET_TPL_DECLARATION
class TRIXY_NET_TPL(TrixyNetType::FeedForward)::InnerStruct
{
public:
    const size_type N;              ///< Number of functional layer (same as topology_size - 1)

    XContainer<XVector> B;          ///< Container of network bias
    XContainer<XMatrix> W;          ///< Container of network weight

    const InnerTopology topology;   ///< Network topology

public:
    InnerStruct(const InnerTopology& topology);

    // operator= for copy and move InnerStruct object will not implicit generate
    InnerStruct(const InnerStruct&) = default;
    InnerStruct(InnerStruct&&) noexcept = default;

    template <class FloatGenerator>
    void initialize(FloatGenerator generator_all) noexcept;

    template <class FloatGenerator>
    void initialize(FloatGenerator generator_bias,
                    FloatGenerator generator_weight) noexcept;

    void initialize(const Container<Vector>& bias,
                    const Container<Matrix>& weight) noexcept;
};

TRIXY_NET_TPL_DECLARATION
struct TRIXY_NET_TPL(TrixyNetType::FeedForward)::ActivationFunction
{
public:
    using Function        = void (*)(XVector&, const XVector&);
    using FunctionDerived = void (*)(XVector&, const XVector&);

public:
    Function f;           ///< void (*f)(XVector& buff, const XVector& tensor)
    FunctionDerived df;   ///< void (*df)(XVector& buff, const XVector& tensor)

    ActivationId id;      ///< id of activation function, for user's def id = activationId::undefined

public:
    ActivationFunction() noexcept : f(nullptr), df(nullptr), id(ActivationId::undefined) {}

    ActivationFunction(Function function,
                       FunctionDerived function_derived,
                       ActivationId function_id = ActivationId::undefined) noexcept
    : f(function)
    , df(function_derived)
    , id(function_id) {}
};

TRIXY_NET_TPL_DECLARATION
struct TRIXY_NET_TPL(TrixyNetType::FeedForward)::LossFunction
{
public:
    using Function        = void (*)(precision_type&, const XVector&, const XVector&);
    using FunctionDerived = void (*)(XVector&, const XVector&, const XVector&);

public:
    Function f;           ///< void (*)(Precision& result, const XVector& target, const XVector& prediction)
    FunctionDerived df;   ///< void (*)(XVector& buff, const XVector& target, const XVector& prediction)

    LossId id;            ///< id of loss function, for user's def id = LossId::undefined

public:
    LossFunction() noexcept : f(nullptr), df(nullptr), id(LossId::undefined) {}

    LossFunction(Function function,
                 FunctionDerived function_derived,
                 LossId function_id = LossId::undefined) noexcept
    : f(function)
    , df(function_derived)
    , id(function_id) {}
};

TRIXY_NET_TPL_DECLARATION
class TRIXY_NET_TPL(TrixyNetType::FeedForward)::Builder
{
public:
    template <class Ret = XContainer<XVector>,
              class Init = Container<XVector>, typename... Args>
    static Ret getlock1d(const InnerTopology& topology, Args&&... args);

    template <class Ret = Container<Vector>,
              class Init = Ret, typename... Args>
    static Ret get1d(const InnerTopology& topology, Args&&... args);

    template <class Ret = XContainer<XMatrix>,
              class Init = Container<XMatrix>, typename... Args>
    static Ret getlock2d(const InnerTopology& topology, Args&&... args);

    template <class Ret = Container<Matrix>,
              class Init = Ret, typename... Args>
    static Ret get2d(const InnerTopology& topology, Args&&... args);
};

TRIXY_NET_TPL_DECLARATION
class TRIXY_NET_TPL(TrixyNetType::FeedForward)::InnerFunctional
{
public:
    using AllActivationFunction             = Container<ActivationFunction>;
    using AllActivationId                   = Container<ActivationId>;

private:
    AllActivationFunction activation_;      ///< Network activation functions
    LossFunction loss_;                     ///< Network loss function

    AllActivationId activationId_;          ///< Network activation function ids

public:
    explicit InnerFunctional(size_type N) : activation_(N), loss_(), activationId_(N) {}
    ~InnerFunctional() = default;

    // operator= for copy and move InnerFunctional object will not implicit generate
    InnerFunctional(const InnerFunctional&) = default;
    InnerFunctional(InnerFunctional&&) noexcept = default;

    void activation(const ActivationFunction&);
    void activationSet(const AllActivationFunction&);
    void normalization(const ActivationFunction&);

    void loss(const LossFunction&);

    const ActivationFunction& activation(size_type i = 0) const noexcept { return activation_[i]; }
    const ActivationId& activationId(size_type i = 0) const noexcept { return activationId_[i]; }

    const AllActivationFunction& activationSet() const noexcept { return activation_; }
    const Container<ActivationId>& activationIdSet() const noexcept { return activationId_; }

    const ActivationFunction& normalization() const noexcept { return activation_.back(); }
    const ActivationId& normalizationId() const noexcept { return activationId_.back(); }

    const LossFunction& loss() const noexcept { return loss_; }
    const LossId& lossId() const noexcept { return loss_.id; }
};

TRIXY_NET_TPL_DECLARATION
template <class FloatGenerator>
void TRIXY_NET_TPL(TrixyNetType::FeedForward)::InnerStruct::initialize(
    FloatGenerator generator_all) noexcept
{
    for(size_type i = 0; i < N; ++i)
    {
        B[i].fill(generator_all);
        W[i].fill(generator_all);
    }
}

TRIXY_NET_TPL_DECLARATION
template <class FloatGenerator>
void TRIXY_NET_TPL(TrixyNetType::FeedForward)::InnerStruct::initialize(
    FloatGenerator generator_bias,
    FloatGenerator generator_weight) noexcept
{
    for(size_type i = 0; i < N; ++i)
    {
        B[i].fill(generator_bias);
        W[i].fill(generator_weight);
    }
}

TRIXY_NET_TPL_DECLARATION
void TRIXY_NET_TPL(TrixyNetType::FeedForward)::InnerStruct::initialize(
    const Container<Vector>& bias,
    const Container<Matrix>& weight) noexcept
{
    for(size_type i = 0; i < N; ++i)
    {
        B[i].copy(bias[i]);
        W[i].copy(weight[i]);
    }
}

TRIXY_NET_TPL_DECLARATION
template <class Ret, class Init, typename... Args>
Ret TRIXY_NET_TPL(TrixyNetType::FeedForward)::Builder::get1d(
    const Container<size_type>& topology, Args&&... args)
{
    Init data;

    data.reserve(topology.size() - 1);
    for(size_type i = 1; i < topology.size(); ++i)
        data.emplace_back(topology[i], std::forward<Args>(args)...);

    return data;
}

TRIXY_NET_TPL_DECLARATION
template <class Ret, class Init, typename... Args>
Ret TRIXY_NET_TPL(TrixyNetType::FeedForward)::Builder::getlock1d(
    const Container<size_type>& topology, Args&&... args)
{
    return get1d<Ret, Init>(topology, std::forward<Args>(args)...);
}

TRIXY_NET_TPL_DECLARATION
template <class Ret, class Init, typename... Args>
Ret TRIXY_NET_TPL(TrixyNetType::FeedForward)::Builder::get2d(
    const Container<size_type>& topology, Args&&... args)
{
    Init data;

    data.reserve(topology.size() - 1);
    for(size_type i = 1; i < topology.size(); ++i)
        data.emplace_back(topology[i - 1], topology[i], std::forward<Args>(args)...);

    return data;
}

TRIXY_NET_TPL_DECLARATION
template <class Ret, class Init, typename... Args>
Ret TRIXY_NET_TPL(TrixyNetType::FeedForward)::Builder::getlock2d(
    const Container<size_type>& topology, Args&&... args)
{
    return get2d<Ret, Init>(topology, std::forward<Args>(args)...);
}

TRIXY_NET_TPL_DECLARATION
void TRIXY_NET_TPL(TrixyNetType::FeedForward)::InnerFunctional::activation(
    const TRIXY_NET_TPL(TrixyNetType::FeedForward)::ActivationFunction& f)
{
    for(size_type i = 0; i < activation_.size() - 1; ++i)
    {
        activation_  [i] = f;
        activationId_[i] = f.id;
    }
}

TRIXY_NET_TPL_DECLARATION
void TRIXY_NET_TPL(TrixyNetType::FeedForward)::InnerFunctional::activationSet(
    const Container<ActivationFunction>& fs)
{
    for(size_type i = 0; i < activation_.size(); ++i)
    {
        activation_  [i] = fs[i];
        activationId_[i] = fs[i].id;
    }
}

TRIXY_NET_TPL_DECLARATION
void TRIXY_NET_TPL(TrixyNetType::FeedForward)::InnerFunctional::normalization(
    const ActivationFunction& f)
{
    activation_  .back() = f;
    activationId_.back() = f.id;
}

TRIXY_NET_TPL_DECLARATION
void TRIXY_NET_TPL(TrixyNetType::FeedForward)::InnerFunctional::loss(
    const LossFunction& f)
{
    loss_ = f;
}

TRIXY_NET_TPL_DECLARATION
TRIXY_NET_TPL(TrixyNetType::FeedForward)::InnerStruct::InnerStruct(
    const Container<size_type>& topology)
    : N(topology.size() - 1)
    , B(TrixyNet::Builder::getlock1d(topology))
    , W(TrixyNet::Builder::getlock2d(topology))
    , topology(topology)
{
}

TRIXY_NET_TPL_DECLARATION
TRIXY_NET_TPL(TrixyNetType::FeedForward)::TrixyNet(
    const Container<size_type>& topology)
    : buff(TrixyNet::Builder::getlock1d(topology))
    , inner(topology)
    , function(topology.size() - 1)
    , linear()
{
}

TRIXY_NET_TPL_DECLARATION
const typename TRIXY_NET_TPL(TrixyNetType::FeedForward)::Vector&
    TRIXY_NET_TPL(TrixyNetType::FeedForward)::feedforward(
    const Vector& sample) const noexcept
{
    /*
    Operations:
    . - dot
    Processing:
    buff = H' . W + B, where H' - previous
    H = activation(buff)
    */
    linear.dot(buff[0], sample, inner.W[0]);
    linear.add(buff[0], inner.B[0]);
    function.activation(0).f(buff[0], buff[0]);

    for(size_type i = 1; i < inner.N; ++i)
    {
        linear.dot(buff[i], buff[i - 1], inner.W[i]);
        linear.add(buff[i], inner.B[i]);
        function.activation(i).f(buff[i], buff[i]);
    }

    return buff.back().base();
}

} // namespace trixy

#include <Trixy/Neuro/Detail/MacroUnscope.hpp>

#endif // TRIXY_NETWORK_FEED_FORWARD_NET_HPP
