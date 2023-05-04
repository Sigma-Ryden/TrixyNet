#ifndef TRIXY_FUNCTION_ACTIVATION_HPP
#define TRIXY_FUNCTION_ACTIVATION_HPP

#include <cstddef> // size_t
#include <cmath> // exp

#include <Trixy/Neuro/Functional/Function/Base.hpp>

#include <Trixy/Neuro/Functional/Function/ActivationLess.hpp>

#include <Trixy/Neuro/Detail/TrixyNetMeta.hpp>

#include <Trixy/Neuro/Functional/Function/Detail/MacroScope.hpp>

namespace trixy
{

namespace functional
{

namespace activation
{

TRIXY_FUNCTION_GENERIC_HELPER(identity)

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

template <class OutRange, class InRange>
void unstable_softmax(OutRange& result, const InRange& input) noexcept
{
    using precision_type = typename OutRange::value_type;

    auto first = result.data();
    auto last  = result.data() + result.size();

    auto it = input.data();

    while (first != last) *first++ = std::exp(*it++);

    precision_type denominator = 0.;

    first = result.data();
    last  = result.data() + result.size();

    while (first != last)
    {
        denominator += *first;
        ++first;
    }

    denominator = 1. / denominator;

    first = result.data();
    last  = result.data() + result.size();

    while (first != last)
    {
        *first *= denominator;
        ++first;
    }
}

template <class OutRange, class InRange>
void softmax(OutRange& result, const InRange& input) noexcept
{
    using precision_type = typename OutRange::value_type;

    precision_type max;
    {
        auto first = input.data();
        auto last  = input.data() + input.size();

        max = *first++; // assign of curr value and increment of it

        while (first != last)
        {
            if (max < *first) max = *first;

            ++first;
        }
    }

    auto first = result.data();
    auto last  = result.data() + result.size();

    auto it = input.data();

    while (first != last)
    {
        *first = std::exp(*it - max);
        ++first;
        ++it;
    }

    first = result.data();
    last  = result.data() + result.size();

    precision_type denominator = 0.;

    while (first != last)
    {
        denominator += *first;
        ++first;
    }

    denominator = 1. / denominator;

    first = result.data();
    last  = result.data() + result.size();

    while (first != last)
    {
        *first *= denominator;
        ++first;
    }
}

template <class Range1, class Range2>
void softmax_derived(Range1& result, const Range2& input) noexcept
{
    auto first = result.data();
    auto last  = result.data() + result.size();

    auto it = input.data();

    while (first != last) *first++ = 1.;
}

TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(Identity, identity, identity_derived);

TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(ReLU, relu, relu_derived);
TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(ELU, elu, elu_derived);

TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(LReLU, lrelu, lrelu_derived);
TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(SELU, selu, selu_derived);
TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(GELU, gelu, gelu_derived);

TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(Sigmoid, sigmoid, sigmoid_derived);
TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(Tanh, tanh, tanh_derived);

TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(SoftSign, softsign, softsign_derived);
TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(SoftPlus, softplus, softplus_derived);
TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(Swish, swish, swish_derived);

TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(ModRelu, mod_relu, mod_relu_derived);
TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(ModTanh, mod_tanh, mod_tanh_derived);

TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(SoftMax, softmax, softmax_derived);

} // namespace activation

} // namespace functional

} // namespace trixy

#include <Trixy/Neuro/Functional/Function/Detail/MacroScope.hpp>

#endif // TRIXY_FUNCTION_ACTIVATION_HPP
