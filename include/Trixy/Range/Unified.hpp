#ifndef TRIXY_RANGE_UNIFIED_HPP
#define TRIXY_RANGE_UNIFIED_HPP

#include <cstddef> // size_t, ptrdiff_t

#include <Trixy/Range/Base.hpp>

namespace trixy
{

namespace utility
{

template <typename T>
struct Range<T, RangeType::Unified>
{
public:
    using pointer           = T*;
    using const_pointer     = const T*;

    using value_type        = T;
    using size_type         = std::size_t;
    using difference_type   = std::ptrdiff_t;

private:
    pointer first_;
    size_type size_;

public:
    Range() : first_(nullptr), size_(0) {}

    Range(size_type size)
        : first_(new value_type [size]), size_(size)
    {
    }

    Range(size_type size, value_type value)
        : Range(size)
    {
        fill(first_, first_ + size_);
    }

    ~Range()
    {
        delete[] first_;
    }

    void fill(value_type value)
    {
        auto first = first_;
        auto last  = first_ + size_;

        while (first != last) *first++ = value;
    }

    void resize(size_type size)
    {
        delete[] first_;

        first_ = new value_type [size];
        size_  = size;
    }

    void resize(size_type size, value_type value)
    {
        resize(size);
        fill(value);
    }

    pointer data() noexcept { return first_; }
    const_pointer data() const noexcept { return first_; }

    difference_type size() const noexcept { return size_; }

    pointer first() noexcept { return size_; }
    pointer last() noexcept { return first_ + size_; }

    const_pointer first() const noexcept { return first_; }
    const_pointer last() const noexcept { return first_ + size_; }
};

} // namespace utility

} // namespace trixy

#endif // TRIXY_RANGE_UNIFIED_HPP
