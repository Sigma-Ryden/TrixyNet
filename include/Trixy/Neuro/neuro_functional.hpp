#ifndef NEURO_FUNCTIONAL_HPP
#define NEURO_FUNCTIONAL_HPP

#include <cstddef> // size_t
#include <cmath> // pow, exp, log, fabs, tanh, cosh
#include <utility> // declval
#include <type_traits> // enable_if, is_same
#include <map> // map

#define TRIXY_TENSOR_FUNCTION_DECLARATION                      \
    template <template <typename T, typename...> class Tensor, \
              typename Precision,                              \
              typename... Args>

#define TRIXY_VECTOR_FUNCTION_DECLARATION                      \
    template <template <typename T, typename...> class Vector, \
              typename Precision,                              \
              typename... Args>

#define TRIXY_FUNCTION_GENERIC_HELPER(name)                                                          \
    template <template <typename T, typename...> class Tensor, typename Precision, typename... Args> \
    Tensor<Precision, Args...>& name(                                                                \
        Tensor<Precision, Args...>& buff, const Tensor<Precision, Args...>& tensor) {                \
        return buff.apply(detail::name, tensor);                                                     \
    }                                                                                                \
    template <template <typename T, typename...> class Tensor, typename Precision, typename... Args> \
    Tensor<Precision, Args...>& name##_derived(                                                      \
        Tensor<Precision, Args...>& buff, const Tensor<Precision, Args...>& tensor) {                \
        return buff.apply(detail::name##_derived, tensor);                                           \
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
Precision relu(Precision x)
{
    return x > 0.0 ? x : 0.0;
}
template <typename Precision>
Precision relu_derived(Precision x)
{
    return x > 0.0 ? 1.0 : 0.0;
}

template <typename Precision>
Precision elu(Precision x)
{
    static const Precision alpha = 0.2;
    return x > 0.0 ? x : alpha * (std::exp(x) - 1.0);
}
template <typename Precision>
Precision elu_derived(Precision x)
{
    static const Precision alpha = 0.2;
    return x > 0.0 ? 1.0 : alpha * std::exp(x);
}

template <typename Precision>
Precision lrelu(Precision x)
{
    static const Precision alpha = 0.01;
    return x > 0.0 ? x : alpha * x;
}
template <typename Precision>
Precision lrelu_derived(Precision x)
{
    static const Precision alpha = 0.01;
    return x > 0.0 ? 1.0 : alpha;
}

template <typename Precision>
Precision selu(Precision x)
{
    static const Precision lambda = 1.050701;
    static const Precision beta   = 1.758099;

    return x > 0.0 ? lambda * x : beta * (std::exp(x) - 1.0);
}
template <typename Precision>
Precision selu_derived(Precision x)
{
    static const Precision lambda = 1.050701;
    static const Precision beta   = 1.758099;

    return x > 0.0 ? lambda : beta * std::exp(x);
}

template <typename Precision>
Precision gelu(Precision x)
{
    static const Precision a = 0.797885;
    static const Precision b = 0.0356774;

    return 0.5 * x * (std::tanh(x * a + x * x * x * b) + 1.0);
}
template <typename Precision>
Precision gelu_derived(Precision x)
{
    static const Precision a = 0.797885;
    static const Precision b = 0.0356774;
    static const Precision c = 0.0535161;
    static const Precision d = 0.398942;

    static Precision x3;
    static Precision y;
    static Precision sch;

    x3 = x * x * x;
    y = a * x3 + b * x;
    sch = 1.0 / std::cosh(y);

    return 0.5 * std::tanh(y) + (c * x3 + d * x) * sch * sch + 0.5;
}

template <typename Precision>
Precision sigmoid(Precision x)
{
    return 1.0 / (std::exp(-x) + 1.0);
}
template <typename Precision>
Precision sigmoid_derived(Precision x)
{
    return 0.5 / (std::cosh(x) + 1.0);
}

template <typename Precision>
Precision tanh(Precision x)
{
    return std::tanh(x);
}
template <typename Precision>
Precision tanh_derived(Precision x)
{
    static Precision sech;
    sech = 1.0 / std::cosh(x);

    return sech * sech;
}

template <typename Precision>
Precision softsign(Precision x)
{
    return x / (std::fabs(x) + 1.0);
}
template <typename Precision>
Precision softsign_derived(Precision x)
{
    static Precision f;
    f = 1.0 / (std::fabs(x) + 1.0);

    return f * f;
}

template <typename Precision>
Precision softplus(Precision x)
{
    return std::log(std::exp(x) + 1.0);
}
template <typename Precision>
Precision softplus_derived(Precision x)
{
    return 1.0 / (std::exp(-x) + 1.0);
}

template <typename Precision>
Precision swish(Precision x)
{
    return x / (std::exp(-x) + 1.0);
}
template <typename Precision>
Precision swish_derived(Precision x)
{
    static Precision a;
    static Precision b;

    a = std::exp(-x);
    b = a + 1;

    return (a * x + b) / (b * b);
}

template <typename Precision>
Precision mod_relu(Precision x)
{
    if      (x < 0.0) return 0.01 * x;
    else if (x > 1.0) return 0.99 + 0.01 * x;
    else              return x;
}
template <typename Precision>
Precision mod_relu_derived(Precision x)
{
    if (x < 0.0 || x > 1.0) return 0.01;
    else return 1.0;
}

template <typename Precision>
Precision mod_tanh(Precision x)
{
    if (x < 0.0) return 0.01 * std::tanh(x);
    else         return std::tanh(x);
}
template <typename Precision>
Precision mod_tanh_derived(Precision x)
{
    static Precision sech2;

    sech2 = 1.0 / std::cosh(x);
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

TRIXY_VECTOR_FUNCTION_DECLARATION
Vector<Precision, Args...>& unstable_softmax(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& vector)
{
    for(std::size_t i = 0; i < vector.size(); ++i)
        buff(i) = std::exp(vector(i));

    Precision denominator = 0.0;
    for(std::size_t i = 0; i < vector.size(); ++i)
        denominator += buff(i);

    for(std::size_t i = 0; i < vector.size(); ++i)
        buff(i) /= denominator;

    return buff;
}

TRIXY_VECTOR_FUNCTION_DECLARATION
Vector<Precision, Args...>& softmax(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& vector)
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

    return buff;
}

TRIXY_TENSOR_FUNCTION_DECLARATION
Tensor<Precision, Args...>& tensor_of_units(
    Tensor<Precision, Args...>& buff,
    const Tensor<Precision, Args...>&)
{
    return buff.fill(1.0);
}

} // namespace activation

namespace loss
{

TRIXY_VECTOR_FUNCTION_DECLARATION
Precision categorical_cross_entropy(
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred)
{
    static const Precision epsilon = 1e-9;
    static Precision result;

    result = 0.0;
    for(std::size_t i = 0; i < y_true.size(); ++i)
        result -= y_true(i) * std::log(y_pred(i) + epsilon);

    return result;
}

TRIXY_VECTOR_FUNCTION_DECLARATION
Vector<Precision, Args...>& categorical_cross_entropy_derived(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred)
{
    static const Precision epsilon = 1e-9;

    for(std::size_t i = 0; i < y_true.size(); ++i)
        buff(i) = - y_true(i) / (y_pred(i) + epsilon);

    return buff;
}

TRIXY_VECTOR_FUNCTION_DECLARATION
Vector<Precision, Args...>& categorical_cross_entropy_derived_softmax(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred)
{
    for(std::size_t i = 0; i < y_true.size(); ++i)
        buff(i) = y_pred(i) - y_true(i);

    return buff;
}

TRIXY_VECTOR_FUNCTION_DECLARATION
Precision mean_squared_error(
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred)
{
    static Precision result;

    result = 0.0;
    for(std::size_t i = 0; i < y_true.size(); ++i)
        result += std::pow(y_true(i) - y_pred(i), 2);

    return result / 2.0;
}

TRIXY_VECTOR_FUNCTION_DECLARATION
Vector<Precision, Args...>& mean_squared_error_derived(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred)
{
    for(std::size_t i = 0; i < y_true.size(); ++i)
        buff(i) = y_pred(i) - y_true(i);

    return buff;
}

TRIXY_VECTOR_FUNCTION_DECLARATION
Precision mean_absolute_error(
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred)
{
    static Precision result;

    result = 0.0;
    for(std::size_t i = 0; i < y_true.size(); ++i)
        result += std::fabs(y_true(i) - y_pred(i));

    return result;
}

TRIXY_VECTOR_FUNCTION_DECLARATION
Vector<Precision, Args...>& mean_absolute_error_derived(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred)
{
    for(std::size_t i = 0; i < y_true.size(); ++i)
        buff(i) = y_true(i) > y_pred(i) ? -1.0 : 1.0;

    return buff;
}

TRIXY_VECTOR_FUNCTION_DECLARATION
Precision mean_squared_logarithmic_error(
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred)
{
    static Precision result;

    result = 0.0;
    for(std::size_t i = 0; i < y_true.size(); ++i)
        result += std::pow(std::log( (y_pred(i) + 1.0) / (y_true(i) + 1.0) ), 2);

    return result / 2.0;
}

TRIXY_VECTOR_FUNCTION_DECLARATION
Vector<Precision, Args...>& mean_squared_logarithmic_error_derived(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred)
{
    for(std::size_t i = 0; i < y_true.size(); ++i)
    {
        buff(i) = y_pred(i) + 1.0;
        buff(i) /= std::log(buff(i) / (y_true(i) + 1.0));
    }
    return buff;
}

TRIXY_VECTOR_FUNCTION_DECLARATION
Precision binary_cross_entropy(
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred)
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

TRIXY_VECTOR_FUNCTION_DECLARATION
Vector<Precision, Args...>& binary_cross_entropy_derived(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred)
{
    static const Precision epsilon = 1e-9;
    static const Precision alpha   = epsilon - 1.0;

    for(std::size_t i = 0; i < y_true.size(); ++i)
        buff(i) =
            (y_true(i) - 1.0) / (y_pred(i) + alpha) - y_true(i) / (y_pred(i) + epsilon);

    return buff;
}

TRIXY_VECTOR_FUNCTION_DECLARATION
Vector<Precision, Args...>& binary_cross_entropy_derived_sigmoid(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred)
{
    for(std::size_t i = 0; i < y_true.size(); ++i)
        buff(i) = y_true(i) * (y_pred(i) - 1.0) + (1.0 - y_true(i)) * y_pred(i);

    return buff;
}

TRIXY_VECTOR_FUNCTION_DECLARATION
Precision logcosh(
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred)
{
    static Precision result;

    result = 0.0;
    for(std::size_t i = 0; i < y_true.size(); ++i)
        result += std::log( std::cosh(y_pred(i) - y_true(i)) );

    return result;
}

TRIXY_VECTOR_FUNCTION_DECLARATION
Vector<Precision, Args...>& logcosh_derived(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& y_true,
    const Vector<Precision, Args...>& y_pred)
{
    for(std::size_t i = 0; i < y_true.size(); ++i)
        buff(i) = std::tanh(y_pred(i) - y_true(i));

    return buff;
}

} // namespace loss

namespace data
{

template <template <typename T, typename...> class Tensor, class Precision, typename... Args>
struct ActivationData
{
    using Tensor_t = Tensor<Precision, Args...>;

    Tensor_t& (*f)(Tensor_t&, const Tensor_t&);
    Tensor_t& (*df)(Tensor_t&, const Tensor_t&);
};

template <template <typename T, typename...> class Tensor, typename Precision, typename... Args>
struct LossData
{
    using Tensor_t = Tensor<Precision, Args...>;

    Precision (*f)(const Tensor_t&, const Tensor_t&);
    Tensor_t& (*df)(Tensor_t&, const Tensor_t&, const Tensor_t&);
};

} // namespace data

} // namespace set

namespace meta
{

template <template <template <typename, typename...> class T, typename P, typename...> class FunctionData,
          template <typename, typename...> class Tensor,
          typename Precision,
          typename... Args>
struct is_activation_data
{
    using Tensor_t       = Tensor<Precision, Args...>;
    using FunctionData_t = FunctionData<Tensor, Precision, Args...>;

    static constexpr bool value =
        std::is_same<decltype(std::declval<FunctionData_t>().f), Tensor_t& (*)(Tensor_t&, const Tensor_t&)>::value &&
        std::is_same<decltype(std::declval<FunctionData_t>().df), Tensor_t& (*)(Tensor_t&, const Tensor_t&)>::value;
};

template <template <template <typename, typename...> class T, typename P, typename...> class FunctionData,
          template <typename, typename...> class Tensor,
          typename Precision,
          typename... Args>
struct is_loss_data
{
    using Tensor_t       = Tensor<Precision, Args...>;
    using FunctionData_t = FunctionData<Tensor, Precision, Args...>;

    static constexpr bool value =
        std::is_same<decltype(std::declval<FunctionData_t>().f), Precision (*)(const Tensor_t&, const Tensor_t&)>::value &&
        std::is_same<decltype(std::declval<FunctionData_t>().df), Tensor_t& (*)(Tensor_t&, const Tensor_t&, const Tensor_t&)>::value;
};

} // namespace meta

template <template <template <typename, typename...> class T, typename P, typename...> class FunctionData,
          template <typename, typename...> class Tensor,
          typename Precision,
          typename... Args,
          typename std::enable_if<meta::is_activation_data<FunctionData, Tensor, Precision, Args...>::value, int>::type = 0>
FunctionData<Tensor, Precision, Args...> get(const char* activation_function_name)
{
    using namespace set::activation;
    using namespace set::data;

    static std::map<const char*, ActivationData<Tensor, Precision, Args...>> activation_data;

    activation_data["sigmoid"]          = { sigmoid,          sigmoid_derived  };
    activation_data["sigmoid_bce"]      = { sigmoid,          tensor_of_units  };
    activation_data["tanh"]             = { tanh,             tanh_derived     };
    activation_data["relu"]             = { relu,             relu_derived     };
    activation_data["elu"]              = { elu,              elu_derived      };
    activation_data["leaky_relu"]       = { lrelu,            lrelu_derived    };
    activation_data["selu"]             = { selu,             selu_derived     };
    activation_data["gelu"]             = { gelu,             gelu_derived     };
    activation_data["softsign"]         = { softsign,         softsign_derived };
    activation_data["softplus"]         = { softplus,         softplus_derived };
    activation_data["swish"]            = { swish,            swish_derived    };
    activation_data["mod_relu"]         = { mod_relu,         mod_relu_derived };
    activation_data["mod_tanh"]         = { mod_tanh,         mod_tanh_derived };
    activation_data["unstable_softmax"] = { unstable_softmax, tensor_of_units  };
    activation_data["softmax"]          = { softmax,          tensor_of_units  };

    auto it = activation_data.find(activation_function_name);

    if(it != activation_data.end())
        return FunctionData<Tensor, Precision, Args...>(it->second.f, it->second.df);

    return FunctionData<Tensor, Precision, Args...>();
}

template <template <template <typename, typename...> class T, typename P, typename...> class FunctionData,
          template <typename, typename...> class Tensor,
          typename Precision,
          typename... Args,
          typename std::enable_if<meta::is_loss_data<FunctionData, Tensor, Precision, Args...>::value, int>::type = 0>
FunctionData<Tensor, Precision, Args...> get(const char* loss_function_name)
{
    using namespace set::loss;
    using namespace set::data;

    static std::map<const char*, LossData<Tensor, Precision, Args...>> loss_data;

    loss_data["MSE"]  = { mean_squared_error,             mean_squared_error_derived                };
    loss_data["MAE"]  = { mean_absolute_error,            mean_absolute_error_derived               };
    loss_data["MSLE"] = { mean_squared_logarithmic_error, mean_squared_logarithmic_error_derived    };
    loss_data["*CCE"] = { categorical_cross_entropy,      categorical_cross_entropy_derived         }; // deprecated
    loss_data["CCE"]  = { categorical_cross_entropy,      categorical_cross_entropy_derived_softmax };
    loss_data["*BCE"] = { binary_cross_entropy,           binary_cross_entropy_derived              }; // deprecated
    loss_data["BCE"]  = { binary_cross_entropy,           binary_cross_entropy_derived_sigmoid      };
    loss_data["LC"]   = { logcosh,                        logcosh_derived                           };

    auto it = loss_data.find(loss_function_name);

    if(it != loss_data.end())
        return FunctionData<Tensor, Precision, Args...>(it->second.f, it->second.df);

    return FunctionData<Tensor, Precision, Args...>();
}

} // namespace trixy

// clean up
#undef TRIXY_TENSOR_FUNCTION_DECLARATION
#undef TRIXY_VECTOR_FUNCTION_DECLARATION
#undef TRIXY_FUNCTION_GENERIC_HELPER

#endif // NEURO_FUNCTIONAL_HPP
