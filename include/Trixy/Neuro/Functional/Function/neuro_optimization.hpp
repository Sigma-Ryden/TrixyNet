#ifndef NEURO_OPTIMIZATION_HPP
#define NEURO_OPTIMIZATION_HPP

#include <cstddef> // size_t
#include <cmath> // sqrt

#include "Trixy/Neuro/Detail/macro_scope.hpp"

namespace trixy
{

namespace set
{

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

TRIXY_FUNCTION_TENSOR_TPL_DECLARATION
void momentum(
    Tensor<Precision, Args...>& buff,
    Tensor<Precision, Args...>& s,
    const Tensor<Precision, Args...>& g) noexcept
{
    static constexpr Precision beta1 = 0.9;
    static constexpr Precision beta2 = 1. - beta1;

    s.join(beta1);
    s.add(buff.join(beta2, g));

    buff.copy(s);
}

TRIXY_FUNCTION_TENSOR_TPL_DECLARATION
void rms_prop(
    Tensor<Precision, Args...>& buff,
    Tensor<Precision, Args...>& s,
    const Tensor<Precision, Args...>& g) noexcept
{
    static constexpr Precision beta1 = 0.9;
    static constexpr Precision beta2 = 1. - beta1;

    s.join(beta1);
    s.add(buff.multiply(g, g).join(beta2));

    buff.multiply(g, s.apply(detail::invertSqrt));
}

TRIXY_FUNCTION_TENSOR_TPL_DECLARATION
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

} // namespace trixy

#include "Trixy/Neuro/Detail/macro_unscope.hpp"

#endif // NEURO_OPTIMIZATION_HPP
