#ifndef NESTOROV_OPTIMIZER_HPP
#define NESTOROV_OPTIMIZER_HPP

#include "Trixy/Neuro/Functional/Optimizer/BaseOptimizer.hpp"
#include "Trixy/Neuro/Functional/IdFunctional.hpp"

#include "Trixy/Neuro/Detail/TrixyNetMeta.hpp"

#include "Trixy/Neuro/Detail/MacroScope.hpp"

namespace trixy
{

namespace train
{

TRIXY_OPTIMIZER_TPL_DECLARATION
using NestorovOptimizer =
    TRIXY_OPTIMIZER_TPL(meta::is_feedforward_net, functional::OptimizationType::nestorov);

TRIXY_OPTIMIZER_TPL_DECLARATION
class TRIXY_OPTIMIZER_TPL(meta::is_feedforward_net, functional::OptimizationType::nestorov)
    : public BaseOptimizer<Optimizeriable, NestorovOptimizer>
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

    precision_type momentum;

    size_type N;

public:
    Optimizer() noexcept : N(0) {}

    Optimizer(const Optimizeriable& net,
              precision_type learning_rate,
              precision_type momentum = 0.9);

    void setLearnRate(precision_type new_learning_rate) noexcept;

    void update(Container<Tensor1D>& bias,
                Container<Tensor2D>& weight,
                const Container<Tensor1D>& gradBias,
                const Container<Tensor2D>& gradWeight) noexcept;

    void prepare(const Optimizeriable& net,
                 precision_type new_learning_rate,
                 precision_type new_momentum); // deprecated

    Optimizer& reset() noexcept;
};

TRIXY_OPTIMIZER_TPL_DECLARATION
NestorovOptimizer<Optimizeriable>::Optimizer(
    const Optimizeriable& net,
    precision_type learning_rate,
    precision_type momentum)
{
    prepare(net, learning_rate, momentum);
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void NestorovOptimizer<Optimizeriable>::setLearnRate(
    precision_type new_learning_rate) noexcept
{
    learning_rate = new_learning_rate;
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void NestorovOptimizer<Optimizeriable>::update(
    Container<Tensor1D>& bias,
    Container<Tensor2D>& weight,
    const Container<Tensor1D>& gradBias,
    const Container<Tensor2D>& gradWeight) noexcept
{
    // velocity = momentum * velocity - learning_rate * g
    // w = w + momentum * velocity - learning_rate * g

    for(size_type i = 0; i < N; ++i)
    {
        optimizedB[i].join(momentum).sub(
            buff1[i].join(learning_rate, gradBias[i])
        );

        bias[i].sub(buff1[i]).add(
            buff1[i].join(momentum, optimizedB[i])
        );

        optimizedW[i].join(momentum).sub(
            buff2[i].join(learning_rate, gradWeight[i])
        );

        weight[i].sub(buff2[i]).add(
            buff2[i].join(momentum, optimizedW[i])
        );
    }
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void NestorovOptimizer<Optimizeriable>::prepare(
    const Optimizeriable& net,
    precision_type new_learning_rate,
    precision_type new_momentum)
{
    learning_rate = new_learning_rate;
    momentum = new_momentum;

    N = net.getTopology().size() - 1;

    buff1.resize(N);
    buff2.resize(N);

    optimizedB.resize(N);
    optimizedW.resize(N);

    for(size_type i = 0; i < N; ++i)
    {
        buff1[i].resize(net.  getInnerBias()[i]. size());
        buff2[i].resize(net.getInnerWeight()[i].shape());

        optimizedB[i].resize(net.  getInnerBias()[i]. size(), 0.);
        optimizedW[i].resize(net.getInnerWeight()[i].shape(), 0.);
    }
}

TRIXY_OPTIMIZER_TPL_DECLARATION
NestorovOptimizer<Optimizeriable>& NestorovOptimizer<Optimizeriable>::reset() noexcept
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

#include "Trixy/Neuro/Detail/MacroUnscope.hpp"

#endif // NESTOROV_OPTIMIZER_HPP
