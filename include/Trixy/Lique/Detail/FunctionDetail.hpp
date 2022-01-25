#ifndef LIQUE_FUNCTION_DETAIL_HPP
#define LIQUE_FUNCTION_DETAIL_HPP

#include "LiqueMeta.hpp"

namespace lique
{

namespace detail
{

template <typename Precision, meta::use_for_arithmetic_t<Precision> = 0>
void copy(Precision* beg, Precision* end, const Precision* src)
{
    while(beg != end) *beg++ = *src++;
}

} // namespace lique

} // namespace detail

#endif // LIQUE_FUNCTION_DETAIL_HPP
