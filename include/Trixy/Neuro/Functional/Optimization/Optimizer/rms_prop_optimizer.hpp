#ifndef RMS_PROP_OPTIMIZER_HPP
#define RMS_PROP_OPTIMIZER_HPP

#include "Trixy/Neuro/Functional/Optimization/base_optimizer.hpp"

#include "Trixy/Neuro/Detail/neuro_function_id.hpp"
#include "Trixy/Neuro/Detail/function_detail.hpp"
#include "Trixy/Neuro/Detail/neuro_meta.hpp"

#include "Trixy/Neuro/Detail/macro_scope.hpp"

namespace trixy
{

namespace train
{

TRIXY_OPTIMIZER_TPL_DECLARATION
class TRIXY_OPTIMIZER_TPL(meta::is_feedforward_neuro, function::OptimizationId::rms_prop)
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

    precision_type learn_rate;

    precision_type beta;
    precision_type rbeta;

    size_type N;

public:
    Optimizer() noexcept : N(0) {}

    void setLearnRate(precision_type new_learn_rate) noexcept;

    void update(Container<Tensor1D>& bias,
                Container<Tensor2D>& weight,
                const Container<Tensor1D>& gradBias,
                const Container<Tensor2D>& gradWeight) noexcept;

    void prepare(const Optimizeriable& net,
                 precision_type learn_rate,
                 precision_type beta = 0.9);

    void reset() noexcept;
};

TRIXY_OPTIMIZER_TPL_DECLARATION
void TRIXY_OPTIMIZER_TPL(meta::is_feedforward_neuro, function::OptimizationId::rms_prop)::setLearnRate(
    precision_type new_learn_rate) noexcept
{
    learn_rate = new_learn_rate;
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void TRIXY_OPTIMIZER_TPL(meta::is_feedforward_neuro, function::OptimizationId::rms_prop)::update(
    Container<Tensor1D>& bias,
    Container<Tensor2D>& weight,
    const Container<Tensor1D>& gradBias,
    const Container<Tensor2D>& gradWeight) noexcept
{
    for(size_type i = 0; i < N; ++i)
    {
        optimizedB[i].join(beta).add(
            buff1[i].multiply(gradBias[i], gradBias[i])
                    .join(rbeta)
        );

        bias[i].sub(
            buff1[i].apply(detail::invertSqrt, optimizedB[i])
                    .multiply(gradBias[i])
                    .join(learn_rate)
        );

        optimizedW[i].join(beta).add(
            buff2[i].multiply(gradWeight[i], gradWeight[i])
                    .join(rbeta)
        );

        weight[i].sub(
            buff2[i].apply(detail::invertSqrt, optimizedW[i])
                    .multiply(gradWeight[i])
                    .join(learn_rate)
        );
    }
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void TRIXY_OPTIMIZER_TPL(meta::is_feedforward_neuro, function::OptimizationId::rms_prop)::prepare(
    const Optimizeriable& net,
    precision_type learn_rate,
    precision_type beta)
{
    this->learn_rate = learn_rate;

    this->beta = beta;
    rbeta = 1. - beta;

    N = net.getTopology().size() - 1;

    buff1.resize(N);
    buff2.resize(N);

    optimizedB.resize(N);
    optimizedW.resize(N);

    for(size_type i = 0; i < N; ++i)
    {
        buff1[i].resize(net.getInnerBias()[i].size());
        buff2[i].resize(net.getInnerWeight()[i].size());

        optimizedB[i].resize(net.getInnerBias()[i].size());
        optimizedW[i].resize(net.getInnerWeight()[i].size());
    }

    reset();
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void TRIXY_OPTIMIZER_TPL(meta::is_feedforward_neuro, function::OptimizationId::rms_prop)::reset() noexcept
{
    for(size_type i = 0; i < N; ++i)
    {
        optimizedB[i].fill(0.);
        optimizedW[i].fill(0.);
    }
}

} // namespace train

} // namespace trixy

#include "Trixy/Neuro/Detail/macro_unscope.hpp"

#endif // RMS_PROP_OPTIMIZER_HPP
