// This file contains all internal macro definitions
// You MUST include MacroUnscope.hpp at the end of *.hpp to undef all of them

#define TRIXY_HAS_FUNCTION_HELPER(name)                                                                 \
    template <typename C, typename = ::trixy::meta::to_void<>>                                          \
    struct has_##name : std::false_type {};								\
    template <typename C>                                                                               \
    struct has_##name<C, ::trixy::meta::to_void<decltype(&C::name)>>                                    \
        : std::true_type {}

#define TRIXY_HAS_TYPE_HELPER(name)                                                                     \
    template <typename T, typename = ::trixy::meta::to_void<>>                                          \
    struct has_##name : std::false_type {};								\
    template <typename T>                                                                               \
    struct has_##_name<T, ::trixy::meta::to_void<typename T::name>> : std::true_type {}

#define TRIXY_APPLY_FUNCTION_GENERIC_HELPER(name)                                                       \
    template <class InRange, class OutRange>                                                            \
    void name(InRange& result, const OutRange& input) noexcept {                                        \
        auto it = input.data();                                                                         \
        auto first = result.data();                                                                     \
        auto last = result.data() + result.size();                                                      \
        while (first != last) *first++ = name(*it++);                                                   \
    }

#define TRIXY_FUNCTION_GENERIC_HELPER(name)                                                             \
    TRIXY_APPLY_FUNCTION_GENERIC_HELPER(name)                                                           \
    TRIXY_APPLY_FUNCTION_GENERIC_HELPER(name##_derived)

#define TRIXY_FUNCTION_GENERIC_LOSS_HELPER(name, function_name, derived_function_name)                  \
    template <typename Precision = double>                                                              \
    class name : public ILoss<Precision> {                                                              \
    public:                                                                                             \
        using Base = ILoss<Precision>;                                                                  \
                                                                                                        \
        using typename Base::precision_type;                                                            \
        using typename Base::Range;                                                                     \
                                                                                                        \
        name() : Base() {}                                                                              \
                                                                                                        \
        void f(precision_type& result, const Range y_true, const Range y_pred) noexcept                 \
        { function_name(result, y_true, y_pred); }                                                      \
                                                                                                        \
        void df(Range result, const Range y_true, const Range y_pred) noexcept                          \
        { derived_function_name(result, y_true, y_pred); }                                              \
                                                                                                        \
        void operator() (precision_type& result, const Range y_true, const Range y_pred) noexcept       \
        { function_name(result, y_true, y_pred); }                                                      \
    }

#define TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(name, function_name, derived_function_name)            \
    template <typename Precision = double>                                                              \
    class name : public IActivation<Precision> {                                                        \
    public:                                                                                             \
        using Base = IActivation<Precision>;                                                            \
                                                                                                        \
        using typename Base::precision_type;                                                            \
        using typename Base::Range;                                                                     \
                                                                                                        \
        name() : Base() {}                                                                              \
                                                                                                        \
        void f(Range result, const Range input) noexcept { function_name(result, input); }              \
        void df(Range result, const Range input) noexcept { derived_function_name(result, input); }     \
                                                                                                        \
        void operator() (Range result, const Range input) noexcept { function_name(result, input); }    \
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

#define TRIXY_DEF_OPTIMIZER_HELPER(id_type, T)                                                          \
    struct T {                                                                                          \
        template <id_type id>                                                                           \
        using type = ::trixy::meta::select_for<id == id_type::T, T>;                                    \
    }
