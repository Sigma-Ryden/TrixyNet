#ifndef TRIXY_REQUIRE_MATRIX_HPP
#define TRIXY_REQUIRE_MATRIX_HPP

#include <Trixy/Require/Base.hpp>

namespace trixy
{

template <class Tensor>
using MatrixRequire = Require<Tensor, RequireType::matrix>;

template <class Tensor>
struct Require<Tensor, RequireType::matrix> : protected Tensor
{
public:
    using type = RequireType::matrix;

protected:
    using require = Tensor;

protected:
    using typename require::Shape;

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
    using require::dim;

    using require::resize;
    using require::reshape;

    using require::fill;
    using require::apply;

    using require::operator();

    using require::dot;
    using require::add;
    using require::sub;
    using require::mul;
    using require::join;

    using require::transpose;
    using require::inverse;

    using require::data;
};

} // namespace trixy

#endif // TRIXY_REQUIRE_MATRIX_HPP
