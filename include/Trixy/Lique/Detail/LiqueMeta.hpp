// This file contains all extern meta function
// For safer use, you MUST only include the Base*.hpp file from lib
#ifndef TRIXY_LIQUE_META_HPP
#define TRIXY_LIQUE_META_HPP

#include <type_traits> // enable_if, is_same, true_type, false_type

#include <Trixy/Detail/TrixyMeta.hpp>
#include <Trixy/Range/Detail/Meta.hpp>

#include <Trixy/Lique/Base.hpp>
#include <Trixy/Locker/Base.hpp>

#include <Trixy/Locker/Detail/LockerMeta.hpp>

namespace trixy
{

namespace lique
{

namespace meta
{

template <typename> struct is_tensor_type : std::false_type {};
template <typename Precision, typename TensrorType, typename TensorMode>
struct is_tensor_type<Tensor<Precision, TensrorType, TensorMode>> : std::true_type {};

template <class Tensor>
struct is_vector : std::is_base_of<lique::TensorType::vector, Tensor> {};

template <class Tensor>
struct is_matrix : std::is_base_of<lique::TensorType::matrix, Tensor> {};

template <class Tensor>
struct is_tensor : std::is_base_of<lique::TensorType::tensor, Tensor> {};

template <class Tensor>
struct is_iterate : trixy::meta::or_
<
    is_tensor<Tensor>,
    is_matrix<Tensor>,
    is_vector<Tensor>,
    trixy::meta::is_range<trixy::meta::decay<Tensor>>
> {};

template <typename T>
using as_vector = trixy::meta::require<is_vector<T>::value>;

template <typename T>
using as_matrix = trixy::meta::require<is_matrix<T>::value>;

template <typename T>
using as_tensor = trixy::meta::require<is_tensor<T>::value>;

template <typename T>
using as_iterate = trixy::meta::require<is_iterate<T>::value>;

} // namespace meta

} // namespace lique

} // namespace trixy

#endif // TRIXY_LIQUE_META_HPP
