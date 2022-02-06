#ifndef TRIXY_FUNCTION_DETAIL_HPP
#define TRIXY_FUNCTION_DETAIL_HPP

#include <cmath> // sqrt

#include "Trixy/Detail/TrixyMeta.hpp"

namespace trixy
{

namespace detail
{

template <typename Precision, meta::use_for_arithmetic_t<Precision> = 0>
Precision invert_sqrt(Precision x) noexcept
{
    return 1. / std::sqrt(1e-9 + x);
}

template <typename Pointer>
inline const char* const_byte_cast(Pointer* ptr) noexcept
{
    return reinterpret_cast<const char*>(ptr);
}

template <typename Pointer>
inline char* byte_cast(Pointer* ptr) noexcept
{
    return reinterpret_cast<char*>(ptr);
}

} // namespace detail

} // namespace trixy

#endif // TRIXY_FUNCTION_DETAIL_HPP
