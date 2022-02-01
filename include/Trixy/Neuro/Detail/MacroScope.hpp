// This file contains all internal macro definitions
// You MUST include MacroUnscope.hpp at the end of *.hpp to undef all of them

#define TRIXY_HAS_HELPER(type)                                                                          \
    template <typename T> struct has_##type {                                                           \
    private:                                                                                            \
        template <typename U, typename = typename U::type>                                              \
        static int detect(U &&);                                                                        \
        static void detect(...);                                                                        \
    public:                                                                                             \
        static constexpr bool value =                                                                   \
            std::is_integral<decltype(detect(std::declval<T>()))>::value;                               \
    }

#define TRIXY_NET_TPL_DECLARATION                                                                       \
    template <template <typename P, typename...> class VectorType,                                      \
              template <typename P, typename...> class MatrixType,                                      \
              template <typename P> class LinearType,                                                   \
              template <typename...> class ContainerType,                                               \
              typename PrecisionType,                                                                   \
              typename... Args>

#define TRIXY_NET_TPL(network_type)                                                                     \
    TrixyNet<network_type,                                                                              \
             VectorType, MatrixType, LinearType, ContainerType, PrecisionType, void, Args...>

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

#define TRIXY_FUNCTION_TENSOR_TPL_DECLARATION                                                           \
    template <class Tensor,                                                                             \
              typename precision_type = typename Tensor::precision_type,                                \
              typename size_type = typename Tensor::size_type>

#define TRIXY_FUNCTION_TPL_DECLARATION                                                                  \
    template <typename Precision,                                                                       \
        typename std::enable_if<std::is_floating_point<Precision>::value, int>::type = 0>

#define TRIXY_FUNCTION_GENERIC_HELPER(name)                                                             \
    template <class Tensor, typename size_type = typename Tensor::size_type>                            \
    void name(Tensor& buff, const Tensor& tensor) noexcept {                                            \
        for(size_type i = 0; i < buff.size(); ++i)                                                      \
            buff(i) = ::trixy::set::activation::detail::name(tensor(i));                                \
    }                                                                                                   \
    template <class Tensor, typename size_type = typename Tensor::size_type>                            \
    void name##_derived(Tensor& buff, const Tensor& tensor) noexcept {                                  \
        for(size_type i = 0; i < buff.size(); ++i)                                                      \
            buff(i) = ::trixy::set::activation::detail::name##_derived(tensor(i));                      \
    }

#define TRIXY_REGRESSION_TPL_DECLARATION                                                                \
    template <template <typename P, typename...> class VectorType,                                      \
              template <typename P, typename...> class MatrixType,                                      \
              template <typename P> class LinearType,                                                   \
              typename PrecisionType,                                                                   \
              typename... Args>

#define TRIXY_REGRESSION_TPL(regression_type)                                                           \
    Regression<regression_type,                                                                         \
               VectorType, MatrixType, LinearType, PrecisionType, void, Args...>

#define TRIXY_BASE_CLASS_TPL_DECLARATION(class_name)                                                    \
    template <typename Class, typename enable = void>                                                   \
    class class_name;

#define TRIXY_CLASS_TPL_DECLARATION                                                                     \
    template <typename Class>

#define TRIXY_CLASS_TPL(class_name, is_type...)                                                         \
    class_name<Class,                                                                                   \
        typename std::enable_if<::trixy::meta::has_true<Class, is_type>::value>::type>

#define TRIXY_CLASS_TPL_SELECT(is_type)                                                                 \
    template <typename T = Class,                                                                       \
              typename std::enable_if<is_type<T>::value, int>::type = 0>

#define TRIXY_CHECK_TYPE_HELPER(check_for, type)                                                        \
    struct type {                                                                                       \
        template <check_for id>                                                                         \
        using check = ::trixy::meta::select_for<id == check_for::type, type>;                           \
    }

#define CONST_BYTE_CAST(pointer)                                                                        \
    reinterpret_cast<const char*>(pointer)

#define BYTE_CAST(pointer)                                                                              \
    reinterpret_cast<char*>(pointer)
