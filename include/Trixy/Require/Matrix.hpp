#ifndef TRIXY_REQUIRE_MATRIX_HPP
#define TRIXY_REQUIRE_MATRIX_HPP

#include <Trixy/Require/Base.hpp>

#include <Trixy/Detail/TrixyMeta.hpp>

namespace trixy
{

namespace guard
{

template <class Tensor>
using MatrixRequire = Require<Tensor, RequireType::matrix>;

template <class Tensor>
struct Require<Tensor, RequireType::matrix> : protected Tensor
{
public:
    using type = RequireType::matrix;

protected:
    static constexpr bool matrix_require =
        std::is_base_of<lique::TensorType::matrix, Tensor>::value;

    static_assert(matrix_require, "'Tensor' is not base of trixy::lique::TensorType::matrix.");

    using require = Tensor;

protected:
    using typename require::size_type;
    using typename require::precision_type;
    using typename require::value_type;
    using typename require::shape_type;

    using typename require::pointer;
    using typename require::const_pointer;

    using typename require::reference;
    using typename require::const_reference;

    using typename require::range_view;

protected:
    using require::copy;

    using require::shape;
    using require::size;

    using require::resize;
    using require::reshape; // maybe unused

    using require::fill;
    using require::apply; // maybe unused

    using require::operator();
    using require::operator range_view;

    using require::add;
    using require::sub;
    using require::mul;
    using require::join;

    using require::swap; // maybe unused

    using require::data;
};

} // namespace guard

} // namespace trixy

#endif // TRIXY_REQUIRE_MATRIX_HPP
