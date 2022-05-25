#ifndef TRIXY_REQUIRE_LINEAR_HPP
#define TRIXY_REQUIRE_LINEAR_HPP

#include <Trixy/Require/Base.hpp>

namespace trixy
{

namespace guard
{

template <class Linear>
using LinearRequire = Require<Linear, RequireType::linear>;

template <class Linear>
struct Require<Linear, RequireType::linear> : protected Linear
{
public:
    using type = RequireType::linear;

protected:
    using require = Linear;

protected:
    using typename require::size_type;
    using typename require::precision_type;

protected:
    using require::first;
    using require::last;

    using require::dot;
    using require::tensordot;
    using require::transpose;
    using require::inverse;

    using require::add;
    using require::sub;
    using require::mul;
    using require::join;

    using require::apply;

    using require::for_each;
};


} // namespace guard

} // namespace trixy

#endif // TRIXY_REQUIRE_LINEAR_HPP
