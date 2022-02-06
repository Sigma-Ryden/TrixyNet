#ifndef ILIQUE_BASE_HPP
#define ILIQUE_BASE_HPP

#include <cstddef> // size_t

#include "Trixy/Detail/TrixyMeta.hpp"

namespace trixy
{

namespace ilique
{

template <template <typename P, typename...> class Tensor, typename Precision,
          typename enable = void, typename... Args>
class ILiqueBase;

template <template <typename P, typename...> class Tensor1D, typename Precision,
          typename enable = void, typename... Args>
class IVector;

template <template <typename P, typename...> class Tensor2D, typename Precision,
          typename enable = void, typename... Args>
class IMatrix;

} // namespace ilique

} // namespacce trixy

namespace trixy
{

namespace ilique
{

template <template <typename P, typename...> class Tensor, typename Precision, typename... Args>
class ILiqueBase<Tensor, Precision, meta::enable_for_arithmetic_t<Precision>, Args...>
{
protected:
    virtual ~ILiqueBase() = default;

public:
    using TensorType = Tensor<Precision, Args...>;
    using Generator  = Precision (*)();
    using Function   = Precision (*)(Precision);
    using size_type  = std::size_t;

public:
    virtual TensorType& copy(const TensorType&) noexcept = 0;

    virtual TensorType& fill(Precision value) noexcept = 0;
    virtual TensorType& fill(Generator) noexcept = 0;

    virtual size_type size() const noexcept = 0;

    virtual TensorType  apply(Function) const = 0;
    virtual TensorType& apply(Function) noexcept = 0;
    virtual TensorType& apply(Function, const TensorType&) noexcept = 0;

    virtual TensorType  multiply(const TensorType&) const = 0;
    virtual TensorType& multiply(const TensorType&) noexcept = 0;
    virtual TensorType& multiply(const TensorType&, const TensorType&) noexcept = 0;

    virtual TensorType  join(Precision value) const = 0;
    virtual TensorType& join(Precision value) noexcept = 0;
    virtual TensorType& join(Precision value, const TensorType&) noexcept = 0;

    virtual TensorType  add(const TensorType&) const = 0;
    virtual TensorType& add(const TensorType&) noexcept = 0;
    virtual TensorType& add(const TensorType&, const TensorType&) noexcept = 0;

    virtual TensorType  sub(const TensorType&) const = 0;
    virtual TensorType& sub(const TensorType&) noexcept = 0;
    virtual TensorType& sub(const TensorType&, const TensorType&) noexcept = 0;
};

template <template <typename P, typename...> class Tensor1D, typename Precision, typename... Args>
class IVector<Tensor1D, Precision, meta::enable_for_arithmetic_t<Precision>, Args...>
{
public:
    using TensorType      = Tensor1D<Precision, Args...>;
    using size_type       = std::size_t;
    using reference       = Precision&;
    using const_reference = const Precision&;

protected:
    virtual ~IVector() = default;

public:
    virtual reference operator() (size_type i) noexcept = 0;
    virtual const_reference operator() (size_type i) const noexcept = 0;

    virtual void resize(size_type new_size) = 0;
    virtual Precision dot(const TensorType&) const = 0;
};

template <template <typename P, typename...> class Tensor2D, typename Precision, typename... Args>
class IMatrix<Tensor2D, Precision, meta::enable_for_arithmetic_t<Precision>, Args...>
{
protected:
    class Shape;

public:
    using TensorType      = Tensor2D<Precision, Args...>;
    using size_type       = std::size_t;
    using reference       = Precision&;
    using const_reference = const Precision&;

protected:
    virtual ~IMatrix() = default;

public:
    virtual reference operator() (size_type i, size_type j) noexcept = 0;
    virtual const_reference operator() (size_type i, size_type j) const noexcept = 0;

    virtual reference operator() (size_type i) noexcept = 0;
    virtual const_reference operator() (size_type i) const noexcept = 0;

    virtual const Shape& shape() const noexcept = 0;

    virtual void resize(size_type m, size_type n) = 0;
    virtual void resize(const Shape& new_shape) = 0;

    virtual void resize(size_type m, size_type n, Precision fill_value) = 0;
    virtual void resize(const Shape& new_shape, Precision fill_value) = 0;

    virtual void reshape(size_type m, size_type n) noexcept = 0;

    virtual TensorType dot(const TensorType&) const = 0;
    virtual TensorType transpose() const = 0;

    virtual TensorType  inverse() const = 0;
    virtual TensorType& inverse() = 0;
};

template <template <typename P, typename...> class Tensor2D, typename Precision, typename... Args>
class IMatrix<Tensor2D, Precision, meta::enable_for_arithmetic_t<Precision>, Args...>::Shape
{
friend IMatrix<Tensor2D, Precision, meta::enable_for_arithmetic_t<Precision>, Args...>;
friend Tensor2D<Precision, Args...>;

public:
    using size_type = std::size_t;

protected:
    size_type row_;
    size_type col_;
    size_type size_;

public:
    explicit Shape(size_type m, size_type n) noexcept : row_(m), col_(n), size_(m * n) {}
    Shape(const Shape& shape) noexcept : row_(shape.row_), col_(shape.col_), size_(shape.size_) {}

    size_type row() const noexcept { return row_; }
    size_type col() const noexcept { return col_; }
};

} // namespace ilique

} // namespace trixy

#endif // ILIQUE_BASE_HPP
