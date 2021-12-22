#ifndef FEEDFORWARD_NEURO_SERIALIZER_HPP
#define FEEDFORWARD_NEURO_SERIALIZER_HPP

#include "../Detail/neuro_function_id.hpp"
#include "../Detail/neuro_meta.hpp"

#include "base_serializer.hpp"

#include <fstream> // ifstream, ofstream

#define TRIXY_FEED_FORWARD_NEURO_SERIALIZER_TPL                              \
    Serializer<NeuralNetwork,                                                \
        meta::enable_if_t<meta::is_feedforward_neuro<NeuralNetwork>::value>>

namespace trixy
{

template <class NeuralNetwork>
class Serializer<NeuralNetwork, meta::enable_if_t<meta::is_feedforward_neuro<NeuralNetwork>::value>>
{
private:
    template <class T>
    using Container      = typename NeuralNetwork::template ContainerType<T>;

    using Tensor1D       = typename NeuralNetwork::Tensor1D;
    using Tensor2D       = typename NeuralNetwork::Tensor2D;

    using precision_type = typename NeuralNetwork::precision_type;
    using size_type      = typename NeuralNetwork::size_type;

private:
    Container<size_type> topology;

    Container<Tensor1D> B;
    Container<Tensor2D> W;

    size_type N;

    Container<function::ActivationId> activation;
    function::LossId loss;
    function::OptimizationId optimization;

public:
    Serializer();

    void prepare(const NeuralNetwork& net);

    void serialize(std::ofstream& out) const;
    void deserialize(std::ifstream& in);

    const Container<size_type>& getTopology() const noexcept { return topology; }
    const Container<Tensor1D>& getBias() const noexcept { return B; }
    const Container<Tensor2D>& getWeight() const noexcept { return W; }

    function::ActivationId getActivationId() const noexcept { return activation[0]; }
    function::ActivationId getNormalizationId() const noexcept { return activation[N - 1]; }

    const Container<function::ActivationId>& getEachActivationId() const noexcept { return activation; }

    function::LossId getLossId() const noexcept { return loss; }
    function::OptimizationId getOptimizationId() const noexcept { return optimization; }
};

template <typename NeuralNetwork>
TRIXY_FEED_FORWARD_NEURO_SERIALIZER_TPL::Serializer()
    : N(0)
    , loss(function::LossId::undefined)
    , optimization(function::OptimizationId::undefined)
{
}

template <typename NeuralNetwork>
void TRIXY_FEED_FORWARD_NEURO_SERIALIZER_TPL::prepare(const NeuralNetwork& net)
{
    topology = net.getTopology();

    B = net.getInnerBias();
    W = net.getInnerWeight();

    N = topology.size() - 1;

    activation.resize(N);
    for(size_type i = 0; i < N; ++i)
        activation[i] = static_cast<function::ActivationId>(net.function.getEachActivation()[i].id);

    loss = static_cast<function::LossId>(net.function.getLoss().id);
    optimization = static_cast<function::OptimizationId>(net.function.getOptimization().id);
}

template <typename NeuralNetwork>
void TRIXY_FEED_FORWARD_NEURO_SERIALIZER_TPL::serialize(std::ofstream& out) const
{
    size_type topology_size;
    size_type n;

    topology_size = topology.size();
    out.write(reinterpret_cast<const char*>(&topology_size), sizeof(size_type));

    for(n = 0; n < topology_size; ++n)
        out.write(reinterpret_cast<const char*>(&topology[n]), sizeof(size_type));

    for(n = 0; n < N; ++n)
        out.write(reinterpret_cast<const char*>(&activation[n]), sizeof(function::ActivationId));

    out.write(reinterpret_cast<const char*>(&loss), sizeof(function::LossId));
    out.write(reinterpret_cast<const char*>(&optimization), sizeof(function::OptimizationId));

    for(n = 0; n < N; ++n)
        for(size_type i = 0; i < B[n].size(); ++i)
            out.write(reinterpret_cast<const char*>(&B[n](i)), sizeof(precision_type));

    for(n = 0; n < N; ++n)
        for(size_type i = 0; i < W[n].size().row(); ++i)
            for(size_type j = 0; j < W[n].size().col(); ++j)
                out.write(reinterpret_cast<const char*>(&W[n](i, j)), sizeof(precision_type));
}

template <typename NeuralNetwork>
void TRIXY_FEED_FORWARD_NEURO_SERIALIZER_TPL::deserialize(std::ifstream& in)
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
        in.read(reinterpret_cast<char*>(&activation[n]), sizeof(function::ActivationId));

    in.read(reinterpret_cast<char*>(&loss), sizeof(function::LossId));
    in.read(reinterpret_cast<char*>(&optimization), sizeof(function::OptimizationId));

    for(n = 0; n < N; ++n)
        for(size_type i = 0; i < B[n].size(); ++i)
            in.read(reinterpret_cast<char*>(&B[n](i)), sizeof(precision_type));

    for(n = 0; n < N; ++n)
        for(size_type i = 0; i < W[n].size().row(); ++i)
            for(size_type j = 0; j < W[n].size().col(); ++j)
                in.read(reinterpret_cast<char*>(&W[n](i, j)), sizeof(precision_type));
}

} // namepace trixy

// clean up
#undef TRIXY_FEED_FORWARD_NEURO_SERIALIZER_TPL

#endif // FEED_FORWARD_NEURO_SERIALIZER_HPP
