#ifndef FFNN_HPP
#define FFNN_HPP

#include <cstddef> // size_t
#include <cstdint> // uint8_t
#include <cmath> // fabs

namespace trixy
{

template <template <typename, typename...> class Vector,
          template <typename, typename...> class Matrix,
          template <template <typename, typename...> class V,
                    template <typename, typename...> class M,
                    typename P, typename...>
          class Linear,
          template <typename Type> class Container,
          typename Precision,
          typename... Args>
class FeedForwardNeuro;

namespace function
{

template <template <typename P, typename...> class Vector,
          typename Precision,
          typename... Args>
struct Activation;

template <template <typename P, typename...> class Vector,
          typename Precision,
          typename... Args>
struct Loss;

template <template <typename P, typename...> class Vector,
          template <typename P, typename...> class Matrix,
          typename Precision,
          typename... Args>
struct Optimization;

} // namespace function

} // namespace trixy

#define TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION                   \
    template <template <typename, typename...> class Vector,       \
              template <typename, typename...> class Matrix,       \
              template <template <typename, typename...> class T1, \
                        template <typename, typename...> class T2, \
                        typename P, typename...>                   \
              class Linear,                                        \
              template <typename Type> class Container,            \
              typename Precision,                                  \
              typename... Args>

#define TRIXY_FEED_FORWARD_NEURO_TPL                               \
    FeedForwardNeuro<Vector, Matrix, Linear, Container,            \
                     Precision, Args...>

namespace trixy
{

namespace function
{

template <template <typename P, typename...> class Vector,
          typename Precision, typename... Args>
struct Activation
{
public:
    using Tensor    = Vector<Precision, Args...>;
    using byte_type = std::uint8_t;

    using Function        = void (*)(Tensor&, const Tensor&);
    using FunctionDerived = void (*)(Tensor&, const Tensor&);

public:
    Function f;             ///< void (*f)(Tensor& buff, const Tensor& tensor)
    FunctionDerived df;     ///< void (*df)(Tensor& buff, const Tensor& tensor)

    byte_type id;

public:
    Activation() noexcept : id(0), f(nullptr), df(nullptr) {}

    Activation(Function function,
               FunctionDerived function_derived,
               byte_type function_id = 0) noexcept
    : f(function)
    , df(function_derived)
    , id(function_id) {}
};

template <template <typename P, typename...> class Vector,
          typename Precision, typename... Args>
struct Loss
{
public:
    using Tensor    = Vector<Precision, Args...>;
    using byte_type = std::uint8_t;

    using Function        = void (*)(Precision&, const Tensor&, const Tensor&);
    using FunctionDerived = void (*)(Tensor&, const Tensor&, const Tensor&);

public:
    Function f;             ///< void (*)(Precision& result, const Tensor& target, const Tensor& prediction)
    FunctionDerived df;     ///< void (*)(Tensor& buff, const Tensor& target, const Tensor& prediction)

    byte_type id;

public:
    Loss() noexcept : id(0), f(nullptr), df(nullptr) {}

    Loss(Function function,
         FunctionDerived function_derived,
         byte_type function_id = 0) noexcept
    : id(function_id)
    , f(function)
    , df(function_derived) {}
};

template <template <typename P, typename...> class Vector,
          template <typename P, typename...> class Matrix,
          typename Precision, typename... Args>
struct Optimization
{
private:
    using Tensor1D  = Vector<Precision, Args...>;
    using Tensor2D  = Matrix<Precision, Args...>;

    using byte_type = std::uint8_t;

public:
    using Function1D = void (*)(Tensor1D&, Tensor1D&, const Tensor1D&);
    using Function2D = void (*)(Tensor2D&, Tensor2D&, const Tensor2D&);

public:
    Function1D f1D;     ///< void (*)(Tensor1D& buff, Tensor1D& otensor, const Tensor1D& tensor)
    Function2D f2D;     ///< void (*)(Tensor1D& buff, Tensor1D& otensor, const Tensor1D& tensor)

    byte_type id;

public:
    Optimization() noexcept : id(0), f1D(nullptr), f2D(nullptr) {}

    Optimization(Function1D tensor1d_optimizer,
                 Function2D tensor2d_optimizer,
                 byte_type function_id = 0) noexcept
    : f1D(tensor1d_optimizer)
    , f2D(tensor2d_optimizer)
    , id(function_id) {}
};

} // namespace function

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
class FeedForwardNeuro
{
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

    using ActivationFunction   = function::Activation<Vector, Precision, Args...>;
    using OptimizationFunction = function::Optimization<Vector, Matrix, Precision, Args...>;
    using LossFunction         = function::Loss<Vector, Precision, Args...>;

private:
    Container<size_type> topology;  ///< Network topology
    size_type N;                    ///< Number of functional layer (same as topology_size - 1)

    mutable InnerBuffer ib;         ///< in - inner buffer (class for temporary hold storage)
    Container<Tensor1D>  B;         ///< Container of network bias
    Container<Tensor2D>  W;         ///< Container of network weight

public:
    InnerFunctional function;       ///< Functional object for set & get each inner network function

private:
    TensorOperation li;             ///< li - linear (class for linear calculate)

public:
    FeedForwardNeuro(const Container<size_type>& neural_network_topology);

    const Tensor1D& feedforward(const Tensor1D& sample) const noexcept;

    template <typename GeneratorInteger = int (*)()>
    void trainStochastic(const Container<Tensor1D>& idata,
                         const Container<Tensor1D>& odata,
                         Precision learn_rate,
                         size_type epoch_scale,
                         GeneratorInteger generator) noexcept;

    void trainBatch(const Container<Tensor1D>& idata,
                    const Container<Tensor1D>& odata,
                    Precision learn_rate,
                    size_type epoch_scale) noexcept;

    template <typename GeneratorInteger = int (*)()>
    void trainMiniBatch(const Container<Tensor1D>& idata,
                        const Container<Tensor1D>& odata,
                        Precision learn_rate,
                        size_type epoch_scale,
                        size_type mini_batch_size,
                        GeneratorInteger generator) noexcept;

    template <typename GeneratorInteger = int (*)()>
    void trainOptimize(const Container<Tensor1D>& idata,
                       const Container<Tensor1D>& odata,
                       Precision learn_rate,
                       size_type epoch_scale,
                       size_type mini_batch_size,
                       GeneratorInteger generator) noexcept;

    double accuracy(const Container<Tensor1D>& idata,
                    const Container<Tensor1D>& odata) const noexcept;

    double accuracyf(const Container<Tensor1D>& idata,
                     const Container<Tensor1D>& odata,
                     Precision range_rate) const noexcept;

    double accuracyg(const Container<Tensor1D>& idata,
                     const Container<Tensor1D>& odata,
                     Precision range_rate) const noexcept;

    double loss(const Container<Tensor1D>& idata,
                const Container<Tensor1D>& odata) const noexcept;

private:
    void innerFeedForward(const Tensor1D& sample) const noexcept;

    void innerBackPropagation(const Tensor1D& sample,
                              const Tensor1D& target) const noexcept;

    void innerUpdateNormalize(const Container<Tensor1D>& deltaB,
                              const Container<Tensor2D>& deltaW,
                              Container<Tensor1D>& optimizedB,
                              Container<Tensor2D>& optimizedW,
                              Precision learn_rate) noexcept;

    void innerUpdate(Container<Tensor1D>& deltaB,
                     Container<Tensor2D>& deltaW,
                     Precision learn_rate) noexcept;

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
    template <typename GeneratorPrecision = Precision (*)()>
    void initializeInnerStruct(GeneratorPrecision generator_all) noexcept;

    template <typename GeneratorPrecision = Precision (*)()>
    void initializeInnerStruct(GeneratorPrecision generator_bias,
                               GeneratorPrecision generator_weight) noexcept;

    void initializeInnerStruct(const Container<Tensor1D>& bias,
                               const Container<Tensor2D>& weight) noexcept;

    const Container<Tensor1D>& getInnerBias() const noexcept;
    const Container<Tensor2D>& getInnerWeight() const noexcept;
    const Container<size_type>& getTopology() const noexcept;
};

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
class TRIXY_FEED_FORWARD_NEURO_TPL::InnerBuffer
{
friend class TRIXY_FEED_FORWARD_NEURO_TPL;

public:
    using size_type = std::size_t;

private:
    size_type size_;

    Container<Tensor1D> H;              ///< hidden layer storage
    Container<Tensor1D> derivedH;       ///< derived hidden layer storage

    Container<Tensor1D> derivedB;       ///< derived bias storage
    Container<Tensor2D> derivedW;       ///< derived weight storage

    Container<Tensor1D> deltaB;         ///< delta bias storage
    Container<Tensor2D> deltaW;         ///< delta weight storage

    Container<Tensor1D> optimizedB;     ///< optimize bias storage
    Container<Tensor2D> optimizedW;     ///< optimize weight storage

    Container<Tensor1D> buff;           ///< 1D buffer for handle
    Container<Tensor2D> buff2;          ///< 2D buffer for handle

public:
    explicit InnerBuffer(size_type size);

    void startDefault(const Container<size_type>& topology);
    void startDelta(const Container<size_type>& topology);
    void startOptimizer(const Container<size_type>& topology);
    void startBuffer(const Container<size_type>& topology);

    void resetDelta() noexcept;
    void resetOptimizer() noexcept;

    void updateDelta() noexcept;
    void normalizeDelta(Precision alpha) noexcept;
};

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
class TRIXY_FEED_FORWARD_NEURO_TPL::InnerFunctional
{
friend class TRIXY_FEED_FORWARD_NEURO_TPL;

private:
    ~InnerFunctional() = default;

private:
    Container<ActivationFunction> activation;
    LossFunction loss;
    OptimizationFunction optimization;

public:
    explicit InnerFunctional(size_type N) : activation(N), loss(), optimization() {}
    InnerFunctional& operator= (const InnerFunctional&) = delete;

    void setActivation(const ActivationFunction&);
    void setEachActivation(const Container<ActivationFunction>&); // maybe unused
    void setNormalization(const ActivationFunction&);

    void setLoss(const LossFunction&);
    void setOptimization(const OptimizationFunction&);

    const ActivationFunction& getActivation() const noexcept;
    const Container<ActivationFunction>& getEachActivation() const noexcept; // maybe unused
    const ActivationFunction& getNormalization() const noexcept;

    const LossFunction& getLoss() const noexcept;
    const OptimizationFunction& getOptimization() const noexcept;
};

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::InnerFunctional::setActivation(
    const function::Activation<Vector, Precision, Args...>& f)
{
    for(size_type i = 0; i < activation.size() - 1; ++i)
        activation[i] = f;
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::InnerFunctional::setEachActivation(
    const Container<function::Activation<Vector, Precision, Args...>>& fs)
{
    for(size_type i = 0; i < activation.size(); ++i)
        activation[i] = fs[i];
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::InnerFunctional::setNormalization(
    const function::Activation<Vector, Precision, Args...>& f)
{
    activation[activation.size() - 1] = f;
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::InnerFunctional::setLoss(
    const function::Loss<Vector, Precision, Args...>& f)
{
    loss = f;
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::InnerFunctional::setOptimization(
    const function::Optimization<Vector, Matrix, Precision, Args...>& f)
{
    optimization = f;
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
inline const function::Activation<Vector, Precision, Args...>&
    TRIXY_FEED_FORWARD_NEURO_TPL::InnerFunctional::getActivation() const noexcept
{
    return activation[0];
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
inline const Container<function::Activation<Vector, Precision, Args...>>&
    TRIXY_FEED_FORWARD_NEURO_TPL::InnerFunctional::getEachActivation() const noexcept
{
    return activation;
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
inline const function::Activation<Vector, Precision, Args...>&
    TRIXY_FEED_FORWARD_NEURO_TPL::InnerFunctional::getNormalization() const noexcept
{
    return activation[activation.size() - 1];
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
inline const function::Loss<Vector, Precision, Args...>&
    TRIXY_FEED_FORWARD_NEURO_TPL::InnerFunctional::getLoss() const noexcept
{
    return loss;
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
inline const function::Optimization<Vector, Matrix, Precision, Args...>&
    TRIXY_FEED_FORWARD_NEURO_TPL::InnerFunctional::getOptimization() const noexcept
{
    return optimization;
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
TRIXY_FEED_FORWARD_NEURO_TPL::InnerBuffer::InnerBuffer(size_type size)
    : size_(size)
    , H(size),          derivedH(size)
    , derivedB(size),   derivedW(size)
    , deltaB(size),     deltaW(size)
    , optimizedB(size), optimizedW(size)
    , buff(size),       buff2(size)
{
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::InnerBuffer::startDefault(
    const Container<std::size_t>& topology)
{
    for(size_type i = 0; i < size_; ++i)
    {
        H[i].resize(topology[i + 1]);
        derivedH[i].resize(topology[i + 1]);
        derivedB[i].resize(topology[i + 1]);
        derivedW[i].resize(topology[i], topology[i + 1]);
    }
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::InnerBuffer::startDelta(
    const Container<std::size_t>& topology)
{
    for(size_type i = 0; i < size_; ++i)
    {
        deltaB[i].resize(topology[i + 1]);
        deltaW[i].resize(topology[i], topology[i + 1]);
    }
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::InnerBuffer::startOptimizer(
    const Container<std::size_t>& topology)
{
    for(size_type i = 0; i < size_; ++i)
    {
        optimizedB[i].resize(topology[i + 1]);
        optimizedW[i].resize(topology[i], topology[i + 1]);
    }
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::InnerBuffer::startBuffer(
    const Container<std::size_t>& topology)
{
    for(size_type i = 0; i < size_; ++i)
    {
        buff [i].resize(topology[i + 1]);
        buff2[i].resize(topology[i], topology[i + 1]);
    }
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::InnerBuffer::resetDelta() noexcept
{
    for(size_type i = 0; i < size_; ++i)
    {
        deltaB[i].fill(0.0);
        deltaW[i].fill(0.0);
    }
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::InnerBuffer::resetOptimizer() noexcept
{
    for(size_type i = 0; i < size_; ++i)
    {
        optimizedB[i].fill(0.0);
        optimizedW[i].fill(0.0);
    }
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::InnerBuffer::updateDelta() noexcept
{
    for(size_type i = 0; i < size_; ++i)
    {
        deltaB[i].add(derivedB[i]);
        deltaW[i].add(derivedW[i]);
    }
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::InnerBuffer::normalizeDelta(Precision alpha) noexcept
{
    for(size_type i = 0; i < size_; ++i)
    {
        deltaB[i].join(alpha);
        deltaW[i].join(alpha);
    }
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
TRIXY_FEED_FORWARD_NEURO_TPL::FeedForwardNeuro(
    const Container<std::size_t>& neural_network_topology)
    : topology(neural_network_topology)
    , N(neural_network_topology.size() - 1)
    , ib(neural_network_topology.size() - 1)
    , B(neural_network_topology.size() - 1)
    , W(neural_network_topology.size() - 1)
    , function(neural_network_topology.size() - 1)
    , li()
{
    for(size_type i = 0; i < N; ++i)
    {
        B[i].resize(topology[i + 1]);
        W[i].resize(topology[i], topology[i + 1]);
    }

    ib.startDefault(topology);
    ib.startDelta(topology);
    ib.startOptimizer(topology);
    ib.startBuffer(topology);
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
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

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
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

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
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

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
inline const Container<Vector<Precision, Args...>>&
    TRIXY_FEED_FORWARD_NEURO_TPL::getInnerBias() const noexcept
{
    return B;
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
inline const Container<Matrix<Precision, Args...>>&
    TRIXY_FEED_FORWARD_NEURO_TPL::getInnerWeight() const noexcept
{
    return W;
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
inline const Container<std::size_t>& TRIXY_FEED_FORWARD_NEURO_TPL::getTopology() const noexcept
{
    return topology;
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
const Vector<Precision, Args...>& TRIXY_FEED_FORWARD_NEURO_TPL::feedforward(
    const Vector<Precision, Args...>& sample) const noexcept
{
    li.dot(ib.buff[0], sample, W[0]);
    function.activation[0].f(ib.buff[0], ib.buff[0].add(B[0]));

    for(size_type i = 1; i < N; ++i)
    {
        li.dot(ib.buff[i], ib.buff[i - 1], W[i]);
        function.activation[i].f(ib.buff[i], ib.buff[i].add(B[i]));
    }

    return ib.buff[N - 1];
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
template <typename GeneratorInteger>
void TRIXY_FEED_FORWARD_NEURO_TPL::trainStochastic(
    const Container<Vector<Precision, Args...>>& idata,
    const Container<Vector<Precision, Args...>>& odata,
    Precision learn_rate,
    std::size_t epoch_scale,
    GeneratorInteger generator) noexcept
{
    for(size_type epoch = 0, sample; epoch < epoch_scale; ++epoch)
    {
        sample = generator() % idata.size();

        innerFeedForward(idata[sample]);
        innerBackPropagation(idata[sample], odata[sample]);
        innerUpdate(ib.derivedB, ib.derivedW, learn_rate);
    }
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::trainBatch(
    const Container<Vector<Precision, Args...>>& idata,
    const Container<Vector<Precision, Args...>>& odata,
    Precision learn_rate,
    std::size_t epoch_scale) noexcept
{
    learn_rate /= idata.size();

    for(size_type epoch = 0; epoch < epoch_scale; ++epoch)
    {
        ib.resetDelta();

        for(size_type sample = 0; sample < idata.size(); ++sample)
        {
            innerFeedForward(idata[sample]);
            innerBackPropagation(idata[sample], odata[sample]);
            ib.updateDelta();
        }

        innerUpdate(ib.deltaB, ib.deltaW, learn_rate);
    }
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
template <typename GeneratorInteger>
void TRIXY_FEED_FORWARD_NEURO_TPL::trainMiniBatch(
    const Container<Vector<Precision, Args...>>& idata,
    const Container<Vector<Precision, Args...>>& odata,
    Precision learn_rate,
    std::size_t epoch_scale,
    std::size_t mini_batch_size,
    GeneratorInteger generator) noexcept
{
    size_type batch_part;
    size_type sample_beg;
    size_type sample_end;

    learn_rate /= mini_batch_size;

    for(size_type epoch = 0; epoch < epoch_scale; ++epoch)
    {
        batch_part = generator() % (idata.size() / mini_batch_size);
        sample_beg = batch_part * mini_batch_size;
        sample_end = sample_beg + mini_batch_size;

        ib.resetDelta();

        while(sample_beg < sample_end)
        {
            innerFeedForward(idata[sample_beg]);
            innerBackPropagation(idata[sample_beg], odata[sample_beg]);
            ib.updateDelta();

            ++sample_beg;
        }

        innerUpdate(ib.deltaB, ib.deltaW, learn_rate);
    }
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
template <typename GeneratorInteger>
void TRIXY_FEED_FORWARD_NEURO_TPL::trainOptimize(
    const Container<Vector<Precision, Args...>>& idata,
    const Container<Vector<Precision, Args...>>& odata,
    Precision learn_rate,
    std::size_t epoch_scale,
    std::size_t mini_batch_size,
    GeneratorInteger generator) noexcept
{
    size_type batch_part;
    size_type sample_beg;
    size_type sample_end;

    ib.resetOptimizer();

    const Precision alpha = 1.0 / static_cast<double>(mini_batch_size);

    for(size_type epoch = 0; epoch < epoch_scale; ++epoch)
    {
        batch_part = generator() % (idata.size() / mini_batch_size);
        sample_beg = batch_part * mini_batch_size;
        sample_end = sample_beg + mini_batch_size;

        ib.resetDelta();

        while(sample_beg < sample_end)
        {
            innerFeedForward(idata[sample_beg]);
            innerBackPropagation(idata[sample_beg], odata[sample_beg]);
            ib.updateDelta();

            ++sample_beg;
        }

        ib.normalizeDelta(alpha);
        innerUpdateNormalize(ib.deltaB, ib.deltaW,
                             ib.optimizedB, ib.optimizedW, learn_rate);
    }
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
double TRIXY_FEED_FORWARD_NEURO_TPL::accuracy(
    const Container<Vector<Precision, Args...>>& idata,
    const Container<Vector<Precision, Args...>>& odata) const noexcept
{
    size_type count = 0;

    for(size_type i = 0; i < odata.size(); ++i)
        if(check(odata[i], feedforward(idata[i])))
            ++count;

    return static_cast<double>(count) / odata.size();
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
double TRIXY_FEED_FORWARD_NEURO_TPL::accuracyf(
    const Container<Vector<Precision, Args...>>& idata,
    const Container<Vector<Precision, Args...>>& odata,
    Precision range_rate) const noexcept
{
    size_type count = 0;

    for(size_type i = 0; i < odata.size(); ++i)
        if(checkf(odata[i], feedforward(idata[i]), range_rate))
            ++count;

    return static_cast<double>(count) / odata.size();
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
double TRIXY_FEED_FORWARD_NEURO_TPL::accuracyg(
    const Container<Vector<Precision, Args...>>& idata,
    const Container<Vector<Precision, Args...>>& odata,
    Precision range_rate) const noexcept
{
    size_type count = 0;

    for(size_type i = 0; i < odata.size(); ++i)
        checkg(odata[i], feedforward(idata[i]), range_rate, count);

    return static_cast<double>(count) / (odata.size() * odata[0].size());
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
double TRIXY_FEED_FORWARD_NEURO_TPL::loss(
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

    return result / static_cast<double>(odata.size());
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::innerFeedForward(
    const Vector<Precision, Args...>& sample) const noexcept
{
    size_type i;
    size_type j;

    li.dot(ib.buff[0], sample, W[0]);
    ib.buff[0].add(B[0]);

    for(i = 0, j = 1; j < N; ++i, ++j)
    {
        function.activation[i]. f(ib.H[i],        ib.buff[i]);
        function.activation[i].df(ib.derivedH[i], ib.buff[i]);

        li.dot(ib.buff[j], ib.H[i], W[j]);
        ib.buff[j].add(B[j]);
    }

    function.activation[i]. f(ib.H[i],        ib.buff[i]);
    function.activation[i].df(ib.derivedH[i], ib.buff[i]);
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::innerBackPropagation(
    const Vector<Precision, Args...>& sample,
    const Vector<Precision, Args...>& target) const noexcept
{
    size_type i;
    size_type j;

    i = N - 1;
    function.loss.df(ib.buff[i], target, ib.H[i]);

    for(j = i - 1; i > 0; --i, --j)
    {
        ib. derivedB[i].multiply(ib. buff[i], ib.derivedH[i]);
        li.tensordot(ib.derivedW[i], ib.H[j], ib.derivedB[i]);
        li. dottranspose(ib.buff[j], ib.derivedB[i], W[i]);
    }

    ib. derivedB[0].multiply(ib.buff[0], ib.derivedH[0]);
    li.tensordot(ib.derivedW[0], sample, ib.derivedB[0]);
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::innerUpdate(
    Container<Vector<Precision, Args...>>& deltaB,
    Container<Matrix<Precision, Args...>>& deltaW,
    Precision learn_rate) noexcept
{
    for(size_type i = 0; i < N; ++i)
    {
        B[i].sub(deltaB[i].join(learn_rate));
        W[i].sub(deltaW[i].join(learn_rate));
    }
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::innerUpdateNormalize(
    const Container<Vector<Precision, Args...>>& deltaB,
    const Container<Matrix<Precision, Args...>>& deltaW,
    Container<Vector<Precision, Args...>>& optimizedB,
    Container<Matrix<Precision, Args...>>& optimizedW,
    Precision learn_rate) noexcept
{
    for(size_type i = 0; i < N; ++i)
    {
        function.optimization.f1D(ib.buff [i], optimizedB[i], deltaB[i]);
        function.optimization.f2D(ib.buff2[i], optimizedW[i], deltaW[i]);

        B[i].sub(ib.buff [i].join(learn_rate));
        W[i].sub(ib.buff2[i].join(learn_rate));
    }
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
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

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
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

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
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

// clean up
#undef TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
#undef TRIXY_FEED_FORWARD_NEURO_TPL

#endif // FFNN_HPP
