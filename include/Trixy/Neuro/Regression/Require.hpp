#ifndef TRIXY_REGRESSION_REQUIRE_HPP
#define TRIXY_REGRESSION_REQUIRE_HPP

#include <Trixy/Neuro/Regression/Base.hpp>

#include <Trixy/Require/Core.hpp>

#include <Trixy/Neuro/Detail/MacroScope.hpp>

namespace trixy
{

namespace guard
{

TRIXY_REGRESSION_TEMPLATE()
struct RegressionRequire<TypeSet, RegressionType::Linear>
{
public:
    using type = RegressionType::Linear;

protected:
    using precision_type    = typename TypeSet::precision_type;

    using Vector            = typename TypeSet::Vector;
    using Matrix            = typename TypeSet::Matrix;

    using Linear            = typename TypeSet::Linear;

protected:
    using require_precision = typename PrecisionRequire<precision_type>::type;

    using require_vector    = typename VectorRequire<Vector>::type;
    using require_matrix    = typename MatrixRequire<Matrix>::type;

    using require_linear    = typename LinearRequire<Linear>::type;
};

TRIXY_REGRESSION_TEMPLATE()
struct RegressionRequire<TypeSet>
{
public:
    using type = RegressionType::Polynomial;

protected:
    using precision_type    = typename TypeSet::precision_type;

    using Vector            = typename TypeSet::Vector;
    using Matrix            = typename TypeSet::Matrix;

    using Linear            = typename TypeSet::Linear;

protected:
    using require_precision = typename PrecisionRequire<precision_type>::type;

    using require_vector    = typename VectorRequire<Vector>::type;
    using require_matrix    = typename MatrixRequire<Matrix>::type;

    using require_linear    = typename LinearRequire<Linear>::type;
};

} // namespace guard

} // namespace trixy

#endif // TRIXY_REGRESSION_REQUIRE_HPP
