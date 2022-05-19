#ifndef TRIXY_OPTIMIZER_ADAM_HPP
#define TRIXY_OPTIMIZER_ADAM_HPP

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
using Adam =
    TRIXY_OPTIMIZER_TPL(meta::is_feedforward_net, OptimizerType::adam);

TRIXY_OPTIMIZER_TPL_DECLARATION
class TRIXY_OPTIMIZER_TPL(meta::is_feedforward_net, OptimizerType::adam)
    : public IOptimizer<Adam<Optimizeriable>, Optimizeriable>
{
public:
    using Net  = Optimizeriable;
    using Base = IOptimizer<Adam<Net>, Net>;

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

    Container<Vector> optimizedB1;
    Container<Matrix> optimizedW1;

    Container<Vector> optimizedB2;
    Container<Matrix> optimizedW2;

    precision_type learning_rate_;

    precision_type beta1, beta2;
    precision_type rbeta1, rbeta2;

    precision_type tbeta1, tbeta2;

    precision_type alpha1, alpha2;

public:
    Optimizer(Net& network,
              precision_type learning_rate,
              precision_type beta1 = 0.9,
              precision_type beta2 = 0.999);

    Optimizer& reset() noexcept;

    precision_type learning_rate() const noexcept { return learning_rate_; }
    void learning_rate(precision_type value) noexcept;

    template <class BiasGrad, class WeightGrad>
    void update(const Container<BiasGrad>& gradB,
                const Container<WeightGrad>& gradW) noexcept;

private:
    template <class Buffer, class Optimized, class Parameter, class Gradient>
    void update(Buffer& buff,
                Optimized& optimized1,
                Optimized& optimized2,
                Parameter& parameter,
                const Gradient& grad) noexcept;
};

TRIXY_OPTIMIZER_TPL_DECLARATION
Adam<Optimizeriable>::Optimizer(
    Net& network,
    precision_type learning_rate,
    precision_type beta1,
    precision_type beta2)
    : Base()
    , net(network)
    , buff1(Builder::get1d(net.inner.topology))
    , buff2(Builder::get2d(net.inner.topology))
    , optimizedB1(Builder::get1d(net.inner.topology, 0.))
    , optimizedW1(Builder::get2d(net.inner.topology, 0.))
    , optimizedB2(Builder::get1d(net.inner.topology, 0.))
    , optimizedW2(Builder::get2d(net.inner.topology, 0.))
    , learning_rate_(learning_rate)
    , beta1(beta1)
    , beta2(beta2)
{
    rbeta1 = 1. - beta1;
    rbeta2 = 1. - beta2;

    tbeta1 = 1.;
    tbeta2 = 1.;
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void Adam<Optimizeriable>::learning_rate(
    precision_type value) noexcept
{
    learning_rate_ = value;
}

TRIXY_OPTIMIZER_TPL_DECLARATION
template <class BiasGrad, class WeightGrad>
void Adam<Optimizeriable>::update(
    const Container<BiasGrad>& gradB,
    const Container<WeightGrad>& gradW) noexcept
{
    tbeta1 *= beta1;
    tbeta2 *= beta2;

    alpha1 = learning_rate_ / (1. - tbeta1);
    alpha2 = 1. / (1. - tbeta2);

    for (size_type i = 0; i < net.inner.N; ++i)
    {
        update(buff1[i], optimizedB1[i], optimizedB2[i], net.inner.B[i], gradB[i]);
        update(buff2[i], optimizedW1[i], optimizedW2[i], net.inner.W[i], gradW[i]);
    }
}

TRIXY_OPTIMIZER_TPL_DECLARATION
template <class Buffer, class Optimized, class Parameter, class Gradient>
void Adam<Optimizeriable>::update(
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
Adam<Optimizeriable>& Adam<Optimizeriable>::reset() noexcept
{
    tbeta1 = 1.;
    tbeta2 = 1.;

    for (size_type i = 0; i < net.inner.N; ++i)
    {
        optimizedB1[i].fill(0.);
        optimizedW1[i].fill(0.);

        optimizedB2[i].fill(0.);
        optimizedW2[i].fill(0.);
    }

    return *this;
}

template <class Net, typename... Args>
Adam<Net> AdamOptimizer(Net& net, Args&&... args)
{
    return Adam<Net>(net, std::forward<Args>(args)...);
}

} // namespace train

} // namespace trixy

#include <Trixy/Neuro/Detail/MacroUnscope.hpp>

#endif // TRIXY_OPTIMIZER_ADAM_HPP
