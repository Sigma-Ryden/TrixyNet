#ifndef TEST_DEBUG_TOOLS_HPP
#define TEST_DEBUG_TOOLS_HPP

#include <cstddef> // size_t
#include <iostream> // ostream
#include <type_traits> // enable_if, is_same
#include <utility> // declval
#include <chrono> // chrono

#include <Trixy/Detail/TrixyMeta.hpp>
#include <Trixy/Lique/Detail/LiqueMeta.hpp>

#include <Trixy/Neuro/Checker/Core.hpp>

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

template <typename> struct is_ltensor : std::false_type {};
template <typename Precision>
struct is_ltensor<trixy::lique::Tensor<Precision, trixy::lique::TensorType::tensor>> : std::true_type {};

template <typename> struct is_lmatrix : std::false_type {};
template <typename Precision>
struct is_lmatrix<trixy::lique::Tensor<Precision, trixy::lique::TensorType::matrix>> : std::true_type {};

template <typename> struct is_lvector : std::false_type {};
template <typename Precision>
struct is_lvector<trixy::lique::Tensor<Precision, trixy::lique::TensorType::vector>> : std::true_type {};

template <class Vector,
    trixy::meta::require<is_lvector<Vector>::value> = 0>
std::ostream& operator<< (std::ostream& out, const Vector& vector)
{
    out << '[';
    for (std::size_t i = 0; i < vector.size(); ++i)
        out << vector(i) << (i == vector.size() - 1 ? "" : " ");
    out << ']';

    return out;
}

template <class Matrix,
    trixy::meta::require<is_lmatrix<Matrix>::value> = 0>
std::ostream& operator<< (std::ostream& out, const Matrix& matrix)
{
    out << '[';
    for (std::size_t i = 0; i < matrix.shape().height; ++i)
    {
        out << '[';
        for (std::size_t j = 0; j < matrix.shape().width; ++j)
            out << matrix(i, j) << (j == matrix.shape().width - 1 ? "" : " ");
        out << ']';
    }
    out << ']';

    return out;
}

template <class Tensor,
    trixy::meta::require<is_ltensor<Tensor>::value> = 0>
std::ostream& operator<< (std::ostream& out, const Tensor& tensor)
{
    out << '[';
    for (std::size_t i = 0; i < tensor.shape().depth; ++i)
    {
        out << '[';
        for (std::size_t j = 0; j < tensor.shape().height; ++j)
        {
            out << '[';
            for (std::size_t k = 0; k < tensor.shape().width; ++k)
                out << tensor(i, j, k) << (k == tensor.shape().width - 1 ? "" : " ");
            out << ']';
        }
        out << ']';
    }
    out << ']';

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

    std::cout << "Network normal accuracy: " << check.accuracy.normal(idata, odata);
              //<< "\nNetwork global accuracy: " << check.accuracy.global(idata, odata, 0.1)
              //<< "\nNetwork full accuracy: " << check.accuracy(idata, odata);

    std::cout << '\n';
}

template <class TrixyNet,
          template <typename> class Container = TrixyNet::template Container,
          typename Sample, typename Target, typename LossFunction>
void statistic(
    TrixyNet& network,
    const Container<Sample>& idata,
    const Container<Target>& odata,
    LossFunction loss)
{
    statistic(network, idata, odata);

    trixy::Checker<TrixyNet> check(network);
    std::cout << "Network loss: " << check.loss(idata, odata, loss);

    std::cout << '\n';
}

#endif // TEST_DEBUG_TOOLS_HPP
