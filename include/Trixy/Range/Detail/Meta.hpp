// This file contains all extern meta function
// For safer use, you MUST only include the Base*.hpp file from lib
#ifndef TRIXY_RANGE_META_HPP
#define TRIXY_RANGE_META_HPP

#include <type_traits> // true_type, false_type

#include <Trixy/Range/Base.hpp>

namespace trixy
{

namespace meta
{

template <typename> struct is_range : std::false_type {};
template <typename T, typename RangeType>
struct is_range<utility::Range<T, RangeType>> : std::true_type {};

} // namespace meta

} // namespace trixy

#endif // TRIXY_RANGE_META_HPP
