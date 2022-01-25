#ifndef ADA_GRAD_OPTIMIZER_HPP
#define ADA_GRAD_OPTIMIZER_HPP

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
using AdaGradOptimizer =
    TRIXY_OPTIMIZER_TPL(meta::is_feedforward_net, functional::OptimizationType::ada_grad);

TRIXY_OPTIMIZER_TPL_DECLARATION
class TRIXY_OPTIMIZER_TPL(meta::is_feedforward_net, functional::OptimizationType::ada_grad)
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

    Container<Tensor1D> buff1;
    Container<Tensor2D> buff2;

    Container<Tensor1D> optimizedB;
    Container<Tensor2D> optimizedW;

public:
    Optimizer(Optimizeriable& network,
              precision_type learning_rate);

    void set_learning_rate(precision_type new_learning_rate) noexcept;

    void update(const Container<Tensor1D>& gradB,
                const Container<Tensor2D>& gradW) noexcept;

    Optimizer& reset() noexcept;

private:
    void initialize_inner_struct();

    template <class Tensor>
    void update(Tensor& buff,
                Tensor& optimized,
                Tensor& parameter,
                const Tensor& grad) noexcept;
};

TRIXY_OPTIMIZER_TPL_DECLARATION
AdaGradOptimizer<Optimizeriable>::Optimizer(
    Optimizeriable& network,
    precision_type learning_rate)
    : net(network)
    , learning_rate(learning_rate)
{
    this->template initialize<Optimizer>();

    initialize_inner_struct();
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void AdaGradOptimizer<Optimizeriable>::set_learning_rate(
    precision_type new_learning_rate) noexcept
{
    learning_rate = new_learning_rate;
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void AdaGradOptimizer<Optimizeriable>::update(
    const Container<Tensor1D>& gradB,
    const Container<Tensor2D>& gradW) noexcept
{
    for(size_type i = 0; i < net.inner.N; ++i)
    {
        update(buff1[i], optimizedB[i], net.inner.B[i], gradB[i]);
        update(buff2[i], optimizedW[i], net.inner.W[i], gradW[i]);
    }
}

TRIXY_OPTIMIZER_TPL_DECLARATION
template <class Tensor>
void AdaGradOptimizer<Optimizeriable>::update(
    Tensor& buff,
    Tensor& optimized,
    Tensor& parameter,
    const Tensor& grad) noexcept
{
    // velocity = velocity + g * g
    // w = w - learning_rate * g / sqrt(velocity)

    optimized.add(
        buff.multiply(grad, grad)
    );

    parameter.sub(
        buff.apply(detail::invertSqrt, optimized)
            .multiply(grad)
            .join(learning_rate)
    );
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void AdaGradOptimizer<Optimizeriable>::initialize_inner_struct()
{
    buff1.resize(net.inner.N);
    buff2.resize(net.inner.N);

    optimizedB.resize(net.inner.N);
    optimizedW.resize(net.inner.N);

    for(size_type i = 0; i < net.inner.N; ++i)
    {
        buff1[i].resize(net.inner.B[i]. size());
        buff2[i].resize(net.inner.W[i].shape());

        optimizedB[i].resize(net.inner.B[i]. size(), 0.);
        optimizedW[i].resize(net.inner.W[i].shape(), 0.);
    }
}

TRIXY_OPTIMIZER_TPL_DECLARATION
AdaGradOptimizer<Optimizeriable>& AdaGradOptimizer<Optimizeriable>::reset() noexcept
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

#endif // ADA_GRAD_OPTIMIZER_HPP
