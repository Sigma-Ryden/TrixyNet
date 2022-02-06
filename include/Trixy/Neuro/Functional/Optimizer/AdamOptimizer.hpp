#ifndef ADAM_OPTIMIZER_HPP
#define ADAM_OPTIMIZER_HPP

#include "Trixy/Neuro/Functional/Optimizer/BaseOptimizer.hpp"
#include "Trixy/Neuro/Functional/IdFunctional.hpp"

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
    : public IOptimizer<Optimizeriable>
{
    TRIXY_IOPTIMIZER_BODY

private:
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

    LContainer<LVector> optimizedB1;
    LContainer<LMatrix> optimizedW1;

    LContainer<LVector> optimizedB2;
    LContainer<LMatrix> optimizedW2;

    precision_type learning_rate;

    precision_type beta1;
    precision_type beta2;

    precision_type rbeta1;
    precision_type rbeta2;

    precision_type tbeta1;
    precision_type tbeta2;

    precision_type alpha1;
    precision_type alpha2;

public:
    Optimizer(Optimizeriable& network,
              precision_type learning_rate,
              precision_type beta1 = 0.9,
              precision_type beta2 = 0.999);

    //void set_learning_rate(precision_type new_learning_rate) noexcept;

    void update(const Container<LVector>& gradB,
                const Container<LMatrix>& gradW) noexcept;

    Optimizer& reset() noexcept;

private:
    template <class Tensor>
    void update(Tensor& buff,
                Tensor& optimized1,
                Tensor& optimized2,
                Tensor& parameter,
                const Tensor& grad) noexcept;
};

TRIXY_OPTIMIZER_TPL_DECLARATION
AdamOptimizer<Optimizeriable>::Optimizer(
    Optimizeriable& network,
    precision_type learning_rate,
    precision_type beta1,
    precision_type beta2)
    : net(network)
    , buff1(Optimizeriable::init1D(net.inner.topology))
    , buff2(Optimizeriable::init2D(net.inner.topology))
    , optimizedB1(Optimizeriable::init1D(net.inner.topology, 0.))
    , optimizedW1(Optimizeriable::init2D(net.inner.topology, 0.))
    , optimizedB2(Optimizeriable::init1D(net.inner.topology, 0.))
    , optimizedW2(Optimizeriable::init2D(net.inner.topology, 0.))
    , learning_rate(learning_rate)
    , beta1(beta1)
    , beta2(beta2)
{
    rbeta1 = 1. - beta1;
    rbeta2 = 1. - beta2;

    tbeta1 = 1.;
    tbeta2 = 1.;

    this->template initialize<Optimizer>();
}
/*
TRIXY_OPTIMIZER_TPL_DECLARATION
void AdamOptimizer<Optimizeriable>::set_learning_rate(
    precision_type new_learning_rate) noexcept
{
    learning_rate = new_learning_rate;
}
*/
TRIXY_OPTIMIZER_TPL_DECLARATION
void AdamOptimizer<Optimizeriable>::update(
    const Container<LVector>& gradB,
    const Container<LMatrix>& gradW) noexcept
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
template <class Tensor>
void AdamOptimizer<Optimizeriable>::update(
    Tensor& buff,
    Tensor& optimized1,
    Tensor& optimized2,
    Tensor& parameter,
    const Tensor& grad) noexcept
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
