#ifndef NEURO_CORE_HPP
#define NEURO_CORE_HPP

#include <cstddef> // size_t
#include <cmath> // fabs

namespace trixy
{

template <template <typename T, typename...> class Vector,
          template <typename T, typename...> class Matrix,
          template <class V, class M> class Linear,
          template <typename...> class Container,
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
              template <typename...> class Container,          \
              typename Precision,                              \
              typename... Args>

#define TRIXY_NEURO_TPL                                        \
    Neuro<Vector, Matrix, Linear,                              \
          Container, Precision, Args...>

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
    using Tensor1D  = Vector<Precision, Args...>;
    using size_type = std::size_t;
		
public:
    size_type id;
    void (*f)(Tensor1D&, const Tensor1D&);
    void (*df)(Tensor1D&, const Tensor1D&);

    Activation(
        size_type f_id = 0,
        void (*function)(Tensor1D&, const Tensor1D&) = nullptr,
        void (*function_derived)(Tensor1D&, const Tensor1D&) = nullptr) noexcept
    : id(f_id), f(function), df(function_derived) {}
};

TRIXY_FUNCTION_LOSS_TPL_DECLARATION
class Loss
{
private:
    using Tensor1D  = Vector<Precision, Args...>;
    using size_type = std::size_t;
		
public:
    size_type id;
    Precision (*f)(const Tensor1D&, const Tensor1D&);
    void (*df)(Tensor1D&, const Tensor1D&, const Tensor1D&);

    Loss(
        size_type f_id = 0,
        Precision (*function)(const Tensor1D&, const Tensor1D&) = nullptr,
        void (*function_derived)(Tensor1D&, const Tensor1D&, const Tensor1D&) = nullptr) noexcept
    : id(f_id), f(function), df(function_derived) {}
};

TRIXY_FUNCTION_OPTIMIZATION_TPL_DECLARATION
class Optimization
{
private:
    using Tensor1D  = Vector<Precision, Args...>;
    using Tensor2D  = Matrix<Precision, Args...>;
    using size_type = std::size_t;
		
public:
    size_type id;
    void (*f1D)(Tensor1D&, Tensor1D&, const Tensor1D&);
    void (*f2D)(Tensor2D&, Tensor2D&, const Tensor2D&);

    Optimization(
        size_type f_id = 0,
        void (*vector_optimizer)(Tensor1D&, Tensor1D&, const Tensor1D&) = nullptr,
        void (*matrix_optimizer)(Tensor2D&, Tensor2D&, const Tensor2D&) = nullptr) noexcept
    : id(f_id), f1D(vector_optimizer), f2D(matrix_optimizer) {}
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

    using size_type          = std::size_t;
    using GeneratorInteger   = int (*)();
    using GeneratorPrecision = Precision (*)();

private:
    mutable InnerBuffer ib;

    Container<Tensor1D> B;
    Container<Tensor2D> W;
    size_type N;

    Container<ActivationFunction> A;
    LossFunction E;
    OptimizationFunction O;

    Linear<Tensor1D, Tensor2D> li;

public:
    Neuro(const Container<size_type>& topology);

    const Tensor1D& feedforward(const Tensor1D&) const noexcept;

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

    double fullAccuracy(const Container<Tensor1D>& idata,
                        const Container<Tensor1D>& odata,
                        Precision range_rate) const noexcept;

    double globalAccuracy(const Container<Tensor1D>& idata,
                          const Container<Tensor1D>& odata,
                          Precision range_rate) const noexcept;

    double loss(const Container<Tensor1D>& idata,
                const Container<Tensor1D>& odata) const noexcept;

private:
    void innerFeedForward(const Tensor1D& idata_sample) const noexcept;

    void innerBackPropagation(const Tensor1D& idata_sample,
                              const Tensor1D& odata_sample) const noexcept;

    void innerUpdateNormalize(const Container<Tensor1D>& deltaB,
                              const Container<Tensor2D>& detlaW,
                              Container<Tensor1D>& OB,
                              Container<Tensor2D>& OW,
                              Precision learn_rate) noexcept;

    void innerUpdate(Container<Tensor1D>& deltaB,
                     Container<Tensor2D>& deltaW,
                     Precision learn_rate) noexcept;

    bool check(const Tensor1D& y_true,
               const Tensor1D& y_pred) const noexcept;

    bool fullCheck(const Tensor1D& y_true,
                   const Tensor1D& y_pred,
                   Precision range_rate) const noexcept;

    void globalCheck(const Tensor1D& y_true,
                     const Tensor1D& y_pred,
                     Precision range_rate,
                     size_type& count) const noexcept;

public:
    void initializeInnerStruct(GeneratorPrecision generator_all) noexcept;

    void initializeInnerStruct(GeneratorPrecision generator_bias,
                               GeneratorPrecision generator_weight) noexcept;

    void initializeInnerStruct(const Container<Tensor1D>& bias,
                               const Container<Tensor2D>& weight) noexcept;

    void setActivationFunction(const ActivationFunction&) noexcept;
    void setNormalizationFunction(const ActivationFunction&) noexcept;
    void setEachActivationFunction(const Container<ActivationFunction>&) noexcept; // maybe unused

    void setLossFunction(const LossFunction&) noexcept;
    void setOptimizationFunction(const OptimizationFunction&) noexcept;

    const Container<Tensor1D>& getInnerBias() const noexcept;
    const Container<Tensor2D>& getInnerWeight() const noexcept;

    const LossFunction& getLossFunction() const noexcept;
    const Container<ActivationFunction>& getEachActivationFunction() const noexcept; // maybe unused
};

TRIXY_NEURO_TPL_DECLARATION
class TRIXY_NEURO_TPL::InnerBuffer
{
public:
    using size_type = std::size_t;

private:
    size_type size_;

public:
    Container<Tensor1D> H;
    Container<Tensor1D> B1;
    Container<Tensor1D> DH;
    Container<Tensor1D> DB;
    Container<Tensor2D> DW;

    Container<Tensor1D> deltaB;
    Container<Tensor2D> deltaW;

    Container<Tensor1D> OB;
    Container<Tensor2D> OW;
    Container<Tensor2D> B2;

public:
    InnerBuffer() = default;
    explicit InnerBuffer(size_type) noexcept;

    void initializeDefault();
    void initializeDelta();
    void initializeOptimizer();

    void startDefault(const Container<Tensor1D>& B,
                      const Container<Tensor2D>& W);

    void startDelta(const Container<Tensor1D>& B,
                    const Container<Tensor2D>& W);

    void startOptimizer(const Container<Tensor1D>& B,
                        const Container<Tensor2D>& W);

    void resetDelta() noexcept;
    void resetOptimizer() noexcept;

    void updateDelta() noexcept;
    void normalizeDelta(Precision alpha) noexcept;
};

TRIXY_NEURO_TPL_DECLARATION
inline TRIXY_NEURO_TPL::InnerBuffer::InnerBuffer(std::size_t N) noexcept
    : size_(N)
{
}

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::InnerBuffer::initializeDefault()
{
    H.resize(size_);
    B1.resize(size_);
    DH.resize(size_);
    DB.resize(size_);
    DW.resize(size_);
}

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::InnerBuffer::initializeDelta()
{
    deltaB.resize(size_);
    deltaW.resize(size_);
}

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::InnerBuffer::initializeOptimizer()
{
    OB.resize(size_);
    OW.resize(size_);
    B2.resize(size_);
}

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::InnerBuffer::startDefault(
    const Container<Vector<Precision, Args...>>& B,
    const Container<Matrix<Precision, Args...>>& W)
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
    const Container<Vector<Precision, Args...>>& B,
    const Container<Matrix<Precision, Args...>>& W)
{
    for(size_type i = 0; i < size_; ++i)
    {
        deltaB[i].resize(B[i].size());
        deltaW[i].resize(W[i].size());
    }
}

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::InnerBuffer::startOptimizer(
    const Container<Vector<Precision, Args...>>& B,
    const Container<Matrix<Precision, Args...>>& W)
{
    for(size_type i = 0; i < size_; ++i)
    {
        OB[i].resize(B[i].size());
        OW[i].resize(W[i].size());
        B2[i].resize(W[i].size());
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
        deltaB[i].add(DB[i]);
        deltaW[i].add(DW[i]);
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
    const Container<size_type>& topology)
    : ib(topology.size() - 1)
    , B(topology.size() - 1)
    , W(topology.size() - 1)
    , N(topology.size() - 1)
    , A(topology.size() - 1)
    , E()
    , O()
    , li()
{
    for(size_type i = 0; i < N; ++i)
    {
        B[i].resize(topology[i + 1]);
        W[i].resize(topology[i], topology[i + 1]);
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
    Precision (*generator_all)()) noexcept
{
    for(size_type i = 0; i < N; ++i)
    {
        B[i].fill(generator_all);
        W[i].fill(generator_all);
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
void TRIXY_NEURO_TPL::initializeInnerStruct(
    const Container<Tensor1D>& bias,
    const Container<Tensor2D>& weight) noexcept
{
    for(size_type i = 0; i < N; ++i)
    {
        B[i] = bias[i];
        W[i] = weight[i];
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
    const Container<function::Activation<Vector, Precision, Args...>>& activation_set) noexcept
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
inline const Container<Vector<Precision, Args...>>&
    TRIXY_NEURO_TPL::getInnerBias() const noexcept
{
    return B;
}

TRIXY_NEURO_TPL_DECLARATION
inline const Container<Matrix<Precision, Args...>>&
    TRIXY_NEURO_TPL::getInnerWeight() const noexcept
{
    return W;
}

TRIXY_NEURO_TPL_DECLARATION
inline const Container<function::Activation<Vector, Precision, Args...>>&
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
    const Vector<Precision, Args...>& vector) const noexcept
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
void TRIXY_NEURO_TPL::trainStochastic(
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

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::trainBatch(
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

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::trainMiniBatch(
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

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::trainOptimize(
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

    const Precision alpha = 1.0 / mini_batch_size;

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

TRIXY_NEURO_TPL_DECLARATION
double TRIXY_NEURO_TPL::accuracy(
    const Container<Vector<Precision, Args...>>& idata,
    const Container<Vector<Precision, Args...>>& odata) const noexcept
{
    size_type count = 0;

    for(size_type i = 0; i < odata.size(); ++i)
        if(check(odata[i], feedforward(idata[i])))
            ++count;

    return static_cast<double>(count) / odata.size();
}

TRIXY_NEURO_TPL_DECLARATION
double TRIXY_NEURO_TPL::fullAccuracy(
    const Container<Vector<Precision, Args...>>& idata,
    const Container<Vector<Precision, Args...>>& odata,
    Precision range_rate) const noexcept
{
    size_type count = 0;

    for(size_type i = 0; i < odata.size(); ++i)
        if(fullCheck(odata[i], feedforward(idata[i]), range_rate))
            ++count;

    return static_cast<double>(count) / odata.size();
}

TRIXY_NEURO_TPL_DECLARATION
double TRIXY_NEURO_TPL::globalAccuracy(
    const Container<Vector<Precision, Args...>>& idata,
    const Container<Vector<Precision, Args...>>& odata,
    Precision range_rate) const noexcept
{
    size_type count = 0;

    for(size_type i = 0; i < odata.size(); ++i)
        globalCheck(odata[i], feedforward(idata[i]), range_rate, count);

    return static_cast<double>(count) / (odata.size() * odata[0].size());
}

TRIXY_NEURO_TPL_DECLARATION
double TRIXY_NEURO_TPL::loss(
    const Container<Vector<Precision, Args...>>& idata,
    const Container<Vector<Precision, Args...>>& odata) const noexcept
{
    size_type result = 0;

    for(size_type i = 0; i < odata.size(); ++i)
        result += E.f(odata[i], feedforward(idata[i]));

    return static_cast<double>(result) / odata.size();
}

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::innerFeedForward(
    const Vector<Precision, Args...>& idata_sample) const noexcept
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
    const Vector<Precision, Args...>& odata_sample) const noexcept
{
    E.df(ib.B1[N - 1], odata_sample, ib.H[0]);
    for(size_type i = N - 1; i > 0; --i)
    {
        ib.DB[i].multiply(ib.B1[i], ib.DH[i]);

        li.tensordot(ib.DW[i], ib.H[i], ib.DB[i]);
        li.dottranspose(ib.B1[i - 1], ib.DB[i], W[i]);
    }
    ib.DB[0].multiply(ib.B1[0], ib.DH[0]);
    li.tensordot(ib.DW[0], idata_sample, ib.B1[0]);
}

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::innerUpdate(
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

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::innerUpdateNormalize(
    const Container<Vector<Precision, Args...>>& deltaB,
    const Container<Matrix<Precision, Args...>>& deltaW,
    Container<Vector<Precision, Args...>>& OB,
    Container<Matrix<Precision, Args...>>& OW,
    Precision learn_rate) noexcept
{
    for(size_type i = 0; i < N; ++i)
    {
        O.f1D(ib.B1[i], OB[i], deltaB[i]);
        O.f2D(ib.B2[i], OW[i], deltaW[i]);

        B[i].sub(ib.B1[i].join(learn_rate));
        W[i].sub(ib.B2[i].join(learn_rate));
    }
}

TRIXY_NEURO_TPL_DECLARATION
bool TRIXY_NEURO_TPL::check(
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred) const noexcept
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
bool TRIXY_NEURO_TPL::fullCheck(
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred,
    Precision range_rate) const noexcept
{
    for(size_type j = 0; j < y_true.size(); ++j)
        if(std::fabs(y_true(j) - y_pred(j)) > range_rate)
            return false;

    return true;
}

TRIXY_NEURO_TPL_DECLARATION
void TRIXY_NEURO_TPL::globalCheck(
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
#undef TRIXY_NEURO_TPL_DECLARATION
#undef TRIXY_NEURO_TPL
#undef TRIXY_FUNCTION_ACTIVATION_TPL_DECLARATION
#undef TRIXY_FUNCTION_LOSS_TPL_DECLARATION
#undef TRIXY_FUNCTION_OPTIMIZATION_TPL_DECLARATION

#endif // NEURO_CORE_HPP
