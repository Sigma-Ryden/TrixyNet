#ifndef LIQUE_MATRIX_HPP
#define LIQUE_MATRIX_HPP

#include <cstddef> // size_t

namespace lique
{

template <typename Type>
class Matrix
{
private:
    class Shape;

protected:
    Type** data_;
    Shape shape_;

public:
    Matrix() noexcept;
    ~Matrix();
    explicit Matrix(std::size_t m, size_t n);
    explicit Matrix(const Shape& shape);
    Matrix(const Matrix&);
    Matrix(Matrix&&) noexcept;

    Matrix& operator= (const Matrix&);
    Matrix& operator= (Matrix&&) noexcept;

    const Shape& size() const noexcept;
    Matrix& resize(std::size_t m, std::size_t n);
    Matrix& resize(const Shape& new_shape);

    Matrix& fill(Type (*generator)()) noexcept;
    Matrix& fill(Type value) noexcept;

    Matrix apply(Type (*function)(Type)) const;
    Matrix& modify(Type (*function)(Type)) noexcept;

    Type& operator() (std::size_t i, std::size_t j) noexcept;
    const Type& operator() (std::size_t i, std::size_t j) const noexcept;

    Matrix dot(const Matrix&) const;
    Matrix multiply(const Matrix&) const;
    Matrix join(Type value) const;
    Matrix transpose() const;

    Matrix operator+ (const Matrix&) const;
    Matrix operator- (const Matrix&) const;
    Matrix& operator+= (const Matrix&) noexcept;
    Matrix& operator-= (const Matrix&) noexcept;
};

template <typename Type>
class Matrix<Type>::Shape
{
friend Matrix<Type>;

private:
    std::size_t row_;
    std::size_t col_;

public:
    explicit Shape(size_t m, size_t n) noexcept : row_(m), col_(n) {}
    Shape(const Shape& shape) noexcept : row_(shape.row_), col_(shape.col_) {}

    std::size_t row() const noexcept { return row_; }
    std::size_t col() const noexcept { return col_; }
};

template <typename Type>
inline Matrix<Type>::Matrix() noexcept : data_(nullptr), shape_(0, 0)
{
}

template <typename Type>
Matrix<Type>::~Matrix()
{
    if(data_ != nullptr)
    {
        for(std::size_t i = 0; i < shape_.row_; ++i)
            delete[] data_[i];
        delete[] data_;
    }
}

template <typename Type>
Matrix<Type>::Matrix(std::size_t m, std::size_t n) : data_(new Type* [m]), shape_(m, n)
{
    for(std::size_t i = 0; i < shape_.row_; ++i)
        data_[i] = new Type[shape_.col_];
}
template <typename Type>
Matrix<Type>::Matrix(const Shape& shape) : data_(new Type* [shape.row_]), shape_(shape)
{
    for(std::size_t i = 0; i < shape_.row_; ++i)
        data_[i] = new Type[shape_.col_];
}
template <typename Type>
Matrix<Type>::Matrix(const Matrix& matrix)
    : data_(new Type* [matrix.shape_.row_]), shape_(matrix.shape_)
{
    for(std::size_t i = 0; i < shape_.row_; ++i)
        data_[i] = new Type[shape_.col_];

    for(std::size_t i = 0; i < shape_.row_; ++i)
        for(std::size_t j = 0; j < shape_.col_; ++j)
            data_[i][j] = matrix.data_[i][j];
}

template <typename Type>
Matrix<Type>::Matrix(Matrix&& matrix) noexcept
    : data_(matrix.data_), shape_(matrix.shape_)
{
    matrix.data_ = nullptr;
}

template <typename Type>
Matrix<Type>& Matrix<Type>::operator= (const Matrix& matrix)
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

template <typename Type>
Matrix<Type>& Matrix<Type>::operator= (Matrix&& matrix) noexcept
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

template <typename Type>
inline const typename Matrix<Type>::Shape& Matrix<Type>::size() const noexcept
{
    return shape_;
}

template <typename Type>
Matrix<Type>& Matrix<Type>::resize(std::size_t m, std::size_t n)
{
    if(data_ != nullptr)
    {
        for(std::size_t i = 0; i < shape_.row_; ++i)
            delete[] data_[i];
        delete[] data_;
    }

    shape_.row_ = m;
    shape_.col_ = n;
    data_ = new Type* [shape_.row_];
    for(std::size_t i = 0; i < shape_.row_; ++i)
        data_[i] = new Type[shape_.col_];

    return *this;
}

template <typename Type>
Matrix<Type>& Matrix<Type>::resize(const Shape& shape)
{
    return resize(shape.row_, shape.col_);
}

template <typename Type>
Matrix<Type>& Matrix<Type>::fill(Type (*generator)()) noexcept
{
    for(std::size_t i = 0; i < shape_.row_; ++i)
        for(std::size_t j = 0; j < shape_.col_; ++j)
            data_[i][j] = generator();

    return *this;
}

template <typename Type>
Matrix<Type>& Matrix<Type>::fill(Type value) noexcept
{
    for(std::size_t i = 0; i < shape_.row_; ++i)
        for(std::size_t j = 0; j < shape_.col_; ++j)
            data_[i][j] = value;

    return *this;
}

template <typename Type>
Matrix<Type> Matrix<Type>::apply(Type (*function)(Type)) const
{
    Matrix new_matrix(shape_);

    for(std::size_t i = 0; i < shape_.row_; ++i)
        for(std::size_t j = 0; j < shape_.col_; ++j)
            new_matrix.data_[i][j] = function(data_[i][j]);

    return new_matrix;
}

template <typename Type>
Matrix<Type>& Matrix<Type>::modify(Type (*function)(Type)) noexcept
{
    for(std::size_t i = 0; i < shape_.row_; ++i)
        for(std::size_t j = 0; j < shape_.col_; ++j)
            data_[i][j] = function(data_[i][j]);

    return *this;
}

template <typename Type>
inline Type& Matrix<Type>::operator() (std::size_t i, std::size_t j) noexcept
{
    return data_[i][j];
}

template <typename Type>
inline const Type& Matrix<Type>::operator() (std::size_t i, std::size_t j) const noexcept
{
    return data_[i][j];
}

template <typename Type>
Matrix<Type> Matrix<Type>::dot(const Matrix& matrix) const
{
    Matrix new_matrix(shape_.row_, matrix.shape_.col_);
    Type result = 0.0;

    for(std::size_t i = 0; i < shape_.row_; ++i)
    {
        for(std::size_t j = 0; j <  matrix.shape_.col_; ++j)
        {
            for(std::size_t r = 0; r < shape_.col_; ++r)
                result += data_[i][r] * matrix.data_[r][j];

            new_matrix.data_[i][j] = result;
            result = 0.0;
        }
    }

    return new_matrix;
}

template <typename Type>
Matrix<Type> Matrix<Type>::multiply(const Matrix& matrix) const
{
    Matrix new_matrix(matrix.shape_);

    for(std::size_t i = 0; i < shape_.row_; ++i)
        for(std::size_t j = 0; j < shape_.col_; ++j)
            new_matrix.data_[i][j] = data_[i][j] * matrix.data_[i][j];

    return new_matrix;
}

template <typename Type>
Matrix<Type> Matrix<Type>::join(Type value) const
{
    Matrix<Type> new_matrix(shape_);

    for(std::size_t i = 0; i < shape_.row_; ++i)
        for(std::size_t j = 0; j < shape_.col_; ++j)
            new_matrix.data_[i][j] = data_[i][j] * value;

    return new_matrix;
}

template <typename Type>
Matrix<Type> Matrix<Type>::transpose() const
{
    Matrix new_matrix(shape_.col_, shape_.row_);

    for(std::size_t i = 0; i < shape_.col_; ++i)
        for(std::size_t j = 0; j < shape_.row_; ++j)
            new_matrix.data_[i][j] = data_[j][i];

    return new_matrix;
}

template <typename Type>
Matrix<Type> Matrix<Type>::operator+ (const Matrix& matrix) const
{
    Matrix new_matrix(shape_);

    for(std::size_t i = 0; i < shape_.row_; ++i)
        for(std::size_t j = 0; j < shape_.col_; ++j)
            new_matrix.data_[i][j] = data_[i][j] + matrix.data_[i][j];

    return new_matrix;
}

template <typename Type>
Matrix<Type> Matrix<Type>::operator- (const Matrix& matrix) const
{
    Matrix new_matrix(shape_);

    for(std::size_t i = 0; i < shape_.row_; ++i)
        for(std::size_t j = 0; j < shape_.col_; ++j)
            new_matrix.data_[i][j] = data_[i][j] - matrix.data_[i][j];

    return new_matrix;
}

template <typename Type>
Matrix<Type>& Matrix<Type>::operator+= (const Matrix& matrix) noexcept
{
    for(std::size_t i = 0; i < shape_.row_; ++i)
        for(std::size_t j = 0; j < shape_.col_; ++j)
            data_[i][j] += matrix.data_[i][j];

    return *this;
}

template <typename Type>
Matrix<Type>& Matrix<Type>::operator-= (const Matrix& matrix) noexcept
{
    for(std::size_t i = 0; i < shape_.row_; ++i)
        for(std::size_t j = 0; j < shape_.col_; ++j)
            data_[i][j] -= matrix.data_[i][j];

    return *this;
}

} // namespace lique

#endif // LIQUE_MATRIX_HPP
