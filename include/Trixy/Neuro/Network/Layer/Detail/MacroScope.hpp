// This file contains all internal macro definitions
// You MUST include MacroUnscope.hpp at the end of *.hpp to undef all of them
#ifndef TRIXY_NEURO_NETWORK_LAYER_DETAIL_MACRO_SCOPE_HPP
#define TRIXY_NEURO_NETWORK_LAYER_DETAIL_MACRO_SCOPE_HPP

#define TRIXY_LAYER_BODY(...)                                                                           \
    public:                                                                                             \
        using Base = __VA_ARGS__;                                                                       \
        using typename Base::IOptimizer;                                                                \
    public:                                                                                             \
        template <typename T>                                                                           \
        using Container = typename Base::template Container<T>;                                         \
                                                                                                        \
        using typename Base::Vector;                                                                    \
        using typename Base::Matrix;                                                                    \
        using typename Base::Tensor;                                                                    \
                                                                                                        \
        using typename Base::XVector;                                                                   \
        using typename Base::XMatrix;                                                                   \
        using typename Base::XTensor;                                                                   \
                                                                                                        \
        using typename Base::Linear;                                                                    \
                                                                                                        \
        using typename Base::size_type;                                                                 \
        using typename Base::precision_type;                                                            \
        using typename Base::shape_type;                                                                \
                                                                                                        \
        using typename Base::Generator;                                                                 \
        using typename Base::IActivation;                                                               \
                                                                                                        \
    public:                                                                                             \
        using Identity = functional::activation::Identity<precision_type>;

#endif // TRIXY_NEURO_NETWORK_LAYER_DETAIL_MACRO_SCOPE_HPP
