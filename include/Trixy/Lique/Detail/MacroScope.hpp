// This file contains all internal macro definitions
// You MUST include MacroUnscope.hpp at the end of *.hpp to undef all of them

#define LIQUE_TENSOR_TPL_DECLARATION                                                                    \
    template <typename Precision>

#define LIQUE_TENSOR_TPL(tensor_type)                                                                   \
    Tensor<Precision, tensor_type,                                                                      \
           ::lique::meta::enable_for_arithmetic_t<Precision>>

#define LIQUE_LOCKER_TPL_DECLARATION                                                                    \
    template <class Lockable>

#define LIQUE_LOCKER_TPL(is_type)                                                                       \
    Locker<Lockable,                                                                                    \
           typename std::enable_if<is_type<Lockable>::value>::type>

#define LIQUE_LINEAR_TPL_DECLARATION                                                                    \
    template <template <typename, typename...> class Vector,                                            \
              template <typename, typename...> class Matrix,                                            \
              typename Precision,                                                                       \
              typename... Args>

#define LIQUE_LINEAR_TPL                                                                                \
    Linear<Vector, Matrix, Precision,                                                                   \
           ::lique::meta::enable_for_arithmetic_t<Precision>, Args...>

#define LIQUE_FUNCTION_TPL                                                                              \
    template <typename Precision,                                                                       \
              ::lique::meta::use_for_arithmetic_t<Precision> = 0>
