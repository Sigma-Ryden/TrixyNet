#ifndef TRIXY_OPTIMIZER_INTERFACE_HPP
#define TRIXY_OPTIMIZER_INTERFACE_HPP

#include <Trixy/Neuro/Functional/Optimizer/Base.hpp>

#include <Trixy/Range/View.hpp>
#include <Trixy/Range/Unified.hpp>

#include <Trixy/Neuro/Detail/TrixyNetMeta.hpp>

#include <Trixy/Detail/MacroScope.hpp>

namespace trixy
{

namespace train
{

template <class Optimizeriable>
class IOptimizer<Optimizeriable,
    meta::when<meta::is_trixy_net<Optimizeriable>::value>>
{
public:
    using Net               = Optimizeriable;

    using precision_type    = typename Net::precision_type;
    using size_type         = typename Net::size_type;

    using Range             = utility::Range<precision_type>; // default view range
    using RangeUnified      = utility::Range<precision_type, RangeType::Unified>;

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
    virtual ~IOptimizer() = default;

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

protected:
    template <class Table>
    static RangeUnified& get(Table& table, Range range)
    {
        auto key = reinterpret_cast<typename Table::key_type>(range.data());
        auto& buff = table[key];

        if (buff.data() == nullptr)
            buff.resize(range.size(), precision_type{});

        return buff;
    }
};

} // namespace train

} // namespace trixy

#include <Trixy/Detail/MacroScope.hpp>

#endif // TRIXY_OPTIMIZER_INTERFACE_HPP
