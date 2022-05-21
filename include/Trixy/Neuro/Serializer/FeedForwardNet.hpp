#ifndef TRIXY_SERIALIZER_FEED_FORWARD_NET_HPP
#define TRIXY_SERIALIZER_FEED_FORWARD_NET_HPP

#include <cstdint> // int8_t, int32_t

#include <Trixy/Neuro/Serializer/Base.hpp>

#include <Trixy/Buffer/Core.hpp>

#include <Trixy/Detail/TrixyMeta.hpp>
#include <Trixy/Detail/FunctionDetail.hpp>

#include <Trixy/Neuro/Detail/TrixyNetMeta.hpp>

#include <Trixy/Neuro/Detail/MacroScope.hpp>

namespace trixy
{

TRIXY_SERIALIZER_TPL_DECLARATION
class TRIXY_SERIALIZER_TPL(meta::is_feedforward_net)
{
public:
    using Net = Serializable;

    template <class T>
    using Container                 = typename Net::template Container<T>;

    using Vector                    = typename Net::Vector;
    using Matrix                    = typename Net::Matrix;

    using InnerTopology             = typename Net::InnerTopology;

    using precision_type            = typename Net::precision_type;
    using size_type                 = typename Net::size_type;

    using ActivationId              = typename Net::ActivationId;
    using LossId                    = typename Net::LossId;

    using AllActivationId           = Container<ActivationId>;

private:
    using meta_data_type            = std::int32_t;
    using byte_type                 = std::int8_t;

    using BaseId                    = Buffer::BaseTypeId;

private:
    Buffer buff;                    ///< Specialized Buffer for casting stream data

    InnerTopology topology;         ///< Network topology (main meta data for construction)

    Container<Vector> B;            ///< Container of network bias
    Container<Matrix> W;            ///< Container of network weight

    AllActivationId activationId;   ///< Network activation functions id
    LossId lossId;                  ///< Network loss function id

    size_type N;                    ///< Number of functional layer (same as topology_size - 1)

    meta_data_type meta;            ///< 4 bytes of meta data for hold type information

public:
    Serializer() : buff(), N(0), meta(0) {}

    void prepare(const Net& net);

    template <class OutStream>
    void serialize(OutStream& out) const;

    template <class OutStream>
    void serialize(OutStream& out, const Net& net) const;

    template <class InStream>
    void deserialize(InStream& in);

    const Container<size_type>& getTopology() const noexcept { return topology; }
    const Container<Vector>& getBias() const noexcept { return B; }
    const Container<Matrix>& getWeight() const noexcept { return W; }

    ActivationId getActivationId() const noexcept { return activationId.front(); }
    ActivationId getNormalizationId() const noexcept { return activationId.back(); }

    const AllActivationId& getAllActivationId() const noexcept { return activationId; }

    LossId getLossId() const noexcept { return lossId; }

private:
    constexpr static meta_data_type getBaseMetaData() noexcept;

    template <class OutStream, typename InData>
    static void serializeData(OutStream& out, InData data, size_type n);

    template <class InStream, typename OutData>
    void deserializeData(InStream& in, OutData data, size_type n, bool buffering);
};

TRIXY_SERIALIZER_TPL_DECLARATION
void TRIXY_SERIALIZER_TPL(meta::is_feedforward_net)::prepare(const Net& net)
{
    topology = net.inner.topology;

    N = topology.size() - 1;

    B.resize(N);
    W.resize(N);

    for (size_type i = 0; i < N; ++i)
    {
        B[i].resize(net.inner.B[i].shape());
        B[i].copy(net.inner.B[i].data());

        W[i].resize(net.inner.W[i].shape());
        B[i].copy(net.inner.W[i].data());
    }

    activationId = net.function.activationIdSet();
    lossId = net.function.lossId();
}

TRIXY_SERIALIZER_TPL_DECLARATION
template <class OutStream>
void TRIXY_SERIALIZER_TPL(meta::is_feedforward_net)::serialize(OutStream& out) const
{
    meta_data_type xmeta = getBaseMetaData();
    out.write(detail::const_byte_cast(&xmeta), 4); // writing 4 bytes of meta data

    size_type topology_size = topology.size();
    serializeData(out, &topology_size, 1);

    serializeData(out, topology.data(), topology.size());

    serializeData(out, activationId.data(), activationId.size());
    serializeData(out, &lossId, 1);

    for (auto& tensor : B)
        serializeData(out, tensor.data(), tensor.size());

    for (auto& tensor : W)
        serializeData(out, tensor.data(), tensor.size());
}

TRIXY_SERIALIZER_TPL_DECLARATION
template <class OutStream>
void TRIXY_SERIALIZER_TPL(meta::is_feedforward_net)::serialize(
    OutStream& out, const Net& net) const
{
    meta_data_type xmeta = getBaseMetaData();
    out.write(detail::const_byte_cast(&xmeta), 4); // writing 4 bytes of meta data

    size_type topology_size = net.inner.topology.size();
    serializeData(out, &topology_size, 1);

    serializeData(
        out,
        net.inner.topology.data(),
        net.inner.topology.size()
    );

    serializeData(
        out,
        net.function.activationIdSet().data(),
        net.function.activationIdSet().size()
    );

    serializeData(out, &net.function.lossId(), 1);

    for (auto& tensor : net.inner.B)
        serializeData(out, tensor.data(), tensor.size());

    for (auto& tensor : net.inner.W)
        serializeData(out, tensor.data(), tensor.size());
}

TRIXY_SERIALIZER_TPL_DECLARATION
template <class InStream>
void TRIXY_SERIALIZER_TPL(meta::is_feedforward_net)::deserialize(InStream& in)
{
    // reading first 4 bytes for getting meta data of type size
    in.read(detail::byte_cast(&meta), 4);

    byte_type meta_size_type = meta >> 24;
    byte_type meta_precision_type = (meta & 0x00FF0000) >> 16;
    byte_type meta_activation_id = (meta & 0x0000FF00) >> 8;
    byte_type meta_loss_id = meta & 0x000000FF;

    bool buffering;

    buffering = (sizeof(size_type) != meta_size_type);
    if(buffering) buff.set(BaseId::Unsigned, meta_size_type);

    size_type topology_size = 0;
    deserializeData(in, &topology_size, 1, buffering);

    topology.resize(topology_size);
    deserializeData(in, topology.data(), topology.size(), buffering);

    N = topology_size - 1;

    activationId.resize(N);

    B = Net::Builder::get1d(topology);
    W = Net::Builder::get2d(topology);

    buffering = (sizeof(ActivationId) != meta_activation_id);
    if (buffering) buff.set(BaseId::Unsigned, meta_activation_id);

    deserializeData(in, activationId.data(), activationId.size(), buffering);

    buffering = (sizeof(LossId) != meta_loss_id);
    if (buffering) buff.set(BaseId::Unsigned, meta_loss_id);

    deserializeData(in, &lossId, 1, buffering);

    buffering = (sizeof(precision_type) != meta_precision_type);
    if (buffering) buff.set(BaseId::Float, meta_precision_type);

    for (auto& tensor : B)
        deserializeData(in, tensor.data(), tensor.size(), buffering);

    for (auto& tensor : W)
        deserializeData(in, tensor.data(), tensor.size(), buffering);
}

TRIXY_SERIALIZER_TPL_DECLARATION
constexpr typename TRIXY_SERIALIZER_TPL(meta::is_feedforward_net)::meta_data_type
TRIXY_SERIALIZER_TPL(meta::is_feedforward_net)::getBaseMetaData() noexcept
{
    using M = meta_data_type;

    return (static_cast<M>(sizeof(size_type)) << 24)
         + (static_cast<M>(sizeof(precision_type)) << 16)
         + (static_cast<M>(sizeof(ActivationId)) << 8)
         +  static_cast<M>(sizeof(LossId));
}

TRIXY_SERIALIZER_TPL_DECLARATION
template <class OutStream, typename InData>
void TRIXY_SERIALIZER_TPL(meta::is_feedforward_net)::serializeData(
    OutStream& out, InData data, size_type n)
{
    using Data = meta::deref<InData>; // dereferencing InData type

    size_type memory_size = n * sizeof(Data);
    out.write(reinterpret_cast<const char*>(data), memory_size);
}

TRIXY_SERIALIZER_TPL_DECLARATION
template <class InStream, typename OutData>
void TRIXY_SERIALIZER_TPL(meta::is_feedforward_net)::deserializeData(
    InStream& in, OutData data, size_type n, bool buffering)
{
    using Data = meta::deref<OutData>; // dereferencing OutData type

    if (buffering)
    {
        // you MUST pre-define offset for buffer before
        size_type memory_size = n * buff.offset();

        buff.reserve(memory_size);
        in.read(buff.data(), memory_size); // write from stream to buffer
        buff.read(data, memory_size); // write from buffer to data
    }
    else
    {
        size_type memory_size = n * sizeof(Data);
        in.read(reinterpret_cast<char*>(data), memory_size);
    }
}

} // namespace trixy

#include <Trixy/Neuro/Detail/MacroUnscope.hpp>

#endif // TRIXY_SERIALIZER_FEED_FORWARD_NET_HPP
