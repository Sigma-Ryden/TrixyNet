// This file contains all internal macro definitions
// You MUST include MacroUnscope.hpp at the end of *.hpp to undef all of them
#ifndef TRIXY_LIQUE_DETAIL_MACRO_SCOPE_HPP
#define TRIXY_LIQUE_DETAIL_MACRO_SCOPE_HPP

#include <Trixy/Detail/MetaMacro.hpp> // TRIXY_TEMPLATE

#define LIQUE_TENSOR_TEMPLATE(...) TRIXY_TEMPLATE(typename Precision)

#define _LIQUE_TENSOR_BASE_TYPES(...)                                                                   \
    private:                                                                                            \
        using Base = TensorBase<Precision>;                                                             \
                                                                                                        \
    public:                                                                                             \
        using typename Base::size_type;                                                                 \
        using typename Base::precision_type;                                                            \
        using typename Base::value_type;                                                                \
        using typename Base::shape_type;                                                                \
                                                                                                        \
        using typename Base::pointer;                                                                   \
        using typename Base::const_pointer;                                                             \
                                                                                                        \
        using typename Base::reference;                                                                 \
        using typename Base::const_reference;

#define _LIQUE_TENSOR_BASE_FUNCIONS(...)                                                                \
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
        using Base::at;                                                                                 \
        using Base::data;                                                                               \
        using Base::size;                                                                               \
        using Base::shape;                                                                              \
                                                                                                        \
        using Base::operator();

#define LIQUE_TENSOR_BASE_BODY(...)                                                                     \
    _LIQUE_TENSOR_BASE_TYPES(__VA_ARGS__)                                                               \
    _LIQUE_TENSOR_BASE_FUNCIONS(__VA_ARGS__)

#endif // TRIXY_LIQUE_DETAIL_MACRO_SCOPE_HPP
