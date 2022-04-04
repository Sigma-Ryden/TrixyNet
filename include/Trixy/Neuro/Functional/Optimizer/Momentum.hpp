#ifndef TRIXY_OPTIMIZER_MOMENTUM_HPP
#define TRIXY_OPTIMIZER_MOMENTUM_HPP

#include "Base.hpp"
#include "Interface.hpp"

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
    : public IOptimizer<MomentumOptimizer<Optimizeriable>, Optimizeriable>
{
public:
    using Net  = Optimizeriable;
    using Base = IOptimizer<MomentumOptimizer<Net>, Net>;

    friend Base;

public:
    template <typename T>
    using Container = typename Base::template Container<T>;

    using typename Base::Vector;
    using typename Base::Matrix;

    using typename Base::NetInit;

    using typename Base::precision_type;
    using typename Base::size_type;

private:
    Net& net;

    Container<Vector> buff1;
    Container<Matrix> buff2;

    Container<Vector> optimizedB;
    Container<Matrix> optimizedW;

    precision_type learning_rate;

    precision_type momentum;

public:
    Optimizer(Net& network,
              precision_type learning_rate,
              precision_type momentum = 0.9);

    Optimizer& reset() noexcept;

private:
    void set_learning_rate(precision_type value) noexcept;

    template <class BiasGrad, class WeightGrad>
    void update(const Container<BiasGrad>& gradB,
                const Container<WeightGrad>& gradW) noexcept;

private:
    template <class Buffer, class Optimized, class Parameter, class Gradient>
    void update(Buffer& buff,
                Optimized& optimized,
                Parameter& parameter,
                const Gradient& grad) noexcept;
};

TRIXY_OPTIMIZER_TPL_DECLARATION
MomentumOptimizer<Optimizeriable>::Optimizer(
    Net& network,
    precision_type learning_rate,
    precision_type momentum)
    : Base()
    , net(network)
    , buff1(NetInit::get1d(net.inner.topology))
    , buff2(NetInit::get2d(net.inner.topology))
    , optimizedB(NetInit::get1d(net.inner.topology, 0.))
    , optimizedW(NetInit::get2d(net.inner.topology, 0.))
    , learning_rate(learning_rate)
    , momentum(momentum)
{
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void MomentumOptimizer<Optimizeriable>::set_learning_rate(
    precision_type value) noexcept
{
    learning_rate = value;
}

TRIXY_OPTIMIZER_TPL_DECLARATION
template <class BiasGrad, class WeightGrad>
void MomentumOptimizer<Optimizeriable>::update(
    const Container<BiasGrad>& gradB,
    const Container<WeightGrad>& gradW) noexcept
{
    for(size_type i = 0; i < net.inner.N; ++i)
    {
        update(buff1[i], optimizedB[i], net.inner.B[i], gradB[i]);
        update(buff2[i], optimizedW[i], net.inner.W[i], gradW[i]);
    }
}

TRIXY_OPTIMIZER_TPL_DECLARATION
template <class Buffer, class Optimized, class Parameter, class Gradient>
void MomentumOptimizer<Optimizeriable>::update(
    Buffer& buff,
    Optimized& optimized,
    Parameter& parameter,
    const Gradient& grad) noexcept
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

#endif // TRIXY_OPTIMIZER_MOMENTUM_HPP
