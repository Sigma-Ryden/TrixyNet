#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <cstring> // memcpy
#include <cstdint>
// size_t, int8_t, int16_t, int32_t, int64_t
// uint8_t, uint16_t, uint32_t, uint64_t

#include "Trixy/Detail/TrixyMeta.hpp"

#include "Detail/MacroScope.hpp"

namespace trixy
{

class Buffer
{
public:
    struct SupportType;

public:
    using buff_size     = std::size_t;
    using size_type     = std::size_t;

    using byte_type     = char;

    using pointer       = byte_type*;
    using const_pointer = const byte_type*;

private:
    enum class SupportTypeId : std::uint8_t
    {
        null,
        i8, i16, i32, i64,
        u8, u16, u32, u64,
        f32, f64, f128
    };

public:
    enum class BaseTypeId : std::uint8_t
    {
        Integer, Unsigned, Float
    };

    struct BaseType
    {
        struct Integer; struct Unsigned; struct Float;
    };

private:
    pointer data_;
    size_type size_;

    SupportTypeId id_;
    size_type offset_;

public:
    Buffer() noexcept;
    ~Buffer();

    Buffer(buff_size size);

    Buffer(const Buffer&);
    Buffer(Buffer&&) noexcept;

    Buffer& operator= (const Buffer&);
    Buffer& operator= (Buffer&&) noexcept;

    char* data() noexcept { return data_; }
    const char* data() const noexcept { return data_; }

    buff_size size() const noexcept { return size_ ; }
    size_type offset() const noexcept { return offset_; }

    void resize(buff_size size);
    void reserve(buff_size size);

    void clear() noexcept;
    bool empty() const noexcept;

    void set(BaseTypeId id, size_type offset) noexcept;
    template <class BaseType>
    void set(size_type offset) noexcept;

    bool is_ready() const noexcept { return id_ != SupportTypeId::null; }

    template <typename OutData>
    void read(OutData* beg, OutData* end) noexcept;

    template <typename OutData>
    void read(OutData* odata, buff_size size) noexcept;

    template <typename InData>
    void write(const InData* beg, const InData* end, bool is_mutable = true) noexcept;

    template <typename InData>
    void write(const InData* idata, buff_size size, bool is_mutable = true) noexcept;

private:
    template <typename DataCastType, typename OutData>
    void read_buff(OutData* beg, OutData* end);

    template <typename DetectionDataType>
    SupportTypeId detect_data_type_id();

    static SupportTypeId get_integer_id(size_type sizeof_type) noexcept;
    static SupportTypeId get_unsigned_id(size_type sizeof_type) noexcept;
    static SupportTypeId get_float_id(size_type sizeof_type) noexcept;
};

struct Buffer::SupportType
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

inline Buffer::Buffer() noexcept
    : data_(nullptr)
    , size_(0)
    , id_(SupportTypeId::null)
    , offset_(1)
{
}

inline Buffer::~Buffer()
{
    delete[] data_;
}

template <typename OutData>
void Buffer::read(OutData* beg, OutData* end) noexcept
{
    if(offset_ * (end - beg) > size_) return;

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

    default: return;
    }
}

template <typename OutData>
void Buffer::read(OutData* odata, buff_size size) noexcept
{
    read(odata, odata + size / offset_);
}

template <typename InData>
void Buffer::write(const InData* beg, const InData* end, bool is_mutable) noexcept
{
    SupportTypeId type_id = detect_data_type_id<InData>();

    if(type_id == SupportTypeId::null) return;

    if(sizeof(InData) * (end - beg) > size_)
    {
        if(is_mutable) resize(sizeof(InData) * (end - beg));
        else return;
    }

    id_ = type_id;
    offset_ = sizeof(InData);

    auto it = data_;
    while(beg != end)
    {
        *reinterpret_cast<InData*>(it) = *beg;
        it += offset_;
        ++beg;
    }
}

template <typename InData>
void Buffer::write(const InData* idata, buff_size size, bool is_mutable) noexcept
{
    write(idata, idata + size / sizeof(InData), is_mutable);
}

template <class Type>
void Buffer::set(size_type offset) noexcept
{
    if(std::is_same<Type, typename BaseType::Integer>::value)
        id_ = get_integer_id(offset);

    else if(std::is_same<Type, typename BaseType::Unsigned>::value)
        id_ = get_unsigned_id(offset);

    else if(std::is_same<Type, typename BaseType::Float>::value)
        id_ = get_float_id(offset);

    else return;

    offset_ = offset;
}

template <typename DataCastType, typename OutData>
void Buffer::read_buff(OutData* beg, OutData* end)
{
    auto it = data_;
    while(beg != end)
    {
        *beg = static_cast<OutData>(*reinterpret_cast<DataCastType*>(it));
        it += offset_;
        ++beg;
    }
}

template <typename DetectionDataType>
typename Buffer::SupportTypeId Buffer::detect_data_type_id()
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

    return SupportTypeId::null;
}

} // namespace trixy

#include "Detail/MacroUnscope.hpp"

#endif // BUFFER_HPP
