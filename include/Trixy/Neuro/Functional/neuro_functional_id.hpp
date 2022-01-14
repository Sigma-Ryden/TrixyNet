#ifndef NEURO_FUNCTIONAL_ID_HPP
#define NEURO_FUNCTIONAL_ID_HPP

#include <cstdint> // uint8_t
#include <type_traits> // enable_if, conditional, integral_constant

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
private:
    template <bool condition, typename T>
    struct select_if : std::enable_if<condition, T>
    {
        static constexpr bool value = condition;
    };

    template <class...> struct switch_enable : std::true_type {};
    template <class B1> struct switch_enable<B1> : B1 {};
    template <class B1, class... Bn>
    struct switch_enable<B1, Bn...>
        : std::conditional<bool(B1::value), B1, switch_enable<Bn...>>::type {};

public:
    struct undefined;
    struct grad_descent;
    struct momentum;
    struct nestorov;
    struct ada_grad;
    struct rms_prop;
    struct adam;

    template <OptimizationId id>
    struct from : switch_enable<
        select_if<id == OptimizationId::undefined,    undefined>,
        select_if<id == OptimizationId::grad_descent, grad_descent>,
        select_if<id == OptimizationId::momentum,     momentum>,
        select_if<id == OptimizationId::nestorov,     nestorov>,
        select_if<id == OptimizationId::ada_grad,     ada_grad>,
        select_if<id == OptimizationId::rms_prop,     rms_prop>,
        select_if<id == OptimizationId::adam,         adam>>
    {};
};

} // namespace functional

} // namespace trixy

#endif // NEURO_FUNCTIONAL_ID_HPP
