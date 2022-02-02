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
private:
    template <class... T>
    using Container                 = typename Serializable::template Container<T...>;

    using Vector                    = typename Serializable::Vector;
    using Matrix                    = typename Serializable::Matrix;

    using InnerTopology             = typename Serializable::InnerTopology;

    using precision_type            = typename Serializable::precision_type;
    using size_type                 = typename Serializable::size_type;
    using byte_type                 = typename Serializable::byte_type;

    using ActivationId              = functional::ActivationId;
    using LossId                    = functional::LossId;

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
    void deserialize(std::ifstream& in);

    const Container<size_type>& getTopology() const noexcept { return topology; }
    const Container<Vector>& getBias() const noexcept { return B; }
    const Container<Matrix>& getWeight() const noexcept { return W; }

    ActivationId getActivationId() const noexcept { return activation.front(); }
    ActivationId getNormalizationId() const noexcept { return activation.back(); }

    const Container<ActivationId>& getAllActivationId() const noexcept { return activation; }

    LossId getLossId() const noexcept { return loss; }
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
        B[i].resize(topology[i + 1], net.inner.B[i].data());
        W[i].resize(topology[i], topology[i + 1], net.inner.W[i].data());
    }

    for(size_type i = 0; i < N; ++i)
        activation[i] = static_cast<ActivationId>(net.function.getAllActivation()[i].id);

    loss = static_cast<LossId>(net.function.getLoss().id);
}

TRIXY_SERIALIZER_TPL_DECLARATION
void TRIXY_SERIALIZER_TPL(meta::is_feedforward_net)::serialize(std::ofstream& out) const
{
    size_type topology_size;
    size_type n;

    topology_size = topology.size();
    out.write(CONST_BYTE_CAST(&topology_size), sizeof(size_type));

    for(n = 0; n < topology_size; ++n)
        out.write(CONST_BYTE_CAST(&topology[n]), sizeof(size_type));

    for(n = 0; n < N; ++n)
        out.write(CONST_BYTE_CAST(&activation[n]), sizeof(byte_type));

    out.write(CONST_BYTE_CAST(&loss), sizeof(byte_type));

    for(n = 0; n < N; ++n)
        for(size_type i = 0; i < B[n].size(); ++i)
            out.write(CONST_BYTE_CAST(&B[n](i)), sizeof(precision_type));

    for(n = 0; n < N; ++n)
        for(size_type i = 0; i < W[n].size(); ++i)
            out.write(CONST_BYTE_CAST(&W[n](i)), sizeof(precision_type));
}

TRIXY_SERIALIZER_TPL_DECLARATION
void TRIXY_SERIALIZER_TPL(meta::is_feedforward_net)::deserialize(std::ifstream& in)
{
    size_type topology_size;
    size_type n;

    in.read(BYTE_CAST(&topology_size), sizeof(size_type));

    topology.resize(topology_size);
    for(n = 0; n < topology_size; ++n)
        in.read(BYTE_CAST(&topology[n]), sizeof(size_type));

    N = topology_size - 1;

    activation.resize(N);
    B.resize(N);
    W.resize(N);

    for(n = 0; n < N; ++n)
    {
        B[n].resize(topology[n + 1]);
        W[n].resize(topology[n], topology[n + 1]);
    }

    for(n = 0; n < N; ++n)
        in.read(BYTE_CAST(&activation[n]), sizeof(byte_type));

    in.read(BYTE_CAST(&loss), sizeof(byte_type));

    for(n = 0; n < N; ++n)
        for(size_type i = 0; i < B[n].size(); ++i)
            in.read(BYTE_CAST(&B[n](i)), sizeof(precision_type));

    for(n = 0; n < N; ++n)
        for(size_type i = 0; i < W[n].size(); ++i)
            in.read(BYTE_CAST(&W[n](i)), sizeof(precision_type));
}

} // namespace trixy

#include "Trixy/Neuro/Detail/MacroUnscope.hpp"

#endif // FEED_FORWARD_NET_SERIALIZER_HPP
