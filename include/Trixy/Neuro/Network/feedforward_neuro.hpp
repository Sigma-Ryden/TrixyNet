#ifndef FFNN_HPP
#define FFNN_HPP

#include <cstddef> // size_t
#include <cstdint> // uint8_t
#include <cmath> // fabs

namespace trixy
{

template <template <typename T, typename...> class Vector,
          template <typename T, typename...> class Matrix,
          template <class V, class M> class Linear,
          template <typename...> class Container,
          typename Precision,
          typename... Args>
class FeedForwardNeuro;

namespace function
{

template <template <typename T, typename...> class Vector,
          typename Precision,
          typename... Args>
struct Activation;

template <template <typename T, typename...> class Vector,
          typename Precision,
          typename... Args>
struct Loss;

template <template <typename T, typename...> class Vector,
          template <typename T, typename...> class Matrix,
          typename Precision,
          typename... Args>
struct Optimization;

} // namespace function

} // namespace trixy

#define TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION               \
    template <template <typename T, typename...> class Vector, \
              template <typename T, typename...> class Matrix, \
              template <class V, class M> class Linear,        \
              template <typename...> class Container,          \
              typename Precision,                              \
              typename... Args>

#define TRIXY_FEED_FORWARD_NEURO_TPL                           \
    FeedForwardNeuro<Vector, Matrix, Linear, Container,        \
                     Precision, Args...>

#define TRIXY_FUNCTION_ACTIVATION_TPL_DECLARATION              \
    template <template <typename T, typename...> class Vector, \
        typename Precision,                                    \
        typename... Args>

#define TRIXY_FUNCTION_LOSS_TPL_DECLARATION                    \
    template <template <typename T, typename...> class Vector, \
              typename Precision,                              \
              typename... Args>

#define TRIXY_FUNCTION_OPTIMIZATION_TPL_DECLARATION            \
    template <template <typename T, typename...> class Vector, \
              template <typename T, typename...> class Matrix, \
              typename Precision,                              \
              typename... Args>

namespace trixy
{

namespace function
{

TRIXY_FUNCTION_ACTIVATION_TPL_DECLARATION
struct Activation
{
private:
    using Tensor1D  = Vector<Precision, Args...>;
    using byte_type = std::uint8_t;

public:
    byte_type id;

    void (*f)(Tensor1D&, const Tensor1D&);
    void (*df)(Tensor1D&, const Tensor1D&);

public:
    Activation() noexcept : id(0), f(nullptr), df(nullptr) {}

    Activation(
        byte_type function_id,
        void (*function)(Tensor1D&, const Tensor1D&),
        void (*function_derived)(Tensor1D&, const Tensor1D&)) noexcept
            : id(function_id), f(function), df(function_derived) {}
};

TRIXY_FUNCTION_LOSS_TPL_DECLARATION
struct Loss
{
private:
    using Tensor1D  = Vector<Precision, Args...>;
    using byte_type = std::uint8_t;

public:
    byte_type id;

    Precision (*f)(const Tensor1D&, const Tensor1D&);
    void (*df)(Tensor1D&, const Tensor1D&, const Tensor1D&);

public:
    Loss() noexcept : id(0), f(nullptr), df(nullptr) {}

    Loss(
        byte_type function_id,
        Precision (*function)(const Tensor1D&, const Tensor1D&),
        void (*function_derived)(Tensor1D&, const Tensor1D&, const Tensor1D&)) noexcept
            : id(function_id), f(function), df(function_derived) {}
};

TRIXY_FUNCTION_OPTIMIZATION_TPL_DECLARATION
struct Optimization
{
private:
    using Tensor1D  = Vector<Precision, Args...>;
    using Tensor2D  = Matrix<Precision, Args...>;

    using byte_type = std::uint8_t;

public:
    byte_type id;

    void (*f1D)(Tensor1D&, Tensor1D&, const Tensor1D&);
    void (*f2D)(Tensor2D&, Tensor2D&, const Tensor2D&);

public:
    Optimization() noexcept : id(0), f1D(nullptr), f2D(nullptr) {}

    Optimization(
        byte_type function_id,
        void (*vector_optimizer)(Tensor1D&, Tensor1D&, const Tensor1D&),
        void (*matrix_optimizer)(Tensor2D&, Tensor2D&, const Tensor2D&)) noexcept
            : id(function_id), f1D(vector_optimizer), f2D(matrix_optimizer) {}
};

} // namespace function

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
class FeedForwardNeuro
{
private:
    class InnerBuffer;
    class InnerFunctional;

public:
    template <typename... T> using ContainerType = Container<T...>;

    using precision_type = Precision;
    using size_type      = std::size_t;
    using byte_type      = std::uint8_t;

    using ActivationFunction   = function::Activation<Vector, Precision, Args...>;
    using LossFunction         = function::Loss<Vector, Precision, Args...>;
    using OptimizationFunction = function::Optimization<Vector, Matrix, Precision, Args...>;

    using Tensor1D = Vector<Precision, Args...>;
    using Tensor2D = Matrix<Precision, Args...>;

    using GeneratorInteger   = int (*)();
    using GeneratorPrecision = Precision (*)();

private:
    Container<size_type> T;         ///< Network topology
    size_type N;                    ///< Number of functional layer (same as topology_size - 1)

    mutable InnerBuffer ib;         ///< in - inner buffer (class for temporary hold storage)
    Container<Tensor1D>  B;         ///< Container of network bias
    Container<Tensor2D>  W;         ///< Container of network weight

public:
    InnerFunctional function;       ///< Functional object for set & get each inner network function

private:
    Linear<Tensor1D, Tensor2D> li;  ///< li - linear (class for linear calculate)

public:
    FeedForwardNeuro(const Container<size_type>& topology);

    const Tensor1D& feedforward(const Tensor1D& sample) const noexcept;

    void trainStochastic(const Container<Tensor1D>& idata,
                         const Container<Tensor1D>& odata,
                         Precision learn_rate,
                         size_type epoch_scale,
                         GeneratorInteger generator) noexcept;

    void trainBatch(const Container<Tensor1D>& idata,
                    const Container<Tensor1D>& odata,
                    Precision learn_rate,
                    size_type epoch_scale) noexcept;

    void trainMiniBatch(const Container<Tensor1D>& idata,
                        const Container<Tensor1D>& odata,
                        Precision learn_rate,
                        size_type epoch_scale,
                        size_type mini_batch_size,
                        GeneratorInteger generator) noexcept;

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
                              Container<Tensor1D>& OB,
                              Container<Tensor2D>& OW,
                              Precision learn_rate) noexcept;

    void innerUpdate(Container<Tensor1D>& deltaB,
                     Container<Tensor2D>& deltaW,
                     Precision learn_rate) noexcept;

    bool check(const Tensor1D& y_true,
               const Tensor1D& y_pred) const noexcept;

    bool checkf(const Tensor1D& y_true,
                const Tensor1D& y_pred,
                Precision range_rate) const noexcept;

    void checkg(const Tensor1D& y_true,
                const Tensor1D& y_pred,
                Precision range_rate,
                size_type& count) const noexcept;

public:
    void initializeInnerStruct(GeneratorPrecision generator_all) noexcept;

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
public:
    using size_type = std::size_t;

private:
    size_type size_;

public:
    Container<Tensor1D> H;       ///<
    Container<Tensor1D> DH;      ///<

    Container<Tensor1D> DB;      ///<
    Container<Tensor2D> DW;      ///<

    Container<Tensor1D> deltaB;  ///<
    Container<Tensor2D> deltaW;  ///<

    Container<Tensor1D> OB;      ///<
    Container<Tensor2D> OW;      ///<

    Container<Tensor1D> buff;    ///< 1D buffer for handle
    Container<Tensor2D> buff2;   ///< 2D buffer for handle

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
    Container<ActivationFunction> A;
    LossFunction E;
    OptimizationFunction O;

public:
    explicit InnerFunctional(size_type N) : A(N), E(), O() {}
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
    for(size_type i = 0; i < A.size() - 1; ++i)
        A[i] = f;
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::InnerFunctional::setEachActivation(
    const Container<function::Activation<Vector, Precision, Args...>>& fs)
{
    for(size_type i = 0; i < A.size(); ++i)
        A[i] = fs[i];
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::InnerFunctional::setNormalization(
    const function::Activation<Vector, Precision, Args...>& f)
{
    A[A.size() - 1] = f;
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::InnerFunctional::setLoss(
    const function::Loss<Vector, Precision, Args...>& f)
{
    E = f;
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::InnerFunctional::setOptimization(
    const function::Optimization<Vector, Matrix, Precision, Args...>& f)
{
    O = f;
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
inline const function::Activation<Vector, Precision, Args...>&
    TRIXY_FEED_FORWARD_NEURO_TPL::InnerFunctional::getActivation() const noexcept
{
    return A[0];
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
inline const Container<function::Activation<Vector, Precision, Args...>>&
    TRIXY_FEED_FORWARD_NEURO_TPL::InnerFunctional::getEachActivation() const noexcept
{
    return A;
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
inline const function::Activation<Vector, Precision, Args...>&
    TRIXY_FEED_FORWARD_NEURO_TPL::InnerFunctional::getNormalization() const noexcept
{
    return A[A.size() - 1];
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
inline const function::Loss<Vector, Precision, Args...>&
    TRIXY_FEED_FORWARD_NEURO_TPL::InnerFunctional::getLoss() const noexcept
{
    return E;
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
inline const function::Optimization<Vector, Matrix, Precision, Args...>&
    TRIXY_FEED_FORWARD_NEURO_TPL::InnerFunctional::getOptimization() const noexcept
{
    return O;
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
TRIXY_FEED_FORWARD_NEURO_TPL::InnerBuffer::InnerBuffer(size_type size)
    : size_(size)
    , H(size),      DH(size)
    , DB(size),     DW(size)
    , deltaB(size), deltaW(size)
    , OB(size),     OW(size)
    , buff(size),   buff2(size)
{
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::InnerBuffer::startDefault(
    const Container<std::size_t>& topology)
{
    for(size_type i = 0; i < size_; ++i)
    {
        H [i].resize(topology[i + 1]);
        DH[i].resize(topology[i + 1]);
        DB[i].resize(topology[i + 1]);
        DW[i].resize(topology[i], topology[i + 1]);
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
        OB[i].resize(topology[i + 1]);
        OW[i].resize(topology[i], topology[i + 1]);
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
        OB[i].fill(0.0);
        OW[i].fill(0.0);
    }
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::InnerBuffer::updateDelta() noexcept
{
    for(size_type i = 0; i < size_; ++i)
    {
        deltaB[i].add(DB[i]);
        deltaW[i].add(DW[i]);
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
TRIXY_FEED_FORWARD_NEURO_TPL::FeedForwardNeuro(const Container<std::size_t>& topology)
    : T(topology)
    , N(topology.size() - 1)
    , ib(topology.size() - 1)
    , B(topology.size() - 1)
    , W(topology.size() - 1)
    , function(topology.size() - 1)
    , li()
{
    for(size_type i = 0; i < N; ++i)
    {
        B[i].resize(T[i + 1]);
        W[i].resize(T[i], T[i + 1]);
    }

    ib.startDefault(T);
    ib.startDelta(T);
    ib.startOptimizer(T);
    ib.startBuffer(T);
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::initializeInnerStruct(
    Precision (*generator_all)()) noexcept
{
    for(size_type i = 0; i < N; ++i)
    {
        B[i].fill(generator_all);
        W[i].fill(generator_all);
    }
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::initializeInnerStruct(
    Precision (*generator_bias)(),
    Precision (*generator_weight)()) noexcept
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
    return T;
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
const Vector<Precision, Args...>& TRIXY_FEED_FORWARD_NEURO_TPL::feedforward(
    const Vector<Precision, Args...>& sample) const noexcept
{
    li.         dot(ib.buff[0], sample, W[0]);
    function.A[0].f(ib.buff[0], ib.buff[0].add(B[0]));

    for(size_type i = 1; i < N; ++i)
    {
        li.         dot(ib.buff[i], ib.buff[i - 1], W[i]);
        function.A[i].f(ib.buff[i], ib.buff[i].add(B[i]));
    }

    return ib.buff[N - 1];
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::trainStochastic(
    const Container<Vector<Precision, Args...>>& idata,
    const Container<Vector<Precision, Args...>>& odata,
    Precision learn_rate,
    std::size_t epoch_scale,
    int (*generator)()) noexcept
{
    for(size_type epoch = 0, sample; epoch < epoch_scale; ++epoch)
    {
        sample = generator() % idata.size();

        innerFeedForward(idata[sample]);
        innerBackPropagation(idata[sample], odata[sample]);
        innerUpdate(ib.DB, ib.DW, learn_rate);
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
void TRIXY_FEED_FORWARD_NEURO_TPL::trainMiniBatch(
    const Container<Vector<Precision, Args...>>& idata,
    const Container<Vector<Precision, Args...>>& odata,
    Precision learn_rate,
    std::size_t epoch_scale,
    std::size_t mini_batch_size,
    int (*generator)()) noexcept
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
void TRIXY_FEED_FORWARD_NEURO_TPL::trainOptimize(
    const Container<Vector<Precision, Args...>>& idata,
    const Container<Vector<Precision, Args...>>& odata,
    Precision learn_rate,
    std::size_t epoch_scale,
    std::size_t mini_batch_size,
    int (*generator)()) noexcept
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
                             ib.OB, ib.OW, learn_rate);
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
    size_type result = 0;

    for(size_type i = 0; i < odata.size(); ++i)
        result += function.E.f(odata[i], feedforward(idata[i]));

    return static_cast<double>(result) / odata.size();
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
        function.A[i]. f(ib .H[i], ib.buff[i]);
        function.A[i].df(ib.DH[i], ib.buff[i]);

        li.dot(ib.buff[j], ib.H[i], W[j]);
        ib.buff[j].add(B[j]);
    }

    function.A[i]. f(ib. H[i], ib.buff[i]);
    function.A[i].df(ib.DH[i], ib.buff[i]);
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::innerBackPropagation(
    const Vector<Precision, Args...>& sample,
    const Vector<Precision, Args...>& target) const noexcept
{
    size_type i;
    size_type j;

    i = N - 1;
    function.E.df(ib.buff[i], target, ib.H[i]);

    for(j = i - 1; i > 0; --i, --j)
    {
        ib.DB[i].multiply(ib.buff[i], ib.DH[i]);
        li.     tensordot(ib.  DW[i], ib. H[j], ib.DB[i]);
        li.  dottranspose(ib.buff[j], ib.DB[i], W[i]);
    }

    ib.DB[0].multiply(ib.buff[0], ib.DH[0]);
    li.     tensordot(ib.  DW[0], sample, ib.DB[0]);
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
    Container<Vector<Precision, Args...>>& OB,
    Container<Matrix<Precision, Args...>>& OW,
    Precision learn_rate) noexcept
{
    for(size_type i = 0; i < N; ++i)
    {
        function.O.f1D(ib.buff [i], OB[i], deltaB[i]);
        function.O.f2D(ib.buff2[i], OW[i], deltaW[i]);

        B[i].sub(ib.buff [i].join(learn_rate));
        W[i].sub(ib.buff2[i].join(learn_rate));
    }
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
bool TRIXY_FEED_FORWARD_NEURO_TPL::check(
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred) const noexcept
{
    size_type max_true_out;
    size_type max_pred_out;

    max_true_out = 0;
    max_pred_out = 0;

    for(size_type j = 1; j < y_true.size(); ++j)
        if(y_true(max_true_out) < y_true(j))
            max_true_out = j;

    for(size_type j = 1; j < y_true.size(); ++j)
        if(y_pred(max_pred_out) < y_pred(j))
            max_pred_out = j;

    return max_true_out == max_pred_out;
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
bool TRIXY_FEED_FORWARD_NEURO_TPL::checkf(
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred,
    Precision range_rate) const noexcept
{
    for(size_type j = 0; j < y_true.size(); ++j)
        if(std::fabs(y_true(j) - y_pred(j)) > range_rate)
            return false;

    return true;
}

TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_TPL::checkg(
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred,
    Precision range_rate,
    std::size_t& count) const noexcept
{
    for(size_type i = 0; i < y_true.size(); ++i)
        if(std::fabs(y_true(i) - y_pred(i)) < range_rate)
            ++count;
}

} // namespace trixy

// clean up
#undef TRIXY_FEED_FORWARD_NEURO_TPL_DECLARATION
#undef TRIXY_FEED_FORWARD_NEURO_TPL
#undef TRIXY_FUNCTION_ACTIVATION_TPL_DECLARATION
#undef TRIXY_FUNCTION_LOSS_TPL_DECLARATION
#undef TRIXY_FUNCTION_OPTIMIZATION_TPL_DECLARATION

#endif // FFNN_HPP
