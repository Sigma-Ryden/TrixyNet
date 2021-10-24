#ifndef ILIQUE_MATRIX_HPP
#define ILIQUE_MATRIX_HPP

#include <cstddef> // size_t

namespace ilique
{

template <template <typename T> class Tensor, typename Type>
class Matrix
{
protected:
    class Shape;
    virtual ~Matrix();

protected:
    Type** data_;
    Shape shape_;

public:
    Matrix() noexcept;
    explicit Matrix(std::size_t m, size_t n);
    explicit Matrix(const Shape& shape);
    Matrix(const Matrix&);
    Matrix(Matrix&&) noexcept;

    Matrix& operator= (const Matrix&);
    Matrix& operator= (Matrix&&) noexcept;

    Type& operator() (std::size_t i, std::size_t j) noexcept;
    const Type& operator() (std::size_t i, std::size_t j) const noexcept;

    const Shape& size() const noexcept;

    virtual Tensor<Type>& resize(std::size_t m, std::size_t n) = 0;
    virtual Tensor<Type>& resize(const Shape& new_shape) = 0;

    virtual Tensor<Type> dot(const Tensor<Type>&) const = 0;
    virtual Tensor<Type> transpose() const = 0;
};

template <template <typename T> class Tensor, typename Type>
class Matrix<Tensor, Type>::Shape
{
friend Matrix<Tensor, Type>;
friend Tensor<Type>;

private:
    std::size_t row_;
    std::size_t col_;

public:
    explicit Shape(size_t m, size_t n) noexcept : row_(m), col_(n) {}
    Shape(const Shape& shape) noexcept : row_(shape.row_), col_(shape.col_) {}

    std::size_t row() const noexcept { return row_; }
    std::size_t col() const noexcept { return col_; }
};

template <template <typename T> class Tensor, typename Type>
Matrix<Tensor, Type>::Matrix() noexcept : data_(nullptr), shape_(0, 0)
{
}

template <template <typename T> class Tensor, typename Type>
Matrix<Tensor, Type>::~Matrix()
{
    if(data_ != nullptr)
    {
        for(std::size_t i = 0; i < shape_.row_; ++i)
            delete[] data_[i];
        delete[] data_;
    }
}

template <template <typename T> class Tensor, typename Type>
Matrix<Tensor, Type>::Matrix(std::size_t m, std::size_t n)
    : data_(new Type* [m]), shape_(m, n)
{
    for(std::size_t i = 0; i < shape_.row_; ++i)
        data_[i] = new Type[shape_.col_];
}

template <template <typename T> class Tensor, typename Type>
Matrix<Tensor, Type>::Matrix(const Shape& shape)
    : data_(new Type* [shape.row_]), shape_(shape)
{
    for(std::size_t i = 0; i < shape_.row_; ++i)
        data_[i] = new Type[shape_.col_];
}

template <template <typename T> class Tensor, typename Type>
Matrix<Tensor, Type>::Matrix(const Matrix& matrix)
    : data_(new Type* [matrix.shape_.row_]), shape_(matrix.shape_)
{
    for(std::size_t i = 0; i < shape_.row_; ++i)
        data_[i] = new Type[shape_.col_];

    for(std::size_t i = 0; i < shape_.row_; ++i)
        for(std::size_t j = 0; j < shape_.col_; ++j)
            data_[i][j] = matrix.data_[i][j];
}

template <template <typename T> class Tensor, typename Type>
Matrix<Tensor, Type>::Matrix(Matrix&& matrix) noexcept
    : data_(matrix.data_), shape_(matrix.shape_)
{
    matrix.data_ = nullptr;
}

template <template <typename T> class Tensor, typename Type>
Matrix<Tensor, Type>& Matrix<Tensor, Type>::operator= (const Matrix& matrix)
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
Matrix<Tensor, Type>& Matrix<Tensor, Type>::operator= (Matrix&& matrix) noexcept
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
Type& Matrix<Tensor, Type>::operator() (std::size_t i, std::size_t j) noexcept
{
    return data_[i][j];
}

template <template <typename T> class Tensor, typename Type>
const Type& Matrix<Tensor, Type>::operator() (std::size_t i, std::size_t j) const noexcept
{
    return data_[i][j];
}

template <template <typename T> class Tensor, typename Type>
const typename Matrix<Tensor, Type>::Shape& Matrix<Tensor, Type>::size() const noexcept
{
    return shape_;
}

} // namespace ilique

#endif // ILIQUE_MATRIX_HPP
