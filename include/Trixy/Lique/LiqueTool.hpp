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

enum class Axis { X, Y };

template <typename Type> using Binary = bool (*)(Type, Type);

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
inline T sum(T&& t) noexcept { return t; }

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

template <typename Iterator, typename T>
T accumulate(Iterator first, Iterator last, T result)
{
    detail::for_each(
        first, last,
        [&result](const T& value) { result += value; }
    );

    return result;
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
    const size_type block_size = matrix.shape().col();
    const size_type number_of_blocks = matrix.shape().row();

    Vector<size_type> vector;
    size_type arg;

    if(axis == Axis::X)
    {
        vector.resize(block_size, size_type(0));

        for(size_type i = 1; i < number_of_blocks; ++i)
            for(size_type n = 0; n < vector.size(); ++n)
                if(compare(matrix(vector(n), n), matrix(i, n)))
                    vector(n) = i;
    }
    else
    {
        vector.resize(number_of_blocks);

        for(size_type n = 0; n < vector.size(); ++n)
        {
            for(size_type i = 1; i < block_size; ++i)
                if(compare(matrix(n, arg), matrix(n, i)))
                    arg = i;

            vector(n) = arg;
        }
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

    mean_value = accumulate(first(tensor), last(tensor), mean_value);

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

    const size_type block_size = matrix.shape().col();
    const size_type number_of_blocks = matrix.shape().row();

    auto m_first = first(matrix);
    auto m_last = last(matrix);

    Vector<Precision> vector;

    if(axis == Axis::X)
    {
        vector.resize(block_size, Precision(0.));

        auto v_first = first(vector);
        auto v_last = last(vector);

        while(m_first != m_last)
        {
            detail::assign(v_first, v_last, detail::add(), m_first);
            m_first += vector.size();
        }

        vector.join( 1. / static_cast<Precision>(number_of_blocks));
    }
    else
    {
        vector.resize(number_of_blocks);

        auto v_first = first(vector);
        auto v_last = last(vector);

        while(v_first != v_last)
        {
            *v_first = accumulate(m_first, m_first + block_size, Precision(0.));

            m_first += block_size;
            ++v_first;
        }

        vector.join(1. / static_cast<Precision>(block_size));
    }

    return vector;
}

TRIXY_FUNCTION_TPL_DECLARATION
Vector<Precision> std(const Matrix<Precision>& matrix, Axis axis, bool unbiased = false)
{
    using size_type = typename Vector<Precision>::size_type;

    const size_type block_size = matrix.shape().col();
    const size_type number_of_blocks = matrix.shape().row();

    Vector<Precision> vector = mean(matrix, axis);

    Precision std_value;
    Precision mean_value;

    Precision buff;

    auto accumulate_std =
    [buff](const Precision& mean, const Precision& value, Precision& accumulate)
    {
        buff = mean - value;
        accumulate += buff * buff;
    };

    if(axis == Axis::X)
    {
        for(size_type i = 0; i < vector.size(); ++i)
        {
            std_value = 0.;
            for(size_type n = 0; n < number_of_blocks; ++n)
                accumulate_std(vector(i), matrix(n, i), std_value);

            vector(i) = std_value;
        }

        vector.join(1. / static_cast<Precision>(number_of_blocks - unbiased));
        vector.apply(std::sqrt<Precision>);
    }
    else
    {
        auto v_first = first(vector);
        auto v_last = last(vector);

        auto m_first = first(matrix);

        while(v_first != v_last)
        {
            std_value = 0.;

            mean_value = *v_first;
            auto accumulate_adapter =
            [accumulate_std, &std_value, mean_value](const Precision& value)
            {
                accumulate_std(mean_value, value, std_value);
            };

            detail::for_each(m_first, m_first + block_size, accumulate_adapter);
            *v_first = std_value;

            m_first += block_size;
            ++v_first;
        }

        vector.join(1. / static_cast<Precision>(block_size - unbiased));
        vector.apply(std::sqrt<Precision>);
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

    // random_value satisfies the range [0, 1]
    precision_type random_value = precision_type(generator()) / precision_type(rand_max);

    precision_type accumulate = 0.;

    auto begin = first(tensor);
    auto end = last(tensor);

    while(begin != end)
    {
        accumulate += *begin;

        if(random_value < accumulate) return begin - first(tensor);

        ++begin;
    }

    // special case for invalid input data
    return argmax(tensor);
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
