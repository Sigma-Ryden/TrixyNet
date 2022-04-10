#ifndef TRIXY_BUFFER_HPP
#define TRIXY_BUFFER_HPP

#include <cstring> // memcpy
#include <cstdint>
// size_t, int8_t, int16_t, int32_t, int64_t
// uint8_t, uint16_t, uint32_t, uint64_t

#include <Trixy/Detail/TrixyMeta.hpp>
#include <Trixy/Detail/FunctionDetail.hpp>

#include <Trixy/Buffer/Detail/MacroScope.hpp>

namespace trixy
{

template <typename T>
class Buff
{
public:
    struct SupportType;

public:
    using memory_size   = std::size_t;
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
        f32, f64, f128,
        user,
    };

public:
    enum class BaseTypeId : std::uint8_t
    {
        Integer, Unsigned, Float, User
    };

    struct BaseType
    {
        struct Integer; struct Unsigned; struct Float; struct User;
    };

private:
    pointer data_;
    memory_size size_;

    SupportTypeId id_;
    size_type offset_;

public:
    Buff() noexcept;
    ~Buff();

    explicit Buff(memory_size n);

    Buff(const Buff&);
    Buff(Buff&&) noexcept;

    Buff& operator= (const Buff&);
    Buff& operator= (Buff&&) noexcept;

    char* data() noexcept { return data_; }
    const char* data() const noexcept { return data_; }

    memory_size size() const noexcept { return size_ ; }
    size_type offset() const noexcept { return offset_; }

    void resize(memory_size n);
    void reserve(memory_size n);

    void clear() noexcept;
    bool empty() const noexcept;

    void set(BaseTypeId id, size_type offset) noexcept;

    template <class Type>
    void set(size_type offset) noexcept;

    bool is_ready() const noexcept { return id_ != SupportTypeId::null; }

    template <typename OutData>
    void read(OutData first, OutData last) noexcept;

    template <typename OutData>
    void read(OutData odata, memory_size n) noexcept;

    template <typename InData>
    void write(InData first, InData last, bool is_mutable = true) noexcept;

    template <typename InData>
    void write(InData idata, memory_size n, bool is_mutable = true) noexcept;

private:
    template <typename DataCastType, typename OutData>
    void read_buff(OutData first, OutData last);

    template <typename DetectionDataType>
    SupportTypeId detect_data_type_id();

    void set_integer(size_type sizeof_type) noexcept;
    void set_unsigned(size_type sizeof_type) noexcept;
    void set_float(size_type sizeof_type) noexcept;
    void set_user(size_type sizeof_type) noexcept;
};

template <typename T>
struct Buff<T>::SupportType
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

    using user = T;
};

template <typename T>
inline Buff<T>::Buff() noexcept
    : data_(nullptr)
    , size_(0)
    , id_(SupportTypeId::null)
    , offset_(1)
{
}

template <typename T>
inline Buff<T>::~Buff()
{
    delete[] data_;
}

template <typename T>
Buff<T>::Buff(memory_size n)
    : data_(new byte_type [n])
    , size_(n)
    , id_(SupportTypeId::null)
    , offset_(1)
{
    clear();
}

template <typename T>
Buff<T>::Buff(const Buff& buff)
    : data_(new byte_type [buff.size_])
    , size_(buff.size_)
    , id_(buff.id_)
    , offset_(buff.offset_)
{
    std::memcpy(data_, buff.data_, size_);
}

template <typename T>
Buff<T>::Buff(Buff&& buff) noexcept
    : data_(buff.data_)
    , size_(buff.size_)
    , id_(buff.id_)
    , offset_(buff.offset_)
{
    buff.data_ = nullptr;
}

template <typename T>
Buff<T>& Buff<T>::operator= (Buff&& buff) noexcept
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

template <typename T>
Buff<T>& Buff<T>::operator= (const Buff& buff)
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

template <typename T>
template <typename OutData>
void Buff<T>::read(OutData first, OutData last) noexcept
{
    if(offset_ * (last - first) > size_) return;

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

    BUFF_CASE_READ_HELPER(user)

    default: return;
    }
}

template <typename T>
void Buff<T>::resize(memory_size n)
{
    delete[] data_;

    size_ = n;
    data_ = new byte_type [n];

    clear();
}

template <typename T>
template <typename OutData>
void Buff<T>::read(OutData odata, memory_size n) noexcept
{
    read(odata, odata + n / offset_);
}

template <typename T>
template <typename InData>
void Buff<T>::write(InData first, InData last, bool is_mutable) noexcept
{
    using Data = typename std::decay<decltype(*first)>::type;

    SupportTypeId type_id = detect_data_type_id<Data>();

    if(type_id == SupportTypeId::null) return;

    if(sizeof(Data) * (last - first) > size_)
    {
        if(is_mutable) resize(sizeof(Data) * (last - first));
        else return;
    }

    id_ = type_id;
    offset_ = sizeof(Data);

    auto it = data_;
    while(first != last)
    {
        *reinterpret_cast<Data*>(it) = *first;
        it += offset_;
        ++first;
    }
}

template <typename T>
template <typename InData>
void Buff<T>::write(InData idata, memory_size n, bool is_mutable) noexcept
{
    using Data = typename std::decay<decltype(*idata)>::type;

    write(idata, idata + n / sizeof(Data), is_mutable);
}

template <typename T>
void Buff<T>::reserve(memory_size n)
{
    if(n > size_) resize(n);
}

template <typename T>
void Buff<T>::set(BaseTypeId id, size_type offset) noexcept
{
    switch (id)
    {
    case BaseTypeId::Integer:
        return set_integer(offset);

    case BaseTypeId::Unsigned:
        return set_unsigned(offset);

    case BaseTypeId::Float:
        return set_float(offset);

    case BaseTypeId::User:
        return set_user(offset);

    default:
        id_ = SupportTypeId::null;
    }
}

template <typename T>
void Buff<T>::clear() noexcept
{
    auto first = data_;
    auto last = data_ + size_;

    while(first != last) *first++ = 0;
}

template <typename T>
bool Buff<T>::empty() const noexcept
{
    auto first = data_;
    auto last = data_ + size_;

    while(first != last and *first == 0)
    {
        ++first;
    }

    return first == last;
}

template <typename T>
void Buff<T>::set_integer(size_type sizeof_type) noexcept
{
    if(sizeof_type == 1)
        id_ = SupportTypeId::i8;

    else if(sizeof_type == 2)
        id_ = SupportTypeId::i16;

    else if(sizeof_type == 4)
        id_ = SupportTypeId::i32;

    else if(sizeof_type == 8)
        id_ = SupportTypeId::i64;

    else
    {
        id_ = SupportTypeId::null;
        return;
    }

    offset_ = sizeof_type;
}

template <typename T>
void Buff<T>::set_unsigned(size_type sizeof_type) noexcept
{
    if(sizeof_type == 1)
        id_ = SupportTypeId::u8;

    else if(sizeof_type == 2)
        id_ = SupportTypeId::u16;

    else if(sizeof_type == 4)
        id_ = SupportTypeId::u32;

    else if(sizeof_type == 8)
        id_ = SupportTypeId::u64;

    else
    {
        id_ = SupportTypeId::null;
        return;
    }

    offset_ = sizeof_type;
}

template <typename T>
void Buff<T>::set_float(size_type sizeof_type) noexcept
{
    if(sizeof_type == 4)
        id_ = SupportTypeId::f32;

    else if(sizeof_type == 8)
        id_ = SupportTypeId::f64;

    else if(sizeof_type == 16)
        id_ = SupportTypeId::f128;

    else
    {
        id_ = SupportTypeId::null;
        return;
    }

    offset_ = sizeof_type;
}

template <typename T>
void Buff<T>::set_user(size_type sizeof_type) noexcept
{
    if(sizeof_type == sizeof(T))
    {
        id_ = SupportTypeId::user;
        offset_ = sizeof(T);
    }
    else
    {
        id_ = SupportTypeId::null;
    }
}

template <typename T>
template <class Type>
void Buff<T>::set(size_type offset) noexcept
{
    using BT = BaseType;
    using ST = SupportType;

    using U = Type;

    if(
    std::is_same<U, typename BT::Integer>::value or
    std::is_same<U, typename ST::i8>::value or
    std::is_same<U, typename ST::i16>::value or
    std::is_same<U, typename ST::i32>::value or
    std::is_same<U, typename ST::i64>::value)
        set_integer(offset);

    else if(
    std::is_same<U, typename BT::Unsigned>::value or
    std::is_same<U, typename ST::u8>::value or
    std::is_same<U, typename ST::u16>::value or
    std::is_same<U, typename ST::u32>::value or
    std::is_same<U, typename ST::u64>::value)
        set_unsigned(offset);

    else if(
    std::is_same<U, typename BT::Float>::value or
    std::is_same<U, typename ST::f32>::value or
    std::is_same<U, typename ST::f64>::value or
    std::is_same<U, typename ST::f128>::value)
        set_float(offset);

    else if(
    std::is_same<U, typename BT::User>::value or
    std::is_same<U, T>::value)
        set_user(offset);

    else
    {
        id_ = SupportTypeId::null;
        return;
    }

    offset_ = offset;
}

template <typename T>
template <typename DataCastType, typename OutData>
void Buff<T>::read_buff(OutData first, OutData last)
{
    using Data = typename std::decay<decltype(*first)>::type;

    auto it = data_;
    while(first != last)
    {
        *first = detail::try_cast<Data>(*reinterpret_cast<DataCastType*>(it));
        it += offset_;
        ++first;
    }
}

template <typename T>
template <typename DetectionDataType>
typename Buff<T>::SupportTypeId Buff<T>::detect_data_type_id()
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

    BUFF_DETECT_HELPER(user)

    return SupportTypeId::null;
}

using Buffer = Buff<char>;

} // namespace trixy

#include <Trixy/Buffer/Detail/MacroUnscope.hpp>

#endif // TRIXY_BUFFER_HPP
