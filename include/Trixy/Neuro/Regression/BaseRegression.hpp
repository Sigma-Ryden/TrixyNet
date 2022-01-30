#ifndef BASE_REGRESSION_HPP
#define BASE_REGRESSION_HPP

namespace trixy
{

template <template <typename P, typename...> class Tensor1D,
          template <typename P, typename...> class Tensor2D,
          template <typename P> class Linear,
          typename Precision,
          typename... Args>
class LinearRegression;

template <template <typename P, typename...> class Tensor1D,
          template <typename P, typename...> class Tensor2D,
          template <typename P> class Linear,
          typename Precision,
          typename... Args>
class PolynomialRegression;

} // namespace trixy

#endif // BASE_REGRESSION_HPP
