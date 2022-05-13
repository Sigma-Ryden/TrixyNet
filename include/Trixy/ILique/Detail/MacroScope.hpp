// This file contains all internal macro definitions
// You MUST include MacroUnscope.hpp at the end of *.hpp to undef all of them

#define ILIQUE_TENSOR_TPL_DECLARATION                                                                   \
    template <template <typename, typename...> class Derived,                                           \
              typename Precision, typename... Pack>

#define ILIQUE_TENSOR_TPL(tensor_type)                                                                  \
    ITensor<tensor_type, Derived, Precision, Pack...>

#define ILIQUE_TENSOR_BASE_TYPES                                                                        \
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

#define ILIQUE_TENSOR_BASE_FUNCIONS                                                                     \
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

#define ILIQUE_TENSOR_BASE_BODY                                                                         \
    ILIQUE_TENSOR_BASE_TYPES                                                                            \
    ILIQUE_TENSOR_BASE_FUNCIONS
