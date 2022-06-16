#ifndef TRIXY_LIQUE_TOOL_HPP
#define TRIXY_LIQUE_TOOL_HPP

#include <cstddef> // size_t
#include <random> // rand
#include <utility> // forward

#include <Trixy/Lique/Vector.hpp>
#include <Trixy/Lique/Matrix.hpp>

#include <Trixy/Lique/Detail/LiqueMeta.hpp>
#include <Trixy/Lique/Detail/FunctionDetail.hpp>

#include <Trixy/Detail/TrixyMeta.hpp>

#include <Trixy/Detail/MacroScope.hpp>

namespace trixy
{

namespace lique
{

enum class Axis { X, Y, Z };

namespace comp
{

struct is_bigger
{
    template <typename T>
    bool operator() (T previous, T current) { return previous > current; }
};

struct is_less
{
    template <typename T>
    bool operator() (T previous, T current) { return previous < current; }
};

} // namespace comp

template <class T>
inline T sum(T&& t) noexcept { return t; }

template <class T, class... Tn,
          trixy::meta::require<trixy::meta::is_same_all<T, Tn...>::value> = 0>
inline T sum(T&& t, Tn&&... tn)
{
    return t + sum(std::forward<T>(tn)...);
}

template <class Iterable, lique::meta::as_iterate<Iterable> = 0>
inline auto first(Iterable& it) -> decltype(it.data())
{
    return it.data();
}

template <class Iterable, lique::meta::as_iterate<Iterable> = 0>
inline auto last(Iterable& it) -> decltype(it.data() + it.size())
{
    return it.data() + it.size();
}

template <typename InIt, typename T>
T accumulate(InIt first, InIt last, T init)
{
    detail::for_each(
        first, last, [&init](const T& value) { init += value; }
    );

    return init;
}

template <class FwdIt, class Binary>
FwdIt search(FwdIt first, FwdIt last, Binary compare) noexcept
{
    if (first == last) return first;

    auto hold = first;
    auto it = ++first;

    while (it != last)
    {
        if (compare(*hold, *it)) hold = it;

        ++it;
    }

    return hold;
}

template <class Iterable, class Binary,
          lique::meta::as_iterate<Iterable> = 0>
std::size_t search(const Iterable& it, Binary compare) noexcept
{
    return search(first(it), last(it), compare) - first(it);
}

template <typename Precision, class Binary>
Vector<std::size_t> search(const Matrix<Precision>& matrix, Axis axis, Binary compare) // repair
{
    using size_type = std::size_t;

    const size_type block_size = matrix.shape().width;
    const size_type number_of_blocks = matrix.shape().height;

    Vector<size_type> vector;
    size_type arg;

    if (axis == Axis::X)
    {
        vector.resize(block_size);
        vector.fill(size_type(0));

        for (size_type i = 1; i < number_of_blocks; ++i)
            for (size_type n = 0; n < vector.size(); ++n)
                if (compare(matrix(vector(n), n), matrix(i, n)))
                    vector(n) = i;
    }
    else if (axis == Axis::Y)
    {
        vector.resize(number_of_blocks);

        for (size_type n = 0; n < vector.size(); ++n)
        {
            for (size_type i = 1; i < block_size; ++i)
                if (compare(matrix(n, arg), matrix(n, i)))
                    arg = i;

            vector(n) = arg;
        }
    }

    return vector;
}

template <class FwdIt>
std::size_t argmin(FwdIt first, FwdIt last) noexcept
{
    return search(first, last, comp::is_bigger{}) - first;
}

template <class Iterable, lique::meta::as_iterate<Iterable> = 0>
std::size_t argmin(const Iterable& it) noexcept
{
    return search(it, comp::is_bigger{});
}

template <class FwdIt>
std::size_t argmax(FwdIt first, FwdIt last) noexcept
{
    return search(first, last, comp::is_less{}) - first;
}

template <class Iterable, lique::meta::as_iterate<Iterable> = 0>
std::size_t argmax(const Iterable& it) noexcept
{
    return search(it, comp::is_less{});
}

TRIXY_FUNCTION_TPL_DECLARATION
Vector<std::size_t> argmin(const Matrix<Precision>& matrix, Axis axis)
{
    return search(matrix, axis, comp::is_bigger{});
}

TRIXY_FUNCTION_TPL_DECLARATION
Vector<std::size_t> argmax(const Matrix<Precision>& matrix, Axis axis)
{
    return search(matrix, axis, comp::is_less{});
}

template <class FwdIt>
auto min(FwdIt first, FwdIt last) noexcept -> decltype(*search(first, last, comp::is_bigger{}))
{
    return *search(first, last, comp::is_bigger{});
}

template <class Iterable, typename precision_type = typename Iterable::precision_type,
          lique::meta::as_iterate<Iterable> = 0>
precision_type min(const Iterable& it) noexcept
{
    return it(search(it, comp::is_bigger{}));
}

template <class FwdIt>
auto max(FwdIt first, FwdIt last) noexcept -> decltype(*search(first, last, comp::is_less{}))
{
    return *search(first, last, comp::is_less{});
}

template <class Iterable, typename precision_type = typename Iterable::precision_type,
          lique::meta::as_iterate<Iterable> = 0>
precision_type max(const Iterable& it) noexcept
{
    return it(search(it, comp::is_less{}));
}

template <class InIt, typename T>
T mean(InIt first, InIt last, T init) noexcept
{
    init = lique::accumulate(first, last, init);

    return init / static_cast<T>(last - first);
}

template <class Iterable, typename T = double, lique::meta::as_iterate<Iterable> = 0>
T mean(const Iterable& it) noexcept
{
    return mean(first(it), last(it), T{});
}

template <class InIt, typename T>
T std(InIt first, InIt last, T init, bool unbiased = false)
{
    T mean_value = mean(first, last, init);
    T std_value{};

    auto it = first;

    while (it != last)
    {
        init = *it - mean_value;
        std_value += init * init;

        ++it;
    }

    std_value /= static_cast<T>(last - first - unbiased);

    return static_cast<T>(std::sqrt(std_value));
}

template <class Iterable, typename T = double,
          lique::meta::as_iterate<Iterable> = 0>
T std(const Iterable& it, bool unbiased = false)
{
    return std(first(it), last(it), T{}, unbiased);
}

TRIXY_FUNCTION_TPL_DECLARATION
Vector<double> mean(const Matrix<Precision>& matrix, Axis axis) // repair
{
    using size_type = typename Matrix<Precision>::size_type;

    const size_type block_size = matrix.shape().width;
    const size_type number_of_blocks = matrix.shape().height;

    auto m_first = first(matrix);
    auto m_last  = last(matrix);

    Vector<double> vector;

    if (axis == Axis::X)
    {
        vector.resize(block_size, Precision(0.));

        auto v_first = first(vector);
        auto v_last = last(vector);

        while (m_first != m_last)
        {
            detail::assign(v_first, v_last, detail::add(), m_first);
            m_first += vector.size();
        }

        vector.join( 1. / static_cast<double>(number_of_blocks));
    }
    else if (axis == Axis::Y)
    {
        vector.resize(number_of_blocks);

        auto v_first = first(vector);
        auto v_last = last(vector);

        while (v_first != v_last)
        {
            *v_first = lique::accumulate(m_first, m_first + block_size, Precision(0.));

            m_first += block_size;
            ++v_first;
        }

        vector.join(1. / static_cast<double>(block_size));
    }

    return vector;
}

TRIXY_FUNCTION_TPL_DECLARATION
Vector<double> std(const Matrix<Precision>& matrix, Axis axis, bool unbiased = false)
{
    using size_type = typename Matrix<Precision>::size_type;

    const size_type block_size = matrix.shape().width;
    const size_type number_of_blocks = matrix.shape().height;

    Vector<double> vector = mean(matrix, axis);

    double std_value;
    double mean_value;

    double buff;

    auto accumulate_std = [buff](double mean, double value, double& accumulate) mutable
    {
        buff = mean - value;
        accumulate += buff * buff;
    };

    if (axis == Axis::X)
    {
        for (size_type i = 0; i < vector.size(); ++i)
        {
            std_value = 0.;
            for (size_type n = 0; n < number_of_blocks; ++n)
                accumulate_std(vector(i), matrix(n, i), std_value);

            vector(i) = std_value;
        }

        vector.join(1. / static_cast<double>(number_of_blocks - unbiased));
        vector.apply<double (*)(double)>(std::sqrt);
    }
    else
    {
        auto v_first = first(vector);
        auto v_last  = last(vector);

        auto m_first = first(matrix);

        while (v_first != v_last)
        {
            std_value = 0.;

            mean_value = *v_first;
            auto accumulate_adapter = [accumulate_std, mean_value, &std_value](double value)
            {
                accumulate_std(mean_value, value, std_value);
            };

            detail::for_each(m_first, m_first + block_size, accumulate_adapter);
            *v_first = std_value;

            m_first += block_size;
            ++v_first;
        }

        vector.join(1. / static_cast<double>(block_size - unbiased));
        vector.apply<double (*)(double)>(std::sqrt);
    }

    return vector;
}

using detail::for_each;

template <class Iterable, class Function,
          lique::meta::as_iterate<Iterable> = 0>
void loop(Iterable& it, Function func) TRIXY_NOEXCEPT_IF(noexcept(func))
{
    detail::for_each(first(it), last(it), func);
}

template <class FwdIt, class Function>
void block_loop(
    FwdIt A,
    FwdIt B,
    std::size_t extern_block_width,
    Function func) TRIXY_NOEXCEPT_IF(noexcept(func))
{
    detail::block_for_each(A, B, extern_block_width, func);
}

namespace detail
{

template <class T, lique::meta::as_iterate<T> = 0>
void concat(T& out, std::size_t& at, const T& it)
{
    detail::copy(out.data() + at, out.data() + at + it.size(), it.data());
}

template <class T, class... Tn,
          lique::meta::as_iterate<T> = 0,
          trixy::meta::enable_if_t<trixy::meta::is_same_all<T, Tn...>::value, int> = 0>
void concat(T& out, std::size_t& at, const T& it, const Tn&... it_n)
{
    detail::copy(out.data() + at, out.data() + at + it.size(), it.data());
    at += it.size();

    concat(out, at, it_n...);
}

} // namespace detail

template <class Iterable, template <typename...> class Container,
          lique::meta::as_iterate<Iterable> = 0>
Iterable concat(const Container<Iterable>& list)
{
    using size_type = typename Iterable::size_type;

    size_type accumulate_size = 0;

    for (const auto& it : list) accumulate_size += it.size();

    Iterable it(accumulate_size);

    size_type at = 0;
    for (const auto& it : list)
    {
        detail::copy(it.data() + at, it.data() + at + it.size(), it.data());
        at += it.size();
    }

    return it;
}

template <class T, class... Tn,
          lique::meta::as_iterate<T> = 0,
          trixy::meta::require<trixy::meta::is_same_all<T, Tn...>::value> = 0>
T concat(const T& it, const Tn&... it_n)
{
    using size_type = typename T::size_type;

    T out = sum(it.size(), it_n.size()...);

    size_type position = 0;
    detail::concat(out, position, it, it_n...);

    return out;
}

template <class FwdIt, class Generator>
std::size_t multinomial(FwdIt first, FwdIt last, Generator generator, std::size_t rand_max) noexcept
{
    using precision_type = trixy::meta::decay_t<decltype(*first)>;

    // random_value satisfies the range [0, 1]
    precision_type random_value = precision_type(generator()) / precision_type(rand_max);

    precision_type accumulate = 0.;

    auto it = first;

    while (it != last)
    {
        accumulate += *it;

        if (random_value < accumulate) return std::size_t(it - first);

        ++it;
    }

    // special case for invalid input data
    // finding max it* in the sequance
    return std::size_t(search(first, last, comp::is_less{}) - first);
}

template <class Iterable, class Generator, lique::meta::as_iterate<Iterable> = 0>
std::size_t multinomial(const Iterable& it, Generator generator, std::size_t rand_max) noexcept
{
    return multinomial(first(it), last(it), generator, rand_max);
}

template <class FwdIt>
std::size_t multinomial(FwdIt first, FwdIt last) noexcept
{
    return multinomial(first, last, std::rand, RAND_MAX);
}

template <class Iterable, lique::meta::as_iterate<Iterable> = 0>
std::size_t multinomial(const Iterable& it) noexcept
{
    return multinomial(it, std::rand, RAND_MAX);
}

} // namespace lique

} // namespace trixy

#include <Trixy/Detail/MacroUnscope.hpp>

#endif // TRIXY_LIQUE_TOOL_HPP
