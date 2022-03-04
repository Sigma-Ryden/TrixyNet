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
    TRIXY_OPTIMIZER_TPL(meta::is_feedforward_net, OptimizerType::ada_grad);

TRIXY_OPTIMIZER_TPL_DECLARATION
class TRIXY_OPTIMIZER_TPL(meta::is_feedforward_net, OptimizerType::ada_grad)
    : public IOptimizer<Optimizeriable>
{
    TRIXY_IOPTIMIZER_BODY

public:
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

    LContainer<LVector> optimizedB;
    LContainer<LMatrix> optimizedW;

    precision_type learning_rate;

public:
    Optimizer(Optimizeriable& network,
              precision_type learning_rate);

    void set_learning_rate(precision_type new_learning_rate) noexcept;

    void update(const Container<LVector>& gradB,
                const Container<LMatrix>& gradW) noexcept;

    Optimizer& reset() noexcept;

private:
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
    : Base()
    , net(network)
    , buff1(Optimizeriable::initlock1D(net.inner.topology))
    , buff2(Optimizeriable::initlock2D(net.inner.topology))
    , optimizedB(Optimizeriable::initlock1D(net.inner.topology, 0.))
    , optimizedW(Optimizeriable::initlock2D(net.inner.topology, 0.))
    , learning_rate(learning_rate)
{
    this->template initialize<Optimizer>();
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void AdaGradOptimizer<Optimizeriable>::set_learning_rate(
    precision_type new_learning_rate) noexcept
{
    learning_rate = new_learning_rate;
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void AdaGradOptimizer<Optimizeriable>::update(
    const Container<LVector>& gradB,
    const Container<LMatrix>& gradW) noexcept
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

    net.linear.mul(buff, grad, grad);
    net.linear.add(optimized, buff);

    net.linear.apply(buff, &detail::invert_sqrt<precision_type>, optimized);
    net.linear.mul(buff, grad);
    net.linear.join(buff, learning_rate);

    net.linear.sub(parameter, buff);
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
