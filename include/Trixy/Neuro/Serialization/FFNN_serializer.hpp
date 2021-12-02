#ifndef FFNN_SERIALIZER_HPP
#define FFNN_SERIALIZER_HPP

#include "../Detail/neuro_function_id.hpp"
#include "../Detail/neuro_meta.hpp"

#include "base_serializer.hpp"

#include <fstream> // ifstream, ofstream

#define TRIXY_FFNN_SERIALIZER_TPL                                           \
    Serializer<Neuro,                                                       \
               meta::enable_if_t<meta::is_feedforward_neuro<Neuro>::value>>

namespace trixy
{

template <class Neuro>
class Serializer<Neuro, meta::enable_if_t<meta::is_feedforward_neuro<Neuro>::value>>
{
private:
    template <class T>
    using Container = typename Neuro::template ContainerType<T>;

    using Tensor1D  = typename Neuro::Tensor1D;
    using Tensor2D  = typename Neuro::Tensor2D;

    using precision_type = typename Neuro::precision_type;
    using size_type      = typename Neuro::size_type;

private:
    Container<size_type> T;

    Container<Tensor1D> B;
    Container<Tensor2D> W;

    size_type N;

    Container<function::ActivationId> A;
    function::LossId E;
    function::OptimizationId O;

public:
    Serializer() : N(0), E(function::LossId::undefined), O(function::OptimizationId::undefined) {}

    void prepare(const Neuro& net);

    void serialize(std::ofstream& out) const;
    void deserialize(std::ifstream& in);

    const Container<size_type>& getTopology() const noexcept { return T; }
    const Container<Tensor1D>& getBias() const noexcept { return B; }
    const Container<Tensor2D>& getWeight() const noexcept { return W; }

    function::ActivationId getActivationId() const noexcept { return A[0]; }
    function::ActivationId getNormalizationId() const noexcept { return A[N - 1]; }

    const Container<function::ActivationId>& getEachActivationId() const noexcept { return A; }

    function::LossId getLossId() const noexcept { return E; }
    function::OptimizationId getOptimizationId() const noexcept { return O; }
};

template <typename Neuro>
void TRIXY_FFNN_SERIALIZER_TPL::prepare(const Neuro& net)
{
    T = net.getTopology();

    B = net.getInnerBias();
    W = net.getInnerWeight();

    N = T.size() - 1;

    A.resize(N);
    for(size_type i = 0; i < N; ++i)
        A[i] = static_cast<function::ActivationId>(net.function.getEachActivation()[i].id);

    E = static_cast<function::LossId>(net.function.getLoss().id);
    O = static_cast<function::OptimizationId>(net.function.getOptimization().id);
}

template <typename Neuro>
void TRIXY_FFNN_SERIALIZER_TPL::serialize(std::ofstream& out) const
{
    static size_type topology_size;

    topology_size = T.size();
    out.write(reinterpret_cast<const char*>(&topology_size), sizeof(size_type));

    for(size_type n = 0; n < topology_size; ++n)
        out.write(reinterpret_cast<const char*>(&T[n]), sizeof(size_type));

    for(size_type n = 0; n < N; ++n)
        out.write(reinterpret_cast<const char*>(&A[n]), sizeof(function::ActivationId));

    out.write(reinterpret_cast<const char*>(&E), sizeof(function::LossId));
    out.write(reinterpret_cast<const char*>(&O), sizeof(function::OptimizationId));

    for(size_type n = 0; n < N; ++n)
        for(size_type i = 0; i < B[n].size(); ++i)
            out.write(reinterpret_cast<const char*>(&B[n](i)), sizeof(precision_type));

    for(size_type n = 0; n < N; ++n)
        for(size_type i = 0; i < W[n].size().row(); ++i)
            for(size_type j = 0; j < W[n].size().col(); ++j)
                out.write(reinterpret_cast<const char*>(&W[n](i, j)), sizeof(precision_type));
}

template <typename Neuro>
void TRIXY_FFNN_SERIALIZER_TPL::deserialize(std::ifstream& in)
{
    static size_type topology_size;

    in.read(reinterpret_cast<char*>(&topology_size), sizeof(size_type));

    T.resize(topology_size);
    for(size_type n = 0; n < topology_size; ++n)
        in.read(reinterpret_cast<char*>(&T[n]), sizeof(size_type));

    N = topology_size - 1;

    A.resize(N);
    B.resize(N);
    W.resize(N);

    for(size_type n = 0; n < N; ++n)
    {
        B[n].resize(T[n + 1]);
        W[n].resize(T[n], T[n + 1]);
    }

    for(size_type n = 0; n < N; ++n)
        in.read(reinterpret_cast<char*>(&A[n]), sizeof(function::ActivationId));

    in.read(reinterpret_cast<char*>(&E), sizeof(function::LossId));
    in.read(reinterpret_cast<char*>(&O), sizeof(function::OptimizationId));

    for(size_type n = 0; n < N; ++n)
        for(size_type i = 0; i < B[n].size(); ++i)
            in.read(reinterpret_cast<char*>(&B[n](i)), sizeof(precision_type));

    for(size_type n = 0; n < N; ++n)
        for(size_type i = 0; i < W[n].size().row(); ++i)
            for(size_type j = 0; j < W[n].size().col(); ++j)
                in.read(reinterpret_cast<char*>(&W[n](i, j)), sizeof(precision_type));
}

} // namepace trixy

// clean up
#undef TRIXY_FFNN_SERIALIZER_TPL

#endif // FFNN_SERIALIZER_HPP
