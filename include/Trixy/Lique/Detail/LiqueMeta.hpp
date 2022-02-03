// This file contains all extern meta function
// For safer use, you MUST only include the Base*.hpp file from lib
#ifndef LIQUE_META_HPP
#define LIQUE_META_HPP

#include <type_traits> // enable_if, is_same, is_arithmetic, condition, true_type, false_type

#include "Trixy/Lique/LiqueBaseTensor.hpp"
#include "Trixy/Locker/BaseLocker.hpp"

#include "Trixy/Locker/Detail/LockerMeta.hpp"

namespace trixy
{

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

template <class F, typename Ret = void, typename... Args>
struct is_callable
{
private:
    template <class U>
    static auto check(U* p) -> typename std::enable_if<
        std::is_same<decltype((*p)(std::declval<Args>()...)), Ret>::value, std::true_type>::type;

    template <class>
    static std::false_type check(...);

public:
    static constexpr bool value = decltype(check<F>(nullptr))::value;
};

template <class T, class... Tn>
struct is_same_types: meta::conjunction<std::is_same<T, Tn>...> {};

template <bool condition, class T = void>
using enable_if_t = typename std::enable_if<condition, T>::type;

template <typename T> struct enable_for_arithmetic : std::enable_if<std::is_arithmetic<T>::value> {};
template <typename T> using enable_for_arithmetic_t = typename enable_for_arithmetic<T>::type;

template <typename T> struct use_for_arithmetic : std::enable_if<std::is_arithmetic<T>::value, int> {};
template <typename T> using use_for_arithmetic_t = typename use_for_arithmetic<T>::type;

template <typename> struct is_tensor : std::false_type {};
template <typename Precision, class tensor_type>
struct is_tensor<Tensor<Precision, tensor_type>> : std::true_type {};

template <class Tensor>
struct is_tensor_1d : std::is_same<typename Tensor::type, TensorType::vector> {};

template <class Tensor>
struct is_tensor_2d : std::is_same<typename Tensor::type, TensorType::matrix> {};

template <class Tensor>
struct is_tensor_nd :
    disjunction<std::is_same<typename Tensor::type, TensorType::vector>,
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
