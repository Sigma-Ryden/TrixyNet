#ifndef TRIXY_FUNCTION_LOSS_HPP
#define TRIXY_FUNCTION_LOSS_HPP

#include <cmath> // log, fabs, tanh, cosh

#include <Trixy/Neuro/Functional/Function/Base.hpp>

#include <Trixy/Range/Base.hpp>

#include <Trixy/Neuro/Functional/Function/Detail/MacroScope.hpp>

namespace trixy
{

namespace functional
{

namespace loss
{

template <typename Precision, class Target, class Prediction>
void categorical_cross_entropy(Precision& result, const Target& y_true, const Prediction& y_pred) noexcept
{
    static constexpr Precision epsilon = 1e-9;

    auto target = y_true.data();
    auto end    = y_true.data() + y_true.size();

    auto pred   = y_pred.data();

    result = Precision{};
    while (target != end)
    {
        result -= (*target) * std::log(*pred + epsilon);

        ++target;
        ++pred;
    }
}

template <class Buffer, class Target, class Prediction>
void categorical_cross_entropy_derived(Buffer& result, const Target& y_true, const Prediction& y_pred) noexcept
{
    static constexpr auto epsilon = 1e-9;

    auto first  = result.data();
    auto last   = result.data() + result.size();

    auto target = y_true.data();
    auto pred   = y_pred.data();

    while (first != last)
    {
        *first++ = -(*target) / (*pred + epsilon);

        ++target;
        ++pred;
    }
}

template <typename Precision, class Target, class Prediction>
void mean_squared_error(Precision& result, const Target& y_true, const Prediction& y_pred) noexcept
{
    static Precision f;

    auto target = y_true.data();
    auto end    = y_true.data() + y_true.size();

    auto pred   = y_pred.data();

    result = Precision{};
    while (target != end)
    {
        f = *target - *pred;
        result += f * f;

        ++target;
        ++pred;
    }

    result *= 0.5;
}

template <class Buffer, class Target, class Prediction>
void mean_squared_error_derived(Buffer& result, const Target& y_true, const Prediction& y_pred) noexcept
{
    auto first  = result.data();
    auto last   = result.data() + result.size();

    auto target = y_true.data();
    auto pred   = y_pred.data();

    while (first != last)
    {
        *first++ = *pred - *target;

        ++target;
        ++pred;
    }
}

template <typename Precision, class Target, class Prediction>
void mean_absolute_error(Precision& result, const Target& y_true, const Prediction& y_pred) noexcept
{
    auto target = y_true.data();
    auto end    = y_true.data() + y_true.size();

    auto pred   = y_pred.data();

    result = Precision{};
    while (target != end)
    {
        result += std::fabs(*pred - *target);

        ++target;
        ++pred;
    }
}

template <class Buffer, class Target, class Prediction>
void mean_absolute_error_derived(Buffer& result, const Target& y_true, const Prediction& y_pred) noexcept
{
    auto first  = result.data();
    auto last   = result.data() + result.size();

    auto target = y_true.data();
    auto pred   = y_pred.data();

    while (first != last)
    {
        *first = *target - *pred;
        *first = *first < 0.
                 ? -1.
                 : (*first > 0. ? 1. : 0.);

        ++first;
        ++target;
        ++pred;
    }
}

template <typename Precision, class Target, class Prediction>
void mean_squared_log_error(Precision& result, const Target& y_true, const Prediction& y_pred) noexcept
{
    static Precision f;

    auto target = y_true.data();
    auto end    = y_true.data() + y_true.size();

    auto pred   = y_pred.data();

    result = Precision{};
    while (target != end)
    {
        f = (*pred + 1.) / (*target + 1.);
        f = std::log(f);

        result += f * f;

        ++target;
        ++pred;
    }

    result *= 0.5;
}

template <class Buffer, class Target, class Prediction>
void mean_squared_log_error_derived(Buffer& result, const Target& y_true, const Prediction& y_pred) noexcept
{
    auto first  = result.data();
    auto last   = result.data() + result.size();

    auto target = y_true.data();
    auto pred   = y_pred.data();

    while (first != last)
    {
        *first = *pred + 1.;
        *first = std::log(*first / (*target + 1.)) / (*first);

        ++first;
        ++target;
        ++pred;
    }
}

template <typename Precision, class Target, class Prediction>
void binary_cross_entropy(Precision& result, const Target& y_true, const Prediction& y_pred) noexcept
{
    static constexpr Precision epsilon = 1e-9;

    auto target = y_true.data();
    auto end    = y_true.data() + y_true.size();

    auto pred   = y_pred.data();

    result = Precision{};
    while (target != end)
    {
        result -= (*target) * std::log(*pred + epsilon) +  (1. - *target) * std::log1p(epsilon - *pred);

        ++target;
        ++pred;
    }
}

template <class Buffer, class Target, class Prediction>
void binary_cross_entropy_derived(Buffer& result, const Target& y_true, const Prediction& y_pred) noexcept
{
    static constexpr auto epsilon = 1e-9;
    static constexpr auto alpha   = epsilon - 1.0;

    auto first  = result.data();
    auto last   = result.data() + result.size();

    auto target = y_true.data();
    auto pred   = y_pred.data();

    while (first != last)
    {
        *first++ = (*target - 1.) / (*pred + alpha) - (*target) / (*pred + epsilon);

        ++target;
        ++pred;
    }
}

template <class Buffer, class Target, class Prediction>
void binary_cross_entropy_derived_sigmoid(Buffer& result, const Target& y_true, const Prediction& y_pred) noexcept
{
    auto first  = result.data();
    auto last   = result.data() + result.size();

    auto target = y_true.data();
    auto pred   = y_pred.data();

    while (first != last)
    {
        *first++ = (*target) * (*pred - 1.) + (*pred) * (1. - *target);

        ++target;
        ++pred;
    }
}

template <class Precision, class Target, class Prediction>
void negative_log_likelihood(Precision& result, const Target& y_true, const Prediction& y_pred) noexcept
{
    auto target = y_true.data();
    auto end    = y_true.data() + y_true.size();

    auto pred   = y_pred.data();

    result = Precision{};
    while (target != end)
    {
        result += (*target) * (*pred);

        ++target;
        ++pred;
    }
    // negative logarithm
    result = -std::log(result);
}

template <class Buffer, class Target, class Prediction>
void negative_log_likelihood_derived_softmax(Buffer& result, const Target& y_true, const Prediction& y_pred) noexcept
{
    auto first  = result.data();
    auto last   = result.data() + result.size();

    auto target = y_true.data();
    auto pred   = y_pred.data();

    while (first != last)
    {
        *first++ = *pred - *target;

        ++target;
        ++pred;
    }
}

template <typename Precision, class Target, class Prediction>
void logcosh(Precision& result, const Target& y_true, const Prediction& y_pred) noexcept
{
    auto target = y_true.data();
    auto end    = y_true.data() + y_true.size();

    auto pred   = y_pred.data();

    result = Precision{};
    while (target != end)
    {
        result += std::log(std::cosh(*pred - *target));

        ++target;
        ++pred;
    }
}

template <class Buffer, class Target, class Prediction>
void logcosh_derived(Buffer& result, const Target& y_true, const Prediction& y_pred) noexcept
{
    auto first  = result.data();
    auto last   = result.data() + result.size();

    auto target = y_true.data();
    auto pred   = y_pred.data();

    while (first != last)
    {
        *first++ = std::tanh(*pred - *target);

        ++target;
        ++pred;
    }
}

TRIXY_FUNCTION_GENERIC_LOSS_HELPER(MSE, mean_squared_error, mean_squared_error_derived);
TRIXY_FUNCTION_GENERIC_LOSS_HELPER(MAE, mean_absolute_error, mean_absolute_error_derived);
TRIXY_FUNCTION_GENERIC_LOSS_HELPER(CCE, categorical_cross_entropy, mean_squared_error_derived);
TRIXY_FUNCTION_GENERIC_LOSS_HELPER(BCE, binary_cross_entropy, binary_cross_entropy_derived_sigmoid);
TRIXY_FUNCTION_GENERIC_LOSS_HELPER(MSLE, mean_squared_log_error, mean_squared_log_error_derived);
TRIXY_FUNCTION_GENERIC_LOSS_HELPER(NLL, negative_log_likelihood, negative_log_likelihood_derived_softmax);
TRIXY_FUNCTION_GENERIC_LOSS_HELPER(LC, logcosh, logcosh_derived);

} // namespace loss

} // namespace functional

} // namespace trixy

#endif // TRIXY_FUNCTION_LOSS_HPP
