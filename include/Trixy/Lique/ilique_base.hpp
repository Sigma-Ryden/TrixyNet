#ifndef ILIQUE_BASE_HPP
#define ILIQUE_BASE_HPP

#include <cstddef> // size_t

namespace ilique
{

template <template <typename T, typename...> class Tensor, typename Type, typename... Args>
class ILiqueBase
{
protected:
    virtual ~ILiqueBase() = default;

public:
    virtual Tensor<Type, Args...>& fill(Type value) noexcept = 0;
    virtual Tensor<Type, Args...>& fill(Type (*generator)()) noexcept = 0;

    virtual Tensor<Type, Args...> apply(Type (*function)(Type)) const = 0;
    virtual Tensor<Type, Args...>& modify(Type (*function)(Type)) noexcept = 0;

    virtual Tensor<Type, Args...> multiply(const Tensor<Type, Args...>&) const = 0;
    virtual Tensor<Type, Args...>& multiply(const Tensor<Type, Args...>&) noexcept = 0;

    virtual Tensor<Type, Args...> join(Type value) const = 0;
    virtual Tensor<Type, Args...>& join(Type value) noexcept = 0;

    virtual Tensor<Type, Args...> operator+ (const Tensor<Type, Args...>&) const = 0;
    virtual Tensor<Type, Args...> operator- (const Tensor<Type, Args...>&) const = 0;
    virtual Tensor<Type, Args...>& operator+= (const Tensor<Type, Args...>&) noexcept = 0;
    virtual Tensor<Type, Args...>& operator-= (const Tensor<Type, Args...>&) noexcept = 0;
};

template <template <typename T, typename...> class Tensor, typename Type, typename... Args>
class IVector
{
public:
    using reference = Type&;
    using const_reference = const Type&;
    using size_type = std::size_t;

protected:
    virtual ~IVector() = default;

public:
    virtual reference operator() (size_type i) noexcept = 0;
    virtual const_reference operator() (size_type i) const noexcept = 0;

    virtual size_type size() const noexcept = 0;
    virtual void resize(size_type new_size) = 0;
    virtual Type dot(const Tensor<Type, Args...>&) const = 0;
};

template <template <typename T, typename...> class Tensor, typename Type, typename... Args>
class IMatrix
{
public:
    using reference = Type&;
    using const_reference = const Type&;
    using size_type = std::size_t;

protected:
    virtual ~IMatrix() = default;
    class Shape;

public:
    virtual reference operator() (size_type i, size_type j) noexcept = 0;
    virtual const_reference operator() (size_type i, size_type j) const noexcept = 0;

    virtual const Shape& size() const noexcept = 0;

    virtual void resize(size_type m, size_type n) = 0;
    virtual void resize(const Shape& new_shape) = 0;

    virtual Tensor<Type, Args...> dot(const Tensor<Type, Args...>&) const = 0;
    virtual Tensor<Type, Args...> transpose() const = 0;
};

template <template <typename T, typename...> class Tensor, typename Type, typename... Args>
class IMatrix<Tensor, Type, Args...>::Shape
{
friend IMatrix<Tensor, Type, Args...>;
friend Tensor<Type, Args...>;

public:
    using size_type = std::size_t;

private:
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
