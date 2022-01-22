#ifndef RMS_PROP_OPTIMIZER_HPP
#define RMS_PROP_OPTIMIZER_HPP

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
using RMSPropOptimizer =
    TRIXY_OPTIMIZER_TPL(meta::is_feedforward_net, functional::OptimizationType::rms_prop);

TRIXY_OPTIMIZER_TPL_DECLARATION
class TRIXY_OPTIMIZER_TPL(meta::is_feedforward_net, functional::OptimizationType::rms_prop)
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
    Container<Tensor1D> buff1;
    Container<Tensor2D> buff2;

    Container<Tensor1D> optimizedB;
    Container<Tensor2D> optimizedW;

    precision_type learning_rate;

    precision_type beta;
    precision_type rbeta;

    size_type N;

public:
    Optimizer() noexcept : N(0) { this->template initialize<Optimizer>(); }

    Optimizer(const Optimizeriable& net,
              precision_type learning_rate,
              precision_type beta = 0.9);

    void set_learning_rate(precision_type new_learning_rate) noexcept;

    void update(Container<Tensor1D>& bias,
                Container<Tensor2D>& weight,
                const Container<Tensor1D>& grad_bias,
                const Container<Tensor2D>& grad_weight) noexcept;

    void prepare(const Optimizeriable& net,
                 precision_type new_learning_rate,
                 precision_type new_beta); // deprecated

    Optimizer& reset() noexcept;

private:
    template <class Tensor>
    void update(Tensor& buff,
                Tensor& optimized,
                Tensor& parameter,
                const Tensor& grad) noexcept;
};

TRIXY_OPTIMIZER_TPL_DECLARATION
RMSPropOptimizer<Optimizeriable>::Optimizer(
    const Optimizeriable& net,
    precision_type learning_rate,
    precision_type beta)
{
    this->template initialize<Optimizer>();

    prepare(net, learning_rate, beta);
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void RMSPropOptimizer<Optimizeriable>::set_learning_rate(
    precision_type new_learning_rate) noexcept
{
    learning_rate = new_learning_rate;
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void RMSPropOptimizer<Optimizeriable>::update(
    Container<Tensor1D>& B,
    Container<Tensor2D>& W,
    const Container<Tensor1D>& gradB,
    const Container<Tensor2D>& gradW) noexcept
{
    for(size_type i = 0; i < N; ++i)
    {
        update(buff1[i], optimizedB[i], B[i], gradB[i]);
        update(buff2[i], optimizedW[i], W[i], gradW[i]);
    }
}

TRIXY_OPTIMIZER_TPL_DECLARATION
template <class Tensor>
void RMSPropOptimizer<Optimizeriable>::update(
    Tensor& buff,
    Tensor& optimized,
    Tensor& parameter,
    const Tensor& grad) noexcept
{
    // velocity = beta * velocity + (1 - beta) * g * g
    // w = w - learning_rate * g / sqrt(velocity)

    optimized.join(beta).add(
        buff.multiply(grad, grad)
            .join(rbeta)
    );

    parameter.sub(
        buff.apply(detail::invertSqrt, optimized)
            .multiply(grad)
            .join(learning_rate)
    );
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void RMSPropOptimizer<Optimizeriable>::prepare(
    const Optimizeriable& net,
    precision_type new_learning_rate,
    precision_type new_beta)
{
    learning_rate = new_learning_rate;

    beta = new_beta;
    rbeta = 1. - new_beta;

    N = net.getTopology().size() - 1;

    buff1.resize(N);
    buff2.resize(N);

    optimizedB.resize(N);
    optimizedW.resize(N);

    for(size_type i = 0; i < N; ++i)
    {
        buff1[i].resize(net.  getInnerBias()[i]. size());
        buff2[i].resize(net.getInnerWeight()[i].shape());

        optimizedB[i].resize(net.  getInnerBias()[i]. size(), 0.);
        optimizedW[i].resize(net.getInnerWeight()[i].shape(), 0.);
    }
}

TRIXY_OPTIMIZER_TPL_DECLARATION
RMSPropOptimizer<Optimizeriable>& RMSPropOptimizer<Optimizeriable>::reset() noexcept
{
    for(size_type i = 0; i < N; ++i)
    {
        optimizedB[i].fill(0.);
        optimizedW[i].fill(0.);
    }

    return *this;
}

} // namespace train

} // namespace trixy

#include "Trixy/Neuro/Detail/MacroUnscope.hpp"

#endif // RMS_PROP_OPTIMIZER_HPP
