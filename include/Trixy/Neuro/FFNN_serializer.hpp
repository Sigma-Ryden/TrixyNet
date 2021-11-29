#ifndef FFNN_SERIALIZER_HPP
#define FFNN_SERIALIZER_HPP

#include "Function/neuro_function_id.hpp"
#include "Function/neuro_activation.hpp"
#include "Detail/neuro_meta.hpp"

#include <cstddef> // size_t
#include <fstream> // ifstream, ofstream

namespace trixy
{

template <template <typename, typename...> class Vector,
          template <typename, typename...> class Matrix,
          template <typename...> class Container,
          typename Precision, typename... Args>
class FFNNSerializer;

} // namespace trixy

#define TRIXY_FFNN_SERIALIZER_TPL_DECLARATION                \
    template <template <typename, typename...> class Vector, \
              template <typename, typename...> class Matrix, \
              template <typename...> class Container,        \
              typename Precision, typename... Args>

#define TRIXY_FFNN_SERIALIZER_TPL                            \
    FFNNSerializer<Vector, Matrix, Container,                \
                   Precision, Args...>

namespace trixy
{

TRIXY_FFNN_SERIALIZER_TPL_DECLARATION
class FFNNSerializer
{
public:
    using Tensor1D  = Vector<Precision, Args...>;
    using Tensor2D  = Matrix<Precision, Args...>;

    using size_type = std::size_t;

private:
    Container<size_type> topology;

    Container<Tensor1D> B;
    Container<Tensor2D> W;

    size_type N;

    Container<function::ActivationId> A;
    function::LossId E;
    function::OptimizationId O;

public:
    FFNNSerializer() : N(0), E(function::LossId::undefined), O(function::OptimizationId::undefined) {}

    template <typename Neuro>
    meta::enable_if_t<meta::is_serializable_neuro<Neuro>::value, void>
    prepare(const Neuro& net);

    void serialize(std::ofstream& out) const;
    void deserialize(std::ifstream& in);

    const Container<size_type>& getTopology() const noexcept;
    const Container<Tensor1D>& getBias() const noexcept;
    const Container<Tensor2D>& getWeight() const noexcept;

    function::ActivationId getActivationId() const noexcept;
    function::ActivationId getNormalizationId() const noexcept;
    const Container<function::ActivationId>& getEachActivationId() const noexcept;

    function::LossId getLossId() const noexcept;
    function::OptimizationId getOptimizationId() const noexcept;
};

TRIXY_FFNN_SERIALIZER_TPL_DECLARATION
template <typename Neuro>
meta::enable_if_t<meta::is_serializable_neuro<Neuro>::value, void>
TRIXY_FFNN_SERIALIZER_TPL::prepare(
    const Neuro& net)
{
    topology = net.getTopology();

    B = net.getInnerBias();
    W = net.getInnerWeight();

    N = B.size();

    A.resize(N);
    for(size_type i = 0; i < N; ++i)
        A[i] = static_cast<function::ActivationId>(net.function.getEachActivation()[i].id);

    E = static_cast<function::LossId>(net.function.getLoss().id);
    O = static_cast<function::OptimizationId>(net.function.getOptimization().id);
}

TRIXY_FFNN_SERIALIZER_TPL_DECLARATION
void TRIXY_FFNN_SERIALIZER_TPL::serialize(std::ofstream& out) const
{
    static size_type topology_size;

    topology_size = topology.size();
    out.write(reinterpret_cast<const char*>(&topology_size), sizeof(size_type));

    for(size_type n = 0; n < topology_size; ++n)
        out.write(reinterpret_cast<const char*>(&topology[n]), sizeof(size_type));

    for(size_type n = 0; n < N; ++n)
        out.write(reinterpret_cast<const char*>(&A[n]), sizeof(function::ActivationId));

    out.write(reinterpret_cast<const char*>(&E), sizeof(function::LossId));
    out.write(reinterpret_cast<const char*>(&O), sizeof(function::OptimizationId));

    for(size_type n = 0; n < N; ++n)
        for(size_type i = 0; i < B[n].size(); ++i)
            out.write(reinterpret_cast<const char*>(&B[n](i)), sizeof(Precision));

    for(size_type n = 0; n < N; ++n)
        for(size_type i = 0; i < W[n].size().row(); ++i)
            for(size_type j = 0; j < W[n].size().col(); ++j)
                out.write(reinterpret_cast<const char*>(&W[n](i, j)), sizeof(Precision));
}

TRIXY_FFNN_SERIALIZER_TPL_DECLARATION
void TRIXY_FFNN_SERIALIZER_TPL::deserialize(std::ifstream& in)
{
    static size_type topology_size;

    in.read(reinterpret_cast<char*>(&topology_size), sizeof(size_type));

    topology.resize(topology_size);
    for(size_type n = 0; n < topology_size; ++n)
        in.read(reinterpret_cast<char*>(&topology[n]), sizeof(size_type));

    N = topology_size - 1;

    A.resize(N);
    B.resize(N);
    W.resize(N);

    for(size_type n = 0; n < N; ++n)
    {
        B[n].resize(topology[n + 1]);
        W[n].resize(topology[n], topology[n + 1]);
    }

    for(size_type n = 0; n < N; ++n)
        in.read(reinterpret_cast<char*>(&A[n]), sizeof(function::ActivationId));

    in.read(reinterpret_cast<char*>(&E), sizeof(function::LossId));
    in.read(reinterpret_cast<char*>(&O), sizeof(function::OptimizationId));

    for(size_type n = 0; n < N; ++n)
        for(size_type i = 0; i < B[n].size(); ++i)
            in.read(reinterpret_cast<char*>(&B[n](i)), sizeof(Precision));

    for(size_type n = 0; n < N; ++n)
        for(size_type i = 0; i < W[n].size().row(); ++i)
            for(size_type j = 0; j < W[n].size().col(); ++j)
                in.read(reinterpret_cast<char*>(&W[n](i, j)), sizeof(Precision));
}

TRIXY_FFNN_SERIALIZER_TPL_DECLARATION
inline const Container<std::size_t>&
    TRIXY_FFNN_SERIALIZER_TPL::getTopology() const noexcept
{
    return topology;
}

TRIXY_FFNN_SERIALIZER_TPL_DECLARATION
inline const Container<Vector<Precision, Args...>>&
    TRIXY_FFNN_SERIALIZER_TPL::getBias() const noexcept
{
    return B;
}

TRIXY_FFNN_SERIALIZER_TPL_DECLARATION
inline const Container<Matrix<Precision, Args...>>&
    TRIXY_FFNN_SERIALIZER_TPL::getWeight() const noexcept
{
    return W;
}

TRIXY_FFNN_SERIALIZER_TPL_DECLARATION
inline function::ActivationId TRIXY_FFNN_SERIALIZER_TPL::getActivationId() const noexcept
{
    return static_cast<function::ActivationId>(A[0]);
}

TRIXY_FFNN_SERIALIZER_TPL_DECLARATION
inline function::ActivationId TRIXY_FFNN_SERIALIZER_TPL::getNormalizationId() const noexcept
{
    return A[A.size() - 1];
}

TRIXY_FFNN_SERIALIZER_TPL_DECLARATION
inline const Container<function::ActivationId>&
    TRIXY_FFNN_SERIALIZER_TPL::getEachActivationId() const noexcept
{
    return A;
}

TRIXY_FFNN_SERIALIZER_TPL_DECLARATION
inline function::LossId TRIXY_FFNN_SERIALIZER_TPL::getLossId() const noexcept
{
    return E;
}

TRIXY_FFNN_SERIALIZER_TPL_DECLARATION
inline function::OptimizationId TRIXY_FFNN_SERIALIZER_TPL::getOptimizationId() const noexcept
{
    return O;
}

} // namepace trixy

// clean up
#undef TRIXY_FFNN_SERIALIZER_TPL_DECLARATION
#undef TRIXY_FFNN_SERIALIZER_TPL

#endif // FFNN_SERIALIZER_HPP
