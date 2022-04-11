// This file contains all internal macro definitions
// You MUST include MacroUnscope.hpp at the end of *.hpp to undef all of them

#define ILIQUE_TENSOR_TPL_DECLARATION                                                                   \
    template <template <typename, typename...> class Derived,                                           \
              typename Precision, typename... Pack>

#define ILIQUE_TENSOR_TPL(tensor_type)                                                                  \
    ITensor<tensor_type, Derived, Precision, Pack...>
