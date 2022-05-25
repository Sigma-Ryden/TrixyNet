#ifndef TRIXY_REGRESSION_BASE_HPP
#define TRIXY_REGRESSION_BASE_HPP

#include <Trixy/Base.hpp> // RegressionType

namespace trixy
{

template <typename RegressionType, typename TypeSet>
class Regression;

namespace guard
{

template <class RegressionType, typename TypeSet>
struct RegressionRequire;

} // namespace guard

} // namespace trixy

#endif // TRIXY_REGRESSION_BASE_HPP
