#ifndef TRIXY_FUNCTION_ACTIVATION_LESS_HPP
#define TRIXY_FUNCTION_ACTIVATION_LESS_HPP

#include <cstddef> // size_t
#include <cmath> // exp, log, fabs, tanh, cosh

#include <Trixy/Detail/TrixyMeta.hpp>

#include <Trixy/Detail/MacroScope.hpp>

namespace trixy
{

namespace functional
{

namespace activation
{

// inline namespace for generation code
inline namespace detail
{

TRIXY_FUNCTION_TEMPLATE() inline Precision identity(Precision x) noexcept
{
    return x;
}

TRIXY_FUNCTION_TEMPLATE() inline Precision identity_derived(Precision x) noexcept
{
    return 1.;
}

TRIXY_FUNCTION_TEMPLATE() inline Precision relu(Precision x) noexcept
{
    return x > 0. ? x : 0.;
}

TRIXY_FUNCTION_TEMPLATE() inline Precision relu_derived(Precision x) noexcept
{
    return x > 0. ? 1. : 0.;
}

TRIXY_FUNCTION_TEMPLATE() Precision elu(Precision x) noexcept
{
    constexpr Precision alpha = 0.2;
    return x > 0. ? x : alpha * std::expm1(x);
}

TRIXY_FUNCTION_TEMPLATE() Precision elu_derived(Precision x) noexcept
{
    constexpr Precision alpha = 0.2;
    return x > 0. ? 1. : alpha * std::exp(x);
}

TRIXY_FUNCTION_TEMPLATE() inline Precision lrelu(Precision x) noexcept
{
    constexpr Precision alpha = 0.01;
    return x > 0. ? x : alpha * x;
}

TRIXY_FUNCTION_TEMPLATE() inline Precision lrelu_derived(Precision x) noexcept
{
    constexpr Precision alpha = 0.01;
    return x > 0. ? 1. : alpha;
}

TRIXY_FUNCTION_TEMPLATE() Precision selu(Precision x) noexcept
{
    constexpr Precision lambda = 1.050701;
    constexpr Precision beta   = 1.758099;

    return x > 0. ? lambda * x : beta * std::expm1(x);
}

TRIXY_FUNCTION_TEMPLATE() Precision selu_derived(Precision x) noexcept
{
    constexpr Precision lambda = 1.050701;
    constexpr Precision beta   = 1.758099;

    return x > 0. ? lambda : beta * std::exp(x);
}

TRIXY_FUNCTION_TEMPLATE() Precision gelu(Precision x) noexcept
{
    constexpr Precision a = 0.797885;
    constexpr Precision b = 0.0356774;

    return 0.5 * x * (std::tanh(x * a + x * x * x * b) + 1.);
}

TRIXY_FUNCTION_TEMPLATE() Precision gelu_derived(Precision x) noexcept
{
    constexpr Precision a = 0.797885;
    constexpr Precision b = 0.0356774;
    constexpr Precision c = 0.0535161;
    constexpr Precision d = 0.398942;

    Precision x3 = x * x * x;
    Precision y = a * x3 + b * x;
    Precision sch = 1. / std::cosh(y);

    return 0.5 * std::tanh(y) + (c * x3 + d * x) * sch * sch + 0.5;
}

TRIXY_FUNCTION_TEMPLATE() Precision sigmoid(Precision x) noexcept
{
    return 1. / (std::exp(-x) + 1.);
}

TRIXY_FUNCTION_TEMPLATE() Precision sigmoid_derived(Precision x) noexcept
{
    return 0.5 / (std::cosh(x) + 1.);
}

TRIXY_FUNCTION_TEMPLATE() inline Precision sigmoid_derived_self(Precision x) noexcept
{
    return x * (1 - x);
}

TRIXY_FUNCTION_TEMPLATE() Precision tanh(Precision x) noexcept
{
    return std::tanh(x);
}

TRIXY_FUNCTION_TEMPLATE() Precision tanh_derived(Precision x) noexcept
{
    Precision sech = 1. / std::cosh(x);
    return sech * sech;
}

TRIXY_FUNCTION_TEMPLATE() Precision softsign(Precision x) noexcept
{
    return x / (std::fabs(x) + 1.);
}

TRIXY_FUNCTION_TEMPLATE() Precision softsign_derived(Precision x) noexcept
{
    Precision f = 1. / (std::fabs(x) + 1.);
    return f * f;
}

TRIXY_FUNCTION_TEMPLATE() Precision softplus(Precision x) noexcept
{
    return std::log(std::exp(x) + 1.);
}

TRIXY_FUNCTION_TEMPLATE() Precision softplus_derived(Precision x) noexcept
{
    return 1. / (std::exp(-x) + 1.);
}

TRIXY_FUNCTION_TEMPLATE() Precision swish(Precision x) noexcept
{
    return x / (std::exp(-x) + 1.);
}

TRIXY_FUNCTION_TEMPLATE() Precision swish_derived(Precision x) noexcept
{
    Precision a = std::exp(-x);
    Precision b = a + 1.;
    return (a * x + b) / (b * b);
}

TRIXY_FUNCTION_TEMPLATE() inline Precision mod_relu(Precision x) noexcept
{
    if      (x < 0.) return 0.01 * x;
    else if (x > 1.) return 0.99 + 0.01 * x;
    else             return x;
}
TRIXY_FUNCTION_TEMPLATE() inline Precision mod_relu_derived(Precision x) noexcept
{
    return (x < 0. or x > 1.) ? 0.01 : 1.;
}

TRIXY_FUNCTION_TEMPLATE() Precision mod_tanh(Precision x) noexcept
{
    return x < 0. ? 0.01 * std::tanh(x) : std::tanh(x);
}

TRIXY_FUNCTION_TEMPLATE() Precision mod_tanh_derived(Precision x) noexcept
{
    Precision sech2 = 1. / std::cosh(x);
    sech2 *= sech2;
    return x < 0. ? 0.01 * sech2 : sech2;
}

} // inline namespace detail

} // namespace activation

} // namespace functional

} // namespace trixy

#include <Trixy/Detail/MacroUnscope.hpp>

#endif // TRIXY_FUNCTION_ACTIVATION_LESS_HPP
