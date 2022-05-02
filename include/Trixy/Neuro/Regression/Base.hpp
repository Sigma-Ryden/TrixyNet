#ifndef TRIXY_REGRESSION_BASE_HPP
#define TRIXY_REGRESSION_BASE_HPP

namespace trixy
{

struct RegressionType
{
    struct Linear { using type = Linear; };
    struct Polynomial { using type = Polynomial; };
};

template <typename RegressionType, typename TypeSet>
class Regression;

template <class RegressionType, typename TypeSet>
struct RegressionRequire;

} // namespace trixy

#endif // TRIXY_REGRESSION_BASE_HPP
