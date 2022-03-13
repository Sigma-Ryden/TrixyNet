#ifndef ILIQUE_BASE_HPP
#define ILIQUE_BASE_HPP

#include <cstddef> // size_t

#include "Trixy/Lique/LiqueBaseTensor.hpp"

#include "Trixy/Detail/TrixyMeta.hpp"

namespace trixy
{

namespace ilique
{

template <template <typename...> class Derived, typename Precision, typename... Args>
class ITensor
{
public:
    using Tensor            = Derived<Precision, Args...>;

public:
    using size_type         = std::size_t;
    using precision_type    = Precision;

    using pointer           = Precision*;
    using const_pointer     = const Precision*;

    using reference         = Precision&;
    using const_reference   = const Precision&;

    using Function          = Precision (*)(Precision);

protected:
    virtual ~ITensor() = default;

private:
    Tensor& self() noexcept
    { return *static_cast<Tensor*>(this); }

    const Tensor& self() const noexcept
    { return *static_cast<const Tensor*>(this); }

public:
    Tensor& copy(const Tensor& tensor) noexcept { return self().copy(tensor); }

    Tensor& fill(Precision value) noexcept { return self().fill(value); }

    template <class Generator,
              trixy::meta::use_for_callable_t<Generator, precision_type> = 0>
    Tensor& fill(Generator gen) noexcept { return self().fill(gen); }

    size_type size() const noexcept { return self().size(); }

    Tensor  apply(Function func) const { return self().apply(func); }
    Tensor& apply(Function func) noexcept { return self().apply(func); }

    Tensor& apply(Function func, const Tensor& tensor) noexcept
    { return self().apply(func, tensor); }

    Tensor& apply(Function func, const_pointer src) noexcept
    { return self().apply(func, src); }

    Tensor  multiply(const Tensor& tensor) const { return self().multiply(tensor); }
    Tensor& multiply(const Tensor& tensor) noexcept { return self().multiply(tensor); }

    Tensor& multiply(const Tensor& lhs, const Tensor& rhs) noexcept
    { return self().multiply(lhs, rhs); }

    Tensor  join(Precision value) const { return self().join(value); }
    Tensor& join(Precision value) noexcept { return self().join(value); }

    Tensor& join(Precision value, const Tensor& tensor) noexcept
    { return self().join(value, tensor); }

    Tensor  add(const Tensor& tensor) const { return self().add(tensor); }
    Tensor& add(const Tensor& tensor) noexcept { return self().add(tensor); }

    Tensor& add(const Tensor& lhs, const Tensor& rhs) noexcept
    { return self().add(lhs, rhs); }

    Tensor  sub(const Tensor& tensor) const { return self().sub(tensor); }
    Tensor& sub(const Tensor& tensor) noexcept { return self().sub(tensor); }

    Tensor& sub(const Tensor& lhs, const Tensor& rhs) noexcept
    { return self().sub(lhs, rhs); }
};

template <template <typename...> class Derived, typename Precision, typename... Args>
class IVector : public lique::TensorType::vector
{
public:
    using Tensor          = Derived<Precision, Args...>;

public:
    using size_type       = std::size_t;
    using precision_type  = Precision;

    using reference       = Precision&;
    using const_reference = const Precision&;

protected:
    virtual ~IVector() = default;

private:
    Tensor& self() { return *static_cast<Tensor*>(this); }
    const Tensor& self() const { return *static_cast<const Tensor*>(this); }

public:
    reference operator() (size_type i) noexcept { return self().operator()(i); }
    const_reference operator() (size_type i) const noexcept { return self().operator()(i); }

    void resize(size_type size) { self().resize(size); }
    void resize(size_type size, precision_type value) { self().resize(size, value); }

    precision_type dot(const Tensor& tensor) const { return self().dot(tensor); }
};

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

#endif // ILIQUE_BASE_HPP
