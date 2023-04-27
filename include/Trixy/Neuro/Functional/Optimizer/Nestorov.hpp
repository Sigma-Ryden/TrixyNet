#ifndef TRIXY_OPTIMIZER_NESTOROV_HPP
#define TRIXY_OPTIMIZER_NESTOROV_HPP

#include <Trixy/Neuro/Functional/Optimizer/Base.hpp>
#include <Trixy/Neuro/Functional/Optimizer/Interface.hpp>

#include <Trixy/Neuro/Detail/TrixyNetMeta.hpp>

#include <Trixy/Neuro/Detail/MacroScope.hpp>

namespace trixy
{

namespace train
{

template <class Optimizeriable, class TypeSet = OptimizerTypeSet>
using Nestorov
    = TRIXY_OPTIMIZER_TEMPLATE_CLASS(meta::is_trixy_net, OptimizerType::nestorov);

TRIXY_OPTIMIZER_TEMPLATE()
class TRIXY_OPTIMIZER_TEMPLATE_CLASS(meta::is_trixy_net, OptimizerType::nestorov)
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
    precision_type momentum_;

public:
    Optimizer(Net& network,
              precision_type learning_rate,
              precision_type momentum = 0.9)
        : Base()
        , net(network)
        , buff_table_()
        , optimized_table_()
        , learning_rate_(learning_rate)
        , momentum_(momentum)
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

        // velocity = momentum * velocity - learning_rate * g
        // w = w + momentum * velocity - learning_rate * g

        net.linear.join(optimized, momentum_);
        net.linear.join(buff, learning_rate_, grad);
        net.linear.sub(optimized, buff);

        net.linear.sub(param, buff);
        net.linear.join(buff, momentum_, optimized);
        net.linear.add(param, buff);
    }
};

template <class TypeSet = OptimizerTypeSet, class Net, typename... Args>
Nestorov<Net, TypeSet> NestorovOptimizer(Net& net, Args&&... args)
{
    return Nestorov<Net, TypeSet>(net, std::forward<Args>(args)...);
}

} // namespace train

} // namespace trixy

#endif // TRIXY_OPTIMIZER_NESTOROV_HPP
