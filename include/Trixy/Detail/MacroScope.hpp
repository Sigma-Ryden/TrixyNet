// This file contains all internal macro definitions
// You MUST include MacroUnscope.hpp at the end of *.hpp to undef all of them

#define TRIXY_HAS_TYPE_HELPER(type)                                                                     \
    template <typename T> struct has_##type {                                                           \
    private:                                                                                            \
        template <typename U, typename = typename U::type>                                              \
        static int detect(U &&);                                                                        \
        static void detect(...);                                                                        \
    public:                                                                                             \
        static constexpr bool value =                                                                   \
            std::is_integral<decltype(detect(std::declval<T>()))>::value;                               \
    }

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

#define TRIXY_FUNCTION_TENSOR_TPL_DECLARATION                                                           \
    template <class Tensor,                                                                             \
              typename precision_type = typename Tensor::precision_type,                                \
              typename size_type = typename Tensor::size_type>

#define TRIXY_FUNCTION_TPL_DECLARATION                                                                  \
    template <typename Precision,                                                                       \
        typename std::enable_if<std::is_arithmetic<Precision>::value, int>::type = 0>

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

#define TRIXY_CHECK_ID_HELPER(id_type, type)                                                            \
    struct type {                                                                                       \
        template <id_type id> using check = ::trixy::meta::select_for<id == id_type::type, type>;       \
    }

#define TRIXY_REQUIRE(conditions...)                                                                    \
    ::trixy::meta::conjunction<conditions>::value

#define TRIXY_ENABLE(conditions...)                                                                     \
    typename std::enable_if<TRIXY_REQUIRE(conditions)>::type
