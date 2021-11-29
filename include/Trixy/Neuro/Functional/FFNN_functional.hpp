#ifndef FFNN_FUNCTIONAL_HPP
#define FFNN_FUNCTIONAL_HPP

#include "../Detail/neuro_function_id.hpp"
#include "../Detail/neuro_meta.hpp"

#include "Function/neuro_activation.hpp"
#include "Function/neuro_optimization.hpp"
#include "Function/neuro_loss.hpp"


#include <cstdint> // uint_8
#include <utility> // declval
#include <type_traits> // enable_if, is_same, true_type

namespace trixy
{

template <typename FeedForwardNeuro>
class FFNNFunctional
{
public:
    using byte_type = std::uint8_t;

private:
    using ActivationFunction   = typename FeedForwardNeuro::ActivationFunction;
    using LossFunction         = typename FeedForwardNeuro::LossFunction;
    using OptimizationFunction = typename FeedForwardNeuro::OptimizationFunction;

public:
    ActivationFunction get(function::ActivationId id) const noexcept;
    LossFunction get(function::LossId id) const noexcept;
    OptimizationFunction get(function::OptimizationId id) const noexcept;
};

template <typename FeedForwardNeuro>
typename FFNNFunctional<FeedForwardNeuro>::ActivationFunction
FFNNFunctional<FeedForwardNeuro>::get(function::ActivationId id) const noexcept
{
    using namespace set::activation;
    using namespace function;

    static byte_type f_id;

    f_id = static_cast<byte_type>(id);

    switch (id)
    {
    case ActivationId::identity:
        return { f_id, identity, identity_derived };

    case ActivationId::sigmoid:
        return { f_id, sigmoid, sigmoid_derived };
    case ActivationId::tanh:
        return { f_id, tanh, tanh_derived };
    case ActivationId::relu:
        return { f_id, relu, relu_derived };

    case ActivationId::elu:
        return { f_id, elu, elu_derived };
    case ActivationId::lrelu:
        return { f_id, lrelu, lrelu_derived };
    case ActivationId::selu:
        return { f_id, selu, selu_derived };
    case ActivationId::gelu:
        return { f_id, gelu, gelu_derived };

    case ActivationId::softsign:
        return { f_id, softsign, softsign_derived };
    case ActivationId::softplus:
        return { f_id, softplus, softplus_derived };
    case ActivationId::swish:
        return { f_id, swish, swish_derived };

    case ActivationId::mod_relu:
        return { f_id, mod_relu, mod_relu_derived };
    case ActivationId::mod_tanh:
        return { f_id, mod_tanh, mod_tanh_derived };

    case ActivationId::softmax:
        return { f_id, softmax, tensor_of_units };

    case ActivationId::unstable_softmax:
        return { f_id, unstable_softmax, tensor_of_units };
    case ActivationId::sigmoid_:
        return { f_id, sigmoid, tensor_of_units };

    default:
        return { static_cast<byte_type>(ActivationId::undefined), nullptr, nullptr };
    }
}

template <typename FeedForwardNeuro>
typename FFNNFunctional<FeedForwardNeuro>::LossFunction
FFNNFunctional<FeedForwardNeuro>::get(function::LossId id) const noexcept
{
    using namespace set::loss;
    using namespace function;

    static byte_type f_id;

    f_id = static_cast<decltype(f_id)>(id);

    switch (id)
    {
    case LossId::MSE:
        return { f_id, mean_squared_error, mean_squared_error_derived };
    case LossId::MAE:
        return { f_id, mean_absolute_error, mean_absolute_error_derived };
    case LossId::CCE:
        return { f_id, categorical_cross_entropy, categorical_cross_entropy_derived_softmax };

    case LossId::BCE:
        return { f_id, binary_cross_entropy, binary_cross_entropy_derived_sigmoid };
    case LossId::MSLE:
        return { f_id, mean_squared_log_error, mean_squared_log_error_derived };
    case LossId::NLL:
        return { f_id, negative_log_likelihood, negative_log_likelihood_derived_softmax };

    case LossId::LC:
        return { f_id, logcosh, logcosh_derived };

    case LossId::CCE_:
        return { f_id, categorical_cross_entropy, categorical_cross_entropy_derived };
    case LossId::BCE_:
        return { f_id, binary_cross_entropy, binary_cross_entropy_derived };

    default:
        return { static_cast<byte_type>(LossId::undefined), nullptr, nullptr };
    }
}

template <typename FeedForwardNeuro>
typename FFNNFunctional<FeedForwardNeuro>::OptimizationFunction
FFNNFunctional<FeedForwardNeuro>::get(function::OptimizationId id) const noexcept
{
    using namespace set::optimization;
    using namespace function;

    static byte_type f_id;

    f_id = static_cast<byte_type>(id);

    switch (id)
    {
    case OptimizationId::momentum:
        return { f_id, momentum, momentum };

    case OptimizationId::rms_prop:
        return { f_id, rms_prop, rms_prop };
    case OptimizationId::ada_grad:
        return { f_id, ada_grad, ada_grad };

    default:
        return { static_cast<byte_type>(OptimizationId::undefined), nullptr, nullptr };
    }
}

} // namespace trixy

#endif // FFNN_FUNCTIONAL_HPP
