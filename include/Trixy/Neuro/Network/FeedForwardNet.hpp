#ifndef FEED_FORWARD_NET_HPP
#define FEED_FORWARD_NET_HPP

#include <cstddef> // size_t
#include <cstdint> // uint8_t
#include <cmath> // fabs

#include "Trixy/Neuro/Training/FeedForwardNetTraining.hpp"
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
    using Tensor1D                  = Vector<Precision, Args...>;
    using Tensor2D                  = Matrix<Precision, Args...>;
    using TensorOperation           = Linear<Vector, Matrix, Precision, Args...>;

    using InnerBuffer               = Container<Vector<Precision, Args...>>;
    using InnerTopology             = Container<std::size_t>;
    template <typename... T>
    using ContainerType             = Container<T...>;

    using precision_type            = Precision;
    using size_type                 = std::size_t;
    using byte_type                 = std::uint8_t;

private:
    mutable InnerBuffer buff;       ///< 1D buffer for handle

public:
    InnerStruct inner;              ///< Network set of bias and weight

    InnerFunctional function;       ///< Functional object for setup inner network function
    TensorOperation linear;         ///< Linear class for tensor calculate

public:
    FeedForwardNet(const Container<size_type>& topology);

    const Tensor1D& feedforward(const Tensor1D& sample) const noexcept;

    long double accuracy(const Container<Tensor1D>& idata,
                         const Container<Tensor1D>& odata) const noexcept;

    long double accuracyf(const Container<Tensor1D>& idata,
                          const Container<Tensor1D>& odata,
                          Precision range_rate) const noexcept;

    long double accuracyg(const Container<Tensor1D>& idata,
                          const Container<Tensor1D>& odata,
                          Precision range_rate) const noexcept;

    long double loss(const Container<Tensor1D>& idata,
                     const Container<Tensor1D>& odata) const noexcept;

private:
    bool check(const Tensor1D& target,
               const Tensor1D& prediction) const noexcept;

    bool checkf(const Tensor1D& target,
                const Tensor1D& prediction,
                Precision range_rate) const noexcept;

    void checkg(const Tensor1D& target,
                const Tensor1D& prediction,
                Precision range_rate,
                size_type& count) const noexcept;

public:
    template <typename GeneratorPrecision>
    void initializeInnerStruct(GeneratorPrecision generator_all) noexcept;

    template <typename GeneratorPrecision>
    void initializeInnerStruct(GeneratorPrecision generator_bias,
                               GeneratorPrecision generator_weight) noexcept;

    void initializeInnerStruct(const Container<Tensor1D>& bias,
                               const Container<Tensor2D>& weight) noexcept;

    const Container<Tensor1D>& getInnerBias() const noexcept;
    const Container<Tensor2D>& getInnerWeight() const noexcept;
    const Container<size_type>& getTopology() const noexcept;
};

TRIXY_NET_TPL_DECLARATION
struct TRIXY_FEED_FORWARD_NET_TPL::InnerStruct
{
public:
    const InnerTopology topology;   ///< Network topology
    const size_type N;              ///< Number of functional layer (same as topology_size - 1)

    Container<Tensor1D> B;          ///< Container of network bias
    Container<Tensor2D> W;          ///< Container of network weight

public:
    InnerStruct(const Container<size_type>& topology);
};

TRIXY_NET_TPL_DECLARATION
TRIXY_FEED_FORWARD_NET_TPL::InnerStruct::InnerStruct(
    const Container<size_type>& topology)
    : topology(topology)
    , N(topology.size() - 1)
    , B(topology.size() - 1)
    , W(topology.size() - 1)
{
    for(size_type i = 0; i < N; ++i)
    {
        B[i].resize(topology[i + 1]);
        W[i].resize(topology[i], topology[i + 1]);
    }
}

TRIXY_NET_TPL_DECLARATION
struct TRIXY_FEED_FORWARD_NET_TPL::ActivationFunction
{
public:
    using Function        = void (*)(Tensor1D&, const Tensor1D&);
    using FunctionDerived = void (*)(Tensor1D&, const Tensor1D&);

public:
    Function f;           ///< void (*f)(Tensor1D& buff, const Tensor1D& tensor)
    FunctionDerived df;   ///< void (*df)(Tensor1D& buff, const Tensor1D& tensor)

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
    using Function        = void (*)(Precision&, const Tensor1D&, const Tensor1D&);
    using FunctionDerived = void (*)(Tensor1D&, const Tensor1D&, const Tensor1D&);

public:
    Function f;           ///< void (*)(Precision& result, const Tensor1D& target, const Tensor1D& prediction)
    FunctionDerived df;   ///< void (*)(Tensor1D& buff, const Tensor1D& target, const Tensor1D& prediction)

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

    const ActivationFunction& getActivation() const noexcept;
    const Container<ActivationFunction>& getAllActivation() const noexcept;
    const ActivationFunction& getNormalization() const noexcept;

    const LossFunction& getLoss() const noexcept;
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
inline const typename TRIXY_FEED_FORWARD_NET_TPL::ActivationFunction&
    TRIXY_FEED_FORWARD_NET_TPL::InnerFunctional::getActivation() const noexcept
{
    return activation.front();
}

TRIXY_NET_TPL_DECLARATION
inline const Container<typename TRIXY_FEED_FORWARD_NET_TPL::ActivationFunction>&
    TRIXY_FEED_FORWARD_NET_TPL::InnerFunctional::getAllActivation() const noexcept
{
    return activation;
}

TRIXY_NET_TPL_DECLARATION
inline const typename TRIXY_FEED_FORWARD_NET_TPL::ActivationFunction&
    TRIXY_FEED_FORWARD_NET_TPL::InnerFunctional::getNormalization() const noexcept
{
    return activation.back();
}

TRIXY_NET_TPL_DECLARATION
inline const typename TRIXY_FEED_FORWARD_NET_TPL::LossFunction&
    TRIXY_FEED_FORWARD_NET_TPL::InnerFunctional::getLoss() const noexcept
{
    return loss;
}

TRIXY_NET_TPL_DECLARATION
TRIXY_FEED_FORWARD_NET_TPL::FeedForwardNet(
    const Container<size_type>& topology)
    : buff(topology.size() - 1)
    , inner(topology)
    , function(topology.size() - 1)
{
    for(size_type i = 0; i < inner.N; ++i)
        buff[i].resize(topology[i + 1]);
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
    const Container<Tensor1D>& bias,
    const Container<Tensor2D>& weight) noexcept
{
    for(size_type i = 0; i < inner.N; ++i)
    {
        inner.B[i].copy(bias[i]);
        inner.W[i].copy(weight[i]);
    }
}

TRIXY_NET_TPL_DECLARATION
inline const Container<typename TRIXY_FEED_FORWARD_NET_TPL::Tensor1D>&
    TRIXY_FEED_FORWARD_NET_TPL::getInnerBias() const noexcept
{
    return inner.B;
}

TRIXY_NET_TPL_DECLARATION
inline const Container<typename TRIXY_FEED_FORWARD_NET_TPL::Tensor2D>&
    TRIXY_FEED_FORWARD_NET_TPL::getInnerWeight() const noexcept
{
    return inner.W;
}

TRIXY_NET_TPL_DECLARATION
inline const Container<typename TRIXY_FEED_FORWARD_NET_TPL::size_type>&
    TRIXY_FEED_FORWARD_NET_TPL::getTopology() const noexcept
{
    return inner.topology;
}

TRIXY_NET_TPL_DECLARATION
const typename TRIXY_FEED_FORWARD_NET_TPL::Tensor1D& TRIXY_FEED_FORWARD_NET_TPL::feedforward(
    const Tensor1D& sample) const noexcept
{
    linear.dot(buff[0], sample, inner.W[0]);
    function.activation[0].f(buff[0], buff[0].add(inner.B[0]));

    for(size_type i = 1; i < inner.N; ++i)
    {
        linear.dot(buff[i], buff[i - 1], inner.W[i]);
        function.activation[i].f(buff[i], buff[i].add(inner.B[i]));
    }

    return buff.back();
}

TRIXY_NET_TPL_DECLARATION
long double TRIXY_FEED_FORWARD_NET_TPL::accuracy(
    const Container<Tensor1D>& idata,
    const Container<Tensor1D>& odata) const noexcept
{
    size_type count = 0;

    for(size_type i = 0; i < odata.size(); ++i)
        if(check(odata[i], feedforward(idata[i])))
            ++count;

    return static_cast<long double>(count) / odata.size();
}

TRIXY_NET_TPL_DECLARATION
long double TRIXY_FEED_FORWARD_NET_TPL::accuracyf(
    const Container<Tensor1D>& idata,
    const Container<Tensor1D>& odata,
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
    const Container<Tensor1D>& idata,
    const Container<Tensor1D>& odata,
    Precision range_rate) const noexcept
{
    size_type count = 0;

    for(size_type i = 0; i < odata.size(); ++i)
        checkg(odata[i], feedforward(idata[i]), range_rate, count);

    return static_cast<long double>(count) / (odata.size() * odata.front().size());
}

TRIXY_NET_TPL_DECLARATION
long double TRIXY_FEED_FORWARD_NET_TPL::loss(
    const Container<Tensor1D>& idata,
    const Container<Tensor1D>& odata) const noexcept
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
    const Tensor1D& target,
    const Tensor1D& prediction) const noexcept
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
    const Tensor1D& target,
    const Tensor1D& prediction,
    Precision range_rate) const noexcept
{
    for(size_type j = 0; j < target.size(); ++j)
        if(std::fabs(target(j) - prediction(j)) > range_rate)
            return false;

    return true;
}

TRIXY_NET_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NET_TPL::checkg(
    const Tensor1D& target,
    const Tensor1D& prediction,
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
