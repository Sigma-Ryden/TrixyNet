#ifndef NEURO_OPTIMIZER_HPP
#define NEURO_OPTIMIZER_HPP

#include <cmath> // pow

namespace trixy
{

namespace optimization
{

template <template <typename T, typename...> class Array, typename... Args>
Array<double, Args...> momentum(
    const Array<double, Args...>& grad, Array<double, Args...>& m, double beta = 0.9)
{
    m = m.join(beta) + grad.join(1 - beta);

    return m;
}

template <template <typename T, typename...> class Array, typename... Args>
Array<double, Args...> rms_prop(
    const Array<double, Args...>& grad, Array<double, Args...>& v, double beta = 0.9)
{
    v = v.join(beta) + grad.multiply(grad.join(1 - beta));

    return grad.multiply(
        v.apply([] (double x) { return std::pow(1e-9 + x, -0.5); })
    );
}

template <template <typename T, typename...> class Array, typename... Args>
Array<double, Args...> ada_grad(
    const Array<double, Args...>& grad, Array<double, Args...>& v)
{
    v = v + grad.multiply(grad);

    return grad.multiply(
        v.apply([] (double x) { return std::pow(1e-9 + x, -0.5); })
    );
}

template <template <typename T, typename...> class Array, typename... Args>
Array<double, Args...> adam(
    const Array<double, Args...>& grad,
    Array<double, Args...>& m, Array<double, Args...>& v,
    double beta_1 = 0.9, double beta_2 = 0.999)
{
    m = m.join(beta_1) + grad.join(1 - beta_1);
    v = v.join(beta_2) + grad.multiply(grad.join(1 - beta_2));

    return grad.multiply(
        m.multiply( v.apply([] (double x) { return std::pow(1e-9 + x, -0.5); }) )
    );
}

} // namespace optimization

} // namespace trixy

#endif // NEURO_OPTIMIZER_HPP
