#ifndef NEURO_FUNCTIONAL_HPP
#define NEURO_FUNCTIONAL_HPP

#include <cstddef> // size_t
#include <cmath> // pow, exp, log, fabs, tanh, cosh
#include <type_traits> // enable_if, is_same
#include <vector> // vector

namespace trixy
{

namespace set
{

namespace activation
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
    static const double beta   = 1.673263 * lambda;

    return x > 0.0 ? lambda * x : beta * (std::exp(x) - 1.0);
}
double selu_derived(double x)
{
    static const double lambda = 1.050701;
    static const double beta   = 1.673263 * lambda;

    return x > 0.0 ? lambda : beta * std::exp(x);
}

double sigmoid(double x)
{
    return 1.0 / (std::exp(-x) + 1.0);
}
double sigmoid_derived(double x)
{
    const double f = 1.0 / (std::exp(-x) + 1.0);
    return f * (1.0 - f);
}

double tanh(double x)
{
    return std::tanh(x);
}
double tanh_derived(double x)
{
    const double f = std::tanh(x);
    return 1.0 - f * f;
}

double softsign(double x)
{
    return x / (std::fabs(x) + 1);
}
double softsign_derived(double x)
{
     return 1.0 / std::pow(std::fabs(x) + 1.0, 2);
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
    double f = 1.0 / (std::exp(-x) + 1.0);
    return f + x * f * (1.0 - f);
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> relu(const Vector<double, Args...>& vector)
{
    Vector<double, Args...> new_vector(vector.size());
    for(std::size_t i = 0; i < vector.size(); ++i)
        new_vector(i) = vector(i) > 0.0
                        ? vector(i)
                        : 0.0;

    return new_vector;
}
template <template <typename T, typename...> class Vector, typename... Args>

Vector<double, Args...> relu_derived(const Vector<double, Args...>& vector)
{
    Vector<double, Args...> new_vector(vector.size());
    for(std::size_t i = 0; i < vector.size(); ++i)
        new_vector(i) = vector(i) > 0.0
                        ? 1.0
                        : 0.0;

    return new_vector;
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> elu(const Vector<double, Args...>& vector)
{
    static const double alpha = 0.2;

    Vector<double, Args...> new_vector(vector.size());
    for(std::size_t i = 0; i < vector.size(); ++i)
        new_vector(i) = vector(i) > 0.0
                        ? vector(i)
                        : alpha * (std::exp(vector(i)) - 1.0);

    return new_vector;
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> elu_derived(const Vector<double, Args...>& vector)
{
    static const double alpha = 0.2;

    Vector<double, Args...> new_vector(vector.size());
    for(std::size_t i = 0; i < vector.size(); ++i)
        new_vector(i) = vector(i) > 0.0
                        ? 1.0
                        : alpha * std::exp(vector(i));

    return new_vector;
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> lrelu(const Vector<double, Args...>& vector)
{
    static const double alpha = 0.01;

    Vector<double, Args...> new_vector(vector.size());
    for(std::size_t i = 0; i < vector.size(); ++i)
        new_vector(i) = vector(i) > 0.0
                        ? vector(i)
                        : alpha * vector(i);

    return new_vector;
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> lrelu_derived(const Vector<double, Args...>& vector)
{
    static const double alpha = 0.01;

    Vector<double, Args...> new_vector(vector.size());
    for(std::size_t i = 0; i < vector.size(); ++i)
        new_vector(i) = vector(i) > 0.0
                        ? 1.0
                        : alpha;

    return new_vector;
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> selu(const Vector<double, Args...>& vector)
{
    static const double lambda = 1.050701;
    static const double beta   = 1.673263 * lambda;

    Vector<double, Args...> new_vector(vector.size());
    for(std::size_t i = 0; i < vector.size(); ++i)
        new_vector(i) = vector(i) > 0.0
                        ? lambda * vector(i)
                        : beta * (std::exp(vector(i)) - 1.0);

    return new_vector;
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> selu_derived(const Vector<double, Args...>& vector)
{
    static const double lambda = 1.050701;
    static const double beta   = 1.673263 * lambda;

    Vector<double, Args...> new_vector(vector.size());
    for(std::size_t i = 0; i < vector.size(); ++i)
        new_vector(i) = vector(i) > 0.0
                        ? lambda
                        : beta * std::exp(vector(i));

    return new_vector;
}
/*
template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> gelu(const Vector<double, Args...>& vector)
{
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> gelu_derived(const Vector<double, Args...>& vector)
{
}
*/
template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> sigmoid(const Vector<double, Args...>& vector)
{
    Vector<double, Args...> new_vector(vector.size());
    for(std::size_t i = 0; i < vector.size(); ++i)
        new_vector(i) = 1.0 / (std::exp(-vector(i)) + 1.0);

    return new_vector;
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> sigmoid_derived(const Vector<double, Args...>& vector)
{
    Vector<double, Args...> new_vector(vector.size());
    double sigma;

    for(std::size_t i = 0; i < vector.size(); ++i)
    {
        sigma = 1.0 / (std::exp(-vector(i)) + 1.0);
        new_vector(i) = sigma * (1.0 - sigma);
    }
    return new_vector;
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> sigmoid_derived_bce(const Vector<double, Args...>& vector)
{
    Vector<double, Args...> new_vector(vector.size());
    return new_vector.fill(1.0);
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> tanh(const Vector<double, Args...>& vector)
{
    Vector<double, Args...> new_vector(vector.size());
    for(std::size_t i = 0; i < vector.size(); ++i)
        new_vector(i) = std::tanh(vector(i));

    return new_vector;
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> tanh_derived(const Vector<double, Args...>& vector)
{
    Vector<double, Args...> new_vector(vector.size());
    for(std::size_t i = 0; i < vector.size(); ++i)
        new_vector(i) = 1.0 - std::pow(std::tanh(vector(i)), 2);

    return new_vector;
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> softsign(const Vector<double, Args...>& vector)
{
    Vector<double, Args...> new_vector(vector.size());
    for(std::size_t i = 0; i < vector.size(); ++i)
        new_vector(i) = vector(i) / (std::fabs(vector(i)) + 1.0);

    return new_vector;
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> softsign_derived(const Vector<double, Args...>& vector)
{
    Vector<double, Args...> new_vector(vector.size());
    for(std::size_t i = 0; i < vector.size(); ++i)
        new_vector(i) = 1.0 / std::pow(std::fabs(vector(i)) + 1.0, 2);

    return new_vector;
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> softplus(const Vector<double, Args...>& vector)
{
    Vector<double, Args...> new_vector(vector.size());
    for(std::size_t i = 0; i < vector.size(); ++i)
        new_vector(i) = std::log(std::exp(vector(i)) + 1.0);

    return new_vector;
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> softplus_derived(const Vector<double, Args...>& vector)
{
    Vector<double, Args...> new_vector(vector.size());
    for(std::size_t i = 0; i < vector.size(); ++i)
        new_vector(i) = 1.0 / (std::exp(-vector(i)) + 1.0);

    return new_vector;
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> swish(const Vector<double, Args...>& vector)
{
    Vector<double, Args...> new_vector(vector.size());
    for(std::size_t i = 0; i < vector.size(); ++i)
        new_vector(i) = vector(i) / (std::exp(-vector(i)) + 1.0);

    return new_vector;
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> swish_derived(const Vector<double, Args...>& vector)
{
    Vector<double, Args...> new_vector(vector.size());
    double sigma;

    for(std::size_t i = 0; i < vector.size(); ++i)
    {
        sigma = 1.0 / (std::exp(-vector(i)) + 1.0);
        new_vector(i) = sigma + vector(i) * sigma * (1.0 - sigma);
    }
    return new_vector;
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> softmax(const Vector<double, Args...>& vector)
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
Vector<double, Args...> stable_softmax(const Vector<double, Args...>& vector)
{
    double max = vector(0);
    for(std::size_t i = 1; i < vector.size(); ++i)
        if(max < vector(i)) max = vector(i);

    Vector<double, Args...> new_vector(vector.size());
    for(std::size_t i = 0; i < vector.size(); ++i)
        new_vector(i) = std::exp(vector(i) - max);

    double denominator = 0.0;
    for(std::size_t i = 0; i < vector.size(); ++i)
        denominator += new_vector(i);

    for(std::size_t i = 0; i < vector.size(); ++i)
        new_vector(i) /= denominator;

    return new_vector;
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> softmax_derived_cce(const Vector<double, Args...>& vector)
{
    Vector<double, Args...> new_vector(vector.size());
    return new_vector.fill(1.0);
}

} // namespace activation

namespace loss
{

template <template <typename T, typename...> class Vector, typename... Args>
double categorical_cross_entropy(
    const Vector<double, Args...>& y_true, const Vector<double, Args...>& y_pred)
{
    static const double epsilon = 1e-9;
    double result = 0.0;

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
    double result = 0.0;
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
    double result = 0.0;
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
    double result = 0.0;
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
    static const double alpha = 1.0 + epsilon;

    double result = 0.0;
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
    static const double alpha = epsilon - 1.0;

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
    double result = 0.0;
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

template <template <typename T, typename...> class Vector, typename... Args>
struct ActivationData
{
    const char* name;
    Vector<double, Args...> (*f)(const Vector<double, Args...>&);
    Vector<double, Args...> (*df)(const Vector<double, Args...>&);
};

template <template <typename T, typename...> class Vector, typename... Args>
struct LossData
{
    const char* name;
    double (*f)(
        const Vector<double, Args...>&, const Vector<double, Args...>&);
    Vector<double, Args...> (*df)(
        const Vector<double, Args...>&, const Vector<double, Args...>&);
};

} // namespace data

} // namespace set

template <template <template <typename T, typename...> class V, typename...>
                    class FunctionData,
          template <typename U, typename...> class Vector,
          typename... Args,
          typename std::enable_if<
                   std::is_same<decltype(std::declval< FunctionData<Vector, Args...> >().f),
                                Vector<double, Args...> (*)(const Vector<double, Args...>&)>::value &&
                   std::is_same<decltype(std::declval< FunctionData<Vector, Args...> >().df),
                                Vector<double, Args...> (*)(const Vector<double, Args...>&)>::value,
                   int>::type = 0>
FunctionData<Vector, Args...> get(const char* activation_function_name)
{
    using namespace set::activation;
    using namespace set::data;

    static std::vector<ActivationData<Vector, Args...>> activation_data =
    {
        { "sigmoid",        sigmoid,        sigmoid_derived     },
        { "sigmoid_bce",    sigmoid,        sigmoid_derived_bce },
        { "tanh",           tanh,           tanh_derived        },
        { "relu",           relu,           relu_derived        },
        { "elu",            elu,            elu_derived         },
        { "leaky_relu",     lrelu,          lrelu_derived       },
        { "selu",           selu,           selu_derived        },
      //{ "gelu",           gelu,           gelu_derived        },
        { "softsign",       softsign,       softsign_derived    },
        { "softplus",       softplus,       softplus_derived    },
        { "swish",          swish,          swish_derived       },
        { "softmax",        softmax,        softmax_derived_cce },
        { "stable_softmax", stable_softmax, softmax_derived_cce }
    };

    for(std::size_t i = 0; i < activation_data.size(); ++i)
        if(activation_function_name == activation_data[i].name)
            return FunctionData(activation_data[i].f, activation_data[i].df);

    return FunctionData<Vector, Args...>();
}

template <template <template <typename T, typename...> class V, typename...>
                    class FunctionData,
          template <typename U, typename...> class Vector,
          typename... Args,
          typename std::enable_if<
                   std::is_same<decltype(std::declval< FunctionData<Vector, Args...> >().f),
                                double (*)(const Vector<double, Args...>&, const Vector<double, Args...>&)>::value &&
                   std::is_same<decltype(std::declval< FunctionData<Vector, Args...> >().df),
                                Vector<double, Args...> (*)(const Vector<double, Args...>&, const Vector<double, Args...>&)>::value,
                   int>::type = 0>
FunctionData<Vector, Args...> get(const char* loss_function_name)
{
    using namespace set::loss;
    using namespace set::data;

    static std::vector<LossData<Vector, Args...>> loss_data =
    {
        { "MSE",  mean_squared_error,             mean_squared_error_derived                },
        { "MAE",  mean_absolute_error,            mean_absolute_error_derived               },
        { "MSLE", mean_squared_logarithmic_error, mean_squared_logarithmic_error_derived    },
        { "*CCE", categorical_cross_entropy,      categorical_cross_entropy_derived         },
        { "CCE",  categorical_cross_entropy,      categorical_cross_entropy_derived_softmax },
        { "*BCE", binary_cross_entropy,           binary_cross_entropy_derived              },
        { "BCE",  binary_cross_entropy,           binary_cross_entropy_derived_sigmoid      },
        { "LC",   logcosh,                        logcosh_derived                           }
    };

    for(std::size_t i = 0; i < loss_data.size(); ++i)
        if(loss_function_name == loss_data[i].name)
            return FunctionData(loss_data[i].f, loss_data[i].df);

    return FunctionData<Vector, Args...>();
}

} // namespace trixy

#endif // NEURO_FUNCTIONAL_HPP
