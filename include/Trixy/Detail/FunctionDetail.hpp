#ifndef FUNCTIONDETAIL_HPP
#define FUNCTIONDETAIL_HPP

#include <cstddef> // size_t
#include <thread> // thread
#include <tuple> // pair

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

} // namespace detail

} // namespace trixy

#endif // FUNCTIONDETAIL_HPP
