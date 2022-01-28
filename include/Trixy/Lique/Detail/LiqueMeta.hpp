// This file contains all extern meta function
// For safer use, you MUST only include the Base*.hpp file from lib
#ifndef LIQUE_META_HPP
#define LIQUE_META_HPP

#include <type_traits> // enable_if, is_arithmetic, condition, true_type, false_type

#include "Trixy/Lique/LiqueBaseTensor.hpp"
#include "Trixy/Lique/LiqueBaseLocker.hpp"

namespace lique
{

namespace meta
{

template <class...> struct conjunction : std::true_type {};
template <class B1> struct conjunction<B1> : B1 {};
template <class B1, class... Bn>
struct conjunction<B1, Bn...> : std::conditional<bool(B1::value), conjunction<Bn...>, B1>::type {};

template <class...> struct disjunction : std::true_type {};
template <class B1> struct disjunction<B1> : B1 {};
template <class B1, class... Bn>
struct disjunction<B1, Bn...> : std::conditional<bool(B1::value), B1, disjunction<Bn...>>::type {};

template <typename> struct is_tensor : std::false_type {};
template <typename Precision, class tensor_type>
struct is_tensor<Tensor<Precision, tensor_type>> : std::true_type {};

template <typename> struct is_locker : std::false_type {};
template <class Tensor>
struct is_locker<Locker<Tensor>> : std::true_type {};

template <typename> struct is_vector : std::false_type {};
template <typename Precision>
struct is_vector<Tensor<Precision, TensorType::vector>> : std::true_type {};

template <typename> struct is_matrix : std::false_type {};
template <typename Precision>
struct is_matrix<Tensor<Precision, TensorType::matrix>> : std::true_type {};

template <typename> struct is_lock_tensor : std::false_type {};
template <class Tensor>
struct is_lock_tensor<Locker<Tensor>> : is_tensor<Tensor> {};

template <typename> struct is_lock_vector : std::false_type {};
template <class Tensor>
struct is_lock_vector<Locker<Tensor>> : is_vector<Tensor> {};

template <typename> struct is_lock_matrix : std::false_type {};
template <class Tensor>
struct is_lock_matrix<Locker<Tensor>> : is_matrix<Tensor> {};

template <class Tensor>
struct is_ltensor : disjunction<is_tensor<Tensor>, is_lock_tensor<Tensor>> {};

template <class Tensor>
struct is_lvector : disjunction<is_vector<Tensor>, is_lock_vector<Tensor>> {};

template <class Tensor>
struct is_lmatrix : disjunction<is_matrix<Tensor>, is_lock_matrix<Tensor>> {};

template <class T, class... Tn>
struct is_same_types: meta::conjunction<std::is_same<T, Tn>...> {};

template <typename T>
struct enable_for_arithmetic : std::enable_if<std::is_arithmetic<T>::value> {};

template <typename T>
using enable_for_arithmetic_t = typename enable_for_arithmetic<T>::type;

template <typename T>
struct use_for_arithmetic : std::enable_if<std::is_arithmetic<T>::value, int> {};

template <typename T>
using use_for_arithmetic_t = typename use_for_arithmetic<T>::type;

} // namespace meta

} // namespace lique

#endif // LIQUE_META_HPP
