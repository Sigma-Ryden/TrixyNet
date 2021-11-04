#ifndef NEURO_CORE_HPP
#define NEURO_CORE_HPP

#include <cstddef> // size_t
#include <cmath> // fabs
#include <initializer_list> // initializer_list
#include <utility> // declval, move

namespace trixy
{

namespace function
{

template <template <typename T, typename...> class Vector, typename Precision, typename... Args>
class Activation
{
private:
    using Tensor1D = Vector<Precision, Args...>;

public:
    Tensor1D (*f)(const Tensor1D&);
    Tensor1D (*df)(const Tensor1D&);

    explicit Activation(
        Tensor1D (*function)(const Tensor1D&) = nullptr,
        Tensor1D (*function_derived)(const Tensor1D&) = nullptr) noexcept
    : f(function), df(function_derived) {}
};

template <template <typename T, typename...> class Vector, typename Precision, typename... Args>
class Loss
{
private:
    using Tensor1D = Vector<Precision, Args...>;

public:
    Precision (*f)(const Tensor1D&, const Tensor1D&);
    Tensor1D (*df)(const Tensor1D&, const Tensor1D&);

    explicit Loss(
        Precision (*function)(const Tensor1D&, const Tensor1D&) = nullptr,
        Tensor1D (*function_derived)(const Tensor1D&, const Tensor1D&) = nullptr) noexcept
    : f(function), df(function_derived) {}
};

template <template <typename T, typename...> class Vector, template <typename T, typename...> class Matrix,
          typename Precision, typename... Args>
class Optimization
{
private:
    using Tensor1D = Vector<Precision, Args...>;
    using Tensor2D = Matrix<Precision, Args...>;

public:
    Tensor1D (*f1D)(Tensor1D&, Tensor1D&);
    Tensor2D (*f2D)(Tensor2D&, Tensor2D&);

    explicit Optimization(
        Tensor1D (*vector_optimizer)(Tensor1D&, Tensor1D&) = nullptr,
        Tensor2D (*matrix_optimizer)(Tensor2D&, Tensor2D&) = nullptr) noexcept
    : f1D(vector_optimizer), f2D(matrix_optimizer) {}
};

namespace detail
{

template <template <typename T, typename...> class Tensor, typename Precision, typename... Args>
class Optimizer
{
private:
    using TensorND = Tensor<Precision, Args...>;
    using tensor_size_type = decltype(std::declval<TensorND>().size());

    TensorND retain_;
    TensorND (*optimizer_)(TensorND&, TensorND&);

public:
    Optimizer() = default;
    explicit Optimizer(
        TensorND (*optimizer)(TensorND&, TensorND&), tensor_size_type retain_size)
        : retain_(retain_size), optimizer_(optimizer)
    {
        retain_.fill(0.0);
    }

    void change(TensorND (*new_optimizer)(TensorND&, TensorND&))
    {
        optimizer_ = new_optimizer;
    }

    void reset(tensor_size_type new_size)
    {
        retain_.resize(new_size);
        retain_.fill(0.0);
    }

    TensorND update(TensorND& grad)
    {
        return optimizer_(grad, retain_);
    }
};

} // namespace detail

} // namespace function

template <template <typename T, typename...> class Vector, template <typename T, typename...> class Matrix,
          template <class V, class M> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
class Neuro
{
public:
    using Tensor1D = Vector<Precision, Args...>;
    using Tensor2D = Matrix<Precision, Args...>;

    using Optimizer1D = function::detail::Optimizer<Vector, Precision, Args...>;
    using Optimizer2D = function::detail::Optimizer<Matrix, Precision, Args...>;

    using ActivationFunction   = function::Activation<Vector, Precision, Args...>;
    using LossFunction         = function::Loss<Vector, Precision, Args...>;
    using OptimizationFunction = function::Optimization<Vector, Matrix, Precision, Args...>;

    using size_type          = std::size_t;
    using GeneratorInteger   = int (*)();
    using GeneratorFloat     = Precision (*)();

private:
    Collection<Tensor1D> B;
    Collection<Tensor2D> W;
    size_type N;

    Collection<ActivationFunction> A;
    LossFunction E;
    OptimizationFunction O;

    Linear<Tensor1D, Tensor2D> li;

public:
    Neuro(const std::initializer_list<size_type>& topology);
    ~Neuro() = default;

    void initializeInnerStruct(GeneratorFloat generator) noexcept;

    void initializeInnerStruct(GeneratorFloat generator_bias,
                               GeneratorFloat generator_weight) noexcept;

    void setActivationFunction(const ActivationFunction& activation_function) noexcept;
    void setNormalizationFunction(const ActivationFunction& normalization_function) noexcept;
    void setLossFunction(const LossFunction& loss_function) noexcept;
    void setOptimizationFunction(const OptimizationFunction& optimization_function) noexcept;

    void setEachActivationFunction(const Collection<ActivationFunction>& activation_set) noexcept;

    const Collection<Tensor1D>& getInnerBias() const noexcept;
    const Collection<Tensor2D>& getInnerWeight() const noexcept;

    const Collection<ActivationFunction>& getEachActivationFunction() const noexcept;
    const LossFunction& getLossFunction() const noexcept;

    Tensor1D feedforward(const Tensor1D&) const;
    Collection<Tensor1D> feedforward(const Collection<Tensor1D>&) const;

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

    double globalAccuracy(const Collection<Tensor1D>& idata,
                          const Collection<Tensor1D>& odata,
                          Precision range_rate) const;

    double fullAccuracy(const Collection<Tensor1D>& idata,
                        const Collection<Tensor1D>& odata,
                        Precision range_rate) const;

    double loss(const Collection<Tensor1D>& idata,
                const Collection<Tensor1D>& odata) const;

private:
    void feedForward(const Tensor1D& idata_sample,
                     Collection<Tensor1D>& H,
                     Collection<Tensor1D>& DH,
                     Collection<Tensor1D>& S) const;

    void backPropagation(const Tensor1D& odata_sample,
                         const Collection<Tensor1D>& H,
                         Collection<Tensor1D>& DH,
                         Collection<Tensor1D>& DB,
                         Collection<Tensor2D>& DW,
                         Collection<Tensor1D>& theta) const;

    void updateNormalize(Collection<Tensor1D>& deltaB,
                         Collection<Tensor2D>& deltaW,
                         Collection<Optimizer1D>& OB,
                         Collection<Optimizer2D>& OW,
                         Precision learn_rate,
                         size_type batch_size);

    void updateDelta(const Collection<Tensor1D>& DB,
                     const Collection<Tensor2D>& DW,
                     Collection<Tensor1D>& deltaB,
                     Collection<Tensor2D>& deltaW) const noexcept;

    void updateInnerStruct(Collection<Tensor1D>& deltaB,
                           Collection<Tensor2D>& deltaW,
                           Precision learn_rate);

    void startOptimizer(Collection<Optimizer1D>& OB,
                        Collection<Optimizer2D>& OW) const;

    void resetDelta(Collection<Tensor1D>& deltaB,
                    Collection<Tensor2D>& deltaW) const noexcept;

    void startDelta(Collection<Tensor1D>& deltaB,
                    Collection<Tensor2D>& deltaW) const;
};

template <template <typename T, typename...> class Vector, template <typename T, typename...> class Matrix,
          template <class V, class M> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
Neuro<Vector, Matrix, Linear, Collection, Precision, Args...>::Neuro(
    const std::initializer_list<std::size_t>& topology)
    : B(topology.size() - 1)
    , W(topology.size() - 1)
    , N(topology.size() - 1)
    , A(topology.size() - 1)
    , E()
    , O()
    , li()
{
    auto lsh = topology.begin();
    auto rsh = topology.begin() + 1;

    for(size_type i = 0; i < N; ++i)
    {
        B[i] = Tensor1D(*rsh);
        W[i] = Tensor2D(*lsh, *rsh);

        ++lsh;
        ++rsh;
    }
}

template <template <typename T, typename...> class Vector, template <typename T, typename...> class Matrix,
          template <class V, class M> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
void Neuro<Vector, Matrix, Linear, Collection, Precision, Args...>::initializeInnerStruct(
    Precision (*generator)()) noexcept
{
    for(size_type i = 0; i < N; ++i)
    {
        B[i].fill(generator);
        W[i].fill(generator);
    }
}

template <template <typename T, typename...> class Vector, template <typename T, typename...> class Matrix,
          template <class V, class M> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
void Neuro<Vector, Matrix, Linear, Collection, Precision, Args...>::initializeInnerStruct(
    Precision (*generator_bias)(),
    Precision (*generator_weight)()) noexcept
{
    for(size_type i = 0; i < N; ++i)
    {
        B[i].fill(generator_bias);
        W[i].fill(generator_weight);
    }
}

template <template <typename T, typename...> class Vector, template <typename T, typename...> class Matrix,
          template <class V, class M> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
void Neuro<Vector, Matrix, Linear, Collection, Precision, Args...>::setActivationFunction(
    const function::Activation<Vector, Precision, Args...>& activation_function) noexcept
{
    for(size_type i = 0; i < N - 1; ++i)
        A[i] = activation_function;
}

template <template <typename T, typename...> class Vector, template <typename T, typename...> class Matrix,
          template <class V, class M> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
void Neuro<Vector, Matrix, Linear, Collection, Precision, Args...>::setNormalizationFunction(
    const function::Activation<Vector, Precision, Args...>& normalization_function) noexcept
{
    A[N - 1] = normalization_function;
}

template <template <typename T, typename...> class Vector, template <typename T, typename...> class Matrix,
          template <class V, class M> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
void Neuro<Vector, Matrix, Linear, Collection, Precision, Args...>::setLossFunction(
    const function::Loss<Vector, Precision, Args...>& loss_function) noexcept
{
    E = loss_function;
}

template <template <typename T, typename...> class Vector, template <typename T, typename...> class Matrix,
          template <class V, class M> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
void Neuro<Vector, Matrix, Linear, Collection, Precision, Args...>::setEachActivationFunction(
    const Collection<function::Activation<Vector, Precision, Args...>>& activation_set) noexcept
{
    for(size_type i = 0; i < activation_set.size(); ++i)
        A[i] = activation_set[i];
}

template <template <typename T, typename...> class Vector, template <typename T, typename...> class Matrix,
          template <class V, class M> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
void Neuro<Vector, Matrix, Linear, Collection, Precision, Args...>::setOptimizationFunction(
    const OptimizationFunction& optimization_function) noexcept
{
    O = optimization_function;
}

template <template <typename T, typename...> class Vector, template <typename T, typename...> class Matrix,
          template <class V, class M> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
inline const Collection<Vector<Precision, Args...>>&
    Neuro<Vector, Matrix, Linear, Collection, Precision, Args...>::getInnerBias() const noexcept
{
    return B;
}

template <template <typename T, typename...> class Vector, template <typename T, typename...> class Matrix,
          template <class V, class M> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
inline const Collection<Matrix<Precision, Args...>>&
    Neuro<Vector, Matrix, Linear, Collection, Precision, Args...>::getInnerWeight() const noexcept
{
    return W;
}

template <template <typename T, typename...> class Vector, template <typename T, typename...> class Matrix,
          template <class V, class M> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
inline const Collection<function::Activation<Vector, Precision, Args...>>&
    Neuro<Vector, Matrix, Linear, Collection, Precision, Args...>::getEachActivationFunction() const noexcept
{
    return A;
}

template <template <typename T, typename...> class Vector, template <typename T, typename...> class Matrix,
          template <class V, class M> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
inline const function::Loss<Vector, Precision, Args...>&
    Neuro<Vector, Matrix, Linear, Collection, Precision, Args...>::getLossFunction() const noexcept
{
    return E;
}

template <template <typename T, typename...> class Vector, template <typename T, typename...> class Matrix,
          template <class V, class M> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
Vector<Precision, Args...> Neuro<Vector, Matrix, Linear, Collection, Precision, Args...>::feedforward(
    const Vector<Precision, Args...>& vector) const
{
    Tensor1D y_pred = vector;

    for(size_type i = 0; i < N; ++i)
        y_pred = A[i].f(li.dot(y_pred, W[i]) + B[i]);

    return y_pred;
}

template <template <typename T, typename...> class Vector, template <typename T, typename...> class Matrix,
          template <class V, class M> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
Collection<Vector<Precision, Args...>> Neuro<Vector, Matrix, Linear, Collection, Precision, Args...>::feedforward(
    const Collection<Vector<Precision, Args...>>& idata) const
{
    Collection<Tensor1D> y_pred(idata.size());

    for(size_type i = 0; i < idata.size(); ++i)
        y_pred[i] = feedforward(idata[i]);

    return y_pred;
}

template <template <typename T, typename...> class Vector, template <typename T, typename...> class Matrix,
          template <class V, class M> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
void Neuro<Vector, Matrix, Linear, Collection, Precision, Args...>::trainStochastic(
    const Collection<Vector<Precision, Args...>>& idata,
    const Collection<Vector<Precision, Args...>>& odata,
    Precision learn_rate,
    std::size_t epoch_scale,
    int (*generator)())
{
    Collection<Tensor1D> H(N + 1);
    Collection<Tensor1D> DH(N);
    Collection<Tensor1D> DB(N);
    Collection<Tensor2D> DW(N);

    Collection<Tensor1D> S(N);
    Collection<Tensor1D> theta(N);

    for(size_type n = 0, sample; n < epoch_scale; ++n)
    {
        sample = generator() % idata.size();

        feedForward(idata[sample], H, DH, S);
        backPropagation(odata[sample], H, DH, DB, DW, theta);
        updateInnerStruct(DB, DW, learn_rate);
    }
}

template <template <typename T, typename...> class Vector, template <typename T, typename...> class Matrix,
          template <class V, class M> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
void Neuro<Vector, Matrix, Linear, Collection, Precision, Args...>::trainBatch(
    const Collection<Vector<Precision, Args...>>& idata,
    const Collection<Vector<Precision, Args...>>& odata,
    Precision learn_rate,
    std::size_t epoch_scale)
{
    Collection<Tensor1D> H(N + 1);
    Collection<Tensor1D> DH(N);
    Collection<Tensor1D> DB(N);
    Collection<Tensor2D> DW(N);

    Collection<Tensor1D> deltaB(N);
    Collection<Tensor2D> deltaW(N);

    Collection<Tensor1D> S(N);
    Collection<Tensor1D> theta(N);

    learn_rate /= idata.size();

    startDelta(deltaB, deltaW);

    for(size_type n = 0; n < epoch_scale; ++n)
    {
        resetDelta(deltaB, deltaW);

        for(size_type sample = 0; sample < idata.size(); ++sample)
        {
            feedForward(idata[sample], H, DH, S);
            backPropagation(odata[sample], H, DH, DB, DW, theta);
            updateDelta(DB, DW, deltaB, deltaW);
        }

        updateInnerStruct(deltaB, deltaW, learn_rate);
    }
}

template <template <typename T, typename...> class Vector, template <typename T, typename...> class Matrix,
          template <class V, class M> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
void Neuro<Vector, Matrix, Linear, Collection, Precision, Args...>::trainMiniBatch(
    const Collection<Vector<Precision, Args...>>& idata,
    const Collection<Vector<Precision, Args...>>& odata,
    Precision learn_rate,
    std::size_t epoch_scale,
    std::size_t mini_batch_size,
    int (*generator)())
{
    Collection<Tensor1D> H(N + 1);
    Collection<Tensor1D> DH(N);
    Collection<Tensor1D> DB(N);
    Collection<Tensor2D> DW(N);

    Collection<Tensor1D> deltaB(N);
    Collection<Tensor2D> deltaW(N);

    Collection<Tensor1D> S(N);
    Collection<Tensor1D> theta(N);

    size_type sample;
    size_type sample_end;
    size_type sample_part;

    learn_rate /= mini_batch_size;

    startDelta(deltaB, deltaW);

    for(size_type n = 0; n < epoch_scale; ++n)
    {
        sample_part = generator() % (idata.size() / mini_batch_size);
        sample      = sample_part * mini_batch_size;
        sample_end  = sample + mini_batch_size;

        resetDelta(deltaB, deltaW);

        while(sample < sample_end)
        {
            feedForward(idata[sample], H, DH, S);
            backPropagation(odata[sample], H, DH, DB, DW, theta);
            updateDelta(DB, DW, deltaB, deltaW);

            ++sample;
        }

        updateInnerStruct(deltaB, deltaW, learn_rate);
    }
}

template <template <typename T, typename...> class Vector, template <typename T, typename...> class Matrix,
          template <class V, class M> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
void Neuro<Vector, Matrix, Linear, Collection, Precision, Args...>::trainOptimize(
    const Collection<Vector<Precision, Args...>>& idata,
    const Collection<Vector<Precision, Args...>>& odata,
    Precision learn_rate,
    std::size_t epoch_scale,
    std::size_t mini_batch_size,
    int (*generator)())
{
    Collection<Tensor1D> H(N + 1);
    Collection<Tensor1D> DH(N);
    Collection<Tensor1D> DB(N);
    Collection<Tensor2D> DW(N);

    Collection<Tensor1D> deltaB(N);
    Collection<Tensor2D> deltaW(N);

    Collection<Optimizer1D> OB(N);
    Collection<Optimizer2D> OW(N);

    Collection<Tensor1D> S(N);
    Collection<Tensor1D> theta(N);

    size_type sample;
    size_type sample_end;
    size_type sample_part;

    startDelta(deltaB, deltaW);
    startOptimizer(OB, OW);

    for(size_type n = 0; n < epoch_scale; ++n)
    {
        sample_part = generator() % (idata.size() / mini_batch_size);
        sample      = sample_part * mini_batch_size;
        sample_end  = sample + mini_batch_size;

        resetDelta(deltaB, deltaW);

        while(sample < sample_end)
        {
            feedForward(idata[sample], H, DH, S);
            backPropagation(odata[sample], H, DH, DB, DW, theta);
            updateDelta(DB, DW, deltaB, deltaW);

            ++sample;
        }

        updateNormalize(deltaB, deltaW, OB, OW, learn_rate, mini_batch_size);
    }
}

template <template <typename T, typename...> class Vector, template <typename T, typename...> class Matrix,
          template <class V, class M> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
double Neuro<Vector, Matrix, Linear, Collection, Precision, Args...>::accuracy(
    const Collection<Vector<Precision, Args...>>& idata,
    const Collection<Vector<Precision, Args...>>& odata) const
{
    const Collection<Tensor1D> pred_out = feedforward(idata);

    const size_type batch_size  = odata.size();
    const size_type output_size = odata[0].size();

    double count = 0.0;

    size_type max_pred_out;
    size_type max_out;

    for(size_type i = 0; i < batch_size; ++i)
    {
        max_pred_out = 0;
        max_out      = 0;

        for(size_type j = 0; j < output_size; ++j)
            if(pred_out[i](max_pred_out) < pred_out[i](j))
                max_pred_out = j;

        for(size_type j = 0; j < output_size; ++j)
            if(odata[i](max_out) < odata[i](j))
                max_out = j;

        if(max_pred_out == max_out)
            ++count;
    }

    return count / batch_size;
}

template <template <typename T, typename...> class Vector, template <typename T, typename...> class Matrix,
          template <class V, class M> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
double Neuro<Vector, Matrix, Linear, Collection, Precision, Args...>::globalAccuracy(
    const Collection<Vector<Precision, Args...>>& idata,
    const Collection<Vector<Precision, Args...>>& odata,
    Precision range_rate) const
{
    const Collection<Tensor1D> pred_out = feedforward(idata);

    const size_type batch_size  = odata.size();
    const size_type output_size = odata[0].size();

    double count = 0.0;

    for(size_type i = 0; i < batch_size; ++i)
        for(size_type j = 0; j < output_size; ++j)
            if(std::fabs(pred_out[i](j) - odata[i](j)) < range_rate)
                ++count;

    return count / (batch_size * output_size);
}

template <template <typename T, typename...> class Vector, template <typename T, typename...> class Matrix,
          template <class V, class M> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
double Neuro<Vector, Matrix, Linear, Collection, Precision, Args...>::fullAccuracy(
    const Collection<Vector<Precision, Args...>>& idata,
    const Collection<Vector<Precision, Args...>>& odata,
    Precision range_rate) const
{
    const Collection<Tensor1D>& pred_out = feedforward(idata);

    const size_type batch_size = odata.size();
    const size_type output_size = odata[0].size();

    double count = 0.0;
    bool answer;

    for(size_type i = 0; i < batch_size; ++i)
    {
        answer = true;
        for(size_type j = 0; j < output_size; ++j)
        {
            if(std::fabs(pred_out[i](j) - odata[i](j)) > range_rate)
            {
                answer = false;
                break;
            }
        }
        if(answer) ++count;
    }
    return count / batch_size;
}

template <template <typename T, typename...> class Vector, template <typename T, typename...> class Matrix,
          template <class V, class M> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
double Neuro<Vector, Matrix, Linear, Collection, Precision, Args...>::loss(
    const Collection<Vector<Precision, Args...>>& idata,
    const Collection<Vector<Precision, Args...>>& odata) const
{
    const Collection<Tensor1D> pred_out = feedforward(idata);
    double result = 0.0;

    for(size_type i = 0; i < odata.size(); ++i)
        result += E.f(odata[i], pred_out[i]);

    return result / odata.size();
}

template <template <typename T, typename...> class Vector, template <typename T, typename...> class Matrix,
          template <class V, class M> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
void Neuro<Vector, Matrix, Linear, Collection, Precision, Args...>::feedForward(
    const Vector<Precision, Args...>& idata_sample,
    Collection<Vector<Precision, Args...>>& H,
    Collection<Vector<Precision, Args...>>& DH,
    Collection<Vector<Precision, Args...>>& S) const
{
    H[0] = idata_sample;
    for(size_type i = 0; i < N; ++i)
    {
        S[i]     = li.dot(H[i], W[i]) + B[i];
        H[i + 1] = A[i].f(S[i]);
        DH[i]    = A[i].df(S[i]);
    }
}

template <template <typename T, typename...> class Vector, template <typename T, typename...> class Matrix,
          template <class V, class M> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
void Neuro<Vector, Matrix, Linear, Collection, Precision, Args...>::backPropagation(
    const Tensor1D& odata_sample,
    const Collection<Vector<Precision, Args...>>& H,
    Collection<Vector<Precision, Args...>>& DH,
    Collection<Vector<Precision, Args...>>& DB,
    Collection<Matrix<Precision, Args...>>& DW,
    Collection<Vector<Precision, Args...>>& theta) const
{
    theta[N - 1] = E.df(odata_sample, H[N]);
    for(size_type i = N - 1; i > 0; --i)
    {
        DB[i]        = std::move(DH[i].multiply(theta[i]));
        DW[i]        = li.tensordot(DB[i], H[i]);
        theta[i - 1] = li.dot(DB[i], W[i], true);
    }
    DB[0] = std::move(DH[0].multiply(theta[0]));
    DW[0] = li.tensordot(DB[0], H[0]);
}

template <template <typename T, typename...> class Vector, template <typename T, typename...> class Matrix,
          template <class V, class M> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
void Neuro<Vector, Matrix, Linear, Collection, Precision, Args...>::updateInnerStruct(
    Collection<Vector<Precision, Args...>>& deltaB,
    Collection<Matrix<Precision, Args...>>& deltaW,
    Precision learn_rate)
{
    for(size_type i = 0; i < N; ++i)
    {
        B[i] -= deltaB[i].join(learn_rate);
        W[i] -= deltaW[i].join(learn_rate);
    }
}

template <template <typename T, typename...> class Vector, template <typename T, typename...> class Matrix,
          template <class V, class M> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
void Neuro<Vector, Matrix, Linear, Collection, Precision, Args...>::updateDelta(
    const Collection<Vector<Precision, Args...>>& DB,
    const Collection<Matrix<Precision, Args...>>& DW,
    Collection<Vector<Precision, Args...>>& deltaB,
    Collection<Matrix<Precision, Args...>>& deltaW) const noexcept
{
    for(size_type i = 0; i < N; ++i)
    {
        deltaB[i] += DB[i];
        deltaW[i] += DW[i];
    }
}

template <template <typename T, typename...> class Vector, template <typename T, typename...> class Matrix,
          template <class V, class M> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
void Neuro<Vector, Matrix, Linear, Collection, Precision, Args...>::updateNormalize(
    Collection<Vector<Precision, Args...>>& deltaB,
    Collection<Matrix<Precision, Args...>>& deltaW,
    Collection<function::detail::Optimizer<Vector, Precision, Args...>>& OB,
    Collection<function::detail::Optimizer<Matrix, Precision, Args...>>& OW,
    Precision learn_rate,
    size_type batch_size)
{
    for(size_type i = 0; i < N; ++i)
    {
        B[i] -= OB[i].update(deltaB[i].join(1.0 / batch_size)).join(learn_rate);
        W[i] -= OW[i].update(deltaW[i].join(1.0 / batch_size)).join(learn_rate);
    }
}

template <template <typename T, typename...> class Vector, template <typename T, typename...> class Matrix,
          template <class V, class M> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
void Neuro<Vector, Matrix, Linear, Collection, Precision, Args...>::resetDelta(
    Collection<Vector<Precision, Args...>>& deltaB,
    Collection<Matrix<Precision, Args...>>& deltaW) const noexcept
{
    for(size_type i = 0; i < N; ++i)
    {
        deltaB[i].fill(0.0);
        deltaW[i].fill(0.0);
    }
}

template <template <typename T, typename...> class Vector, template <typename T, typename...> class Matrix,
          template <class V, class M> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
void Neuro<Vector, Matrix, Linear, Collection, Precision, Args...>::startDelta(
    Collection<Vector<Precision, Args...>>& deltaB,
    Collection<Matrix<Precision, Args...>>& deltaW) const
{
    for(size_type i = 0; i < N; ++i)
    {
        deltaB[i].resize(B[i].size());
        deltaW[i].resize(W[i].size());
    }
}

template <template <typename T, typename...> class Vector, template <typename T, typename...> class Matrix,
          template <class V, class M> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
void Neuro<Vector, Matrix, Linear, Collection, Precision, Args...>::startOptimizer(
    Collection<function::detail::Optimizer<Vector, Precision, Args...>>& OB,
    Collection<function::detail::Optimizer<Matrix, Precision, Args...>>& OW) const
{
    for(size_type i = 0; i < N; ++i)
    {
        OB[i] = Optimizer1D(O.f1D, B[i].size());
        OW[i] = Optimizer2D(O.f2D, W[i].size());
    }
}

} // namespace trixy

#endif // NEURO_CORE_HPP
