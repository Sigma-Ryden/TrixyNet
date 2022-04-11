// This file contains all internal macro definitions
// You MUST include MacroUnscope.hpp at the end of *.hpp to undef all of them

#define TRIXY_NET_TPL_DECLARATION                                                                       \
    template <template <typename P, typename...> class VectorType,                                      \
              template <typename P, typename...> class MatrixType,                                      \
              template <typename P, typename...> class LinearType,                                      \
              template <typename T, typename...> class ContainerType,                                   \
              typename PrecisionType,                                                                   \
              typename... Pack>

#define TRIXY_NET_TPL(trixy_net_type)                                                                   \
    TrixyNet<trixy_net_type,                                                                            \
             VectorType, MatrixType, LinearType, ContainerType, PrecisionType, Pack...>

#define TRIXY_NET_REQUIRE_TPL(trixy_net_type)                                                           \
    TrixyNetRequire<trixy_net_type,                                                                     \
             VectorType, MatrixType, LinearType, ContainerType, PrecisionType, Pack...>

#define TRIXY_SERIALIZER_TPL_DECLARATION                                                                \
    template <typename Serializable>

#define TRIXY_SERIALIZER_TPL(is_type)                                                                   \
    Serializer<Serializable,                                                                            \
        ::trixy::meta::when<is_type<Serializable>::value>>

#define TRIXY_FUNCTIONAL_TPL_DECLARATION                                                                \
    template <typename Functionable>

#define TRIXY_FUNCTIONAL_TPL(is_type...)                                                                \
    Functional<Functionable,                                                                            \
        ::trixy::meta::when<::trixy::meta::has_true<Functionable, is_type>::value>>

#define TRIXY_OPTIMIZER_TPL_DECLARATION                                                                 \
    template <class Optimizeriable>

#define TRIXY_OPTIMIZER_TPL(is_type, optimizer_type)                                                    \
    Optimizer<Optimizeriable,                                                                           \
        optimizer_type,                                                                                 \
        ::trixy::meta::when<is_type<Optimizeriable>::value>>

#define TRIXY_TRAINING_TPL_DECLARATION                                                                  \
    template <class Trainable>

#define TRIXY_TRAINING_TPL(is_type)                                                                     \
    Training<Trainable,                                                                                 \
        ::trixy::meta::when<is_type<Trainable>::value>>

#define TRIXY_REGRESSION_TPL_DECLARATION                                                                \
    template <template <typename P, typename...> class VectorType,                                      \
              template <typename P, typename...> class MatrixType,                                      \
              template <typename P, typename...> class LinearType,                                      \
              typename PrecisionType,                                                                   \
              typename... Pack>

#define TRIXY_REGRESSION_TPL(regression_type)                                                           \
    Regression<regression_type,                                                                         \
               VectorType, MatrixType, LinearType, PrecisionType, Pack...>

#define TRIXY_REGRESSION_REQUIRE_TPL(regression_type)                                                   \
    RegressionRequire<regression_type,                                                                  \
             VectorType, MatrixType, LinearType, PrecisionType, Pack...>
