#ifndef NEURO_NETWORK_ALPHA_HPP
#define NEURO_NETWORK_ALPHA_HPP

#include <cstddef> // size_t
#include <initializer_list> // initializer_list
#include <cmath> // fabs
#include <random> // rand

namespace trixy
{

namespace function
{

template <template <typename T, typename...> class Vector, typename... Args>
class Activation
{
public:
        Vector<double, Args...> (*f)(const Vector<double, Args...>&);
        Vector<double, Args...> (*df)(const Vector<double, Args...>&);

    Activation(
        Vector<double, Args...> (*function)(const Vector<double, Args...>&) = nullptr,
        Vector<double, Args...> (*function_derived)(const Vector<double, Args...>&) = nullptr)
        : f(function), df(function_derived) {}
};

template <template <typename T, typename...> class Vector, typename... Args>
class Loss
{
public:
    double (*f)(
        const Vector<double, Args...>&, const Vector<double, Args...>&);
    Vector<double, Args...> (*df)(
        const Vector<double, Args...>&, const Vector<double, Args...>&);

    Loss(
        double (*function)(
            const Vector<double, Args...>&, const Vector<double, Args...>&) = nullptr,
        Vector<double, Args...> (*function_derived)(
            const Vector<double, Args...>&, const Vector<double, Args...>&) = nullptr)
        : f(function), df(function_derived) {}
};

} // namespace function

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
class Neuro
{
private:
    Collection<Matrix<double, Args...>> W;
    Collection<Vector<double, Args...>> B;

    Collection<function::Activation<Vector, Args...>> A;
    function::Loss<Vector, Args...> E;

    std::size_t N;

    Linear<Matrix<double, Args...>, Vector<double, Args...>> li;

public:
    Neuro(const std::initializer_list<std::size_t>& topology);
    Neuro(const Neuro&) = default;
    Neuro(Neuro&&) = default;
    Neuro& operator= (const Neuro&) = default;
    Neuro& operator= (Neuro&&) = default;

    void initializeInnerStruct(double (*generator)());
    void initializeInnerStruct(double (*generator_weight)(), double (*generator_bias)());

    void setActivationFunction(
        const function::Activation<Vector, Args...>& activation_function);
    void setNormalizationFunction(
        const function::Activation<Vector, Args...>& normalization_function);
    void setLossFunction(
        const function::Loss<Vector, Args...>& loss_function);

    void setEachActivationFunction(
        const Collection<function::Activation<Vector, Args...>>& activation_set);

    const Collection<Matrix<double, Args...>>& getInnerWeight() const;
    const Collection<Vector<double, Args...>>& getInnerBias() const;

    const Collection<function::Activation<Vector, Args...>>& getEachActivationFunction() const;
    const function::Loss<Vector, Args...>& getLossFunction() const;

    Vector<double, Args...> feedforward(const Vector<double, Args...>&) const;
    Collection<Vector<double, Args...>> feedforward(const Collection<Vector<double, Args...>>&) const;

    void trainStochastic(
        const Collection<Vector<double, Args...>>& idata,
        const Collection<Vector<double, Args...>>& odata,
        double learn_rate, std::size_t epoch_size);
    void trainBatch(
        const Collection<Vector<double, Args...>>& idata,
        const Collection<Vector<double, Args...>>& odata,
        double learn_rate, std::size_t epoch_size);
    void trainMiniBatch(
        const Collection<Vector<double, Args...>>& idata,
        const Collection<Vector<double, Args...>>& odata,
        double learn_rate, std::size_t epoch_size, std::size_t mini_batch_size);

    double normalAccuracy(
        const Collection<Vector<double, Args...>>& idata,
        const Collection<Vector<double, Args...>>& odata) const;
    double globalAccuracy(
        const Collection<Vector<double, Args...>>& idata,
        const Collection<Vector<double, Args...>>& odata,
        double range_rate) const;
    double fullAccuracy(
        const Collection<Vector<double, Args...>>& idata,
        const Collection<Vector<double, Args...>>& odata,
        double range_rate) const;

    double loss(
        const Collection<Vector<double, Args...>>& idata,
        const Collection<Vector<double, Args...>>& odata) const;
};

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
Neuro<Matrix, Vector, Linear, Collection, Args...>::Neuro(
    const std::initializer_list<std::size_t>& topology)
        : W(topology.size() - 1), B(topology.size() - 1), A(topology.size() - 1), E(), N(topology.size() - 1), li()
{
    auto layer = topology.begin() + 1;
    for(std::size_t i = 0; i < N; ++i)
    {
        W[i] = Matrix<double, Args...>(*(layer - 1), *layer);
        B[i] = Vector<double, Args...>(*layer);
        ++layer;
    }
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
void Neuro<Matrix, Vector, Linear, Collection, Args...>::initializeInnerStruct(
    double (*generator)())
{
    for(std::size_t i = 0; i < N; ++i)
    {
        W[i].fill(generator);
        B[i].fill(generator);
    }
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
void Neuro<Matrix, Vector, Linear, Collection, Args...>::initializeInnerStruct(
    double (*generator_weigth)(), double (*generator_bias)())
{
    for(std::size_t i = 0; i < N; ++i)
        W[i].fill(generator_weigth);

    for(std::size_t i = 0; i < N; ++i)
        B[i].fill(generator_bias);
}


template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
void Neuro<Matrix, Vector, Linear, Collection, Args...>::setActivationFunction(
    const function::Activation<Vector, Args...>& activation_function)
{
    for(std::size_t i = 0; i < N - 1; ++i)
        A[i] = activation_function;
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
void Neuro<Matrix, Vector, Linear, Collection, Args...>::setNormalizationFunction(
    const function::Activation<Vector, Args...>& normalization_function)
{
    A[N - 1] = normalization_function;
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
void Neuro<Matrix, Vector, Linear, Collection, Args...>::setLossFunction(
    const function::Loss<Vector, Args...>& loss_function)
{
    E = loss_function;
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
void Neuro<Matrix, Vector, Linear, Collection, Args...>::setEachActivationFunction(
    const Collection<function::Activation<Vector, Args...>>& activation_set)
{
    for(std::size_t i = 0; i < activation_set.size(); ++i)
        A[i] = activation_set[i];
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
const Collection<Matrix<double, Args...>>&
    Neuro<Matrix, Vector, Linear, Collection, Args...>::getInnerWeight() const
{
    return W;
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
const Collection<Vector<double, Args...>>&
    Neuro<Matrix, Vector, Linear, Collection, Args...>::getInnerBias() const
{
    return B;
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
const Collection<function::Activation<Vector, Args...>>&
    Neuro<Matrix, Vector, Linear, Collection, Args...>::getEachActivationFunction() const
{
    return A;
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
const function::Loss<Vector, Args...>&
    Neuro<Matrix, Vector, Linear, Collection, Args...>::getLossFunction() const
{
    return E;
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
Vector<double, Args...> Neuro<Matrix, Vector, Linear, Collection, Args...>::feedforward(
    const Vector<double, Args...>& vector) const
{
    Vector<double, Args...> y_pred = vector;

    for(std::size_t i = 0; i < N; ++i)
        y_pred = A[i].f(li.dot(y_pred, W[i]) + B[i]);

    return y_pred;
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
Collection<Vector<double, Args...>> Neuro<Matrix, Vector, Linear, Collection, Args...>::feedforward(
    const Collection<Vector<double, Args...>>& idata) const
{
    Collection<Vector<double, Args...>> y_pred(idata.size());

    for(std::size_t i = 0; i < idata.size(); ++i)
        y_pred[i] = feedforward(idata[i]);

    return y_pred;
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
void Neuro<Matrix, Vector, Linear, Collection, Args...>::trainStochastic(
    const Collection<Vector<double, Args...>>& idata,
    const Collection<Vector<double, Args...>>& odata,
    double learn_rate, std::size_t epoch_size)
{
    Collection<Vector<double, Args...>> S(N);
    Collection<Vector<double, Args...>> H(N + 1);

    Collection<Vector<double, Args...>> DH(N);
    Collection<Matrix<double, Args...>> DW(N);
    Collection<Vector<double, Args...>> DB(N);

    Vector<double, Args...> theta;

    std::size_t within = idata.size();
    std::size_t sample;

    for(std::size_t epoch = 0; epoch < epoch_size; ++epoch)
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
            theta = li.dot(DB[i], W[i], 1);
        }
        DB[0] = DH[0].multiply(theta);

        for(std::size_t i = 0; i < N; ++i)
            DW[i] = li.tensordot(DB[i], H[i]);

        for(std::size_t i = 0; i < N; ++i)
        {
            W[i] -= DW[i].join(learn_rate);
            B[i] -= DB[i].join(learn_rate);
        }
    }
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
void Neuro<Matrix, Vector, Linear, Collection, Args...>::trainBatch(
    const Collection<Vector<double, Args...>>& idata,
    const Collection<Vector<double, Args...>>& odata,
    double learn_rate, std::size_t epoch_size)
{
    Collection<Vector<double, Args...>> S(N);
    Collection<Vector<double, Args...>> H(N + 1);

    Collection<Vector<double, Args...>> DH(N);
    Collection<Matrix<double, Args...>> DW(N);
    Collection<Vector<double, Args...>> DB(N);

    Collection<Matrix<double, Args...>> deltaW(N);
    Collection<Vector<double, Args...>> deltaB(N);

    for(std::size_t i = 0; i < N; ++i)
    {
        deltaW[i].resize(W[i].size());
        deltaB[i].resize(B[i].size());
    }

    Vector<double, Args...> theta;

    learn_rate /= idata.size();

    for(std::size_t epoch = 0; epoch < epoch_size; ++epoch)
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
                theta = li.dot(DB[i], W[i], 1);
            }
            DB[0] = DH[0].multiply(theta);

            for(std::size_t i = 0; i < N; ++i)
                DW[i] = li.tensordot(DB[i], H[i]);

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
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
void Neuro<Matrix, Vector, Linear, Collection, Args...>::trainMiniBatch(
    const Collection<Vector<double, Args...>>& idata,
    const Collection<Vector<double, Args...>>& odata,
    double learn_rate, std::size_t epoch_size,
    std::size_t mini_batch_size)
{
    Collection<Vector<double, Args...>> S(N);
    Collection<Vector<double, Args...>> H(N + 1);

    Collection<Vector<double, Args...>> DH(N);
    Collection<Matrix<double, Args...>> DW(N);
    Collection<Vector<double, Args...>> DB(N);

    Collection<Matrix<double, Args...>> deltaW(N);
    Collection<Vector<double, Args...>> deltaB(N);

    for(std::size_t i = 0; i < N; ++i)
    {
        deltaW[i].resize(W[i].size());
        deltaB[i].resize(B[i].size());
    }

    Vector<double, Args...> theta;

    std::size_t sample_begin;
    std::size_t sample_end;
    std::size_t sample_part;

    learn_rate /= mini_batch_size;

    for(std::size_t epoch = 0; epoch < epoch_size; ++epoch)
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
                theta = li.dot(DB[i], W[i], 1);
            }
            DB[0] = DH[0].multiply(theta);

            for(std::size_t i = 0; i < N; ++i)
                DW[i] = li.tensordot(DB[i], H[i]);

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
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
double Neuro<Matrix, Vector, Linear, Collection, Args...>::normalAccuracy(
    const Collection<Vector<double, Args...>>& idata,
    const Collection<Vector<double, Args...>>& odata) const
{
    const Collection<Vector<double, Args...>> pred_out = feedforward(idata);

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
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
double Neuro<Matrix, Vector, Linear, Collection, Args...>::globalAccuracy(
    const Collection<Vector<double, Args...>>& idata,
    const Collection<Vector<double, Args...>>& odata,
    double range_rate) const
{
    const Collection<Vector<double, Args...>> pred_out = feedforward(idata);

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
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
double Neuro<Matrix, Vector, Linear, Collection, Args...>::fullAccuracy(
    const Collection<Vector<double, Args...>>& idata,
    const Collection<Vector<double, Args...>>& odata,
    double range_rate) const
{
    const Collection<Vector<double, Args...>>& pred_out = feedforward(idata);

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
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
double Neuro<Matrix, Vector, Linear, Collection, Args...>::loss(
    const Collection<Vector<double, Args...>>& idata,
    const Collection<Vector<double, Args...>>& odata) const
{
    const Collection<Vector<double, Args...>> pred_out = feedforward(idata);
    double result = 0.0;

    for(std::size_t i = 0; i < odata.size(); ++i)
        result += E.f(odata[i], pred_out[i]);

    return result / odata.size();
}

} // namespace trixy

#endif // NEURO_NETWORK_ALPHA_HPP
