#ifndef TRIXY_REGRESSION_BASE_HPP
#define TRIXY_REGRESSION_BASE_HPP

#include <Trixy/Base.hpp> // RegressionType

namespace trixy
{

template <typename TypeSet, typename RegressionType = RegressionType::Polynomial>
class Regression;

namespace guard
{

template <typename TypeSet, typename RegressionType = RegressionType::Polynomial>
struct RegressionRequire;

} // namespace guard

} // namespace trixy

#endif // TRIXY_REGRESSION_BASE_HPP
