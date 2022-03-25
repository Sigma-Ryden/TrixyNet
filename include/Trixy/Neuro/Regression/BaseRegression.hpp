#ifndef BASE_REGRESSION_HPP
#define BASE_REGRESSION_HPP

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
    typename... Args>
class Regression;

template <class RegressionType,
    template <typename P, typename...> class VectorType,
    template <typename P, typename...> class MatrixType,
    template <typename P, typename...> class LinearType,
    typename PrecisionType,
    typename... Args>
class RegressionRequire;

} // namespace trixy

#endif // BASE_REGRESSION_HPP
