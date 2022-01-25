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
    : public IOptimizer<Optimizeriable>
{
private:
    template <class T>
    using Container      = typename Optimizeriable::template ContainerType<T>;

    using Tensor1D       = typename Optimizeriable::Tensor1D;
    using Tensor2D       = typename Optimizeriable::Tensor2D;

    using precision_type = typename Optimizeriable::precision_type;
    using size_type      = typename Optimizeriable::size_type;

private:
    Optimizeriable& net;

    precision_type learning_rate;

    precision_type momentum;

    Container<Tensor1D> buff1;
    Container<Tensor2D> buff2;

    Container<Tensor1D> optimizedB;
    Container<Tensor2D> optimizedW;

public:
    Optimizer(Optimizeriable& network,
              precision_type learning_rate,
              precision_type momentum = 0.9);

    void set_learning_rate(precision_type new_learning_rate) noexcept;

    void update(const Container<Tensor1D>& gradB,
                const Container<Tensor2D>& gradW) noexcept;

    Optimizer& reset() noexcept;

private:
    void initialize_inner_struct();

    template <class Tensor>
    void update(Tensor& buff,
                Tensor& optimized,
                Tensor& parameter,
                const Tensor& grad) noexcept;
};

TRIXY_OPTIMIZER_TPL_DECLARATION
NestorovOptimizer<Optimizeriable>::Optimizer(
    Optimizeriable& network,
    precision_type learning_rate,
    precision_type momentum)
    : net(network)
    , learning_rate(learning_rate)
    , momentum(momentum)
{
    this->template initialize<Optimizer>();

    initialize_inner_struct();
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void NestorovOptimizer<Optimizeriable>::set_learning_rate(
    precision_type new_learning_rate) noexcept
{
    learning_rate = new_learning_rate;
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void NestorovOptimizer<Optimizeriable>::update(
    const Container<Tensor1D>& gradB,
    const Container<Tensor2D>& gradW) noexcept
{
    for(size_type i = 0; i < net.inner.N; ++i)
    {
        update(buff1[i], optimizedB[i], net.inner.B[i], gradB[i]);
        update(buff2[i], optimizedW[i], net.inner.W[i], gradW[i]);
    }
}

TRIXY_OPTIMIZER_TPL_DECLARATION
template <class Tensor>
void NestorovOptimizer<Optimizeriable>::update(
    Tensor& buff,
    Tensor& optimized,
    Tensor& parameter,
    const Tensor& grad) noexcept
{
    // velocity = momentum * velocity - learning_rate * g
    // w = w + momentum * velocity - learning_rate * g

    optimized.join(momentum).sub(
        buff.join(learning_rate, grad)
    );

    parameter.sub(buff).add(
        buff.join(momentum, optimized)
    );
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void NestorovOptimizer<Optimizeriable>::initialize_inner_struct()
{
    buff1.resize(net.inner.N);
    buff2.resize(net.inner.N);

    optimizedB.resize(net.inner.N);
    optimizedW.resize(net.inner.N);

    for(size_type i = 0; i < net.inner.N; ++i)
    {
        buff1[i].resize(net.inner.B[i]. size());
        buff2[i].resize(net.inner.W[i].shape());

        optimizedB[i].resize(net.inner.B[i]. size(), 0.);
        optimizedW[i].resize(net.inner.W[i].shape(), 0.);
    }
}

TRIXY_OPTIMIZER_TPL_DECLARATION
NestorovOptimizer<Optimizeriable>& NestorovOptimizer<Optimizeriable>::reset() noexcept
{
    for(size_type i = 0; i < net.inner.N; ++i)
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
