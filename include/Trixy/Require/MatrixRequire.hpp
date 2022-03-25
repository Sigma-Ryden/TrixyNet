#ifndef MATRIX_REQUIRE_HPP
#define MATRIX_REQUIRE_HPP

#include "BaseRequire.hpp"

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
    using require::resize;
    using require::reshape;

    using require::fill;
    using require::apply;

    using require::operator();

    using require::dot;
    using require::add;
    using require::sub;
    using require::multiply;
    using require::join;

    using require::transpose;
    using require::inverse;

    using require::data;
};

} // namespace trixy

#endif // MATRIX_REQUIRE_HPP
