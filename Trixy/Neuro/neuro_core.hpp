#ifndef NEURO_NETWORK_HPP
#define NEURO_NETWORK_HPP

#include <cstddef> // size_t
#include <initializer_list> // initializer_list
#include <cmath> // fabs
#include <random> // rand

namespace trixy
{

namespace function
{

template <template <typename T, typename...> class Vector, typename Precision, typename... Args>
class Activation
{
public:
    Vector<Precision, Args...> (*f)(const Vector<Precision, Args...>&);
    Vector<Precision, Args...> (*df)(const Vector<Precision, Args...>&);

    Activation(Vector<Precision, Args...> (*function)(const Vector<Precision, Args...>&) = nullptr,
               Vector<Precision, Args...> (*function_derived)(const Vector<Precision, Args...>&) = nullptr)
    : f(function), df(function_derived) {}
};

template <template <typename T, typename...> class Vector, typename Precision, typename... Args>
class Loss
{
public:
    Precision (*f)(const Vector<Precision, Args...>&,
                   const Vector<Precision, Args...>&);
    Vector<Precision, Args...> (*df)(const Vector<Precision, Args...>&,
                                     const Vector<Precision, Args...>&);

    Loss(Precision (*function)(const Vector<Precision, Args...>&,
                               const Vector<Precision, Args...>&) = nullptr,
        Vector<Precision, Args...> (*function_derived)(const Vector<Precision, Args...>&,
                                                       const Vector<Precision, Args...>&) = nullptr)
    : f(function), df(function_derived) {}
};

} // namespace function

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
          template <class M, class V> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
class Neuro
{
private:
    Collection<Matrix<Precision, Args...>> W;
    Collection<Vector<Precision, Args...>> B;

    Collection<function::Activation<Vector, Precision, Args...>> A;
    function::Loss<Vector, Precision, Args...> E;

    std::size_t N;

    Linear<Matrix<Precision, Args...>, Vector<Precision, Args...>> li;

public:
    Neuro(const std::initializer_list<std::size_t>& topology);
    Neuro(const Neuro&) = default;
    Neuro(Neuro&&) = default;
    Neuro& operator= (const Neuro&) = default;
    Neuro& operator= (Neuro&&) = default;

    void initializeInnerStruct(Precision (*generator)());
    void initializeInnerStruct(Precision (*generator_weight)(), Precision (*generator_bias)());

    void setActivationFunction(
        const function::Activation<Vector, Precision, Args...>& activation_function);
    void setNormalizationFunction(
        const function::Activation<Vector, Precision, Args...>& normalization_function);
    void setLossFunction(
        const function::Loss<Vector, Precision, Args...>& loss_function);

    void setEachActivationFunction(
        const Collection<function::Activation<Vector, Precision, Args...>>& activation_set);

    const Collection<Matrix<Precision, Args...>>& getInnerWeight() const;
    const Collection<Vector<Precision, Args...>>& getInnerBias() const;

    const Collection<function::Activation<Vector, Precision, Args...>>& getEachActivationFunction() const;
    const function::Loss<Vector, Precision, Args...>& getLossFunction() const;

    Vector<Precision, Args...> feedforward(const Vector<Precision, Args...>&) const;
    Collection<Vector<Precision, Args...>> feedforward(const Collection<Vector<Precision, Args...>>&) const;

    void trainStochastic(
        const Collection<Vector<Precision, Args...>>& idata,
        const Collection<Vector<Precision, Args...>>& odata,
        Precision learn_rate, std::size_t epoch_scale);
    void trainBatch(
        const Collection<Vector<Precision, Args...>>& idata,
        const Collection<Vector<Precision, Args...>>& odata,
        Precision learn_rate, std::size_t epoch_scale);
    void trainMiniBatch(
        const Collection<Vector<Precision, Args...>>& idata,
        const Collection<Vector<Precision, Args...>>& odata,
        Precision learn_rate, std::size_t epoch_scale,
        std::size_t mini_batch_size);

    double normalAccuracy(
        const Collection<Vector<Precision, Args...>>& idata,
        const Collection<Vector<Precision, Args...>>& odata) const;
    double globalAccuracy(
        const Collection<Vector<Precision, Args...>>& idata,
        const Collection<Vector<Precision, Args...>>& odata,
        Precision range_rate) const;
    double fullAccuracy(
        const Collection<Vector<Precision, Args...>>& idata,
        const Collection<Vector<Precision, Args...>>& odata,
        Precision range_rate) const;

    double loss(
        const Collection<Vector<Precision, Args...>>& idata,
        const Collection<Vector<Precision, Args...>>& odata) const;
};

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
          template <class M, class V> class Linear, template <typename...> class Collection,
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
    for(std::size_t i = 0; i < N; ++i)
    {
        W[i] = Matrix<Precision, Args...>(*(layer - 1), *layer);
        B[i] = Vector<Precision, Args...>(*layer);
        ++layer;
    }
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
          template <class M, class V> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
void Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::initializeInnerStruct(
    Precision (*generator)())
{
    for(std::size_t i = 0; i < N; ++i)
    {
        W[i].fill(generator);
        B[i].fill(generator);
    }
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
          template <class M, class V> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
void Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::initializeInnerStruct(
    Precision (*generator_weigth)(), Precision (*generator_bias)())
{
    for(std::size_t i = 0; i < N; ++i)
    {
        W[i].fill(generator_weigth);
        B[i].fill(generator_bias);
    }
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
          template <class M, class V> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
void Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::setActivationFunction(
    const function::Activation<Vector, Precision, Args...>& activation_function)
{
    for(std::size_t i = 0; i < N - 1; ++i)
        A[i] = activation_function;
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
          template <class M, class V> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
void Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::setNormalizationFunction(
    const function::Activation<Vector, Precision, Args...>& normalization_function)
{
    A[N - 1] = normalization_function;
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
          template <class M, class V> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
void Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::setLossFunction(
    const function::Loss<Vector, Precision, Args...>& loss_function)
{
    E = loss_function;
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
          template <class M, class V> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
void Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::setEachActivationFunction(
    const Collection<function::Activation<Vector, Precision, Args...>>& activation_set)
{
    for(std::size_t i = 0; i < activation_set.size(); ++i)
        A[i] = activation_set[i];
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
          template <class M, class V> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
const Collection<Matrix<Precision, Args...>>&
    Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::getInnerWeight() const
{
    return W;
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
          template <class M, class V> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
const Collection<Vector<Precision, Args...>>&
    Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::getInnerBias() const
{
    return B;
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
          template <class M, class V> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
const Collection<function::Activation<Vector, Precision, Args...>>&
    Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::getEachActivationFunction() const
{
    return A;
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
          template <class M, class V> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
const function::Loss<Vector, Precision, Args...>&
    Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::getLossFunction() const
{
    return E;
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
          template <class M, class V> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
Vector<Precision, Args...> Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::feedforward(
    const Vector<Precision, Args...>& vector) const
{
    Vector<Precision, Args...> y_pred = vector;

    for(std::size_t i = 0; i < N; ++i)
        y_pred = A[i].f(li.dot(y_pred, W[i]) + B[i]);

    return y_pred;
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
          template <class M, class V> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
Collection<Vector<Precision, Args...>> Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::feedforward(
    const Collection<Vector<Precision, Args...>>& idata) const
{
    Collection<Vector<Precision, Args...>> y_pred(idata.size());

    for(std::size_t i = 0; i < idata.size(); ++i)
        y_pred[i] = feedforward(idata[i]);

    return y_pred;
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
          template <class M, class V> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
void Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::trainStochastic(
    const Collection<Vector<Precision, Args...>>& idata,
    const Collection<Vector<Precision, Args...>>& odata,
    Precision learn_rate, std::size_t epoch_scale)
{
    Collection<Vector<Precision, Args...>> S(N);
    Collection<Vector<Precision, Args...>> H(N + 1);

    Collection<Vector<Precision, Args...>> DH(N);
    Collection<Matrix<Precision, Args...>> DW(N);
    Collection<Vector<Precision, Args...>> DB(N);

    Vector<Precision, Args...> theta;

    std::size_t within = idata.size();
    std::size_t sample;

    for(std::size_t n = 0; n < epoch_scale; ++n)
    {
        sample = rand() % within;

        H[0] = idata[sample];
        for(std::size_t i = 0; i < N; ++i)
        {
            S[i]     = li.dot(H[i], W[i]) + B[i];
            H[i + 1] = A[i].f(S[i]);
            DH[i]    = A[i].df(S[i]);
        }

        theta = E.df(odata[sample], H[N]);
        for(std::size_t i = N - 1; i > 0; --i)
        {
            DB[i] = DH[i].multiply(theta);
            DW[i] = li.tensordot(DB[i], H[i]);
            theta = li.dot(DB[i], W[i], true);
        }
        DB[0] = DH[0].multiply(theta);
        DW[0] = li.tensordot(DB[0], H[0]);

        for(std::size_t i = 0; i < N; ++i)
        {
            W[i] -= DW[i].join(learn_rate);
            B[i] -= DB[i].join(learn_rate);
        }
    }
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
          template <class M, class V> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
void Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::trainBatch(
    const Collection<Vector<Precision, Args...>>& idata,
    const Collection<Vector<Precision, Args...>>& odata,
    Precision learn_rate, std::size_t epoch_scale)
{
    Collection<Vector<Precision, Args...>> S(N);
    Collection<Vector<Precision, Args...>> H(N + 1);

    Collection<Vector<Precision, Args...>> DH(N);
    Collection<Matrix<Precision, Args...>> DW(N);
    Collection<Vector<Precision, Args...>> DB(N);

    Collection<Matrix<Precision, Args...>> deltaW(N);
    Collection<Vector<Precision, Args...>> deltaB(N);

    for(std::size_t i = 0; i < N; ++i)
    {
        deltaW[i].resize(W[i].size());
        deltaB[i].resize(B[i].size());
    }

    Vector<Precision, Args...> theta;

    learn_rate /= idata.size();

    for(std::size_t n = 0; n < epoch_scale; ++n)
    {
        for(std::size_t i = 0; i < N; ++i)
        {
            deltaW[i].fill(0.0);
            deltaB[i].fill(0.0);
        }

        for(std::size_t sample = 0; sample < idata.size(); ++sample)
        {
            H[0] = idata[sample];
            for(std::size_t i = 0; i < N; ++i)
            {
                S[i]     = li.dot(H[i], W[i]) + B[i];
                H[i + 1] = A[i].f(S[i]);
                DH[i]    = A[i].df(S[i]);
            }

            theta = E.df(odata[sample], H[N]);
            for(std::size_t i = N - 1; i > 0; --i)
            {
                DB[i] = DH[i].multiply(theta);
                DW[i] = li.tensordot(DB[i], H[i]);
                theta = li.dot(DB[i], W[i], true);
            }
            DB[0] = DH[0].multiply(theta);
            DW[0] = li.tensordot(DB[0], H[0]);

            for(std::size_t i = 0; i < N; ++i)
            {
                deltaW[i] += DW[i];
                deltaB[i] += DB[i];
            }
        }

        for(std::size_t i = 0; i < N; ++i)
        {
            W[i] -= deltaW[i].join(learn_rate);
            B[i] -= deltaB[i].join(learn_rate);
        }
    }
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
          template <class M, class V> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
void Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::trainMiniBatch(
    const Collection<Vector<Precision, Args...>>& idata,
    const Collection<Vector<Precision, Args...>>& odata,
    Precision learn_rate, std::size_t epoch_scale,
    std::size_t mini_batch_size)
{
    Collection<Vector<Precision, Args...>> S(N);
    Collection<Vector<Precision, Args...>> H(N + 1);

    Collection<Vector<Precision, Args...>> DH(N);
    Collection<Matrix<Precision, Args...>> DW(N);
    Collection<Vector<Precision, Args...>> DB(N);

    Collection<Matrix<Precision, Args...>> deltaW(N);
    Collection<Vector<Precision, Args...>> deltaB(N);

    for(std::size_t i = 0; i < N; ++i)
    {
        deltaW[i].resize(W[i].size());
        deltaB[i].resize(B[i].size());
    }

    Vector<Precision, Args...> theta;

    std::size_t sample_begin;
    std::size_t sample_end;
    std::size_t sample_part;

    learn_rate /= mini_batch_size;

    for(std::size_t n = 0; n < epoch_scale; ++n)
    {
        sample_part  = rand() % (idata.size() / mini_batch_size);
        sample_begin = sample_part * mini_batch_size;
        sample_end   = sample_begin + mini_batch_size;

        for(std::size_t i = 0; i < N; ++i)
        {
            deltaW[i].fill(0.0);
            deltaB[i].fill(0.0);
        }

        while(sample_begin < sample_end)
        {
            H[0] = idata[sample_begin];
            for(std::size_t i = 0; i < N; ++i)
            {
                S[i]     = li.dot(H[i], W[i]) + B[i];
                H[i + 1] = A[i].f(S[i]);
                DH[i]    = A[i].df(S[i]);
            }

            theta = E.df(odata[sample_begin], H[N]);
            for(std::size_t i = N - 1; i > 0; --i)
            {
                DB[i] = DH[i].multiply(theta);
                DW[i] = li.tensordot(DB[i], H[i]);
                theta = li.dot(DB[i], W[i], true);
            }
            DB[0] = DH[0].multiply(theta);
            DW[0] = li.tensordot(DB[0], H[0]);

            for(std::size_t i = 0; i < N; ++i)
            {
                deltaW[i] += DW[i];
                deltaB[i] += DB[i];
            }

            ++sample_begin;
        }

        for(std::size_t i = 0; i < N; ++i)
        {
            W[i] -= deltaW[i].join(learn_rate);
            B[i] -= deltaB[i].join(learn_rate);
        }
    }
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
          template <class M, class V> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
double Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::normalAccuracy(
    const Collection<Vector<Precision, Args...>>& idata,
    const Collection<Vector<Precision, Args...>>& odata) const
{
    const Collection<Vector<Precision, Args...>> pred_out = feedforward(idata);

    const std::size_t batch_size = odata.size();
    const std::size_t output_size = odata[0].size();

    double count = 0.0;

    std::size_t max_pred_out;
    std::size_t max_out;

    for(std::size_t i = 0; i < batch_size; ++i)
    {
        max_pred_out = 0;
        max_out = 0;

        for(std::size_t j = 0; j < output_size; ++j)
            if(pred_out[i](max_pred_out) < pred_out[i](j))
                max_pred_out = j;

        for(std::size_t j = 0; j < output_size; ++j)
            if(odata[i](max_out) < odata[i](j))
                max_out = j;

        if(max_pred_out == max_out)
            ++count;
    }

    return count / batch_size;
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
          template <class M, class V> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
double Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::globalAccuracy(
    const Collection<Vector<Precision, Args...>>& idata,
    const Collection<Vector<Precision, Args...>>& odata,
    Precision range_rate) const
{
    const Collection<Vector<Precision, Args...>> pred_out = feedforward(idata);

    const std::size_t batch_size = odata.size();
    const std::size_t output_size = odata[0].size();

    double count = 0.0;

    for(std::size_t i = 0; i < batch_size; ++i)
        for(std::size_t j = 0; j < output_size; ++j)
            if(std::fabs(pred_out[i](j) - odata[i](j)) < range_rate)
                ++count;

    return count / (batch_size * output_size);
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
          template <class M, class V> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
double Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::fullAccuracy(
    const Collection<Vector<Precision, Args...>>& idata,
    const Collection<Vector<Precision, Args...>>& odata,
    Precision range_rate) const
{
    const Collection<Vector<Precision, Args...>>& pred_out = feedforward(idata);

    const std::size_t batch_size = odata.size();
    const std::size_t output_size = odata[0].size();

    double count = 0.0;
    bool answer;

    for(std::size_t i = 0; i < batch_size; ++i)
    {
        answer = true;
        for(std::size_t j = 0; j < output_size; ++j)
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

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
          template <class M, class V> class Linear, template <typename...> class Collection,
          typename Precision, typename... Args>
double Neuro<Matrix, Vector, Linear, Collection, Precision, Args...>::loss(
    const Collection<Vector<Precision, Args...>>& idata,
    const Collection<Vector<Precision, Args...>>& odata) const
{
    const Collection<Vector<Precision, Args...>> pred_out = feedforward(idata);
    double result = 0.0;

    for(std::size_t i = 0; i < odata.size(); ++i)
        result += E.f(odata[i], pred_out[i]);

    return result / odata.size();
}

} // namespace trixy

#endif // NEURO_NETWORK_HPP
