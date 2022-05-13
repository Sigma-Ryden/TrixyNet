// This file contains all internal macro definitions
// You MUST include MacroUnscope.hpp at the end of *.hpp to undef all of them

#define LIQUE_TENSOR_TPL_DECLARATION                                                                    \
    template <typename Precision>

#define LIQUE_TENSOR_TPL(tensor_type)                                                                   \
    Tensor<Precision, tensor_type,                                                                      \
           ::trixy::meta::when<std::is_arithmetic<Precision>::value>>

#define LIQUE_TENSOR_BASE_TYPES                                                                         \
    private:                                                                                            \
        using Base = TensorBase<Precision>;                                                             \
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

#define LIQUE_TENSOR_BASE_FUNCIONS                                                                      \
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
        using Base::operator();

#define LIQUE_TENSOR_BASE_BODY                                                                          \
    LIQUE_TENSOR_BASE_TYPES                                                                             \
    LIQUE_TENSOR_BASE_FUNCIONS
