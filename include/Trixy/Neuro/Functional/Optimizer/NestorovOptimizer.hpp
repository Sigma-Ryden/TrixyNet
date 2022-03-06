#ifndef NESTOROV_OPTIMIZER_HPP
#define NESTOROV_OPTIMIZER_HPP

#include "Trixy/Neuro/Functional/Optimizer/BaseOptimizer.hpp"
#include "Trixy/Neuro/Functional/IdFunctional.hpp"

#include "Trixy/Neuro/Detail/TrixyNetMeta.hpp"

#include "Trixy/Neuro/Detail/MacroScope.hpp"

namespace trixy
{

namespace train
{

TRIXY_OPTIMIZER_TPL_DECLARATION
using NestorovOptimizer =
    TRIXY_OPTIMIZER_TPL(meta::is_feedforward_net, OptimizerType::nestorov);

TRIXY_OPTIMIZER_TPL_DECLARATION
class TRIXY_OPTIMIZER_TPL(meta::is_feedforward_net, OptimizerType::nestorov)
    : public IOptimizer<Optimizeriable>
{
    TRIXY_IOPTIMIZER_BODY

public:
    template <class... T>
    using Container         = typename Optimizeriable::template Container<T...>;

    using Vector            = typename Optimizeriable::Vector;
    using Matrix            = typename Optimizeriable::Matrix;

    using LVector           = typename Optimizeriable::LVector;
    using LMatrix           = typename Optimizeriable::LMatrix;

    using NetInit           = typename Optimizeriable::Init;

    using precision_type    = typename Optimizeriable::precision_type;
    using size_type         = typename Optimizeriable::size_type;

private:
    Optimizeriable& net;

    Container<Vector> buff1;
    Container<Matrix> buff2;

    Container<Vector> optimizedB;
    Container<Matrix> optimizedW;

    precision_type learning_rate;

    precision_type momentum;

public:
    Optimizer(Optimizeriable& network,
              precision_type learning_rate,
              precision_type momentum = 0.9);

    void set_learning_rate(precision_type value) noexcept;

    void update(const Container<LVector>& gradB,
                const Container<LMatrix>& gradW) noexcept;

    Optimizer& reset() noexcept;

private:
    template <class Buffer, class Optimized, class Parameter, class Gradient>
    void update(Buffer& buff,
                Optimized& optimized,
                Parameter& parameter,
                const Gradient& grad) noexcept;
};

TRIXY_OPTIMIZER_TPL_DECLARATION
NestorovOptimizer<Optimizeriable>::Optimizer(
    Optimizeriable& network,
    precision_type learning_rate,
    precision_type momentum)
    : Base()
    , net(network)
    , buff1(NetInit::get1D(net.inner.topology))
    , buff2(NetInit::get2D(net.inner.topology))
    , optimizedB(NetInit::get1D(net.inner.topology, 0.))
    , optimizedW(NetInit::get2D(net.inner.topology, 0.))
    , learning_rate(learning_rate)
    , momentum(momentum)
{
    this->template initialize<Optimizer>();
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void NestorovOptimizer<Optimizeriable>::set_learning_rate(
    precision_type value) noexcept
{
    learning_rate = value;
}

TRIXY_OPTIMIZER_TPL_DECLARATION
void NestorovOptimizer<Optimizeriable>::update(
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
template <class Buffer, class Optimized, class Parameter, class Gradient>
void NestorovOptimizer<Optimizeriable>::update(
    Buffer& buff,
    Optimized& optimized,
    Parameter& parameter,
    const Gradient& grad) noexcept
{
    // velocity = momentum * velocity - learning_rate * g
    // w = w + momentum * velocity - learning_rate * g

    net.linear.join(optimized, momentum);
    net.linear.join(buff, learning_rate, grad);
    net.linear.sub(optimized, buff);

    net.linear.sub(parameter, buff);
    net.linear.join(buff, momentum, optimized);
    net.linear.add(parameter, buff);
}

TRIXY_OPTIMIZER_TPL_DECLARATION
NestorovOptimizer<Optimizeriable>& NestorovOptimizer<Optimizeriable>::reset() noexcept
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

#endif // NESTOROV_OPTIMIZER_HPP
