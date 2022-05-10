#ifndef TRIXY_REQUIRE_VECTOR_HPP
#define TRIXY_REQUIRE_VECTOR_HPP

#include <Trixy/Require/Base.hpp>

namespace trixy
{

template <class Tensor>
using VectorRequire = Require<Tensor, RequireType::vector>;

template <class Tensor>
struct Require<Tensor, RequireType::vector> : protected Tensor
{
public:
    using type = RequireType::vector;

protected:
    using require = Tensor;

protected:
    using typename require::size_type;
    using typename require::precision_type;

    using typename require::pointer;
    using typename require::const_pointer;

    using typename require::reference;
    using typename require::const_reference;

protected:
    using require::copy;

    using require::shape;
    using require::size;

    using require::resize;
    using require::reshape;

    using require::fill;
    using require::apply;

    using require::operator();

    //using require::dot; deprecated
    using require::add;
    using require::sub;
    using require::mul;

    using require::join;

    using require::data;
};

} // namespace trixy

#endif // TRIXY_REQUIRE_VECTOR_HPP
