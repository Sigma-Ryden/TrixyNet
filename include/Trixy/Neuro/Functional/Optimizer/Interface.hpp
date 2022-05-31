#ifndef TRIXY_OPTIMIZER_INTERFACE_HPP
#define TRIXY_OPTIMIZER_INTERFACE_HPP

#include <Trixy/Neuro/Functional/Optimizer/Base.hpp>
#include <Trixy/Range/Base.hpp>

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

// __EXPERIMENTAL__
template <class Optimizeriable>
class IOptimizer_<Optimizeriable,
    meta::when<meta::is_unified_net<Optimizeriable>::value>>
{
public:
    using Net               = Optimizeriable;

    using Vector            = typename Net::Vector;
    using Matrix            = typename Net::Matrix;
    using Tensor            = typename Net::Tensor;

    using precision_type    = typename Net::precision_type;
    using size_type         = typename Net::size_type;

    using Range             = utility::Range<precision_type>; // default unified range

private:
    template <typename Ret, typename... Args>
    using Func = Ret (*)(void* const, Args...);

private:
    Func<void, precision_type> f_set_learning_rate = nullptr;
    Func<precision_type> f_get_learning_rate = nullptr;

    Func<void, Range, Range> f_update = nullptr;

protected:
    template <class Derived>
    void initialize() noexcept
    {
        f_set_learning_rate = [](void *const self, precision_type value)
        { TRIXY_DERIVED.learning_rate(value); };

        f_get_learning_rate = [](void *const self) -> precision_type
        { return TRIXY_DERIVED.learning_rate(); };

        f_update = [](void *const self, Range param, Range grad)
        { TRIXY_DERIVED.update(param, grad); };
    }

public:
    virtual ~IOptimizer_() = default;

    void learning_rate(precision_type value) noexcept
    {
        f_set_learning_rate(this, value);
    }

    precision_type learning_rate() const noexcept
    {
        return f_get_learning_rate(this);
    }

    void update(Range param, Range grad) noexcept
    {
        f_update(this, param, grad);
    }
};

} // namespace train

} // namespace trixy

#include <Trixy/Detail/MacroScope.hpp>

#endif // TRIXY_OPTIMIZER_INTERFACE_HPP
