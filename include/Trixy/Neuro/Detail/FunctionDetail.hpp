#ifndef TRIXY_FUNCTION_DETAIL_HPP
#define TRIXY_FUNCTION_DETAIL_HPP

#include <cmath> // sqrt

#include "Trixy/Neuro/Detail/TrixyNetMeta.hpp"

namespace trixy
{

namespace detail
{

template <typename Precision, meta::use_for_arithmetic_t<Precision> = 0>
Precision invert_sqrt(Precision x) noexcept
{
    return 1. / std::sqrt(1e-9 + x);
}

} // namespace detail

} // namespace trixy

#endif // TRIXY_FUNCTION_DETAIL_HPP
