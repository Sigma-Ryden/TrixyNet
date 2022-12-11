#ifndef TRIXY_ILIQUE_MATRIX_HPP
#define TRIXY_ILIQUE_MATRIX_HPP

#include <Trixy/ILique/Base.hpp>

#include <Trixy/ILique/Detail/MacroScope.hpp>

namespace trixy
{

namespace ilique
{

ILIQUE_TENSOR_TEMPLATE()
using IMatrix = ILIQUE_TENSOR_TEMPLATE_CLASS(lique::TensorType::matrix);

ILIQUE_TENSOR_TEMPLATE()
class ILIQUE_TENSOR_TEMPLATE_CLASS(lique::TensorType::matrix)
    : protected ilique::ITensorBase<Derived, Precision, Pack...>
    , public lique::TensorType::matrix
{
    ILIQUE_TENSOR_BASE_BODY()

public:
    reference operator() (size_type i, size_type j) noexcept
    { return self().operator()(i, j); }

    const_reference operator() (size_type i, size_type j) const noexcept
    { return self().operator()(i, j); }

    void resize(const shape_type& shape) { self().resize(shape); }
    void resize(size_type height, size_type width) { self().resize(height, width); }

    void reshape(size_type height, size_type width) noexcept { self().reshape(height, width); }
};

} // namespace ilique

} // namespace trixy

#include <Trixy/ILique/Detail/MacroUnscope.hpp>

#endif // TRIXY_ILIQUE_MATRIX_HPP

