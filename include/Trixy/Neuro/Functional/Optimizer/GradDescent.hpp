#ifndef TRIXY_OPTIMIZER_GRADIENT_DESCENT_HPP
#define TRIXY_OPTIMIZER_GRADIENT_DESCENT_HPP

#include <Trixy/Neuro/Functional/Optimizer/Base.hpp>
#include <Trixy/Neuro/Functional/Optimizer/Interface.hpp>

#include <Trixy/Range/Unified.hpp>

#include <Trixy/Neuro/Detail/TrixyNetMeta.hpp>

#include <Trixy/Neuro/Detail/MacroScope.hpp>

namespace trixy
{

namespace train
{

TRIXY_OPTIMIZER_TPL_DECLARATION
using GradDescent
    = TRIXY_OPTIMIZER_TPL(meta::is_trixy_net, OptimizerType::grad_descent);

TRIXY_OPTIMIZER_TPL_DECLARATION
class TRIXY_OPTIMIZER_TPL(meta::is_feedforward_net, OptimizerType::grad_descent)
    : public IOptimizer<GradDescent<Optimizeriable>, Optimizeriable>
{
public:
    using Net  = Optimizeriable;
    using Base = IOptimizer<GradDescent<Net>, Net>;

public:
    template <typename T>
    using Container = typename Base::template Container<T>;

    using typename Base::Vector;
    using typename Base::Matrix;

    using typename Base::Builder;

    using typename Base::precision_type;
    using typename Base::size_type;

private:
    Net& net;

    Container<Vector> buff1;
    Container<Matrix> buff2;

    precision_type learning_rate_;

public:
    Optimizer(Net& network,
              precision_type learning_rate)
        : Base()
        , net(network)
        , buff1(Builder::get1d(net.inner.topology))
        , buff2(Builder::get2d(net.inner.topology))
        , learning_rate_(learning_rate)
    {
    }

    precision_type learning_rate() const noexcept { return learning_rate_; }
    void learning_rate(precision_type value) noexcept { learning_rate_ = value; }

    template <class BiasGrad, class WeightGrad>
    void update(const Container<BiasGrad>& gradB,
                const Container<WeightGrad>& gradW) noexcept
    {
        // w = w - learning_rate * g

        for (size_type i = 0; i < net.inner.N; ++i)
        {
            net.linear.join(buff1[i], learning_rate_, gradB[i]);
            net.linear.sub(net.inner.B[i], buff1[i]);

            net.linear.join(buff2[i], learning_rate_, gradW[i]);
            net.linear.sub(net.inner.W[i], buff2[i]);
        }
    }
};

// __EXPERIMENTAL__
TRIXY_OPTIMIZER_TPL_DECLARATION
class Optimizer_<Optimizeriable, OptimizerType::grad_descent,
    meta::when<meta::is_unified_net<Optimizeriable>::value>>
    : public IOptimizer_<Optimizeriable>
{
public:
    using Net  = Optimizeriable;
    using Base = IOptimizer_<Net>;

public:
    using typename Base::Vector;
    using typename Base::Matrix;
    using typename Base::Tensor;

    using typename Base::precision_type;
    using typename Base::size_type;

    using typename Base::Range;

private:
    Net& net;
    precision_type learning_rate_;

public:
    Optimizer_(Net& network,
              precision_type learning_rate)
        : Base()
        , net(network)
        , learning_rate_(learning_rate)
    {
        this->template initialize<Optimizer_>();
    }

    precision_type learning_rate() const noexcept { return learning_rate_; }
    void learning_rate(precision_type value) noexcept { learning_rate_ = value; }

    // get zip
    void update(Range param, Range grad) noexcept
    {
        net.linear.join(grad, learning_rate_);
        net.linear.sub(param, grad);
    }
};

// __EXPERIMENTAL__
// will be change in the future versions
template <class Net, typename... Args>
Optimizer_<Net, OptimizerType::grad_descent> GradDescentOptimizer_(Net& net, Args&&... args)
{
    return Optimizer_<Net, OptimizerType::grad_descent>(net, std::forward<Args>(args)...);
}

template <class Net, typename... Args>
GradDescent<Net> GradDescentOptimizer(Net& net, Args&&... args)
{
    return GradDescent<Net>(net, std::forward<Args>(args)...);
}

} // namespace train

} // namespace trixy

#include <Trixy/Neuro/Detail/MacroUnscope.hpp>

#endif // TRIXY_OPTIMIZER_GRADIENT_DESCENT_HPP
