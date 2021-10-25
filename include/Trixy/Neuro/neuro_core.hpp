#ifndef NEURO_CORE_HPP
#define NEURO_CORE_HPP

#include <cstddef> // size_t
#include <initializer_list> // initializer_list
#include <cmath> // fabs

namespace trixy
{

namespace function
{

template <template <typename, typename...> class Vector, typename Precision, typename... Args>
class Activation
{
public:
    using Tensor1D = Vector<Precision, Args...>;

    Tensor1D (*f)(const Tensor1D&);
    Tensor1D (*df)(const Tensor1D&);

    explicit Activation(Tensor1D (*function)(const Tensor1D&) = nullptr,
               Tensor1D (*function_derived)(const Tensor1D&) = nullptr) noexcept
    : f(function), df(function_derived) {}
};

template <template <typename, typename...> class Vector, typename Precision, typename... Args>
class Loss
{
public:
    using Tensor1D = Vector<Precision, Args...>;

    Precision (*f)(const Tensor1D&, const Tensor1D&);
    Tensor1D (*df)(const Tensor1D&, const Tensor1D&);

    explicit Loss(Precision (*function)(const Tensor1D&, const Tensor1D&) = nullptr,
         Tensor1D (*function_derived)(const Tensor1D&, const Tensor1D&) = nullptr) noexcept
    : f(function), df(function_derived) {}
};

} // namespace function

template <template <typename, typename...> class Matrix, template <typename, typename...> class Vector,
          template <class, class> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
class Neuro
{
private:
    using Tensor2D = Matrix<Precision, Args...>;
    using Tensor1D = Vector<Precision, Args...>;

    using ActivationFunction = function::Activation<Vector, Precision, Args...>;
    using LossFunction = function::Loss<Vector, Precision, Args...>;

    using initializer_list_t = std::initializer_list<std::size_t>;
    using GeneratorInteger = int (*)();
    using GeneratorFloat = Precision (*)();
    using size_type = std::size_t;

    Collection<Tensor2D> W;
    Collection<Tensor1D> B;

    Collection<ActivationFunction> A;
    LossFunction E;

    size_type N;

    Linear<Tensor2D, Tensor1D> li;

public:
    Neuro(const initializer_list_t& topology);
    Neuro(const Neuro&) = default;
    Neuro(Neuro&&) noexcept = default;
    Neuro& operator= (const Neuro&) = default;
    Neuro& operator= (Neuro&&) noexcept = default;
    ~Neuro() = default;

    void initializeInnerStruct(GeneratorFloat generator) noexcept;
    void initializeInnerStruct(
        GeneratorFloat generator_weight, GeneratorFloat generator_bias) noexcept;

    void setActivationFunction(const ActivationFunction& activation_function) noexcept;
    void setNormalizationFunction(const ActivationFunction& normalization_function) noexcept;
    void setLossFunction(const LossFunction& loss_function) noexcept;

    void setEachActivationFunction(const Collection<ActivationFunction>& activation_set) noexcept;

    const Collection<Tensor2D>& getInnerWeight() const noexcept;
    const Collection<Tensor1D>& getInnerBias() const noexcept;

    const Collection<ActivationFunction>& getEachActivationFunction() const noexcept;
    const LossFunction& getLossFunction() const noexcept;

    Tensor1D feedforward(const Tensor1D&) const;
    Collection<Tensor1D> feedforward(const Collection<Tensor1D>&) const;

    void trainStochastic(
        const Collection<Tensor1D>& idata, const Collection<Tensor1D>& odata,
        Precision learn_rate, size_type epoch_scale, GeneratorInteger generator);
        void trainBatch(
        const Collection<Tensor1D>& idata, const Collection<Tensor1D>& odata,
        Precision learn_rate, size_type epoch_scale);
    void trainMiniBatch(
        const Collection<Tensor1D>& idata, const Collection<Tensor1D>& odata,
        Precision learn_rate, size_type epoch_scale, size_type mini_batch_size,
        GeneratorInteger generator);

    double accuracy(
        const Collection<Tensor1D>& idata, const Collection<Tensor1D>& odata) const;
    double globalAccuracy(
        const Collection<Tensor1D>& idata, const Collection<Tensor1D>& odata,
        Precision range_rate) const;
    double fullAccuracy(
        const Collection<Tensor1D>& idata, const Collection<Tensor1D>& odata,
        Precision range_rate) const;

    double loss(
        const Collection<Tensor1D>& idata, const Collection<Tensor1D>& odata) const;
};

template <template <typename, typename...> class Matrix, template <typename, typename...> class Vector,
        template <class, class> class Linear, template <typename...> class Collection,
        typename Precision, typename... Args>
Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::Neuro(
    const std::initializer_list<std::size_t>& topology)
        : W(topology.size() - 1)
        , B(topology.size() - 1)
        , A(topology.size() - 1)
        , E()
        , N(topology.size() - 1)
        , li()
{
    auto layer = topology.begin() + 1;
    for(size_type i = 0; i < N; ++i)
    {
        W[i] = Tensor2D(*(layer - 1), *layer);
        B[i] = Tensor1D(*layer);
        ++layer;
    }
}

template <template <typename, typename...> class Matrix, template <typename, typename...> class Vector,
        template <class, class> class Linear, template <typename...> class Collection,
        typename Precision, typename... Args>
void Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::initializeInnerStruct(
    Precision (*generator)()) noexcept
{
    for(size_type i = 0; i < N; ++i)
    {
        W[i].fill(generator);
        B[i].fill(generator);
    }
}

template <template <typename, typename...> class Matrix, template <typename, typename...> class Vector,
        template <class, class> class Linear, template <typename...> class Collection,
        typename Precision, typename... Args>
void Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::initializeInnerStruct(
    Precision (*generator_weight)(), Precision (*generator_bias)()) noexcept
{
    for(size_type i = 0; i < N; ++i)
    {
        W[i].fill(generator_weight);
        B[i].fill(generator_bias);
    }
}

template <template <typename, typename...> class Matrix, template <typename, typename...> class Vector,
        template <class, class> class Linear, template <typename...> class Collection,
        typename Precision, typename... Args>
void Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::setActivationFunction(
    const function::Activation<Vector, Precision, Args...>& activation_function) noexcept
{
    for(size_type i = 0; i < N - 1; ++i)
        A[i] = activation_function;
}

template <template <typename, typename...> class Matrix, template <typename, typename...> class Vector,
        template <class, class> class Linear, template <typename...> class Collection,
        typename Precision, typename... Args>
void Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::setNormalizationFunction(
    const function::Activation<Vector, Precision, Args...>& normalization_function) noexcept
{
    A[N - 1] = normalization_function;
}

template <template <typename, typename...> class Matrix, template <typename, typename...> class Vector,
        template <class, class> class Linear, template <typename...> class Collection,
        typename Precision, typename... Args>
void Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::setLossFunction(
    const function::Loss<Vector, Precision, Args...>& loss_function) noexcept
{
    E = loss_function;
}

template <template <typename, typename...> class Matrix, template <typename, typename...> class Vector,
        template <class, class> class Linear, template <typename...> class Collection,
        typename Precision, typename... Args>
void Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::setEachActivationFunction(
    const Collection<function::Activation<Vector, Precision, Args...>>& activation_set) noexcept
{
    for(size_type i = 0; i < activation_set.size(); ++i)
        A[i] = activation_set[i];
}

template <template <typename, typename...> class Matrix, template <typename, typename...> class Vector,
        template <class, class> class Linear, template <typename...> class Collection,
        typename Precision, typename... Args>
inline const Collection<Matrix<Precision, Args...>>&
    Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::getInnerWeight() const noexcept
{
    return W;
}

template <template <typename, typename...> class Matrix, template <typename, typename...> class Vector,
        template <class, class> class Linear, template <typename...> class Collection,
        typename Precision, typename... Args>
inline const Collection<Vector<Precision, Args...>>&
    Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::getInnerBias() const noexcept
{
    return B;
}

template <template <typename, typename...> class Matrix, template <typename, typename...> class Vector,
        template <class, class> class Linear, template <typename...> class Collection,
        typename Precision, typename... Args>
inline const Collection<function::Activation<Vector, Precision, Args...>>&
    Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::getEachActivationFunction() const noexcept
{
    return A;
}

template <template <typename, typename...> class Matrix, template <typename, typename...> class Vector,
        template <class, class> class Linear, template <typename...> class Collection,
        typename Precision, typename... Args>
inline const function::Loss<Vector, Precision, Args...>&
    Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::getLossFunction() const noexcept
{
    return E;
}

template <template <typename, typename...> class Matrix, template <typename, typename...> class Vector,
        template <class, class> class Linear, template <typename...> class Collection,
        typename Precision, typename... Args>
Vector<Precision, Args...> Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::feedforward(
    const Vector<Precision, Args...>& vector) const
{
    Tensor1D y_pred = vector;

    for(size_type i = 0; i < N; ++i)
        y_pred = A[i].f(li.dot(y_pred, W[i]) + B[i]);

    return y_pred;
}

template <template <typename, typename...> class Matrix, template <typename, typename...> class Vector,
        template <class, class> class Linear, template <typename...> class Collection,
        typename Precision, typename... Args>
Collection<Vector<Precision, Args...>> Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::feedforward(
    const Collection<Vector<Precision, Args...>>& idata) const
{
    Collection<Tensor1D> y_pred(idata.size());

    for(size_type i = 0; i < idata.size(); ++i)
        y_pred[i] = feedforward(idata[i]);

    return y_pred;
}

template <template <typename, typename...> class Matrix, template <typename, typename...> class Vector,
        template <class, class> class Linear, template <typename...> class Collection,
        typename Precision, typename... Args>
void Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::trainStochastic(
    const Collection<Vector<Precision, Args...>>& idata,
    const Collection<Vector<Precision, Args...>>& odata,
    Precision learn_rate, std::size_t epoch_scale, int (*generator)())
{
    Collection<Tensor1D> S(N);
    Collection<Tensor1D> H(N + 1);

    Collection<Tensor1D> DH(N);
    Collection<Tensor2D> DW(N);
    Collection<Tensor1D> DB(N);

    Tensor1D theta;

    size_type within = idata.size();
    size_type sample;

    for(size_type n = 0; n < epoch_scale; ++n)
    {
        sample = generator() % within;

        H[0] = idata[sample];
        for(size_type i = 0; i < N; ++i)
        {
            S[i]     = li.dot(H[i], W[i]) + B[i];
            H[i + 1] = A[i].f(S[i]);
            DH[i]    = A[i].df(S[i]);
        }

        theta = E.df(odata[sample], H[N]);
        for(size_type i = N - 1; i > 0; --i)
        {
            DB[i] = DH[i].multiply(theta);
            DW[i] = li.tensordot(DB[i], H[i]);
            theta = li.dot(DB[i], W[i], true);
        }
        DB[0] = DH[0].multiply(theta);
        DW[0] = li.tensordot(DB[0], H[0]);

        for(size_type i = 0; i < N; ++i)
        {
            W[i] -= DW[i].join(learn_rate);
            B[i] -= DB[i].join(learn_rate);
        }
    }
}

template <template <typename, typename...> class Matrix, template <typename, typename...> class Vector,
        template <class, class> class Linear, template <typename...> class Collection,
        typename Precision, typename... Args>
void Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::trainBatch(
    const Collection<Vector<Precision, Args...>>& idata,
    const Collection<Vector<Precision, Args...>>& odata,
    Precision learn_rate, std::size_t epoch_scale)
{
    Collection<Tensor1D> S(N);
    Collection<Tensor1D> H(N + 1);

    Collection<Tensor1D> DH(N);
    Collection<Tensor2D> DW(N);
    Collection<Tensor1D> DB(N);

    Collection<Tensor2D> deltaW(N);
    Collection<Tensor1D> deltaB(N);

    for(size_type i = 0; i < N; ++i)
    {
        deltaW[i].resize(W[i].size());
        deltaB[i].resize(B[i].size());
    }

    Tensor1D theta;

    learn_rate /= idata.size();

    for(size_type n = 0; n < epoch_scale; ++n)
    {
        for(size_type i = 0; i < N; ++i)
        {
            deltaW[i].fill(0.0);
            deltaB[i].fill(0.0);
        }

        for(size_type sample = 0; sample < idata.size(); ++sample)
        {
            H[0] = idata[sample];
            for(size_type i = 0; i < N; ++i)
            {
                S[i]     = li.dot(H[i], W[i]) + B[i];
                H[i + 1] = A[i].f(S[i]);
                DH[i]    = A[i].df(S[i]);
            }

            theta = E.df(odata[sample], H[N]);
            for(size_type i = N - 1; i > 0; --i)
            {
                DB[i] = DH[i].multiply(theta);
                DW[i] = li.tensordot(DB[i], H[i]);
                theta = li.dot(DB[i], W[i], true);
            }
            DB[0] = DH[0].multiply(theta);
            DW[0] = li.tensordot(DB[0], H[0]);

            for(size_type i = 0; i < N; ++i)
            {
                deltaW[i] += DW[i];
                deltaB[i] += DB[i];
            }
        }

        for(size_type i = 0; i < N; ++i)
        {
            W[i] -= deltaW[i].join(learn_rate);
            B[i] -= deltaB[i].join(learn_rate);
        }
    }
}

template <template <typename, typename...> class Matrix, template <typename, typename...> class Vector,
        template <class, class> class Linear, template <typename...> class Collection,
        typename Precision, typename... Args>
void Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::trainMiniBatch(
    const Collection<Vector<Precision, Args...>>& idata,
    const Collection<Vector<Precision, Args...>>& odata,
    Precision learn_rate, std::size_t epoch_scale,
    std::size_t mini_batch_size, int (*generator)())
{
    Collection<Tensor1D> S(N);
    Collection<Tensor1D> H(N + 1);

    Collection<Tensor1D> DH(N);
    Collection<Tensor2D> DW(N);
    Collection<Tensor1D> DB(N);

    Collection<Tensor2D> deltaW(N);
    Collection<Tensor1D> deltaB(N);

    for(size_type i = 0; i < N; ++i)
    {
        deltaW[i].resize(W[i].size());
        deltaB[i].resize(B[i].size());
    }

    Tensor1D theta;

    size_type sample_begin;
    size_type sample_end;
    size_type sample_part;

    learn_rate /= mini_batch_size;

    for(size_type n = 0; n < epoch_scale; ++n)
    {
        sample_part  = generator() % (idata.size() / mini_batch_size);
        sample_begin = sample_part * mini_batch_size;
        sample_end   = sample_begin + mini_batch_size;

        for(size_type i = 0; i < N; ++i)
        {
            deltaW[i].fill(0.0);
            deltaB[i].fill(0.0);
        }

        while(sample_begin < sample_end)
        {
            H[0] = idata[sample_begin];
            for(size_type i = 0; i < N; ++i)
            {
                S[i]     = li.dot(H[i], W[i]) + B[i];
                H[i + 1] = A[i].f(S[i]);
                DH[i]    = A[i].df(S[i]);
            }

            theta = E.df(odata[sample_begin], H[N]);
            for(size_type i = N - 1; i > 0; --i)
            {
                DB[i] = DH[i].multiply(theta);
                DW[i] = li.tensordot(DB[i], H[i]);
                theta = li.dot(DB[i], W[i], true);
            }
            DB[0] = DH[0].multiply(theta);
            DW[0] = li.tensordot(DB[0], H[0]);

            for(size_type i = 0; i < N; ++i)
            {
                deltaW[i] += DW[i];
                deltaB[i] += DB[i];
            }

            ++sample_begin;
        }

        for(size_type i = 0; i < N; ++i)
        {
            W[i] -= deltaW[i].join(learn_rate);
            B[i] -= deltaB[i].join(learn_rate);
        }
    }
}

template <template <typename, typename...> class Matrix, template <typename, typename...> class Vector,
        template <class, class> class Linear, template <typename...> class Collection,
        typename Precision, typename... Args>
double Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::accuracy(
    const Collection<Vector<Precision, Args...>>& idata,
    const Collection<Vector<Precision, Args...>>& odata) const
{
    const Collection<Tensor1D> pred_out = feedforward(idata);

    const size_type batch_size = odata.size();
    const size_type output_size = odata[0].size();

    double count = 0.0;

    size_type max_pred_out;
    size_type max_out;

    for(size_type i = 0; i < batch_size; ++i)
    {
        max_pred_out = 0;
        max_out = 0;

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

template <template <typename, typename...> class Matrix, template <typename, typename...> class Vector,
        template <class, class> class Linear, template <typename...> class Collection,
        typename Precision, typename... Args>
double Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::globalAccuracy(
    const Collection<Vector<Precision, Args...>>& idata,
    const Collection<Vector<Precision, Args...>>& odata,
    Precision range_rate) const
{
    const Collection<Tensor1D> pred_out = feedforward(idata);

    const size_type batch_size = odata.size();
    const size_type output_size = odata[0].size();

    double count = 0.0;

    for(size_type i = 0; i < batch_size; ++i)
        for(size_type j = 0; j < output_size; ++j)
            if(std::fabs(pred_out[i](j) - odata[i](j)) < range_rate)
                ++count;

    return count / (batch_size * output_size);
}

template <template <typename, typename...> class Matrix, template <typename, typename...> class Vector,
        template <class, class> class Linear, template <typename...> class Collection,
        typename Precision, typename... Args>
double Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::fullAccuracy(
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

template <template <typename, typename...> class Matrix, template <typename, typename...> class Vector,
        template <class, class> class Linear, template <typename...> class Collection,
        typename Precision, typename... Args>
double Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::loss(
    const Collection<Vector<Precision, Args...>>& idata,
    const Collection<Vector<Precision, Args...>>& odata) const
{
    const Collection<Tensor1D> pred_out = feedforward(idata);
    double result = 0.0;

    for(size_type i = 0; i < odata.size(); ++i)
        result += E.f(odata[i], pred_out[i]);

    return result / odata.size();
}

} // namespace trixy

#endif // NEURO_CORE_HPP
