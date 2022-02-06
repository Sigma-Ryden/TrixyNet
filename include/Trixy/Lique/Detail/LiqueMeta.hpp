// This file contains all extern meta function
// For safer use, you MUST only include the Base*.hpp file from lib
#ifndef LIQUE_META_HPP
#define LIQUE_META_HPP

#include <type_traits> // enable_if, is_same, is_arithmetic, condition, true_type, false_type

#include "Trixy/Detail/TrixyMeta.hpp"

#include "Trixy/Lique/LiqueBaseTensor.hpp"
#include "Trixy/Locker/BaseLocker.hpp"

#include "Trixy/Locker/Detail/LockerMeta.hpp"

namespace trixy
{

namespace lique
{

namespace meta
{

template <typename> struct is_tensor : std::false_type {};
template <typename Precision, class tensor_type>
struct is_tensor<Tensor<Precision, tensor_type>> : std::true_type {};

template <class Tensor>
struct is_tensor_1d : std::is_same<typename Tensor::type, TensorType::vector> {};

template <class Tensor>
struct is_tensor_2d : std::is_same<typename Tensor::type, TensorType::matrix> {};

template <class Tensor>
struct is_tensor_nd : trixy::meta::disjunction<
    std::is_same<typename Tensor::type, TensorType::vector>,
    std::is_same<typename Tensor::type, TensorType::matrix>> {};

template <typename> struct is_vector : std::false_type {};
template <typename Precision>
struct is_vector<Tensor<Precision, TensorType::vector>> : std::true_type {};

template <typename> struct is_matrix : std::false_type {};
template <typename Precision>
struct is_matrix<Tensor<Precision, TensorType::matrix>> : std::true_type {};

template <typename> struct is_lock_tensor : std::false_type {};
template <class Tensor, class locker_type>
struct is_lock_tensor<Locker<Tensor, locker_type>> : is_tensor<Tensor> {};

template <typename> struct is_lvector : std::false_type {};
template <class Tensor> struct is_lvector<Locker<Tensor, LockerType::vector>> : is_vector<Tensor> {};

template <typename> struct is_lmatrix : std::false_type {};
template <class Tensor> struct is_lmatrix<Locker<Tensor, LockerType::matrix>> : is_matrix<Tensor> {};

template <typename T> struct use_for_tensor_1d : std::enable_if<is_tensor_1d<T>::value, int> {};
template <typename T> using use_for_tensor_1d_t = typename use_for_tensor_1d<T>::type;

template <typename T> struct use_for_tensor_2d : std::enable_if<is_tensor_2d<T>::value, int> {};
template <typename T> using use_for_tensor_2d_t = typename use_for_tensor_2d<T>::type;

template <typename T> struct use_for_tensor_nd : std::enable_if<is_tensor_nd<T>::value, int> {};
template <typename T> using use_for_tensor_nd_t = typename use_for_tensor_nd<T>::type;

} // namespace meta

} // namespace lique

} // namespace trixy

#endif // LIQUE_META_HPP
