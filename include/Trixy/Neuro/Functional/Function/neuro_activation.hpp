#ifndef NEURO_ACTIVATION_HPP
#define NEURO_ACTIVATION_HPP

#include "neuro_activation_less.hpp"

#include <cstddef> // size_t
#include <cmath> // exp

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

template <template <typename P, typename...> class Tensor1D, typename Precision, typename... Args>
void unstable_softmax(
    Tensor1D<Precision, Args...>& buff,
    const Tensor1D<Precision, Args...>& vector) noexcept
{
    for(std::size_t i = 0; i < vector.size(); ++i)
        buff(i) = std::exp(vector(i));

    Precision denominator = 0.;
    for(std::size_t i = 0; i < vector.size(); ++i)
        denominator += buff(i);

    denominator = 1. / denominator;

    for(std::size_t i = 0; i < vector.size(); ++i)
        buff(i) *= denominator;
}

template <template <typename P, typename...> class Tensor1D, typename Precision, typename... Args>
void softmax(
    Tensor1D<Precision, Args...>& buff,
    const Tensor1D<Precision, Args...>& vector) noexcept
{
    Precision max;
    Precision denominator;

    max = vector(0);
    for(std::size_t i = 1; i < vector.size(); ++i)
        if(max < vector(i)) max = vector(i);

    for(std::size_t i = 0; i < vector.size(); ++i)
        buff(i) = std::exp(vector(i) - max);

    denominator = 0.;
    for(std::size_t i = 0; i < vector.size(); ++i)
        denominator += buff(i);

    denominator = 1. / denominator;

    for(std::size_t i = 0; i < vector.size(); ++i)
        buff(i) *= denominator;
}

template <template <typename P, typename...> class Tensor, typename Precision, typename... Args>
void tensor_of_units(
    Tensor<Precision, Args...>& buff,
    const Tensor<Precision, Args...>& /*unused*/) noexcept
{
    buff.fill(1.);
}

} // namespace activation

} // namespace set

} // namespace trixy

// clean up
#undef TRIXY_FUNCTION_GENERIC_HELPER

#endif // NEURO_ACTIVATION_HPP
