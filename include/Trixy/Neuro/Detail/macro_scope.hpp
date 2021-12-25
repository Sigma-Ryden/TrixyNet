// This file contains all internal macro definitions
// You MUST include macro_unscope.hpp at the end of *.hpp to undef all of them

#define TRIXY_NEURO_HAS_HELPER(type)                                                                    \
    template <typename T> struct has_##type {                                                           \
    private:                                                                                            \
        template <typename U, typename = typename U::type>                                              \
        static int detect(U &&);                                                                        \
        static void detect(...);                                                                        \
    public:                                                                                             \
        static constexpr bool value =                                                                   \
            std::is_integral<decltype(detect(std::declval<T>()))>::value;                               \
    }

#define TRIXY_NEURO_NETWORK_TPL_DECLARATION                                                             \
    template <template <typename, typename...> class Vector,                                            \
              template <typename, typename...> class Matrix,                                            \
              template <template <typename, typename...> class T1,                                      \
                        template <typename, typename...> class T2,                                      \
                        typename P, typename...>                                                        \
              class Linear,                                                                             \
              template <typename Type> class Container,                                                 \
              typename Precision,                                                                       \
              typename... Args>

#define TRIXY_FEED_FORWARD_NEURO_TPL                                                                    \
    FeedForwardNeuro<Vector, Matrix, Linear, Container,                                                 \
                     Precision, Args...>

#define TRIXY_FEED_FORWARD_NEURO_LESS_TPL                                                               \
    FeedForwardNeuroLess<Vector, Matrix, Linear, Container,                                             \
                     Precision, Args...>

#define TRIXY_SERIALIZER_TPL_DECLARATION                                                                \
    template <typename Serializable>

#define TRIXY_SERIALIZER_TPL(is_type)                                                                   \
    Serializer<Serializable,                                                                            \
        typename std::enable_if<is_type<Serializable>::value>::type>

#define TRIXY_FUNCTIONAL_TPL_DECLARATION                                                                \
    template <typename Functionable>

#define TRIXY_FUNCTIONAL_TPL(is_type)                                                                   \
    Functional<Functionable,                                                                            \
        typename std::enable_if<is_type<Functionable>::value>::type>

#define TRIXY_FUNCTION_TENSOR_TPL_DECLARATION                                                           \
    template <template <typename P, typename...> class Tensor, typename Precision, typename... Args>    \

#define TRIXY_FUNCTION_TENSOR1D_TPL_DECLARATION                                                         \
    template <template <typename P, typename...> class Tensor1D, typename Precision, typename... Args>  \

#define TRIXY_FUNCTION_TPL_DECLARATION                                                                  \
    template <typename Precision,                                                                       \
        typename std::enable_if<std::is_floating_point<Precision>::value, int>::type = 0>

#define TRIXY_FUNCTION_GENERIC_HELPER(name)                                                             \
    template <template <typename P, typename...> class Tensor, typename Precision, typename... Args>    \
    void name(                                                                                          \
        Tensor<Precision, Args...>& buff, const Tensor<Precision, Args...>& tensor) noexcept {          \
        buff.apply(detail::name, tensor);                                                               \
    }                                                                                                   \
    template <template <typename P, typename...> class Tensor, typename Precision, typename... Args>    \
    void name##_derived(                                                                                \
        Tensor<Precision, Args...>& buff, const Tensor<Precision, Args...>& tensor) noexcept {          \
        buff.apply(detail::name##_derived, tensor);                                                     \
    }

#define TRIXY_REGRESSION_TPL_DECLARATION                                                                \
    template <template <typename P, typename...> class Vector,                                          \
              template <typename P, typename...> class Matrix,                                          \
              template <template <typename, typename...> class V,                                       \
                        template <typename, typename...> class M,                                       \
                        typename P, typename...>                                                        \
              class Linear,                                                                             \
              typename Precision,                                                                       \
              typename... Args>

#define TRIXY_LINEAR_REGRESSION_TPL                                                                     \
    LinearRegression<Vector, Matrix, Linear, Precision,                                                 \
           typename std::enable_if<std::is_arithmetic<Precision>::value>::type, Args...>

#define TRIXY_POLYNOMIAL_REGRESSION_TPL                                                                 \
    PolynomialRegression<Vector, Matrix, Linear, Precision,                                             \
           typename std::enable_if<std::is_arithmetic<Precision>::value>::type, Args...>
