#ifndef TRIXY_FUNCTION_ACTIVATION_HPP
#define TRIXY_FUNCTION_ACTIVATION_HPP

#include <cstddef> // size_t
#include <cmath> // exp

#include <Trixy/Neuro/Detail/TrixyNetMeta.hpp>
#include <Trixy/Neuro/Functional/Function/ActivationLess.hpp>

#include <Trixy/Detail/MacroScope.hpp>

namespace trixy
{

namespace functional
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
void softmax_derived(Tensor& buff, const Tensor& /*unused*/) noexcept
{
    buff.fill(1.);
}

template <class ActivationFunction, typename CastType, typename ActivationId>
ActivationFunction get_activation_function(ActivationId id)
{
    auto f_id = static_cast<CastType>(id);

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

    case ActivationId::softmax:     return { softmax, softmax_derived, f_id };

    case ActivationId::unstable_softmax:    return { unstable_softmax, softmax_derived, f_id };

    default:
        return { nullptr, nullptr, static_cast<CastType>(ActivationId::undefined) };
    }
}

TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(Identity, identity, identity_derived);

TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(ReLU, relu, relu_derived);
TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(ELU, elu, elu_derived);

TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(LReLU, lrelu, lrelu_derived);
TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(SELU, selu, selu_derived);
TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(GELU, gelu, gelu_derived);

TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(Sigmoid, sigmoid, sigmoid_derived);
TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(Tanh, tanh, tanh_derived);

TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(SoftSign, softsign, softsign_derived);
TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(SoftPlus, softplus, softplus_derived);
TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(Swish, swish, swish_derived);

TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(ModRelu, mod_relu, mod_relu_derived);
TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(ModTanh, mod_tanh, mod_tanh_derived);

TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(SoftMax, softmax, softmax_derived);

} // namespace activation

} // namespace functional

} // namespace trixy

#include <Trixy/Detail/MacroUnscope.hpp>

#endif // TRIXY_FUNCTION_ACTIVATION_HPP
