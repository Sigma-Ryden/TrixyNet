#ifndef TRIXY_FUNCTION_DETAIL_HPP
#define TRIXY_FUNCTION_DETAIL_HPP

#include <cmath> // sqrt
#include <cstddef> // size_t
#include <thread> // thread
#include <tuple> // pair

#include <Trixy/Detail/TrixyMeta.hpp>

namespace trixy
{

namespace detail
{

/// Function return pair of two elements: number_of_threads & block_size of data per thread
template <std::size_t min_per_thread>
std::pair<std::size_t, std::size_t> parallel_info(std::size_t size)
{
    constexpr std::size_t default_number_of_threads = 2;

    // even if size of data is equal to zero, number_of_threads should be 1
    if(size == 0) return { 1, 0 };

    const std::size_t hardware_threads = std::thread::hardware_concurrency();
    const std::size_t max_threads = (size - 1) / min_per_thread + 1;

    const std::size_t number_of_threads =
        std::min(hardware_threads == 0 ? default_number_of_threads : hardware_threads,
                 max_threads);

    const std::size_t block_size = size / number_of_threads;

    return { number_of_threads, block_size };
}

template <typename Precision, meta::as_arithmetic_t<Precision> = 0>
Precision invert_sqrt(Precision x) noexcept
{
    return 1. / std::sqrt(1e-9 + x);
}

template <typename Pointer>
inline const char* const_byte_cast(Pointer* ptr) noexcept
{
    return reinterpret_cast<const char*>(ptr);
}

template <typename Pointer>
inline char* byte_cast(Pointer* ptr) noexcept
{
    return reinterpret_cast<char*>(ptr);
}

} // namespace detail

} // namespace trixy

#endif // TRIXY_FUNCTION_DETAIL_HPP
