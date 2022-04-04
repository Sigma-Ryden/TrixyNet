#ifndef TRIXY_REGRESSION_BASE_HPP
#define TRIXY_REGRESSION_BASE_HPP

namespace trixy
{

struct RegressionType
{
    struct Linear { using type = Linear; };
    struct Polynomial { using type = Polynomial; };
};

template <class RegressionType,
    template <typename P, typename...> class VectorType,
    template <typename P, typename...> class MatrixType,
    template <typename P, typename...> class LinearType,
    typename PrecisionType,
    typename... Pack>
class Regression;

template <class RegressionType,
    template <typename P, typename...> class VectorType,
    template <typename P, typename...> class MatrixType,
    template <typename P, typename...> class LinearType,
    typename PrecisionType,
    typename... Pack>
struct RegressionRequire;

} // namespace trixy

#endif // TRIXY_REGRESSION_BASE_HPP
