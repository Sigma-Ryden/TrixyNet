#ifndef FEED_FORWARD_NET_IOPTIMIZER_HPP
#define FEED_FORWARD_NET_IOPTIMIZER_HPP

#include "BaseOptimizer.hpp"

#include "Trixy/Neuro/Detail/TrixyNetMeta.hpp"

#include "Trixy/Detail/MacroScope.hpp"

namespace trixy
{

namespace train
{

template <class Derived, class Optimizeriable>
class IOptimizer<Derived, Optimizeriable,
    meta::enable_if_t<meta::is_feedforward_net<Optimizeriable>::value>>
{
private:
    template <class... T>
    using Container         = typename Optimizeriable::template Container<T...>;

    using precision_type    = typename Optimizeriable::precision_type;

protected:
    using DerivedType       = Derived;

protected:
    virtual ~IOptimizer() = default;

private:
    DerivedType& self() { return *static_cast<DerivedType*>(this); }
    const DerivedType& self() const { return *static_cast<const DerivedType*>(this); }

public:
    void set_learning_rate(precision_type value) noexcept
    {
        self().set_learning_rate(value);
    }

    template <class BiasGrad, class WeightGrad>
    void update(const Container<BiasGrad>& gradB,
                const Container<WeightGrad>& gradW) noexcept
    {
        self().update(gradB, gradW);
    }
};

} // namespace train

} // namespace trixy

#include "Trixy/Detail/MacroScope.hpp"

#endif // FEED_FORWARD_NET_IOPTIMIZER_HPP
