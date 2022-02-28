#ifndef FEED_FORWARD_NET_SERIALIZER_HPP
#define FEED_FORWARD_NET_SERIALIZER_HPP

#include <fstream> // ifstream, ofstream

#include "Trixy/Neuro/Serialization/BaseSerializer.hpp"

#include "Trixy/Neuro/Detail/TrixyNetMeta.hpp"
#include "Trixy/Neuro/Detail/FunctionDetail.hpp"

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

    AllActivationId activationId;   ///< Network activation functions id
    LossId lossId;                  ///< Network loss function id

    size_type N;                    ///< Number of functional layer (same as topology_size - 1)

public:
    Serializer() : N(0) {}

    void prepare(const Serializable& net);

    void serialize(std::ofstream& out) const;
    void serialize(std::ofstream& out, const Serializable& net) const;

    void deserialize(std::ifstream& in);

    const Container<size_type>& getTopology() const noexcept { return topology; }
    const Container<Vector>& getBias() const noexcept { return B; }
    const Container<Matrix>& getWeight() const noexcept { return W; }

    ActivationId getActivationId() const noexcept { return activationId.front(); }
    ActivationId getNormalizationId() const noexcept { return activationId.back(); }

    const AllActivationId& getAllActivationId() const noexcept { return activationId; }

    LossId getLossId() const noexcept { return lossId; }

private:
    template <typename Data>
    static void serializeData(
        std::ofstream& out, const Data* beg, size_type size
    );

    template <typename Data>
    static void deserializeData(
        std::ifstream& in, Data* beg, size_type size
    );
};

TRIXY_SERIALIZER_TPL_DECLARATION
void TRIXY_SERIALIZER_TPL(meta::is_feedforward_net)::prepare(const Serializable& net)
{
    topology = net.inner.topology;

    N = topology.size() - 1;

    B.resize(N);
    W.resize(N);

    for(size_type i = 0; i < N; ++i)
    {
        B[i].resize(
            net.inner.B[i].size(),
            net.inner.B[i].data()
        );

        W[i].resize(
            net.inner.W[i].shape(),
            net.inner.W[i].data()
        );
    }

    activationId = net.function.getAllActivationId();
    lossId = net.function.getLossId();
}

TRIXY_SERIALIZER_TPL_DECLARATION
void TRIXY_SERIALIZER_TPL(meta::is_feedforward_net)::serialize(std::ofstream& out) const
{
    size_type n = topology.size();

    serializeData(out, &n, 1);
    serializeData(out, topology.data(), topology.size());

    serializeData(out, activationId.data(), activationId.size());
    serializeData(out, &lossId, 1);

    for(auto& tensor : B)
        serializeData(out, tensor.data(), tensor.size());

    for(auto& tensor : W)
        serializeData(out, tensor.data(), tensor.size());
}

TRIXY_SERIALIZER_TPL_DECLARATION
void TRIXY_SERIALIZER_TPL(meta::is_feedforward_net)::serialize(
    std::ofstream& out, const Serializable& net) const
{
    size_type n = net.inner.topology.size();

    serializeData(out, &n, 1);

    serializeData(
        out,
        net.inner.topology.data(),
        net.inner.topology.size()
    );

    serializeData(
        out,
        net.function.getAllActivationId().data(),
        net.function.getAllActivationId().size()
    );

    serializeData(out, &net.function.getLossId(), 1);

    for(auto& tensor : net.inner.B)
        serializeData(out, tensor.data(), tensor.size());

    for(auto& tensor : net.inner.W)
        serializeData(out, tensor.data(), tensor.size());
}

TRIXY_SERIALIZER_TPL_DECLARATION
void TRIXY_SERIALIZER_TPL(meta::is_feedforward_net)::deserialize(std::ifstream& in)
{
    size_type n;

    deserializeData(in, &n, 1);

    topology.resize(n);

    deserializeData(in, topology.data(), topology.size());

    N = n - 1;

    activationId.resize(N);
    B.resize(N);
    W.resize(N);

    for(n = 0; n < N; ++n)
    {
        B[n].resize(topology[n + 1]);
        W[n].resize(topology[n], topology[n + 1]);
    }

    deserializeData(in, activationId.data(), activationId.size());
    deserializeData(in, &lossId, 1);

    for(auto& tensor : B)
        deserializeData(in, tensor.data(), tensor.size());

    for(auto& tensor : W)
        deserializeData(in, tensor.data(), tensor.size());
}

TRIXY_SERIALIZER_TPL_DECLARATION
template <typename Data>
void TRIXY_SERIALIZER_TPL(meta::is_feedforward_net)::serializeData(
    std::ofstream& out, const Data* beg, size_type size)
{
    out.write(reinterpret_cast<const char*>(beg), sizeof(*beg) * size);
}

TRIXY_SERIALIZER_TPL_DECLARATION
template <typename Data>
void TRIXY_SERIALIZER_TPL(meta::is_feedforward_net)::deserializeData(
    std::ifstream& in, Data* beg, size_type size)
{
    in.read(reinterpret_cast<char*>(beg), sizeof(*beg) * size);
}

} // namespace trixy

#include "Trixy/Neuro/Detail/MacroUnscope.hpp"

#endif // FEED_FORWARD_NET_SERIALIZER_HPP
