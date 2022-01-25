#ifndef GRADIENT_DESCENT_OPTIMIZER_HPP
#define GRADIENT_DESCENT_OPTIMIZER_HPP

#include "Trixy/Neuro/Functional/Optimizer/BaseOptimizer.hpp"
#include "Trixy/Neuro/Functional/IdFunctional.hpp"

#include "Trixy/Neuro/Detail/TrixyNetMeta.hpp"

#include "Trixy/Neuro/Detail/MacroScope.hpp"

namespace trixy
{

namespace train
{

TRIXY_OPTIMIZER_TPL_DECLARATION
using GradDescentOptimizer
    = TRIXY_OPTIMIZER_TPL(meta::is_feedforward_net, functional::OptimizationType::grad_descent);

TRIXY_OPTIMIZER_TPL_DECLARATION
class TRIXY_OPTIMIZER_TPL(meta::is_feedforward_net, functional::OptimizationType::grad_descent)
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

public:
    Optimizer(Optimizeriable& network,
              precision_type learning_rate);

    void set_learning_rate(precision_type new_learning_rate) noexcept;

    void update(const Container<Tensor1D>& gradB,
                const Container<Tensor2D>& gradW) noexcept;

private:
    void initialize_inner_struct();
};

TRIXY_OPTIMIZER_TPL_DECLARATION
GradDescentOptimizer<Optimizeriable>::Optimizer(
    Optimizeriable& network,
    precision_type learning_rate)
    : net(network)
    , learning_rate(learning_rate)
{
    this->template initialize<Optimizer>();

    initialize_inner_struct();
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void GradDescentOptimizer<Optimizeriable>::set_learning_rate(
    precision_type new_learning_rate) noexcept
{
    learning_rate = new_learning_rate;
}
TRIXY_OPTIMIZER_TPL_DECLARATION
void GradDescentOptimizer<Optimizeriable>::initialize_inner_struct()
{
    buff1.resize(net.inner.N);
    buff2.resize(net.inner.N);

    for(size_type i = 0; i < net.inner.N; ++i)
    {
        buff1[i].resize(net.inner.B[i]. size());
        buff2[i].resize(net.inner.W[i].shape());
    }
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void GradDescentOptimizer<Optimizeriable>::update(
    const Container<Tensor1D>& gradB,
    const Container<Tensor2D>& gradW) noexcept
{
    // w = w - learning_rate * g

    for(size_type i = 0; i < net.inner.N; ++i)
    {
        net.inner.B[i].sub(
            buff1[i].join(learning_rate, gradB[i])
        );

        net.inner.W[i].sub(
            buff2[i].join(learning_rate, gradW[i])
        );
    }
}

} // namespace train

} // namespace trixy

#include "Trixy/Neuro/Detail/MacroUnscope.hpp"

#endif // GRADIENT_DESCENT_OPTIMIZER_HPP
