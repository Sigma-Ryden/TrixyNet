#ifndef NEURO_FUNCTION_ID_HPP
#define NEURO_FUNCTION_ID_HPP

#include <cstdint> // uint8_t

namespace trixy
{

namespace function
{

enum class ActivationId : std::uint8_t
{
    undefined,         ///< default null value
    identity,          ///< same value from input
    sigmoid,           ///< sigmoid(x) = 1 / (exp(-x) + 1)
    tanh,              ///< hyperbolic tangent
    relu,              ///< relu(x) = max(0,x) (Rectified Linear Unit)
    elu,               ///< exponential relu with alpha = 0.2
    lrelu,             ///< leaky relu (same as relu, but with low negative signal)
    selu,              ///< exponential relu with lambda = 1.050701, beta = 1.758099
    gelu,              ///< gaussian relu
    softsign,          ///< absolute value hyperbola
    softplus,          ///< logarithm with exponential argument
    swish,             ///< same as relu & sigmoid
    softmax,           ///< normalization function
    mod_relu,          ///< relu for range [0, 1]
    mod_tanh,          ///< tanh for range [0, 1]
    unstable_softmax,  ///< deprecated
    sigmoid_           ///< maybe unused
};

enum class LossId : std::uint8_t
{
    undefined,  ///< default null value
    MSE,        ///< mean squared error
    MAE,        ///< mean absolute error
    CCE,        ///< categorical cross entropy (for softmax)
    BCE,        ///< binary cross entropy (for sigmoid)
    MSLE,       ///< mean squared logarithmic error
    NLL,        ///< negative logarithmic likelihood (for softmax)
    LC,         ///< logcosh (maybe unused)
    CCE_,       ///< categorical cross entropy (deprecated)
    BCE_        ///< binary_cross_entropy (maybe unused)
};

enum class OptimizationId : std::uint8_t
{
    undefined,  ///< default null value
    momentum,   ///< Momentum (slowed & stable)
    rms_prop,   ///< RMSProp - root mean square propagation (horny)
    ada_grad    ///< Adagrad - adaptive gradient algorithm (stable)
};

} // namespace function

} // namespace trixy

#endif // NEURO_FUNCTION_ID_HPP