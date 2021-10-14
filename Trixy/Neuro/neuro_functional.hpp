#ifndef NEURO_FUNCTIONAL_HPP
#define NEURO_FUNCTIONAL_HPP

#include <cstddef> // size_t
#include <cmath> // pow, exp, log, fabs, tanh
#include <type_traits> // enable_if, is_same

namespace trixy
{

namespace set
{

namespace activation
{

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
                        : alpha;

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
    static const double lambda = 1.0507009873554804934193349852946;
    static const double beta   = 1.6732632423543772848170429916717 * lambda;

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
    static const double lambda = 1.0507009873554804934193349852946;
    static const double beta   = 1.6732632423543772848170429916717 * lambda;

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
        new_vector(i) = 1.0 - std::pow(std::tanh(vector(i)), 2.0);

    return new_vector;
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> softsign(const Vector<double, Args...>& vector)
{
    Vector<double, Args...> new_vector(vector.size());
    for(std::size_t i = 0; i < vector.size(); ++i)
        new_vector(i) = vector(i) / (std::fabs(vector(i)) + 1);

    return new_vector;
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> softsign_derived(const Vector<double, Args...>& vector)
{
    Vector<double, Args...> new_vector(vector.size());
    for(std::size_t i = 0; i < vector.size(); ++i)
        new_vector(i) = 1.0 / std::pow(std::fabs(vector(i)) + 1, 2);

    return new_vector;
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> softplus(const Vector<double, Args...>& vector)
{
    Vector<double, Args...> new_vector(vector.size());
    for(std::size_t i = 0; i < vector.size(); ++i)
        new_vector(i) = std::log(std::exp(vector(i)) + 1);

    return new_vector;
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> softplus_derived(const Vector<double, Args...>& vector)
{
    Vector<double, Args...> new_vector(vector.size());
    for(std::size_t i = 0; i < vector.size(); ++i)
        new_vector(i) = 1.0 / (std::exp(-vector(i)) + 1);

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
Vector<double, Args...> softmax_derived(const Vector<double, Args...>& vector)
{
    Vector<double, Args...> new_vector(vector.size());
    new_vector.fill(1.0);

    return new_vector;
}

} // namespace activation

namespace loss
{

template <template <typename T, typename...> class Vector, typename... Args>
double cross_entropy(
    const Vector<double, Args...>& y_true, const Vector<double, Args...>& y_pred)
{
    static const double epsilon = 1e-9;
    double result = 0.0;

    for(std::size_t i = 0; i < y_true.size(); ++i)
        result -= y_true(i) * std::log(y_pred(i) + epsilon);

    return result;
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> cross_entropy_derived(
    const Vector<double, Args...>& y_true, const Vector<double, Args...>& y_pred)
{
    Vector<double, Args...> loss_vector(y_true.size());
    for(std::size_t i = 0; i < y_true.size(); ++i)
        loss_vector(i) = y_pred(i) - y_true(i);

    return loss_vector;
}

template <template <typename T, typename...> class Vector, typename... Args>
double mean_squared_error(
    const Vector<double, Args...>& y_true, const Vector<double ,Args...>& y_pred)
{
    double result = 0.0;
    for(std::size_t i = 0; i < y_true.size(); ++i)
        result += std::pow(y_true(i) - y_pred(i), 2.0);

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
    const Vector<double, Args...>& y_true, const Vector<double ,Args...>& y_pred)
{
    double result = 0.0;
    for(std::size_t i = 0; i < y_true.size(); ++i)
        result += std::fabs(y_true(i) - y_pred(i));

    return result;
}

template <template <typename T, typename...> class Vector, typename... Args>
Vector<double, Args...> mean_absolute_error_derived(
    const Vector<double, Args...>& y_true, const Vector<double ,Args...>& y_pred)
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
        result += std::pow(std::log( (y_pred(i) + 1.0) / (y_true(i) + 1.0) ), 2.0);

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
/*
template <template <typename T, typename...> class Vector, typename... Args>
double binary_cross_entropy(
    const Vector<double, Args...>& y_true, const Vector<double ,Args...>& y_pred)
{
    double result = 0.0;
    for(std::size_t i = 0; i < y_true.size(); ++i)
        result -= y_true(i) * std::log(y_pred(i)) + (1 - y_true(i)) * log(1 - y_pred(i));

    return result;
}

*/
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

    static constexpr std::size_t activation_data_list_size = 11;
    static ActivationData<Vector, Args...> activation_data[activation_data_list_size] =
    {
        { "sigmoid",        sigmoid,        sigmoid_derived  },
        { "tanh",           tanh,           tanh_derived     },
        { "relu",           relu,           relu_derived     },
        { "elu",            elu,            elu_derived      },
        { "leaky_relu",     lrelu,          lrelu_derived    },
        { "selu",           selu,           selu_derived     },
        //{ "gelu",           gelu,           gelu_derived     },
        { "softsign",       softsign,       softsign_derived },
        { "softplus",       softplus,       softplus_derived },
        { "swish",          swish,          swish_derived    },
        { "softmax",        softmax,        softmax_derived  },
        { "stable_softmax", stable_softmax, softmax_derived  }
    };

    for(std::size_t i = 0; i < activation_data_list_size; ++i)
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

    static constexpr std::size_t loss_data_list_size = 4;
    static LossData<Vector, Args...> loss_data[loss_data_list_size] =
    {
        { "MSE",  mean_squared_error,             mean_squared_error_derived             },
        { "MAE",  mean_absolute_error,            mean_absolute_error_derived            },
        { "MSLE", mean_squared_logarithmic_error, mean_squared_logarithmic_error_derived },
        { "CE",   cross_entropy,                  cross_entropy_derived                  }
    };

    for(std::size_t i = 0; i < loss_data_list_size; ++i)
        if(loss_function_name == loss_data[i].name)
            return FunctionData(loss_data[i].f, loss_data[i].df);

    return FunctionData<Vector, Args...>();
}

} // namespace trixy

#endif // NEURO_FUNCTIONAL_HPP
