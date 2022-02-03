#ifndef FEED_FORWARD_NET_SERIALIZER_HPP
#define FEED_FORWARD_NET_SERIALIZER_HPP

#include <fstream> // ifstream, ofstream

#include "Trixy/Neuro/Serialization/BaseSerializer.hpp"
#include "Trixy/Neuro/Functional/IdFunctional.hpp"
#include "Trixy/Neuro/Detail/TrixyNetMeta.hpp"

#include "Trixy/Neuro/Detail/MacroScope.hpp"


namespace trixy
{

TRIXY_SERIALIZER_TPL_DECLARATION
class TRIXY_SERIALIZER_TPL(meta::is_feedforward_net)
{
public:
    template <class... T>
    using Container                 = typename Serializable::template Container<T...>;

    using Vector                    = typename Serializable::Vector;
    using Matrix                    = typename Serializable::Matrix;

    using InnerTopology             = typename Serializable::InnerTopology;

    using precision_type            = typename Serializable::precision_type;
    using size_type                 = typename Serializable::size_type;

    using ActivationId              = typename Serializable::ActivationId;
    using LossId                    = typename Serializable::LossId;

    using AllActivationId           = Container<ActivationId>;

private:
    InnerTopology topology;         ///< Network topology

    Container<Vector> B;            ///< Container of network bias
    Container<Matrix> W;            ///< Container of network weight

    size_type N;                    ///< Number of functional layer (same as topology_size - 1)

    AllActivationId activation;     ///< Network activation functions id
    LossId loss;                    ///< Network loss function id

public:
    Serializer() : N(0) {}

    void prepare(const Serializable& net);

    void serialize(std::ofstream& out) const;
    void serialize(std::ofstream& out, const Serializable& net) const;

    void deserialize(std::ifstream& in);

    const Container<size_type>& getTopology() const noexcept { return topology; }
    const Container<Vector>& getBias() const noexcept { return B; }
    const Container<Matrix>& getWeight() const noexcept { return W; }

    ActivationId getActivationId() const noexcept { return activation.front(); }
    ActivationId getNormalizationId() const noexcept { return activation.back(); }

    const AllActivationId& getAllActivationId() const noexcept { return activation; }

    LossId getLossId() const noexcept { return loss; }

private:
    template <class Tensor>
    static void serializeTensor(const Tensor& tensor, std::ofstream& out, size_type offset);

    template <class Tensor>
    static void deserializeTensor(Tensor& tensor, std::ifstream& in, size_type offset);
};

TRIXY_SERIALIZER_TPL_DECLARATION
void TRIXY_SERIALIZER_TPL(meta::is_feedforward_net)::prepare(const Serializable& net)
{
    topology = net.inner.topology;

    N = topology.size() - 1;

    B.resize(N);
    W.resize(N);
    activation.resize(N);

    for(size_type i = 0; i < N; ++i)
    {
        B[i].resize(net.inner.B[i].size(), net.inner.B[i].data());
        W[i].resize(net.inner.W[i].shape(), net.inner.W[i].data());
    }

    activation = net.function.getAllActivationId();
    loss = net.function.getLossId();
}

TRIXY_SERIALIZER_TPL_DECLARATION
void TRIXY_SERIALIZER_TPL(meta::is_feedforward_net)::serialize(std::ofstream& out) const
{
    size_type n = topology.size();
    out.write(CONST_BYTE_CAST(&n), sizeof(size_type));

    serializeTensor(topology, out, sizeof(size_type));

    serializeTensor(activation, out, sizeof(ActivationId));

    out.write(CONST_BYTE_CAST(&loss), sizeof(LossId));

    for(auto& tensor : B)
        serializeTensor(tensor, out, sizeof(precision_type));

    for(auto& tensor : W)
        serializeTensor(tensor, out, sizeof(precision_type));
}

TRIXY_SERIALIZER_TPL_DECLARATION
void TRIXY_SERIALIZER_TPL(meta::is_feedforward_net)::serialize(
    std::ofstream& out, const Serializable& net) const
{
    size_type n = net.inner.topology.size();
    out.write(CONST_BYTE_CAST(&n), sizeof(size_type));

    serializeTensor(net.inner.topology, out, sizeof(size_type));

    serializeTensor(net.function.getAllActivationId(), out, sizeof(ActivationId));

    out.write(CONST_BYTE_CAST(&net.function.getLossId()), sizeof(LossId));

    for(auto& tensor : net.inner.B)
        serializeTensor(tensor, out, sizeof(precision_type));

    for(auto& tensor : net.inner.W)
        serializeTensor(tensor, out, sizeof(precision_type));
}

TRIXY_SERIALIZER_TPL_DECLARATION
void TRIXY_SERIALIZER_TPL(meta::is_feedforward_net)::deserialize(std::ifstream& in)
{
    size_type n;

    in.read(BYTE_CAST(&n), sizeof(size_type));

    topology.resize(n);

    deserializeTensor(topology, in, sizeof(size_type));

    N = n - 1;

    activation.resize(N);
    B.resize(N);
    W.resize(N);

    for(n = 0; n < N; ++n)
    {
        B[n].resize(topology[n + 1]);
        W[n].resize(topology[n], topology[n + 1]);
    }

    deserializeTensor(activation, in, sizeof(ActivationId));

    in.read(BYTE_CAST(&loss), sizeof(LossId));

    for(auto& tensor : B)
        deserializeTensor(tensor, in, sizeof(precision_type));

    for(auto& tensor : W)
        deserializeTensor(tensor, in, sizeof(precision_type));
}

TRIXY_SERIALIZER_TPL_DECLARATION
template <class Tensor>
void TRIXY_SERIALIZER_TPL(meta::is_feedforward_net)::serializeTensor(
    const Tensor& tensor, std::ofstream& out, size_type offset)
{
    auto beg = tensor.data();
    auto end = tensor.data() + tensor.size();

    while(beg != end)
    {
        out.write(CONST_BYTE_CAST(beg), offset);
        ++beg;
    }
}

TRIXY_SERIALIZER_TPL_DECLARATION
template <class Tensor>
void TRIXY_SERIALIZER_TPL(meta::is_feedforward_net)::deserializeTensor(
    Tensor& tensor, std::ifstream& in, size_type offset)
{
    auto beg = tensor.data();
    auto end = tensor.data() + tensor.size();

    while(beg != end)
    {
        in.read(BYTE_CAST(beg), offset);
        ++beg;
    }
}

} // namespace trixy

#include "Trixy/Neuro/Detail/MacroUnscope.hpp"

#endif // FEED_FORWARD_NET_SERIALIZER_HPP
