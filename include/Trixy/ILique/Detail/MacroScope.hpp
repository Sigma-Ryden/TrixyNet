// This file contains all internal macro definitions
// You MUST include MacroUnscope.hpp at the end of *.hpp to undef all of them
#ifndef TRIXY_ILIQUE_DETAIL_MACRO_SCOPE_HPP
#define TRIXY_ILIQUE_DETAIL_MACRO_SCOPE_HPP

#include <Trixy/Detail/MetaMacro.hpp> // TRIXY_TEMPLATE

#define ILIQUE_TENSOR_TEMPLATE(...)                                                                     \
    TRIXY_TEMPLATE(template <typename, typename...> class Derived,                                      \
                   typename Precision, typename... Pack)

#define ILIQUE_TENSOR_TEMPLATE_CLASS(...)                                                               \
    ITensor<__VA_ARGS__, Derived, Precision, Pack...>

#define _ILIQUE_TENSOR_BASE_TYPES(...)                                                                  \
    private:                                                                                            \
        using Base = ITensorBase<Derived, Precision, Pack...>;                                          \
                                                                                                        \
    public:                                                                                             \
        using typename Base::size_type;                                                                 \
        using typename Base::precision_type;                                                            \
        using typename Base::shape_type;                                                                \
                                                                                                        \
        using typename Base::pointer;                                                                   \
        using typename Base::const_pointer;                                                             \
                                                                                                        \
        using typename Base::reference;                                                                 \
        using typename Base::const_reference;

#define _ILIQUE_TENSOR_BASE_FUNCIONS(...)                                                               \
    public:                                                                                             \
        using Base::copy;                                                                               \
        using Base::fill;                                                                               \
        using Base::apply;                                                                              \
                                                                                                        \
        using Base::add;                                                                                \
        using Base::sub;                                                                                \
        using Base::mul;                                                                                \
        using Base::join;                                                                               \
                                                                                                        \
        using Base::data;                                                                               \
        using Base::size;                                                                               \
        using Base::shape;                                                                              \
                                                                                                        \
        using Base::operator();                                                                         \
                                                                                                        \
    protected:                                                                                          \
        using Base::self;

#define ILIQUE_TENSOR_BASE_BODY(...)                                                                    \
    _ILIQUE_TENSOR_BASE_TYPES(__VA_ARGS__)                                                              \
    _ILIQUE_TENSOR_BASE_FUNCIONS(__VA_ARGS__)

#endif // TRIXY_ILIQUE_DETAIL_MACRO_SCOPE_HPP
