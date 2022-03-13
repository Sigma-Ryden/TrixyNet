#include "Buffer.hpp"

namespace trixy
{

Buffer::Buffer(memory_size n)
    : data_(new byte_type [n])
    , size_(n)
    , id_(SupportTypeId::null)
    , offset_(1)
{
    clear();
}

Buffer::Buffer(const Buffer& buff)
    : data_(new byte_type [buff.size_])
    , size_(buff.size_)
    , id_(buff.id_)
    , offset_(buff.offset_)
{
    std::memcpy(data_, buff.data_, size_);
}

Buffer::Buffer(Buffer&& buff) noexcept
    : data_(buff.data_)
    , size_(buff.size_)
    , id_(buff.id_)
    , offset_(buff.offset_)
{
    buff.data_ = nullptr;
}

Buffer& Buffer::operator= (const Buffer& buff)
{
    if(this != &buff)
    {
        delete[] data_;
        data_ = new char [buff.size_];

        std::memcpy(data_, buff.data_, size_);

        size_ = buff.size_;
        id_ = buff.id_;
        offset_ = buff.offset_;
    }

    return *this;
}

Buffer& Buffer::operator= (Buffer&& buff) noexcept
{
    if(this != &buff)
    {
        delete[] data_;

        data_ = buff.data_;
        size_ = buff.size_;

        id_ = buff.id_;
        offset_ = buff.offset_;

        buff.data_ = nullptr;
    }

    return *this;
}

void Buffer::resize(memory_size n)
{
    delete[] data_;

    size_ = n;
    data_ = new byte_type [n];

    clear();
}

void Buffer::reserve(memory_size n)
{
    if(n > size_) resize(n);
}

void Buffer::set(
    BaseTypeId id, size_type offset) noexcept
{
    switch (id)
    {
    case BaseTypeId::Integer:
        id_ = get_integer_id(offset);
        break;

    case BaseTypeId::Unsigned:
        id_ = get_unsigned_id(offset);
        break;

    case BaseTypeId::Float:
        id_ = get_float_id(offset);
        break;

    default: return;
    }

    offset_ = offset;
}

void Buffer::clear() noexcept
{
    auto beg = data_;
    auto end = data_ + size_;

    while(beg != end) *beg++ = 0;
}

bool Buffer::empty() const noexcept
{
    auto beg = data_;
    auto end = data_ + size_;

    while(beg != end and *beg == 0)
    {
        ++beg;
    }

    return beg == end;
}

typename Buffer::SupportTypeId Buffer::get_integer_id(
    size_type sizeof_type) noexcept
{
    switch (sizeof_type)
    {
    case 1: return SupportTypeId::i8;
    case 2: return SupportTypeId::i16;
    case 4: return SupportTypeId::i32;
    case 8: return SupportTypeId::i64;

    default: return SupportTypeId::null;
    }
}

typename Buffer::SupportTypeId Buffer::get_unsigned_id(
    size_type sizeof_type) noexcept
{
    switch (sizeof_type)
    {
    case 1: return SupportTypeId::u8;
    case 2: return SupportTypeId::u16;
    case 4: return SupportTypeId::u32;
    case 8: return SupportTypeId::u64;

    default: return SupportTypeId::null;
    }
}

typename Buffer::SupportTypeId Buffer::get_float_id(
    size_type sizeof_type) noexcept
{
    switch (sizeof_type)
    {
    case 4: return SupportTypeId::f32;
    case 8: return SupportTypeId::f64;
    case 16: return SupportTypeId::f128;

    default: return SupportTypeId::null;
    }
}

} // namespace trixy
