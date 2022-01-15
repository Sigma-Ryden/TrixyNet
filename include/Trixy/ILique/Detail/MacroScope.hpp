// This file contains all internal macro definitions
// You MUST include MacroUnscope.hpp at the end of *.hpp to undef all of them

#define ILIQUE_VECTOR_TPL_DECLARATION                                                                   \
    template <template <typename P> class Tensor1D, typename Precision>

#define ILIQUE_VECTOR_TPL                                                                               \
    Vector<Tensor1D, Precision,                                                                         \
        ::ilique::meta::use_for_arithmetic_t<Precision>>

#define ILIQUE_MATRIX_TPL_DECLARATION                                                                   \
    template <template <typename P> class Tensor2D, typename Precision>

#define ILIQUE_MATRIX_TPL                                                                               \
    Matrix<Tensor2D, Precision,                                                                         \
        ::ilique::meta::use_for_arithmetic_t<Precision>>
