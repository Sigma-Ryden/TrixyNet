#ifndef TRIXY_ILIQUE_VECTOR_HPP
#define TRIXY_ILIQUE_VECTOR_HPP

#include <Trixy/ILique/Base.hpp>

#include <Trixy/ILique/Detail/MacroScope.hpp>

namespace trixy
{

namespace ilique
{

ILIQUE_TENSOR_TPL_DECLARATION
using IVector = ILIQUE_TENSOR_TPL(lique::TensorType::vector);

ILIQUE_TENSOR_TPL_DECLARATION
class ILIQUE_TENSOR_TPL(lique::TensorType::vector)
    : protected ilique::ITensorBase<Derived, Precision, Pack...>
    , public lique::TensorType::vector
{
    ILIQUE_TENSOR_BASE_BODY

public:
    void resize(const shape_type& shape) { self().resize(shape); }
    void resize(size_type width) { self().resize(width); }

    void reshape(size_type width) noexcept { self().reshape(width); }
};

} // namespace ilique

} // namespace trixy

#include <Trixy/ILique/Detail/MacroUnscope.hpp>

#endif // TRIXY_ILIQUE_VECTOR_HPP
