#ifndef TRIXY_SERIALIZATION_POLYNOMIAL_REGRESSION_HPP
#define TRIXY_SERIALIZATION_POLYNOMIAL_REGRESSION_HPP

#include <cstdint> // int8_t, int16_t

#include <Trixy/Neuro/Serialization/Base.hpp>

#include <Trixy/Buffer/Core.hpp>

#include <Trixy/Neuro/Detail/TrixyNetMeta.hpp>
#include <Trixy/Detail/FunctionDetail.hpp>

#include <Trixy/Neuro/Detail/MacroScope.hpp>

namespace trixy
{

TRIXY_SERIALIZER_TPL_DECLARATION
class TRIXY_SERIALIZER_TPL(meta::is_polynomial_regression)
{
public:
    using Regression        = Serializable;

    using Vector            = typename Regression::Vector;

    using precision_type    = typename Regression::precision_type;
    using size_type         = typename Regression::size_type;

private:
    using meta_data_type    = std::int16_t;
    using byte_type         = std::int8_t;

    using BaseId            = Buffer::BaseTypeId;

private:
    Buffer buff;            ///< Specialized Buffer for casting stream data

    Vector W;               ///< Inner weight
    size_type N;            ///< Size of weight vector (same as power size + 1)

    meta_data_type meta;    ///< 2 bytes of meta data for hold type information

public:
    Serializer() : buff(), W(), N(0), meta(0) {}

    void prepare(const Regression& reg);

    template <class OutStream>
    void serialize(OutStream& out) const;

    template <class OutStream>
    void serialize(OutStream& out, const Regression& reg) const;

    template <class InStream>
    void deserialize(InStream& in);

    const Vector& getWeight() const noexcept { return W; };
    size_type getPower() const noexcept { return N; };

private:
    static constexpr meta_data_type getBaseMetaData() noexcept;

    template <class InStream, typename OutData>
    void deserializeData(InStream& in, OutData data, size_type n, bool buffering);
};

TRIXY_SERIALIZER_TPL_DECLARATION
void TRIXY_SERIALIZER_TPL(meta::is_polynomial_regression)::prepare(const Regression& reg)
{
    W = reg.getInnerWeight();
    N = reg.getInnerPower();
}

TRIXY_SERIALIZER_TPL_DECLARATION
template <class OutStream>
void TRIXY_SERIALIZER_TPL(meta::is_polynomial_regression)::serialize(OutStream& out) const
{
    meta_data_type xmeta = getBaseMetaData();
    out.write(detail::const_byte_cast(&xmeta), 2); // writing 2 bytes of meta data

    out.write(detail::const_byte_cast(&N), sizeof(size_type));
    out.write(detail::const_byte_cast(W.data()), sizeof(precision_type) *  W.size());
}

TRIXY_SERIALIZER_TPL_DECLARATION
template <class OutStream>
void TRIXY_SERIALIZER_TPL(meta::is_polynomial_regression)::serialize(
    OutStream& out, const Regression& reg) const
{
    meta_data_type xmeta = getBaseMetaData();
    out.write(detail::const_byte_cast(&xmeta), 2); // writing 2 bytes of meta data

    size_type n = reg.getInnerPower();
    out.write(detail::const_byte_cast(&n), sizeof(size_type));

    out.write(
        detail::const_byte_cast(reg.getInnerWeight().data()),
        sizeof(precision_type) * reg.getInnerWeight().size()
    );
}

TRIXY_SERIALIZER_TPL_DECLARATION
template <class InStream>
void TRIXY_SERIALIZER_TPL(meta::is_polynomial_regression)::deserialize(InStream& in)
{
    in.read(detail::byte_cast(&meta), 2); // reading 2 bytes of meta data

    byte_type meta_size_type = meta >> 8;
    byte_type meta_precision_type = meta & 0x00FF;

    bool buffering;

    buffering = (sizeof(size_type) != meta_size_type);
    if(buffering) buff.set(BaseId::Unsigned, meta_size_type);

    deserializeData(in, &N, 1, buffering);

    W.resize(N + 1);

    buffering = (sizeof(precision_type) != meta_precision_type);
    if(buffering) buff.set(BaseId::Float, meta_precision_type);

    deserializeData(in, W.data(), W.size(), buffering);
}

TRIXY_SERIALIZER_TPL_DECLARATION
constexpr typename TRIXY_SERIALIZER_TPL(meta::is_polynomial_regression)::meta_data_type
TRIXY_SERIALIZER_TPL(meta::is_polynomial_regression)::getBaseMetaData() noexcept
{
    using M = meta_data_type;

    return (static_cast<M>(sizeof(size_type)) << 8)
         +  static_cast<M>(sizeof(precision_type));
}

TRIXY_SERIALIZER_TPL_DECLARATION
template <class InStream, typename OutData>
void TRIXY_SERIALIZER_TPL(meta::is_polynomial_regression)::deserializeData(
    InStream& in, OutData data, size_type n, bool buffering)
{
    using Data = meta::deref<OutData>; // dereferencing OutData type

    if(buffering)
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

#endif // TRIXY_SERIALIZATION_POLYNOMIAL_REGRESSION_HPP
