#ifndef NEURO_ACTIVATION_HPP
#define NEURO_ACTIVATION_HPP

#include <cstddef> // size_t
#include <cstdint> // uint_8
#include <cmath> // exp, log, fabs, tanh, cosh

#define TRIXY_TENSOR_FUNCTION_TPL_DECLARATION                                                        \
    template <template <typename P, typename...> class Tensor, typename Precision, typename... Args> \

#define TRIXY_VECTOR_FUNCTION_TPL_DECLARATION                                                        \
    template <template <typename P, typename...> class Vector, typename Precision, typename... Args> \

#define TRIXY_FUNCTION_GENERIC_HELPER(name)                                                          \
    template <template <typename P, typename...> class Tensor, typename Precision, typename... Args> \
    void name(                                                                                       \
        Tensor<Precision, Args...>& buff, const Tensor<Precision, Args...>& tensor) noexcept {       \
        buff.apply(detail::name, tensor);                                                            \
    }                                                                                                \
    template <template <typename P, typename...> class Tensor, typename Precision, typename... Args> \
    void name##_derived(                                                                             \
        Tensor<Precision, Args...>& buff, const Tensor<Precision, Args...>& tensor) noexcept {       \
        buff.apply(detail::name##_derived, tensor);                                                  \
    }

namespace trixy
{

namespace set
{

namespace activation
{

namespace detail
{

template <typename Precision>
Precision identity(Precision x) noexcept
{
    return x;
}

template <typename Precision>
Precision identity_derived(Precision x) noexcept
{
    return 1.0;
}

template <typename Precision>
Precision relu(Precision x) noexcept
{
    return x > 0.0 ? x : 0.0;
}
template <typename Precision>
Precision relu_derived(Precision x) noexcept
{
    return x > 0.0 ? 1.0 : 0.0;
}

template <typename Precision>
Precision elu(Precision x) noexcept
{
    static const Precision alpha = 0.2;
    return x > 0.0 ? x : alpha * (std::exp(x) - 1.0);
}
template <typename Precision>
Precision elu_derived(Precision x) noexcept
{
    static const Precision alpha = 0.2;
    return x > 0.0 ? 1.0 : alpha * std::exp(x);
}

template <typename Precision>
Precision lrelu(Precision x) noexcept
{
    static const Precision alpha = 0.01;
    return x > 0.0 ? x : alpha * x;
}
template <typename Precision>
Precision lrelu_derived(Precision x) noexcept
{
    static const Precision alpha = 0.01;
    return x > 0.0 ? 1.0 : alpha;
}

template <typename Precision>
Precision selu(Precision x) noexcept
{
    static const Precision lambda = 1.050701;
    static const Precision beta   = 1.758099;

    return x > 0.0 ? lambda * x : beta * (std::exp(x) - 1.0);
}
template <typename Precision>
Precision selu_derived(Precision x) noexcept
{
    static const Precision lambda = 1.050701;
    static const Precision beta   = 1.758099;

    return x > 0.0 ? lambda : beta * std::exp(x);
}

template <typename Precision>
Precision gelu(Precision x) noexcept
{
    static const Precision a = 0.797885;
    static const Precision b = 0.0356774;

    return 0.5 * x * (std::tanh(x * a + x * x * x * b) + 1.0);
}
template <typename Precision>
Precision gelu_derived(Precision x) noexcept
{
    static const Precision a = 0.797885;
    static const Precision b = 0.0356774;
    static const Precision c = 0.0535161;
    static const Precision d = 0.398942;

    static Precision x3;
    static Precision y;
    static Precision sch;

    x3  = x * x * x;
    y   = a * x3 + b * x;
    sch = 1.0 / std::cosh(y);

    return 0.5 * std::tanh(y) + (c * x3 + d * x) * sch * sch + 0.5;
}

template <typename Precision>
Precision sigmoid(Precision x) noexcept
{
    return 1.0 / (std::exp(-x) + 1.0);
}
template <typename Precision>
Precision sigmoid_derived(Precision x) noexcept
{
    return 0.5 / (std::cosh(x) + 1.0);
}

template <typename Precision>
Precision tanh(Precision x) noexcept
{
    return std::tanh(x);
}
template <typename Precision>
Precision tanh_derived(Precision x) noexcept
{
    static Precision sech;
    sech = 1.0 / std::cosh(x);

    return sech * sech;
}

template <typename Precision>
Precision softsign(Precision x) noexcept
{
    return x / (std::fabs(x) + 1.0);
}
template <typename Precision>
Precision softsign_derived(Precision x) noexcept
{
    static Precision f;
    f = 1.0 / (std::fabs(x) + 1.0);

    return f * f;
}

template <typename Precision>
Precision softplus(Precision x) noexcept
{
    return std::log(std::exp(x) + 1.0);
}
template <typename Precision>
Precision softplus_derived(Precision x) noexcept
{
    return 1.0 / (std::exp(-x) + 1.0);
}

template <typename Precision>
Precision swish(Precision x) noexcept
{
    return x / (std::exp(-x) + 1.0);
}
template <typename Precision>
Precision swish_derived(Precision x) noexcept
{
    static Precision a;
    static Precision b;

    a = std::exp(-x);
    b = a + 1.0;

    return (a * x + b) / (b * b);
}

template <typename Precision>
Precision mod_relu(Precision x) noexcept
{
    if      (x < 0.0) return 0.01 * x;
    else if (x > 1.0) return 0.99 + 0.01 * x;
    else              return x;
}
template <typename Precision>
Precision mod_relu_derived(Precision x) noexcept
{
    if (x < 0.0 || x > 1.0) return 0.01;
    else return 1.0;
}

template <typename Precision>
Precision mod_tanh(Precision x) noexcept
{
    if (x < 0.0) return 0.01 * std::tanh(x);
    else         return std::tanh(x);
}
template <typename Precision>
Precision mod_tanh_derived(Precision x) noexcept
{
    static Precision sech2;

    sech2  = 1.0 / std::cosh(x);
    sech2 *= sech2;

    if (x < 0.0) return 0.01 * sech2;
    else         return sech2;
}

} // namespace detail

TRIXY_FUNCTION_GENERIC_HELPER(identity)

TRIXY_FUNCTION_GENERIC_HELPER(relu)
TRIXY_FUNCTION_GENERIC_HELPER(elu)
TRIXY_FUNCTION_GENERIC_HELPER(lrelu)
TRIXY_FUNCTION_GENERIC_HELPER(selu)
TRIXY_FUNCTION_GENERIC_HELPER(gelu)

TRIXY_FUNCTION_GENERIC_HELPER(sigmoid)
TRIXY_FUNCTION_GENERIC_HELPER(tanh)

TRIXY_FUNCTION_GENERIC_HELPER(softsign)
TRIXY_FUNCTION_GENERIC_HELPER(softplus)
TRIXY_FUNCTION_GENERIC_HELPER(swish)

TRIXY_FUNCTION_GENERIC_HELPER(mod_relu)
TRIXY_FUNCTION_GENERIC_HELPER(mod_tanh)

TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
void unstable_softmax(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& vector) noexcept
{
    for(std::size_t i = 0; i < vector.size(); ++i)
        buff(i) = std::exp(vector(i));

    Precision denominator = 0.0;
    for(std::size_t i = 0; i < vector.size(); ++i)
        denominator += buff(i);

    denominator = 1.0 / denominator;

    for(std::size_t i = 0; i < vector.size(); ++i)
        buff(i) *= denominator;
}

TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
void softmax(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& vector) noexcept
{
    Precision max;
    Precision denominator;

    max = vector(0);
    for(std::size_t i = 1; i < vector.size(); ++i)
        if(max < vector(i)) max = vector(i);

    for(std::size_t i = 0; i < vector.size(); ++i)
        buff(i) = std::exp(vector(i) - max);

    denominator = 0.0;
    for(std::size_t i = 0; i < vector.size(); ++i)
        denominator += buff(i);

    denominator = 1.0 / denominator;

    for(std::size_t i = 0; i < vector.size(); ++i)
        buff(i) *= denominator;
}

TRIXY_TENSOR_FUNCTION_TPL_DECLARATION
void tensor_of_units(
    Tensor<Precision, Args...>& buff,
    const Tensor<Precision, Args...>& /*unused*/) noexcept
{
    buff.fill(1.0);
}

} // namespace activation

} // namespace set

} // namespace trixy

// clean up
#undef TRIXY_TENSOR_FUNCTION_TPL_DECLARATION
#undef TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
#undef TRIXY_FUNCTION_GENERIC_HELPER

#endif // NEURO_ACTIVATION_HPP
