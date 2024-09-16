// This file contains all internal macro definitions
// You MUST include MacroUnscope.hpp at the end of *.hpp to undef all of them
#ifndef TRIXY_NEURO_FUNCTIONAL_DETAIL_MACRO_SCOPE_HPP
#define TRIXY_NEURO_FUNCTIONAL_DETAIL_MACRO_SCOPE_HPP

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

#endif // TRIXY_NEURO_FUNCTIONAL_DETAIL_MACRO_SCOPE_HPP
