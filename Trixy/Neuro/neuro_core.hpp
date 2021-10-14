#ifndef NEURO_CORE_HPP
#define NEURO_CORE_HPP

#include <cstddef> // size_t
#include <initializer_list> // initializer_list
#include <cmath> // fabs
#include <random> // rand

namespace trixy
{

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
class Neuro
{
private:
    struct ActivationFunction
    {
        Vector<double, Args...> (*f)(const Vector<double, Args...>&);
        Vector<double, Args...> (*df)(const Vector<double, Args...>&);
    };
    struct LossFunction
    {
        double (*f)(
            const Vector<double, Args...>&, const Vector<double, Args...>&);
        Vector<double, Args...> (*df)(
            const Vector<double, Args...>&, const Vector<double, Args...>&);
    };

    Collection<Matrix<double, Args...>> W;
    Collection<Vector<double, Args...>> B;

    std::size_t L;
    std::size_t P;

    Linear<Matrix<double, Args...>, Vector<double, Args...>> li;

    ActivationFunction A;
    ActivationFunction N;
    LossFunction E;

public:
    Neuro(const std::initializer_list<std::size_t>& topology);
    Neuro(
        const Collection<Matrix<double, Args...>>& innerWeigth,
        const Collection<Vector<double, Args...>>& innerBias);

    Neuro(const Neuro&) = default;
    Neuro(Neuro&&) = default;
    Neuro& operator= (const Neuro&) = default;
    Neuro& operator= (Neuro&&) = default;

    void initializeInnerStruct(double (*generator)());
    void initializeInnerStruct(double (*generator_weight)(), double (*generator_bias)());

    void setActivationFunction(
        Vector<double, Args...> (*function)(const Vector<double, Args...>&),
        Vector<double, Args...> (*function_derived)(const Vector<double, Args...>&));
    void setNormalizationFunction(
        Vector<double, Args...> (*function)(const Vector<double, Args...>&),
        Vector<double, Args...> (*function_derived)(const Vector<double, Args...>&));
    void setLossFunction(
        double (*function)(
            const Vector<double, Args...>&, const Vector<double, Args...>&),
        Vector<double, Args...> (*function_derived)(
            const Vector<double, Args...>&, const Vector<double, Args...>&));

    const Collection<Matrix<double, Args...>>& getInnerWeight() const;
    const Collection<Vector<double, Args...>>& getInnerBias() const;

    Vector<double, Args...> feedforward(const Vector<double, Args...>&) const;
    Matrix<double, Args...> feedforward(const Matrix<double, Args...>&) const;

    void trainStochastic(
        const Matrix<double, Args...>& idata, const Matrix<double, Args...>& odata,
        double learn_rate, std::size_t epoch_size);
    void trainBatch(
        const Matrix<double, Args...>& idata, const Matrix<double, Args...>& odata,
        double learn_rate, std::size_t epoch_size);
    void trainMiniBatch(
        const Matrix<double, Args...>& idata, const Matrix<double, Args...>& odata,
        double learn_rate, std::size_t epoch_size, std::size_t mini_batch_size);

    double normalAccuracy(
        const Matrix<double, Args...>& idata,
        const Matrix<double, Args...>& odata) const;
    double globalAccuracy(
        const Matrix<double, Args...>& idata,
        const Matrix<double, Args...>& odata,
        double range_rate) const;
    double fullAccuracy(
        const Matrix<double, Args...>& idata,
        const Matrix<double, Args...>& odata,
        double range_rate) const;

    double loss(
        const Matrix<double, Args...>& idata,
        const Matrix<double, Args...>& odata) const;
};

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
Neuro<Matrix, Vector, Linear, Collection, Args...>::Neuro(
    const std::initializer_list<std::size_t>& topology)
        : W(topology.size() - 1), B(topology.size() - 1), L(topology.size() - 1), P(topology.size() - 2), li()
{
    auto layer = topology.begin() + 1;
    for(std::size_t i = 0; i < L; ++i)
    {
        W[i] = Matrix<double, Args...>(*(layer - 1), *layer);
        B[i] = Vector<double, Args...>(*layer);
        ++layer;
    }
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
Neuro<Matrix, Vector, Linear, Collection, Args...>::Neuro(
    const Collection<Matrix<double, Args...>>& innerWeight,
    const Collection<Vector<double, Args...>>& innerBias)
        : W(innerWeight), B(innerBias), L(innerBias.size()), P(innerBias.size() - 1), li()
{
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
void Neuro<Matrix, Vector, Linear, Collection, Args...>::initializeInnerStruct(
    double (*generator)())
{
    for(std::size_t i = 0; i < L; ++i)
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
    for(std::size_t i = 0; i < L; ++i)
        W[i].fill(generator_weigth);

    for(std::size_t i = 0; i < L; ++i)
        B[i].fill(generator_bias);
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
void Neuro<Matrix, Vector, Linear, Collection, Args...>::setActivationFunction(
   Vector<double, Args...> (*function)(const Vector<double, Args...>&),
   Vector<double, Args...> (*function_derived)(const Vector<double, Args...>&))
{
    A.f = function;
    A.df = function_derived;
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
void Neuro<Matrix, Vector, Linear, Collection, Args...>::setNormalizationFunction(
    Vector<double, Args...> (*function)(const Vector<double, Args...>&),
    Vector<double, Args...> (*function_derived)(const Vector<double, Args...>&))
{
    N.f = function;
    N.df = function_derived;
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
void Neuro<Matrix, Vector, Linear, Collection, Args...>::setLossFunction(
    double (*function)(
        const Vector<double, Args...>&, const Vector<double, Args...>&),
    Vector<double, Args...> (*function_derived)(
        const Vector<double, Args...>&, const Vector<double, Args...>&))
{
    E.f = function;
    E.df = function_derived;
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
Vector<double, Args...> Neuro<Matrix, Vector, Linear, Collection, Args...>::feedforward(
    const Vector<double, Args...>& vector) const
{
    Vector<double, Args...> y_pred = vector;

    for(std::size_t i = 0; i < P; ++i)
        y_pred = A.f(li.dot(y_pred, W[i]) + B[i]);

    return N.f(li.dot(y_pred, W[P]) + B[P]);
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
Matrix<double, Args...> Neuro<Matrix, Vector, Linear, Collection, Args...>::feedforward(
    const Matrix<double, Args...>& in) const
{
    const std::size_t batch_size = in.size().row();
    const std::size_t output_size = W[P].size().col();

    Matrix<double, Args...> y_pred(batch_size, output_size);
    Vector<double, Args...> out;

    for(std::size_t i = 0; i < batch_size; ++i)
    {
        out = feedforward(li.get(in, i));
        for(std::size_t j = 0; j < out.size(); ++j)
            y_pred(i, j) = out(j);
    }

    return y_pred;
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
void Neuro<Matrix, Vector, Linear, Collection, Args...>::trainStochastic(
    const Matrix<double, Args...>& idata, const Matrix<double, Args...>& odata,
    double learn_rate, std::size_t epoch_size)
{
    Collection<Vector<double, Args...>> S(L);
    Collection<Vector<double, Args...>> H(L);

    Collection<Vector<double, Args...>> DH(L);
    Collection<Matrix<double, Args...>> DW(L);
    Collection<Vector<double, Args...>> DB(L);

    Vector<double, Args...> theta;

    std::size_t within = idata.size().row();
    std::size_t sample;

    for(std::size_t epoch = 0; epoch < epoch_size; ++epoch)
    {
        sample = rand() % within;

        H[0] = li.get(idata, sample);
        for(std::size_t i = 0; i < P; ++i)
        {
            S[i]     = li.dot(H[i], W[i]) + B[i];
            H[i + 1] = A.f(S[i]);
            DH[i]    = A.df(S[i]);
        }
        S[P]  = li.dot(H[P], W[P]) + B[P];
        DH[P] = N.df(S[P]);

        theta = E.df(li.get(odata, sample), N.f(S[P]));
        for(std::size_t i = P; i > 0; --i)
        {
            DB[i] = DH[i].multiply(theta);
            theta = li.dot(DB[i], W[i], 1);
        }
        DB[0] = DH[0].multiply(theta);

        for(std::size_t i = 0; i < L; ++i)
            DW[i] = li.tensordot(DB[i], H[i]);

        for(std::size_t i = 0; i < L; ++i)
        {
            W[i] -= DW[i].join(learn_rate);
            B[i] -= DB[i].join(learn_rate);
        }
    }
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
void Neuro<Matrix, Vector, Linear, Collection, Args...>::trainBatch(
    const Matrix<double, Args...> &idata, const Matrix<double, Args...> &odata,
    double learn_rate, std::size_t epoch_size)
{
    Collection<Vector<double, Args...>> S(L);
    Collection<Vector<double, Args...>> H(L);

    Collection<Vector<double, Args...>> DH(L);
    Collection<Matrix<double, Args...>> DW(L);
    Collection<Vector<double, Args...>> DB(L);

    Collection<Matrix<double, Args...>> deltaW(L);
    Collection<Vector<double, Args...>> deltaB(L);

    for(std::size_t i = 0; i < L; ++i)
    {
        deltaW[i].resize(W[i].size());
        deltaB[i].resize(B[i].size());
    }

    Vector<double, Args...> theta;

    learn_rate /= idata.size().row();

    for(std::size_t epoch = 0; epoch < epoch_size; ++epoch)
    {
        for(std::size_t i = 0; i < L; ++i)
        {
            deltaW[i].fill(0.0);
            deltaB[i].fill(0.0);
        }

        for(std::size_t sample = 0; sample < idata.size().row(); ++sample)
        {
            H[0] = li.get(idata, sample);
            for(std::size_t i = 0; i < P; ++i)
            {
                S[i]     = li.dot(H[i], W[i]) + B[i];
                H[i + 1] = A.f(S[i]);
                DH[i]    = A.df(S[i]);
            }
            S[P]  = li.dot(H[P], W[P]) + B[P];
            DH[P] = N.df(S[P]);

            theta = E.df(li.get(odata, sample), N.f(S[P]));
            for(std::size_t i = P; i > 0; --i)
            {
                DB[i] = DH[i].multiply(theta);
                theta = li.dot(DB[i], W[i], 1);
            }
            DB[0] = DH[0].multiply(theta);

            for(std::size_t i = 0; i < L; ++i)
                DW[i] = li.tensordot(DB[i], H[i]);

            for(std::size_t i = 0; i < L; ++i)
            {
                deltaW[i] += DW[i];
                deltaB[i] += DB[i];
            }
        }

        for(std::size_t i = 0; i < L; ++i)
        {
            W[i] -= deltaW[i].join(learn_rate);
            B[i] -= deltaB[i].join(learn_rate);
        }
    }
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
void Neuro<Matrix, Vector, Linear, Collection, Args...>::trainMiniBatch(
    const Matrix<double, Args...> &idata, const Matrix<double, Args...> &odata,
    double learn_rate, std::size_t epoch_size, std::size_t mini_batch_size)
{
    Collection<Vector<double, Args...>> S(L);
    Collection<Vector<double, Args...>> H(L);

    Collection<Vector<double, Args...>> DH(L);
    Collection<Matrix<double, Args...>> DW(L);
    Collection<Vector<double, Args...>> DB(L);

    Collection<Matrix<double, Args...>> deltaW(L);
    Collection<Vector<double, Args...>> deltaB(L);

    for(std::size_t i = 0; i < L; ++i)
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
        sample_part  = rand() % (idata.size().row() / mini_batch_size);
        sample_begin = sample_part * mini_batch_size;
        sample_end   = sample_begin + mini_batch_size;

        for(std::size_t i = 0; i < L; ++i)
        {
            deltaW[i].fill(0.0);
            deltaB[i].fill(0.0);
        }

        while(sample_begin < sample_end)
        {
            H[0] = li.get(idata, sample_begin);
            for(std::size_t i = 0; i < P; ++i)
            {
                S[i]     = li.dot(H[i], W[i]) + B[i];
                H[i + 1] = A.f(S[i]);
                DH[i]    = A.df(S[i]);
            }
            S[P]  = li.dot(H[P], W[P]) + B[P];
            DH[P] = N.df(S[P]);

            theta = E.df(li.get(odata, sample_begin), N.f(S[P]));
            for(std::size_t i = P; i > 0; --i)
            {
                DB[i] = DH[i].multiply(theta);
                theta = li.dot(DB[i], W[i], 1);
            }
            DB[0] = DH[0].multiply(theta);

            for(std::size_t i = 0; i < L; ++i)
                DW[i] = li.tensordot(DB[i], H[i]);

            for(std::size_t i = 0; i < L; ++i)
            {
                deltaW[i] += DW[i];
                deltaB[i] += DB[i];
            }

            ++sample_begin;
        }

        for(std::size_t i = 0; i < L; ++i)
        {
            W[i] -= deltaW[i].join(learn_rate);
            B[i] -= deltaB[i].join(learn_rate);
        }
    }
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
double Neuro<Matrix, Vector, Linear, Collection, Args...>::normalAccuracy(
    const Matrix<double, Args...>& idata, const Matrix<double, Args...>& odata) const
{
    const Matrix<double, Args...> pred_out = feedforward(idata);
    double count = 0.0;

    std::size_t max_pred_out;
    std::size_t max_out;

    for(std::size_t i = 0; i < pred_out.size().row(); ++i)
    {
        max_pred_out = 0;
        max_out = 0;

        for(std::size_t j = 0; j < pred_out.size().col(); ++j)
            if(pred_out(i, max_pred_out) < pred_out(i, j))
                max_pred_out = j;

        for(std::size_t j = 0; j < odata.size().col(); ++j)
            if(odata(i, max_out) < odata(i, j))
                max_out = j;

        if(max_pred_out == max_out)
            ++count;
    }

    return count / odata.size().row();
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
double Neuro<Matrix, Vector, Linear, Collection, Args...>::globalAccuracy(
    const Matrix<double, Args...>& idata, const Matrix<double, Args...>& odata, double range_rate) const
{
    const Matrix<double, Args...> pred_out = feedforward(idata);
    double count = 0.0;

    for(std::size_t i = 0; i < odata.size().row(); ++i)
        for(std::size_t j = 0; j < odata.size().col(); ++j)
            if(std::fabs(pred_out(i, j) - odata(i, j)) < range_rate)
                ++count;

    return count / (odata.size().row() * odata.size().col());
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
double Neuro<Matrix, Vector, Linear, Collection, Args...>::fullAccuracy(
    const Matrix<double, Args...>& idata, const Matrix<double, Args...>& odata, double range_rate) const
{
    const Matrix<double, Args...> pred_out = feedforward(idata);
    double count = 0.0;

    bool answer;
    for(std::size_t i = 0; i < odata.size().row(); ++i)
    {
        answer = true;
        for(std::size_t j = 0; j < odata.size().col(); ++j)
        {
            if(std::fabs(pred_out(i, j) - odata(i, j)) > range_rate)
            {
                answer = false;
                break;
            }
        }
        if(answer) ++count;
    }
    return count / odata.size().row();
}

template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
    template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
double Neuro<Matrix, Vector, Linear, Collection, Args...>::loss(
    const Matrix<double, Args...>& idata, const Matrix<double, Args...>& odata) const
{

    const Matrix<double, Args...> pred = feedforward(idata);
    double result = 0.0;

    for(std::size_t i = 0; i < odata.size().row(); ++i)
        result += E.f(li.get(odata, i), li.get(pred, i));

    return result / odata.size().row();
}

} // namespace trixy

#endif // NEURO_CORE_HPP
