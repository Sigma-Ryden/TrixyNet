#ifndef UTIL_HPP
#define UTIL_HPP

#include <cstddef> // size_t
#include <iostream> // ostream
#include <type_traits> // enable_if, is_same
#include <utility> // declval
#include <chrono> // chrono

#include "Trixy/Lique/LiqueVector.hpp"
#include "Trixy/Lique/LiqueMatrix.hpp"

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

template <typename Precision>
std::size_t max(const trixy::lique::Vector<Precision>& vector) noexcept
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

template <typename Precision>
std::ostream& operator<< (
    std::ostream& out, const trixy::lique::Vector<Precision>& vector)
{
    out << '[';
    for(std::size_t i = 0; i < vector.size() - 1; ++i)
        out << vector(i) << ", ";

    out << vector(vector.size() - 1) << ']';

    return out;
}

template <typename Precision>
std::ostream& operator<< (
    std::ostream& out, const trixy::lique::Matrix<Precision>& matrix)
{
    out << '[';
    for(std::size_t i = 0; i < matrix.shape().row() - 1; ++i)
    {
        out << '[';
        for(std::size_t j = 0; j < matrix.shape().col() - 1; ++j)
            out << matrix(i, j) << ", ";

        out << matrix(i, matrix.shape().col() - 1) << "],\n";
    }

    out << '[';
    for(std::size_t j = 0; j < matrix.shape().col() - 1; ++j)
        out << matrix(matrix.shape().row() - 1, j) << ", ";

    out << matrix(matrix.size() - 1) << "]]";

    return out;
}

template <typename Neuro, template <typename...> class Collection, typename Precision>
void test_neuro(
    const Neuro& network,
    const Collection<trixy::lique::Vector<Precision>>& idata,
    const Collection<trixy::lique::Vector<Precision>>& odata)
{
    for(std::size_t i = 0; i < idata.size(); ++i)
        std::cout << "<" << i << "> "
            << network.feedforward(idata[i]) << " : " << odata[i] << '\n';
}

template <typename Neuro, template <typename...> class Collection, typename Precision>
void check_neuro(
    const Neuro& network,
    const Collection<trixy::lique::Vector<Precision>>& idata,
    const Collection<trixy::lique::Vector<Precision>>& odata)
{
    std::cout << "Network train normal accuracy: "   << network.accuracy(idata, odata)
              << "\nNetwork train global accuracy: " << network.accuracyg(idata, odata, 0.05)
              << "\nNetwork train full accuracy: "   << network.accuracyf(idata, odata, 0.05)
              << "\nNetwork train Loss: "            << network.loss(idata, odata) << '\n';
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
