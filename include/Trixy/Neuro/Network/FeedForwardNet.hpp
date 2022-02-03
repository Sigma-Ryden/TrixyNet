#ifndef FEED_FORWARD_NET_HPP
#define FEED_FORWARD_NET_HPP

#include <cstddef> // size_t
#include <cstdint> // uint8_t
#include <cmath> // fabs

#include "Trixy/Locker/LockerCore.hpp"
#include "Trixy/Neuro/Training/FeedForwardNetTraining.hpp"
#include "Trixy/Neuro/Functional/IdFunctional.hpp"

#include "Trixy/Neuro/Detail/TrixyNetMeta.hpp"

#include "Trixy/Neuro/Detail/MacroScope.hpp"

namespace trixy
{

TRIXY_NET_TPL_DECLARATION
using FeedForwardNet = TRIXY_NET_TPL(TrixyNetType::FeedForward);

TRIXY_NET_TPL_DECLARATION
class TRIXY_NET_TPL(TrixyNetType::FeedForward) : public TrixyNetType::FeedForward
{
public:
    struct InnerStruct;

    struct ActivationFunction;
    struct LossFunction;

private:
    class InnerFunctional;

public:
    template <typename... T>
    using Container                 = ContainerType<T...>;

    template <typename... T>
    using LContainer                = ContainerLocker<ContainerType<T...>>;

    using Vector                    = VectorType<PrecisionType, Args...>;
    using Matrix                    = MatrixType<PrecisionType, Args...>;
    using LVector                   = VectorLocker<Vector>;

    using LMatrix                   = MatrixLocker<Matrix>;

    using precision_type            = PrecisionType;
    using size_type                 = std::size_t;

    using TensorOperation           = LinearType<precision_type>;

    using InnerBuffer               = LContainer<LVector>;
    using InnerTopology             = ContainerType<size_type>;

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

    TrixyNet(const TrixyNet&) = default;
    TrixyNet(TrixyNet&&) noexcept = default;

    const Vector& feedforward(const Vector& sample) const noexcept;

    long double accuracy(const Container<Vector>& idata,
                         const Container<Vector>& odata) const noexcept;

    long double accuracyf(const Container<Vector>& idata,
                          const Container<Vector>& odata,
                          precision_type range_rate) const noexcept;

    long double accuracyg(const Container<Vector>& idata,
                          const Container<Vector>& odata,
                          precision_type range_rate) const noexcept;

    long double loss(const Container<Vector>& idata,
                     const Container<Vector>& odata) const noexcept;

private:
    bool check(const Vector& target,
               const Vector& prediction) const noexcept;

    bool checkf(const Vector& target,
                const Vector& prediction,
                precision_type range_rate) const noexcept;

    void checkg(const Vector& target,
                const Vector& prediction,
                precision_type range_rate,
                size_type& count) const noexcept;

public:
    template <class GeneratorPrecision>
    void initializeInnerStruct(GeneratorPrecision generator_all) noexcept;

    template <class GeneratorPrecision>
    void initializeInnerStruct(GeneratorPrecision generator_bias,
                               GeneratorPrecision generator_weight) noexcept;

    void initializeInnerStruct(const Container<Vector>& bias,
                               const Container<Matrix>& weight) noexcept;

    const Container<LVector>& getInnerBias() const noexcept { return inner.B.base(); }
    const Container<LMatrix>& getInnerWeight() const noexcept { return inner.W.base(); }
    const InnerTopology& getTopology() const noexcept { return inner.topology; }

public:
    template <typename... T>
    static LContainer<LVector> init1D(const InnerTopology& topology, T&&... args);
    template <typename... T>
    static LContainer<LMatrix> init2D(const InnerTopology& topology, T&&... args);
};

TRIXY_NET_TPL_DECLARATION
struct TRIXY_NET_TPL(TrixyNetType::FeedForward)::InnerStruct
{
public:
    LContainer<LVector> B;          ///< Container of network bias
    LContainer<LMatrix> W;          ///< Container of network weight

    const InnerTopology topology;   ///< Network topology
    const size_type N;              ///< Number of functional layer (same as topology_size - 1)

public:
    InnerStruct(const InnerTopology& topology);

    InnerStruct(const InnerStruct&) = default;
    InnerStruct(InnerStruct&&) noexcept = default;
};

TRIXY_NET_TPL_DECLARATION
TRIXY_NET_TPL(TrixyNetType::FeedForward)::InnerStruct::InnerStruct(
    const Container<size_type>& topology)
    : B(TrixyNet::init1D(topology))
    , W(TrixyNet::init2D(topology))
    , topology(topology)
    , N(topology.size() - 1)
{
}

TRIXY_NET_TPL_DECLARATION
struct TRIXY_NET_TPL(TrixyNetType::FeedForward)::ActivationFunction
{
public:
    using Function        = void (*)(LVector&, const LVector&);
    using FunctionDerived = void (*)(LVector&, const LVector&);

public:
    Function f;           ///< void (*f)(LVector& buff, const LVector& tensor)
    FunctionDerived df;   ///< void (*df)(LVector& buff, const LVector& tensor)

    ActivationId id;

public:
    ActivationFunction() noexcept : id(ActivationId::undefined), f(nullptr), df(nullptr) {}

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
    using Function        = void (*)(precision_type&, const LVector&, const LVector&);
    using FunctionDerived = void (*)(LVector&, const LVector&, const LVector&);

public:
    Function f;           ///< void (*)(Precision& result, const LVector& target, const LVector& prediction)
    FunctionDerived df;   ///< void (*)(LVector& buff, const LVector& target, const LVector& prediction)

    LossId id;

public:
    LossFunction() noexcept : id(LossId::undefined), f(nullptr), df(nullptr) {}

    LossFunction(Function function,
                 FunctionDerived function_derived,
                 LossId function_id = LossId::undefined) noexcept
    : id(function_id)
    , f(function)
    , df(function_derived) {}
};

TRIXY_NET_TPL_DECLARATION
class TRIXY_NET_TPL(TrixyNetType::FeedForward)::InnerFunctional
{
friend TrixyNet;
friend train::Training<TrixyNet>;

private:
    ~InnerFunctional() = default;

public:
    using AllActivationFunction             = Container<ActivationFunction>;
    using AllActivationId                   = Container<ActivationId>;

private:
    AllActivationFunction activation;       ///< Network activation functions
    AllActivationId activationId;           ///< Network activation function ids

    LossFunction loss;                      ///< Network loss function

public:
    explicit InnerFunctional(size_type N) : activation(N), activationId(N), loss() {}

    InnerFunctional(const InnerFunctional&) = default;
    InnerFunctional(InnerFunctional&&) noexcept = default;

    void setActivation(const ActivationFunction&);
    void setAllActivation(const AllActivationFunction&);
    void setNormalization(const ActivationFunction&);

    void setLoss(const LossFunction&);

    const ActivationFunction& getActivation() const noexcept { return activation.front(); }
    const ActivationId& getActivationId() const noexcept { return activationId.front(); }

    const AllActivationFunction& getAllActivation() const noexcept { return activation; }
    const Container<ActivationId>& getAllActivationId() const noexcept { return activationId; }

    const ActivationFunction& getNormalization() const noexcept { return activation.back(); }
    const ActivationId& getNormalizationId() const noexcept { return activationId.back(); }

    const LossFunction& getLoss() const noexcept { return loss; }
    const LossId& getLossId() const noexcept { return loss.id; }

};

TRIXY_NET_TPL_DECLARATION
void TRIXY_NET_TPL(TrixyNetType::FeedForward)::InnerFunctional::setActivation(
    const TRIXY_NET_TPL(TrixyNetType::FeedForward)::ActivationFunction& f)
{
    for(size_type i = 0; i < activation.size() - 1; ++i)
    {
        activation  [i] = f;
        activationId[i] = f.id;
    }
}

TRIXY_NET_TPL_DECLARATION
void TRIXY_NET_TPL(TrixyNetType::FeedForward)::InnerFunctional::setAllActivation(
    const Container<ActivationFunction>& fs)
{
    for(size_type i = 0; i < activation.size(); ++i)
    {
        activation  [i] = fs[i];
        activationId[i] = fs[i].id;
    }
}

TRIXY_NET_TPL_DECLARATION
void TRIXY_NET_TPL(TrixyNetType::FeedForward)::InnerFunctional::setNormalization(
    const ActivationFunction& f)
{
    activation.  back() = f;
    activationId.back() = f.id;
}

TRIXY_NET_TPL_DECLARATION
void TRIXY_NET_TPL(TrixyNetType::FeedForward)::InnerFunctional::setLoss(
    const LossFunction& f)
{
    loss = f;
}

TRIXY_NET_TPL_DECLARATION
TRIXY_NET_TPL(TrixyNetType::FeedForward)::TrixyNet(
    const Container<size_type>& topology)
    : buff(TrixyNet::init1D(topology))
    , inner(topology)
    , function(topology.size() - 1)
{
}

TRIXY_NET_TPL_DECLARATION
template <class GeneratorPrecision>
void TRIXY_NET_TPL(TrixyNetType::FeedForward)::initializeInnerStruct(
    GeneratorPrecision generator_all) noexcept
{
    for(size_type i = 0; i < inner.N; ++i)
    {
        inner.B[i].fill(generator_all);
        inner.W[i].fill(generator_all);
    }
}

TRIXY_NET_TPL_DECLARATION
template <class GeneratorPrecision>
void TRIXY_NET_TPL(TrixyNetType::FeedForward)::initializeInnerStruct(
    GeneratorPrecision generator_bias,
    GeneratorPrecision generator_weight) noexcept
{
    for(size_type i = 0; i < inner.N; ++i)
    {
        inner.B[i].fill(generator_bias);
        inner.W[i].fill(generator_weight);
    }
}

TRIXY_NET_TPL_DECLARATION
void TRIXY_NET_TPL(TrixyNetType::FeedForward)::initializeInnerStruct(
    const Container<Vector>& bias,
    const Container<Matrix>& weight) noexcept
{
    for(size_type i = 0; i < inner.N; ++i)
    {
        inner.B[i].copy(bias[i]);
        inner.W[i].copy(weight[i]);
    }
}

TRIXY_NET_TPL_DECLARATION
const typename TRIXY_NET_TPL(TrixyNetType::FeedForward)::Vector&
    TRIXY_NET_TPL(TrixyNetType::FeedForward)::feedforward(
    const Vector& sample) const noexcept
{
    linear.dot(buff[0], sample, inner.W[0]);
    linear.add(buff[0], inner.B[0]);
    function.activation[0].f(buff[0], buff[0]);

    for(size_type i = 1; i < inner.N; ++i)
    {
        linear.dot(buff[i], buff[i - 1], inner.W[i]);
        linear.add(buff[i], inner.B[i]);
        function.activation[i].f(buff[i], buff[i]);
    }

    return buff.back().base();
}

TRIXY_NET_TPL_DECLARATION
template <typename... T>
typename TRIXY_NET_TPL(TrixyNetType::FeedForward)::template
    LContainer<typename TRIXY_NET_TPL(TrixyNetType::FeedForward)::LVector>
TRIXY_NET_TPL(TrixyNetType::FeedForward)::init1D(
    const Container<size_type>& topology, T&&... args)
{
    Container<LVector> data;

    data.reserve(topology.size() - 1);
    for(size_type i = 1; i < topology.size(); ++i)
        data.emplace_back(topology[i], std::forward<T>(args)...);

    return data;
}

TRIXY_NET_TPL_DECLARATION
template <typename... T>
typename TRIXY_NET_TPL(TrixyNetType::FeedForward)::template
    LContainer<typename TRIXY_NET_TPL(TrixyNetType::FeedForward)::LMatrix>
TRIXY_NET_TPL(TrixyNetType::FeedForward)::init2D(
    const Container<size_type>& topology, T&&... args)
{
    Container<LMatrix> data;

    data.reserve(topology.size() - 1);
    for(size_type i = 1; i < topology.size(); ++i)
        data.emplace_back(topology[i - 1], topology[i], std::forward<T>(args)...);

    return data;
}

TRIXY_NET_TPL_DECLARATION
long double TRIXY_NET_TPL(TrixyNetType::FeedForward)::accuracy(
    const Container<Vector>& idata,
    const Container<Vector>& odata) const noexcept
{
    size_type count = 0;

    for(size_type i = 0; i < odata.size(); ++i)
        if(check(odata[i], feedforward(idata[i])))
            ++count;

    return static_cast<long double>(count) / odata.size();
}

TRIXY_NET_TPL_DECLARATION
long double TRIXY_NET_TPL(TrixyNetType::FeedForward)::accuracyf(
    const Container<Vector>& idata,
    const Container<Vector>& odata,
    precision_type range_rate) const noexcept
{
    size_type count = 0;

    for(size_type i = 0; i < odata.size(); ++i)
        if(checkf(odata[i], feedforward(idata[i]), range_rate))
            ++count;

    return static_cast<long double>(count) / odata.size();
}

TRIXY_NET_TPL_DECLARATION
long double TRIXY_NET_TPL(TrixyNetType::FeedForward)::accuracyg(
    const Container<Vector>& idata,
    const Container<Vector>& odata,
    precision_type range_rate) const noexcept
{
    size_type count = 0;

    for(size_type i = 0; i < odata.size(); ++i)
        checkg(odata[i], feedforward(idata[i]), range_rate, count);

    return static_cast<long double>(count) / (odata.size() * odata.front().size());
}

TRIXY_NET_TPL_DECLARATION
long double TRIXY_NET_TPL(TrixyNetType::FeedForward)::loss(
    const Container<Vector>& idata,
    const Container<Vector>& odata) const noexcept
{
    precision_type result = 0.;
    precision_type error  = 0.;

    for(size_type i = 0; i < odata.size(); ++i)
    {
        function.loss.f(error, odata[i], feedforward(idata[i]));
        result += error;
    }

    return result / static_cast<long double>(odata.size());
}

TRIXY_NET_TPL_DECLARATION
bool TRIXY_NET_TPL(TrixyNetType::FeedForward)::check(
    const Vector& target,
    const Vector& prediction) const noexcept
{
    size_type max_true_out;
    size_type max_pred_out;

    max_true_out = 0;
    max_pred_out = 0;

    for(size_type j = 1; j < target.size(); ++j)
        if(target(max_true_out) < target(j))
            max_true_out = j;

    for(size_type j = 1; j < target.size(); ++j)
        if(prediction(max_pred_out) < prediction(j))
            max_pred_out = j;

    return max_true_out == max_pred_out;
}

TRIXY_NET_TPL_DECLARATION
bool TRIXY_NET_TPL(TrixyNetType::FeedForward)::checkf(
    const Vector& target,
    const Vector& prediction,
    precision_type range_rate) const noexcept
{
    for(size_type j = 0; j < target.size(); ++j)
        if(std::fabs(target(j) - prediction(j)) > range_rate)
            return false;

    return true;
}

TRIXY_NET_TPL_DECLARATION
void TRIXY_NET_TPL(TrixyNetType::FeedForward)::checkg(
    const Vector& target,
    const Vector& prediction,
    precision_type range_rate,
    size_type& count) const noexcept
{
    for(size_type i = 0; i < target.size(); ++i)
        if(std::fabs(target(i) - prediction(i)) < range_rate)
            ++count;
}

} // namespace trixy

#include "Trixy/Neuro/Detail/MacroUnscope.hpp"

#endif // FEED_FORWARD_NET_HPP
