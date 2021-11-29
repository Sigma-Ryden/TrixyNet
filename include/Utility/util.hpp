#ifndef UTIL_HPP
#define UTIL_HPP

#include <cstddef> // size_t
#include <iostream> // ostream
#include <type_traits> // enable_if, is_same
#include <utility> // declval
#include <chrono> // chrono

namespace util
{

class Timer
{
private:
    using clock_t  = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1>>;

    std::chrono::time_point<clock_t> m_beg;

public:
    Timer() : m_beg(clock_t::now())
    {
    }

    void reset()
    {
        m_beg = clock_t::now();
    }

    double elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};

template <template <typename, typename...> class Tensor1D, typename Precision, typename... Args>
std::size_t max(const Tensor1D<Precision, Args...>& vector) noexcept
{
    static std::size_t max;

    max = 0;
    for(std::size_t i = 1; i < vector.size(); ++i)
        if(vector(max) < vector(i))
            max = i;

    return max;
}

template <template <typename...> class Collection>
void network_size(const Collection<std::size_t>& topology)
{
    std::size_t count = 0;
    for(std::size_t i = 1; i < topology.size(); ++i)
       count += (topology[i - 1] + 1) * topology[i];

    count += topology.size();

    count *= 8;

    std::cout << (count / 1024) / 1024 << " MByte(s) "
              << (count / 1024) % 1024 << " KByte(s) "
              << count % 1024 << " Byte(s)\n";
}

template <template <typename T, typename...> class Tensor1D, typename Type, typename... Args,
          typename std::enable_if<
                   std::is_same<decltype(std::declval<Tensor1D<Type, Args...>>().operator()(0)),
                                Type&>::value, int>::type = 0>
std::ostream& operator<< (
    std::ostream& out, const Tensor1D<Type, Args...>& vector)
{
    out << '[';
    for(std::size_t i = 0; i < vector.size() - 1; ++i)
        out << vector(i) << ", ";

    out << vector(vector.size() - 1) << ']';

    return out;
}

template <template <typename T, typename...> class Tensor2D, typename Type, typename... Args,
          typename std::enable_if<
                   std::is_same<decltype(std::declval<Tensor2D<Type, Args...>>().operator()(0, 0)),
                                Type&>::value, int>::type = 0>
std::ostream& operator<< (
    std::ostream& out, const Tensor2D<Type, Args...>& matrix)
{
    out << '[';
    for(std::size_t i = 0; i < matrix.size().row() - 1; ++i)
    {
        out << '[';
        for(std::size_t j = 0; j < matrix.size().col() - 1; ++j)
            out << matrix(i, j) << ", ";

        out << matrix(i, matrix.size().col() - 1) << "], ";
    }

    out << '[';
    for(std::size_t j = 0; j < matrix.size().col() - 1; ++j)
        out << matrix(matrix.size().row() - 1, j) << ", ";

    out << matrix(matrix.size().row() - 1, matrix.size().col() - 1) << "]]";

    return out;
}

template <typename Neuro,
          template <typename T, typename...> class Tensor1D,
          template <typename...> class Collection,
          typename Type,
          typename... Args>
void test_neuro(
    const Neuro& network,
    const Collection<Tensor1D<Type, Args...>>& idata,
    const Collection<Tensor1D<Type, Args...>>& odata)
{
    for(std::size_t i = 0; i < idata.size(); ++i)
        std::cout << "<" << i << "> "
            << network.feedforward(idata[i]) << " : " << odata[i] << '\n';
}

template <typename Neuro,
          template <typename T, typename...> class Tensor1D,
          template <typename...> class Collection,
          typename Type,
          typename... Args>
void check_neuro(
    const Neuro& network,
    const Collection<Tensor1D<Type, Args...>>& idata,
    const Collection<Tensor1D<Type, Args...>>& odata)
{
    std::cout << "NNetwork tarin normal accuracy: "   << network.accuracy(idata, odata)
              << "\nNNetwork tarin global accuracy: " << network.accuracyg(idata, odata, 0.05)
              << "\nNNetwork tarin full accuracy: "   << network.accuracyf(idata, odata, 0.05)
              << "\nNNetwork tarin Loss: "            << network.loss(idata, odata) << '\n';
}

template <typename Neuro>
void show_inner_struct(const Neuro& neuro)
{
    for(std::size_t i = 0; i < neuro.getInnerWeight().size(); ++i)
        std::cout << "W[" << i << "]: " << neuro.getInnerWeight()[i] << '\n';

    for(std::size_t i = 0; i < neuro.getInnerBias().size(); ++i)
        std::cout << "B[" << i << "]: " << neuro.getInnerBias()[i] << '\n';
}

} // namespace util

#endif // UTIL_HPP
