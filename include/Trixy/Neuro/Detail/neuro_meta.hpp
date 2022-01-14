#ifndef NEURO_META_HPP
#define NEURO_META_HPP

#include <utility> // declval
#include <type_traits> // enable_if, is_arithmetic, is_same, conditional, true_type, false_type

#include "Trixy/Neuro/Network/neuro_network_base.hpp"
#include "Trixy/Neuro/Regression/regression_base.hpp"
#include "Trixy/Neuro/Functional/Optimization/base_optimizer.hpp"

#include "Trixy/Neuro/Detail/macro_scope.hpp"

namespace trixy
{

namespace meta
{

template <class...> struct disjunction : std::true_type {};
template <class B1> struct disjunction<B1> : B1 {};
template <class B1, class... Bn>
struct disjunction<B1, Bn...> : std::conditional<bool(B1::value), B1, disjunction<Bn...>>::type {};

template <class Class, template <class T> class... Bn>
struct has_true : disjunction<Bn<Class>...> {};

template <typename T>
struct use_for_arithmetic : std::enable_if<std::is_arithmetic<T>::value> {};

template <typename T>
using use_for_arithmetic_t = typename use_for_arithmetic<T>::type;

template <bool condition, typename T>
struct select_if : std::enable_if<condition, T>
{
    static constexpr bool value = condition;
};

template <typename> struct is_feedforward_net : std::false_type {};
TRIXY_NEURAL_NETWORK_TPL_DECLARATION
struct is_feedforward_net<TRIXY_FEED_FORWARD_NET_TPL> : std::true_type {};

template <typename> struct is_feedforward_net_less : std::false_type {};
TRIXY_NEURAL_NETWORK_TPL_DECLARATION
struct is_feedforward_net_less<TRIXY_FEED_FORWARD_NET_LESS_TPL> : std::true_type {};

template <typename> struct is_linear_regression : std::false_type {};
TRIXY_REGRESSION_TPL_DECLARATION
struct is_linear_regression<TRIXY_LINEAR_REGRESSION_TPL> : std::true_type {};

template <typename> struct is_polynomial_regression : std::false_type {};
TRIXY_REGRESSION_TPL_DECLARATION
struct is_polynomial_regression<TRIXY_POLYNOMIAL_REGRESSION_TPL> : std::true_type {};

} // namespace meta

} // namespace trixy

#include "Trixy/Neuro/Detail/macro_unscope.hpp"

#endif // NEURO_META_HPP
