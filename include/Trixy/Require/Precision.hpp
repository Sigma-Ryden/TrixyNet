#ifndef TRIXY_REQUIRE_PRECISION_HPP
#define TRIXY_REQUIRE_PRECISION_HPP

#include <type_traits> // is_floationg_point

#include <Trixy/Require/Base.hpp>

namespace trixy
{

namespace guard
{

template <typename Precision>
using PrecisionRequire = Require<Precision, RequireType::precision>;

template <typename Precision>
struct Require<Precision, RequireType::precision>
{
public:
    using type = RequireType::precision;

protected:
    using require = Precision;

protected:
    static constexpr bool precision_require = std::is_floating_point<require>::value;

    static_assert(precision_require, "'Precision' is not a floating point type.");
};

} // namespace guard

} // namespace trixy

#endif // TRIXY_REQUIRE_PRECISION_HPP
