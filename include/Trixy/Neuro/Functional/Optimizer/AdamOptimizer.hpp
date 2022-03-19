#ifndef ADAM_OPTIMIZER_HPP
#define ADAM_OPTIMIZER_HPP

#include "BaseOptimizer.hpp"
#include "InterfaceOptimizer.hpp"

#include "Trixy/Neuro/Detail/FunctionDetail.hpp"
#include "Trixy/Neuro/Detail/TrixyNetMeta.hpp"

#include "Trixy/Neuro/Detail/MacroScope.hpp"

namespace trixy
{

namespace train
{

TRIXY_OPTIMIZER_TPL_DECLARATION
using AdamOptimizer =
    TRIXY_OPTIMIZER_TPL(meta::is_feedforward_net, OptimizerType::adam);

TRIXY_OPTIMIZER_TPL_DECLARATION
class TRIXY_OPTIMIZER_TPL(meta::is_feedforward_net, OptimizerType::adam)
    : public IOptimizer<AdamOptimizer<Optimizeriable>, Optimizeriable>
{
public:
    using Net               = Optimizeriable;

    using Base              = IOptimizer<AdamOptimizer<Net>, Net>;

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

    Container<Vector> optimizedB1;
    Container<Matrix> optimizedW1;

    Container<Vector> optimizedB2;
    Container<Matrix> optimizedW2;

    precision_type learning_rate;

    precision_type beta1, beta2;
    precision_type rbeta1, rbeta2;

    precision_type tbeta1, tbeta2;

    precision_type alpha1, alpha2;

public:
    Optimizer(Net& network,
              precision_type learning_rate,
              precision_type beta1 = 0.9,
              precision_type beta2 = 0.999);

    void set_learning_rate(precision_type value) noexcept;

    template <class BiasGrad, class WeightGrad>
    void update(const Container<BiasGrad>& gradB,
                const Container<WeightGrad>& gradW) noexcept;

    Optimizer& reset() noexcept;

private:
    template <class Buffer, class Optimized, class Parameter, class Gradient>
    void update(Buffer& buff,
                Optimized& optimized1,
                Optimized& optimized2,
                Parameter& parameter,
                const Gradient& grad) noexcept;
};

TRIXY_OPTIMIZER_TPL_DECLARATION
AdamOptimizer<Optimizeriable>::Optimizer(
    Net& network,
    precision_type learning_rate,
    precision_type beta1,
    precision_type beta2)
    : Base()
    , net(network)
    , buff1(NetInit::get1d(net.inner.topology))
    , buff2(NetInit::get2d(net.inner.topology))
    , optimizedB1(NetInit::get1d(net.inner.topology, 0.))
    , optimizedW1(NetInit::get2d(net.inner.topology, 0.))
    , optimizedB2(NetInit::get1d(net.inner.topology, 0.))
    , optimizedW2(NetInit::get2d(net.inner.topology, 0.))
    , learning_rate(learning_rate)
    , beta1(beta1)
    , beta2(beta2)
{
    rbeta1 = 1. - beta1;
    rbeta2 = 1. - beta2;

    tbeta1 = 1.;
    tbeta2 = 1.;
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void AdamOptimizer<Optimizeriable>::set_learning_rate(
    precision_type value) noexcept
{
    learning_rate = value;
}

TRIXY_OPTIMIZER_TPL_DECLARATION
template <class BiasGrad, class WeightGrad>
void AdamOptimizer<Optimizeriable>::update(
    const Container<BiasGrad>& gradB,
    const Container<WeightGrad>& gradW) noexcept
{
    tbeta1 *= beta1;
    tbeta2 *= beta2;

    alpha1 = learning_rate / (1. - tbeta1);
    alpha2 = 1. / (1. - tbeta2);

    for(size_type i = 0; i < net.inner.N; ++i)
    {
        update(buff1[i], optimizedB1[i], optimizedB2[i], net.inner.B[i], gradB[i]);
        update(buff2[i], optimizedW1[i], optimizedW2[i], net.inner.W[i], gradW[i]);
    }
}

TRIXY_OPTIMIZER_TPL_DECLARATION
template <class Buffer, class Optimized, class Parameter, class Gradient>
void AdamOptimizer<Optimizeriable>::update(
    Buffer& buff,
    Optimized& optimized1,
    Optimized& optimized2,
    Parameter& parameter,
    const Gradient& grad) noexcept
{
    // m = beta1 * m + (1 - beta1) * g
    // s = beta2 * m + (1 - beta2) * g * g

    // xm = m / (1 - beta1 ^ t)
    // xs = x / (1 - beta2 ^ t)

    // w = w - learning_rate * xm / sqrt(xs)

    // where: t - is number of calls this function (or number of iteration in train)

    net.linear.join(optimized1, beta1);
    net.linear.join(buff, rbeta1, grad);
    net.linear.add(optimized1, buff);

    net.linear.join(optimized2, beta2);
    net.linear.mul(buff, grad, grad);
    net.linear.join(buff, rbeta2);
    net.linear.add(optimized2, buff);

    net.linear.join(buff, alpha2, optimized2);
    net.linear.apply(buff, &detail::invert_sqrt<precision_type>);
    net.linear.mul(buff, optimized1);
    net.linear.join(buff, alpha1);

    net.linear.sub(parameter, buff);
}

TRIXY_OPTIMIZER_TPL_DECLARATION
AdamOptimizer<Optimizeriable>& AdamOptimizer<Optimizeriable>::reset() noexcept
{
    tbeta1 = 1.;
    tbeta2 = 1.;

    for(size_type i = 0; i < net.inner.N; ++i)
    {
        optimizedB1[i].fill(0.);
        optimizedW1[i].fill(0.);

        optimizedB2[i].fill(0.);
        optimizedW2[i].fill(0.);
    }

    return *this;
}

} // namespace train

} // namespace trixy

#include "Trixy/Neuro/Detail/MacroUnscope.hpp"

#endif // ADAM_OPTIMIZER_HPP
