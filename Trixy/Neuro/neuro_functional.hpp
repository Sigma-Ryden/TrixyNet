#ifndef NEURO_FUNCTIONAL_HPP
#define NEURO_FUNCTIONAL_HPP

#include <cstddef> // size_t
#include <cmath> // pow, exp, log, fabs, tanh, cosh
#include <type_traits> // enable_if, is_same
#include <map> // map
#include <utility> // declval

namespace trixy
{

namespace set
{

namespace activation
{

namespace detail
{

double relu(double x)
{
    return x > 0.0 ? x : 0.0;
}
double relu_derived(double x)
{
    return x > 0.0 ? 1.0 : 0.0;
}

double elu(double x)
{
    static const double alpha = 0.2;
    return x > 0.0 ? x : alpha * (std::exp(x) - 1.0);
}
double elu_derived(double x)
{
    static const double alpha = 0.2;
    return x > 0.0 ? 1.0 : alpha * std::exp(x);
}

double lrelu(double x)
{
    static const double alpha = 0.01;
    return x > 0.0 ? x : alpha * x;
}
double lrelu_derived(double x)
{
    static const double alpha = 0.01;
    return x > 0.0 ? 1.0 : alpha;
}

double selu(double x)
{
    static const double lambda = 1.050701;
    static const double beta   = 1.758099;

    return x > 0.0 ? lambda * x : beta * (std::exp(x) - 1.0);
}
double selu_derived(double x)
{
    static const double lambda = 1.050701;
    static const double beta   = 1.758099;

    return x > 0.0 ? lambda : beta * std::exp(x);
}

double gelu(double x)
{
    static const double a = 0.797885;
    static const double b = 0.0356774;

    return 0.5 * x * (std::tanh(x * a + x * x * x * b) + 1.0);
}
double gelu_derived(double x)
{
    static const double a = 0.797885;
    static const double b = 0.0356774;
    static const double c = 0.0535161;
    static const double d = 0.398942;

    static double x3;
    static double y;
    static double sch;

    x3 = x * x * x;
    y = a * x3 + b * x;
    sch = 1.0 / std::cosh(y);

    return 0.5 * std::tanh(y) + (c * x3 + d * x) * sch * sch + 0.5;
}

double sigmoid(double x)
{
    return 1.0 / (std::exp(-x) + 1.0);
}
double sigmoid_derived(double x)
{
    return 0.5 / (std::cosh(x) + 1.0);
}

double tanh(double x)
{
    return std::tanh(x);
}
double tanh_derived(double x)
{
    static double sech;
    sech = 1.0 / std::cosh(x);

    return sech * sech;
}

double softsign(double x)
{
    return x / (std::fabs(x) + 1.0);
}
double softsign_derived(double x)
{
    static double f;
    f = 1.0 / (std::fabs(x) + 1.0);

    return f * f;
}

double softplus(double x)
{
    return std::log(std::exp(x) + 1.0);
}
double softplus_derived(double x)
{
    return 1.0 / (std::exp(-x) + 1.0);
}

double swish(double x)
{
    return x / (std::exp(-x) + 1.0);
}
double swish_derived(double x)
{
    static double a;
    static double b;

    a = std::exp(-x);
    b = a + 1;

    return (a * x + b) / (b * b);
}

} // namespace detail

template <template <typename T, typename...> class Tensor, typename... Args>
Tensor<double, Args...> relu(const Tensor<double, Args...>& tensor)
{
    return tensor.apply(detail::relu);
}
template <template <typename T, typename...> class Tensor, typename... Args>
Tensor<double, Args...> relu_derived(const Tensor<double, Args...>& tensor)
{
    return tensor.apply(detail::relu_derived);
}

template <template <typename T, typename...> class Tensor, typename... Args>
Tensor<double, Args...> elu(const Tensor<double, Args...>& tensor)
{
    return tensor.apply(detail::elu);
}
template <template <typename T, typename...> class Tensor, typename... Args>
Tensor<double, Args...> elu_derived(const Tensor<double, Args...>& tensor)
{
    return tensor.apply(detail::elu_derived);
}

template <template <typename T, typename...> class Tensor, typename... Args>
Tensor<double, Args...> lrelu(const Tensor<double, Args...>& tensor)
{
    return tensor.apply(detail::lrelu);
}
template <template <typename T, typename...> class Tensor, typename... Args>
Tensor<double, Args...> lrelu_derived(const Tensor<double, Args...>& tensor)
{
    return tensor.apply(detail::lrelu_derived);
}

template <template <typename T, typename...> class Tensor, typename... Args>
Tensor<double, Args...> selu(const Tensor<double, Args...>& tensor)
{
    return tensor.apply(detail::selu);
}
template <template <typename T, typename...> class Tensor, typename... Args>
Tensor<double, Args...> selu_derived(const Tensor<double, Args...>& tensor)
{
    return tensor.apply(detail::selu_derived);
}

template <template <typename T, typename...> class Tensor, typename... Args>
Tensor<double, Args...> gelu(const Tensor<double, Args...>& tensor)
{
    return tensor.apply(detail::gelu);
}
template <template <typename T, typename...> class Tensor, typename... Args>
Tensor<double, Args...> gelu_derived(const Tensor<double, Args...>& tensor)
{
    return tensor.apply(detail::gelu_derived);
}

template <template <typename T, typename...> class Tensor, typename... Args>
Tensor<double, Args...> sigmoid(const Tensor<double, Args...>& tensor)
{
    return tensor.apply(detail::sigmoid);
}
template <template <typename T, typename...> class Tensor, typename... Args>
Tensor<double, Args...> sigmoid_derived(const Tensor<double, Args...>& tensor)
{
    return tensor.apply(detail::sigmoid_derived);
}

template <template <typename T, typename...> class Tensor, typename... Args>
Tensor<double, Args...> tanh(const Tensor<double, Args...>& tensor)
{
    return tensor.apply(detail::tanh);
}
template <template <typename T, typename...> class Tensor, typename... Args>
Tensor<double, Args...> tanh_derived(const Tensor<double, Args...>& tensor)
{
    return tensor.apply(detail::tanh_derived);
}

template <template <typename T, typename...> class Tensor, typename... Args>
Tensor<double, Args...> softsign(const Tensor<double, Args...>& tensor)
{
    return tensor.apply(detail::softsign);
}
template <template <typename T, typename...> class Tensor, typename... Args>
Tensor<double, Args...> softsign_derived(const Tensor<double, Args...>& tensor)
{
    return tensor.apply(detail::softsign_derived);
}

template <template <typename T, typename...> class Tensor, typename... Args>
Tensor<double, Args...> softplus(const Tensor<double, Args...>& tensor)
{
    return tensor.apply(detail::softplus);
}
template <template <typename T, typename...> class Tensor, typename... Args>
Tensor<double, Args...> softplus_derived(const Tensor<double, Args...>& tensor)
{
    return tensor.apply(detail::softplus_derived);
}

template <template <typename T, typename...> class Tensor, typename... Args>
Tensor<double, Args...> swish(const Tensor<double, Args...>& tensor)
{
    return tensor.apply(detail::swish);
}
template <template <typename T, typename...> class Tensor, typename... Args>
Tensor<double, Args...> swish_derived(const Tensor<double, Args...>& tensor)
{
    return tensor.apply(detail::swish_derived);
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> unstable_softmax(const Vector<double, Args...>& vector)
{
    Vector<double, Args...> new_vector(vector.size());
    for(std::size_t i = 0; i < vector.size(); ++i)
        new_vector(i) = std::exp(vector(i));

    double denominator = 0.0;
    for(std::size_t i = 0; i < vector.size(); ++i)
        denominator += new_vector(i);

    for(std::size_t i = 0; i < vector.size(); ++i)
        new_vector(i) /= denominator;

    return new_vector;
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> softmax(const Vector<double, Args...>& vector)
{
    static double max;
    static double denominator;

    max = vector(0);
    for(std::size_t i = 1; i < vector.size(); ++i)
        if(max < vector(i)) max = vector(i);

    Vector<double, Args...> new_vector(vector.size());
    for(std::size_t i = 0; i < vector.size(); ++i)
        new_vector(i) = std::exp(vector(i) - max);

    denominator = 0.0;
    for(std::size_t i = 0; i < vector.size(); ++i)
        denominator += new_vector(i);

    for(std::size_t i = 0; i < vector.size(); ++i)
        new_vector(i) /= denominator;

    return new_vector;
}

template <template <typename T, typename...> class Tensor, typename... Args>
Tensor<double, Args...> tensor_of_units(const Tensor<double, Args...>& tensor)
{
    Tensor<double, Args...> new_tensor(tensor.size());
    new_tensor.fill(1.0);

    return new_tensor;
}

} // namespace activation

namespace loss
{

template <template <typename T, typename...> class Vector, typename... Args>
double categorical_cross_entropy(
    const Vector<double, Args...>& y_true, const Vector<double, Args...>& y_pred)
{
    static const double epsilon = 1e-9;
    static double result;

    result = 0.0;
    for(std::size_t i = 0; i < y_true.size(); ++i)
        result -= y_true(i) * std::log(y_pred(i) + epsilon);

    return result;
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> categorical_cross_entropy_derived(
    const Vector<double, Args...>& y_true, const Vector<double, Args...>& y_pred)
{
    static const double epsilon = 1e-9;

    Vector<double, Args...> loss_vector(y_true.size());
    for(std::size_t i = 0; i < y_true.size(); ++i)
        loss_vector(i) = y_true(i) / (y_pred(i) + epsilon);

    return loss_vector;
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> categorical_cross_entropy_derived_softmax(
    const Vector<double, Args...>& y_true, const Vector<double, Args...>& y_pred)
{
    Vector<double, Args...> loss_vector(y_true.size());
    for(std::size_t i = 0; i < y_true.size(); ++i)
        loss_vector(i) = y_pred(i) - y_true(i);

    return loss_vector;
}

template <template <typename T, typename...> class Vector, typename... Args>
double mean_squared_error(
    const Vector<double, Args...>& y_true, const Vector<double, Args...>& y_pred)
{
    static double result;

    result = 0.0;
    for(std::size_t i = 0; i < y_true.size(); ++i)
        result += std::pow(y_true(i) - y_pred(i), 2);

    return result / 2.0;
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> mean_squared_error_derived(
    const Vector<double, Args...>& y_true, const Vector<double, Args...>& y_pred)
{
    Vector<double, Args...> loss_vector(y_true.size());
    for(std::size_t i = 0; i < y_true.size(); ++i)
        loss_vector(i) = y_pred(i) - y_true(i);

    return loss_vector;
}

template <template <typename T, typename...> class Vector, typename... Args>
double mean_absolute_error(
    const Vector<double, Args...>& y_true, const Vector<double, Args...>& y_pred)
{
    static double result;

    result = 0.0;
    for(std::size_t i = 0; i < y_true.size(); ++i)
        result += std::fabs(y_true(i) - y_pred(i));

    return result;
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> mean_absolute_error_derived(
    const Vector<double, Args...>& y_true, const Vector<double, Args...>& y_pred)
{
    Vector<double, Args...> loss_vector(y_true.size());
    for(std::size_t i = 0; i < y_true.size(); ++i)
        loss_vector(i) = y_true(i) > y_pred(i) ? -1.0 : 1.0;

    return loss_vector;
}

template <template <typename T, typename...> class Vector, typename... Args>
double mean_squared_logarithmic_error(
    const Vector<double, Args...>& y_true, const Vector<double, Args...>& y_pred)
{
    static double result;

    result = 0.0;
    for(std::size_t i = 0; i < y_true.size(); ++i)
        result += std::pow(std::log( (y_pred(i) + 1.0) / (y_true(i) + 1.0) ), 2);

    return result / 2.0;
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> mean_squared_logarithmic_error_derived(
    const Vector<double, Args...>& y_true, const Vector<double, Args...>& y_pred)
{
    Vector<double, Args...> loss_vector(y_true.size());

    for(std::size_t i = 0; i < y_true.size(); ++i)
    {
        loss_vector(i) = y_pred(i) + 1.0;
        loss_vector(i) /= std::log(loss_vector(i) / (y_true(i) + 1.0));
    }
    return loss_vector;
}

template <template <typename T, typename...> class Vector, typename... Args>
double binary_cross_entropy(
    const Vector<double, Args...>& y_true, const Vector<double, Args...>& y_pred)
{
    static const double epsilon = 1e-9;
    static const double alpha   = epsilon + 1.0;
    static double result;

    result = 0.0;
    for(std::size_t i = 0; i < y_true.size(); ++i)
        result -= y_true(i) * std::log(y_pred(i) + epsilon)
                  + (1.0 - y_true(i)) * std::log(alpha - y_pred(i));

    return result;
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> binary_cross_entropy_derived(
    const Vector<double, Args...>& y_true, const Vector<double, Args...>& y_pred)
{
    static const double epsilon = 1e-9;
    static const double alpha   = epsilon - 1.0;

    Vector<double, Args...> loss_vector(y_true.size());

    for(std::size_t i = 0; i < y_true.size(); ++i)
        loss_vector(i) =
            (y_true(i) - 1.0) / (y_pred(i) + alpha) - y_true(i) / (y_pred(i) + epsilon);

    return loss_vector;
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> binary_cross_entropy_derived_sigmoid(
    const Vector<double, Args...>& y_true, const Vector<double, Args...>& y_pred)
{
    Vector<double, Args...> loss_vector(y_true.size());

    for(std::size_t i = 0; i < y_true.size(); ++i)
        loss_vector(i) = y_true(i) * (y_pred(i) - 1.0) + (1.0 - y_true(i)) * y_pred(i);

    return loss_vector;
}

template <template <typename T, typename...> class Vector, typename... Args>
double logcosh(
    const Vector<double, Args...>& y_true, const Vector<double, Args...>& y_pred)
{
    static double result;

    result = 0.0;
    for(std::size_t i = 0; i < y_true.size(); ++i)
        result += std::log( std::cosh(y_pred(i) - y_true(i)) );

    return result;
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> logcosh_derived(
    const Vector<double, Args...>& y_true, const Vector<double, Args...>& y_pred)
{
    Vector<double, Args...> loss_vector(y_true.size());

    for(std::size_t i = 0; i < y_true.size(); ++i)
        loss_vector(i) = std::tanh(y_pred(i) - y_true(i));

    return loss_vector;
}

} // namespace loss

namespace data
{

template <template <typename T, typename...> class Tensor, typename... Args>
struct ActivationData
{
    Tensor<double, Args...> (*f)(const Tensor<double, Args...>&);
    Tensor<double, Args...> (*df)(const Tensor<double, Args...>&);
};

template <template <typename T, typename...> class Tensor, typename... Args>
struct LossData
{
    double (*f)(
        const Tensor<double, Args...>&, const Tensor<double, Args...>&);
    Tensor<double, Args...> (*df)(
        const Tensor<double, Args...>&, const Tensor<double, Args...>&);
};

} // namespace data

} // namespace set

template <template <template <typename T, typename...> class V, typename...>
                    class FunctionData,
          template <typename U, typename...> class Tensor,
          typename... Args,
          typename std::enable_if<
                   std::is_same<decltype(std::declval<FunctionData<Tensor, Args...>>().f),
                                Tensor<double, Args...> (*)(const Tensor<double, Args...>&)>::value &&
                   std::is_same<decltype(std::declval<FunctionData<Tensor, Args...>>().df),
                                Tensor<double, Args...> (*)(const Tensor<double, Args...>&)>::value,
                   int>::type = 0>
FunctionData<Tensor, Args...> get(const char* activation_function_name)
{
    using namespace set::activation;
    using namespace set::data;

    static std::map<const char*, ActivationData<Tensor, Args...>> activation_data;

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
    activation_data["unstable_softmax"] = { unstable_softmax, tensor_of_units  };
    activation_data["softmax"]          = { softmax,          tensor_of_units  };

    auto i = activation_data.find(activation_function_name);

    if(i != activation_data.end())
        return FunctionData<Tensor, Args...>(i->second.f, i->second.df);

    return FunctionData<Tensor, Args...>();
}

template <template <template <typename T, typename...> class V, typename...>
                    class FunctionData,
          template <typename U, typename...> class Tensor,
          typename... Args,
          typename std::enable_if<
                   std::is_same<decltype(std::declval<FunctionData<Tensor, Args...>>().f),
                                double (*)(const Tensor<double, Args...>&, const Tensor<double, Args...>&)>::value &&
                   std::is_same<decltype(std::declval<FunctionData<Tensor, Args...>>().df),
                                Tensor<double, Args...> (*)(const Tensor<double, Args...>&, const Tensor<double, Args...>&)>::value,
                   int>::type = 0>
FunctionData<Tensor, Args...> get(const char* loss_function_name)
{
    using namespace set::loss;
    using namespace set::data;

    static std::map<const char*, LossData<Tensor, Args...>> loss_data;

    loss_data["MSE"]  = { mean_squared_error,             mean_squared_error_derived                };
    loss_data["MAE"]  = { mean_absolute_error,            mean_absolute_error_derived               };
    loss_data["MSLE"] = { mean_squared_logarithmic_error, mean_squared_logarithmic_error_derived    };
    loss_data["*CCE"] = { categorical_cross_entropy,      categorical_cross_entropy_derived         };
    loss_data["CCE"]  = { categorical_cross_entropy,      categorical_cross_entropy_derived_softmax };
    loss_data["*BCE"] = { binary_cross_entropy,           binary_cross_entropy_derived              };
    loss_data["BCE"]  = { binary_cross_entropy,           binary_cross_entropy_derived_sigmoid      };
    loss_data["LC"]   = { logcosh,                        logcosh_derived                           };

    auto i = loss_data.find(loss_function_name);

    if(i != loss_data.end())
        return FunctionData<Tensor, Args...>(i->second.f, i->second.df);

    return FunctionData<Tensor, Args...>();
}

} // namespace trixy

#endif // NEURO_FUNCTIONAL_HPP
