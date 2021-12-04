#ifndef NEURO_LOSS_HPP
#define NEURO_LOSS_HPP

#include <cstddef> // size_t
#include <cstdint> // uint_8
#include <cmath> // log, fabs, tanh, cosh

#define TRIXY_TENSOR_FUNCTION_TPL_DECLARATION                  \
    template <template <typename T, typename...> class Tensor, \
              typename Precision,                              \
              typename... Args>

#define TRIXY_VECTOR_FUNCTION_TPL_DECLARATION                  \
    template <template <typename T, typename...> class Vector, \
              typename Precision,                              \
              typename... Args>

namespace trixy
{

namespace set
{

namespace loss
{

TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
Precision categorical_cross_entropy(
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred) noexcept
{
    static constexpr Precision epsilon = 1e-9;
    static Precision result;

    result = 0.0;
    for(std::size_t i = 0; i < y_true.size(); ++i)
        result += y_true(i) * std::log(y_pred(i) + epsilon);

    return -result;
}

TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
void categorical_cross_entropy_derived(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred) noexcept
{
    static constexpr Precision epsilon = 1e-9;

    for(std::size_t i = 0; i < y_true.size(); ++i)
        buff(i) = - y_true(i) / (y_pred(i) + epsilon);
}

TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
void categorical_cross_entropy_derived_softmax(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred) noexcept
{
    for(std::size_t i = 0; i < y_true.size(); ++i)
        buff(i) = y_pred(i) - y_true(i);
}

TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
Precision mean_squared_error(
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred) noexcept
{
    static Precision result;
    static Precision f;

    result = 0.0;
    for(std::size_t i = 0; i < y_true.size(); ++i)
    {
        f = y_true(i) - y_pred(i);
        result += f * f;
    }

    return result * 0.5;
}

TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
void mean_squared_error_derived(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred) noexcept
{
    for(std::size_t i = 0; i < y_true.size(); ++i)
        buff(i) = y_pred(i) - y_true(i);
}

TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
Precision mean_absolute_error(
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred) noexcept
{
    static Precision result;

    result = 0.0;
    for(std::size_t i = 0; i < y_true.size(); ++i)
        result += std::fabs(y_true(i) - y_pred(i));

    return result;
}

TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
void mean_absolute_error_derived(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred) noexcept
{
    static Precision diff;

    for(std::size_t i = 0; i < y_true.size(); ++i)
    {
        diff = y_true(i) - y_pred(i);
        buff(i) = diff < 0.0
                  ? -1.0
                  : diff > 0.0 ? 1.0 : 0.0;
    }
}

TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
Precision mean_squared_log_error(
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred) noexcept
{
    static Precision result;
    static Precision f;

    result = 0.0;
    for(std::size_t i = 0; i < y_true.size(); ++i)
    {
        f = (y_pred(i) + 1.0) / (y_true(i) + 1.0);
        f = std::log(f);
        result += f * f;
    }
    return result * 0.5;
}

TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
void mean_squared_log_error_derived(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred) noexcept
{
    for(std::size_t i = 0; i < y_true.size(); ++i)
    {
        buff(i) = y_pred(i) + 1.0;
        buff(i) = std::log(buff(i) / (y_true(i) + 1.0)) / buff(i);
    }
}

TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
Precision binary_cross_entropy(
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred) noexcept
{
    static constexpr Precision epsilon = 1e-9;
    static constexpr Precision alpha   = epsilon + 1.0;
    static Precision result;

    result = 0.0;
    for(std::size_t i = 0; i < y_true.size(); ++i)
        result -= y_true(i) * std::log(y_pred(i) + epsilon)
                  + (1.0 - y_true(i)) * std::log(alpha - y_pred(i));

    return result;
}

TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
void binary_cross_entropy_derived(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred) noexcept
{
    static constexpr Precision epsilon = 1e-9;
    static constexpr Precision alpha   = epsilon - 1.0;

    for(std::size_t i = 0; i < y_true.size(); ++i)
        buff(i) =
            (y_true(i) - 1.0) / (y_pred(i) + alpha) - y_true(i) / (y_pred(i) + epsilon);
}

TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
void binary_cross_entropy_derived_sigmoid(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred) noexcept
{
    for(std::size_t i = 0; i < y_true.size(); ++i)
        buff(i) = y_true(i) * (y_pred(i) - 1.0) + (1.0 - y_true(i)) * y_pred(i);
}


TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
Precision negative_log_likelihood(
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred) noexcept
{
    static Precision result;

    result = 0.0;
    for(std::size_t i = 0; i < y_true.size(); ++i)
        result += y_true(i) * y_pred(i);

    return -std::log(result);
}

TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
void negative_log_likelihood_derived_softmax(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred) noexcept
{
    for(std::size_t i = 0; i < y_true.size(); ++i)
        buff(i) = y_pred(i) - y_true(i);
}

TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
Precision logcosh(
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred) noexcept
{
    static Precision result;

    result = 0.0;
    for(std::size_t i = 0; i < y_true.size(); ++i)
        result += std::log( std::cosh(y_pred(i) - y_true(i)) );

    return result;
}

TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
void logcosh_derived(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred) noexcept
{
    for(std::size_t i = 0; i < y_true.size(); ++i)
        buff(i) = std::tanh(y_pred(i) - y_true(i));
}

} // namespace loss

} // namespace set

} // namespace trixy

// clean up
#undef TRIXY_TENSOR_FUNCTION_TPL_DECLARATION
#undef TRIXY_VECTOR_FUNCTION_TPL_DECLARATION

#endif // NEURO_LOSS_HPP
