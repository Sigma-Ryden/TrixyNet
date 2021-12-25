#ifndef POLYNOMIAL_REGRESSION_HPP
#define POLYNOMIAL_REGRESSION_HPP

#include <cstddef> // size_t
#include <type_traits> // enable_if, is_arithmetic

#include "Trixy/Neuro/Regression/regression_base.hpp"
#include "Trixy/Neuro/Detail/macro_scope.hpp"

namespace trixy
{

TRIXY_REGRESSION_TPL_DECLARATION
class PolynomialRegression<Vector, Matrix, Linear, Precision,
    typename std::enable_if<std::is_arithmetic<Precision>::value>::type, Args...>
{
public:
    using Tensor1D        = Vector<Precision, Args...>;
    using Tensor2D        = Matrix<Precision, Args...>;

    using TensorOperation = Linear<Vector, Matrix, Precision, Args...>;

    using precision_type  = Precision;
    using size_type       = std::size_t;

private:
    Tensor1D  W;          ///< Inner weight
    size_type N;          ///< Size of weight vector (same as power size + 1)

    TensorOperation linear;

public:
    explicit PolynomialRegression(size_type power);

    void initializeInnerStruct(Tensor1D weight) noexcept;

    void reset(size_type new_power);

    void train(const Tensor1D& idata,
               const Tensor1D& odata);

    Precision feedforward(Precision sample) const noexcept;
    Tensor1D feedforward(const Tensor1D& idata) const;

    long double loss(const Tensor1D& idata,
                     const Tensor1D& odata) const;

    const Tensor1D& getInnerWeight() const noexcept;
    Precision getInnerPower() const noexcept;
};

TRIXY_REGRESSION_TPL_DECLARATION
TRIXY_POLYNOMIAL_REGRESSION_TPL::PolynomialRegression(size_type power)
    : W(power + 1), N(power + 1)
{
}

TRIXY_REGRESSION_TPL_DECLARATION
void TRIXY_POLYNOMIAL_REGRESSION_TPL::initializeInnerStruct(Tensor1D weight) noexcept
{
    W.copy(weight);
}

TRIXY_REGRESSION_TPL_DECLARATION
void TRIXY_POLYNOMIAL_REGRESSION_TPL::reset(size_type new_power)
{
    W.resize(new_power + 1);
    N = new_power + 1;
}

TRIXY_REGRESSION_TPL_DECLARATION
void TRIXY_POLYNOMIAL_REGRESSION_TPL::train(
    const Vector<Precision, Args...>& idata,
    const Vector<Precision, Args...>& odata)
{
    Tensor2D X(idata.size(), N);

    Precision sample;
    Precision power;

    for(size_type i = 0; i < idata.size(); ++i)
    {
        sample = idata(i);
        power  = 1.;

        for(size_type j = 0; j < N; ++j)
        {
            X(i, j) = power;
            power  *= sample;
        }
    }

    Tensor2D X_T = X.transpose();

    // W = (X^T . X)^(-1) . X^T . Y

    linear.dot(W, X_T.dot(X).inverse().dot(X_T), odata);
}

TRIXY_REGRESSION_TPL_DECLARATION
Precision TRIXY_POLYNOMIAL_REGRESSION_TPL::feedforward(Precision sample) const noexcept
{
    Precision result = W(0);
    Precision power  = 1.;

    for(size_type i = 1; i < N; ++i)
    {
        power  *= sample;
        result += power * W(i);
    }

    return result;
}

TRIXY_REGRESSION_TPL_DECLARATION
Vector<Precision, Args...> TRIXY_POLYNOMIAL_REGRESSION_TPL::feedforward(
    const Vector<Precision, Args...>& idata) const
{
    Tensor2D X(idata.size(), N);

    Precision sample;
    Precision power;

    for(size_type i = 0; i < idata.size(); ++i)
    {
        sample  = idata(i);
        power   = 1.;

        X(i, 0) = 1.;
        for(size_type j = 1; j < N; ++j)
        {
            power  *= sample;
            X(i, j) = power;
        }
    }

    return linear.dot(X, W);
}

TRIXY_REGRESSION_TPL_DECLARATION
long double TRIXY_POLYNOMIAL_REGRESSION_TPL::loss(
    const Vector<Precision, Args...>& idata,
    const Vector<Precision, Args...>& odata) const
{
    Tensor1D r = feedforward(idata) - odata;

    return r.dot(r) / static_cast<long double>(r.size());
}

TRIXY_REGRESSION_TPL_DECLARATION
inline const Vector<Precision, Args...>& TRIXY_POLYNOMIAL_REGRESSION_TPL::getInnerWeight() const noexcept
{
    return W;
}

TRIXY_REGRESSION_TPL_DECLARATION
inline Precision TRIXY_POLYNOMIAL_REGRESSION_TPL::getInnerPower() const noexcept
{
    return N - 1;
}

} // namespace trixy

#include "Trixy/Neuro/Detail/macro_unscope.hpp"

#endif // POLYNOMIAL_REGRESSION_HPP
