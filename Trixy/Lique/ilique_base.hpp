#ifndef ILIQUE_BASE_HPP
#define ILIQUE_BASE_HPP

#include <cstddef> // size_t

namespace ilique
{

template <template <typename T, typename...> class Tensor, typename Type, typename... Args>
class ILiqueBase
{
protected:
    virtual ~ILiqueBase() {}

public:
    virtual Tensor<Type, Args...>& fill(Type value) = 0;
    virtual Tensor<Type, Args...>& fill(Type (*generator)()) = 0;

    virtual Tensor<Type, Args...> apply(Type (*function)(Type)) const = 0;
    virtual Tensor<Type, Args...>& modify(Type (*function)(Type)) = 0;

    virtual Tensor<Type, Args...> multiply(const Tensor<Type, Args...>&) const = 0;
    virtual Tensor<Type, Args...> join(Type value) const = 0;

    virtual Tensor<Type, Args...> operator+ (const Tensor<Type, Args...>&) const = 0;
    virtual Tensor<Type, Args...> operator- (const Tensor<Type, Args...>&) const = 0;
    virtual Tensor<Type, Args...>& operator+= (const Tensor<Type, Args...>&) = 0;
    virtual Tensor<Type, Args...>& operator-= (const Tensor<Type, Args...>&) = 0;
};

template <template <typename T, typename...> class Tensor, typename Type, typename... Args>
class IVector
{
protected:
    virtual ~IVector() {}

public:
    virtual Type& operator() (std::size_t i) = 0;
    virtual const Type& operator() (std::size_t i) const = 0;

    virtual std::size_t size() const = 0;
    virtual Tensor<Type, Args...>& resize(std::size_t new_size) = 0;
    virtual Type dot(const Tensor<Type, Args...>&) const = 0;
};

template <template <typename T, typename...> class Tensor, typename Type, typename... Args>
class IMatrix
{
protected:
    virtual ~IMatrix() {}
    class Shape;

public:
    virtual Type& operator() (std::size_t i, std::size_t j) = 0;
    virtual const Type& operator() (std::size_t i, std::size_t j) const = 0;

    virtual const Shape& size() const = 0;

    virtual Tensor<Type, Args...>& resize(std::size_t m, std::size_t n) = 0;
    virtual Tensor<Type, Args...>& resize(const Shape& new_shape) = 0;

    virtual Tensor<Type, Args...> dot(const Tensor<Type, Args...>&) const = 0;
    virtual Tensor<Type, Args...> transpoce() const = 0;
};

template <template <typename T, typename...> class Tensor, typename Type, typename... Args>
class IMatrix<Tensor, Type, Args...>::Shape
{
friend IMatrix<Tensor, Type, Args...>;
friend Tensor<Type, Args...>;

private:
    std::size_t row_;
    std::size_t col_;

public:
    Shape(size_t m, size_t n) : row_(m), col_(n) {}
    Shape(const Shape& shape) : row_(shape.row_), col_(shape.col_) {}

    std::size_t row() const { return row_; }
    std::size_t col() const { return col_; }
};

} // namespace ilique

#endif // ILIQUE_BASE_HPP
