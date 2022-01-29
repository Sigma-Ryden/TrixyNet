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
    template <class... T>
    using Container         = typename Optimizeriable::template ContainerType<T...>;

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

    precision_type learning_rate;

public:
    Optimizer(Optimizeriable& network,
              precision_type learning_rate);

    void set_learning_rate(precision_type new_learning_rate) noexcept;

    void update(const Container<LVector>& gradB,
                const Container<LMatrix>& gradW) noexcept;
};

TRIXY_OPTIMIZER_TPL_DECLARATION
GradDescentOptimizer<Optimizeriable>::Optimizer(
    Optimizeriable& network,
    precision_type learning_rate)
    : net(network)
    , learning_rate(learning_rate)
    , buff1(Optimizeriable::init1D(net.inner.topology))
    , buff2(Optimizeriable::init2D(net.inner.topology))
{
    this->template initialize<Optimizer>();
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void GradDescentOptimizer<Optimizeriable>::set_learning_rate(
    precision_type new_learning_rate) noexcept
{
    learning_rate = new_learning_rate;
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void GradDescentOptimizer<Optimizeriable>::update(
    const Container<LVector>& gradB,
    const Container<LMatrix>& gradW) noexcept
{
    // w = w - learning_rate * g

    for(size_type i = 0; i < net.inner.N; ++i)
    {
        net.linear.join(buff1[i], learning_rate, gradB[i]);
        net.linear.sub(net.inner.B[i], buff1[i]);

        net.linear.join(buff2[i], learning_rate, gradW[i]);
        net.linear.sub(net.inner.W[i], buff2[i]);
    }
}

} // namespace train

} // namespace trixy

#include "Trixy/Neuro/Detail/MacroUnscope.hpp"

#endif // GRADIENT_DESCENT_OPTIMIZER_HPP
