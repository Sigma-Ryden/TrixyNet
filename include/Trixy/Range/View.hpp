#ifndef TRIXY_RANGE_VIEW_HPP
#define TRIXY_RANGE_VIEW_HPP

#include <cstddef> // size_t, ptrdiff_t

#include <Trixy/Range/Base.hpp>

namespace trixy
{

namespace utility
{

template <typename T>
struct Range<T, RangeType::View>
{
public:
    using pointer           = T*;
    using const_pointer     = const T*;

    using value_type        = T;
    using size_type         = std::size_t;
    using difference_type   = std::ptrdiff_t;

private:
    pointer first_;
    pointer last_;

public:
    Range(pointer first, pointer last)
        : first_(first), last_(last) {}

    Range() : Range(nullptr, nullptr) {}

    Range(pointer first, pointer last, value_type value)
        : Range(first, last)
    {
        fill(first_, last_);
    }

    void fill(value_type value)
    {
        auto first = first_;
        auto last  = last_;

        while (first != last) *first++ = value;
    }

    pointer data() noexcept { return first_; }
    const_pointer data() const noexcept { return first_; }

    difference_type size() const noexcept { return last_ - first_; }

    pointer first() noexcept { return first_; }
    pointer last() noexcept { return last_; }

    const_pointer first() const noexcept { return first_; }
    const_pointer last() const noexcept { return last_; }
};

} // namespace utility

} // namespace trixy

#endif // TRIXY_RANGE_VIEW_HPP
