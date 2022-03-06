#ifndef LINEAR_REGRESSION_SERIALIZER_HPP
#define LINEAR_REGRESSION_SERIALIZER_HPP

#include <fstream> // ifstream, ofstream
#include <cstdint> // int8_t, int16_t

#include "Trixy/Neuro/Serialization/BaseSerializer.hpp"

#include "Trixy/Buffer/Buffer.hpp"

#include "Trixy/Neuro/Detail/TrixyNetMeta.hpp"
#include "Trixy/Neuro/Detail/FunctionDetail.hpp"

#include "Trixy/Neuro/Detail/MacroScope.hpp"

namespace trixy
{

TRIXY_SERIALIZER_TPL_DECLARATION
class TRIXY_SERIALIZER_TPL(meta::is_linear_regression)
{
public:
    using Vector         = typename Serializable::Vector;

    using precision_type = typename Serializable::precision_type;
    using size_type      = typename Serializable::size_type;

private:
    using meta_data_type = std::int16_t;
    using byte_type      = std::int8_t;

    using BaseId         = Buffer::BaseTypeId;

private:
    Buffer buff;         ///< Specialized Buffer for casting stream data

    Vector W;            ///< Inner weight
    size_type N;         ///< Size of weight vector (same as sample size + 1)

    meta_data_type meta; ///< 2 bytes of meta data for hold type information

public:
    Serializer() : W(), N(0) {}

    void prepare(const Serializable& reg);

    void serialize(std::ofstream& out) const;
    void serialize(std::ofstream& out, const Serializable& reg) const;

    void deserialize(std::ifstream& in);

    const Vector& getWeight() const noexcept { return W; };
    size_type getSize() const noexcept { return N; };

private:
    static constexpr meta_data_type getBaseMetaData() noexcept;

    template <typename Data>
    void deserializeData(std::ifstream& in, Data* data, size_type n);
};

TRIXY_SERIALIZER_TPL_DECLARATION
void TRIXY_SERIALIZER_TPL(meta::is_linear_regression)::prepare(const Serializable& reg)
{
    W = reg.getInnerWeight();
    N = reg.getInnerSize();
}

TRIXY_SERIALIZER_TPL_DECLARATION
void TRIXY_SERIALIZER_TPL(meta::is_linear_regression)::serialize(std::ofstream& out) const
{
    meta_data_type xmeta = getBaseMetaData();
    out.write(detail::const_byte_cast(&xmeta), 2); // writing 2 bytes of meta data

    out.write(detail::const_byte_cast(&N), sizeof(size_type));
    out.write(detail::const_byte_cast(W.data()), sizeof(precision_type) * W.size());
}

TRIXY_SERIALIZER_TPL_DECLARATION
void TRIXY_SERIALIZER_TPL(meta::is_linear_regression)::serialize(
    std::ofstream& out, const Serializable& reg) const
{
    meta_data_type xmeta = getBaseMetaData();
    out.write(detail::const_byte_cast(&xmeta), 2); // writing 2 bytes of meta data

    size_type n = reg.getInnerSize();
    out.write(detail::const_byte_cast(&n), sizeof(size_type));

    out.write(
        detail::const_byte_cast(reg.getInnerWeight().data()),
        sizeof(precision_type) * reg.getInnerWeight().size()
    );
}

TRIXY_SERIALIZER_TPL_DECLARATION
void TRIXY_SERIALIZER_TPL(meta::is_linear_regression)::deserialize(std::ifstream& in)
{
    in.read(detail::byte_cast(&meta), 2); // reading 2 bytes of meta data

    byte_type meta_size_type = meta >> 8;
    byte_type meta_precision_type = meta & 0x00FF;

    if(meta_size_type == sizeof(size_type))
    {
        in.read(detail::byte_cast(&N), meta_size_type);
    }
    else
    {
        buff.set(BaseId::Unsigned, meta_size_type);
        deserializeData(in, &N, 1);
    }

    W.resize(N + 1);

    if(meta_precision_type == sizeof(precision_type))
    {
        in.read(detail::byte_cast(W.data()), meta_precision_type * W.size());
    }
    else
    {
        buff.set(BaseId::Float, meta_precision_type);
        deserializeData(in, W.data(), W.size());
    }
}

TRIXY_SERIALIZER_TPL_DECLARATION
constexpr typename TRIXY_SERIALIZER_TPL(meta::is_linear_regression)::meta_data_type
TRIXY_SERIALIZER_TPL(meta::is_linear_regression)::getBaseMetaData() noexcept
{
    return (meta_data_type(sizeof(size_type)) << 8)
         +  meta_data_type(sizeof(precision_type));
}

TRIXY_SERIALIZER_TPL_DECLARATION
template <typename Data>
void TRIXY_SERIALIZER_TPL(meta::is_linear_regression)::deserializeData(
    std::ifstream& in, Data* data, size_type n)
{
    size_type memory_size  = n * buff.offset();

    buff.reserve(memory_size);
    in.read(buff.data(), memory_size);
    buff.read(data, memory_size);
}

} // namespace trixy

#include "Trixy/Neuro/Detail/MacroUnscope.hpp"

#endif // LINEAR_REGRESSION_SERIALIZER_HPP
