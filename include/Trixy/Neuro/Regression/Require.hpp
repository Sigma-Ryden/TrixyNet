#ifndef TRIXY_REGRESSION_REQUIRE_HPP
#define TRIXY_REGRESSION_REQUIRE_HPP

#include "Base.hpp"

#include "Trixy/Require/Precision.hpp"

#include "Trixy/Require/Vector.hpp"
#include "Trixy/Require/Matrix.hpp"

#include "Trixy/Require/Linear.hpp"

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

#endif // TRIXY_REGRESSION_REQUIRE_HPP
