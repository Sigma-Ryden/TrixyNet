#ifndef NEURO_FUNCTIONAL_ID_HPP
#define NEURO_FUNCTIONAL_ID_HPP

#include <cstdint> // uint8_t

#include "Trixy/Neuro/Detail/neuro_meta.hpp"

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

struct OptimizationType
{
public:
    struct undefined
    {
        template <OptimizationId id>
        using check = meta::select_for<id == OptimizationId::undefined, undefined>;
    };

    struct grad_descent
    {
        template <OptimizationId id>
        using check = meta::select_for<id == OptimizationId::grad_descent, grad_descent>;
    };

    struct momentum
    {
        template <OptimizationId id>
        using check = meta::select_for<id == OptimizationId::momentum, momentum>;
    };

    struct nestorov
    {
        template <OptimizationId id>
        using check = meta::select_for<id == OptimizationId::nestorov, nestorov>;
    };

    struct ada_grad
    {
        template <OptimizationId id>
        using check = meta::select_for<id == OptimizationId::ada_grad, ada_grad>;
    };

    struct rms_prop
    {
        template <OptimizationId id>
        using check = meta::select_for<id == OptimizationId::rms_prop, rms_prop>;
    };

    struct adam
    {
        template <OptimizationId id>
        using check = meta::select_for<id == OptimizationId::adam, adam>;
    };

private:
    template <OptimizationId id> struct from : meta::disjunction<
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

#endif // NEURO_FUNCTIONAL_ID_HPP
