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

public:
    using size_type       = std::size_t;
    using reference       = Type&;
    using const_reference = const Type&;

protected:
    virtual ~Matrix();

protected:
    Type** data_;
    Shape shape_;

public:
    Matrix() noexcept;
    explicit Matrix(size_type m, size_type n);
    explicit Matrix(const Shape& shape);
    Matrix(const Matrix&);
    Matrix(Matrix&&) noexcept;

    Matrix& operator= (const Matrix&);
    Matrix& operator= (Matrix&&) noexcept;

    reference operator() (size_type i, size_type j) noexcept;
    const_reference operator() (size_type i, size_type j) const noexcept;

    const Shape& size() const noexcept;

    virtual void resize(size_type m, size_type n) = 0;
    virtual void resize(const Shape& new_shape) = 0;

    virtual Tensor<Type> dot(const Tensor<Type>&) const = 0;
    virtual Tensor<Type> transpose() const = 0;
};

template <template <typename T> class Tensor, typename Type>
class Matrix<Tensor, Type>::Shape
{
friend Matrix<Tensor, Type>;
friend Tensor<Type>;

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

template <template <typename T> class Tensor, typename Type>
inline Matrix<Tensor, Type>::Matrix() noexcept : data_(nullptr), shape_(0, 0)
{
}

template <template <typename T> class Tensor, typename Type>
Matrix<Tensor, Type>::~Matrix()
{
    if(data_ != nullptr)
    {
        for(size_type i = 0; i < shape_.row_; ++i)
            delete[] data_[i];
        delete[] data_;
    }
}

template <template <typename T> class Tensor, typename Type>
Matrix<Tensor, Type>::Matrix(std::size_t m, std::size_t n)
    : data_(new Type* [m]), shape_(m, n)
{
    for(size_type i = 0; i < shape_.row_; ++i)
        data_[i] = new Type[shape_.col_];
}

template <template <typename T> class Tensor, typename Type>
Matrix<Tensor, Type>::Matrix(const Shape& shape)
    : data_(new Type* [shape.row_]), shape_(shape)
{
    for(size_type i = 0; i < shape_.row_; ++i)
        data_[i] = new Type[shape_.col_];
}

template <template <typename T> class Tensor, typename Type>
Matrix<Tensor, Type>::Matrix(const Matrix& matrix)
    : data_(new Type* [matrix.shape_.row_]), shape_(matrix.shape_)
{
    for(size_type i = 0; i < shape_.row_; ++i)
        data_[i] = new Type[shape_.col_];

    for(size_type i = 0; i < shape_.row_; ++i)
        for(size_type j = 0; j < shape_.col_; ++j)
            data_[i][j] = matrix.data_[i][j];
}

template <template <typename T> class Tensor, typename Type>
inline Matrix<Tensor, Type>::Matrix(Matrix&& matrix) noexcept
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
        for(size_type i = 0; i < shape_.row_; ++i)
            delete[] data_[i];
        delete[] data_;
    }

    shape_ = matrix.shape_;

    data_ = new Type* [shape_.row_];
    for(size_type i = 0; i < shape_.row_; ++i)
        data_[i] = new Type[shape_.col_];

    for(size_type i = 0; i < shape_.row_; ++i)
        for(size_type j = 0; j < shape_.col_; ++j)
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
        for(size_type i = 0; i < shape_.row_; ++i)
            delete[] data_[i];
        delete[] data_;
    }

    data_ = matrix.data_;
    shape_ = matrix.shape_;

    matrix.data_ = nullptr;

    return *this;
}

template <template <typename T> class Tensor, typename Type>
inline Type& Matrix<Tensor, Type>::operator() (std::size_t i, std::size_t j) noexcept
{
    return data_[i][j];
}

template <template <typename T> class Tensor, typename Type>
inline const Type& Matrix<Tensor, Type>::operator() (std::size_t i, std::size_t j) const noexcept
{
    return data_[i][j];
}

template <template <typename T> class Tensor, typename Type>
inline const typename Matrix<Tensor, Type>::Shape& Matrix<Tensor, Type>::size() const noexcept
{
    return shape_;
}

} // namespace ilique

#endif // ILIQUE_MATRIX_HPP
