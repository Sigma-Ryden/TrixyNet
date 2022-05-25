#ifndef TRIXY_REQUIRE_BASE_HPP
#define TRIXY_REQUIRE_BASE_HPP

#include <Trixy/Base.hpp> // RequireType

namespace trixy
{

namespace guard
{

template <class Requirable, typename RequireType>
struct Require;

} // namespace guard

} // namespace trixy

#endif // TRIXY_REQUIRE_BASE_HPP
