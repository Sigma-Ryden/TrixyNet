#ifndef BASE_REGRESSION_HPP
#define BASE_REGRESSION_HPP

namespace trixy
{

template <template <typename P, typename...> class Vector,
          template <typename P, typename...> class Matrix,
          template <template <typename, typename...> class V,
                    template <typename, typename...> class M,
                    typename P, typename...>
          class Linear,
          typename Precision,
          typename enable = void,
          typename... Args>
class LinearRegression;

template <template <typename P, typename...> class Vector,
          template <typename P, typename...> class Matrix,
          template <template <typename, typename...> class V,
                    template <typename, typename...> class M,
                    typename P, typename...>
          class Linear,
          typename Precision,
          typename enable = void,
          typename... Args>
class PolynomialRegression;

} // namespace trixy

#endif // BASE_REGRESSION_HPP
