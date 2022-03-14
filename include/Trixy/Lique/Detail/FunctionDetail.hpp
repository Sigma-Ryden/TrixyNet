#ifndef LIQUE_FUNCTION_DETAIL_HPP
#define LIQUE_FUNCTION_DETAIL_HPP

#include "Trixy/Detail/TrixyMeta.hpp"

namespace trixy
{

namespace lique
{

namespace detail
{

template <typename... Args> using Operation = void (*) (Args...);

template <typename T, Operation<T&, T> operation>
void assign(T* first, T* last, const T* src)
{
    while(first != last)
    {
        operation(*first, *src);

        ++first;
        ++src;
    }
}

template <typename T, Operation<T&, T, T> operation>
void assign(T* first, T* last, const T* src1, const T* src2)
{
    while(first != last)
    {
        operation(*first, *src1, *src2);

        ++first;
        ++src1;
        ++src2;
    }
}

template <typename T, Operation<T&, T> operation>
void assign(T* first, T* last, T val)
{
    while(first != last)
    {
        operation(*first, val);
        ++first;
    }
}

template <typename T, Operation<T&, T, T> operation>
void assign(T* first, T* last, T val, const T* src)
{
    while(first != last)
    {
        operation(*first, val, *src);

        ++first;
        ++src;
    }
}

template <typename T, class Function>
void assign(T* first, T* last, Function func)
{
    while(first != last)
    {
        *first = func(*first);
        ++first;
    }
}

template <typename T, class Function>
void assign(T* first, T* last, Function func, const T* src)
{
    while(first != last)
    {
        *first = func(*src);

        ++first;
        ++src;
    }
}

template <typename T, Operation<T&, T> operation>
void calculate(const T* first, const T* last, T& result)
{
    while(first != last)
    {
        operation(result, *first);
        ++first;
    }
}

template <typename T> inline void add(T& dst, T rhs) { dst += rhs; }
template <typename T> inline void sub(T& dst, T rhs) { dst -= rhs; }
template <typename T> inline void mul(T& dst, T rhs) { dst *= rhs; }

template <typename T> inline void add(T& dst, T lhs, T rhs) { dst = lhs + rhs; }
template <typename T> inline void sub(T& dst, T lhs, T rhs) { dst = lhs - rhs; }
template <typename T> inline void mul(T& dst, T lhs, T rhs) { dst = lhs * rhs; }

template <typename T>
void copy(T* first, T* last, const T* src)
{
    while(first != last) *first++ = *src++;
}

template <typename T>
void fill(T* first, T* last, T val)
{
    while(first != last) *first++ = val;
}

template <typename T, class Generator,
          trixy::meta::use_for_callable_t<Generator, T> = 0>
void fill(T* first, T* last, Generator gen)
{
    while(first != last) *first++ = gen();
}

template <typename T>
void accumulate(const T* first, const T* last, T& result)
{
    calculate<T, add>(first, last, result);
}

} // namespace detail

} // namespace lique

} // namespace trixy

#endif // LIQUE_FUNCTION_DETAIL_HPP
