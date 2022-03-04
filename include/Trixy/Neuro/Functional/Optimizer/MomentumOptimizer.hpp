#ifndef MOMENTUM_OPTIMIZER_HPP
#define MOMENTUM_OPTIMIZER_HPP

#include "Trixy/Neuro/Functional/Optimizer/BaseOptimizer.hpp"
#include "Trixy/Neuro/Functional/IdFunctional.hpp"

#include "Trixy/Neuro/Detail/TrixyNetMeta.hpp"

#include "Trixy/Neuro/Detail/MacroScope.hpp"

namespace trixy
{

namespace train
{

TRIXY_OPTIMIZER_TPL_DECLARATION
using MomentumOptimizer =
    TRIXY_OPTIMIZER_TPL(meta::is_feedforward_net, OptimizerType::momentum);

TRIXY_OPTIMIZER_TPL_DECLARATION
class TRIXY_OPTIMIZER_TPL(meta::is_feedforward_net, OptimizerType::momentum)
    : public IOptimizer<Optimizeriable>
{
    TRIXY_IOPTIMIZER_BODY

public:
    template <class... T>
    using Container         = typename Optimizeriable::template Container<T...>;

    template <class... T>
    using LContainer        = typename Optimizeriable::template LContainer<T...>;

    using LVector           = typename Optimizeriable::LVector;
    using LMatrix           = typename Optimizeriable::LMatrix;

    using precision_type    = typename Optimizeriable::precision_type;
    using size_type         = typename Optimizeriable::size_type;

private:
    Optimizeriable& net;

    LContainer<LVector> buff1;
    LContainer<LMatrix> buff2;

    LContainer<LVector> optimizedB;
    LContainer<LMatrix> optimizedW;

    precision_type learning_rate;

    precision_type momentum;

public:
    Optimizer(Optimizeriable& network,
              precision_type learning_rate,
              precision_type momentum = 0.9);

    void set_learning_rate(precision_type new_learning_rate) noexcept;

    void update(const Container<LVector>& gradB,
                const Container<LMatrix>& gradW) noexcept;

    Optimizer& reset() noexcept;

private:
    template <class Tensor>
    void update(Tensor& buff,
                Tensor& optimized,
                Tensor& parameter,
                const Tensor& grad) noexcept;
};

TRIXY_OPTIMIZER_TPL_DECLARATION
MomentumOptimizer<Optimizeriable>::Optimizer(
    Optimizeriable& network,
    precision_type learning_rate,
    precision_type momentum)
    : Base()
    , net(network)
    , buff1(Optimizeriable::initlock1D(net.inner.topology))
    , buff2(Optimizeriable::initlock2D(net.inner.topology))
    , optimizedB(Optimizeriable::initlock1D(net.inner.topology, 0.))
    , optimizedW(Optimizeriable::initlock2D(net.inner.topology, 0.))
    , learning_rate(learning_rate)
    , momentum(momentum)
{
    this->template initialize<Optimizer>();
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void MomentumOptimizer<Optimizeriable>::set_learning_rate(
    precision_type new_learning_rate) noexcept
{
    learning_rate = new_learning_rate;
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void MomentumOptimizer<Optimizeriable>::update(
    const Container<LVector>& gradB,
    const Container<LMatrix>& gradW) noexcept
{
    for(size_type i = 0; i < net.inner.N; ++i)
    {
        update(buff1[i], optimizedB[i], net.inner.B[i], gradB[i]);
        update(buff2[i], optimizedW[i], net.inner.W[i], gradW[i]);
    }
}

TRIXY_OPTIMIZER_TPL_DECLARATION
template <class Tensor>
void MomentumOptimizer<Optimizeriable>::update(
    Tensor& buff,
    Tensor& optimized,
    Tensor& parameter,
    const Tensor& grad) noexcept
{
    // velocity = momentum * velocity - learning_rate * g
    // w = w + velocity

    net.linear.join(optimized, momentum);
    net.linear.join(buff, learning_rate, grad);
    net.linear.sub(optimized, buff);

    net.linear.add(parameter, optimized);
}

TRIXY_OPTIMIZER_TPL_DECLARATION
MomentumOptimizer<Optimizeriable>& MomentumOptimizer<Optimizeriable>::reset() noexcept
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

#endif // MOMENTUM_OPTIMIZER_HPP
