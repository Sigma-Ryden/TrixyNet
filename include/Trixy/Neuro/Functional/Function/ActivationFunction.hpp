#ifndef NEURO_ACTIVATION_HPP
#define NEURO_ACTIVATION_HPP

#include <cstddef> // size_t
#include <cmath> // exp

#include "Trixy/Neuro/Detail/TrixyNetMeta.hpp"
#include "Trixy/Neuro/Functional/Function/ActivationFunctionLess.hpp"

#include "Trixy/Neuro/Detail/MacroScope.hpp"

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

TRIXY_FUNCTION_TENSOR1D_TPL_DECLARATION
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

TRIXY_FUNCTION_TENSOR1D_TPL_DECLARATION
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

TRIXY_FUNCTION_TENSOR_TPL_DECLARATION
void tensor_of_units(
    Tensor<Precision, Args...>& buff,
    const Tensor<Precision, Args...>& /*unused*/) noexcept
{
    buff.fill(1.);
}

} // namespace activation

} // namespace set

} // namespace trixy

#include "Trixy/Neuro/Detail/MacroUnscope.hpp"

#endif // NEURO_ACTIVATION_HPP
