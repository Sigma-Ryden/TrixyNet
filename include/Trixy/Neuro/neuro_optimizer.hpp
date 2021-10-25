#ifndef NEURO_OPTIMIZER_HPP
#define NEURO_OPTIMIZER_HPP

#include <cmath> // sqrt

namespace trixy
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

} // namespace detail

template <template <typename, typename...> class Tensor, typename Precision, typename... Args>
Tensor<Precision, Args...> momentum(
    const Tensor<Precision, Args...>& g, Tensor<Precision, Args...>& m)
{
    static const Precision beta = 0.9;

    m = m.join(beta) + g.join(1.0 - beta);

    return m;
}

template <template <typename, typename...> class Tensor, typename Precision, typename... Args>
Tensor<Precision, Args...> rms_prop(
    const Tensor<Precision, Args...>& g, Tensor<Precision, Args...>& v)
{
    static const Precision beta = 0.9;

    v = v.join(beta) + g.multiply(g.join(1.0 - beta));

    return g.multiply(v.apply(detail::invertSqrt));
}

template <template <typename, typename...> class Tensor, typename Precision, typename... Args>
Tensor<Precision, Args...> ada_grad(
    const Tensor<Precision, Args...>& g, Tensor<Precision, Args...>& v)
{
    v = v + g.multiply(g);

    return g.multiply(v.apply(detail::invertSqrt));
}

template <template <typename, typename...> class Tensor, typename Precision, typename... Args>
Tensor<Precision, Args...> adam(
    const Tensor<Precision, Args...>& g,
    Tensor<Precision, Args...>& m,
    Tensor<Precision, Args...>& v)
{
    static const Precision beta_1 = 0.9;
    static const Precision beta_2 = 0.999;

    m = m.join(beta_1) + g.join(1 - beta_1);
    v = v.join(beta_2) + g.multiply(g.join(1 - beta_2));

    return g.multiply(m.multiply(v.apply(detail::invertSqrt)));
}

} // namespace optimization

} // namespace trixy

#endif // NEURO_OPTIMIZER_HPP
