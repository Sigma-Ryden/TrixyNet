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
    Container<Tensor1D> buff1;
    Container<Tensor2D> buff2;

    precision_type learning_rate;

    size_type N;

public:
    Optimizer() noexcept : N(0) { this->template initialize<Optimizer>(); }

    Optimizer(const Optimizeriable& net,
              precision_type learning_rate);

    void set_learning_rate(precision_type new_learning_rate) noexcept;

    void update(Container<Tensor1D>& B,
                Container<Tensor2D>& W,
                const Container<Tensor1D>& gradB,
                const Container<Tensor2D>& gradW) noexcept;

    void prepare(const Optimizeriable& net,
                 precision_type new_learning_rate); // deprecated

    void reset() noexcept = delete;
};

TRIXY_OPTIMIZER_TPL_DECLARATION
GradDescentOptimizer<Optimizeriable>::Optimizer(
    const Optimizeriable& net,
    precision_type learning_rate)
{
    this->template initialize<Optimizer>();

    prepare(net, learning_rate);
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void GradDescentOptimizer<Optimizeriable>::set_learning_rate(
    precision_type new_learning_rate) noexcept
{
    learning_rate = new_learning_rate;
}
TRIXY_OPTIMIZER_TPL_DECLARATION
void GradDescentOptimizer<Optimizeriable>::prepare(
    const Optimizeriable& net,
    precision_type new_learning_rate)
{
    learning_rate = new_learning_rate;

    N = net.getTopology().size() - 1;

    buff1.resize(N);
    buff2.resize(N);

    for(size_type i = 0; i < N; ++i)
    {
        buff1[i].resize(net.  getInnerBias()[i]. size());
        buff2[i].resize(net.getInnerWeight()[i].shape());
    }
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void GradDescentOptimizer<Optimizeriable>::update(
    Container<Tensor1D>& B,
    Container<Tensor2D>& W,
    const Container<Tensor1D>& gradB,
    const Container<Tensor2D>& gradW) noexcept
{
    // w = w - learning_rate * g

    for(size_type i = 0; i < N; ++i)
    {
        B[i].sub(
            buff1[i].join(learning_rate, gradB[i])
        );

        W[i].sub(
            buff2[i].join(learning_rate, gradW[i])
        );
    }
}

} // namespace train

} // namespace trixy

#include "Trixy/Neuro/Detail/MacroUnscope.hpp"

#endif // GRADIENT_DESCENT_OPTIMIZER_HPP
