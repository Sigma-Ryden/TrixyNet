#ifndef RMS_PROP_OPTIMIZER_HPP
#define RMS_PROP_OPTIMIZER_HPP

#include "Trixy/Neuro/Functional/Optimization/base_optimizer.hpp"
#include "Trixy/Neuro/Functional/neuro_functional_id.hpp"

#include "Trixy/Neuro/Detail/function_detail.hpp"
#include "Trixy/Neuro/Detail/neuro_meta.hpp"

#include "Trixy/Neuro/Detail/macro_scope.hpp"

namespace trixy
{

namespace train
{

TRIXY_OPTIMIZER_TPL_DECLARATION
using RMSPropOptimizer =
    TRIXY_OPTIMIZER_TPL(meta::is_feedforward_net, functional::OptimizationId::rms_prop);

TRIXY_OPTIMIZER_TPL_DECLARATION
class TRIXY_OPTIMIZER_TPL(meta::is_feedforward_net, functional::OptimizationId::rms_prop)
{
private:
    template <class T>
    using Container      = typename Optimizeriable::template ContainerType<T>;

    using Tensor1D       = typename Optimizeriable::Tensor1D;
    using Tensor2D       = typename Optimizeriable::Tensor2D;

    using precision_type = typename Optimizeriable::precision_type;
    using size_type      = typename Optimizeriable::size_type;

private:
    Container<Tensor1D> buff1;
    Container<Tensor2D> buff2;

    Container<Tensor1D> optimizedB;
    Container<Tensor2D> optimizedW;

    precision_type learning_rate;

    precision_type beta;
    precision_type rbeta;

    size_type N;

public:
    Optimizer() noexcept : N(0) {}

    Optimizer(const Optimizeriable& net,
              precision_type learning_rate,
              precision_type beta = 0.9);

    void setLearnRate(precision_type new_learning_rate) noexcept;

    void update(Container<Tensor1D>& bias,
                Container<Tensor2D>& weight,
                const Container<Tensor1D>& gradBias,
                const Container<Tensor2D>& gradWeight) noexcept;

    void prepare(const Optimizeriable& net,
                 precision_type new_learning_rate,
                 precision_type new_beta); // deprecated

    Optimizer& reset() noexcept;
};

TRIXY_OPTIMIZER_TPL_DECLARATION
RMSPropOptimizer<Optimizeriable>::Optimizer(
    const Optimizeriable& net,
    precision_type learning_rate,
    precision_type beta)
{
    prepare(net, learning_rate, beta);
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void RMSPropOptimizer<Optimizeriable>::setLearnRate(
    precision_type new_learning_rate) noexcept
{
    learning_rate = new_learning_rate;
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void RMSPropOptimizer<Optimizeriable>::update(
    Container<Tensor1D>& bias,
    Container<Tensor2D>& weight,
    const Container<Tensor1D>& gradBias,
    const Container<Tensor2D>& gradWeight) noexcept
{
    // velocity = beta * velocity + (1 - beta) * g * g
    // w = w - learning_rate * g / sqrt(velocity)

    for(size_type i = 0; i < N; ++i)
    {
        optimizedB[i].join(beta).add(
            buff1[i].multiply(gradBias[i], gradBias[i])
                    .join(rbeta)
        );

        bias[i].sub(
            buff1[i].apply(detail::invertSqrt, optimizedB[i])
                    .multiply(gradBias[i])
                    .join(learning_rate)
        );

        optimizedW[i].join(beta).add(
            buff2[i].multiply(gradWeight[i], gradWeight[i])
                    .join(rbeta)
        );

        weight[i].sub(
            buff2[i].apply(detail::invertSqrt, optimizedW[i])
                    .multiply(gradWeight[i])
                    .join(learning_rate)
        );
    }
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void RMSPropOptimizer<Optimizeriable>::prepare(
    const Optimizeriable& net,
    precision_type new_learning_rate,
    precision_type new_beta)
{
    learning_rate = new_learning_rate;

    beta = new_beta;
    rbeta = 1. - new_beta;

    N = net.getTopology().size() - 1;

    buff1.resize(N);
    buff2.resize(N);

    optimizedB.resize(N);
    optimizedW.resize(N);

    for(size_type i = 0; i < N; ++i)
    {
        buff1[i].resize(net.  getInnerBias()[i].size());
        buff2[i].resize(net.getInnerWeight()[i].size());

        optimizedB[i].resize(net.  getInnerBias()[i].size(), 0.);
        optimizedW[i].resize(net.getInnerWeight()[i].size(), 0.);
    }
}

TRIXY_OPTIMIZER_TPL_DECLARATION
RMSPropOptimizer<Optimizeriable>& RMSPropOptimizer<Optimizeriable>::reset() noexcept
{
    for(size_type i = 0; i < N; ++i)
    {
        optimizedB[i].fill(0.);
        optimizedW[i].fill(0.);
    }

    return *this;
}

} // namespace train

} // namespace trixy

#include "Trixy/Neuro/Detail/macro_unscope.hpp"

#endif // RMS_PROP_OPTIMIZER_HPP
