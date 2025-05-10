#ifndef TRIXY_REGRESSION_LINEAR_HPP
#define TRIXY_REGRESSION_LINEAR_HPP

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
using LinearRegression = Regression<TypeSet, RegressionType::Linear>;

TRIXY_REGRESSION_TEMPLATE()
class Regression<TypeSet, RegressionType::Linear> :
    public guard::RegressionRequire<TypeSet, RegressionType::Linear>::type
{
    SERIALIZABLE_ACCESS()

friend train::Training<LinearRegression<TypeSet>>;

public:
    using Vector          = typename TypeSet::Vector;
    using Matrix          = typename TypeSet::Matrix;

    using Linear          = typename TypeSet::Linear;

    using precision_type  = typename TypeSet::precision_type;
    using size_type       = typename TypeSet::size_type;

private:
    Vector W;             ///< Inner weight
    size_type N;          ///< Size of weight vector (same as sample size + 1)

    Linear linear;

public:
    explicit Regression(size_type sample_size = 0)
        : W(sample_size + 1), N(sample_size + 1)
    {
    }

    void init(Vector weight) noexcept
    {
        W.copy(weight);
    }

    void reset(size_type new_sample_size)
    {
        N = new_sample_size + 1;
        W.resize(N);
    }

    precision_type feedforward_sample(const Vector& sample) const
    {
        precision_type result = W(0);

        for (size_type i = 1; i < N; ++i)
        {
            result += sample(i - 1) * W(i);
        }

        return result;
    }

    Vector feedforward(const Matrix& idata) const
    {
        Matrix X(idata.shape().height, N);

        for (size_type i = 0; i < X.shape().height; ++i)
        {
            X(i, 0) = 1.;
            for (size_type j = 1; j < N; ++j)
                X(i, j) = idata(i, j - 1);
        }

        return linear.dot(X, W);
    }

    Vector operator() (const Matrix& idata) const
    {
        return feedforward(idata);
    }

    const Vector& weight() const noexcept { return W; }
    size_type size() const noexcept { return N - 1; }
};

} // namespace trixy

CONDITIONAL_SERIALIZABLE_DECLARATION(trixy::meta::is_linear_regression<S>::value)
SERIALIZABLE_DECLARATION_INIT()

CONDITIONAL_SERIALIZABLE(saveload, regression, trixy::meta::is_linear_regression<S>::value)
    SERIALIZATION
    (
        archive & regression.W & regression.N;
    )
SERIALIZABLE_INIT()

#endif // TRIXY_REGRESSION_LINEAR_HPP
