#ifndef TRIXY_LIQUE_SHAPE_HPP
#define TRIXY_LIQUE_SHAPE_HPP

#include <type_traits> // is_integral

namespace trixy
{

namespace lique
{

// You MUST prevent any changes to this struct!
template <typename T>
struct Shape
{
private:
    static constexpr bool require = std::is_integral<T>::value;

    static_assert(require, "'T' should be an integral type.");

public:
    using size_type = T;

public:
    size_type depth;
    size_type height;
    size_type width;

    size_type size;

public:
    Shape() : depth(0), height(0), width(0) {}

    explicit Shape(size_type d, size_type h, size_type w)
    : depth(d), height(h), width(w), size(d * h * w) {}

    explicit Shape(size_type h, size_type w)
    : depth(1), height(h), width(w), size(h * w) {}

    explicit Shape(size_type w)
    : depth(1), height(1), width(w), size(w) {}
};

} // namespace lique

} // namespace trixy

#endif // TRIXY_LIQUE_SHAPE_HPP
