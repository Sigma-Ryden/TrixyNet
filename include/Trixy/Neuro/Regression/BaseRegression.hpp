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
          template <typename P, typename...> class Tensor1D,
          template <typename P, typename...> class Tensor2D,
          template <typename P> class Linear,
          typename Precision,
          typename... Args>
class Regression;

} // namespace trixy

#endif // BASE_REGRESSION_HPP
