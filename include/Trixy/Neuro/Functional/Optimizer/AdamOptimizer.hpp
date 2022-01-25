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
    TRIXY_OPTIMIZER_TPL(meta::is_feedforward_net, functional::OptimizationType::adam);

TRIXY_OPTIMIZER_TPL_DECLARATION
class TRIXY_OPTIMIZER_TPL(meta::is_feedforward_net, functional::OptimizationType::adam)
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

    precision_type beta1;
    precision_type beta2;

    precision_type rbeta1;
    precision_type rbeta2;

    precision_type tbeta1;
    precision_type tbeta2;

    precision_type alpha1;
    precision_type alpha2;

    Container<Tensor1D> buff1;
    Container<Tensor2D> buff2;

    Container<Tensor1D> optimizedB1;
    Container<Tensor2D> optimizedW1;

    Container<Tensor1D> optimizedB2;
    Container<Tensor2D> optimizedW2;

public:
    Optimizer(Optimizeriable& network,
              precision_type learning_rate,
              precision_type beta1 = 0.9,
              precision_type beta2 = 0.999);

    void set_learning_rate(precision_type new_learning_rate) noexcept;

    void update(const Container<Tensor1D>& gradB,
                const Container<Tensor2D>& gradW) noexcept;

    Optimizer& reset() noexcept;

private:
    void initialize_inner_struct();

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
    , learning_rate(learning_rate)
    , beta1(beta1)
    , beta2(beta2)
{
    this->template initialize<Optimizer>();

    initialize_inner_struct();
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void AdamOptimizer<Optimizeriable>::set_learning_rate(
    precision_type new_learning_rate) noexcept
{
    learning_rate = new_learning_rate;
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void AdamOptimizer<Optimizeriable>::update(
    const Container<Tensor1D>& gradB,
    const Container<Tensor2D>& gradW) noexcept
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
    // m = beta1 * m - (1 - beta1) * g
    // s = beta2 * m + (1 - beta2) * g * g

    // xm = m / (1 - beta1 ^ t)
    // xs = x / (1 - beta2 ^ t)

    // w = w + learning_rate * xm / sqrt(xs)

    // where: t - is number of calls this function (or number of iteration in train)

    optimized1.join(beta1).add(
        buff.join(rbeta1, grad)
    );

    optimized2.join(beta2).add(
        buff.multiply(grad, grad)
            .join(rbeta2)
    );

    parameter.sub(
        buff.join(alpha2, optimized2)
            .apply(detail::invertSqrt)
            .multiply(optimized1)
            .join(alpha1)
    );
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void AdamOptimizer<Optimizeriable>::initialize_inner_struct()
{
    rbeta1 = 1. - beta1;
    rbeta2 = 1. - beta2;

    tbeta1 = 1.;
    tbeta2 = 1.;

    buff1.resize(net.inner.N);
    buff2.resize(net.inner.N);

    optimizedB1.resize(net.inner.N);
    optimizedW1.resize(net.inner.N);

    optimizedB2.resize(net.inner.N);
    optimizedW2.resize(net.inner.N);

    for(size_type i = 0; i < net.inner.N; ++i)
    {
        buff1[i].resize(net.inner.B[i]. size());
        buff2[i].resize(net.inner.W[i].shape());

        optimizedB1[i].resize(net.inner.B[i]. size(), 0.);
        optimizedW1[i].resize(net.inner.W[i].shape(), 0.);

        optimizedB2[i].resize(net.inner.B[i]. size(), 0.);
        optimizedW2[i].resize(net.inner.W[i].shape(), 0.);
    }
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
