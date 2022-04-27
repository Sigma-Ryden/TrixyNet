#ifndef TRIXY_OPTIMIZER_INTERFACE_HPP
#define TRIXY_OPTIMIZER_INTERFACE_HPP

#include <Trixy/Neuro/Functional/Optimizer/Base.hpp>

#include <Trixy/Neuro/Detail/TrixyNetMeta.hpp>

#include <Trixy/Detail/MacroScope.hpp>

namespace trixy
{

namespace train
{

template <class Derived, class Optimizeriable>
class IOptimizer<Derived, Optimizeriable,
    meta::when<meta::is_feedforward_net<Optimizeriable>::value>>
{
public:
    using Net               = Optimizeriable;

    template <class T>
    using Container         = typename Net::template Container<T>;

    using Vector            = typename Net::Vector;
    using Matrix            = typename Net::Matrix;

    using Builder           = typename Net::Builder;

    using precision_type    = typename Net::precision_type;
    using size_type         = typename Net::size_type;

protected:
    using DerivedType       = Derived;

private:
    DerivedType& self() { return *static_cast<DerivedType*>(this); }
    const DerivedType& self() const { return *static_cast<const DerivedType*>(this); }

public:
    void learning_rate(precision_type value) noexcept
    {
        self().learning_rate(value);
    }

    precision_type learning_rate() const noexcept
    {
        return self().learning_rate();
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

#include <Trixy/Detail/MacroScope.hpp>

#endif // TRIXY_OPTIMIZER_INTERFACE_HPP
