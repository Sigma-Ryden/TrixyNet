#ifndef NEURO_CORE_HPP
#define NEURO_CORE_HPP

#include <cstddef> // size_t
#include <cmath> // fabs
#include <initializer_list> // initializer_list
#include <utility> // declval, move

namespace trixy
{

template <template <typename T, typename...> class Vector,
          template <typename T, typename...> class Matrix,
          template <class V, class M> class Linear,
          template <typename...> class Collection,
          typename Precision,
          typename... Args>
class Neuro;

namespace function
{

template <template <typename T, typename...> class Vector,
          typename Precision,
          typename... Args>
class Activation;

template <template <typename T, typename...> class Vector,
          typename Precision,
          typename... Args>
class Loss;

template <template <typename T, typename...> class Vector,
          template <typename T, typename...> class Matrix,
          typename Precision,
          typename... Args>
class Optimization;

} // namespace function

} // namespace trixy

#define TRIXY_NEURO_TPL_DECLARATION                            \
    template <template <typename T, typename...> class Vector, \
              template <typename T, typename...> class Matrix, \
              template <class V, class M> class Linear,        \
              template <typename...> class Collection,         \
              typename Precision,                              \
              typename... Args>

#define TRIXY_NEURO_TPL                                        \
    Neuro<Vector, Matrix, Linear,                              \
    Collection, Precision, Args...>

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
class Activation
{
private:
    using Tensor1D = Vector<Precision, Args...>;

public:
    Tensor1D& (*f)(Tensor1D&, const Tensor1D&);
    Tensor1D& (*df)(Tensor1D&, const Tensor1D&);

    explicit Activation(
        Tensor1D& (*function)(Tensor1D&, const Tensor1D&) = nullptr,
        Tensor1D& (*function_derived)(Tensor1D&, const Tensor1D&) = nullptr) noexcept
    : f(function), df(function_derived) {}
};

TRIXY_FUNCTION_LOSS_TPL_DECLARATION
class Loss
{
private:
    using Tensor1D = Vector<Precision, Args...>;

public:
    Precision (*f)(const Tensor1D&, const Tensor1D&);
    Tensor1D& (*df)(Tensor1D&, const Tensor1D&, const Tensor1D&);

    explicit Loss(
        Precision (*function)(const Tensor1D&, const Tensor1D&) = nullptr,
        Tensor1D& (*function_derived)(Tensor1D&, const Tensor1D&, const Tensor1D&) = nullptr) noexcept
    : f(function), df(function_derived) {}
};

TRIXY_FUNCTION_OPTIMIZATION_TPL_DECLARATION
class Optimization
{
private:
    using Tensor1D = Vector<Precision, Args...>;
    using Tensor2D = Matrix<Precision, Args...>;

public:
    Tensor1D& (*f1D)(Tensor1D&, Tensor1D&, const Tensor1D&);
    Tensor2D& (*f2D)(Tensor2D&, Tensor2D&, const Tensor2D&);

    explicit Optimization(
        Tensor1D& (*vector_optimizer)(Tensor1D&, Tensor1D&, const Tensor1D&) = nullptr,
        Tensor2D& (*matrix_optimizer)(Tensor2D&, Tensor2D&, const Tensor2D&) = nullptr) noexcept
    : f1D(vector_optimizer), f2D(matrix_optimizer) {}
};

} // namespace function

TRIXY_NEURO_TPL_DECLARATION
class Neuro
{
private:
    class InnerBuffer;

public:
    using Tensor1D = Vector<Precision, Args...>;
    using Tensor2D = Matrix<Precision, Args...>;

    using ActivationFunction   = function::Activation<Vector, Precision, Args...>;
    using LossFunction         = function::Loss<Vector, Precision, Args...>;
    using OptimizationFunction = function::Optimization<Vector, Matrix, Precision, Args...>;

    using size_type        = std::size_t;
    using GeneratorInteger = int (*)();
    using GeneratorFloat   = Precision (*)();

private:
    mutable InnerBuffer ib;

    Collection<Tensor1D> B;
    Collection<Tensor2D> W;
    size_type N;

    Collection<ActivationFunction> A;
    LossFunction E;
    OptimizationFunction O;

    Linear<Tensor1D, Tensor2D> li;

public:
    Neuro(const std::initializer_list<size_type>& topology);

    Neuro(const Neuro&)     = default;
    Neuro(Neuro&&) noexcept = default;
    ~Neuro()                = default;
    Neuro& operator= (const Neuro&)     = default;
    Neuro& operator= (Neuro&&) noexcept = default;

    void initializeInnerStruct(GeneratorFloat generator) noexcept;

    void initializeInnerStruct(GeneratorFloat generator_bias,
                               GeneratorFloat generator_weight) noexcept;

    void setActivationFunction(const ActivationFunction& activation_function) noexcept;
    void setNormalizationFunction(const ActivationFunction& normalization_function) noexcept;
    void setEachActivationFunction(const Collection<ActivationFunction>& activation_set) noexcept; // maybe unused

    void setLossFunction(const LossFunction& loss_function) noexcept;
    void setOptimizationFunction(const OptimizationFunction& optimization_function) noexcept;

    const Collection<Tensor1D>& getInnerBias() const noexcept;
    const Collection<Tensor2D>& getInnerWeight() const noexcept;

    const Collection<ActivationFunction>& getEachActivationFunction() const noexcept; // maybe unused
    const LossFunction& getLossFunction() const noexcept;

    const Tensor1D& feedforward(const Tensor1D&) const;
    Collection<Tensor1D> feedforward(const Collection<Tensor1D>&) const; // deprecated

    void trainStochastic(const Collection<Tensor1D>& idata,
                         const Collection<Tensor1D>& odata,
                         Precision learn_rate,
                         size_type epoch_scale,
                         GeneratorInteger generator);

    void trainBatch(const Collection<Tensor1D>& idata,
                    const Collection<Tensor1D>& odata,
                    Precision learn_rate,
                    size_type epoch_scale);

    void trainMiniBatch(const Collection<Tensor1D>& idata,
                        const Collection<Tensor1D>& odata,
                        Precision learn_rate,
                        size_type epoch_scale,
                        size_type mini_batch_size,
                        GeneratorInteger generator);

    void trainOptimize(const Collection<Tensor1D>& idata,
                       const Collection<Tensor1D>& odata,
                       Precision learn_rate,
                       size_type epoch_scale,
                       size_type mini_batch_size,
                       GeneratorInteger generator);

    double accuracy(const Collection<Tensor1D>& idata,
                    const Collection<Tensor1D>& odata) const;

    double accuracyFull(const Collection<Tensor1D>& idata,
                        const Collection<Tensor1D>& odata,
                        Precision range_rate) const;

    double accuracyGlobal(const Collection<Tensor1D>& idata,
                          const Collection<Tensor1D>& odata,
                          Precision range_rate) const;

    double loss(const Collection<Tensor1D>& idata,
                const Collection<Tensor1D>& odata) const;

private:
    void innerFeedForward(const Tensor1D& idata_sample) const;

    void innerBackPropagation(const Tensor1D& idata_sample,
                              const Tensor1D& odata_sample) const;

    void innerUpdateNormalize(Collection<Tensor1D>& deltaB,
                              Collection<Tensor2D>& detlaW,
                              Collection<Tensor1D>& OB,
                              Collection<Tensor2D>& OW,
                              Precision learn_rate);

    void innerUpdate(Collection<Tensor1D>& deltaB,
                     Collection<Tensor2D>& deltaW,
                     Precision learn_rate);

    bool check(const Tensor1D& y_true,
               const Tensor1D& y_pred) const;

    bool checkFull(const Tensor1D& y_true,
                   const Tensor1D& y_pred,
                   Precision range_rate) const;

    void checkGlobal(const Tensor1D& y_true,
                     const Tensor1D& y_pred,
                     Precision range_rate,
                     size_type& count) const;
};

TRIXY_NEURO_TPL_DECLARATION
class TRIXY_NEURO_TPL::InnerBuffer
{
public:
    using size_type = std::size_t;

private:
    size_type size_;

public:
    Collection<Tensor1D> B1;
    Collection<Tensor1D> H;
    Collection<Tensor1D> DH;
    Collection<Tensor1D> DB;
    Collection<Tensor2D> DW;

    Collection<Tensor1D> deltaB;
    Collection<Tensor2D> deltaW;

    Collection<Tensor1D> OB;
    Collection<Tensor2D> OW;
    Collection<Tensor2D> B2;

public:
    InnerBuffer(size_type);

    InnerBuffer(const InnerBuffer&)     = default;
    InnerBuffer(InnerBuffer&&) noexcept = default;
    ~InnerBuffer()                       = default;
    InnerBuffer& operator= (const InnerBuffer&)     = default;
    InnerBuffer& operator= (InnerBuffer&&) noexcept = default;

    void initializeDefault();
    void initializeDelta();
    void initializeOptimizer();

    void startDefault(const Collection<Tensor1D>& B,
                      const Collection<Tensor2D>& W);

    void startDelta(const Collection<Tensor1D>& B,
                    const Collection<Tensor2D>& W);

    void startOptimizer(const Collection<Tensor1D>& B,
                        const Collection<Tensor2D>& W);

    void resetDelta() noexcept;
    void resetOptimizer() noexcept;

    void updateDelta() noexcept;
    void normalizeDelta(Precision alpha) noexcept;
};

TRIXY_NEURO_TPL_DECLARATION
inline TRIXY_NEURO_TPL::InnerBuffer::InnerBuffer(std::size_t N)
    : size_(N)
{
}

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::InnerBuffer::initializeDefault()
{
    B1 = Collection<Tensor1D>(size_);
    H  = Collection<Tensor1D>(size_);
    DH = Collection<Tensor1D>(size_);
    DB = Collection<Tensor1D>(size_);
    DW = Collection<Tensor2D>(size_);
}

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::InnerBuffer::initializeDelta()
{
    deltaB = Collection<Tensor1D>(size_);
    deltaW = Collection<Tensor2D>(size_);
}

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::InnerBuffer::initializeOptimizer()
{
    OB = Collection<Tensor1D>(size_);
    OW = Collection<Tensor2D>(size_);
    B2 = Collection<Tensor2D>(size_);
}

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::InnerBuffer::startDefault(
    const Collection<Vector<Precision, Args...>>& B,
    const Collection<Matrix<Precision, Args...>>& W)
{
    H[0].resize(B[size_ - 1].size());
    for(size_type i = 1; i < size_; ++i)
        H[i].resize(B[i - 1].size());

    for(size_type i = 0; i < size_; ++i)
    {
        B1[i].resize(B[i].size());
        DH[i].resize(B[i].size());
        DB[i].resize(B[i].size());
        DW[i].resize(W[i].size());
    }
}

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::InnerBuffer::startDelta(
    const Collection<Vector<Precision, Args...>>& B,
    const Collection<Matrix<Precision, Args...>>& W)
{
    for(size_type i = 0; i < size_; ++i)
    {
        deltaB[i].resize(B[i].size());
        deltaW[i].resize(W[i].size());
    }
}

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::InnerBuffer::startOptimizer(
    const Collection<Vector<Precision, Args...>>& B,
    const Collection<Matrix<Precision, Args...>>& W)
{
    for(size_type i = 0; i < size_; ++i)
    {
        OB[i] = Tensor1D(B[i].size());
        OW[i] = Tensor2D(W[i].size());
        B2[i] = Tensor2D(W[i].size());
    }
}

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::InnerBuffer::resetDelta() noexcept
{
    for(size_type i = 0; i < size_; ++i)
    {
        deltaB[i].fill(0.0);
        deltaW[i].fill(0.0);
    }
}

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::InnerBuffer::resetOptimizer() noexcept
{
    for(size_type i = 0; i < size_; ++i)
    {
        OB[i].fill(0.0);
        OW[i].fill(0.0);
    }
}

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::InnerBuffer::updateDelta() noexcept
{
    for(size_type i = 0; i < size_; ++i)
    {
        deltaB[i] += DB[i];
        deltaW[i] += DW[i];
    }
}

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::InnerBuffer::normalizeDelta(
    Precision alpha) noexcept
{
    for(size_type i = 0; i < size_; ++i)
    {
        deltaB[i].join(alpha);
        deltaW[i].join(alpha);
    }
}

TRIXY_NEURO_TPL_DECLARATION
TRIXY_NEURO_TPL::Neuro(
    const std::initializer_list<std::size_t>& topology)
    : ib(topology.size() - 1)
    , B(topology.size() - 1)
    , W(topology.size() - 1)
    , N(topology.size() - 1)
    , A(topology.size() - 1)
    , E()
    , O()
    , li()
{
    auto lsh = topology.begin();
    auto rsh = topology.begin() + 1;

    for(size_type i = 0; i < N; ++i, ++lsh, ++rsh)
    {
        B[i] = Tensor1D(*rsh);
        W[i] = Tensor2D(*lsh, *rsh);
    }

    ib.initializeDefault();
    ib.initializeDelta();
    ib.initializeOptimizer();

    ib.startDefault(B, W);
    ib.startDelta(B, W);
    ib.startOptimizer(B, W);
}

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::initializeInnerStruct(
    Precision (*generator)()) noexcept
{
    for(size_type i = 0; i < N; ++i)
    {
        B[i].fill(generator);
        W[i].fill(generator);
    }
}

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::initializeInnerStruct(
    Precision (*generator_bias)(),
    Precision (*generator_weight)()) noexcept
{
    for(size_type i = 0; i < N; ++i)
    {
        B[i].fill(generator_bias);
        W[i].fill(generator_weight);
    }
}

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::setActivationFunction(
    const function::Activation<Vector, Precision, Args...>& activation_function) noexcept
{
    for(size_type i = 0; i < N - 1; ++i)
        A[i] = activation_function;
}

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::setNormalizationFunction(
    const function::Activation<Vector, Precision, Args...>& normalization_function) noexcept
{
    A[N - 1] = normalization_function;
}

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::setLossFunction(
    const function::Loss<Vector, Precision, Args...>& loss_function) noexcept
{
    E = loss_function;
}

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::setEachActivationFunction(
    const Collection<function::Activation<Vector, Precision, Args...>>& activation_set) noexcept
{
    for(size_type i = 0; i < activation_set.size(); ++i)
        A[i] = activation_set[i];
}

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::setOptimizationFunction(
    const function::Optimization<Vector, Matrix, Precision, Args...>& optimization_function) noexcept
{
    O = optimization_function;
}

TRIXY_NEURO_TPL_DECLARATION
inline const Collection<Vector<Precision, Args...>>&
    TRIXY_NEURO_TPL::getInnerBias() const noexcept
{
    return B;
}

TRIXY_NEURO_TPL_DECLARATION
inline const Collection<Matrix<Precision, Args...>>&
    TRIXY_NEURO_TPL::getInnerWeight() const noexcept
{
    return W;
}

TRIXY_NEURO_TPL_DECLARATION
inline const Collection<function::Activation<Vector, Precision, Args...>>&
    TRIXY_NEURO_TPL::getEachActivationFunction() const noexcept
{
    return A;
}

TRIXY_NEURO_TPL_DECLARATION
inline const function::Loss<Vector, Precision, Args...>&
    TRIXY_NEURO_TPL::getLossFunction() const noexcept
{
    return E;
}

TRIXY_NEURO_TPL_DECLARATION
const Vector<Precision, Args...>& TRIXY_NEURO_TPL::feedforward(
    const Vector<Precision, Args...>& vector) const
{
    li.dot(ib.B1[0], vector, W[0]);
    A[0].f(ib.B1[0], ib.B1[0].add(B[0]));

    for(size_type i = 1; i < N; ++i)
    {
        li.dot(ib.B1[i], ib.B1[i - 1], W[i]);
        A[i].f(ib.B1[i], ib.B1[i].add(B[i]));
    }

    return ib.B1[N - 1];
}

TRIXY_NEURO_TPL_DECLARATION
Collection<Vector<Precision, Args...>> TRIXY_NEURO_TPL::feedforward( // deprecated
    const Collection<Vector<Precision, Args...>>& idata) const
{
    Collection<Tensor1D> y_pred(idata.size());

    for(size_type i = 0; i < idata.size(); ++i)
        y_pred[i] = feedforward(idata[i]);

    return y_pred;
}

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::trainStochastic(
    const Collection<Vector<Precision, Args...>>& idata,
    const Collection<Vector<Precision, Args...>>& odata,
    Precision learn_rate,
    std::size_t epoch_scale,
    int (*generator)())
{
    for(size_type epoch = 0, sample; epoch < epoch_scale; ++epoch)
    {
        sample = generator() % idata.size();

        innerFeedForward(idata[sample]);
        innerBackPropagation(idata[sample], odata[sample]);
        innerUpdate(ib.DB, ib.DW, learn_rate);
    }
}

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::trainBatch(
    const Collection<Vector<Precision, Args...>>& idata,
    const Collection<Vector<Precision, Args...>>& odata,
    Precision learn_rate,
    std::size_t epoch_scale)
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

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::trainMiniBatch(
    const Collection<Vector<Precision, Args...>>& idata,
    const Collection<Vector<Precision, Args...>>& odata,
    Precision learn_rate,
    std::size_t epoch_scale,
    std::size_t mini_batch_size,
    int (*generator)())
{
    size_type sample;
    size_type sample_end;
    size_type sample_part;

    learn_rate /= mini_batch_size;

    for(size_type epoch = 0; epoch < epoch_scale; ++epoch)
    {
        sample_part = generator() % (idata.size() / mini_batch_size);
        sample      = sample_part * mini_batch_size;
        sample_end  = sample + mini_batch_size;

        ib.resetDelta();

        while(sample < sample_end)
        {
            innerFeedForward(idata[sample]);
            innerBackPropagation(idata[sample], odata[sample]);
            ib.updateDelta();

            ++sample;
        }

        innerUpdate(ib.deltaB, ib.deltaW, learn_rate);
    }
}

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::trainOptimize(
    const Collection<Vector<Precision, Args...>>& idata,
    const Collection<Vector<Precision, Args...>>& odata,
    Precision learn_rate,
    std::size_t epoch_scale,
    std::size_t mini_batch_size,
    int (*generator)())
{
    size_type sample;
    size_type sample_end;
    size_type sample_part;

    ib.resetOptimizer();

    const Precision alpha = 1.0 / mini_batch_size;

    for(size_type epoch = 0; epoch < epoch_scale; ++epoch)
    {
        sample_part = generator() % (idata.size() / mini_batch_size);
        sample      = sample_part * mini_batch_size;
        sample_end  = sample + mini_batch_size;

        ib.resetDelta();

        while(sample < sample_end)
        {
            innerFeedForward(idata[sample]);
            innerBackPropagation(idata[sample], odata[sample]);
            ib.updateDelta();

            ++sample;
        }

        ib.normalizeDelta(alpha);
        innerUpdateNormalize(ib.deltaB, ib.deltaW,
                             ib.OB, ib.OW, learn_rate);
    }
}

TRIXY_NEURO_TPL_DECLARATION
double TRIXY_NEURO_TPL::accuracy(
    const Collection<Vector<Precision, Args...>>& idata,
    const Collection<Vector<Precision, Args...>>& odata) const
{
    size_type count = 0;

    for(size_type i = 0; i < odata.size(); ++i)
        if(check(odata[i], feedforward(idata[i])))
            ++count;

    return static_cast<double>(count) / odata.size();
}

TRIXY_NEURO_TPL_DECLARATION
double TRIXY_NEURO_TPL::accuracyFull(
    const Collection<Vector<Precision, Args...>>& idata,
    const Collection<Vector<Precision, Args...>>& odata,
    Precision range_rate) const
{
    size_type count = 0;

    for(size_type i = 0; i < odata.size(); ++i)
        if(checkFull(odata[i], feedforward(idata[i]), range_rate))
            ++count;

    return static_cast<double>(count) / odata.size();
}

TRIXY_NEURO_TPL_DECLARATION
double TRIXY_NEURO_TPL::accuracyGlobal(
    const Collection<Vector<Precision, Args...>>& idata,
    const Collection<Vector<Precision, Args...>>& odata,
    Precision range_rate) const
{
    size_type count = 0;

    for(size_type i = 0; i < odata.size(); ++i)
        checkGlobal(odata[i], feedforward(idata[i]), range_rate, count);

    return static_cast<double>(count) / (odata.size() * odata[0].size());
}

TRIXY_NEURO_TPL_DECLARATION
double TRIXY_NEURO_TPL::loss(
    const Collection<Vector<Precision, Args...>>& idata,
    const Collection<Vector<Precision, Args...>>& odata) const
{
    size_type result = 0;

    for(size_type i = 0; i < odata.size(); ++i)
        result += E.f(odata[i], feedforward(idata[i]));

    return static_cast<double>(result) / odata.size();
}

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::innerFeedForward(
    const Vector<Precision, Args...>& idata_sample) const
{
    size_type i = 0;

    li.dot(ib.B1[0], idata_sample, W[0]);
    ib.B1[0].add(B[0]);
    for(size_type j = 1; j < N; ++j, ++i)
    {
        A[i].f(ib.H[j], ib.B1[i]);
        A[i].df(ib.DH[i], ib.B1[i]);
        li.dot(ib.B1[j], ib.H[j], W[j]);
        ib.B1[j].add(B[j]);
    }
    A[i].f(ib.H[0], ib.B1[i]);
    A[i].df(ib.DH[i], ib.B1[i]);
}

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::innerBackPropagation(
    const Vector<Precision, Args...>& idata_sample,
    const Vector<Precision, Args...>& odata_sample) const
{
    E.df(ib.B1[N - 1], odata_sample, ib.H[0]);
    for(size_type i = N - 1; i > 0; --i)
    {
        ib.DB[i].multiply(ib.B1[i], ib.DH[i]);
        li.tensordot(ib.DW[i], ib.DB[i], ib.H[i]);
        li.dottranspose(ib.B1[i - 1], ib.DB[i], W[i]);
    }
    ib.DB[0].multiply(ib.B1[0], ib.DH[0]);
    li.tensordot(ib.DW[0], ib.B1[0], idata_sample);
}

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::innerUpdate(
    Collection<Vector<Precision, Args...>>& deltaB,
    Collection<Matrix<Precision, Args...>>& deltaW,
    Precision learn_rate)
{
    for(size_type i = 0; i < N; ++i)
    {
        B[i].sub(deltaB[i].join(learn_rate));
        W[i].sub(deltaW[i].join(learn_rate));
    }
}

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::innerUpdateNormalize(
    Collection<Vector<Precision, Args...>>& deltaB,
    Collection<Matrix<Precision, Args...>>& deltaW,
    Collection<Vector<Precision, Args...>>& OB,
    Collection<Matrix<Precision, Args...>>& OW,
    Precision learn_rate)
{
    for(size_type i = 0; i < N; ++i)
    {
        B[i].sub(O.f1D(ib.B1[i], OB[i], deltaB[i]).join(learn_rate));
        W[i].sub(O.f2D(ib.B2[i], OW[i], deltaW[i]).join(learn_rate));
    }
}

TRIXY_NEURO_TPL_DECLARATION
bool TRIXY_NEURO_TPL::check(
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred) const
{
    static size_type max_true_out;
    static size_type max_pred_out;

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

TRIXY_NEURO_TPL_DECLARATION
bool TRIXY_NEURO_TPL::checkFull(
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred,
    Precision range_rate) const
{
    for(size_type j = 0; j < y_true.size(); ++j)
        if(std::fabs(y_true(j) - y_pred(j)) > range_rate)
            return false;

    return true;
}

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::checkGlobal(
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred,
    Precision range_rate,
    std::size_t& count) const
{
    for(size_type i = 0; i < y_true.size(); ++i)
        if(std::fabs(y_true(i) - y_pred(i)) < range_rate)
            ++count;
}

} // namespace trixy

// clean up
#undef TRIXY_NEURO_TPL_DECLARATION
#undef TRIXY_NEURO_TPL
#undef TRIXY_FUNCTION_ACTIVATION_TPL_DECLARATION
#undef TRIXY_FUNCTION_LOSS_TPL_DECLARATION
#undef TRIXY_FUNCTION_OPTIMIZATION_TPL_DECLARATION

#endif // NEURO_CORE_HPP
