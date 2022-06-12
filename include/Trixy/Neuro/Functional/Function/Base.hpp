#ifndef TRIXY_FUNCTION_BASE_HPP
#define TRIXY_FUNCTION_BASE_HPP

#include <Trixy/Range/View.hpp>

#include <Trixy/Detail/MacroScope.hpp>

namespace trixy
{

namespace functional
{

namespace activation
{

template <typename Precision>
class IActivation
{
public:
    using precision_type = Precision;
    using Range = utility::Range<Precision>;

private:
    template <typename Ret, typename... Args>
    using Func = Ret (*)(void* const, Args...);

private:
    Func<void, Range, const Range> f_f = nullptr;
    Func<void, Range, const Range> f_df = nullptr;

protected:
    template <class Derived>
    void initialize()
    {
        f_f = [](void *const self, Range result, const Range input)
        {
            TRIXY_DERIVED.f(result, input);
        };

        f_df = [](void *const self, Range result, const Range input)
        {
            TRIXY_DERIVED.df(result, input);
        };
    }

public:
    virtual ~IActivation() = default;

    void f(Range result, const Range input)
    {
        f_f(this, result, input);
    }

    void df(const Range result, const Range input)
    {
        f_df(this, result, input);
    }
};

} // namespace activation

namespace loss
{

template <typename Precision>
class ILoss
{
public:
    using precision_type = Precision;
    using Range = utility::Range<Precision>;

private:
    template <typename Ret, typename... Args>
    using Func = Ret (*)(void* const, Args...);

private:
    Func<void, precision_type&, const Range, const Range> f_f = nullptr;
    Func<void, Range, const Range, const Range> f_df = nullptr;

protected:
    template <class Derived>
    void initialize()
    {
        f_f = [](void *const self, precision_type& result, const Range y_true, const Range y_pred)
        {
            TRIXY_DERIVED.f(result, y_true, y_pred);
        };

        f_df = [](void *const self, Range result, const Range y_true, const Range y_pred)
        {
            TRIXY_DERIVED.df(result, y_true, y_pred);
        };
    }

public:
    virtual ~ILoss() = default;

    void f(precision_type& result, const Range y_true, const Range y_pred)
    {
        f_f(this, result, y_true, y_pred);
    }

    void df(Range result, const Range y_true, const Range y_pred)
    {
        f_df(this, result, y_true, y_pred);
    }
};

} // namespace loss

} // namespace functional

} // namespace trixy

#include <Trixy/Detail/MacroUnscope.hpp>

#endif // TRIXY_FUNCTION_BASE_HPP
