// This file contains all enum functional, you MUST prevent rewriting him,
// since changes can breake a TrixyNet deserialization proccess
#ifndef TRIXY_FUNCTIONAL_ID_HPP
#define TRIXY_FUNCTIONAL_ID_HPP

#include <cstdint> // uint8_t

namespace trixy
{

namespace functional
{

enum class ActivationId : std::uint8_t
{
    undefined = 0,          ///< default null value
    identity = 1,           ///< same value from input
    sigmoid = 2,            ///< sigmoid(x) = 1 / (exp(-x) + 1)
    tanh = 3,               ///< hyperbolic tangent
    relu = 4,               ///< relu(x) = max(0, x) (Rectified Linear Unit)
    elu = 5,                ///< exponential relu with alpha = 0.2
    lrelu = 6,              ///< leaky relu (same as relu, but with low negative signal)
    selu = 7,               ///< exponential relu with lambda = 1.050701, beta = 1.758099
    gelu = 8,               ///< gaussian relu
    softsign = 9,           ///< absolute value hyperbola
    softplus = 10,          ///< logarithm with exponential argument
    swish = 11,             ///< same as relu & sigmoid
    softmax = 12,           ///< normalization function
    mod_relu = 13,          ///< relu for range [0, 1]
    mod_tanh = 14,          ///< tanh for range [0, 1]
    unstable_softmax = 15,  ///< deprecated
    size
};

enum class LossId : std::uint8_t
{
    undefined = 0,          ///< default null value
    MSE = 1,                ///< mean squared error
    MAE = 2,                ///< mean absolute error
    CCE = 3,                ///< categorical cross entropy (for softmax)
    BCE = 4,                ///< binary cross entropy (for sigmoid)
    MSLE = 5,               ///< mean squared logarithmic error
    NLL = 6,                ///< negative logarithmic likelihood (for softmax)
    LC = 7,                 ///< logcosh (maybe unused)
    CCE_ = 8,               ///< categorical cross entropy (deprecated)
    BCE_ = 9,               ///< binary_cross_entropy (maybe unused)
    size
};

enum class OptimizationId : std::uint8_t
{
    undefined = 0,          ///< Default null value
    grad_descent = 1,       ///< Gradient descent optimizer
    stograd_descent = 2,    ///< Stochastic Gradient Descent optimizer
    momentum = 3,           ///< Momentum (slowed & stable)
    nestorov = 4,           ///< Nesterov accelerated gradient (modified momentum)
    ada_grad = 5,           ///< Adaptive Gradient algorithm (stable)
    rms_prop = 6,           ///< Root Mean Square Propagation (horny)
    adam = 7,               ///< Adaptive moment estimation (quick)
    size
};

} // namespace functional

} // namespace trixy

#endif // TRIXY_FUNCTIONAL_ID_HPP
