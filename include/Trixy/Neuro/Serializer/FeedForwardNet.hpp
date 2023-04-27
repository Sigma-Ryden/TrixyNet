#ifndef TRIXY_SERIALIZER_FEED_FORWARD_NET_HPP
#define TRIXY_SERIALIZER_FEED_FORWARD_NET_HPP

#include <cstdint> // int8_t, int32_t

#include <Trixy/Neuro/Serializer/Base.hpp>

#include <Trixy/Buffer/Core.hpp>

#include <Trixy/Detail/TrixyMeta.hpp>
#include <Trixy/Detail/FunctionDetail.hpp>

#include <Trixy/Neuro/Detail/TrixyNetMeta.hpp>

#include <Trixy/Neuro/Detail/MacroScope.hpp>
#include <Trixy/Detail/MetaMacro.hpp>

namespace trixy
{

TRIXY_SERIALIZER_TEMPLATE()
using FeedForwardNetSerializer
    = Serializer<Serializable, TRWITH(Serializable, meta::is_feedforward_net)>;

TRIXY_SERIALIZER_TEMPLATE()
class Serializer<Serializable, TRWITH(Serializable, meta::is_feedforward_net)>
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

    using BaseBuffer                = utility::Buffer;
    using BaseId                    = utility::Buffer::BaseTypeId;

private:
    BaseBuffer buff;                ///< Specialized Buffer for casting stream data

    InnerTopology topology_;        ///< Network topology (main meta data for construction)

    Container<Vector> B;            ///< Container of network bias
    Container<Matrix> W;            ///< Container of network weight

    AllActivationId activation_id_; ///< Network activation functions id
    LossId loss_id_;                ///< Network loss function id

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

    const Container<size_type>& topology() const noexcept { return topology_; }
    const Container<Vector>& bias() const noexcept { return B; }
    const Container<Matrix>& weight() const noexcept { return W; }

    ActivationId activation_id() const noexcept { return activation_id_.front(); }
    ActivationId normalization_id() const noexcept { return activation_id_.back(); }

    const AllActivationId& all_activation_id() const noexcept { return activation_id_; }

    LossId loss_id() const noexcept { return loss_id_; }

private:
    constexpr static meta_data_type meta_data() noexcept;

    template <class OutStream, typename InData>
    static void serialize_data(OutStream& out, InData data, size_type n);

    template <class InStream, typename OutData>
    void deserialize_data(InStream& in, OutData data, size_type n, bool buffering);
};

TRIXY_SERIALIZER_TEMPLATE()
void FeedForwardNetSerializer<Serializable>::prepare(const Net& net)
{
    topology_ = net.inner.topology;

    N = topology_.size() - 1;

    B.resize(N);
    W.resize(N);

    for (size_type i = 0; i < N; ++i)
    {
        B[i].resize(net.inner.B[i].shape());
        B[i].copy(net.inner.B[i].data());

        W[i].resize(net.inner.W[i].shape());
        W[i].copy(net.inner.W[i].data());
    }

    activation_id_ = net.function.activation_id();
    loss_id_ = net.function.loss_id();
}

TRIXY_SERIALIZER_TEMPLATE()
template <class OutStream>
void FeedForwardNetSerializer<Serializable>::serialize(OutStream& out) const
{
    meta_data_type xmeta = meta_data();
    out.write(detail::const_byte_cast(&xmeta), 4); // writing 4 bytes of meta data

    size_type topology_size = topology_.size();
    serialize_data(out, &topology_size, 1);

    serialize_data(out, topology_.data(), topology_.size());

    serialize_data(out, activation_id_.data(), activation_id_.size());
    serialize_data(out, &loss_id_, 1);

    for (auto& tensor : B)
        serialize_data(out, tensor.data(), tensor.size());

    for (auto& tensor : W)
        serialize_data(out, tensor.data(), tensor.size());
}

TRIXY_SERIALIZER_TEMPLATE()
template <class OutStream>
void FeedForwardNetSerializer<Serializable>::serialize(
    OutStream& out, const Net& net) const
{
    meta_data_type xmeta = meta_data();
    out.write(detail::const_byte_cast(&xmeta), 4); // writing 4 bytes of meta data

    size_type topology_size = net.inner.topology.size();
    serialize_data(out, &topology_size, 1);

    serialize_data(
        out,
        net.inner.topology.data(),
        net.inner.topology.size()
    );

    serialize_data(
        out,
        net.function.activation_id().data(),
        net.function.activation_id().size()
    );

    serialize_data(out, &net.function.loss_id(), 1);

    for (auto& tensor : net.inner.B)
        serialize_data(out, tensor.data(), tensor.size());

    for (auto& tensor : net.inner.W)
        serialize_data(out, tensor.data(), tensor.size());
}

TRIXY_SERIALIZER_TEMPLATE()
template <class InStream>
void FeedForwardNetSerializer<Serializable>::deserialize(InStream& in)
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
    deserialize_data(in, &topology_size, 1, buffering);

    topology_.resize(topology_size);
    deserialize_data(in, topology_.data(), topology_.size(), buffering);

    N = topology_size - 1;

    activation_id_.resize(N);

    B = Net::Builder::get1d(topology_);
    W = Net::Builder::get2d(topology_);

    buffering = (sizeof(ActivationId) != meta_activation_id);
    if (buffering) buff.set(BaseId::Unsigned, meta_activation_id);

    deserialize_data(in, activation_id_.data(), activation_id_.size(), buffering);

    buffering = (sizeof(LossId) != meta_loss_id);
    if (buffering) buff.set(BaseId::Unsigned, meta_loss_id);

    deserialize_data(in, &loss_id_, 1, buffering);

    buffering = (sizeof(precision_type) != meta_precision_type);
    if (buffering) buff.set(BaseId::Float, meta_precision_type);

    for (auto& tensor : B)
        deserialize_data(in, tensor.data(), tensor.size(), buffering);

    for (auto& tensor : W)
        deserialize_data(in, tensor.data(), tensor.size(), buffering);
}

TRIXY_SERIALIZER_TEMPLATE()
constexpr auto FeedForwardNetSerializer<Serializable>::meta_data() noexcept -> meta_data_type
{
    using M = meta_data_type;

    return (static_cast<M>(sizeof(size_type)) << 24)
         + (static_cast<M>(sizeof(precision_type)) << 16)
         + (static_cast<M>(sizeof(ActivationId)) << 8)
         +  static_cast<M>(sizeof(LossId));
}

TRIXY_SERIALIZER_TEMPLATE()
template <class OutStream, typename InData>
void FeedForwardNetSerializer<Serializable>::serialize_data(
    OutStream& out, InData data, size_type n)
{
    using Data = meta::dereference<InData>;

    size_type memory_size = n * sizeof(Data);
    out.write(reinterpret_cast<const char*>(data), memory_size);
}

TRIXY_SERIALIZER_TEMPLATE()
template <class InStream, typename OutData>
void FeedForwardNetSerializer<Serializable>::deserialize_data(
    InStream& in, OutData data, size_type n, bool buffering)
{
    using Data = meta::dereference<OutData>;

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

#endif // TRIXY_SERIALIZER_FEED_FORWARD_NET_HPP
