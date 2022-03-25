// This file contains all internal macro definitions
// You MUST include MacroUnscope.hpp at the end of *.hpp to undef all of them

#define TRIXY_NET_TPL_DECLARATION                                                                       \
    template <template <typename P, typename...> class VectorType,                                      \
              template <typename P, typename...> class MatrixType,                                      \
              template <typename P, typename...> class LinearType,                                      \
              template <typename T, typename...> class ContainerType,                                   \
              typename PrecisionType,                                                                   \
              typename... Args>

#define TRIXY_NET_TPL(trixy_net_type)                                                                   \
    TrixyNet<trixy_net_type,                                                                            \
             VectorType, MatrixType, LinearType, ContainerType, PrecisionType, Args...>

#define TRIXY_NET_REQUIRE_TPL(trixy_net_type)                                                           \
    TrixyNetRequire<trixy_net_type,                                                                     \
             VectorType, MatrixType, LinearType, ContainerType, PrecisionType, Args...>

#define TRIXY_SERIALIZER_TPL_DECLARATION                                                                \
    template <typename Serializable>

#define TRIXY_SERIALIZER_TPL(is_type)                                                                   \
    Serializer<Serializable,                                                                            \
        typename std::enable_if<is_type<Serializable>::value>::type>

#define TRIXY_FUNCTIONAL_TPL_DECLARATION                                                                \
    template <typename Functionable>

#define TRIXY_FUNCTIONAL_TPL(is_type...)                                                                \
    Functional<Functionable,                                                                            \
        typename std::enable_if<::trixy::meta::has_true<Functionable, is_type>::value>::type>

#define TRIXY_OPTIMIZER_TPL_DECLARATION                                                                 \
    template <class Optimizeriable>

#define TRIXY_OPTIMIZER_TPL(is_type, optimizer_type)                                                    \
    Optimizer<Optimizeriable,                                                                           \
        optimizer_type,                                                                                 \
        typename std::enable_if<is_type<Optimizeriable>::value>::type>

#define TRIXY_TRAINING_TPL_DECLARATION                                                                  \
    template <class Trainable>

#define TRIXY_TRAINING_TPL(is_type)                                                                     \
    Training<Trainable,                                                                                 \
        typename std::enable_if<is_type<Trainable>::value>::type>

#define TRIXY_REGRESSION_TPL_DECLARATION                                                                \
    template <template <typename P, typename...> class VectorType,                                      \
              template <typename P, typename...> class MatrixType,                                      \
              template <typename P, typename...> class LinearType,                                      \
              typename PrecisionType,                                                                   \
              typename... Args>

#define TRIXY_REGRESSION_TPL(regression_type)                                                           \
    Regression<regression_type,                                                                         \
               VectorType, MatrixType, LinearType, PrecisionType, Args...>
