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
    : public BaseOptimizer<Optimizeriable, AdamOptimizer>
{
private:
    template <class T>
    using Container      = typename Optimizeriable::template ContainerType<T>;

    using Tensor1D       = typename Optimizeriable::Tensor1D;
    using Tensor2D       = typename Optimizeriable::Tensor2D;

    using precision_type = typename Optimizeriable::precision_type;
    using size_type      = typename Optimizeriable::size_type;

private:
    Container<Tensor1D> buff1;
    Container<Tensor2D> buff2;

    Container<Tensor1D> optimizedB1;
    Container<Tensor2D> optimizedW1;

    Container<Tensor1D> optimizedB2;
    Container<Tensor2D> optimizedW2;

    precision_type learning_rate;

    precision_type beta1;
    precision_type beta2;

    precision_type rbeta1;
    precision_type rbeta2;

    precision_type tbeta1;
    precision_type tbeta2;

    precision_type alpha1;
    precision_type alpha2;

    size_type N;

public:
    Optimizer() noexcept : N(0) {}

    Optimizer(const Optimizeriable& net,
              precision_type learning_rate,
              precision_type beta1 = 0.9,
              precision_type beta2 = 0.999);

    void setLearnRate(precision_type new_learning_rate) noexcept;

    void update(Container<Tensor1D>& bias,
                Container<Tensor2D>& weight,
                const Container<Tensor1D>& gradBias,
                const Container<Tensor2D>& gradWeight) noexcept;

    void prepare(const Optimizeriable& net,
                 precision_type new_learning_rate,
                 precision_type new_beta1,
                 precision_type new_beta2); // deprecated

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
    const Optimizeriable& net,
    precision_type learning_rate,
    precision_type beta1,
    precision_type beta2)
{
    prepare(net, learning_rate, beta1, beta2);
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void AdamOptimizer<Optimizeriable>::setLearnRate(
    precision_type new_learning_rate) noexcept
{
    learning_rate = new_learning_rate;
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void AdamOptimizer<Optimizeriable>::update(
    Container<Tensor1D>& bias,
    Container<Tensor2D>& weight,
    const Container<Tensor1D>& gradBias,
    const Container<Tensor2D>& gradWeight) noexcept
{
    tbeta1 *= beta1;
    tbeta2 *= beta2;

    alpha1 = learning_rate / (1. - tbeta1);
    alpha2 = 1. / (1. - tbeta2);

    for(size_type i = 0; i < N; ++i)
    {
        update(buff1[i], optimizedB1[i], optimizedB2[i],   bias[i],   gradBias[i]);
        update(buff2[i], optimizedW1[i], optimizedW2[i], weight[i], gradWeight[i]);
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
void AdamOptimizer<Optimizeriable>::prepare(
    const Optimizeriable& net,
    precision_type new_learning_rate,
    precision_type new_beta1,
    precision_type new_beta2)
{
    learning_rate = new_learning_rate;

    beta1 = new_beta1;
    beta2 = new_beta2;

    rbeta1 = 1. - beta1;
    rbeta2 = 1. - beta2;

    tbeta1 = 1.;
    tbeta2 = 1.;

    N = net.getTopology().size() - 1;

    buff1.resize(N);
    buff2.resize(N);

    optimizedB1.resize(N);
    optimizedW1.resize(N);

    optimizedB2.resize(N);
    optimizedW2.resize(N);

    for(size_type i = 0; i < N; ++i)
    {
        buff1[i].resize(net.  getInnerBias()[i]. size());
        buff2[i].resize(net.getInnerWeight()[i].shape());

        optimizedB1[i].resize(net.  getInnerBias()[i]. size(), 0.);
        optimizedW1[i].resize(net.getInnerWeight()[i].shape(), 0.);

        optimizedB2[i].resize(net.  getInnerBias()[i]. size(), 0.);
        optimizedW2[i].resize(net.getInnerWeight()[i].shape(), 0.);
    }
}

TRIXY_OPTIMIZER_TPL_DECLARATION
AdamOptimizer<Optimizeriable>& AdamOptimizer<Optimizeriable>::reset() noexcept
{
    tbeta1 = 1.;
    tbeta2 = 1.;

    for(size_type i = 0; i < N; ++i)
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
