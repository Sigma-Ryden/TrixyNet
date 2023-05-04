#ifndef TRIXY_REGRESSION_POLYNOMIAL_HPP
#define TRIXY_REGRESSION_POLYNOMIAL_HPP

#include <cstddef> // size_t

#include <Trixy/Neuro/Regression/Base.hpp>
#include <Trixy/Neuro/Regression/Require.hpp>

#include <Trixy/Neuro/Training/Base.hpp>

#include <Trixy/Serializer/Core.hpp>

#include <Trixy/Detail/TrixyMeta.hpp>
#include <Trixy/Neuro/Detail/TrixyNetMeta.hpp>

#include <Trixy/Neuro/Detail/MacroScope.hpp>

namespace trixy
{

TRIXY_REGRESSION_TEMPLATE()
using PolynomialRegression = Regression<TypeSet>;

TRIXY_REGRESSION_TEMPLATE()
class Regression<TypeSet> :
    public guard::RegressionRequire<TypeSet>::type
{
    SERIALIZATION_ACCESS()

friend train::Training<PolynomialRegression<TypeSet>>;

public:
    using Vector          = typename TypeSet::Vector;
    using Matrix          = typename TypeSet::Matrix;

    using Linear          = typename TypeSet::Linear;

    using precision_type  = typename TypeSet::precision_type;
    using size_type       = typename TypeSet::size_type;

private:
    Vector W;             ///< Inner weight
    size_type N;          ///< Size of weight vector (same as power size + 1)

    Linear linear;

public:
    explicit Regression(size_type power = 0);

    void init(Vector weight) noexcept;

    void reset(size_type new_power);

    precision_type feedforward(precision_type sample) const noexcept;
    Vector feedforward(const Vector& idata) const;

    Vector operator() (const Vector& idata) const
    { return feedforward(idata); }

    const Vector& weight() const noexcept { return W; }
    size_type power() const noexcept { return N - 1; }
};

TRIXY_REGRESSION_TEMPLATE()
Regression<TypeSet>::Regression(size_type power)
    : W(power + 1), N(power + 1)
{
}

TRIXY_REGRESSION_TEMPLATE()
void Regression<TypeSet>::init(
    Vector weight) noexcept
{
    W.copy(weight);
}

TRIXY_REGRESSION_TEMPLATE()
void Regression<TypeSet>::reset(
    size_type new_power)
{
    N = new_power + 1;
    W.resize(N);
}

TRIXY_REGRESSION_TEMPLATE()
auto Regression<TypeSet>::feedforward(
    precision_type sample) const noexcept -> precision_type
{
    precision_type result = W(0);
    precision_type power  = 1.;

    for (size_type i = 1; i < N; ++i)
    {
        power  *= sample;
        result += power * W(i);
    }

    return result;
}

TRIXY_REGRESSION_TEMPLATE()
auto Regression<TypeSet>::feedforward(
    const Vector& idata) const -> Vector
{
    Matrix X(idata.size(), N);

    precision_type sample;
    precision_type power;

    for (size_type i = 0; i < idata.size(); ++i)
    {
        sample  = idata(i);
        power   = 1.;

        X(i, 0) = 1.;
        for (size_type j = 1; j < N; ++j)
        {
            power  *= sample;
            X(i, j) = power;
        }
    }

    return linear.dot(X, W);
}

} // namespace trixy

CONDITIONAL_SERIALIZATION(SaveLoad, trixy::meta::is_polynomial_regression<T>::value)
{
    archive & self.W & self.N;
}

#endif // TRIXY_REGRESSION_POLYNOMIAL_HPP
