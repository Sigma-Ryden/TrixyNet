#ifndef ILIQUE_MATRIX_HPP
#define ILIQUE_MATRIX_HPP

#include <cstddef>

namespace ilique
{

template <template <typename T> class Tensor, typename Type>
class IMatrix
{
protected:
    class Shape;
    virtual ~IMatrix();

protected:
    Type** data_;
    Shape shape_;

public:
    IMatrix();
    IMatrix(std::size_t m, size_t n);
    IMatrix(const Shape& shape);
    IMatrix(const IMatrix&);
    IMatrix(IMatrix&&);

    IMatrix& operator= (const IMatrix&);
    IMatrix& operator= (IMatrix&&);

    Type& operator() (std::size_t i, std::size_t j);
    const Type& operator() (std::size_t i, std::size_t j) const;

    const Shape& size() const;

    virtual Tensor<Type>& resize(std::size_t m, std::size_t n) = 0;
    virtual Tensor<Type>& resize(const Shape& new_shape) = 0;

    virtual Tensor<Type> dot(const Tensor<Type>&) const = 0;
    virtual Tensor<Type> transpoce() const = 0;
};

template <template <typename T> class Tensor, typename Type>
class IMatrix<Tensor, Type>::Shape
{
friend IMatrix<Tensor, Type>;
friend Tensor<Type>;

private:
    std::size_t row_;
    std::size_t col_;

public:
    Shape(size_t m, size_t n) : row_(m), col_(n) {}
    Shape(const Shape& shape) : row_(shape.row_), col_(shape.col_) {}

    std::size_t row() const { return row_; }
    std::size_t col() const { return col_; }
};

template <template <typename T> class Tensor, typename Type>
IMatrix<Tensor, Type>::IMatrix() : data_(nullptr), shape_(0, 0)
{
}

template <template <typename T> class Tensor, typename Type>
IMatrix<Tensor, Type>::~IMatrix()
{
    if(data_ != nullptr)
    {
        for(std::size_t i = 0; i < shape_.row_; ++i)
            delete[] data_[i];
        delete[] data_;
    }
}

template <template <typename T> class Tensor, typename Type>
IMatrix<Tensor, Type>::IMatrix(std::size_t m, std::size_t n)
    : data_(new Type* [m]), shape_(m, n)
{
    for(std::size_t i = 0; i < shape_.row_; ++i)
        data_[i] = new Type[shape_.col_];
}

template <template <typename T> class Tensor, typename Type>
IMatrix<Tensor, Type>::IMatrix(const Shape& s)
    : data_(new Type* [s.row_]), shape_(s)
{
    for(std::size_t i = 0; i < shape_.row_; ++i)
        data_[i] = new Type[shape_.col_];
}

template <template <typename T> class Tensor, typename Type>
IMatrix<Tensor, Type>::IMatrix(const IMatrix& matrix)
    : data_(new Type* [matrix.shape_.row_]), shape_(matrix.shape_)
{
    for(std::size_t i = 0; i < shape_.row_; ++i)
        data_[i] = new Type[shape_.col_];

    for(std::size_t i = 0; i < shape_.row_; ++i)
        for(std::size_t j = 0; j < shape_.col_; ++j)
            data_[i][j] = matrix.data_[i][j];
}

template <template <typename T> class Tensor, typename Type>
IMatrix<Tensor, Type>::IMatrix(IMatrix&& matrix)
    : data_(matrix.data_), shape_(matrix.shape_)
{
    matrix.data_ = nullptr;
}

template <template <typename T> class Tensor, typename Type>
IMatrix<Tensor, Type>& IMatrix<Tensor, Type>::operator= (const IMatrix& matrix)
{
    if(this == &matrix)
        return *this;

    if(data_ != nullptr)
    {
        for(std::size_t i = 0; i < shape_.row_; ++i)
            delete[] data_[i];
        delete[] data_;
    }

    shape_ = matrix.shape_;

    data_ = new Type* [shape_.row_];
    for(std::size_t i = 0; i < shape_.row_; ++i)
        data_[i] = new Type[shape_.col_];

    for(std::size_t i = 0; i < shape_.row_; ++i)
        for(std::size_t j = 0; j < shape_.col_; ++j)
            data_[i][j] = matrix.data_[i][j];

    return *this;
}

template <template <typename T> class Tensor, typename Type>
IMatrix<Tensor, Type>& IMatrix<Tensor, Type>::operator= (IMatrix&& matrix)
{
    if(this == &matrix)
        return *this;

    if(data_ != nullptr)
    {
        for(std::size_t i = 0; i < shape_.row_; ++i)
            delete[] data_[i];
        delete[] data_;
    }

    data_ = matrix.data_;
    shape_ = matrix.shape_;

    matrix.data_ = nullptr;

    return *this;
}

template <template <typename T> class Tensor, typename Type>
Type& IMatrix<Tensor, Type>::operator() (std::size_t i, std::size_t j)
{
    return data_[i][j];
}

template <template <typename T> class Tensor, typename Type>
const Type& IMatrix<Tensor, Type>::operator() (std::size_t i, std::size_t j) const
{
    return data_[i][j];
}

template <template <typename T> class Tensor, typename Type>
const typename IMatrix<Tensor, Type>::Shape& IMatrix<Tensor, Type>::size() const
{
    return shape_;
}

} // namespace ilique

#endif // ILIQUE_MATRIX_HPP
