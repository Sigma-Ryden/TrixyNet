#ifndef TRIXY_LIQUE_FUNCTION_DETAIL_HPP
#define TRIXY_LIQUE_FUNCTION_DETAIL_HPP

#include <cstddef> // size_t
//#include <functional> // mem_fn
//#include <iterator> // distance
//#include <thread> // thread
//#include <vector> // vector

#include <Trixy/Detail/FunctionDetail.hpp>

#include <Trixy/Detail/TrixyMeta.hpp>

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
    while(first != last)
    {
        function(*first);
        ++first;
    }
}

template <typename FwdIt, typename InIt>
void copy(FwdIt first, FwdIt last, InIt src)
{
    while(first != last) *first++ = *src++;
}

// __EXPERIMENTAL__ maybe unstable
/*
template <typename FwdIt, typename InIt>
void parrallel_copy(FwdIt first, FwdIt last, InIt src)
{
    constexpr std::size_t min_elements_per_thread = 32;

    const std::size_t length = last - first;

    if(length <= min_elements_per_thread) return copy(first, last, src);

    auto info = trixy::detail::parallel_info<min_elements_per_thread>(length);

    const std::size_t number_of_threads = info.first;
    const std::size_t block_size = info.second;

    std::vector<std::thread> threads;
    threads.reserve(number_of_threads - 1);

    for(std::size_t i = 0; i < number_of_threads - 1; ++i)
    {
        threads.emplace_back(copy<FwdIt, InIt>, first, first + block_size, src);

        std::advance(first, block_size);
        std::advance(src, block_size);
    }
    // task perfomane by main thread
    copy(first, last, src);

    detail::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
}
*/
template <typename FwdIt, typename Generator>
void fill(FwdIt first, FwdIt last, Generator gen)
{
    while(first != last) *first++ = gen();
}

// __EXPERIMENTAL__ maybe unstable
/*
template <typename FwdIt, class Generator>
void parallel_fill(FwdIt first, FwdIt last, Generator gen)
{
    constexpr std::size_t min_elements_per_thread = 32;

    const std::size_t length = last - first;

    if(length <= min_elements_per_thread) return fill(first, last, gen);

    auto info = trixy::detail::parallel_info<min_elements_per_thread>(length);

    const std::size_t number_of_threads = info.first;
    const std::size_t block_size = info.second;

    std::vector<std::thread> threads;
    threads.reserve(number_of_threads - 1);

    for(std::size_t i = 0; i < number_of_threads - 1; ++i)
    {
        threads.emplace_back(fill<FwdIt, Generator>, first, first + block_size, gen);
        first += block_size;
    }
    // task perfomane by main thread
    fill(first, last, gen);

    detail::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
}
*/
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
void assign(T* first, T* last, Operation operation, const T& value, const T* rhs) // OVERIEW
{
    while(first != last)
    {
        operation(*first, value, *rhs);

        ++first;
        ++rhs;
    }
}

template <typename T, class Operation>
void assign(T* first, T* last, Operation operation, const T* lhs, const T* rhs) // OVERVIEW
{
    while(first != last)
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
    while(first != last)
    {
        *first = function(*first);
        ++first;
    }
}

template <typename FwdIt, class Function, typename InIt>
void apply(FwdIt first, FwdIt last, Function function, InIt src)
{
    while(first != last)
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
