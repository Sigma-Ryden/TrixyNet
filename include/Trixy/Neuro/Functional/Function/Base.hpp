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

public:
    virtual ~IActivation() = default;

    virtual void f(Range result, const Range input) noexcept = 0;
    virtual void df(const Range result, const Range input) noexcept = 0;
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

public:
    virtual ~ILoss() = default;

    virtual void f(precision_type& result, const Range y_true, const Range y_pred) noexcept = 0;
    virtual void df(Range result, const Range y_true, const Range y_pred) noexcept = 0;
};

} // namespace loss

} // namespace functional

} // namespace trixy

#include <Trixy/Detail/MacroUnscope.hpp>

#endif // TRIXY_FUNCTION_BASE_HPP
