#ifndef NEURO_META_HPP
#define NEURO_META_HPP

#include <utility> // declval
#include <type_traits> // enable_if, is_same, true_type

#include "Trixy/Neuro/Network/neuro_network_base.hpp"
#include "Trixy/Neuro/Regression/regression_base.hpp"

#include "Trixy/Neuro/Detail/macro_scope.hpp"

namespace trixy
{

namespace meta
{

template <typename> struct is_feedforward_neuro : std::false_type {};
TRIXY_NEURO_NETWORK_TPL_DECLARATION
struct is_feedforward_neuro<TRIXY_FEED_FORWARD_NEURO_TPL> : std::true_type {};

template <typename> struct is_feedforward_neuro_less : std::false_type {};
TRIXY_NEURO_NETWORK_TPL_DECLARATION
struct is_feedforward_neuro_less<TRIXY_FEED_FORWARD_NEURO_LESS_TPL> : std::true_type {};

template <typename> struct is_linear_regression : std::false_type {};
TRIXY_REGRESSION_TPL_DECLARATION
struct is_linear_regression<TRIXY_LINEAR_REGRESSION_TPL> : std::true_type {};

template <typename> struct is_polynomial_regression : std::false_type {};
TRIXY_REGRESSION_TPL_DECLARATION
struct is_polynomial_regression<TRIXY_POLYNOMIAL_REGRESSION_TPL> : std::true_type {};

} // namespace meta

} // namespace trixy

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

template <template <template <typename, typename...> class T, typename P, typename...> class FunctionData,
          template <typename, typename...> class Tensor,
          typename Precision, typename... Args>
struct is_activation_data
{
private:
    using Tensor_t        = Tensor<Precision, Args...>;
    using FunctionData_t  = FunctionData<Tensor, Precision, Args...>;

public:
    using Function        = void (*)(Tensor_t&, const Tensor_t&);
    using FunctionDerived = void (*)(Tensor_t&, const Tensor_t&);

    static constexpr bool value =
        std::is_same<decltype(std::declval<FunctionData_t>().f),  Function>::value &&
        std::is_same<decltype(std::declval<FunctionData_t>().df), FunctionDerived>::value;
};

template <template <template <typename, typename...> class T, typename P, typename...> class FunctionData,
          template <typename, typename...> class Tensor,
          typename Precision, typename... Args>
struct is_loss_data
{
private:
    using Tensor_t        = Tensor<Precision, Args...>;
    using FunctionData_t  = FunctionData<Tensor, Precision, Args...>;

public:
    using Function        = void (*)(Precision&, const Tensor_t&, const Tensor_t&);
    using FunctionDerived = void (*)(Tensor_t&,  const Tensor_t&, const Tensor_t&);

    static constexpr bool value =
        std::is_same<decltype(std::declval<FunctionData_t>().f),  Function>::value &&
        std::is_same<decltype(std::declval<FunctionData_t>().df), FunctionDerived>::value;
};

template <template <template <typename, typename...> class V,
                    template <typename, typename...> class M,
                    typename P, typename...>
          class FunctionData,
          template <typename, typename...> class Vector,
          template <typename, typename...> class Matrix,
          typename Precision, typename... Args>
struct is_optimization_data
{
private:
    using Tensor1D_t      = Vector<Precision, Args...>;
    using Tensor2D_t      = Matrix<Precision, Args...>;
    using FunctionData_t  = FunctionData<Vector, Matrix, Precision, Args...>;

public:
    using Function1D = void (*)(Tensor1D_t&, Tensor1D_t&, const Tensor1D_t&);
    using Function2D = void (*)(Tensor2D_t&, Tensor2D_t&, const Tensor2D_t&);

    static constexpr bool value =
        std::is_same<decltype(std::declval<FunctionData_t>().f1D), Function1D>::value &&
        std::is_same<decltype(std::declval<FunctionData_t>().f2D), Function2D>::value;
};
/*
template <class...> struct conjunction : std::true_type {};
template <class B1> struct conjunction<B1> : B1 {};
template <class B1, class... Bn> struct conjunction<B1, Bn...>
    : std::conditional<bool(B1::value), conjunction<Bn...>, B1>::type {};

TRIXY_NEURO_HAS_HELPER(ActivationFunction);
TRIXY_NEURO_HAS_HELPER(LossFunction);
TRIXY_NEURO_HAS_HELPER(OptimizationFunction);
*/

} // namespace meta

} // namespace trixy

#include "Trixy/Neuro/Detail/macro_unscope.hpp"

#endif // NEURO_META_HPP
