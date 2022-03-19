#ifndef LOSS_FUNCTION_HPP
#define LOSS_FUNCTION_HPP

#include <cmath> // log, fabs, tanh, cosh

#include "Trixy/Detail/TrixyMeta.hpp"

#include "Trixy/Detail/MacroScope.hpp"

namespace trixy
{

namespace set
{

namespace loss
{

TRIXY_FUNCTION_TENSOR_TPL_DECLARATION
void categorical_cross_entropy(precision_type& result, const Tensor& y_true, const Tensor& y_pred) noexcept
{
    static constexpr precision_type epsilon = 1e-9;

    result = 0.;
    for(size_type i = 0; i < y_true.size(); ++i)
        result -= y_true(i) * std::log(y_pred(i) + epsilon);
}

TRIXY_FUNCTION_TENSOR_TPL_DECLARATION
void categorical_cross_entropy_derived(Tensor& buff, const Tensor& y_true, const Tensor& y_pred) noexcept
{
    static constexpr precision_type epsilon = 1e-9;

    for(size_type i = 0; i < y_true.size(); ++i)
        buff(i) = - y_true(i) / (y_pred(i) + epsilon);
}

TRIXY_FUNCTION_TENSOR_TPL_DECLARATION
void categorical_cross_entropy_derived_softmax(Tensor& buff, const Tensor& y_true, const Tensor& y_pred) noexcept
{
    for(size_type i = 0; i < y_true.size(); ++i)
        buff(i) = y_pred(i) - y_true(i);
}

TRIXY_FUNCTION_TENSOR_TPL_DECLARATION
void mean_squared_error(precision_type& result, const Tensor& y_true, const Tensor& y_pred) noexcept
{
    static precision_type f;

    result = 0.;
    for(size_type i = 0; i < y_true.size(); ++i)
    {
        f = y_true(i) - y_pred(i);
        result += f * f;
    }

   result *= 0.5;
}

TRIXY_FUNCTION_TENSOR_TPL_DECLARATION
void mean_squared_error_derived(Tensor& buff, const Tensor& y_true, const Tensor& y_pred) noexcept
{
    for(size_type i = 0; i < y_true.size(); ++i)
        buff(i) = y_pred(i) - y_true(i);
}

TRIXY_FUNCTION_TENSOR_TPL_DECLARATION
void mean_absolute_error(precision_type& result, const Tensor& y_true, const Tensor& y_pred) noexcept
{
    result = 0.;
    for(size_type i = 0; i < y_true.size(); ++i)
        result += std::fabs(y_true(i) - y_pred(i));
}

TRIXY_FUNCTION_TENSOR_TPL_DECLARATION
void mean_absolute_error_derived(Tensor& buff, const Tensor& y_true, const Tensor& y_pred) noexcept
{
    static precision_type diff;

    for(size_type i = 0; i < buff.size(); ++i)
    {
        diff = y_true(i) - y_pred(i);
        buff(i) = diff < 0.
                  ? -1.
                  : diff > 0. ? 1. : 0.;
    }
}

TRIXY_FUNCTION_TENSOR_TPL_DECLARATION
void mean_squared_log_error(precision_type& result, const Tensor& y_true, const Tensor& y_pred) noexcept
{
    static precision_type f;

    result = 0.;
    for(size_type i = 0; i < y_true.size(); ++i)
    {
        f = (y_pred(i) + 1.) / (y_true(i) + 1.);
        f = std::log(f);
        result += f * f;
    }

    result *= 0.5;
}

TRIXY_FUNCTION_TENSOR_TPL_DECLARATION
void mean_squared_log_error_derived(Tensor& buff, const Tensor& y_true, const Tensor& y_pred) noexcept
{
    for(size_type i = 0; i < buff.size(); ++i)
    {
        buff(i) = y_pred(i) + 1.;
        buff(i) = std::log(buff(i) / (y_true(i) + 1.)) / buff(i);
    }
}

TRIXY_FUNCTION_TENSOR_TPL_DECLARATION
void binary_cross_entropy(precision_type& result, const Tensor& y_true, const Tensor& y_pred) noexcept
{
    static constexpr precision_type epsilon = 1e-9;
    result = 0.;
    for(size_type i = 0; i < y_true.size(); ++i)
        result -= y_true(i) * std::log(y_pred(i) + epsilon)
                  + (1. - y_true(i)) * std::log1p(epsilon - y_pred(i));
}

TRIXY_FUNCTION_TENSOR_TPL_DECLARATION
void binary_cross_entropy_derived(Tensor& buff, const Tensor& y_true, const Tensor& y_pred) noexcept
{
    static constexpr precision_type epsilon = 1e-9;
    static constexpr precision_type alpha   = epsilon - 1.0;

    for(size_type i = 0; i < buff.size(); ++i)
        buff(i) =
            (y_true(i) - 1.) / (y_pred(i) + alpha) - y_true(i) / (y_pred(i) + epsilon);
}

TRIXY_FUNCTION_TENSOR_TPL_DECLARATION
void binary_cross_entropy_derived_sigmoid(Tensor& buff, const Tensor& y_true, const Tensor& y_pred) noexcept
{
    for(size_type i = 0; i < buff.size(); ++i)
        buff(i) = y_true(i) * (y_pred(i) - 1.) + (1. - y_true(i)) * y_pred(i);
}


TRIXY_FUNCTION_TENSOR_TPL_DECLARATION
void negative_log_likelihood(precision_type& result, const Tensor& y_true, const Tensor& y_pred) noexcept
{
    result = 0.;
    for(size_type i = 0; i < y_true.size(); ++i)
        result += y_true(i) * y_pred(i);

    result = -std::log(result);
}

TRIXY_FUNCTION_TENSOR_TPL_DECLARATION
void negative_log_likelihood_derived_softmax(Tensor& buff, const Tensor& y_true, const Tensor& y_pred) noexcept
{
    for(size_type i = 0; i < buff.size(); ++i)
        buff(i) = y_pred(i) - y_true(i);
}

TRIXY_FUNCTION_TENSOR_TPL_DECLARATION
void logcosh(precision_type& result, const Tensor& y_true, const Tensor& y_pred) noexcept
{
    result = 0.;
    for(size_type i = 0; i < y_true.size(); ++i)
        result += std::log( std::cosh(y_pred(i) - y_true(i)) );
}

TRIXY_FUNCTION_TENSOR_TPL_DECLARATION
void logcosh_derived(Tensor& buff, const Tensor& y_true, const Tensor& y_pred) noexcept
{
    for(size_type i = 0; i < buff.size(); ++i)
        buff(i) = std::tanh(y_pred(i) - y_true(i));
}

template <class LossFunction, typename CastType, typename LossId>
LossFunction get_loss_function(LossId id)
{
    auto f_id = static_cast<CastType>(id);

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

#include "Trixy/Detail/MacroUnscope.hpp"

#endif // LOSS_FUNCTION_HPP
