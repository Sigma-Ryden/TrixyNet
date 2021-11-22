#ifndef NEURO_SERIALIZER_HPP
#define NEURO_SERIALIZER_HPP

#include <cstddef> // size_t
#include <fstream> // ifstream, ofstream

namespace trixy
{

template <template <typename, typename...> class Vector,
          template <typename, typename...> class Matrix,
          template <typename...> class Container,
          typename Precision, typename... Args>
class NeuroSerializer;

} // namespace trixy

#define TRIXY_NEURO_SERIALIZER_TPL_DECLARATION               \
    template <template <typename, typename...> class Vector, \
              template <typename, typename...> class Matrix, \
              template <typename...> class Container,        \
              typename Precision, typename... Args>

#define TRIXY_NEURO_SERIALIZER_TPL                           \
    NeuroSerializer<Vector, Matrix,                          \
        Container, Precision, Args...>

namespace trixy
{

TRIXY_NEURO_SERIALIZER_TPL_DECLARATION
class NeuroSerializer
{
public:
    using Tensor1D  = Vector<Precision, Args...>;
    using Tensor2D  = Matrix<Precision, Args...>;
    using size_type = std::size_t;

private:
    Container<size_type> topology;
    Container<Tensor1D> B;
    Container<Tensor2D> W;

public:
    NeuroSerializer() = default;

    void prepare(const Container<Tensor1D>& bias,
                 const Container<Tensor2D>& weight);

    void serialize(std::ofstream& out) const;
    void deserialize(std::ifstream& in);

    const Container<size_type>& getTopology() const noexcept;
    const Container<Tensor1D>& getBias() const noexcept;
    const Container<Tensor2D>& getWeight() const noexcept;
};

TRIXY_NEURO_SERIALIZER_TPL_DECLARATION
void TRIXY_NEURO_SERIALIZER_TPL::prepare(
    const Container<Tensor1D>& bias,
    const Container<Tensor2D>& weight)
{
    topology.resize(weight.size() + 1);

    topology[0] = weight[0].size().row();
    for(size_type i = 1; i < topology.size(); ++i)
        topology[i] = weight[i - 1].size().col();

    B = bias;
    W = weight;
}

TRIXY_NEURO_SERIALIZER_TPL_DECLARATION
void TRIXY_NEURO_SERIALIZER_TPL::serialize(std::ofstream& out) const
{
    size_type topology_size = topology.size();
    out.write(reinterpret_cast<const char*>(&topology_size), sizeof(size_type));

    for(size_type n = 0; n < topology.size(); ++n)
        out.write(reinterpret_cast<const char*>(&topology[n]), sizeof(size_type));

    for(size_type n = 0; n < B.size(); ++n)
        for(size_type i = 0; i < B[n].size(); ++i)
            out.write(reinterpret_cast<const char*>(&B[n](i)), sizeof(Precision));

    for(size_type n = 0; n < W.size(); ++n)
        for(size_type i = 0; i < W[n].size().row(); ++i)
            for(size_type j = 0; j < W[n].size().col(); ++j)
                out.write(reinterpret_cast<const char*>(&W[n](i, j)), sizeof(Precision));
}

TRIXY_NEURO_SERIALIZER_TPL_DECLARATION
void TRIXY_NEURO_SERIALIZER_TPL::deserialize(std::ifstream& in)
{
    size_type topology_size;
    in.read(reinterpret_cast<char*>(&topology_size), sizeof(size_type));

    topology.resize(topology_size);
    for(size_type n = 0; n < topology_size; ++n)
        in.read(reinterpret_cast<char*>(&topology[n]), sizeof(size_type));

    B.resize(topology_size - 1);
    W.resize(topology_size - 1);

    for(size_type n = 0; n < B.size(); ++n)
    {
        B[n].resize(topology[n + 1]);
        W[n].resize(topology[n], topology[n + 1]);
    }

    for(size_type n = 0; n < B.size(); ++n)
        for(size_type i = 0; i < B[n].size(); ++i)
            in.read(reinterpret_cast<char*>(&B[n](i)), sizeof(Precision));

    for(size_type n = 0; n < W.size(); ++n)
        for(size_type i = 0; i < W[n].size().row(); ++i)
            for(size_type j = 0; j < W[n].size().col(); ++j)
                in.read(reinterpret_cast<char*>(&W[n](i, j)), sizeof(Precision));
}

TRIXY_NEURO_SERIALIZER_TPL_DECLARATION
inline const Container<std::size_t>&
    TRIXY_NEURO_SERIALIZER_TPL::getTopology() const noexcept
{
    return topology;
}

TRIXY_NEURO_SERIALIZER_TPL_DECLARATION
inline const Container<Vector<Precision, Args...>>&
    TRIXY_NEURO_SERIALIZER_TPL::getBias() const noexcept
{
    return B;
}

TRIXY_NEURO_SERIALIZER_TPL_DECLARATION
inline const Container<Matrix<Precision, Args...>>&
    TRIXY_NEURO_SERIALIZER_TPL::getWeight() const noexcept
{
    return W;
}

} // namespace trixy

// clean up
#undef TRIXY_NEURO_SERIALIZER_TPL_DECLARATION
#undef TRIXY_NEURO_SERIALIZER_TPL

#endif // NEURO_SERIALIZER_HPP
