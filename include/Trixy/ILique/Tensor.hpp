#ifndef TRIXY_ILIQUE_TENSOR_HPP
#define TRIXY_ILIQUE_TENSOR_HPP

#include <Trixy/ILique/Base.hpp>

#include <Trixy/ILique/Detail/MacroScope.hpp>

namespace trixy
{

namespace ilique
{

ILIQUE_TENSOR_TPL_DECLARATION
class ILIQUE_TENSOR_TPL(lique::TensorType::tensor)
    : protected ilique::ITensorBase<Derived, Precision, Pack...>
    , public lique::TensorType::tensor
{
    ILIQUE_TENSOR_BASE_BODY

public:
    reference operator() (size_type i, size_type j, size_type k) noexcept
    { return self().operator()(i, j, k); }

    const_reference operator() (size_type i, size_type j, size_type k) const noexcept
    { return self().operator()(i, j, k); }

    void resize(const shape_type& shape) { self().resize(shape); }
    void resize(size_type depth, size_type height, size_type width)
    { self().resize(depth, height, width); }

    void reshape(size_type depth, size_type height, size_type width) noexcept
    { self().reshape(depth, height, width); }
};

} // namespace ilique

} // namespace trixy

#include <Trixy/ILique/Detail/MacroUnscope.hpp>

#endif // ILIQUE_TENSOR_HPP
