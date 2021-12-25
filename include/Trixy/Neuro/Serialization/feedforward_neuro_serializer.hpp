#ifndef FEEDFORWARD_NEURO_SERIALIZER_HPP
#define FEEDFORWARD_NEURO_SERIALIZER_HPP

#include <fstream> // ifstream, ofstream

#include "base_serializer.hpp"
#include "Trixy/Neuro/Detail/neuro_function_id.hpp"
#include "Trixy/Neuro/Detail/neuro_meta.hpp"

#include "Trixy/Neuro/Detail/macro_scope.hpp"

namespace trixy
{

TRIXY_SERIALIZER_TPL_DECLARATION
class TRIXY_SERIALIZER_TPL(meta::is_feedforward_neuro)
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

    Container<function::ActivationId> activation;
    function::LossId loss;
    function::OptimizationId optimization;

public:
    Serializer();

    void prepare(const Serializable& net);

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

TRIXY_SERIALIZER_TPL_DECLARATION
TRIXY_SERIALIZER_TPL(meta::is_feedforward_neuro)::Serializer()
    : N(0)
    , loss(function::LossId::undefined)
    , optimization(function::OptimizationId::undefined)
{
}

TRIXY_SERIALIZER_TPL_DECLARATION
void TRIXY_SERIALIZER_TPL(meta::is_feedforward_neuro)::prepare(const Serializable& net)
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

TRIXY_SERIALIZER_TPL_DECLARATION
void TRIXY_SERIALIZER_TPL(meta::is_feedforward_neuro)::serialize(std::ofstream& out) const
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

TRIXY_SERIALIZER_TPL_DECLARATION
void TRIXY_SERIALIZER_TPL(meta::is_feedforward_neuro)::deserialize(std::ifstream& in)
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

} // namespace trixy

#include "Trixy/Neuro/Detail/macro_unscope.hpp"

#endif // FEEDFORWARD_NEURO_SERIALIZER_HPP
