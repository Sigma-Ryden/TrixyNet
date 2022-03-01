#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <cstdint> // size_t, int8_t, int16_t, int32_t, int64_t, uint8_t, uint16_t, uint32_t, uint64_t

#include "Trixy/Detail/TrixyMeta.hpp"

#include "Detail/MacroScope.hpp"

namespace trixy
{

enum class ItemSize : std::uint8_t
{
    _1bytes  = 1,
    _2bytes  = 2,
    _4bytes  = 4,
    _8bytes  = 8,
    _16bytes = 16
};

template <ItemSize Size = ItemSize::_8bytes>
class Buffer
{
public:
    struct SupportType;

public:
    using size_type     = std::size_t;
    using byte_type     = char;

    using pointer       = byte_type*;
    using const_pointer = const byte_type*;

private:
    enum class SupportTypeId : std::uint8_t
    {
        undefined,
        i8, i16, i32, i64,
        u8, u16, u32, u64,
        f32, f64, f128
    };

private:
    pointer data_;

    size_type data_size_;
    size_type buff_size_;

    SupportTypeId id_;

    bool empty_;

public:
    Buffer() noexcept;
    ~Buffer();

    Buffer(size_type n);

    pointer data() noexcept { return data_; }
    const_pointer data() const noexcept { return data_; }

    void resize(size_type n);
    void erase() noexcept;

    void empty() const noexcept;

    template <typename OutData,
              meta::enable_if_t<sizeof(OutData) <= std::size_t(Size), int> = 0>
    void read(OutData* beg, OutData* end) noexcept;

    template <typename InData,
              meta::enable_if_t<sizeof(InData) <= std::size_t(Size), int> = 0>
    void write(const InData* beg, const InData* end) noexcept;

private:
    template <typename DstData, typename SrcData>
    void copy(DstData* dst, const SrcData* src);

    template <typename DataCastType, typename OutData>
    void read_buff(OutData* beg, OutData* end);

    template <typename DetectionDataType>
    SupportTypeId detect_data_type_id();
};

template <ItemSize Size>
struct Buffer<Size>::SupportType
{
    using i8   = std::int8_t;
    using i16  = std::int16_t;
    using i32  = std::int32_t;
    using i64  = std::int64_t;

    using u8   = std::uint8_t;
    using u16  = std::uint16_t;
    using u32  = std::uint32_t;
    using u64  = std::uint64_t;

    using f32  = float;
    using f64  = double;
    using f128 = long double;
};

template <ItemSize Size>
inline Buffer<Size>::Buffer() noexcept
    : data_(nullptr)
    , data_size_(0)
    , buff_size_(0)
    , id_(SupportTypeId::undefined)
    , empty_(true)
{
}

template <ItemSize Size>
inline Buffer<Size>::~Buffer()
{
    delete[] data_;
}

template <ItemSize Size>
Buffer<Size>::Buffer(size_type n)
    : data_(new byte_type [size_type(Size) * n])
    , data_size_(n)
    , buff_size_(size_type(Size) * n)
    , id_(SupportTypeId::undefined)
    , empty_(false)
{
    erase();
}

template <ItemSize Size>
void Buffer<Size>::resize(size_type n)
{
    delete[] data_;

    data_size_ = n;
    buff_size_ = size_type(Size) * n;

    data_ = new byte_type [buff_size_];

    id_ = SupportType::undefined;

    erase();
}

template <ItemSize Size>
template <typename OutData,
          meta::enable_if_t<sizeof(OutData) <= std::size_t(Size), int>>
void Buffer<Size>::read(OutData* beg, OutData* end) noexcept
{
    if(end - beg > data_size_) return;

    switch (id_)
    {
    BUFF_CASE_READ_HELPER(i8)
    BUFF_CASE_READ_HELPER(i16)
    BUFF_CASE_READ_HELPER(i32)
    BUFF_CASE_READ_HELPER(i64)

    BUFF_CASE_READ_HELPER(u8)
    BUFF_CASE_READ_HELPER(u16)
    BUFF_CASE_READ_HELPER(u32)
    BUFF_CASE_READ_HELPER(u64)

    BUFF_CASE_READ_HELPER(f32)
    BUFF_CASE_READ_HELPER(f64)
    BUFF_CASE_READ_HELPER(f128)

    default: break;
    }

    id_ = SupportTypeId::undefined;
}

template <ItemSize Size>
template <typename InData,
          meta::enable_if_t<sizeof(InData) <= std::size_t(Size), int>>
void Buffer<Size>::write(const InData* beg, const InData* end) noexcept
{
    if(end - beg > data_size_) return;

    id_ = detect_data_type_id<InData>();

    auto it = data_;
    while(beg != end)
    {
        copy(reinterpret_cast<InData*>(it), beg);
        it += static_cast<size_type>(Size);
        ++beg;
    }

    empty_ = false;
}

template <ItemSize Size>
void Buffer<Size>::erase() noexcept
{
    auto beg = data_;
    auto end = data_ + buff_size_;

    while(beg != end) *beg++ = 0;

    empty_ = true;
}

template <ItemSize Size>
template <typename DstData, typename SrcData>
inline void Buffer<Size>::copy(DstData* dst, const SrcData* src)
{
    *dst = static_cast<DstData>(*src);
}

template <ItemSize Size>
template <typename DataCastType, typename OutData>
void Buffer<Size>::read_buff(OutData* beg, OutData* end)
{
    auto it = data_;
    while(beg != end)
    {
        *beg = *reinterpret_cast<DataCastType*>(it);
        it += static_cast<size_type>(Size);
        ++beg;
    }
}

template <ItemSize Size>
template <typename DetectionDataType>
typename Buffer<Size>::SupportTypeId Buffer<Size>::detect_data_type_id()
{
    BUFF_DETECT_HELPER(i8)
    BUFF_DETECT_HELPER(i16)
    BUFF_DETECT_HELPER(i32)
    BUFF_DETECT_HELPER(i64)
    BUFF_DETECT_HELPER(u8)
    BUFF_DETECT_HELPER(u16)
    BUFF_DETECT_HELPER(u32)
    BUFF_DETECT_HELPER(u64)
    BUFF_DETECT_HELPER(f32)
    BUFF_DETECT_HELPER(f64)
    BUFF_DETECT_HELPER(f128)

    return SupportTypeId::undefined;
}

using DataBuffer = Buffer<ItemSize::_8bytes>;

} // namespace trixy

#include "Detail/MacroUnscope.hpp"

#endif // BUFFER_HPP
