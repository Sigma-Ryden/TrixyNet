#ifndef TRIXY_OPTIMIZER_GRADIENT_DESCENT_HPP
#define TRIXY_OPTIMIZER_GRADIENT_DESCENT_HPP

#include <Trixy/Neuro/Functional/Optimizer/Base.hpp>
#include <Trixy/Neuro/Functional/Optimizer/Interface.hpp>

#include <Trixy/Neuro/Detail/TrixyNetMeta.hpp>

#include <Trixy/Neuro/Detail/MacroScope.hpp>

namespace trixy
{

namespace train
{

TRIXY_OPTIMIZER_TPL_DECLARATION
using GradDescent
    = TRIXY_OPTIMIZER_TPL(meta::is_feedforward_net, OptimizerType::grad_descent);

TRIXY_OPTIMIZER_TPL_DECLARATION
class TRIXY_OPTIMIZER_TPL(meta::is_feedforward_net, OptimizerType::grad_descent)
    : public IOptimizer<GradDescent<Optimizeriable>, Optimizeriable>
{
public:
    using Net  = Optimizeriable;
    using Base = IOptimizer<GradDescent<Net>, Net>;

public:
    template <typename T>
    using Container = typename Base::template Container<T>;

    using typename Base::Vector;
    using typename Base::Matrix;

    using typename Base::Builder;

    using typename Base::precision_type;
    using typename Base::size_type;

private:
    Net& net;

    Container<Vector> buff1;
    Container<Matrix> buff2;

    precision_type learning_rate_;

public:
    Optimizer(Net& network,
              precision_type learning_rate);

    precision_type learning_rate() const noexcept { return learning_rate_; }
    void learning_rate(precision_type value) noexcept;

    template <class BiasGrad, class WeightGrad>
    void update(const Container<BiasGrad>& gradB,
                const Container<WeightGrad>& gradW) noexcept;
};

TRIXY_OPTIMIZER_TPL_DECLARATION
GradDescent<Optimizeriable>::Optimizer(
    Net& network,
    precision_type learning_rate)
    : Base()
    , net(network)
    , buff1(Builder::get1d(net.inner.topology))
    , buff2(Builder::get2d(net.inner.topology))
    , learning_rate_(learning_rate)
{
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void GradDescent<Optimizeriable>::learning_rate(
    precision_type value) noexcept
{
    learning_rate_ = value;
}

TRIXY_OPTIMIZER_TPL_DECLARATION
template <class BiasGrad, class WeightGrad>
void GradDescent<Optimizeriable>::update(
    const Container<BiasGrad>& gradB,
    const Container<WeightGrad>& gradW) noexcept
{
    // w = w - learning_rate * g

    for (size_type i = 0; i < net.inner.N; ++i)
    {
        net.linear.join(buff1[i], learning_rate_, gradB[i]);
        net.linear.sub(net.inner.B[i], buff1[i]);

        net.linear.join(buff2[i], learning_rate_, gradW[i]);
        net.linear.sub(net.inner.W[i], buff2[i]);
    }
}

template <class Net, typename... Args>
GradDescent<Net> GradDescentOptimizer(Net& net, Args&&... args)
{
    return GradDescent<Net>(net, std::forward<Args>(args)...);
}

} // namespace train

} // namespace trixy

#include <Trixy/Neuro/Detail/MacroUnscope.hpp>

#endif // TRIXY_OPTIMIZER_GRADIENT_DESCENT_HPP
