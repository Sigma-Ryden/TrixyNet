#ifndef FUNCTION_DETAIL_HPP
#define FUNCTION_DETAIL_HPP

#include <cmath> // sqrt

namespace trixy
{

namespace detail
{

template <typename Precision>
Precision invertSqrt(Precision x) noexcept
{
    return 1.0 / std::sqrt(1e-9 + x);
}

} // namespace detail

} // namespace trixy

#endif // FUNCTION_DETAIL_HPP
