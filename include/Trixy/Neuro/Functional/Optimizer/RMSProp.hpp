#ifndef TRIXY_OPTIMIZER_RMS_PROP_HPP
#define TRIXY_OPTIMIZER_RMS_PROP_HPP

#include <Trixy/Neuro/Functional/Optimizer/Base.hpp>
#include <Trixy/Neuro/Functional/Optimizer/Interface.hpp>

#include <Trixy/Detail/FunctionDetail.hpp>
#include <Trixy/Neuro/Detail/TrixyNetMeta.hpp>

#include <Trixy/Neuro/Detail/MacroScope.hpp>

namespace trixy
{

namespace train
{

TRIXY_OPTIMIZER_TPL_DECLARATION
using RMSProp =
    TRIXY_OPTIMIZER_TPL(meta::is_feedforward_net, OptimizerType::rms_prop);

TRIXY_OPTIMIZER_TPL_DECLARATION
class TRIXY_OPTIMIZER_TPL(meta::is_feedforward_net, OptimizerType::rms_prop)
    : public IOptimizer<RMSProp<Optimizeriable>, Optimizeriable>
{
public:
    using Net  = Optimizeriable;
    using Base = IOptimizer<RMSProp<Net>, Net>;

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

    Container<Vector> optimizedB;
    Container<Matrix> optimizedW;

    precision_type learning_rate_;

    precision_type beta, rbeta;

public:
    Optimizer(Net& network,
              precision_type learning_rate,
              precision_type beta = 0.9);

    Optimizer& reset() noexcept;

    precision_type learning_rate() const noexcept { return learning_rate_; }
    void learning_rate(precision_type value) noexcept;

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
RMSProp<Optimizeriable>::Optimizer(
    Net& network,
    precision_type learning_rate,
    precision_type beta)
    : Base()
    , net(network)
    , buff1(Builder::get1d(net.inner.topology))
    , buff2(Builder::get2d(net.inner.topology))
    , optimizedB(Builder::get1d(net.inner.topology, 0.))
    , optimizedW(Builder::get2d(net.inner.topology, 0.))
    , learning_rate_(learning_rate)
    , beta(beta)
{
    rbeta = 1. - beta;
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void RMSProp<Optimizeriable>::learning_rate(
    precision_type value) noexcept
{
    learning_rate_ = value;
}

TRIXY_OPTIMIZER_TPL_DECLARATION
template <class BiasGrad, class WeightGrad>
void RMSProp<Optimizeriable>::update(
    const Container<BiasGrad>& gradB,
    const Container<WeightGrad>& gradW) noexcept
{
    for (size_type i = 0; i < net.inner.N; ++i)
    {
        update(buff1[i], optimizedB[i], net.inner.B[i], gradB[i]);
        update(buff2[i], optimizedW[i], net.inner.W[i], gradW[i]);
    }
}

TRIXY_OPTIMIZER_TPL_DECLARATION
template <class Buffer, class Optimized, class Parameter, class Gradient>
void RMSProp<Optimizeriable>::update(
    Buffer& buff,
    Optimized& optimized,
    Parameter& parameter,
    const Gradient& grad) noexcept
{
    // velocity = beta * velocity + (1 - beta) * g * g
    // w = w - learning_rate * g / sqrt(velocity)

    net.linear.join(optimized, beta);
    net.linear.mul(buff, grad, grad);
    net.linear.join(buff, rbeta);
    net.linear.add(optimized, buff);

    net.linear.apply(buff, &detail::invert_sqrt<precision_type>, optimized);
    net.linear.mul(buff, grad);
    net.linear.join(buff, learning_rate_);

    net.linear.sub(parameter, buff);
}

TRIXY_OPTIMIZER_TPL_DECLARATION
RMSProp<Optimizeriable>& RMSProp<Optimizeriable>::reset() noexcept
{
    for (size_type i = 0; i < net.inner.N; ++i)
    {
        optimizedB[i].fill(0.);
        optimizedW[i].fill(0.);
    }

    return *this;
}

template <class Net, typename... Args>
RMSProp<Net> RMSPropOptimizer(Net& net, Args&&... args)
{
    return RMSProp<Net>(net, std::forward<Args>(args)...);
}

} // namespace train

} // namespace trixy

#include <Trixy/Neuro/Detail/MacroUnscope.hpp>

#endif // TRIXY_OPTIMIZER_RMS_PROP_HPP
