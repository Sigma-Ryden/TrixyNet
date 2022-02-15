// This file contains all internal macro definitions
// You MUST include MacroUnscope.hpp at the end of *.hpp to undef all of them

#define LIQUE_TENSOR_TPL_DECLARATION                                                                    \
    template <typename Precision>

#define LIQUE_TENSOR_TPL(tensor_type)                                                                   \
    Tensor<Precision, tensor_type,                                                                      \
           ::trixy::meta::enable_for_arithmetic_t<Precision>>
