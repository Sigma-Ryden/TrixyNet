#ifndef FEEDFORWARD_NEURO_FUNCTIONAL_HPP
#define FEEDFORWARD_NEURO_FUNCTIONAL_HPP

#include <utility> // forward

#include "base_functional.hpp"
#include "neuro_functional_id.hpp"

#include "Function/neuro_activation.hpp"
#include "Function/neuro_loss.hpp"
#include "Optimization/neuro_optimization.hpp"
#include "Trixy/Neuro/Detail/neuro_meta.hpp"

#include "Trixy/Neuro/Detail/macro_scope.hpp"

namespace trixy
{

TRIXY_FUNCTIONAL_TPL_DECLARATION
class TRIXY_FUNCTIONAL_TPL(meta::is_feedforward_net)
{
private:
    using byte_type            = typename Functionable::byte_type;

    using ActivationFunction   = typename Functionable::ActivationFunction;
    using LossFunction         = typename Functionable::LossFunction;

    template <class optimizer_type>
    using OptimizationFunction = typename train::Optimizer<Functionable, optimizer_type>;

    template <functional::OptimizationId id>
    using optimizer_type_from  = typename functional::OptimizationType::from<id>::type;

public:
    ActivationFunction get(functional::ActivationId id) const noexcept;
    LossFunction get(functional::LossId id) const noexcept;

    template <functional::ActivationId id>
    ActivationFunction get() const noexcept
    {
        return get(id);
    }

    template <functional::LossId id>
    LossFunction get() const noexcept
    {
        return get(id);
    }

    template <functional::OptimizationId id, typename... Args>
    OptimizationFunction<optimizer_type_from<id>> get(Args&&... args) const
    {
        return OptimizationFunction<optimizer_type_from<id>>(std::forward<Args>(args)...);
    }
};

TRIXY_FUNCTIONAL_TPL_DECLARATION
typename TRIXY_FUNCTIONAL_TPL(meta::is_feedforward_net)::ActivationFunction
    TRIXY_FUNCTIONAL_TPL(meta::is_feedforward_net)::get(
    functional::ActivationId id) const noexcept
{
    using namespace set::activation;
    using namespace functional;

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

TRIXY_FUNCTIONAL_TPL_DECLARATION
typename TRIXY_FUNCTIONAL_TPL(meta::is_feedforward_net)::LossFunction
    TRIXY_FUNCTIONAL_TPL(meta::is_feedforward_net)::get(
    functional::LossId id) const noexcept
{
    using namespace set::loss;
    using namespace functional;

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

} // namespace trixy

#include "Trixy/Neuro/Detail/macro_unscope.hpp"

#endif // FEEDFORWARD_NEURO_FUNCTIONAL_HPP
