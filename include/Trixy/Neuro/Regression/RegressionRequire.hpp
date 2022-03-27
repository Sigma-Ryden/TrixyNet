#ifndef REGRESSION_REQUIRE_HPP
#define REGRESSION_REQUIRE_HPP

#include "BaseRegression.hpp"

#include "Trixy/Require/PrecisionRequire.hpp"

#include "Trixy/Require/VectorRequire.hpp"
#include "Trixy/Require/MatrixRequire.hpp"

#include "Trixy/Require/LinearRequire.hpp"

#include "Trixy/Neuro/Detail/MacroScope.hpp"

namespace trixy
{

TRIXY_REGRESSION_TPL_DECLARATION
struct TRIXY_REGRESSION_REQUIRE_TPL(RegressionType::Linear)
{
public:
    using type = RegressionType::Linear;

protected:
    using Precision         = PrecisionType;

    using Vector            = VectorType<Precision, Pack...>;
    using Matrix            = MatrixType<Precision, Pack...>;

    using Linear            = LinearType<Precision>;

protected:
    using precision_require = typename PrecisionRequire<Precision>::type;

    using vector_require    = typename VectorRequire<Vector>::type;
    using matrix_require    = typename MatrixRequire<Matrix>::type;

    using linear_require    = typename LinearRequire<Linear>::type;
};

TRIXY_REGRESSION_TPL_DECLARATION
struct TRIXY_REGRESSION_REQUIRE_TPL(RegressionType::Polynomial)
{
public:
    using type = RegressionType::Polynomial;

protected:
    using Precision         = PrecisionType;

    using Vector            = VectorType<Precision, Pack...>;
    using Matrix            = MatrixType<Precision, Pack...>;

    using Linear            = LinearType<Precision>;

protected:
    using precision_require = typename PrecisionRequire<Precision>::type;

    using vector_require    = typename VectorRequire<Vector>::type;
    using matrix_require    = typename MatrixRequire<Matrix>::type;

    using linear_require    = typename LinearRequire<Linear>::type;
};

} // namespace trixy

#include "Trixy/Neuro/Detail/MacroUnscope.hpp"

#endif // REGRESSION_REQUIRE_HPP
