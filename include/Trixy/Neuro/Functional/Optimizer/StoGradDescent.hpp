#ifndef TRIXY_OPTIMIZER_STO_GRAD_DESCENT_HPP
#define TRIXY_OPTIMIZER_STO_GRAD_DESCENT_HPP

#include <Trixy/Neuro/Functional/Optimizer/Base.hpp>
#include <Trixy/Neuro/Functional/Optimizer/Interface.hpp>

#include <Trixy/Range/Unified.hpp>

#include <Trixy/Neuro/Detail/TrixyNetMeta.hpp>

#include <Trixy/Neuro/Detail/MacroScope.hpp>

namespace trixy
{

namespace train
{

template <class Optimizeriable, class TypeSet = OptimizerTypeSet>
using StoGradDescent
    = TRIXY_OPTIMIZER_TEMPLATE_CLASS(meta::is_trixy_net, OptimizerType::stograd_descent);

TRIXY_OPTIMIZER_TEMPLATE()
class TRIXY_OPTIMIZER_TEMPLATE_CLASS(meta::is_trixy_net, OptimizerType::stograd_descent)
    : public IOptimizer<Optimizeriable>
{
public:
    using Net  = Optimizeriable;
    using Base = IOptimizer<Net>;

public:
    using typename Base::precision_type;
    using typename Base::size_type;

    using typename Base::Range;

private:
    Net& net;

    precision_type learning_rate_;
    precision_type alpha_;

public:
    Optimizer(Net& network,
              precision_type learning_rate,
              precision_type decay = 0.e-6)
        : Base()
        , net(network)
        , learning_rate_(learning_rate)
        , alpha_(1. - learning_rate * decay)
    {
        this->template initialize<Optimizer>();
    }

    precision_type learning_rate() const noexcept { return learning_rate_; }
    void learning_rate(precision_type value) noexcept { learning_rate_ = value; }

    void update(Range param, Range grad) noexcept
    {
        // w = alpha * w - learning_rate * grad
        net.linear.join(grad, learning_rate_);
        net.linear.join(param, alpha_);

        net.linear.sub(param, grad);
    }
};

template <class TypeSet = OptimizerTypeSet, class Net, typename... Args>
StoGradDescent<Net, TypeSet> StoGradDescentOptimizer(Net& net, Args&&... args)
{
    return StoGradDescent<Net, TypeSet>(net, std::forward<Args>(args)...);
}

} // namespace train

} // namespace trixy

#endif // TRIXY_OPTIMIZER_GRAD_DESCENT_HPP
