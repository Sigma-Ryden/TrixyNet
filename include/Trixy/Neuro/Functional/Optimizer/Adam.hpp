#ifndef TRIXY_OPTIMIZER_ADAM_HPP
#define TRIXY_OPTIMIZER_ADAM_HPP

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
using Adam
    = TRIXY_OPTIMIZER_TEMPLATE_CLASS(meta::is_trixy_net, OptimizerType::adam);

TRIXY_OPTIMIZER_TEMPLATE()
class TRIXY_OPTIMIZER_TEMPLATE_CLASS(meta::is_trixy_net, OptimizerType::adam)
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
    Table optimized_m_table_;
    Table optimized_s_table_;

    precision_type learning_rate_;

    precision_type beta1, beta2;
    precision_type rbeta1, rbeta2;

    precision_type tbeta1, tbeta2;

public:
    Optimizer(Net& network,
              precision_type learning_rate,
              precision_type beta1 = 0.9,
              precision_type beta2 = 0.999)
        : Base()
        , net(network)
        , buff_table_()
        , optimized_m_table_()
        , optimized_s_table_()
        , learning_rate_(learning_rate)
        , beta1(beta1)
        , beta2(beta2)
    {
        this->template initialize<Optimizer>();

        rbeta1 = 1. - beta1;
        rbeta2 = 1. - beta2;

        tbeta1 = 1.;
        tbeta2 = 1.;
    }

    Optimizer& reset() noexcept
    {
        auto first_m = optimized_m_table_.begin();
        auto last_m  = optimized_m_table_.end();

        while (first_m != last_m)
        {
            first_m->fill(0.);
            ++first_m;
        }

        auto first_s = optimized_s_table_.begin();
        auto last_s  = optimized_m_table_.end();

        while (first_s != last_s)
        {
            first_s->fill(0.);
            ++first_s;
        }

        return *this;
    }

    precision_type learning_rate() const noexcept { return learning_rate_; }
    void learning_rate(precision_type value) noexcept { learning_rate_ = value; }

    void update(Range param, Range grad) noexcept
    {
        auto& buff = this->get(buff_table_, param);

        auto& optimized_m = Base::get(optimized_m_table_, param);
        auto& optimized_s = Base::get(optimized_s_table_, param);

        // m = beta1 * m + (1 - beta1) * g
        // s = beta2 * m + (1 - beta2) * g * g

        // xm = m / (1 - beta1 ^ t)
        // xs = x / (1 - beta2 ^ t)

        // w = w - learning_rate * xm / sqrt(xs)

        // where: t - is number of calls this function (or number of iteration in train)

        tbeta1 *= beta1;
        tbeta2 *= beta2;

        net.linear.join(optimized_m, beta1);
        net.linear.join(buff, rbeta1, grad);
        net.linear.add(optimized_m, buff);

        net.linear.join(optimized_s, beta2);
        net.linear.mul(buff, grad, grad);
        net.linear.join(buff, rbeta2);
        net.linear.add(optimized_s, buff);

        net.linear.join(buff, 1. / (1. - tbeta2), optimized_s);
        net.linear.apply(buff, &detail::invert_sqrt<precision_type>);
        net.linear.mul(buff, optimized_m);
        net.linear.join(buff,  learning_rate_ / (1. - tbeta1));

        net.linear.sub(param, buff);
    }
};

template <class TypeSet = OptimizerTypeSet, class Net, typename... Args>
Adam<Net, TypeSet> AdamOptimizer(Net& net, Args&&... args)
{
    return Adam<Net, TypeSet>(net, std::forward<Args>(args)...);
}

} // namespace train

} // namespace trixy

#endif // TRIXY_OPTIMIZER_ADAM_HPP
