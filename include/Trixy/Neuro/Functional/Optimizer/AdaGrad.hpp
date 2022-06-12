#ifndef TRIXY_OPTIMIZER_ADA_GRAD_HPP
#define TRIXY_OPTIMIZER_ADA_GRAD_HPP

#include <Trixy/Neuro/Functional/Optimizer/Base.hpp>
#include <Trixy/Neuro/Functional/Optimizer/Interface.hpp>

#include <Trixy/Detail/FunctionDetail.hpp>
#include <Trixy/Neuro/Detail/TrixyNetMeta.hpp>

#include <Trixy/Neuro/Detail/MacroScope.hpp>

namespace trixy
{

namespace train
{

template <class Optimizeriable, class TypeSet = OptimizerTypeSet>
using AdaGrad =
    TRIXY_OPTIMIZER_TPL(meta::is_trixy_net, OptimizerType::ada_grad);

TRIXY_OPTIMIZER_TPL_DECLARATION
class TRIXY_OPTIMIZER_TPL(meta::is_trixy_net, OptimizerType::ada_grad)
    : public IOptimizer<Optimizeriable>
{
public:
    using Net  = Optimizeriable;
    using Base = IOptimizer<Net>;

public:
    using typename Base::precision_type;
    using typename Base::size_type;

    using typename Base::Range;
    using typename Base::RangeUnified;

private:
    using Table = OptimizerTypeSet::template Table<std::uintptr_t, RangeUnified>;

private:
    Net& net;

    Table buff_table_;
    Table optimized_table_;

    precision_type learning_rate_;

public:
    Optimizer(Net& network,
              precision_type learning_rate)
        : Base()
        , net(network)
        , buff_table_()
        , optimized_table_()
        , learning_rate_(learning_rate)
    {
        this->template initialize<Optimizer>();
    }

    Optimizer& reset() noexcept
    {
        auto first = optimized_table_.begin();
        auto last  = optimized_table_.end();

        while (first != last)
        {
            first->fill(0.);
            ++first;
        }

        return *this;
    }

    precision_type learning_rate() const noexcept { return learning_rate_; }
    void learning_rate(precision_type value) noexcept { learning_rate_ = value; }

    void update(Range param, Range grad) noexcept
    {
        auto& buff = Base::get(buff_table_, param);
        auto& optimized = Base::get(optimized_table_, param);

        // velocity = velocity + g * g
        // w = w - learning_rate * g / sqrt(velocity)

        net.linear.mul(buff, grad, grad);
        net.linear.add(optimized, buff);

        net.linear.apply(buff, &detail::invert_sqrt<precision_type>, optimized);
        net.linear.mul(buff, grad);
        net.linear.join(buff, learning_rate_);

        net.linear.sub(param, buff);
    }
};

template <class Net, typename... Args>
AdaGrad<Net> AdaGradOptimizer(Net& net, Args&&... args)
{
    return AdaGrad<Net>(net, std::forward<Args>(args)...);
}

} // namespace train

} // namespace trixy

#include <Trixy/Neuro/Detail/MacroUnscope.hpp>

#endif // TRIXY_OPTIMIZER_ADA_GRAD_HPP
