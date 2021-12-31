#ifndef FEEDFORWARD_NEURO_HPP
#define FEEDFORWARD_NEURO_HPP

#include <cstddef> // size_t
#include <cstdint> // uint8_t
#include <cmath> // fabs

#include "../Detail/macro_scope.hpp"

namespace trixy
{

TRIXY_NEURO_NETWORK_TPL_DECLARATION
class FeedForwardNeuro
{
public:
    struct ActivationFunction;
    struct LossFunction;

private:
    class InnerBuffer;
    class InnerFunctional;

public:
    using Tensor1D             = Vector<Precision, Args...>;
    using Tensor2D             = Matrix<Precision, Args...>;
    using TensorOperation      = Linear<Vector, Matrix, Precision, Args...>;

    template <typename... T>
    using ContainerType        = Container<T...>;

    using precision_type       = Precision;
    using size_type            = std::size_t;
    using byte_type            = std::uint8_t;

private:
    mutable InnerBuffer imanage;    ///< Inner buffer (class for temporary hold storage)

    Container<Tensor1D> B;          ///< Container of network bias
    Container<Tensor2D> W;          ///< Container of network weight

    size_type N;                    ///< Number of functional layer (same as topology_size - 1)

public:
    InnerFunctional function;       ///< Functional object for set & get each inner network function

private:
    TensorOperation linear;         ///< Linear class for tensor calculate

public:
    FeedForwardNeuro(const Container<size_type>& neural_network_topology);

    const Tensor1D& feedforward(const Tensor1D& sample) const noexcept;

    template <class GeneratorInteger, class Optimizer>
    void trainStochastic(const Container<Tensor1D>& idata,
                         const Container<Tensor1D>& odata,
                         size_type epoch_scale,
                         GeneratorInteger generator,
                         Optimizer&& optimizer) noexcept;

    template <class Optimizer>
    void trainBatch(const Container<Tensor1D>& idata,
                    const Container<Tensor1D>& odata,
                    size_type epoch_scale,
                    Optimizer&& optimizer) noexcept;

    template <class GeneratorInteger, class Optimizer>
    void trainMiniBatch(const Container<Tensor1D>& idata,
                        const Container<Tensor1D>& odata,
                        size_type epoch_scale,
                        size_type mini_batch_size,
                        GeneratorInteger generator,
                        Optimizer&& optimizer) noexcept;

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
    void innerFeedForward(const Tensor1D& sample) const noexcept;

    void innerBackPropagation(const Tensor1D& sample,
                              const Tensor1D& target) const noexcept;

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

TRIXY_NEURO_NETWORK_TPL_DECLARATION
struct TRIXY_FEED_FORWARD_NEURO_TPL::ActivationFunction
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

TRIXY_NEURO_NETWORK_TPL_DECLARATION
struct TRIXY_FEED_FORWARD_NEURO_TPL::LossFunction
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

TRIXY_NEURO_NETWORK_TPL_DECLARATION
class TRIXY_FEED_FORWARD_NEURO_TPL::InnerBuffer
{
friend class TRIXY_FEED_FORWARD_NEURO_TPL;

private:
    const size_type size_;                ///< Number of functional layer for each storage (same as topology_size - 1)
    const Container<size_type> topology;  ///< Network topology

    Container<Tensor1D> H;                ///< hidden layer storage
    Container<Tensor1D> derivedH;         ///< derived hidden layer storage

    Container<Tensor1D> derivedB;         ///< derived bias storage (using for inner updates)
    Container<Tensor2D> derivedW;         ///< derived weight storage (using for inner updates)

    Container<Tensor1D> deltaB;           ///< delta bias storage (using with derived bias and for inner updates)
    Container<Tensor2D> deltaW;           ///< delta weight storage (using with derived weight and for inner updates)

    Container<Tensor1D> buff;             ///< 1D buffer for handle

public:
    explicit InnerBuffer(const Container<size_type>& neural_network_topology);

    void initializeDefault();
    void initializeDelta();
    void initializeBuffer();

private:
    void resetDelta() noexcept;
    void updateDelta() noexcept;

    void normalizeDelta(Precision alpha) noexcept; ///< alpha should be in range (0, 1)
};

TRIXY_NEURO_NETWORK_TPL_DECLARATION
class TRIXY_FEED_FORWARD_NEURO_TPL::InnerFunctional
{
friend class TRIXY_FEED_FORWARD_NEURO_TPL;

private:
    ~InnerFunctional() = default;

private:
    Container<ActivationFunction> activation;
    LossFunction loss;

public:
    explicit InnerFunctional(size_type N) : activation(N), loss() {}
    InnerFunctional& operator= (const InnerFunctional&) = delete;

    void setActivation(const ActivationFunction&);
    void setEachActivation(const Container<ActivationFunction>&); // maybe unused
    void setNormalization(const ActivationFunction&);

    void setLoss(const LossFunction&);

    const ActivationFunction& getActivation() const noexcept;
    const Container<ActivationFunction>& getEachActivation() const noexcept; // maybe unused
    const ActivationFunction& getNormalization() const noexcept;

    const LossFunction& getLoss() const noexcept;
};

TRIXY_NEURO_NETWORK_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::InnerFunctional::setActivation(
    const TRIXY_FEED_FORWARD_NEURO_TPL::ActivationFunction& f)
{
    for(size_type i = 0; i < activation.size() - 1; ++i)
        activation[i] = f;
}

TRIXY_NEURO_NETWORK_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::InnerFunctional::setEachActivation(
    const Container<TRIXY_FEED_FORWARD_NEURO_TPL::ActivationFunction>& fs)
{
    for(size_type i = 0; i < activation.size(); ++i)
        activation[i] = fs[i];
}

TRIXY_NEURO_NETWORK_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::InnerFunctional::setNormalization(
    const TRIXY_FEED_FORWARD_NEURO_TPL::ActivationFunction& f)
{
    activation[activation.size() - 1] = f;
}

TRIXY_NEURO_NETWORK_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::InnerFunctional::setLoss(
    const TRIXY_FEED_FORWARD_NEURO_TPL::LossFunction& f)
{
    loss = f;
}

TRIXY_NEURO_NETWORK_TPL_DECLARATION
inline const typename TRIXY_FEED_FORWARD_NEURO_TPL::ActivationFunction&
    TRIXY_FEED_FORWARD_NEURO_TPL::InnerFunctional::getActivation() const noexcept
{
    return activation[0];
}

TRIXY_NEURO_NETWORK_TPL_DECLARATION
inline const Container<typename TRIXY_FEED_FORWARD_NEURO_TPL::ActivationFunction>&
    TRIXY_FEED_FORWARD_NEURO_TPL::InnerFunctional::getEachActivation() const noexcept
{
    return activation;
}

TRIXY_NEURO_NETWORK_TPL_DECLARATION
inline const typename TRIXY_FEED_FORWARD_NEURO_TPL::ActivationFunction&
    TRIXY_FEED_FORWARD_NEURO_TPL::InnerFunctional::getNormalization() const noexcept
{
    return activation[activation.size() - 1];
}

TRIXY_NEURO_NETWORK_TPL_DECLARATION
inline const typename TRIXY_FEED_FORWARD_NEURO_TPL::LossFunction&
    TRIXY_FEED_FORWARD_NEURO_TPL::InnerFunctional::getLoss() const noexcept
{
    return loss;
}

TRIXY_NEURO_NETWORK_TPL_DECLARATION
TRIXY_FEED_FORWARD_NEURO_TPL::InnerBuffer::InnerBuffer(
    const Container<size_type>& neural_network_topology)
    : size_(neural_network_topology.size() - 1)
    , topology(neural_network_topology)
{
    initializeBuffer();

    initializeDefault();
    initializeDelta();
}

TRIXY_NEURO_NETWORK_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::InnerBuffer::initializeDefault()
{
    H.resize(size_);
    derivedH.resize(size_);

    derivedB.resize(size_);
    derivedW.resize(size_);

    for(size_type i = 0; i < size_; ++i)
    {
        H[i].resize(topology[i + 1]);
        derivedH[i].resize(topology[i + 1]);

        derivedB[i].resize(topology[i + 1]);
        derivedW[i].resize(topology[i], topology[i + 1]);
    }
}

TRIXY_NEURO_NETWORK_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::InnerBuffer::initializeDelta()
{
    deltaB.resize(size_);
    deltaW.resize(size_);

    for(size_type i = 0; i < size_; ++i)
    {
        deltaB[i].resize(topology[i + 1]);
        deltaW[i].resize(topology[i], topology[i + 1]);
    }
}

TRIXY_NEURO_NETWORK_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::InnerBuffer::initializeBuffer()
{
    buff.resize(size_);

    for(size_type i = 0; i < size_; ++i)
        buff[i].resize(topology[i + 1]);
}

TRIXY_NEURO_NETWORK_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::InnerBuffer::resetDelta() noexcept
{
    for(size_type i = 0; i < size_; ++i)
    {
        deltaB[i].fill(0.0);
        deltaW[i].fill(0.0);
    }
}

TRIXY_NEURO_NETWORK_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::InnerBuffer::updateDelta() noexcept
{
    for(size_type i = 0; i < size_; ++i)
    {
        deltaB[i].add(derivedB[i]);
        deltaW[i].add(derivedW[i]);
    }
}

TRIXY_NEURO_NETWORK_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::InnerBuffer::normalizeDelta(Precision alpha) noexcept
{
    for(size_type i = 0; i < size_; ++i)
    {
        deltaB[i].join(alpha);
        deltaW[i].join(alpha);
    }
}

TRIXY_NEURO_NETWORK_TPL_DECLARATION
TRIXY_FEED_FORWARD_NEURO_TPL::FeedForwardNeuro(
    const Container<std::size_t>& neural_network_topology)
    : imanage(neural_network_topology)
    , B(neural_network_topology.size() - 1)
    , W(neural_network_topology.size() - 1)
    , N(neural_network_topology.size() - 1)
    , function(neural_network_topology.size() - 1)
{
    for(size_type i = 0; i < N; ++i)
    {
        B[i].resize(imanage.topology[i + 1]);
        W[i].resize(imanage.topology[i], imanage.topology[i + 1]);
    }
}

TRIXY_NEURO_NETWORK_TPL_DECLARATION
template <typename GeneratorPrecision>
void TRIXY_FEED_FORWARD_NEURO_TPL::initializeInnerStruct(
    GeneratorPrecision generator_all) noexcept
{
    for(size_type i = 0; i < N; ++i)
    {
        B[i].fill(generator_all);
        W[i].fill(generator_all);
    }
}

TRIXY_NEURO_NETWORK_TPL_DECLARATION
template <typename GeneratorPrecision>
void TRIXY_FEED_FORWARD_NEURO_TPL::initializeInnerStruct(
    GeneratorPrecision generator_bias,
    GeneratorPrecision generator_weight) noexcept
{
    for(size_type i = 0; i < N; ++i)
    {
        B[i].fill(generator_bias);
        W[i].fill(generator_weight);
    }
}

TRIXY_NEURO_NETWORK_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::initializeInnerStruct(
    const Container<Tensor1D>& bias,
    const Container<Tensor2D>& weight) noexcept
{
    for(size_type i = 0; i < N; ++i)
    {
        B[i].copy(bias[i]);
        W[i].copy(weight[i]);
    }
}

TRIXY_NEURO_NETWORK_TPL_DECLARATION
inline const Container<Vector<Precision, Args...>>&
    TRIXY_FEED_FORWARD_NEURO_TPL::getInnerBias() const noexcept
{
    return B;
}

TRIXY_NEURO_NETWORK_TPL_DECLARATION
inline const Container<Matrix<Precision, Args...>>&
    TRIXY_FEED_FORWARD_NEURO_TPL::getInnerWeight() const noexcept
{
    return W;
}

TRIXY_NEURO_NETWORK_TPL_DECLARATION
inline const Container<std::size_t>& TRIXY_FEED_FORWARD_NEURO_TPL::getTopology() const noexcept
{
    return imanage.topology;
}

TRIXY_NEURO_NETWORK_TPL_DECLARATION
const Vector<Precision, Args...>& TRIXY_FEED_FORWARD_NEURO_TPL::feedforward(
    const Vector<Precision, Args...>& sample) const noexcept
{
    linear.dot(imanage.buff[0], sample, W[0]);
    function.activation[0].f(imanage.buff[0], imanage.buff[0].add(B[0]));

    for(size_type i = 1; i < N; ++i)
    {
        linear.dot(imanage.buff[i], imanage.buff[i - 1], W[i]);
        function.activation[i].f(imanage.buff[i], imanage.buff[i].add(B[i]));
    }

    return imanage.buff[N - 1];
}

TRIXY_NEURO_NETWORK_TPL_DECLARATION
template <class GeneratorInteger, class Optimizer>
void TRIXY_FEED_FORWARD_NEURO_TPL::trainStochastic(
    const Container<Vector<Precision, Args...>>& idata,
    const Container<Vector<Precision, Args...>>& odata,
    std::size_t epoch_scale,
    GeneratorInteger generator,
    Optimizer&& optimizer) noexcept
{
    for(size_type epoch = 0, sample; epoch < epoch_scale; ++epoch)
    {
        sample = generator() % idata.size();

        innerFeedForward(idata[sample]);
        innerBackPropagation(idata[sample], odata[sample]);

        optimizer.update(B, W, imanage.derivedB, imanage.derivedW);
    }
}

TRIXY_NEURO_NETWORK_TPL_DECLARATION
template <class Optimizer>
void TRIXY_FEED_FORWARD_NEURO_TPL::trainBatch(
    const Container<Vector<Precision, Args...>>& idata,
    const Container<Vector<Precision, Args...>>& odata,
    std::size_t epoch_scale,
    Optimizer&& optimizer) noexcept
{
    Precision alpha = 1. / static_cast<Precision>(idata.size());

    for(size_type epoch = 0; epoch < epoch_scale; ++epoch)
    {
        imanage.resetDelta();

        for(size_type sample = 0; sample < idata.size(); ++sample)
        {
            innerFeedForward(idata[sample]);
            innerBackPropagation(idata[sample], odata[sample]);
            imanage.updateDelta();
        }

        imanage.normalizeDelta(alpha);

        optimizer.update(B, W, imanage.deltaB, imanage.deltaW);
    }
}

TRIXY_NEURO_NETWORK_TPL_DECLARATION
    template <class GeneratorInteger, class Optimizer>
void TRIXY_FEED_FORWARD_NEURO_TPL::trainMiniBatch(
    const Container<Vector<Precision, Args...>>& idata,
    const Container<Vector<Precision, Args...>>& odata,
    std::size_t epoch_scale,
    std::size_t mini_batch_size,
    GeneratorInteger generator,
    Optimizer&& optimizer) noexcept
{
    Precision alpha = 1. / static_cast<Precision>(mini_batch_size);

    size_type batch_part;
    size_type sample_beg;
    size_type sample_end;

    for(size_type epoch = 0; epoch < epoch_scale; ++epoch)
    {
        batch_part = generator() % (idata.size() / mini_batch_size);
        sample_beg = batch_part * mini_batch_size;
        sample_end = sample_beg + mini_batch_size;

        imanage.resetDelta();

        while(sample_beg < sample_end)
        {
            innerFeedForward(idata[sample_beg]);
            innerBackPropagation(idata[sample_beg], odata[sample_beg]);
            imanage.updateDelta();

            ++sample_beg;
        }

        imanage.normalizeDelta(alpha);

        optimizer.update(B, W, imanage.deltaB, imanage.deltaW);
    }
}

TRIXY_NEURO_NETWORK_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::innerFeedForward(
    const Vector<Precision, Args...>& sample) const noexcept
{
    size_type i;
    size_type j;

    linear.dot(imanage.buff[0], sample, W[0]);
    imanage.buff[0].add(B[0]);

    for(i = 0, j = 1; j < N; ++i, ++j)
    {
        function.activation[i]. f(imanage.H[i],        imanage.buff[i]);
        function.activation[i].df(imanage.derivedH[i], imanage.buff[i]);

        linear.dot(imanage.buff[j], imanage.H[i], W[j]);
        imanage.buff[j].add(B[j]);
    }

    function.activation[i]. f(imanage.H[i],        imanage.buff[i]);
    function.activation[i].df(imanage.derivedH[i], imanage.buff[i]);
}

TRIXY_NEURO_NETWORK_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::innerBackPropagation(
    const Vector<Precision, Args...>& sample,
    const Vector<Precision, Args...>& target) const noexcept
{
    size_type i;
    size_type j;

    i = N - 1;
    function.loss.df(imanage.buff[i], target, imanage.H[i]);

    for(j = i - 1; i > 0; --i, --j)
    {
        imanage.derivedB[i].multiply(imanage.buff[i], imanage.derivedH[i]);
        linear.tensordot(imanage.derivedW[i], imanage.H[j], imanage.derivedB[i]);
        linear.dottranspose(imanage. buff[j], imanage.derivedB[i], W[i]);
    }

    imanage.derivedB[0].multiply(imanage.buff[0], imanage.derivedH[0]);
    linear.tensordot(imanage.derivedW[0], sample, imanage.derivedB[0]);
}

TRIXY_NEURO_NETWORK_TPL_DECLARATION
long double TRIXY_FEED_FORWARD_NEURO_TPL::accuracy(
    const Container<Vector<Precision, Args...>>& idata,
    const Container<Vector<Precision, Args...>>& odata) const noexcept
{
    size_type count = 0;

    for(size_type i = 0; i < odata.size(); ++i)
        if(check(odata[i], feedforward(idata[i])))
            ++count;

    return static_cast<long double>(count) / odata.size();
}

TRIXY_NEURO_NETWORK_TPL_DECLARATION
long double TRIXY_FEED_FORWARD_NEURO_TPL::accuracyf(
    const Container<Vector<Precision, Args...>>& idata,
    const Container<Vector<Precision, Args...>>& odata,
    Precision range_rate) const noexcept
{
    size_type count = 0;

    for(size_type i = 0; i < odata.size(); ++i)
        if(checkf(odata[i], feedforward(idata[i]), range_rate))
            ++count;

    return static_cast<long double>(count) / odata.size();
}

TRIXY_NEURO_NETWORK_TPL_DECLARATION
long double TRIXY_FEED_FORWARD_NEURO_TPL::accuracyg(
    const Container<Vector<Precision, Args...>>& idata,
    const Container<Vector<Precision, Args...>>& odata,
    Precision range_rate) const noexcept
{
    size_type count = 0;

    for(size_type i = 0; i < odata.size(); ++i)
        checkg(odata[i], feedforward(idata[i]), range_rate, count);

    return static_cast<long double>(count) / (odata.size() * odata[0].size());
}

TRIXY_NEURO_NETWORK_TPL_DECLARATION
long double TRIXY_FEED_FORWARD_NEURO_TPL::loss(
    const Container<Vector<Precision, Args...>>& idata,
    const Container<Vector<Precision, Args...>>& odata) const noexcept
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

TRIXY_NEURO_NETWORK_TPL_DECLARATION
bool TRIXY_FEED_FORWARD_NEURO_TPL::check(
    const Vector<Precision, Args...>& target,
    const Vector<Precision, Args...>& prediction) const noexcept
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

TRIXY_NEURO_NETWORK_TPL_DECLARATION
bool TRIXY_FEED_FORWARD_NEURO_TPL::checkf(
    const Vector<Precision, Args...>& target,
    const Vector<Precision, Args...>& prediction,
    Precision range_rate) const noexcept
{
    for(size_type j = 0; j < target.size(); ++j)
        if(std::fabs(target(j) - prediction(j)) > range_rate)
            return false;

    return true;
}

TRIXY_NEURO_NETWORK_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::checkg(
    const Vector<Precision, Args...>& target,
    const Vector<Precision, Args...>& prediction,
    Precision range_rate,
    std::size_t& count) const noexcept
{
    for(size_type i = 0; i < target.size(); ++i)
        if(std::fabs(target(i) - prediction(i)) < range_rate)
            ++count;
}

} // namespace trixy

#include "Trixy/Neuro/Detail/macro_unscope.hpp"

#endif // FEEDFORWARD_NEURO_HPP
