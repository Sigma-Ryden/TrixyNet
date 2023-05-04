// This file contains all extern meta function
// For safer use, you MUST only include the Base*.hpp file from lib
#ifndef TRIXY_NET_META_HPP
#define TRIXY_NET_META_HPP

#include <type_traits> // true_type, false_type
#include <utility> // forward

#include <Trixy/Neuro/Network/Base.hpp>
#include <Trixy/Neuro/Regression/Base.hpp>

#include <Trixy/Neuro/Functional/Base.hpp>
#include <Trixy/Neuro/Functional/Optimizer/Base.hpp>

#include <Trixy/Neuro/Training/Base.hpp>

#include <Trixy/Neuro/Serializer/Base.hpp>

namespace trixy
{

namespace meta
{

template <typename> struct is_trixy_net : std::false_type {};
template <typename TrixyNetType, typename TypeSet>
struct is_trixy_net<TrixyNet<TypeSet, TrixyNetType>> : std::true_type {};

template <typename> struct is_unified_net : std::false_type {};
template <typename TypeSet>
struct is_unified_net<TrixyNet<TypeSet, TrixyNetType::Unified>> : std::true_type {};

template <typename> struct is_regression : std::false_type {};
template <typename RegressionType, typename TypeSet>
struct is_regression<Regression<TypeSet, RegressionType>> : std::true_type {};

template <typename> struct is_linear_regression : std::false_type {};
template <typename TypeSet>
struct is_linear_regression<Regression<TypeSet, RegressionType::Linear>> : std::true_type {};

template <typename> struct is_polynomial_regression : std::false_type {};
template <typename TypeSet>
struct is_polynomial_regression<Regression<TypeSet, RegressionType::Polynomial>> : std::true_type {};

template <typename> struct is_optimizer : std::false_type {};
template <class Optimizeriable,
          class OptimizationType>
struct is_optimizer<train::Optimizer<Optimizeriable, OptimizationType>> : std::true_type {};

template <typename> struct is_serializer : std::false_type {};
template <class Serializable>
struct is_serializer<Serializer<Serializable>> : std::true_type {};

template <typename> struct is_functional : std::false_type {};
template <class Functionable>
struct is_functional<Functional<Functionable>> : std::true_type {};

template <typename> struct is_training : std::false_type {};
template <class Trainable>
struct is_training<train::Training<Trainable>> : std::true_type {};

} // namespace meta

} // namespace trixy

#endif // TRIXY_NET_META_HPP
