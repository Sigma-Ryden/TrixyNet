#ifndef TRIXY_DETAIL_META_MACRO_HPP
#define TRIXY_DETAIL_META_MACRO_HPP

#define TRIXY_TEMPLATE(...)                                                                             \
    template <__VA_ARGS__>

#define TRREQUIRE(...)                                                                                  \
    ::trixy::meta::require<(bool)(__VA_ARGS__)> = 0

#define TRNOEXCEPT_IF(predicate)                                                                        \
    noexcept((predicate))

#define TRWHEN(...)                                                                                     \
    ::trixy::meta::when<(bool)(__VA_ARGS__)>

#define TRWITH(type, ...)                                                                               \
    ::trixy::meta::when<__VA_ARGS__<type>::value>

#endif // TRIXY_DETAIL_META_MACRO_HPP
