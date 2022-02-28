#ifndef ACTIVATION_FUNCTION_HPP
#define ACTIVATION_FUNCTION_HPP

#include <cstddef> // size_t
#include <cmath> // exp

#include "Trixy/Neuro/Detail/TrixyNetMeta.hpp"
#include "ActivationFunctionLess.hpp"

#include "Trixy/Detail/MacroScope.hpp"

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

template <class Tensor>
void unstable_softmax(Tensor& buff, const Tensor& vector) noexcept
{
    using size_type      = typename Tensor::size_type;
    using precision_type = typename Tensor::precision_type;

    for(size_type i = 0; i < buff.size(); ++i)
        buff(i) = std::exp(vector(i));

    precision_type denominator = 0.;
    for(size_type i = 0; i < buff.size(); ++i)
        denominator += buff(i);

    denominator = 1. / denominator;

    for(size_type i = 0; i < buff.size(); ++i)
        buff(i) *= denominator;
}

template <class Tensor>
void softmax(Tensor& buff, const Tensor& vector) noexcept
{
    using size_type      = typename Tensor::size_type;
    using precision_type = typename Tensor::precision_type;

    precision_type max;
    precision_type denominator;

    max = vector(0);
    for(size_type i = 1; i < buff.size(); ++i)
        if(max < vector(i)) max = vector(i);

    for(size_type i = 0; i < buff.size(); ++i)
        buff(i) = std::exp(vector(i) - max);

    denominator = 0.;
    for(size_type i = 0; i < buff.size(); ++i)
        denominator += buff(i);

    denominator = 1. / denominator;

    for(size_type i = 0; i < buff.size(); ++i)
        buff(i) *= denominator;
}

template <class Tensor>
void tensor_of_units(Tensor& buff, const Tensor& /*unused*/) noexcept
{
    buff.fill(1.);
}

template <class ActivationFunction, typename CastType, typename ActivationId>
ActivationFunction get_activation_function(ActivationId id)
{
    CastType f_id = static_cast<CastType>(id);

    switch (id)
    {
    case ActivationId::identity:    return { identity, identity_derived, f_id };

    case ActivationId::sigmoid:     return { sigmoid, sigmoid_derived, f_id};
    case ActivationId::tanh:        return { tanh, tanh_derived, f_id };
    case ActivationId::relu:        return { relu, relu_derived, f_id };

    case ActivationId::elu:         return { elu, elu_derived, f_id };
    case ActivationId::lrelu:       return { lrelu, lrelu_derived, f_id };
    case ActivationId::selu:        return { selu, selu_derived, f_id };
    case ActivationId::gelu:        return { gelu, gelu_derived, f_id };

    case ActivationId::softsign:    return { softsign, softsign_derived, f_id };
    case ActivationId::softplus:    return { softplus, softplus_derived, f_id };
    case ActivationId::swish:       return { swish, swish_derived, f_id };

    case ActivationId::mod_relu:    return { mod_relu, mod_relu_derived, f_id };
    case ActivationId::mod_tanh:    return { mod_tanh, mod_tanh_derived, f_id };

    case ActivationId::softmax:     return { softmax, tensor_of_units, f_id };

    case ActivationId::unstable_softmax:    return { unstable_softmax, tensor_of_units, f_id };
    case ActivationId::sigmoid_:            return { sigmoid, tensor_of_units, f_id };

    default:
        return { nullptr, nullptr, static_cast<CastType>(ActivationId::undefined) };
    }
}

} // namespace activation

} // namespace set

} // namespace trixy

#include "Trixy/Detail/MacroUnscope.hpp"

#endif // ACTIVATION_FUNCTION_HPP
