#ifndef LOSS_FUNCTION_HPP
#define LOSS_FUNCTION_HPP

#include <cstddef> // size_t
#include <cmath> // log, fabs, tanh, cosh

#include "Trixy/Neuro/Detail/TrixyNetMeta.hpp"

#include "Trixy/Neuro/Detail/MacroScope.hpp"

namespace trixy
{

namespace set
{

namespace loss
{

TRIXY_FUNCTION_TENSOR1D_TPL_DECLARATION
void categorical_cross_entropy(
    Precision& result,
    const Tensor1D<Precision, Args...>& y_true,
    const Tensor1D<Precision, Args...>& y_pred) noexcept
{
    static constexpr Precision epsilon = 1e-9;

    result = 0.;
    for(std::size_t i = 0; i < y_true.size(); ++i)
        result -= y_true(i) * std::log(y_pred(i) + epsilon);
}

TRIXY_FUNCTION_TENSOR1D_TPL_DECLARATION
void categorical_cross_entropy_derived(
    Tensor1D<Precision, Args...>& buff,
    const Tensor1D<Precision, Args...>& y_true,
    const Tensor1D<Precision, Args...>& y_pred) noexcept
{
    static constexpr Precision epsilon = 1e-9;

    for(std::size_t i = 0; i < y_true.size(); ++i)
        buff(i) = - y_true(i) / (y_pred(i) + epsilon);
}

TRIXY_FUNCTION_TENSOR1D_TPL_DECLARATION
void categorical_cross_entropy_derived_softmax(
    Tensor1D<Precision, Args...>& buff,
    const Tensor1D<Precision, Args...>& y_true,
    const Tensor1D<Precision, Args...>& y_pred) noexcept
{
    for(std::size_t i = 0; i < y_true.size(); ++i)
        buff(i) = y_pred(i) - y_true(i);
}

TRIXY_FUNCTION_TENSOR1D_TPL_DECLARATION
void mean_squared_error(
    Precision& result,
    const Tensor1D<Precision, Args...>& y_true,
    const Tensor1D<Precision, Args...>& y_pred) noexcept
{
    static Precision f;

    result = 0.;
    for(std::size_t i = 0; i < y_true.size(); ++i)
    {
        f = y_true(i) - y_pred(i);
        result += f * f;
    }

   result *= 0.5;
}

TRIXY_FUNCTION_TENSOR1D_TPL_DECLARATION
void mean_squared_error_derived(
    Tensor1D<Precision, Args...>& buff,
    const Tensor1D<Precision, Args...>& y_true,
    const Tensor1D<Precision, Args...>& y_pred) noexcept
{
    for(std::size_t i = 0; i < y_true.size(); ++i)
        buff(i) = y_pred(i) - y_true(i);
}

TRIXY_FUNCTION_TENSOR1D_TPL_DECLARATION
void mean_absolute_error(
    Precision& result,
    const Tensor1D<Precision, Args...>& y_true,
    const Tensor1D<Precision, Args...>& y_pred) noexcept
{
    result = 0.;
    for(std::size_t i = 0; i < y_true.size(); ++i)
        result += std::fabs(y_true(i) - y_pred(i));
}

TRIXY_FUNCTION_TENSOR1D_TPL_DECLARATION
void mean_absolute_error_derived(
    Tensor1D<Precision, Args...>& buff,
    const Tensor1D<Precision, Args...>& y_true,
    const Tensor1D<Precision, Args...>& y_pred) noexcept
{
    static Precision diff;

    for(std::size_t i = 0; i < y_true.size(); ++i)
    {
        diff = y_true(i) - y_pred(i);
        buff(i) = diff < 0.
                  ? -1.
                  : diff > 0. ? 1. : 0.;
    }
}

TRIXY_FUNCTION_TENSOR1D_TPL_DECLARATION
void mean_squared_log_error(
    Precision& result,
    const Tensor1D<Precision, Args...>& y_true,
    const Tensor1D<Precision, Args...>& y_pred) noexcept
{
    static Precision f;

    result = 0.;
    for(std::size_t i = 0; i < y_true.size(); ++i)
    {
        f = (y_pred(i) + 1.) / (y_true(i) + 1.);
        f = std::log(f);
        result += f * f;
    }

    result *= 0.5;
}

TRIXY_FUNCTION_TENSOR1D_TPL_DECLARATION
void mean_squared_log_error_derived(
    Tensor1D<Precision, Args...>& buff,
    const Tensor1D<Precision, Args...>& y_true,
    const Tensor1D<Precision, Args...>& y_pred) noexcept
{
    for(std::size_t i = 0; i < y_true.size(); ++i)
    {
        buff(i) = y_pred(i) + 1.;
        buff(i) = std::log(buff(i) / (y_true(i) + 1.)) / buff(i);
    }
}

TRIXY_FUNCTION_TENSOR1D_TPL_DECLARATION
void binary_cross_entropy(
    Precision& result,
    const Tensor1D<Precision, Args...>& y_true,
    const Tensor1D<Precision, Args...>& y_pred) noexcept
{
    static constexpr Precision epsilon = 1e-9;
    result = 0.;
    for(std::size_t i = 0; i < y_true.size(); ++i)
        result -= y_true(i) * std::log(y_pred(i) + epsilon)
                  + (1. - y_true(i)) * std::log1p(epsilon - y_pred(i));
}

TRIXY_FUNCTION_TENSOR1D_TPL_DECLARATION
void binary_cross_entropy_derived(
    Tensor1D<Precision, Args...>& buff,
    const Tensor1D<Precision, Args...>& y_true,
    const Tensor1D<Precision, Args...>& y_pred) noexcept
{
    static constexpr Precision epsilon = 1e-9;
    static constexpr Precision alpha   = epsilon - 1.0;

    for(std::size_t i = 0; i < y_true.size(); ++i)
        buff(i) =
            (y_true(i) - 1.) / (y_pred(i) + alpha) - y_true(i) / (y_pred(i) + epsilon);
}

TRIXY_FUNCTION_TENSOR1D_TPL_DECLARATION
void binary_cross_entropy_derived_sigmoid(
    Tensor1D<Precision, Args...>& buff,
    const Tensor1D<Precision, Args...>& y_true,
    const Tensor1D<Precision, Args...>& y_pred) noexcept
{
    for(std::size_t i = 0; i < y_true.size(); ++i)
        buff(i) = y_true(i) * (y_pred(i) - 1.) + (1. - y_true(i)) * y_pred(i);
}


TRIXY_FUNCTION_TENSOR1D_TPL_DECLARATION
void negative_log_likelihood(
    Precision& result,
    const Tensor1D<Precision, Args...>& y_true,
    const Tensor1D<Precision, Args...>& y_pred) noexcept
{
    result = 0.;
    for(std::size_t i = 0; i < y_true.size(); ++i)
        result += y_true(i) * y_pred(i);

    result = -std::log(result);
}

TRIXY_FUNCTION_TENSOR1D_TPL_DECLARATION
void negative_log_likelihood_derived_softmax(
    Tensor1D<Precision, Args...>& buff,
    const Tensor1D<Precision, Args...>& y_true,
    const Tensor1D<Precision, Args...>& y_pred) noexcept
{
    for(std::size_t i = 0; i < y_true.size(); ++i)
        buff(i) = y_pred(i) - y_true(i);
}

TRIXY_FUNCTION_TENSOR1D_TPL_DECLARATION
void logcosh(
    Precision& result,
    const Tensor1D<Precision, Args...>& y_true,
    const Tensor1D<Precision, Args...>& y_pred) noexcept
{
    result = 0.;
    for(std::size_t i = 0; i < y_true.size(); ++i)
        result += std::log( std::cosh(y_pred(i) - y_true(i)) );
}

TRIXY_FUNCTION_TENSOR1D_TPL_DECLARATION
void logcosh_derived(
    Tensor1D<Precision, Args...>& buff,
    const Tensor1D<Precision, Args...>& y_true,
    const Tensor1D<Precision, Args...>& y_pred) noexcept
{
    for(std::size_t i = 0; i < y_true.size(); ++i)
        buff(i) = std::tanh(y_pred(i) - y_true(i));
}

template <class LossFunction, typename CastType, typename LossId>
LossFunction get_loss_function(LossId id)
{
    static CastType f_id;

    f_id = static_cast<CastType>(id);

    switch (id)
    {
    case LossId::MSE:  return { mean_squared_error, mean_squared_error_derived, f_id };
    case LossId::MAE:  return { mean_absolute_error, mean_absolute_error_derived, f_id };
    case LossId::CCE:  return { categorical_cross_entropy, categorical_cross_entropy_derived_softmax, f_id };

    case LossId::BCE:  return { binary_cross_entropy, binary_cross_entropy_derived_sigmoid, f_id };
    case LossId::MSLE: return { mean_squared_log_error, mean_squared_log_error_derived, f_id };
    case LossId::NLL:  return { negative_log_likelihood, negative_log_likelihood_derived_softmax, f_id };

    case LossId::LC:   return { logcosh, logcosh_derived, f_id };

    case LossId::CCE_: return { categorical_cross_entropy, categorical_cross_entropy_derived, f_id };
    case LossId::BCE_: return { binary_cross_entropy, binary_cross_entropy_derived, f_id };

    default:
        return { nullptr, nullptr, static_cast<CastType>(LossId::undefined) };
    }
}

} // namespace loss

} // namespace set

} // namespace trixy

#include "Trixy/Neuro/Detail/MacroUnscope.hpp"

#endif // LOSS_FUNCTION_HPP
