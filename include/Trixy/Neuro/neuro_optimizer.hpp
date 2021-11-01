#ifndef NEURO_OPTIMIZER_HPP
#define NEURO_OPTIMIZER_HPP

#include <cmath> // sqrt
#include <utility> // declval

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

} // namespace detail

template <template <typename T, typename...> class Tensor, typename Precision, typename... Args>
Tensor<Precision, Args...> momentum(
    const Tensor<Precision, Args...>& g, Tensor<Precision, Args...>& s)
{
    static const Precision beta = 0.9;

    s = s.join(beta) + g.join(1.0 - beta);

    return s;
}

template <template <typename T, typename...> class Tensor, typename Precision, typename... Args>
Tensor<Precision, Args...> rms_prop(
    const Tensor<Precision, Args...>& g, Tensor<Precision, Args...>& v)
{
    static const Precision beta = 0.9;

    v = v.join(beta) + g.multiply(g.join(1.0 - beta));

    return g.multiply(v.apply(detail::invertSqrt));
}

template <template <typename T, typename...> class Tensor, typename Precision, typename... Args>
Tensor<Precision, Args...> ada_grad(
    const Tensor<Precision, Args...>& g, Tensor<Precision, Args...>& s)
{
    s = s + g.multiply(g);

    return g.multiply(s.apply(detail::invertSqrt));
}

template <template <typename T, typename...> class Tensor, typename Precision, typename... Args>
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

} // namespace set

namespace meta
{

template <typename T>
struct size_type_of_
{
    using type = decltype(std::declval<T>().size());
};

template <typename T>
using size_type_of = typename size_type_of_<T>::type;

} // namespace meta

template <template <typename T, typename...> class Tensor, typename Precision, typename... Args>
class Optimizer
{
private:
    using TensorND = Tensor<Precision, Args...>;

    Tensor<Precision, Args...> retain_;
    TensorND (*optimizer_)(const TensorND&, TensorND&);
    Precision alpha_;

public:
    Optimizer(TensorND (*optimizer)(const TensorND&, TensorND&) = nullptr, Precision alpha = 0.0)
    : retain_(), optimizer_(optimizer), alpha_(alpha) {}

    void reset(meta::size_type_of<Tensor<Precision, Args...>> new_size)
    {
        retain_.resize(new_size);
        retain_.fill(0.0);
    }

    Tensor<Precision, Args...> optomize(const Tensor<Precision, Args...>& grad)
    {
        return optimizer_(retain_, grad, alpha_);
    }
};

} // namespace trixy

#endif // NEURO_OPTIMIZER_HPP
