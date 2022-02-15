// This file contains all extern meta function
// For safer use, you MUST only include the Base*.hpp file from lib
#ifndef LIQUE_META_HPP
#define LIQUE_META_HPP

#include <type_traits> // enable_if, is_same, true_type, false_type

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

template <typename> struct is_ltensor : std::false_type {};
template <typename Precision, class tensor_type>
struct is_ltensor<Tensor<Precision, tensor_type>> : std::true_type {};

template <typename> struct is_lock_tensor : std::false_type {};
template <class Tensor, class locker_type>
struct is_lock_tensor<Locker<Tensor, locker_type>> : is_ltensor<Tensor> {};

template <typename> struct is_lvector : std::false_type {};
template <typename Precision>
struct is_lvector<Tensor<Precision, TensorType::vector>> : std::true_type {};

template <typename> struct is_lock_lvector : std::false_type {};
template <class Tensor>
struct is_lock_lvector<Locker<Tensor, LockerType::vector>> : is_lvector<Tensor> {};

template <typename> struct is_lmatrix : std::false_type {};
template <typename Precision>
struct is_lmatrix<Tensor<Precision, TensorType::matrix>> : std::true_type {};

template <typename> struct is_lock_lmatrix : std::false_type {};
template <class Tensor>
struct is_lock_lmatrix<Locker<Tensor, LockerType::matrix>> : is_lmatrix<Tensor> {};

template <class Tensor>
struct is_vector : std::is_same<typename Tensor::type, TensorType::vector> {};

template <class Tensor>
struct is_matrix : std::is_same<typename Tensor::type, TensorType::matrix> {};

template <class Tensor>
struct is_tensor : trixy::meta::disjunction<
    std::is_same<typename Tensor::type, TensorType::vector>,
    std::is_same<typename Tensor::type, TensorType::matrix>> {};

template <typename T> struct use_for_vector : std::enable_if<is_vector<T>::value, int> {};
template <typename T>
using use_for_vector_t = typename use_for_vector<T>::type;

template <typename T> struct use_for_matrix : std::enable_if<is_matrix<T>::value, int> {};
template <typename T>
using use_for_matrix_t = typename use_for_matrix<T>::type;

template <typename T> struct use_for_tensor : std::enable_if<is_tensor<T>::value, int> {};
template <typename T>
using use_for_tensor_t = typename use_for_tensor<T>::type;

template <typename T> struct enable_for_vector : std::enable_if<is_vector<T>::value> {};
template <typename T>
using enable_for_vector_t = typename enable_for_vector<T>::type;

template <typename T> struct enable_for_matrix : std::enable_if<is_matrix<T>::value> {};
template <typename T>
using enable_for_matrix_t = typename enable_for_matrix<T>::type;

template <typename T> struct enable_for_tensor : std::enable_if<is_tensor<T>::value> {};
template <typename T>
using enable_for_tensor_t = typename enable_for_tensor<T>::type;

} // namespace meta

} // namespace lique

} // namespace trixy

#endif // LIQUE_META_HPP
