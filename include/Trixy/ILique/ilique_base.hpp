#ifndef ILIQUE_BASE_HPP
#define ILIQUE_BASE_HPP

#include <cstddef> // size_t

namespace ilique
{

template <template <typename T, typename...> class Tensor, typename Precision, typename... Args>
class ILiqueBase
{
protected:
    virtual ~ILiqueBase() = default;

public:
    using TensorType = Tensor<Precision, Args...>;

public:
    virtual TensorType& copy(const TensorType&) noexcept = 0;

    virtual TensorType& fill(Precision value) noexcept = 0;
    virtual TensorType& fill(Precision (*generator)()) noexcept = 0;

    virtual TensorType  apply(Precision (*function)(Precision)) const = 0;
    virtual TensorType& apply(Precision (*function)(Precision)) noexcept = 0;

    virtual TensorType& apply(Precision (*function)(Precision), const TensorType&) noexcept = 0;

    virtual TensorType  multiply(const TensorType&) const = 0;
    virtual TensorType& multiply(const TensorType&) noexcept = 0;

    virtual TensorType& multiply(const TensorType&, const TensorType&) noexcept = 0;

    virtual TensorType  join(Precision value) const = 0;
    virtual TensorType& join(Precision value) noexcept = 0;

    virtual TensorType& join(Precision value, const TensorType&) noexcept = 0;

    virtual TensorType  add(const TensorType&) const = 0;
    virtual TensorType& add(const TensorType&) noexcept = 0;

    virtual TensorType  sub(const TensorType&) const = 0;
    virtual TensorType& sub(const TensorType&) noexcept = 0;

    virtual TensorType operator+ (const TensorType&) const = 0; // maybe unused
    virtual TensorType operator- (const TensorType&) const = 0; // maybe unused
};

template <template <typename T, typename...> class Tensor, typename Precision, typename... Args>
class IVector
{
public:
    using TensorType      = Tensor<Precision, Args...>;
    using size_type       = std::size_t;
    using reference       = Precision&;
    using const_reference = const Precision&;

protected:
    virtual ~IVector() = default;

public:
    virtual reference operator() (size_type i) noexcept = 0;
    virtual const_reference operator() (size_type i) const noexcept = 0;

    virtual size_type size() const noexcept = 0;

    virtual void resize(size_type new_size) = 0;
    virtual Precision dot(const TensorType&) const = 0;
};

template <template <typename T, typename...> class Tensor, typename Precision, typename... Args>
class IMatrix
{
protected:
    class Shape;

public:
    using TensorType      = Tensor<Precision, Args...>;
    using size_type       = std::size_t;
    using reference       = Precision&;
    using const_reference = const Precision&;

protected:
    virtual ~IMatrix() = default;

public:
    virtual reference operator() (size_type i, size_type j) noexcept = 0;
    virtual const_reference operator() (size_type i, size_type j) const noexcept = 0;

    virtual const Shape& size() const noexcept = 0;

    virtual void resize(size_type m, size_type n) = 0;
    virtual void resize(const Shape& new_shape) = 0;

    virtual TensorType dot(const TensorType&) const = 0;
    virtual TensorType transpose() const = 0;

    virtual TensorType  inverse() const = 0;
    virtual TensorType& inverse() = 0;
};

template <template <typename T, typename...> class Tensor, typename Precision, typename... Args>
class IMatrix<Tensor, Precision, Args...>::Shape
{
friend IMatrix<Tensor, Precision, Args...>;
friend Tensor<Precision, Args...>;

public:
    using size_type = std::size_t;

protected:
    size_type row_;
    size_type col_;

public:
    explicit Shape(size_type m, size_type n) noexcept : row_(m), col_(n) {}
    Shape(const Shape& shape) noexcept : row_(shape.row_), col_(shape.col_) {}

    size_type row() const noexcept { return row_; }
    size_type col() const noexcept { return col_; }
};

} // namespace ilique

#endif // ILIQUE_BASE_HPP
