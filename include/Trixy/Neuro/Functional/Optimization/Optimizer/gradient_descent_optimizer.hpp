#ifndef GRADIENT_DESCENT_OPTIMIZER_HPP
#define GRADIENT_DESCENT_OPTIMIZER_HPP

#include "Trixy/Neuro/Functional/Optimization/base_optimizer.hpp"

#include "Trixy/Neuro/Detail/neuro_function_id.hpp"
#include "Trixy/Neuro/Detail/neuro_meta.hpp"

#include "Trixy/Neuro/Detail/macro_scope.hpp"

namespace trixy
{

namespace train
{

TRIXY_OPTIMIZER_TPL_DECLARATION
class TRIXY_OPTIMIZER_TPL(meta::is_feedforward_neuro, function::OptimizationId::grad_descent)
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

    precision_type learn_rate;

    size_type N;

public:
    Optimizer() noexcept : N(0) {}

    void setLearnRate(precision_type new_learn_rate) noexcept;

    void update(Container<Tensor1D>& bias,
                Container<Tensor2D>& weight,
                const Container<Tensor1D>& gradBias,
                const Container<Tensor2D>& gradWeight) noexcept;

    void prepare(const Optimizeriable& net,
                 precision_type learn_rate);

    void reset() noexcept = delete;
};

TRIXY_OPTIMIZER_TPL_DECLARATION
void TRIXY_OPTIMIZER_TPL(meta::is_feedforward_neuro, function::OptimizationId::grad_descent)::setLearnRate(
    precision_type new_learn_rate) noexcept
{
    learn_rate = new_learn_rate;
}
TRIXY_OPTIMIZER_TPL_DECLARATION
void TRIXY_OPTIMIZER_TPL(meta::is_feedforward_neuro, function::OptimizationId::grad_descent)::prepare(
    const Optimizeriable& net,
    precision_type learn_rate)
{
    this->learn_rate = learn_rate;

    N = net.getTopology().size() - 1;

    buff1.resize(N);
    buff2.resize(N);

    for(size_type i = 0; i < N; ++i)
    {
        buff1[i].resize(net.getInnerBias()[i].size());
        buff2[i].resize(net.getInnerWeight()[i].size());
    }
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void TRIXY_OPTIMIZER_TPL(meta::is_feedforward_neuro, function::OptimizationId::grad_descent)::update(
    Container<Tensor1D>& bias,
    Container<Tensor2D>& weight,
    const Container<Tensor1D>& gradBias,
    const Container<Tensor2D>& gradWeight) noexcept
{
    for(size_type i = 0; i < N; ++i)
    {
        bias[i].sub(
            buff1[i].join(learn_rate, gradBias[i])
        );

        weight[i].sub(
            buff2[i].join(learn_rate, gradWeight[i])
        );
    }
}

} // namespace train

} // namespace trixy

#include "Trixy/Neuro/Detail/macro_unscope.hpp"

#endif // GRADIENT_DESCENT_OPTIMIZER_HPP
