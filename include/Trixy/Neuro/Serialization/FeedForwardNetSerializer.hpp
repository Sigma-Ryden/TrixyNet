#ifndef FEED_FORWARD_NET_SERIALIZER_HPP
#define FEED_FORWARD_NET_SERIALIZER_HPP

#include <fstream> // ifstream, ofstream
#include <cstdint> // int8_t, int32_t

#include "BaseSerializer.hpp"

#include "Trixy/Buffer/Buffer.hpp"

#include "Trixy/Neuro/Detail/TrixyNetMeta.hpp"
#include "Trixy/Neuro/Detail/FunctionDetail.hpp"

#include "Trixy/Neuro/Detail/MacroScope.hpp"

namespace trixy
{

TRIXY_SERIALIZER_TPL_DECLARATION
class TRIXY_SERIALIZER_TPL(meta::is_feedforward_net)
{
public:
    template <class T>
    using Container                 = typename Serializable::template Container<T>;

    using Vector                    = typename Serializable::Vector;
    using Matrix                    = typename Serializable::Matrix;

    using InnerTopology             = typename Serializable::InnerTopology;

    using precision_type            = typename Serializable::precision_type;
    using size_type                 = typename Serializable::size_type;

    using ActivationId              = typename Serializable::ActivationId;
    using LossId                    = typename Serializable::LossId;

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
    constexpr static meta_data_type getBaseMetaData() noexcept;

    template <typename OutData>
    static void rawDeserializeData(std::ifstream& in, OutData data, size_type n);

    template <typename OutData>
    void deserializeData(std::ifstream& in, OutData data, size_type n);

    template <typename InData>
    static void serializeData(std::ofstream& out, InData data, size_type n);
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
    meta_data_type xmeta = getBaseMetaData();
    out.write(detail::const_byte_cast(&xmeta), 4); // writing 4 bytes of meta data

    size_type topology_size = topology.size();
    serializeData(out, &topology_size, 1);

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
    // reading first 4 bytes for getting meta data of type size
    in.read(detail::byte_cast(&meta), 4);

    byte_type meta_size_type = meta >> 24;
    byte_type meta_precision_type = (meta & 0x00FF0000) >> 16;
    byte_type meta_activation_id = (meta & 0x0000FF00) >> 8;
    byte_type meta_loss_id = meta & 0x000000FF;

    size_type topology_size;

    if(meta_size_type == sizeof(size_type))
    {
        rawDeserializeData(in, &topology_size, 1);

        topology.resize(topology_size);
        rawDeserializeData(in, topology.data(), topology.size());
    }
    else
    {
        buff.set(BaseId::Unsigned, meta_size_type);

        deserializeData(in, &topology_size, 1);

        topology.resize(topology_size);
        deserializeData(in, topology.data(), topology.size());
    }

    N = topology_size - 1;

    activationId.resize(N);

    B = Serializable::Init::get1d(topology);
    W = Serializable::Init::get2d(topology);

    if(meta_activation_id == sizeof(ActivationId))
    {
        rawDeserializeData(in, activationId.data(), activationId.size());
    }
    else
    {
        buff.set(BaseId::Unsigned, meta_activation_id);
        deserializeData(in, activationId.data(), activationId.size());
    }

    if(meta_loss_id == sizeof(LossId))
    {
        rawDeserializeData(in, &lossId, 1);
    }
    else
    {
        buff.set(BaseId::Unsigned, meta_loss_id);
        deserializeData(in, &lossId, 1);
    }

    if(meta_precision_type == sizeof(precision_type))
    {
        for(auto& tensor : B)
            rawDeserializeData(in, tensor.data(), tensor.size());

        for(auto& tensor : W)
            rawDeserializeData(in, tensor.data(), tensor.size());
    }
    else
    {
        buff.set(BaseId::Float, meta_precision_type);

        for(auto& tensor : B)
            deserializeData(in, tensor.data(), tensor.size());

        for(auto& tensor : W)
            deserializeData(in, tensor.data(), tensor.size());
    }
}

TRIXY_SERIALIZER_TPL_DECLARATION
constexpr typename TRIXY_SERIALIZER_TPL(meta::is_feedforward_net)::meta_data_type
TRIXY_SERIALIZER_TPL(meta::is_feedforward_net)::getBaseMetaData() noexcept
{
    return (meta_data_type(sizeof(size_type)) << 24)
         + (meta_data_type(sizeof(precision_type)) << 16)
         + (meta_data_type(sizeof(ActivationId)) << 8)
         +  meta_data_type(sizeof(LossId));
}

TRIXY_SERIALIZER_TPL_DECLARATION
template <typename InData>
void TRIXY_SERIALIZER_TPL(meta::is_feedforward_net)::serializeData(
    std::ofstream& out, InData data, size_type n)
{
    using Data = typename std::remove_pointer<InData>::type;

    size_type memory_size = n * sizeof(Data);
    out.write(reinterpret_cast<const char*>(data), memory_size);
}

TRIXY_SERIALIZER_TPL_DECLARATION
template <typename OutData>
void TRIXY_SERIALIZER_TPL(meta::is_feedforward_net)::rawDeserializeData(
    std::ifstream& in, OutData data, size_type n)
{
    using Data = typename std::remove_pointer<OutData>::type;

    size_type memory_size = n * sizeof(Data);
    in.read(reinterpret_cast<char*>(data), memory_size);
}

TRIXY_SERIALIZER_TPL_DECLARATION
template <typename OutData>
void TRIXY_SERIALIZER_TPL(meta::is_feedforward_net)::deserializeData(
    std::ifstream& in, OutData data, size_type n)
{
    size_type memory_size = n * buff.offset();

    buff.reserve(memory_size);
    in.read(buff.data(), memory_size);
    buff.read(data, memory_size);
}

} // namespace trixy

#include "Trixy/Neuro/Detail/MacroUnscope.hpp"

#endif // FEED_FORWARD_NET_SERIALIZER_HPP
