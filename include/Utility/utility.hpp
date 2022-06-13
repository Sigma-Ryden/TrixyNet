#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <cstddef> // size_t
#include <iostream> // ostream
#include <type_traits> // enable_if, is_same
#include <utility> // declval
#include <chrono> // chrono

#include <Trixy/Detail/TrixyMeta.hpp>
#include <Trixy/Lique/Detail/LiqueMeta.hpp>

#include <Trixy/Neuro/Checker/Core.hpp>

namespace utility
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

template <template <typename...> class Collection>
void network_size(const Collection<std::size_t>& topology) // deprecated & repair
{
    std::size_t count = 0;
    for (std::size_t i = 1; i < topology.size(); ++i)
       count += (topology[i - 1] + 1) * topology[i];

    count += topology.size();

    count *= 8;

    std::cout << (count / 1024) / 1024 << " MByte(s) "
              << (count / 1024) % 1024 << " KByte(s) "
              << count % 1024 << " Byte(s)\n";
}

template <class Vector,
    trixy::meta::require<not trixy::lique::meta::is_matrix<Vector>::value and
                         trixy::lique::meta::is_iterate<Vector>::value> = 0>
std::ostream& operator<< (std::ostream& out, const Vector& vector)
{
    if (vector.size() == 0) return out;

    out << '[';
    for (std::size_t i = 0; i < vector.size() - 1; ++i)
        out << vector(i) << ", ";

    out << vector(vector.size() - 1) << ']';

    return out;
}

template <class Matrix, trixy::lique::meta::as_matrix<Matrix> = 0>
std::ostream& operator<< (std::ostream& out, const Matrix& matrix)
{
    out << '[';
    for (std::size_t i = 0; i < matrix.shape().height - 1; ++i)
    {
        out << '[';
        for (std::size_t j = 0; j < matrix.shape().width - 1; ++j)
            out << matrix(i, j) << ", ";

        out << matrix(i, matrix.shape().width - 1) << "],\n";
    }

    out << '[';
    for (std::size_t j = 0; j < matrix.shape().width - 1; ++j)
        out << matrix(matrix.shape().height - 1, j) << ", ";

    out << matrix(matrix.size() - 1) << "]]";

    return out;
}

template <class TrixyNet,
          template <typename> class Container = TrixyNet::template Container,
          typename Sample, typename Target>
void statistic(
    TrixyNet& network,
    const Container<Sample>& idata,
    const Container<Target>& odata)
{
    trixy::Checker<TrixyNet> check(network);

    for (std::size_t i = 0; i < idata.size(); ++i)
        std::cout << "<" << i << "> "
            << network(idata[i]) << " : " << odata[i] << '\n';

    std::cout << "Network normal accuracy: " << check.accuracy.normal(idata, odata)
              //<< "\nNetwork global accuracy: " << check.accuracy.global(idata, odata, 0.1)
              //<< "\nNetwork full accuracy: " << check.accuracy(idata, odata)
              //<< "\nNetwork loss: " << check.loss(idata, odata, network.function.loss().f)
              << '\n';
}

} // namespace utility

#endif // UTILITY_HPP
