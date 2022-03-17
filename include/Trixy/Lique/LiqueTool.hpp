#ifndef LIQUE_TOOL_HPP
#define LIQUE_TOOL_HPP

#include <cstddef> // size_t
#include <random> // rand
#include <utility> // forward

#include "LiqueVector.hpp"
#include "LiqueMatrix.hpp"

#include "Trixy/Detail/TrixyMeta.hpp"
#include "Trixy/Lique/Detail/LiqueMeta.hpp"

#include "Detail/FunctionDetail.hpp"

#include "Trixy/Detail/MacroScope.hpp"

namespace trixy
{

namespace lique
{

enum class Axis { None, X, Y };

template <typename Type>
using Binary = bool (*)(Type, Type);

namespace comp
{

TRIXY_FUNCTION_TPL_DECLARATION
inline bool is_bigger(Precision previous, Precision next) noexcept
{
    return previous > next;
}

TRIXY_FUNCTION_TPL_DECLARATION
inline bool is_less(Precision previous, Precision next) noexcept
{
    return previous < next;
}

} // namespace comp

template <class T>
inline T sum(T&& t) noexcept
{
    return t;
}

template <class T, class... Tn,
          trixy::meta::enable_if_t<trixy::meta::is_same_all<T, Tn...>::value, int> = 0>
inline T sum(T&& t, Tn&&... tn)
{
    return t + sum(std::forward<T>(tn)...);
}

template <class Tensor, lique::meta::as_tensor_t<Tensor> = 0>
inline auto first(Tensor& tensor) -> decltype(tensor.data())
{
    return tensor.data();
}

template <class Tensor, lique::meta::as_tensor_t<Tensor> = 0>
inline auto last(Tensor& tensor) -> decltype(tensor.data() + tensor.size())
{
    return tensor.data() + tensor.size();
}

template <typename Iterator, class Function, typename T>
void accumulate(Iterator first, Iterator last, T& result)
{
    detail::for_each(
        first, last,
        [](const T& value, T& res) { res += value; },
        result
    );
}

template <typename Precision,
          Binary<Precision> compare,
          class Tensor,
          typename size_type = typename Tensor::size_type,
          lique::meta::as_tensor_t<Tensor> = 0>
size_type find(const Tensor& tensor) noexcept
{
    size_type idx = 0;
    for(size_type n = 1; n < tensor.size(); ++n)
        if(compare(tensor(idx), tensor(n)))
            idx = n;

    return idx;
}

template <typename Precision, Binary<Precision> compare,
          typename size_type = typename Matrix<Precision>::size_type,
          trixy::meta::as_arithmetic_t<Precision> = 0>
Vector<size_type> find(const Matrix<Precision>& matrix, Axis axis)
{
    Vector<size_type> vector;
    size_type arg;

    switch(axis)
    {
    case Axis::X:
        vector.resize(matrix.shape().col(), size_type());

        for(size_type i = 1; i < matrix.shape().row(); ++i)
            for(size_type n = 0; n < vector.size(); ++n)
                if(compare(matrix(vector(n), n), matrix(i, n)))
                    vector(n) = i;

        break;

    case Axis::Y:
        vector.resize(matrix.shape().row());

        for(size_type n = 0; n < vector.size(); ++n)
        {
            for(size_type i = 1; i < matrix.shape().col(); ++i)
                if(compare(matrix(n, arg), matrix(n, i)))
                    arg = i;

            vector(n) = arg;
        }
        break;

    default:
        vector.resize(1);

        arg = 0;
        for(size_type i = 1; i < matrix.size(); ++i)
            if(compare(matrix(arg), matrix(i)))
                arg = i;

        vector(0) = arg;
        break;
    }

    return vector;
}

template <class Tensor, typename size_type = typename Tensor::size_type,
          lique::meta::as_tensor_t<Tensor> = 0>
size_type argmin(const Tensor& tensor) noexcept
{
    return find<typename Tensor::precision_type, comp::is_bigger>(tensor);
}

template <class Tensor, typename size_type = typename Tensor::size_type,
          lique::meta::as_tensor_t<Tensor> = 0>
size_type argmax(const Tensor& tensor) noexcept
{
    return find<typename Tensor::precision_type, comp::is_less>(tensor);
}

TRIXY_FUNCTION_TPL_DECLARATION
Vector<std::size_t> argmin(const Matrix<Precision>& matrix, Axis axis)
{
    return find<Precision, comp::is_bigger>(matrix, axis);
}

TRIXY_FUNCTION_TPL_DECLARATION
Vector<std::size_t> argmax(const Matrix<Precision>& matrix, Axis axis)
{
    return find<Precision, comp::is_less>(matrix, axis);
}

template <class Tensor, typename precision_type = typename Tensor::precision_type,
          lique::meta::as_tensor_t<Tensor> = 0>
precision_type min(const Tensor& tensor) noexcept
{
    return tensor(find<typename Tensor::precision_type, comp::is_bigger>(tensor));
}

template <class Tensor, typename precision_type = typename Tensor::precision_type,
          lique::meta::as_tensor_t<Tensor> = 0>
precision_type max(const Tensor& tensor) noexcept
{
    return tensor(find<typename Tensor::precision_type, comp::is_less>(tensor));
}

template <class Tensor, typename precision_type = typename Tensor::precision_type,
          lique::meta::as_tensor_t<Tensor> = 0>
precision_type mean(const Tensor& tensor) noexcept
{
    precision_type mean_value = 0.;

    accumulate(first(tensor), last(tensor), mean_value);

    return mean_value / static_cast<precision_type>(tensor.size());
}

template <class Tensor, typename precision_type = typename Tensor::precision_type,
          lique::meta::as_tensor_t<Tensor> = 0>
precision_type std(const Tensor& tensor, bool unbiased = false)
{
    using size_type = typename Tensor::size_type;

    precision_type mean_value = mean(tensor);
    precision_type std_value;
    precision_type buff;

    for(size_type i = 0; i < tensor.size(); ++i)
    {
        buff = vector(i) - mean_value;
        std_value += buff * buff;
    }

    std_value /= static_cast<precision_type>(tensor.size() - unbiased);

    return std::sqrt(std_value);
}

TRIXY_FUNCTION_TPL_DECLARATION
Vector<Precision> mean(const Matrix<Precision>& matrix, Axis axis)
{
    using size_type = typename Vector<Precision>::size_type;

    Vector<Precision> vector;
    Precision alpha;

    switch(axis)
    {
    case Axis::X:
        vector.resize(matrix.shape().col(), Precision());
        alpha = 1. / static_cast<Precision>(matrix.shape().row());

        for(size_type n = 0; n < matrix.shape().row(); ++n)
            for(size_type i = 0; i < vector.size(); ++i)
                vector(i) += matrix(n, i);

        vector.join(alpha);

        break;

    case Axis::Y:
        vector.resize(matrix.shape().row(), Precision());
        alpha = 1. / static_cast<Precision>(matrix.shape().col());

        for(size_type i = 0; i < vector.size(); ++i)
            for(size_type n = 0; n < matrix.shape().col(); ++n)
                vector(i) += matrix(i, n);

        vector.join(alpha);

        break;

    default:
        Precision result = 0.;
        accumulate(first(matrix), last(matrix), result);

        result *= 1. / static_cast<Precision>(matrix.size());

        vector.resize(1, alpha);

        break;
    }

    return vector;
}

TRIXY_FUNCTION_TPL_DECLARATION
Vector<Precision> std(const Matrix<Precision>& matrix, Axis axis, bool unbiased = false)
{
    using size_type = typename Vector<Precision>::size_type;

    Vector<Precision> vector = mean(matrix, axis);

    Precision std_value;
    Precision alpha;
    Precision buff;

    switch(axis)
    {
    case Axis::X:
        alpha = 1. / static_cast<Precision>(matrix.shape().row() - unbiased);

        for(size_type i = 0; i < vector.size(); ++i)
        {
            std_value = 0.;
            for(size_type n = 0; n < matrix.shape().row(); ++n)
            {
                buff = matrix(n, i) - vector(i);
                std_value += buff * buff;
            }

            vector(i) = std_value;
        }

        vector.join(alpha);
        vector.apply(std::sqrt<Precision>);

        break;

    case Axis::Y:
        alpha = 1. / static_cast<Precision>(matrix.shape().col() - unbiased);

        for(size_type i = 0; i < vector.size(); ++i)
        {
            std_value = 0.;
            for(std::size_t n = 0; n < matrix.shape().col(); ++n)
            {
                buff = matrix(i, n) - vector(i);
                std_value += buff * buff;
            }

            vector(i) = std_value;
        }

        vector.join(alpha);
        vector.apply(std::sqrt<Precision>);

        break;

    default:
        alpha = 1. / static_cast<Precision>(matrix.size() - unbiased);
        std_value = 0.;
        for(size_type i = 0; i < matrix.size(); ++i)
        {
            buff = matrix(i) - vector(0);
            std_value += buff * buff;
        }

        vector(0) = std::sqrt(std_value * alpha);
        break;
    }

    return vector;
}

template <class Tensor, class Function,
          typename = lique::meta::enable_for_tensor_t<Tensor>>
void for_each(Tensor& tensor, Function func) noexcept
{
    detail::for_each(first(tensor), last(tensor), func);
}

namespace detail
{

template <class T, lique::meta::as_tensor_t<T> = 0>
void concat(T& out, std::size_t& at, const T& tensor)
{
    detail::copy(out.data() + at, out.data() + at + tensor.size(), tensor.data());
}

template <class T, class... Tn,
          lique::meta::as_tensor_t<T> = 0,
          trixy::meta::enable_if_t<trixy::meta::is_same_all<T, Tn...>::value, int> = 0>
void concat(T& out, std::size_t& at, const T& tensor, const Tn&... tensor_n)
{
    detail::copy(out.data() + at, out.data() + at + tensor.size(), tensor.data());
    at += tensor.size();

    concat(out, at, tensor_n...);
}

} // namespace detail

template <class Tensor, template <typename...> class Container,
          lique::meta::as_tensor_t<Tensor> = 0>
Tensor concat(const Container<Tensor>& list)
{
    using size_type = typename Tensor::size_type;

    size_type accumulate_size = 0;

    for(const auto& it : list) accumulate_size += it.size();

    Tensor tensor(accumulate_size);

    size_type at = 0;
    for(const auto& it : list)
    {
        detail::copy(tensor.data() + at, tensor.data() + at + it.size(), it.data());
        at += it.size();
    }

    return tensor;
}

template <class T, class... Tn,
          lique::meta::as_tensor_t<T> = 0,
          trixy::meta::enable_if_t<trixy::meta::is_same_all<T, Tn...>::value, int> = 0>
T concat(const T& tensor, const Tn&... tensor_n)
{
    using size_type = typename T::size_type;

    T out(sum(tensor.size(), tensor_n.size()...));

    size_type position = 0;
    detail::concat(out, position, tensor, tensor_n...);

    return out;
}

template <class Tensor, class Generator,
          typename size_type = typename Tensor::size_type,
          lique::meta::as_tensor_t<Tensor> = 0>
size_type multinomial(const Tensor& tensor, Generator generator, size_type rand_max)
{
    using precision_type = typename Tensor::precision_type;

    precision_type r = precision_type(generator()) / precision_type(rand_max);
    precision_type accumulate = 0.;

    for(size_type i = 0; i < tensor.size(); ++i)
    {
        accumulate += tensor[i];
        if(r < accumulate)
            return i;
    }

    return argmin(tensor);
}

template <class Tensor,
          typename size_type = typename Tensor::size_type,
          lique::meta::as_tensor_t<Tensor> = 0>
size_type multinomial(const Tensor& tensor)
{
    return multinomial(tensor, std::rand, RAND_MAX);
}

} // namespace lique

} // namespace trixy

#include "Trixy/Detail/MacroUnscope.hpp"

#endif // LIQUE_TOOL_HPP
