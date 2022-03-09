#ifndef LIQUE_FUNCTION_DETAIL_HPP
#define LIQUE_FUNCTION_DETAIL_HPP

#include "LiqueMeta.hpp"

namespace trixy
{

namespace lique
{

namespace detail
{

template <typename Precision,
          trixy::meta::use_for_arithmetic_t<trixy::meta::decay_t<Precision>> = 0>
void copy(Precision* beg, Precision* end, const Precision* src)
{
    while(beg != end) *beg++ = *src++;
}

} // namespace detail

} // namespace lique

} // namespace trixy

#endif // LIQUE_FUNCTION_DETAIL_HPP
