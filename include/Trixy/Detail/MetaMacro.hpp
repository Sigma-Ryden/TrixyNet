#ifndef TRIXY_DETAIL_META_MACRO_HPP
#define TRIXY_DETAIL_META_MACRO_HPP

#define TRREQUIRE(...)                                                                                  \
    ::trixy::meta::require<(bool)(__VA_ARGS__)> = 0

#define TRNOEXCEPT_IF(predicate)                                                                        \
    noexcept((predicate))

#endif // TRIXY_DETAIL_META_MACRO_HPP
