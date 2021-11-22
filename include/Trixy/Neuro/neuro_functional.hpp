#ifndef NEURO_FUNCTIONAL_HPP
#define NEURO_FUNCTIONAL_HPP

#include <cstddef> // size_t
#include <cmath> // sqrt, pow, exp, log, fabs, tanh, cosh
#include <utility> // declval
#include <type_traits> // enable_if, is_same

namespace trixy
{

template <template <typename, typename...> class Vector,
          template <typename, typename...> class Matrix,
          typename Precision, typename... Args>
class NeuroManager;

} // namespace trixy

#define TRIXY_TENSOR_FUNCTION_TPL_DECLARATION                  \
    template <template <typename T, typename...> class Tensor, \
              typename Precision,                              \
              typename... Args>

#define TRIXY_VECTOR_FUNCTION_TPL_DECLARATION                  \
    template <template <typename T, typename...> class Vector, \
              typename Precision,                              \
              typename... Args>

#define TRIXY_NEURO_MANAGER_TPL_DECLARATION                    \
    template <template <typename, typename...> class Vector,   \
              template <typename, typename...> class Matrix,   \
              typename Precision, typename... Args>

#define TRIXY_NEURO_MANAGER_DECLARATION                        \
    NeuroManager<Vector, Matrix, Precision, Args...>

#define TRIXY_FUNCTION_GENERIC_HELPER(name)                                                          \
    template <template <typename T, typename...> class Tensor, typename Precision, typename... Args> \
    void name(                                                                \
        Tensor<Precision, Args...>& buff, const Tensor<Precision, Args...>& tensor) noexcept {       \
        buff.apply(detail::name, tensor);                                                            \
    }                                                                                                \
    template <template <typename T, typename...> class Tensor, typename Precision, typename... Args> \
    void name##_derived(                                                      \
        Tensor<Precision, Args...>& buff, const Tensor<Precision, Args...>& tensor) noexcept {       \
        buff.apply(detail::name##_derived, tensor);                                                  \
    }

namespace trixy
{

namespace set
{

namespace activation
{

namespace detail
{

template <typename Precision>
Precision relu(Precision x) noexcept
{
    return x > 0.0 ? x : 0.0;
}
template <typename Precision>
Precision relu_derived(Precision x) noexcept
{
    return x > 0.0 ? 1.0 : 0.0;
}

template <typename Precision>
Precision elu(Precision x) noexcept
{
    static const Precision alpha = 0.2;
    return x > 0.0 ? x : alpha * (std::exp(x) - 1.0);
}
template <typename Precision>
Precision elu_derived(Precision x) noexcept
{
    static const Precision alpha = 0.2;
    return x > 0.0 ? 1.0 : alpha * std::exp(x);
}

template <typename Precision>
Precision lrelu(Precision x) noexcept
{
    static const Precision alpha = 0.01;
    return x > 0.0 ? x : alpha * x;
}
template <typename Precision>
Precision lrelu_derived(Precision x) noexcept
{
    static const Precision alpha = 0.01;
    return x > 0.0 ? 1.0 : alpha;
}

template <typename Precision>
Precision selu(Precision x) noexcept
{
    static const Precision lambda = 1.050701;
    static const Precision beta   = 1.758099;

    return x > 0.0 ? lambda * x : beta * (std::exp(x) - 1.0);
}
template <typename Precision>
Precision selu_derived(Precision x) noexcept
{
    static const Precision lambda = 1.050701;
    static const Precision beta   = 1.758099;

    return x > 0.0 ? lambda : beta * std::exp(x);
}

template <typename Precision>
Precision gelu(Precision x) noexcept
{
    static const Precision a = 0.797885;
    static const Precision b = 0.0356774;

    return 0.5 * x * (std::tanh(x * a + x * x * x * b) + 1.0);
}
template <typename Precision>
Precision gelu_derived(Precision x) noexcept
{
    static const Precision a = 0.797885;
    static const Precision b = 0.0356774;
    static const Precision c = 0.0535161;
    static const Precision d = 0.398942;

    static Precision x3;
    static Precision y;
    static Precision sch;

    x3  = x * x * x;
    y   = a * x3 + b * x;
    sch = 1.0 / std::cosh(y);

    return 0.5 * std::tanh(y) + (c * x3 + d * x) * sch * sch + 0.5;
}

template <typename Precision>
Precision sigmoid(Precision x) noexcept
{
    return 1.0 / (std::exp(-x) + 1.0);
}
template <typename Precision>
Precision sigmoid_derived(Precision x) noexcept
{
    return 0.5 / (std::cosh(x) + 1.0);
}

template <typename Precision>
Precision tanh(Precision x) noexcept
{
    return std::tanh(x);
}
template <typename Precision>
Precision tanh_derived(Precision x) noexcept
{
    static Precision sech;
    sech = 1.0 / std::cosh(x);

    return sech * sech;
}

template <typename Precision>
Precision softsign(Precision x) noexcept
{
    return x / (std::fabs(x) + 1.0);
}
template <typename Precision>
Precision softsign_derived(Precision x) noexcept
{
    static Precision f;
    f = 1.0 / (std::fabs(x) + 1.0);

    return f * f;
}

template <typename Precision>
Precision softplus(Precision x) noexcept
{
    return std::log(std::exp(x) + 1.0);
}
template <typename Precision>
Precision softplus_derived(Precision x) noexcept
{
    return 1.0 / (std::exp(-x) + 1.0);
}

template <typename Precision>
Precision swish(Precision x) noexcept
{
    return x / (std::exp(-x) + 1.0);
}
template <typename Precision>
Precision swish_derived(Precision x) noexcept
{
    static Precision a;
    static Precision b;

    a = std::exp(-x);
    b = a + 1;

    return (a * x + b) / (b * b);
}

template <typename Precision>
Precision mod_relu(Precision x) noexcept
{
    if      (x < 0.0) return 0.01 * x;
    else if (x > 1.0) return 0.99 + 0.01 * x;
    else              return x;
}
template <typename Precision>
Precision mod_relu_derived(Precision x) noexcept
{
    if (x < 0.0 || x > 1.0) return 0.01;
    else return 1.0;
}

template <typename Precision>
Precision mod_tanh(Precision x) noexcept
{
    if (x < 0.0) return 0.01 * std::tanh(x);
    else         return std::tanh(x);
}
template <typename Precision>
Precision mod_tanh_derived(Precision x) noexcept
{
    static Precision sech2;

    sech2  = 1.0 / std::cosh(x);
    sech2 *= sech2;

    if (x < 0.0) return 0.01 * sech2;
    else         return sech2;
}

} // namespace detail

TRIXY_FUNCTION_GENERIC_HELPER(relu)
TRIXY_FUNCTION_GENERIC_HELPER(elu)
TRIXY_FUNCTION_GENERIC_HELPER(lrelu)
TRIXY_FUNCTION_GENERIC_HELPER(selu)
TRIXY_FUNCTION_GENERIC_HELPER(gelu)

TRIXY_FUNCTION_GENERIC_HELPER(sigmoid)
TRIXY_FUNCTION_GENERIC_HELPER(tanh)

TRIXY_FUNCTION_GENERIC_HELPER(softsign)
TRIXY_FUNCTION_GENERIC_HELPER(softplus)
TRIXY_FUNCTION_GENERIC_HELPER(swish)

TRIXY_FUNCTION_GENERIC_HELPER(mod_relu)
TRIXY_FUNCTION_GENERIC_HELPER(mod_tanh)

TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
void unstable_softmax(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& vector) noexcept
{
    for(std::size_t i = 0; i < vector.size(); ++i)
        buff(i) = std::exp(vector(i));

    Precision denominator = 0.0;
    for(std::size_t i = 0; i < vector.size(); ++i)
        denominator += buff(i);

    for(std::size_t i = 0; i < vector.size(); ++i)
        buff(i) /= denominator;
}

TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
void softmax(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& vector) noexcept
{
    static Precision max;
    static Precision denominator;

    max = vector(0);
    for(std::size_t i = 1; i < vector.size(); ++i)
        if(max < vector(i)) max = vector(i);

    for(std::size_t i = 0; i < vector.size(); ++i)
        buff(i) = std::exp(vector(i) - max);

    denominator = 0.0;
    for(std::size_t i = 0; i < vector.size(); ++i)
        denominator += buff(i);

    for(std::size_t i = 0; i < vector.size(); ++i)
        buff(i) /= denominator;
}

TRIXY_TENSOR_FUNCTION_TPL_DECLARATION
void tensor_of_units(
    Tensor<Precision, Args...>& buff,
    const Tensor<Precision, Args...>& /*unused*/) noexcept
{
    buff.fill(1.0);
}

} // namespace activation

namespace loss
{

TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
Precision categorical_cross_entropy(
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred) noexcept
{
    static const Precision epsilon = 1e-9;
    static Precision result;

    result = 0.0;
    for(std::size_t i = 0; i < y_true.size(); ++i)
        result -= y_true(i) * std::log(y_pred(i) + epsilon);

    return result;
}

TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
void categorical_cross_entropy_derived(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred) noexcept
{
    static const Precision epsilon = 1e-9;

    for(std::size_t i = 0; i < y_true.size(); ++i)
        buff(i) = - y_true(i) / (y_pred(i) + epsilon);
}

TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
void categorical_cross_entropy_derived_softmax(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred) noexcept
{
    for(std::size_t i = 0; i < y_true.size(); ++i)
        buff(i) = y_pred(i) - y_true(i);
}

TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
Precision mean_squared_error(
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred) noexcept
{
    static Precision result;

    result = 0.0;
    for(std::size_t i = 0; i < y_true.size(); ++i)
        result += std::pow(y_true(i) - y_pred(i), 2);

    return result / 2.0;
}

TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
void mean_squared_error_derived(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred) noexcept
{
    for(std::size_t i = 0; i < y_true.size(); ++i)
        buff(i) = y_pred(i) - y_true(i);
}

TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
Precision mean_absolute_error(
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred) noexcept
{
    static Precision result;

    result = 0.0;
    for(std::size_t i = 0; i < y_true.size(); ++i)
        result += std::fabs(y_true(i) - y_pred(i));

    return result;
}

TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
void mean_absolute_error_derived(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred) noexcept
{
    for(std::size_t i = 0; i < y_true.size(); ++i)
        buff(i) = y_true(i) > y_pred(i) ? -1.0 : 1.0;
}

TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
Precision mean_squared_log_error(
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred) noexcept
{
    static Precision result;

    result = 0.0;
    for(std::size_t i = 0; i < y_true.size(); ++i)
        result += std::pow(std::log( (y_pred(i) + 1.0) / (y_true(i) + 1.0) ), 2);

    return result / 2.0;
}

TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
void mean_squared_log_error_derived(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred) noexcept
{
    for(std::size_t i = 0; i < y_true.size(); ++i)
    {
        buff(i)  = y_pred(i) + 1.0;
        buff(i) /= std::log(buff(i) / (y_true(i) + 1.0));
    }
}

TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
Precision binary_cross_entropy(
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred) noexcept
{
    static const Precision epsilon = 1e-9;
    static const Precision alpha   = epsilon + 1.0;
    static Precision result;

    result = 0.0;
    for(std::size_t i = 0; i < y_true.size(); ++i)
        result -= y_true(i) * std::log(y_pred(i) + epsilon)
                  + (1.0 - y_true(i)) * std::log(alpha - y_pred(i));

    return result;
}

TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
void binary_cross_entropy_derived(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred) noexcept
{
    static const Precision epsilon = 1e-9;
    static const Precision alpha   = epsilon - 1.0;

    for(std::size_t i = 0; i < y_true.size(); ++i)
        buff(i) =
            (y_true(i) - 1.0) / (y_pred(i) + alpha) - y_true(i) / (y_pred(i) + epsilon);
}

TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
void binary_cross_entropy_derived_sigmoid(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred) noexcept
{
    for(std::size_t i = 0; i < y_true.size(); ++i)
        buff(i) = y_true(i) * (y_pred(i) - 1.0) + (1.0 - y_true(i)) * y_pred(i);
}

TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
Precision logcosh(
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred) noexcept
{
    static Precision result;

    result = 0.0;
    for(std::size_t i = 0; i < y_true.size(); ++i)
        result += std::log( std::cosh(y_pred(i) - y_true(i)) );

    return result;
}

TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
void logcosh_derived(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred) noexcept
{
    for(std::size_t i = 0; i < y_true.size(); ++i)
        buff(i) = std::tanh(y_pred(i) - y_true(i));
}

} // namespace loss

namespace optimization
{

namespace detail
{

template <typename Precision>
Precision invertSqrt(Precision x) noexcept
{
    return 1.0 / std::sqrt(1e-9 + x);
}

} // namespace detail

TRIXY_TENSOR_FUNCTION_TPL_DECLARATION
void momentum(
    Tensor<Precision, Args...>& buff,
    Tensor<Precision, Args...>& s,
    const Tensor<Precision, Args...>& g) noexcept
{
    static const Precision beta1 = 0.9;
    static const Precision beta2 = 1.0 - beta1;

    s.join(beta1);
    s.add(buff.join(beta2, g));

    buff.copy(s);
}

TRIXY_TENSOR_FUNCTION_TPL_DECLARATION
void rms_prop(
    Tensor<Precision, Args...>& buff,
    Tensor<Precision, Args...>& s,
    const Tensor<Precision, Args...>& g) noexcept
{
    static const Precision beta1 = 0.9;
    static const Precision beta2 = 1.0 - beta1;

    s.join(beta1);
    s.add(buff.multiply(g, g).join(beta2));

    buff.multiply(g, s.apply(detail::invertSqrt));
}

TRIXY_TENSOR_FUNCTION_TPL_DECLARATION
void ada_grad(
    Tensor<Precision, Args...>& buff,
    Tensor<Precision, Args...>& s,
    const Tensor<Precision, Args...>& g)
{
    s.add(buff.multiply(g, g));
    buff.multiply(g, s.apply(detail::invertSqrt));
}

} // namespace optimization

} // namespace set

namespace meta
{

template <template <template <typename, typename...> class T, typename P, typename...> class FunctionData,
          template <typename, typename...> class Tensor,
          typename Precision, typename... Args>
struct is_activation_data
{
    using Tensor_t       = Tensor<Precision, Args...>;
    using FunctionData_t = FunctionData<Tensor, Precision, Args...>;

    static constexpr bool value =
        std::is_same<decltype(std::declval<FunctionData_t>().f), void (*)(Tensor_t&, const Tensor_t&)>::value &&
        std::is_same<decltype(std::declval<FunctionData_t>().df), void (*)(Tensor_t&, const Tensor_t&)>::value;
};

template <template <template <typename, typename...> class T, typename P, typename...> class FunctionData,
          template <typename, typename...> class Tensor,
          typename Precision, typename... Args>
struct is_loss_data
{
    using Tensor_t       = Tensor<Precision, Args...>;
    using FunctionData_t = FunctionData<Tensor, Precision, Args...>;

    static constexpr bool value =
        std::is_same<decltype(std::declval<FunctionData_t>().f), Precision (*)(const Tensor_t&, const Tensor_t&)>::value &&
        std::is_same<decltype(std::declval<FunctionData_t>().df), void (*)(Tensor_t&, const Tensor_t&, const Tensor_t&)>::value;
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
    using Vector_t       = Vector<Precision, Args...>;
    using Matrix_t       = Matrix<Precision, Args...>;
    using FunctionData_t = FunctionData<Vector, Matrix, Precision, Args...>;

    static constexpr bool value =
        std::is_same<decltype(std::declval<FunctionData_t>().f1D), void (*)(Vector_t&, Vector_t&, const Vector_t&)>::value &&
        std::is_same<decltype(std::declval<FunctionData_t>().f2D), void (*)(Matrix_t&, Matrix_t&, const Matrix_t&)>::value;
};

template <bool condition, typename T = void>
using enable_if_t = typename std::enable_if<condition, T>::type;

} // namespace meta

namespace function
{
	
enum class activation
{
    sigmoid,
    tanh,
    relu,
    elu,
    lrelu,
    selu,
    gelu,
    softsign,
    softplus,
    swish,
    softmax,
    mod_relu,
    mod_tanh,
    unstable_softmax,
    sigmoid_
};

enum class loss
{
    MSE,
    MAE,
    CCE,
    BCE,
    MSLE,
    LC,
    CCE_,
    BCE_
};

enum class optimization
{
    momentum,
    rms_prop,
    ada_grad
};

} // namespace function

TRIXY_NEURO_MANAGER_TPL_DECLARATION
class NeuroManager
{
public:
    template <template <template <typename, typename...> class T,
                        typename P, typename...>
              class FunctionData,
              meta::enable_if_t<meta::is_activation_data<FunctionData, Vector, Precision, Args...>::value, int> = 0>
    static FunctionData<Vector, Precision, Args...> get(function::activation id) noexcept;

    template <template <template <typename, typename...> class T,
                        typename P, typename...>
              class FunctionData,
              meta::enable_if_t<meta::is_loss_data<FunctionData, Vector, Precision, Args...>::value, int> = 0>
    static FunctionData<Vector, Precision, Args...> get(function::loss id) noexcept;

    template <template <template <typename, typename...> class T1,
                        template <typename, typename...> class T2,
                        typename P, typename...>
              class FunctionData,
              meta::enable_if_t<meta::is_optimization_data<FunctionData, Vector, Matrix, Precision, Args...>::value, int> = 0>
    static FunctionData<Vector, Matrix, Precision, Args...> get(function::optimization id) noexcept;
};

TRIXY_NEURO_MANAGER_TPL_DECLARATION
template <template <template <typename, typename...> class T, typename P, typename...> class FunctionData,
          meta::enable_if_t<meta::is_activation_data<FunctionData, Vector, Precision, Args...>::value, int>>
FunctionData<Vector, Precision, Args...>
    TRIXY_NEURO_MANAGER_DECLARATION::get(function::activation id) noexcept
{
    using namespace set::activation;
    using namespace function;

    switch (id)
    {
    case activation::sigmoid:
        return { sigmoid, sigmoid_derived };
    case activation::tanh:
        return { tanh, tanh_derived };
    case activation::relu:
        return { relu, relu_derived };

    case activation::elu:
        return { elu, elu_derived };
    case activation::lrelu:
        return { lrelu, lrelu_derived };
    case activation::selu:
        return { selu, selu_derived };
    case activation::gelu:
        return { gelu, gelu_derived };

    case activation::softsign:
        return { softsign, softsign_derived };
    case activation::softplus:
        return { softplus, softplus_derived };
    case activation::swish:
        return { swish, swish_derived };

    case activation::mod_relu:
        return { mod_relu, mod_relu_derived };
    case activation::mod_tanh:
        return { mod_tanh, mod_tanh_derived };

    case activation::softmax:
        return { softmax, tensor_of_units };

    case activation::unstable_softmax:
        return { unstable_softmax, tensor_of_units };
    case activation::sigmoid_:
        return { sigmoid, tensor_of_units };

    default:
        return {};
    }
}

TRIXY_NEURO_MANAGER_TPL_DECLARATION
template <template <template <typename, typename...> class T, typename P, typename...> class FunctionData,
          meta::enable_if_t<meta::is_loss_data<FunctionData, Vector, Precision, Args...>::value, int>>
FunctionData<Vector, Precision, Args...>
    TRIXY_NEURO_MANAGER_DECLARATION::get(function::loss id) noexcept
{
    using namespace set::loss;
    using namespace function;

    switch (id)
    {
    case loss::MSE:
        return { mean_squared_error, mean_squared_error_derived };
    case loss::MAE:
        return { mean_absolute_error, mean_absolute_error_derived };
    case loss::CCE:
        return { categorical_cross_entropy, categorical_cross_entropy_derived_softmax };

    case loss::BCE:
        return { binary_cross_entropy, binary_cross_entropy_derived_sigmoid };
    case loss::MSLE:
        return { mean_squared_log_error, mean_squared_log_error_derived };

    case loss::LC:
        return { logcosh, logcosh_derived };

    case loss::CCE_:
        return { categorical_cross_entropy, categorical_cross_entropy_derived };
    case loss::BCE_:
        return { binary_cross_entropy, binary_cross_entropy_derived };

    default:
        return {};
    }
}

TRIXY_NEURO_MANAGER_TPL_DECLARATION
template <template <template <typename, typename...> class T1,
                    template <typename, typename...> class T2,
                    typename P, typename...>
          class FunctionData,
          meta::enable_if_t<meta::is_optimization_data<FunctionData, Vector, Matrix, Precision, Args...>::value, int>>
FunctionData<Vector, Matrix, Precision, Args...>
    TRIXY_NEURO_MANAGER_DECLARATION::get(function::optimization id) noexcept
{
    using namespace set::optimization;
    using namespace function;

    switch (id)
    {
    case optimization::momentum:
        return { momentum, momentum };

    case optimization::rms_prop:
        return { rms_prop, rms_prop };
    case optimization::ada_grad:
        return { ada_grad, ada_grad };

    default:
        return {};
    }
}

} // namespace trixy

// clean up
#undef TRIXY_TENSOR_FUNCTION_TPL_DECLARATION
#undef TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
#undef TRIXY_NEURO_MANAGER_TPL_DECLARATION
#undef TRIXY_NEURO_MANAGER_DECLARATION
#undef TRIXY_FUNCTION_GENERIC_HELPER

#endif // NEURO_FUNCTIONAL_HPP
