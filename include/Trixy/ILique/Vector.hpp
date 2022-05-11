// __DEPRECATED__
#ifndef TRIXY_ILIQUE_VECTOR_HPP
#define TRIXY_ILIQUE_VECTOR_HPP

#include <cstddef> // size_t

#include <Trixy/Lique/BaseTensor.hpp>
#include <Trixy/ILique/Base.hpp>

#include <Trixy/ILique/Detail/MacroScope.hpp>

namespace trixy
{

namespace ilique
{

ILIQUE_TENSOR_TPL_DECLARATION
using IVector = ILIQUE_TENSOR_TPL(lique::TensorType::vector);

ILIQUE_TENSOR_TPL_DECLARATION
class ILIQUE_TENSOR_TPL(lique::TensorType::vector) : public lique::TensorType::vector,
    protected ilique::ITensorBase<Derived, Precision, Pack...>
{
private:
    using Base = ilique::ITensorBase<Derived, Precision, Pack...>;

public:
    using typename Base::Tensor;

    using typename Base::size_type;
    using typename Base::precision_type;

    using typename Base::pointer;
    using typename Base::const_pointer;

    using typename Base::reference;
    using typename Base::const_reference;

protected:
    using Base::self;

public:
    reference operator() (size_type i) noexcept { return self().operator()(i); }
    const_reference operator() (size_type i) const noexcept { return self().operator()(i); }

    void resize(size_type size) { self().resize(size); }
    void resize(size_type size, precision_type value) { self().resize(size, value); }

    precision_type dot(const Tensor& tensor) const { return self().dot(tensor); }

public:
    using Base::copy;

    using Base::size;

    using Base::fill;
    using Base::apply;

    using Base::add;
    using Base::sub;
    using Base::mul;

    using Base::join;

    using Base::data;
};

} // namespace ilique

} // namespace trixy

#include <Trixy/ILique/Detail/MacroUnscope.hpp>

#endif // TRIXY_ILIQUE_VECTOR_HPP
