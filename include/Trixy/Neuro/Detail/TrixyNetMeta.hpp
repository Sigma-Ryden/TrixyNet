#ifndef TRIXY_NET_META_HPP
// This file contains all extern meta function
// For safer use, you MUST only include the Base*.hpp file from lib
#define TRIXY_NET_META_HPP

#include <utility> // declval
#include <type_traits> // enable_if, is_arithmetic, is_same, conditional, true_type, false_type

#include "Trixy/Neuro/Network/BaseTrixyNet.hpp"
#include "Trixy/Neuro/Regression/BaseRegression.hpp"

#include "Trixy/Neuro/Functional/Optimizer/BaseOptimizer.hpp"
#include "Trixy/Neuro/Functional/BaseFunctional.hpp"
#include "Trixy/Neuro/Serialization/BaseSerializer.hpp"

#include "Trixy/Neuro/Detail/MacroScope.hpp"

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
struct select_for : std::enable_if<condition, T>
{
    static constexpr bool value = condition;
};

template <typename> struct is_feedforward_net : std::false_type {};
TRIXY_NET_TPL_DECLARATION
struct is_feedforward_net<TRIXY_FEED_FORWARD_NET_TPL> : std::true_type {};

template <typename> struct is_feedforward_net_less : std::false_type {};
TRIXY_NET_TPL_DECLARATION
struct is_feedforward_net_less<TRIXY_FEED_FORWARD_NET_LESS_TPL> : std::true_type {};

template <typename> struct is_linear_regression : std::false_type {};
TRIXY_REGRESSION_TPL_DECLARATION
struct is_linear_regression<TRIXY_LINEAR_REGRESSION_TPL> : std::true_type {};

template <typename> struct is_polynomial_regression : std::false_type {};
TRIXY_REGRESSION_TPL_DECLARATION
struct is_polynomial_regression<TRIXY_POLYNOMIAL_REGRESSION_TPL> : std::true_type {};

template <typename> struct is_optimizer : std::false_type {};
template <class Optimizeriable, class OptimizationType>
struct is_optimizer<train::Optimizer<Optimizeriable, OptimizationType>> : std::true_type {};

template <typename> struct is_serializer : std::false_type {};
template <class Serializable>
struct is_serializer<Serializer<Serializable>> : std::true_type {};

template <typename> struct is_functional : std::false_type {};
template <class Functionable>
struct is_functional<Functional<Functionable>> : std::true_type {};

} // namespace meta

} // namespace trixy

#include "Trixy/Neuro/Detail/MacroUnscope.hpp"

#endif // TRIXY_NET_META_HPP
