#ifndef ILIQUE_MATRIX_HPP
#define ILIQUE_MATRIX_HPP

#include <cstddef> // size_t

#include "Trixy/Lique/LiqueBaseTensor.hpp"

namespace trixy
{

namespace ilique
{

template <template <typename...> class Derived, typename Precision, typename... Args>
class IMatrix : public lique::TensorType::matrix
{
public:
    class Shape;

public:
    using Tensor          = Derived<Precision, Args...>;

public:
    using size_type       = std::size_t;
    using precision_type  = Precision;

    using reference       = Precision&;
    using const_reference = const Precision&;

protected:
    virtual ~IMatrix()    = default;

private:
    Tensor& self() { return *static_cast<Tensor*>(this); }
    const Tensor& self() const { return *static_cast<const Tensor*>(this); }

public:
    reference operator() (size_type i, size_type j) noexcept
    { return self().operator()(i, j); }

    const_reference operator() (size_type i, size_type j) const noexcept
    { return self().operator()(i, j); }

    reference operator() (size_type i) noexcept { return self().operator()(i); }
    const_reference operator() (size_type i) const noexcept { return self().operator()(i); }

    const Shape& shape() const noexcept { return self().shape(); }

    void resize(size_type size) { self().resize(size); }
    void resize(size_type m, size_type n) { self().resize(m, n); }
    void resize(const Shape& shape) { self().resize(shape); }

    void resize(size_type m, size_type n, Precision value) { self().resize(m, n, value); }
    void resize(const Shape& shape, Precision value) { self().resize(shape, value); }

    void reshape(size_type m, size_type n) noexcept { self().reshape(m, n); }

    Tensor dot(const Tensor& tensor) const { return self().dot(tensor); }
    Tensor transpose() const { return self().transpose(); }

    Tensor  inverse() const { return self().inverse(); }
    Tensor& inverse() { return self().inverse(); }
};

template <template <typename...> class Derived, typename Precision, typename... Args>
class IMatrix<Derived, Precision, Args...>::Shape
{
friend IMatrix<Derived, Precision, Args...>;
friend Derived<Precision, Args...>;

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

#endif // ILIQUE_MATRIX_HPP

