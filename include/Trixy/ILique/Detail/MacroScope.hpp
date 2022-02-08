// This file contains all internal macro definitions
// You MUST include MacroUnscope.hpp at the end of *.hpp to undef all of them

#define ILIQUE_TENSOR_TPL_DECLARATION                                                                   \
    template <template <typename...> class Derived, typename Precision, typename... Args>

#define ILIQUE_VECTOR_TPL                                                                               \
    ILVector<Derived, Precision, Args...>

#define ILIQUE_MATRIX_TPL                                                                               \
    ILMatrix<Derived, Precision, Args...>
