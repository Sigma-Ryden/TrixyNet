// This file contains all internal macro definitions
// You MUST include MacroUnscope.hpp at the end of *.hpp to undef all of them

#define TRIXY_HAS_TYPE_HELPER(name)                                                                     \
    template <typename T, typename = ::trixy::meta::void_t<>>                                           \
    struct has_##name : std::false_type {};								\
    template <typename T>                                                                               \
    struct has_##_name<T, ::trixy::meta::void_t<typename T::name>> : std::true_type {}

#define TRIXY_HAS_FUNCTION_HELPER(name)                                                                 \
    template <class T, typename Ret = void, typename... Args>                                           \
    struct has_##name {                                                                                 \
    private:                                                                                            \
        template <class U>                                                                              \
        static auto detect(U*) -> typename std::enable_if<                                              \
            std::is_same<decltype(std::declval<U>().name(std::declval<Args>()...)), Ret>::value,        \
            std::true_type>::type;                                                                      \
        template <class>                                                                                \
        static std::false_type detect(...);                                                             \
                                                                                                        \
    public:                                                                                             \
        static constexpr bool value = decltype(detect<T>(nullptr))::value;                              \
    }

#define TRIXY_FUNCTION_GENERIC_HELPER(name)                                                             \
    template <class Tensor, typename precision_type = typename Tensor::precision_type>                  \
    void name(Tensor& buff, const Tensor& tensor) noexcept {                                            \
        buff.apply(::trixy::set::activation::detail::name<precision_type>, tensor.data());              \
    }                                                                                                   \
    template <class Tensor, typename precision_type = typename Tensor::precision_type>                  \
    void name##_derived(Tensor& buff, const Tensor& tensor) noexcept {                                  \
        buff.apply(::trixy::set::activation::detail::name##_derived<precision_type>, tensor.data());    \
    }

#define TRIXY_FUNCTION_GENERIC_LOSS_HELPER(name, function_name)                                         \
struct name {                                                                                           \
    template <typename Precision, class Target, class Prediction>                                       \
    void operator() (Precision& result, const Target& y_true, const Prediction& y_pred) {               \
        function_name(result, y_true, y_pred);                                                          \
    }                                                                                                   \
}

#define TRIXY_FUNCTION_TENSOR_TPL_DECLARATION                                                           \
    template <class Tensor,                                                                             \
              typename precision_type = typename Tensor::precision_type,                                \
              typename size_type = typename Tensor::size_type>

#define TRIXY_FUNCTION_TPL_DECLARATION                                                                  \
    template <typename Precision,                                                                       \
        ::trixy::meta::as<std::is_arithmetic<Precision>::value> = 0>

#define TRIXY_BASE_CLASS_TPL_DECLARATION(class_name)                                                    \
    template <typename Class, typename enable = void>                                                   \
    class class_name;

#define TRIXY_CLASS_TPL_DECLARATION                                                                     \
    template <typename Class>

#define TRIXY_CLASS_TPL(class_name, is_type...)                                                         \
    class_name<Class,                                                                                   \
        ::trixy::meta::when<::trixy::meta::has_true<Class, is_type>::value>>

#define TRIXY_CLASS_TPL_SELECT(is_type)                                                                 \
    template <typename T = Class, ::trixy::meta::as<is_type<T>::value> = 0>

#define TRIXY_DEF_OPT_HELPER(id_type, T)                                                                \
    struct T {                                                                                          \
        template <id_type id>                                                                           \
        using def = ::trixy::meta::select_for<id == id_type::T, T>;                                     \
    }

#define TRIXY_REQUIRE(conditions...)                                                                    \
    ::trixy::meta::conjunction<conditions>::value
