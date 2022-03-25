#ifndef PRECISION_REQUIRE_HPP
#define PRECISION_REQUIRE_HPP

#include <type_traits>

namespace trixy
{

template <typename Precision>
struct PrecisionRequire
{
public:
    using type = Precision;

protected:
    using require = Precision;

protected:
    static constexpr bool precision_require = std::is_floating_point<require>::value;

    static_assert(precision_require, "'Precision' is not a floating point type.");
};

} // namespace trixy

#endif // PRECISION_REQUIRE_HPP
