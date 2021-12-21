#ifndef FEED_FORWARD_NEURO_FUNCTIONAL_HPP
#define FEED_FORWARD_NEURO_FUNCTIONAL_HPP

#include "../Detail/neuro_function_id.hpp"
#include "../Detail/neuro_meta.hpp"

#include "Function/neuro_activation.hpp"
#include "Function/neuro_optimization.hpp"
#include "Function/neuro_loss.hpp"

#include "base_functional.hpp"

#define TRIXY_FEED_FORWARD_NEURO_FUNCTIONAL_TPL                              \
    Functional<NeuralNetwork,                                                \
        meta::enable_if_t<meta::is_feedforward_neuro<NeuralNetwork>::value>>

namespace trixy
{

template <typename NeuralNetwork>
class Functional<NeuralNetwork, meta::enable_if_t<meta::is_feedforward_neuro<NeuralNetwork>::value>>
{
private:
    using byte_type            = typename NeuralNetwork::byte_type;

    using ActivationFunction   = typename NeuralNetwork::ActivationFunction;
    using LossFunction         = typename NeuralNetwork::LossFunction;
    using OptimizationFunction = typename NeuralNetwork::OptimizationFunction;

public:
    ActivationFunction get(function::ActivationId id) const noexcept;
    LossFunction get(function::LossId id) const noexcept;
    OptimizationFunction get(function::OptimizationId id) const noexcept;
};

template <typename NeuralNetwork>
typename TRIXY_FEED_FORWARD_NEURO_FUNCTIONAL_TPL::ActivationFunction TRIXY_FEED_FORWARD_NEURO_FUNCTIONAL_TPL::get(
    function::ActivationId id) const noexcept
{
    using namespace set::activation;
    using namespace function;

    static byte_type f_id;

    f_id = static_cast<byte_type>(id);

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
        return { nullptr, nullptr, static_cast<byte_type>(ActivationId::undefined) };
    }
}

template <typename NeuralNetwork>
typename TRIXY_FEED_FORWARD_NEURO_FUNCTIONAL_TPL::LossFunction TRIXY_FEED_FORWARD_NEURO_FUNCTIONAL_TPL::get(
    function::LossId id) const noexcept
{
    using namespace set::loss;
    using namespace function;

    static byte_type f_id;

    f_id = static_cast<byte_type>(id);

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
        return { nullptr, nullptr, static_cast<byte_type>(LossId::undefined) };
    }
}

template <typename NeuralNetwork>
typename TRIXY_FEED_FORWARD_NEURO_FUNCTIONAL_TPL::OptimizationFunction TRIXY_FEED_FORWARD_NEURO_FUNCTIONAL_TPL::get(
    function::OptimizationId id) const noexcept
{
    using namespace set::optimization;
    using namespace function;

    static byte_type f_id;

    f_id = static_cast<byte_type>(id);

    switch (id)
    {
    case OptimizationId::momentum: return { momentum, momentum, f_id };
    case OptimizationId::rms_prop: return { rms_prop, rms_prop, f_id };
    case OptimizationId::ada_grad: return { ada_grad, ada_grad, f_id };

    default:
        return { nullptr, nullptr, static_cast<byte_type>(OptimizationId::undefined) };
    }
}

} // namespace trixy

// clean up
#undef TRIXY_FEED_FORWARD_NEURO_FUNCTIONAL_TPL

#endif // FEED_FORWARD_NEURO_FUNCTIONAL_HPP
