// This file contains all internal macro definitions
// You MUST include MacroUnscope.hpp at the end of *.hpp to undef all of them

#define TRIXY_HAS_TYPE_HELPER(name)                                                                     \
    template <typename T, typename = ::trixy::meta::void_t<>>                                           \
    struct has_##name : std::false_type {};								\
    template <typename T>                                                                               \
    struct has_##_name<T, ::trixy::meta::void_t<typename T::name>> : std::true_type {}

#define TRIXY_FUNCTION_GENERIC_HELPER(name)                                                             \
    template <class Tensor1, class Tensor2,                                                             \
              typename precision_type = typename Tensor1::precision_type>                               \
    void name(Tensor1& buff, const Tensor2& tensor) noexcept {                                          \
        buff.apply(                                                                                     \
            ::trixy::functional::activation::detail::name<precision_type>,                              \
            tensor.data()                                                                               \
        );                                                                                              \
    }                                                                                                   \
    template <class Tensor1, class Tensor2,                                                             \
              typename precision_type = typename Tensor1::precision_type>                               \
    void name##_derived(Tensor1& buff, const Tensor2& tensor) noexcept {                                \
        buff.apply(                                                                                     \
            ::trixy::functional::activation::detail::name##_derived<precision_type>,                    \
            tensor.data()                                                                               \
        );                                                                                              \
    }

#define TRIXY_FUNCTION_GENERIC_LOSS_HELPER(name, function_name, derived_function_name)                  \
struct name {                                                                                           \
    template <typename Precision, class Target, class Prediction>                                       \
    static void f(Precision& result, const Target& y_true, const Prediction& y_pred) {                  \
        function_name(result, y_true, y_pred);                                                          \
    }                                                                                                   \
    template <class Buffer, class Target, class Prediction>                                             \
    static void df(Buffer& buff, const Target& y_true, const Prediction& y_pred) {                      \
        derived_function_name(buff, y_true, y_pred);                                                    \
    }                                                                                                   \
    template <typename Precision, class Target, class Prediction>                                       \
    void operator() (Precision& result, const Target& y_true, const Prediction& y_pred) {               \
        f(result, y_true, y_pred);                                                                      \
    }                                                                                                   \
}

#define TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(name, function_name, derived_function_name)            \
struct name {                                                                                           \
    template <class Tensor1, class Tensor2>                                                             \
    static void f(Tensor1& result, const Tensor2& input) {                                              \
        function_name(result, input);                                                                   \
    }                                                                                                   \
    template <class Tensor1, class Tensor2>                                                             \
    static void df(Tensor1& result, const Tensor2& input) {                                             \
        derived_function_name(result, input);                                                           \
    }                                                                                                   \
    template <class Tensor1, class Tensor2>                                                             \
    void operator() (Tensor1& result, const Tensor2& input) {                                           \
        f(result, input);                                                                               \
    }                                                                                                   \
}

#define TRIXY_FUNCTION_TENSOR_TPL_DECLARATION                                                           \
    template <class Tensor,                                                                             \
              typename precision_type = typename Tensor::precision_type,                                \
              typename size_type = typename Tensor::size_type>

#define TRIXY_FUNCTION_TPL_DECLARATION                                                                  \
    template <typename Precision,                                                                       \
        ::trixy::meta::require<std::is_arithmetic<Precision>::value> = 0>

#define TRIXY_BASE_CLASS_TPL_DECLARATION(class_name)                                                    \
    template <typename Class, typename enable = void>                                                   \
    class class_name;

#define TRIXY_CLASS_TPL_DECLARATION                                                                     \
    template <typename Class>

#define TRIXY_CLASS_TPL(class_name, is_type)                                                            \
    class_name<Class,                                                                                   \
        ::trixy::meta::when<::trixy::meta::has_true<Class, is_type>::value>>

#define TRIXY_CLASS_TPL_SELECT(is_type)                                                                 \
    template <typename T = Class, ::trixy::meta::require<is_type<T>::value> = 0>

#define TRIXY_DEF_OPT_HELPER(id_type, T)                                                                \
    struct T {                                                                                          \
        template <id_type id>                                                                           \
        using def = ::trixy::meta::select_for<id == id_type::T, T>;                                     \
    }

#define TRIXY_REQUIRE(...)                                                                              \
    ::trixy::meta::conjunction<__VA_ARGS__>::value
