#ifndef NEURO_FUNCTIONAL_HPP
#define NEURO_FUNCTIONAL_HPP

#include <cstddef> // size_t
#include <cstdint> // uint_8
#include <cmath> // sqrt, pow, exp, log, fabs, tanh, cosh
#include <utility> // declval
#include <type_traits> // enable_if, is_same, true_type
#include <fstream> // ifstream, ofstream

namespace trixy
{

template <template <typename, typename...> class Vector,
          template <typename, typename...> class Matrix,
          typename Precision, typename... Args>
class NeuroManager;

template <template <typename, typename...> class Vector,
          template <typename, typename...> class Matrix,
          template <typename...> class Container,
          typename Precision, typename... Args>
class NeuroSerializer;

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

#define TRIXY_NEURO_SERIALIZER_TPL_DECLARATION                 \
    template <template <typename, typename...> class Vector,   \
              template <typename, typename...> class Matrix,   \
              template <typename...> class Container,          \
              typename Precision, typename... Args>

#define TRIXY_NEURO_SERIALIZER_TPL                             \
    NeuroSerializer<Vector, Matrix,                            \
        Container, Precision, Args...>

#define TRIXY_FUNCTION_GENERIC_HELPER(name)                                                          \
    template <template <typename T, typename...> class Tensor, typename Precision, typename... Args> \
    void name(                                                                                       \
        Tensor<Precision, Args...>& buff, const Tensor<Precision, Args...>& tensor) noexcept {       \
        buff.apply(detail::name, tensor);                                                            \
    }                                                                                                \
    template <template <typename T, typename...> class Tensor, typename Precision, typename... Args> \
    void name##_derived(                                                                             \
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

template <typename Neuro, decltype(
    std::declval<Neuro>().getTopology(),
    std::declval<Neuro>().getInnerBias(),
    std::declval<Neuro>().getInnerWeight(),
    std::declval<Neuro>().getEachActivationFunction(),
    std::declval<Neuro>().getLossFunction(),
    std::declval<Neuro>().getOptimizationFunction(),
    int()) = 0>
struct is_serializable_neuro : std::true_type
{
};

template <bool condition, typename T = void>
using enable_if_t = typename std::enable_if<condition, T>::type;

} // namespace meta

namespace function
{

enum class activation_id : std::uint8_t
{
    null,              ///< null value
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
    unstable_softmax,  ///< deprecated
    sigmoid_           ///< maybe unused
};

enum class loss_id : std::uint8_t
{
    null,  ///< null value
    MSE,   ///< mean squared error
    MAE,   ///< mean absolute error
    CCE,   ///< categorical cross entropy (for softmax)
    BCE,   ///< binary cross entropy (for sigmoid)
    MSLE,  ///< mean squared logarithmic error
    LC,    ///< logcosh (maybe unused)
    CCE_,  ///< categorical cross entropy (deprecated)
    BCE_   ///< binary_cross_entropy (maybe unused)
};

enum class optimization_id : std::uint8_t
{
    null,      ///< null value
    momentum,  ///< mpmentum
    rms_prop,  ///< root mean square propagation (RMSProp)
    ada_grad   ///< adaptive Gradient Algorithm (Adagrad)
};

} // namespace function

TRIXY_NEURO_MANAGER_TPL_DECLARATION
class NeuroManager
{
public:
    using byte_type = std::uint8_t;

public:
    template <template <template <typename, typename...> class T,
                        typename P, typename...>
              class FunctionData,
              meta::enable_if_t<meta::is_activation_data<FunctionData, Vector, Precision, Args...>::value, int> = 0>
    static FunctionData<Vector, Precision, Args...> get(function::activation_id id) noexcept;

    template <template <template <typename, typename...> class T,
                        typename P, typename...>
              class FunctionData,
              meta::enable_if_t<meta::is_loss_data<FunctionData, Vector, Precision, Args...>::value, int> = 0>
    static FunctionData<Vector, Precision, Args...> get(function::loss_id id) noexcept;

    template <template <template <typename, typename...> class T1,
                        template <typename, typename...> class T2,
                        typename P, typename...>
              class FunctionData,
              meta::enable_if_t<meta::is_optimization_data<FunctionData, Vector, Matrix, Precision, Args...>::value, int> = 0>
    static FunctionData<Vector, Matrix, Precision, Args...> get(function::optimization_id id) noexcept;
};

TRIXY_NEURO_MANAGER_TPL_DECLARATION
template <template <template <typename, typename...> class T, typename P, typename...> class FunctionData,
          meta::enable_if_t<meta::is_activation_data<FunctionData, Vector, Precision, Args...>::value, int>>
FunctionData<Vector, Precision, Args...>
    TRIXY_NEURO_MANAGER_DECLARATION::get(function::activation_id id) noexcept
{
    using namespace set::activation;
    using namespace function;

    static byte_type f_id;

    f_id = static_cast<byte_type>(id);

    switch (id)
    {
    case activation_id::sigmoid:
        return { f_id, sigmoid, sigmoid_derived };
    case activation_id::tanh:
        return { f_id, tanh, tanh_derived };
    case activation_id::relu:
        return { f_id, relu, relu_derived };

    case activation_id::elu:
        return { f_id, elu, elu_derived };
    case activation_id::lrelu:
        return { f_id, lrelu, lrelu_derived };
    case activation_id::selu:
        return { f_id, selu, selu_derived };
    case activation_id::gelu:
        return { f_id, gelu, gelu_derived };

    case activation_id::softsign:
        return { f_id, softsign, softsign_derived };
    case activation_id::softplus:
        return { f_id, softplus, softplus_derived };
    case activation_id::swish:
        return { f_id, swish, swish_derived };

    case activation_id::mod_relu:
        return { f_id, mod_relu, mod_relu_derived };
    case activation_id::mod_tanh:
        return { f_id, mod_tanh, mod_tanh_derived };

    case activation_id::softmax:
        return { f_id, softmax, tensor_of_units };

    case activation_id::unstable_softmax:
        return { f_id, unstable_softmax, tensor_of_units };
    case activation_id::sigmoid_:
        return { f_id, sigmoid, tensor_of_units };

    default:
        return { static_cast<byte_type>(activation_id::null), nullptr, nullptr };
    }
}

TRIXY_NEURO_MANAGER_TPL_DECLARATION
template <template <template <typename, typename...> class T, typename P, typename...> class FunctionData,
          meta::enable_if_t<meta::is_loss_data<FunctionData, Vector, Precision, Args...>::value, int>>
FunctionData<Vector, Precision, Args...>
    TRIXY_NEURO_MANAGER_DECLARATION::get(function::loss_id id) noexcept
{
    using namespace set::loss;
    using namespace function;

    static byte_type f_id;

    f_id = static_cast<decltype(f_id)>(id);

    switch (id)
    {
    case loss_id::MSE:
        return { f_id, mean_squared_error, mean_squared_error_derived };
    case loss_id::MAE:
        return { f_id, mean_absolute_error, mean_absolute_error_derived };
    case loss_id::CCE:
        return { f_id, categorical_cross_entropy, categorical_cross_entropy_derived_softmax };

    case loss_id::BCE:
        return { f_id, binary_cross_entropy, binary_cross_entropy_derived_sigmoid };
    case loss_id::MSLE:
        return { f_id, mean_squared_log_error, mean_squared_log_error_derived };

    case loss_id::LC:
        return { f_id, logcosh, logcosh_derived };

    case loss_id::CCE_:
        return { f_id, categorical_cross_entropy, categorical_cross_entropy_derived };
    case loss_id::BCE_:
        return { f_id, binary_cross_entropy, binary_cross_entropy_derived };

    default:
        return { static_cast<byte_type>(loss_id::null), nullptr, nullptr };
    }
}

TRIXY_NEURO_MANAGER_TPL_DECLARATION
template <template <template <typename, typename...> class T1,
                    template <typename, typename...> class T2,
                    typename P, typename...>
          class FunctionData,
          meta::enable_if_t<meta::is_optimization_data<FunctionData, Vector, Matrix, Precision, Args...>::value, int>>
FunctionData<Vector, Matrix, Precision, Args...>
    TRIXY_NEURO_MANAGER_DECLARATION::get(function::optimization_id id) noexcept
{
    using namespace set::optimization;
    using namespace function;

    static byte_type f_id;

    f_id = static_cast<byte_type>(id);

    switch (id)
    {
    case optimization_id::momentum:
        return { f_id, momentum, momentum };

    case optimization_id::rms_prop:
        return { f_id, rms_prop, rms_prop };
    case optimization_id::ada_grad:
        return { f_id, ada_grad, ada_grad };

    default:
        return { static_cast<byte_type>(optimization_id::null), nullptr, nullptr };
    }
}

TRIXY_NEURO_SERIALIZER_TPL_DECLARATION
class NeuroSerializer
{
public:
    using Tensor1D  = Vector<Precision, Args...>;
    using Tensor2D  = Matrix<Precision, Args...>;

    using size_type = std::size_t;

private:
    Container<size_type> topology;

    Container<Tensor1D> B;
    Container<Tensor2D> W;

    size_type N;

    Container<function::activation_id> A;
    function::loss_id L;
    function::optimization_id O;

public:
    NeuroSerializer() = default;

    template <typename Neuro>
    meta::enable_if_t<meta::is_serializable_neuro<Neuro>::value, void>
    prepare(const Neuro& net);

    void serialize(std::ofstream& out) const;
    void deserialize(std::ifstream& in);

    const Container<size_type>& getTopology() const noexcept;
    const Container<Tensor1D>& getBias() const noexcept;
    const Container<Tensor2D>& getWeight() const noexcept;

    const function::activation_id getActivationId() const noexcept;
    const function::activation_id getNormalizationId() const noexcept;
    const Container<function::activation_id> getEachActivationId() const noexcept;

    const function::loss_id getLossId() const noexcept;
    const function::optimization_id getOptimizationId() const noexcept;
};

TRIXY_NEURO_SERIALIZER_TPL_DECLARATION
template <typename Neuro>
meta::enable_if_t<meta::is_serializable_neuro<Neuro>::value, void>
TRIXY_NEURO_SERIALIZER_TPL::prepare(
    const Neuro& net)
{
    topology = net.getTopology();

    B = net.getInnerBias();
    W = net.getInnerWeight();

    N = B.size();

    A.resize(N);
    for(size_type i = 0; i < N; ++i)
        A[i] = static_cast<function::activation_id>(net.getEachActivationFunction()[i].id);

    L = static_cast<function::loss_id>(net.getLossFunction().id);
    O = static_cast<function::optimization_id>(net.getOptimizationFunction().id);
}

TRIXY_NEURO_SERIALIZER_TPL_DECLARATION
void TRIXY_NEURO_SERIALIZER_TPL::serialize(std::ofstream& out) const
{
    static size_type topology_size;

    topology_size = topology.size();
    out.write(reinterpret_cast<const char*>(&topology_size), sizeof(size_type));

    for(size_type n = 0; n < topology_size; ++n)
        out.write(reinterpret_cast<const char*>(&topology[n]), sizeof(size_type));

    for(size_type n = 0; n < N; ++n)
        out.write(reinterpret_cast<const char*>(&A[n]), sizeof(function::activation_id));

    out.write(reinterpret_cast<const char*>(&L), sizeof(function::loss_id));
    out.write(reinterpret_cast<const char*>(&O), sizeof(function::optimization_id));

    for(size_type n = 0; n < N; ++n)
        for(size_type i = 0; i < B[n].size(); ++i)
            out.write(reinterpret_cast<const char*>(&B[n](i)), sizeof(Precision));

    for(size_type n = 0; n < N; ++n)
        for(size_type i = 0; i < W[n].size().row(); ++i)
            for(size_type j = 0; j < W[n].size().col(); ++j)
                out.write(reinterpret_cast<const char*>(&W[n](i, j)), sizeof(Precision));
}

TRIXY_NEURO_SERIALIZER_TPL_DECLARATION
void TRIXY_NEURO_SERIALIZER_TPL::deserialize(std::ifstream& in)
{
    static size_type topology_size;

    in.read(reinterpret_cast<char*>(&topology_size), sizeof(size_type));

    topology.resize(topology_size);
    for(size_type n = 0; n < topology_size; ++n)
        in.read(reinterpret_cast<char*>(&topology[n]), sizeof(size_type));

    N = topology_size - 1;

    A.resize(N);
    B.resize(N);
    W.resize(N);

    for(size_type n = 0; n < N; ++n)
    {
        B[n].resize(topology[n + 1]);
        W[n].resize(topology[n], topology[n + 1]);
    }

    for(size_type n = 0; n < N; ++n)
        in.read(reinterpret_cast<char*>(&A[n]), sizeof(function::activation_id));

    in.read(reinterpret_cast<char*>(&L), sizeof(function::loss_id));
    in.read(reinterpret_cast<char*>(&O), sizeof(function::optimization_id));

    for(size_type n = 0; n < N; ++n)
        for(size_type i = 0; i < B[n].size(); ++i)
            in.read(reinterpret_cast<char*>(&B[n](i)), sizeof(Precision));

    for(size_type n = 0; n < N; ++n)
        for(size_type i = 0; i < W[n].size().row(); ++i)
            for(size_type j = 0; j < W[n].size().col(); ++j)
                in.read(reinterpret_cast<char*>(&W[n](i, j)), sizeof(Precision));
}

TRIXY_NEURO_SERIALIZER_TPL_DECLARATION
inline const Container<std::size_t>&
    TRIXY_NEURO_SERIALIZER_TPL::getTopology() const noexcept
{
    return topology;
}

TRIXY_NEURO_SERIALIZER_TPL_DECLARATION
inline const Container<Vector<Precision, Args...>>&
    TRIXY_NEURO_SERIALIZER_TPL::getBias() const noexcept
{
    return B;
}

TRIXY_NEURO_SERIALIZER_TPL_DECLARATION
inline const Container<Matrix<Precision, Args...>>&
    TRIXY_NEURO_SERIALIZER_TPL::getWeight() const noexcept
{
    return W;
}

TRIXY_NEURO_SERIALIZER_TPL_DECLARATION
inline const function::activation_id TRIXY_NEURO_SERIALIZER_TPL::getActivationId() const noexcept
{
    return static_cast<function::activation_id>(A[0]);
}

TRIXY_NEURO_SERIALIZER_TPL_DECLARATION
inline const function::activation_id TRIXY_NEURO_SERIALIZER_TPL::getNormalizationId() const noexcept
{
    return A[A.size() - 1];
}

TRIXY_NEURO_SERIALIZER_TPL_DECLARATION
inline const Container<function::activation_id>
    TRIXY_NEURO_SERIALIZER_TPL::getEachActivationId() const noexcept
{
    return A;
}

TRIXY_NEURO_SERIALIZER_TPL_DECLARATION
inline const function::loss_id TRIXY_NEURO_SERIALIZER_TPL::getLossId() const noexcept
{
    return L;
}

TRIXY_NEURO_SERIALIZER_TPL_DECLARATION
inline const function::optimization_id TRIXY_NEURO_SERIALIZER_TPL::getOptimizationId() const noexcept
{
    return O;
}

} // namespace trixy

// clean up
#undef TRIXY_TENSOR_FUNCTION_TPL_DECLARATION
#undef TRIXY_VECTOR_FUNCTION_TPL_DECLARATION
#undef TRIXY_NEURO_MANAGER_TPL_DECLARATION
#undef TRIXY_NEURO_MANAGER_DECLARATION
#undef TRIXY_NEURO_SERIALIZER_TPL_DECLARATION
#undef TRIXY_NEURO_SERIALIZER_TPL
#undef TRIXY_FUNCTION_GENERIC_HELPER

#endif // NEURO_FUNCTIONAL_HPP
