#ifndef TRIXY_ILIQUE_MATRIX_HPP
#define TRIXY_ILIQUE_MATRIX_HPP

#include <cstddef> // size_t

#include <Trixy/Lique/BaseTensor.hpp>
#include <Trixy/ILique/Base.hpp>

#include <Trixy/ILique/Detail/MacroScope.hpp>

namespace trixy
{

namespace ilique
{

ILIQUE_TENSOR_TPL_DECLARATION
using IMatrix = ILIQUE_TENSOR_TPL(lique::TensorType::matrix);

ILIQUE_TENSOR_TPL_DECLARATION
class ILIQUE_TENSOR_TPL(lique::TensorType::matrix) : public lique::TensorType::matrix,
    protected ilique::ITensorBase<Derived, Precision, Pack...>
{
private:
    using Base = ilique::ITensorBase<Derived, Precision, Pack...>;

public:
    class Shape;

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
    reference operator() (size_type i, size_type j) noexcept
    { return self().operator()(i, j); }

    const_reference operator() (size_type i, size_type j) const noexcept
    { return self().operator()(i, j); }

    reference operator() (size_type i) noexcept { return self().operator()(i); }
    const_reference operator() (size_type i) const noexcept { return self().operator()(i); }

    const Shape& shape() const noexcept { return self().shape(); }
    const Shape& dim() const noexcept { return self().dim(); }

    void resize(size_type size) { self().resize(size); }
    void resize(size_type m, size_type n) { self().resize(m, n); }
    void resize(size_type m, size_type n, Precision value) { self().resize(m, n, value); }

    void reshape(size_type m, size_type n) noexcept { self().reshape(m, n); }

    Tensor dot(const Tensor& tensor) const { return self().dot(tensor); }
    Tensor transpose() const { return self().transpose(); }

    Tensor  inverse() const { return self().inverse(); }
    Tensor& inverse() { return self().inverse(); }

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

ILIQUE_TENSOR_TPL_DECLARATION
class IMatrix<Derived, Precision, Pack...>::Shape
{
friend IMatrix<Derived, Precision, Pack...>;
friend Derived<Precision, Pack...>;

public:
    using size_type = std::size_t;

protected:
    size_type size_;
    size_type row_;
    size_type col_;

public:
    explicit Shape(size_type m, size_type n) noexcept
    : size_(m * n), row_(m), col_(n) {}

    Shape(const Shape& shape) noexcept
    : size_(shape.size_), row_(shape.row_), col_(shape.col_) {}

    size_type row() const noexcept { return row_; }
    size_type col() const noexcept { return col_; }
};

} // namespace ilique

} // namespace trixy

#include <Trixy/ILique/Detail/MacroUnscope.hpp>

#endif // TRIXY_ILIQUE_MATRIX_HPP

