#ifndef ID_FUNCTIONAL_HPP
#define ID_FUNCTIONAL_HPP

#include <cstdint> // uint8_t

#include "Trixy/Neuro/Detail/TrixyNetMeta.hpp"

#include "Trixy/Neuro/Detail/MacroScope.hpp"

namespace trixy
{

namespace functional
{

enum class ActivationId : std::uint8_t
{
    undefined,          ///< default null value
    identity,           ///< same value from input
    sigmoid,            ///< sigmoid(x) = 1 / (exp(-x) + 1)
    tanh,               ///< hyperbolic tangent
    relu,               ///< relu(x) = max(0,x) (Rectified Linear Unit)
    elu,                ///< exponential relu with alpha = 0.2
    lrelu,              ///< leaky relu (same as relu, but with low negative signal)
    selu,               ///< exponential relu with lambda = 1.050701, beta = 1.758099
    gelu,               ///< gaussian relu
    softsign,           ///< absolute value hyperbola
    softplus,           ///< logarithm with exponential argument
    swish,              ///< same as relu & sigmoid
    softmax,            ///< normalization function
    mod_relu,           ///< relu for range [0, 1]
    mod_tanh,           ///< tanh for range [0, 1]
    unstable_softmax,   ///< deprecated
    sigmoid_            ///< maybe unused
};

enum class LossId : std::uint8_t
{
    undefined,          ///< default null value
    MSE,                ///< mean squared error
    MAE,                ///< mean absolute error
    CCE,                ///< categorical cross entropy (for softmax)
    BCE,                ///< binary cross entropy (for sigmoid)
    MSLE,               ///< mean squared logarithmic error
    NLL,                ///< negative logarithmic likelihood (for softmax)
    LC,                 ///< logcosh (maybe unused)
    CCE_,               ///< categorical cross entropy (deprecated)
    BCE_                ///< binary_cross_entropy (maybe unused)
};

enum class OptimizationId : std::uint8_t
{
    undefined,          ///< Default null value
    grad_descent,       ///< Gradient descent optimizer
    momentum,           ///< Momentum (slowed & stable)
    nestorov,           ///< Nesterov accelerated gradient (modified momentum)
    ada_grad,           ///< Adaptive Gradient algorithm (stable)
    rms_prop,           ///< Root Mean Square Propagation (horny)
    adam,               ///< Adaptive moment estimation (quick)
};

struct OptimizerType
{
public:
    TRIXY_CHECK_TYPE_HELPER(OptimizationId, undefined);
    TRIXY_CHECK_TYPE_HELPER(OptimizationId, grad_descent);
    TRIXY_CHECK_TYPE_HELPER(OptimizationId, momentum);
    TRIXY_CHECK_TYPE_HELPER(OptimizationId, nestorov);
    TRIXY_CHECK_TYPE_HELPER(OptimizationId, ada_grad);
    TRIXY_CHECK_TYPE_HELPER(OptimizationId, rms_prop);
    TRIXY_CHECK_TYPE_HELPER(OptimizationId, adam);

private:
    template <OptimizationId id> struct from
    : meta::disjunction<
        undefined::check<id>,
        grad_descent::check<id>,
        momentum::check<id>,
        nestorov::check<id>,
        ada_grad::check<id>,
        rms_prop::check<id>,
        adam::check<id>>
    {};

public:
    template <OptimizationId id>
    using type_from = typename from<id>::type;
};

} // namespace functional

} // namespace trixy

#include "Trixy/Neuro/Detail/MacroUnscope.hpp"

#endif // ID_FUNCTIONAL_HPP
