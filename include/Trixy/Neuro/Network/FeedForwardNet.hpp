#ifndef FEED_FORWARD_NET_HPP
#define FEED_FORWARD_NET_HPP

#include <cstddef> // size_t
#include <cstdint> // uint8_t
#include <cmath> // fabs
#include <utility> // move

#include "Trixy/Neuro/Training/FeedForwardNetTraining.hpp"
#include "Trixy/Locker/LockerCore.hpp"

#include "Trixy/Neuro/Detail/TrixyNetMeta.hpp"

#include "Trixy/Neuro/Detail/MacroScope.hpp"

namespace trixy
{

TRIXY_NET_TPL_DECLARATION
class FeedForwardNet
{
public:
    struct InnerStruct;

    struct ActivationFunction;
    struct LossFunction;

private:
    class InnerFunctional;

public:
    template <typename... T>
    using ContainerType             = Container<T...>;

    template <typename... T>
    using LContainer                = ContainerLocker<Container<T...>>;

    using Vector                    = Tensor1D<Precision, Args...>;
    using Matrix                    = Tensor2D<Precision, Args...>;

    using LVector                   = VectorLocker<Vector>;
    using LMatrix                   = MatrixLocker<Matrix>;

    using precision_type            = Precision;
    using size_type                 = std::size_t;
    using byte_type                 = std::uint8_t;

    using TensorOperation           = Linear<precision_type>;

    using InnerBuffer               = LContainer<LVector>;
    using InnerTopology             = Container<size_type>;

private:
    mutable InnerBuffer buff;       ///< 1D buffer for handle

public:
    InnerStruct inner;              ///< Network set of bias and weight

    InnerFunctional function;       ///< Functional object for setup inner network function
    TensorOperation linear;         ///< Linear class for tensor calculate

public:
    FeedForwardNet(const Container<size_type>& topology);

    const LVector& feedforward(const LVector& sample) const noexcept;

    long double accuracy(const Container<LVector>& idata,
                         const Container<LVector>& odata) const noexcept;

    long double accuracyf(const Container<LVector>& idata,
                          const Container<LVector>& odata,
                          Precision range_rate) const noexcept;

    long double accuracyg(const Container<LVector>& idata,
                          const Container<LVector>& odata,
                          Precision range_rate) const noexcept;

    long double loss(const Container<LVector>& idata,
                     const Container<LVector>& odata) const noexcept;

private:
    bool check(const LVector& target,
               const LVector& prediction) const noexcept;

    bool checkf(const LVector& target,
                const LVector& prediction,
                Precision range_rate) const noexcept;

    void checkg(const LVector& target,
                const LVector& prediction,
                Precision range_rate,
                size_type& count) const noexcept;

public:
    template <typename GeneratorPrecision>
    void initializeInnerStruct(GeneratorPrecision generator_all) noexcept;

    template <typename GeneratorPrecision>
    void initializeInnerStruct(GeneratorPrecision generator_bias,
                               GeneratorPrecision generator_weight) noexcept;

    void initializeInnerStruct(const Container<Vector>& bias,
                               const Container<Matrix>& weight) noexcept;

    const Container<LVector>& getInnerBias() const noexcept { return inner.B.get(); }
    const Container<LMatrix>& getInnerWeight() const noexcept { return inner.W.get(); }
    const Container<size_type>& getTopology() const noexcept { return inner.topology; }

public:
    template <typename... T>
    static LContainer<LVector> init1D(const Container<size_type>& topology, T&&... args);
    template <typename... T>
    static LContainer<LMatrix> init2D(const Container<size_type>& topology, T&&... args);
};

TRIXY_NET_TPL_DECLARATION
struct TRIXY_FEED_FORWARD_NET_TPL::InnerStruct
{
public:
    LContainer<LVector> B;          ///< Container of network bias
    LContainer<LMatrix> W;          ///< Container of network weight

    const InnerTopology topology;   ///< Network topology
    const size_type N;              ///< Number of functional layer (same as topology_size - 1)

public:
    InnerStruct(const Container<size_type>& topology);
};

TRIXY_NET_TPL_DECLARATION
TRIXY_FEED_FORWARD_NET_TPL::InnerStruct::InnerStruct(
    const Container<size_type>& topology)
    : B(FeedForwardNet::init1D(topology))
    , W(FeedForwardNet::init2D(topology))
    , topology(topology)
    , N(topology.size() - 1)
{
}

TRIXY_NET_TPL_DECLARATION
struct TRIXY_FEED_FORWARD_NET_TPL::ActivationFunction
{
public:
    using Function        = void (*)(LVector&, const LVector&);
    using FunctionDerived = void (*)(LVector&, const LVector&);

public:
    Function f;           ///< void (*f)(LVector& buff, const LVector& tensor)
    FunctionDerived df;   ///< void (*df)(LVector& buff, const LVector& tensor)

    byte_type id;

public:
    ActivationFunction() noexcept : id(0), f(nullptr), df(nullptr) {}

    ActivationFunction(Function function,
                       FunctionDerived function_derived,
                       byte_type function_id = 0) noexcept
    : f(function)
    , df(function_derived)
    , id(function_id) {}
};

TRIXY_NET_TPL_DECLARATION
struct TRIXY_FEED_FORWARD_NET_TPL::LossFunction
{
public:
    using Function        = void (*)(Precision&, const LVector&, const LVector&);
    using FunctionDerived = void (*)(LVector&, const LVector&, const LVector&);

public:
    Function f;           ///< void (*)(Precision& result, const LVector& target, const LVector& prediction)
    FunctionDerived df;   ///< void (*)(LVector& buff, const LVector& target, const LVector& prediction)

    byte_type id;

public:
    LossFunction() noexcept : id(0), f(nullptr), df(nullptr) {}

    LossFunction(Function function,
                 FunctionDerived function_derived,
                 byte_type function_id = 0) noexcept
    : id(function_id)
    , f(function)
    , df(function_derived) {}
};

TRIXY_NET_TPL_DECLARATION
class TRIXY_FEED_FORWARD_NET_TPL::InnerFunctional
{
friend TRIXY_FEED_FORWARD_NET_TPL;
friend train::Training<FeedForwardNet>;

private:
    ~InnerFunctional() = default;

private:
    Container<ActivationFunction> activation;
    LossFunction loss;

public:
    explicit InnerFunctional(size_type N) : activation(N), loss() {}

    void setActivation(const ActivationFunction&);
    void setAllActivation(const Container<ActivationFunction>&);
    void setNormalization(const ActivationFunction&);

    void setLoss(const LossFunction&);

    const ActivationFunction& getActivation() const noexcept { return activation.front(); }
    const Container<ActivationFunction>& getAllActivation() const noexcept { return activation; }
    const ActivationFunction& getNormalization() const noexcept { return activation.back(); }

    const LossFunction& getLoss() const noexcept { return loss; }
};

TRIXY_NET_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NET_TPL::InnerFunctional::setActivation(
    const TRIXY_FEED_FORWARD_NET_TPL::ActivationFunction& f)
{
    for(size_type i = 0; i < activation.size() - 1; ++i)
        activation[i] = f;
}

TRIXY_NET_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NET_TPL::InnerFunctional::setAllActivation(
    const Container<TRIXY_FEED_FORWARD_NET_TPL::ActivationFunction>& fs)
{
    for(size_type i = 0; i < activation.size(); ++i)
        activation[i] = fs[i];
}

TRIXY_NET_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NET_TPL::InnerFunctional::setNormalization(
    const TRIXY_FEED_FORWARD_NET_TPL::ActivationFunction& f)
{
    activation.back() = f;
}

TRIXY_NET_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NET_TPL::InnerFunctional::setLoss(
    const TRIXY_FEED_FORWARD_NET_TPL::LossFunction& f)
{
    loss = f;
}

TRIXY_NET_TPL_DECLARATION
TRIXY_FEED_FORWARD_NET_TPL::FeedForwardNet(
    const Container<size_type>& topology)
    : buff(FeedForwardNet::init1D(topology))
    , inner(topology)
    , function(topology.size() - 1)
{
}

TRIXY_NET_TPL_DECLARATION
template <typename GeneratorPrecision>
void TRIXY_FEED_FORWARD_NET_TPL::initializeInnerStruct(
    GeneratorPrecision generator_all) noexcept
{
    for(size_type i = 0; i < inner.N; ++i)
    {
        inner.B[i].fill(generator_all);
        inner.W[i].fill(generator_all);
    }
}

TRIXY_NET_TPL_DECLARATION
template <typename GeneratorPrecision>
void TRIXY_FEED_FORWARD_NET_TPL::initializeInnerStruct(
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
void TRIXY_FEED_FORWARD_NET_TPL::initializeInnerStruct(
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
const typename TRIXY_FEED_FORWARD_NET_TPL::LVector& TRIXY_FEED_FORWARD_NET_TPL::feedforward(
    const LVector& sample) const noexcept
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

    return buff.back();
}

TRIXY_NET_TPL_DECLARATION
template <typename... T>
typename TRIXY_FEED_FORWARD_NET_TPL::template LContainer<typename TRIXY_FEED_FORWARD_NET_TPL::LVector>
TRIXY_FEED_FORWARD_NET_TPL::init1D(const Container<size_type>& topology, T&&... args)
{
    Container<LVector> data;

    data.reserve(topology.size() - 1);
    for(size_type i = 1; i < topology.size(); ++i)
        data.emplace_back(topology[i], std::forward<T>(args)...);

    return { std::move(data) };
}

TRIXY_NET_TPL_DECLARATION
template <typename... T>
typename TRIXY_FEED_FORWARD_NET_TPL::template LContainer<typename TRIXY_FEED_FORWARD_NET_TPL::LMatrix>
TRIXY_FEED_FORWARD_NET_TPL::init2D(const Container<size_type>& topology, T&&... args)
{
    Container<LMatrix> data;

    data.reserve(topology.size() - 1);
    for(size_type i = 1; i < topology.size(); ++i)
        data.emplace_back(topology[i - 1], topology[i], std::forward<T>(args)...);

    return { std::move(data) };
}

TRIXY_NET_TPL_DECLARATION
long double TRIXY_FEED_FORWARD_NET_TPL::accuracy(
    const Container<LVector>& idata,
    const Container<LVector>& odata) const noexcept
{
    size_type count = 0;

    for(size_type i = 0; i < odata.size(); ++i)
        if(check(odata[i], feedforward(idata[i])))
            ++count;

    return static_cast<long double>(count) / odata.size();
}

TRIXY_NET_TPL_DECLARATION
long double TRIXY_FEED_FORWARD_NET_TPL::accuracyf(
    const Container<LVector>& idata,
    const Container<LVector>& odata,
    Precision range_rate) const noexcept
{
    size_type count = 0;

    for(size_type i = 0; i < odata.size(); ++i)
        if(checkf(odata[i], feedforward(idata[i]), range_rate))
            ++count;

    return static_cast<long double>(count) / odata.size();
}

TRIXY_NET_TPL_DECLARATION
long double TRIXY_FEED_FORWARD_NET_TPL::accuracyg(
    const Container<LVector>& idata,
    const Container<LVector>& odata,
    Precision range_rate) const noexcept
{
    size_type count = 0;

    for(size_type i = 0; i < odata.size(); ++i)
        checkg(odata[i], feedforward(idata[i]), range_rate, count);

    return static_cast<long double>(count) / (odata.size() * odata.front().size());
}

TRIXY_NET_TPL_DECLARATION
long double TRIXY_FEED_FORWARD_NET_TPL::loss(
    const Container<LVector>& idata,
    const Container<LVector>& odata) const noexcept
{
    Precision result = 0.;
    Precision error  = 0.;

    for(size_type i = 0; i < odata.size(); ++i)
    {
        function.loss.f(error, odata[i], feedforward(idata[i]));
        result += error;
    }

    return result / static_cast<long double>(odata.size());
}

TRIXY_NET_TPL_DECLARATION
bool TRIXY_FEED_FORWARD_NET_TPL::check(
    const LVector& target,
    const LVector& prediction) const noexcept
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
bool TRIXY_FEED_FORWARD_NET_TPL::checkf(
    const LVector& target,
    const LVector& prediction,
    Precision range_rate) const noexcept
{
    for(size_type j = 0; j < target.size(); ++j)
        if(std::fabs(target(j) - prediction(j)) > range_rate)
            return false;

    return true;
}

TRIXY_NET_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NET_TPL::checkg(
    const LVector& target,
    const LVector& prediction,
    Precision range_rate,
    size_type& count) const noexcept
{
    for(size_type i = 0; i < target.size(); ++i)
        if(std::fabs(target(i) - prediction(i)) < range_rate)
            ++count;
}

} // namespace trixy

#include "Trixy/Neuro/Detail/MacroUnscope.hpp"

#endif // FEED_FORWARD_NET_HPP
