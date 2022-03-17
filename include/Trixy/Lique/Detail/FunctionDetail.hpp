#ifndef LIQUE_FUNCTION_DETAIL_HPP
#define LIQUE_FUNCTION_DETAIL_HPP

#include "Trixy/Detail/TrixyMeta.hpp"

namespace trixy
{

namespace lique
{

namespace detail
{

template <typename Iterator, typename ConstIterator>
void copy(Iterator first, Iterator last, ConstIterator src)
{
    while(first != last) *first++ = *src++;
}

template <typename T>
void fill(T* first, T* last, const T& value)
{
    while(first != last) *first++ = value;
}

template <typename T, class Generator, meta::as_callable_t<Generator> = 0>
void fill(T* first, T* last, Generator generator)
{
    while(first != last) *first++ = generator();
}

template <typename T, class Operation>
void assign(T* first, T* last, Operation operation, const T& value)
{
    while(first != last)
    {
        operation(*first, value);
        ++first;
    }
}

template <typename T, class Operation>
void assign(T* first, T* last, Operation operation, const T* src)
{
    while(first != last)
    {
        operation(*first, *src);

        ++first;
        ++src;
    }
}

template <typename T, class Operation>
void assign(T* first, T* last, Operation operation, const T& value, const T* rhs)
{
    fill(first, last, value);
    assign(first, last, operation, rhs);
}

template <typename T, class Operation>
void assign(T* first, T* last, Operation operation, const T* lhs, const T* rhs)
{
    copy(first, last, lhs);
    assign(first, last, operation, rhs);
}

template <typename Iterator, class Function>
void apply(Iterator first, Iterator last, Function func)
{
    while(first != last)
    {
        *first = func(*first);
        ++first;
    }
}

template <typename Iterator, class Function, typename ConstIterator>
void apply(Iterator first, Iterator last, Function func, ConstIterator src)
{
    while(first != last)
    {
        *first = func(*src);

        ++first;
        ++src;
    }
}

template <typename Iterator, class Function, typename T>
void for_each(Iterator first, Iterator last, Function func, T& result)
{
    while(first != last)
    {
        func(result, *first);
        ++first;
    }
}

template <typename Iterator, class Function>
void for_each(Iterator first, Iterator last, Function func)
{
    while(first != last)
    {
        func(*first);
        ++first;
    }
}

struct add
{
    template <typename T>
    void operator() (T& dst, const T& rhs) noexcept { dst += rhs; }
};

struct sub
{
    template <typename T>
    void operator() (T& dst, const T& rhs) noexcept { dst -= rhs; }
};

struct mul
{
    template <typename T>
    void operator() (T& dst, const T& rhs) noexcept { dst *= rhs; }
};

} // namespace detail

} // namespace lique

} // namespace trixy

#endif // LIQUE_FUNCTION_DETAIL_HPP
