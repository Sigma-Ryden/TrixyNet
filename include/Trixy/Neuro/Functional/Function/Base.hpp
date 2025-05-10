#ifndef TRIXY_FUNCTION_BASE_HPP
#define TRIXY_FUNCTION_BASE_HPP

#include <Trixy/Range/View.hpp>

#include <Trixy/Serializer/Core.hpp>

#include <Trixy/Detail/MacroScope.hpp>

namespace trixy
{

namespace functional
{

struct ActivationType {};

namespace activation
{

template <typename Precision>
class IActivation : public ActivationType, public sf::instantiable_t
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

struct LossType {};

namespace loss
{

template <typename Precision>
class ILoss : public LossType, public sf::instantiable_t
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

namespace meta
{

template <typename T> struct is_iactivation : std::is_base_of<functional::ActivationType, T> {};
template <typename T> struct is_iloss : std::is_base_of<functional::LossType, T> {};

} // namespace meta

} // namespace trixy

CONDITIONAL_SERIALIZABLE_DECLARATION(trixy::meta::is_iactivation<S>::value)
SERIALIZABLE_DECLARATION_INIT()

CONDITIONAL_SERIALIZABLE(saveload, activation, trixy::meta::is_iactivation<S>::value)
    SERIALIZATION()
SERIALIZABLE_INIT()

CONDITIONAL_SERIALIZABLE_DECLARATION(trixy::meta::is_iloss<S>::value)
SERIALIZABLE_DECLARATION_INIT()

CONDITIONAL_SERIALIZABLE(saveload, loss, trixy::meta::is_iloss<S>::value)
    SERIALIZATION()
SERIALIZABLE_INIT()

#endif // TRIXY_FUNCTION_BASE_HPP
