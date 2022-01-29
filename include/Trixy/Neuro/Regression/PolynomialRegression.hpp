#ifndef POLYNOMIAL_REGRESSION_HPP
#define POLYNOMIAL_REGRESSION_HPP

#include <cstddef> // size_t

#include "Trixy/Neuro/Regression/BaseRegression.hpp"
#include "Trixy/Neuro/Training/PolynomialRegressionTraining.hpp"

#include "Trixy/Neuro/Detail/TrixyNetMeta.hpp"

#include "Trixy/Neuro/Detail/MacroScope.hpp"

namespace trixy
{

TRIXY_REGRESSION_TPL_DECLARATION
class TRIXY_POLYNOMIAL_REGRESSION_TPL
{
friend train::Training<TRIXY_POLYNOMIAL_REGRESSION_TPL>;

public:
    using Vector          = Tensor1D<Precision, Args...>;
    using Matrix          = Tensor2D<Precision, Args...>;

    using precision_type  = Precision;
    using size_type       = std::size_t;

    using TensorOperation = Linear<Precision>;

private:
    Vector  W;            ///< Inner weight
    size_type N;          ///< Size of weight vector (same as power size + 1)

    TensorOperation linear;

public:
    explicit PolynomialRegression(size_type power);

    void initializeInnerStruct(Vector weight) noexcept;

    void reset(size_type new_power);

    Precision feedforward(Precision sample) const noexcept;
    Vector feedforward(const Vector& idata) const;

    long double loss(const Vector& idata,
                     const Vector& odata) const;

    const Vector& getInnerWeight() const noexcept { return W; }
    Precision getInnerPower() const noexcept { return N; }
};

TRIXY_REGRESSION_TPL_DECLARATION
TRIXY_POLYNOMIAL_REGRESSION_TPL::PolynomialRegression(size_type power)
    : W(power + 1), N(power + 1)
{
}

TRIXY_REGRESSION_TPL_DECLARATION
void TRIXY_POLYNOMIAL_REGRESSION_TPL::initializeInnerStruct(Vector weight) noexcept
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
typename TRIXY_POLYNOMIAL_REGRESSION_TPL::Vector TRIXY_POLYNOMIAL_REGRESSION_TPL::feedforward(
    const Vector& idata) const
{
    Matrix X(idata.size(), N);

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
    const Vector& idata,
    const Vector& odata) const
{
    Vector r = feedforward(idata);
    r.sub(odata);

    return r.dot(r) / static_cast<long double>(r.size());
}

} // namespace trixy

#include "Trixy/Neuro/Detail/MacroUnscope.hpp"

#endif // POLYNOMIAL_REGRESSION_HPP
