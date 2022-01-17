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
    template <class T>
    using Container      = typename Serializable::template ContainerType<T>;

    using Tensor1D       = typename Serializable::Tensor1D;
    using Tensor2D       = typename Serializable::Tensor2D;

    using precision_type = typename Serializable::precision_type;
    using size_type      = typename Serializable::size_type;

private:
    Container<size_type> topology;  ///< Network topology

    Container<Tensor1D> B;          ///< Container of network bias
    Container<Tensor2D> W;          ///< Container of network weight

    size_type N;                    ///< Number of functional layer (same as topology_size - 1)

    Container<functional::ActivationId> activation;
    functional::LossId loss;

public:
    Serializer();

    void prepare(const Serializable& net);

    void serialize(std::ofstream& out) const;
    void deserialize(std::ifstream& in);

    const Container<size_type>& getTopology() const noexcept { return topology; }
    const Container<Tensor1D>& getBias() const noexcept { return B; }
    const Container<Tensor2D>& getWeight() const noexcept { return W; }

    functional::ActivationId getActivationId() const noexcept { return activation.front(); }
    functional::ActivationId getNormalizationId() const noexcept { return activation.back(); }

    const Container<functional::ActivationId>& getEachActivationId() const noexcept { return activation; }

    functional::LossId getLossId() const noexcept { return loss; }
};

TRIXY_SERIALIZER_TPL_DECLARATION
TRIXY_SERIALIZER_TPL(meta::is_feedforward_net)::Serializer() : N(0)
{
}

TRIXY_SERIALIZER_TPL_DECLARATION
void TRIXY_SERIALIZER_TPL(meta::is_feedforward_net)::prepare(const Serializable& net)
{
    topology = net.getTopology();

    B = net.getInnerBias();
    W = net.getInnerWeight();

    N = topology.size() - 1;

    activation.resize(N);
    for(size_type i = 0; i < N; ++i)
        activation[i] = static_cast<functional::ActivationId>(net.function.getEachActivation()[i].id);

    loss = static_cast<functional::LossId>(net.function.getLoss().id);
}

TRIXY_SERIALIZER_TPL_DECLARATION
void TRIXY_SERIALIZER_TPL(meta::is_feedforward_net)::serialize(std::ofstream& out) const
{
    size_type topology_size;
    size_type n;

    topology_size = topology.size();
    out.write(reinterpret_cast<const char*>(&topology_size), sizeof(size_type));

    for(n = 0; n < topology_size; ++n)
        out.write(reinterpret_cast<const char*>(&topology[n]), sizeof(size_type));

    for(n = 0; n < N; ++n)
        out.write(reinterpret_cast<const char*>(&activation[n]), sizeof(functional::ActivationId));

    out.write(reinterpret_cast<const char*>(&loss), sizeof(functional::LossId));

    for(n = 0; n < N; ++n)
        for(size_type i = 0; i < B[n].size(); ++i)
            out.write(reinterpret_cast<const char*>(&B[n](i)), sizeof(precision_type));

    for(n = 0; n < N; ++n)
        for(size_type i = 0; i < W[n].size(); ++i)
            out.write(reinterpret_cast<const char*>(&W[n](i)), sizeof(precision_type));
}

TRIXY_SERIALIZER_TPL_DECLARATION
void TRIXY_SERIALIZER_TPL(meta::is_feedforward_net)::deserialize(std::ifstream& in)
{
    size_type topology_size;
    size_type n;

    in.read(reinterpret_cast<char*>(&topology_size), sizeof(size_type));

    topology.resize(topology_size);
    for(n = 0; n < topology_size; ++n)
        in.read(reinterpret_cast<char*>(&topology[n]), sizeof(size_type));

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
        in.read(reinterpret_cast<char*>(&activation[n]), sizeof(functional::ActivationId));

    in.read(reinterpret_cast<char*>(&loss), sizeof(functional::LossId));

    for(n = 0; n < N; ++n)
        for(size_type i = 0; i < B[n].size(); ++i)
            in.read(reinterpret_cast<char*>(&B[n](i)), sizeof(precision_type));

    for(n = 0; n < N; ++n)
        for(size_type i = 0; i < W[n].size(); ++i)
            in.read(reinterpret_cast<char*>(&W[n](i)), sizeof(precision_type));
}

} // namespace trixy

#include "Trixy/Neuro/Detail/MacroUnscope.hpp"

#endif // FEED_FORWARD_NET_SERIALIZER_HPP
