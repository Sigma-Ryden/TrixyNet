#ifndef GRADIENT_DESCENT_OPTIMIZER_HPP
#define GRADIENT_DESCENT_OPTIMIZER_HPP

#include "BaseOptimizer.hpp"
#include "InterfaceOptimizer.hpp"

#include "Trixy/Neuro/Detail/TrixyNetMeta.hpp"

#include "Trixy/Neuro/Detail/MacroScope.hpp"

namespace trixy
{

namespace train
{

TRIXY_OPTIMIZER_TPL_DECLARATION
using GradDescentOptimizer
    = TRIXY_OPTIMIZER_TPL(meta::is_feedforward_net, OptimizerType::grad_descent);

TRIXY_OPTIMIZER_TPL_DECLARATION
class TRIXY_OPTIMIZER_TPL(meta::is_feedforward_net, OptimizerType::grad_descent)
    : public IOptimizer<GradDescentOptimizer<Optimizeriable>, Optimizeriable>
{
public:
    using Net               = Optimizeriable;

    using Base              = IOptimizer<GradDescentOptimizer<Net>, Net>;

    template <class... T>
    using Container         = typename Net::template Container<T...>;

    using Vector            = typename Net::Vector;
    using Matrix            = typename Net::Matrix;

    using NetInit           = typename Net::Init;

    using precision_type    = typename Net::precision_type;
    using size_type         = typename Net::size_type;

private:
    Net& net;

    Container<Vector> buff1;
    Container<Matrix> buff2;

    precision_type learning_rate;

public:
    Optimizer(Net& network,
              precision_type learning_rate);

    void set_learning_rate(precision_type value) noexcept;

    template <class BiasGrad, class WeightGrad>
    void update(const Container<BiasGrad>& gradB,
                const Container<WeightGrad>& gradW) noexcept;
};

TRIXY_OPTIMIZER_TPL_DECLARATION
GradDescentOptimizer<Optimizeriable>::Optimizer(
    Net& network,
    precision_type learning_rate)
    : Base()
    , net(network)
    , buff1(NetInit::get1d(net.inner.topology))
    , buff2(NetInit::get2d(net.inner.topology))
    , learning_rate(learning_rate)
{
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void GradDescentOptimizer<Optimizeriable>::set_learning_rate(
    precision_type value) noexcept
{
    learning_rate = value;
}

TRIXY_OPTIMIZER_TPL_DECLARATION
template <class BiasGrad, class WeightGrad>
void GradDescentOptimizer<Optimizeriable>::update(
    const Container<BiasGrad>& gradB,
    const Container<WeightGrad>& gradW) noexcept
{
    // w = w - learning_rate * g

    for(size_type i = 0; i < net.inner.N; ++i)
    {
        net.linear.join(buff1[i], learning_rate, gradB[i]);
        net.linear.sub(net.inner.B[i], buff1[i]);

        net.linear.join(buff2[i], learning_rate, gradW[i]);
        net.linear.sub(net.inner.W[i], buff2[i]);
    }
}

} // namespace train

} // namespace trixy

#include "Trixy/Neuro/Detail/MacroUnscope.hpp"

#endif // GRADIENT_DESCENT_OPTIMIZER_HPP
