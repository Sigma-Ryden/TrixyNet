#ifndef TRIXY_LIQUE_FUNCTION_DETAIL_HPP
#define TRIXY_LIQUE_FUNCTION_DETAIL_HPP

#include <cstddef> // size_t

#include <Trixy/Detail/FunctionDetail.hpp>

#include <Trixy/Detail/MetaMacro.hpp>

namespace trixy
{

namespace lique
{

namespace detail
{

struct cpy
{
    template <typename T>
    void operator() (T& dst, const T& rhs) noexcept { dst = rhs; }
};

template <typename FwdIt, class Function>
void for_each(FwdIt first, FwdIt last, Function function)
{
    while (first != last)
    {
        function(*first);
        ++first;
    }
}

template <class FwdIt, class Function>
void block_for_each(
    FwdIt first, FwdIt last, std::size_t extern_block_width, Function func)
    TRNOEXCEPT_IF(noexcept(func))
{
    auto size = last - first + 1;

    auto width  = size % extern_block_width; // iterable part
    auto offset = extern_block_width - width; // offset to step over non-iterable part

    while (first < last) // 'first' maybe never equal to 'last'
    {
        auto non_iterable_part = first + width;
        while (first != non_iterable_part)
            func(*first++);

        first += offset;
    }
}

template <typename FwdIt, typename InIt>
void copy(FwdIt first, FwdIt last, InIt src)
{
    while (first != last) *first++ = *src++;
}

template <typename FwdIt, typename Generator>
void fill(FwdIt first, FwdIt last, Generator gen)
{
    while(first != last) *first++ = gen();
}

template <typename T, class Operation>
void assign(T* first, T* last, Operation operation, const T& value)
{
    while (first != last)
    {
        operation(*first, value);
        ++first;
    }
}

template <typename T, class Operation>
void assign(T* first, T* last, Operation operation, const T* src)
{
    while (first != last)
    {
        operation(*first, *src);

        ++first;
        ++src;
    }
}

template <typename T, class Operation>
void assign(T* first, T* last, Operation operation, const T& value, const T* rhs) // OVERIEW
{
    while (first != last)
    {
        operation(*first, value, *rhs);

        ++first;
        ++rhs;
    }
}

template <typename T, class Operation>
void assign(T* first, T* last, Operation operation, const T* lhs, const T* rhs) // OVERVIEW
{
    while (first != last)
    {
        operation(*first, *lhs, *rhs);

        ++first;
        ++lhs;
        ++rhs;
    }
}

template <typename FwdIt, class Function>
void apply(FwdIt first, FwdIt last, Function function)
{
    while (first != last)
    {
        *first = function(*first);
        ++first;
    }
}

template <typename FwdIt, class Function, typename InIt>
void apply(FwdIt first, FwdIt last, Function function, InIt src)
{
    while (first != last)
    {
        *first = function(*src);

        ++first;
        ++src;
    }
}

struct add
{
    template <typename T>
    void operator() (T& dst, const T& rhs) noexcept { dst += rhs; }

    template <typename T>
    void operator() (T& dst, const T& lhs, const T& rhs) noexcept { dst = lhs + rhs; }
};

struct sub
{
    template <typename T>
    void operator() (T& dst, const T& rhs) noexcept { dst -= rhs; }

    template <typename T>
    void operator() (T& dst, const T& lhs, const T& rhs) noexcept { dst = lhs - rhs; }
};

struct mul
{
    template <typename T>
    void operator() (T& dst, const T& rhs) noexcept { dst *= rhs; }

    template <typename T>
    void operator() (T& dst, const T& lhs, const T& rhs) noexcept { dst = lhs * rhs; }
};

} // namespace detail

} // namespace lique

} // namespace trixy

#endif // TRIXY_LIQUE_FUNCTION_DETAIL_HPP
