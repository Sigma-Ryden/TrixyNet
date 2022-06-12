#ifndef TRIXY_REQUIRE_TENSOR_HPP
#define TRIXY_REQUIRE_TENSOR_HPP

#include <Trixy/Require/Base.hpp>

#include <Trixy/Detail/TrixyMeta.hpp>

namespace trixy
{

namespace guard
{

template <class Tensor>
using TensorRequire = Require<Tensor, RequireType::tensor>;

template <class Tensor>
struct Require<Tensor, RequireType::tensor> : protected Tensor
{
public:
    using type = RequireType::tensor;

protected:
    static constexpr bool tensor_require =
        std::is_base_of<lique::TensorType::tensor, Tensor>::value;

    static_assert(tensor_require, "'Tensor' is not base of trixy::lique::TensorType::tensor.");

    using require = Tensor;

protected:
    using typename require::size_type;
    using typename require::precision_type;
    using typename require::value_type;

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

#endif // TRIXY_REQUIRE_TENSOR_HPP
