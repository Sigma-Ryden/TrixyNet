#ifndef NEURO_LOSS_HPP
#define NEURO_LOSS_HPP

#include <cstddef> // size_t
#include <cmath> // log, fabs, tanh, cosh

#define TRIXY_TENSOR1D_FUNCTION_TPL_DECLARATION                                                        \
    template <template <typename P, typename...> class Tensor1D, typename Precision, typename... Args> \

namespace trixy
{

namespace set
{

namespace loss
{

TRIXY_TENSOR1D_FUNCTION_TPL_DECLARATION
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

TRIXY_TENSOR1D_FUNCTION_TPL_DECLARATION
void categorical_cross_entropy_derived(
    Tensor1D<Precision, Args...>& buff,
    const Tensor1D<Precision, Args...>& y_true,
    const Tensor1D<Precision, Args...>& y_pred) noexcept
{
    static constexpr Precision epsilon = 1e-9;

    for(std::size_t i = 0; i < y_true.size(); ++i)
        buff(i) = - y_true(i) / (y_pred(i) + epsilon);
}

TRIXY_TENSOR1D_FUNCTION_TPL_DECLARATION
void categorical_cross_entropy_derived_softmax(
    Tensor1D<Precision, Args...>& buff,
    const Tensor1D<Precision, Args...>& y_true,
    const Tensor1D<Precision, Args...>& y_pred) noexcept
{
    for(std::size_t i = 0; i < y_true.size(); ++i)
        buff(i) = y_pred(i) - y_true(i);
}

TRIXY_TENSOR1D_FUNCTION_TPL_DECLARATION
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

TRIXY_TENSOR1D_FUNCTION_TPL_DECLARATION
void mean_squared_error_derived(
    Tensor1D<Precision, Args...>& buff,
    const Tensor1D<Precision, Args...>& y_true,
    const Tensor1D<Precision, Args...>& y_pred) noexcept
{
    for(std::size_t i = 0; i < y_true.size(); ++i)
        buff(i) = y_pred(i) - y_true(i);
}

TRIXY_TENSOR1D_FUNCTION_TPL_DECLARATION
void mean_absolute_error(
    Precision& result,
    const Tensor1D<Precision, Args...>& y_true,
    const Tensor1D<Precision, Args...>& y_pred) noexcept
{
    result = 0.;
    for(std::size_t i = 0; i < y_true.size(); ++i)
        result += std::fabs(y_true(i) - y_pred(i));
}

TRIXY_TENSOR1D_FUNCTION_TPL_DECLARATION
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

TRIXY_TENSOR1D_FUNCTION_TPL_DECLARATION
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

TRIXY_TENSOR1D_FUNCTION_TPL_DECLARATION
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

TRIXY_TENSOR1D_FUNCTION_TPL_DECLARATION
void binary_cross_entropy(
    Precision& result,
    const Tensor1D<Precision, Args...>& y_true,
    const Tensor1D<Precision, Args...>& y_pred) noexcept
{
    static constexpr Precision epsilon = 1e-9;
    static constexpr Precision alpha   = epsilon + 1.;

    result = 0.;
    for(std::size_t i = 0; i < y_true.size(); ++i)
        result -= y_true(i) * std::log(y_pred(i) + epsilon)
                  + (1. - y_true(i)) * std::log(alpha - y_pred(i));
}

TRIXY_TENSOR1D_FUNCTION_TPL_DECLARATION
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

TRIXY_TENSOR1D_FUNCTION_TPL_DECLARATION
void binary_cross_entropy_derived_sigmoid(
    Tensor1D<Precision, Args...>& buff,
    const Tensor1D<Precision, Args...>& y_true,
    const Tensor1D<Precision, Args...>& y_pred) noexcept
{
    for(std::size_t i = 0; i < y_true.size(); ++i)
        buff(i) = y_true(i) * (y_pred(i) - 1.) + (1. - y_true(i)) * y_pred(i);
}


TRIXY_TENSOR1D_FUNCTION_TPL_DECLARATION
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

TRIXY_TENSOR1D_FUNCTION_TPL_DECLARATION
void negative_log_likelihood_derived_softmax(
    Tensor1D<Precision, Args...>& buff,
    const Tensor1D<Precision, Args...>& y_true,
    const Tensor1D<Precision, Args...>& y_pred) noexcept
{
    for(std::size_t i = 0; i < y_true.size(); ++i)
        buff(i) = y_pred(i) - y_true(i);
}

TRIXY_TENSOR1D_FUNCTION_TPL_DECLARATION
void logcosh(
    Precision& result,
    const Tensor1D<Precision, Args...>& y_true,
    const Tensor1D<Precision, Args...>& y_pred) noexcept
{
    result = 0.;
    for(std::size_t i = 0; i < y_true.size(); ++i)
        result += std::log( std::cosh(y_pred(i) - y_true(i)) );
}

TRIXY_TENSOR1D_FUNCTION_TPL_DECLARATION
void logcosh_derived(
    Tensor1D<Precision, Args...>& buff,
    const Tensor1D<Precision, Args...>& y_true,
    const Tensor1D<Precision, Args...>& y_pred) noexcept
{
    for(std::size_t i = 0; i < y_true.size(); ++i)
        buff(i) = std::tanh(y_pred(i) - y_true(i));
}

} // namespace loss

} // namespace set

} // namespace trixy

// clean up
#undef TRIXY_TENSOR_FUNCTION_TPL_DECLARATION
#undef TRIXY_TENSOR1D_FUNCTION_TPL_DECLARATION

#endif // NEURO_LOSS_HPP
