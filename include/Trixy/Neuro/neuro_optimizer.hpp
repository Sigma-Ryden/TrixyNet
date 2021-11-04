#ifndef NEURO_OPTIMIZER_HPP
#define NEURO_OPTIMIZER_HPP

#include <cmath> // sqrt
#include <utility> // declval
#include <type_traits> // enable_if, is_same
#include <map> // map

namespace trixy
{

namespace set
{

namespace optimization
{

namespace detail
{

template <typename Precision>
Precision invertSqrt(Precision x)
{
    return 1.0 / std::sqrt(1e-9 + x);
}

template <typename T>
inline const T& call_const(T& obj)
{
    return const_cast<const T&>(obj);
}

} // namespace detail

template <template <typename T, typename...> class Tensor, typename Precision, typename... Args>
Tensor<Precision, Args...> momentum(
    Tensor<Precision, Args...>& g,
    Tensor<Precision, Args...>& s)
{
    static const Precision beta1 = 0.9;
    static const Precision beta2 = 1.0 - beta1;

    s = s.join(beta1) + g.join(beta2);

    return s;
}

template <template <typename T, typename...> class Tensor, typename Precision, typename... Args>
Tensor<Precision, Args...> rms_prop(
    Tensor<Precision, Args...>& g,
    Tensor<Precision, Args...>& s)
{
    static const Precision beta1 = 0.9;
    static const Precision beta2 = 1.0 - beta1;

    s = s.join(beta1) + detail::call_const(g).multiply(detail::call_const(g).join(beta2));
    g.multiply(s.apply(detail::invertSqrt));

    return g;
}

template <template <typename T, typename...> class Tensor, typename Precision, typename... Args>
Tensor<Precision, Args...> ada_grad(
    Tensor<Precision, Args...>& g,
    Tensor<Precision, Args...>& s)
{
    s = s + detail::call_const(g).multiply(g);
    g.multiply(s.apply(detail::invertSqrt));

    return g;
}

} // namespace optimization

namespace data
{

template <template <typename T, typename...> class Vector, template <typename T, typename...> class Matrix,
          typename Precision, typename... Args>
struct OptimizationData
{
     Vector<Precision, Args...> (*f1D)(Vector<Precision, Args...>&, Vector<Precision, Args...>&);
     Matrix<Precision, Args...> (*f2D)(Matrix<Precision, Args...>&, Matrix<Precision, Args...>&);
};

} // namespace

} // namespace set

namespace meta
{

template <template <template <typename, typename...> class V,
                    template <typename, typename...> class M,
                    typename P,
                    typename...> class FunctionData,
          template <typename, typename...> class Vector,
          template <typename, typename...> class Matrix,
          typename Precision,
          typename... Args>
struct is_optimization_data
{
using Vector_t       = Vector<Precision, Args...>;
using Matrix_t       = Matrix<Precision, Args...>;
using FunctionData_t = FunctionData<Vector, Matrix, Precision, Args...>;

constexpr static bool value =
    std::is_same<decltype(std::declval<FunctionData_t>().f1D), Vector_t (*)(Vector_t&, Vector_t&)>::value &&
    std::is_same<decltype(std::declval<FunctionData_t>().f2D), Matrix_t (*)(Matrix_t&, Matrix_t&)>::value;
};

} // namespace meta

template <template <template <typename, typename...> class V,
                    template <typename, typename...> class M,
                    typename P,
                    typename...> class FunctionData,
          template <typename, typename...> class Vector,
          template <typename, typename...> class Matrix,
          typename Precision,
          typename... Args,
          typename std::enable_if<meta::is_optimization_data<FunctionData, Vector, Matrix, Precision, Args...>::value, int>::type = 0>
FunctionData<Vector, Matrix, Precision, Args...> get(const char* optimization_function_name)
{
    using namespace set::optimization;
    using namespace set::data;

    static std::map<const char*, OptimizationData<Vector, Matrix, Precision, Args...>> optimization_data;

    optimization_data["momentum"] = { momentum, momentum };
    optimization_data["rms_prop"] = { rms_prop, rms_prop };
    optimization_data["ada_grad"] = { ada_grad, ada_grad };

    auto it = optimization_data.find(optimization_function_name);

    if(it != optimization_data.end())
        return FunctionData<Vector, Matrix, Precision, Args...>(it->second.f1D, it->second.f2D);

    return FunctionData<Vector, Matrix, Precision, Args...>();
}

} // namespace trixy

#endif // NEURO_OPTIMIZER_HPP
