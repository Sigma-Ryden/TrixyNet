#ifndef TIRXY_META_HPP
#define TIRXY_META_HPP

#include <utility> // declval
#include <type_traits> // enable_if, is_same, true_type

#define TRIXY_NEURO_HAS_HELPER(type)                                      \
    template <typename T> struct has_##type {                             \
    private:                                                              \
        template <typename U, typename = typename U::type>                \
        static int detect(U &&);                                          \
        static void detect(...);                                          \
    public:                                                               \
        static constexpr bool value =                                     \
            std::is_integral<decltype(detect(std::declval<T>()))>::value; \
    }

namespace trixy
{

namespace meta
{

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

template <class...> struct conjunction : std::true_type {};
template <class B1> struct conjunction<B1> : B1 {};
template <class B1, class... Bn> struct conjunction<B1, Bn...>
    : std::conditional<bool(B1::value), conjunction<Bn...>, B1>::type {};

TRIXY_NEURO_HAS_HELPER(ActivationFunction);
TRIXY_NEURO_HAS_HELPER(LossFunction);
TRIXY_NEURO_HAS_HELPER(OptimizationFunction);

template <typename Neuro> struct is_feedforward_neuro
    : conjunction<has_ActivationFunction<Neuro>, has_LossFunction<Neuro>, has_OptimizationFunction<Neuro>> {};

template <typename Neuro, decltype(
    std::declval<Neuro>().getTopology(), std::declval<Neuro>().getInnerBias(), std::declval<Neuro>().getInnerWeight(),
    std::declval<Neuro>().function.getEachActivation(), std::declval<Neuro>().function.getLoss(),
    std::declval<Neuro>().function.getOptimization(),
    int()) = 0>
struct is_serializable_neuro : std::true_type {};

template <bool condition, typename T = void>
using enable_if_t = typename std::enable_if<condition, T>::type;

} // namespace meta

} // namespace trixy

// clean up
#undef TRIXY_NEURO_HAS_HELPER

#endif // TIRXY_META_HPP
