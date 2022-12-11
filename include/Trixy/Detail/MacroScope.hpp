// This file contains all internal macro definitions
// You MUST include MacroUnscope.hpp at the end of *.hpp to undef all of them
#include <Trixy/Detail/MetaMacro.hpp> // TRIXY_TEMPLATE

#define TRIXY_HAS_FUNCTION_HELPER(name)                                                                 \
    template <typename C, typename = ::trixy::meta::to_void<>>                                          \
    struct has_##name : std::false_type {};								\
    template <typename C>                                                                               \
    struct has_##name<C, ::trixy::meta::to_void<decltype(&C::name)>>                                    \
        : std::true_type {}

#define TRIXY_HAS_TYPE_HELPER(name)                                                                     \
    template <typename T, typename = ::trixy::meta::to_void<>>                                          \
    struct has_##name : std::false_type {};								\
    template <typename T>                                                                               \
    struct has_##_name<T, ::trixy::meta::to_void<typename T::name>> : std::true_type {}

#define TRIXY_FUNCTION_TEMPLATE(...)                                                                    \
    TRIXY_TEMPLATE(typename Precision, TRREQUIRE(std::is_arithmetic<Precision>::value))
