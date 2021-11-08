#ifndef LIQUE_MATRIX_HPP
#define LIQUE_MATRIX_HPP

namespace var_matrix
{

extern int D;
extern int C;
extern int CC;
extern int M;

} // namespace var_matrix

#include <cstddef> // size_t

namespace lique
{

template <typename Type>
class Matrix
{
protected:
    class Shape;

public:
    using reference       = Type&;
    using const_reference = const Type&;
    using size_type       = std::size_t;

protected:
    Type** data_;
    Shape shape_;

public:
    Matrix() noexcept;
    ~Matrix();
    explicit Matrix(size_type m, size_type n);
    explicit Matrix(const Shape& shape);
    Matrix(const Matrix&);
    Matrix(Matrix&&) noexcept;

    Matrix& operator= (const Matrix&);
    Matrix& operator= (Matrix&&) noexcept;

    const Shape& size() const noexcept;
    void resize(size_type m, size_type n);
    void resize(const Shape& new_shape);

    Matrix& fill(Type (*generator)()) noexcept;
    Matrix& fill(Type value) noexcept;

    Matrix apply(Type (*function)(Type)) const;
    Matrix& modify(Type (*function)(Type)) noexcept;

    reference operator() (size_type i, size_type j) noexcept;
    const_reference operator() (size_type i, size_type j) const noexcept;

    Matrix dot(const Matrix&) const;

    Matrix multiply(const Matrix&) const;
    Matrix& multiply(const Matrix&) noexcept;

    Matrix join(Type value) const;
    Matrix& join(Type value) noexcept;

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

template <typename Type>
inline Matrix<Type>::Matrix() noexcept : data_(nullptr), shape_(0, 0)
{
    ++var_matrix::D;
}

template <typename Type>
Matrix<Type>::~Matrix()
{
    if(data_ != nullptr)
    {
        for(size_type i = 0; i < shape_.row_; ++i)
            delete[] data_[i];
        delete[] data_;
    }
}

template <typename Type>
Matrix<Type>::Matrix(std::size_t m, std::size_t n) : data_(new Type* [m]), shape_(m, n)
{
    ++var_matrix::C;
    for(size_type i = 0; i < shape_.row_; ++i)
        data_[i] = new Type[shape_.col_];
}
template <typename Type>
Matrix<Type>::Matrix(const Shape& shape) : data_(new Type* [shape.row_]), shape_(shape)
{
    ++var_matrix::C;
    for(size_type i = 0; i < shape_.row_; ++i)
        data_[i] = new Type[shape_.col_];
}
template <typename Type>
Matrix<Type>::Matrix(const Matrix& matrix)
    : data_(new Type* [matrix.shape_.row_]), shape_(matrix.shape_)
{
    ++var_matrix::CC;
    for(size_type i = 0; i < shape_.row_; ++i)
        data_[i] = new Type[shape_.col_];

    for(size_type i = 0; i < shape_.row_; ++i)
        for(size_type j = 0; j < shape_.col_; ++j)
            data_[i][j] = matrix.data_[i][j];
}

template <typename Type>
inline Matrix<Type>::Matrix(Matrix&& matrix) noexcept
    : data_(matrix.data_), shape_(matrix.shape_)
{
    ++var_matrix::M;
    matrix.data_ = nullptr;
}

template <typename Type>
Matrix<Type>& Matrix<Type>::operator= (const Matrix& matrix)
{
    ++var_matrix::CC;
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

template <typename Type>
Matrix<Type>& Matrix<Type>::operator= (Matrix&& matrix) noexcept
{
    ++var_matrix::M;
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

template <typename Type>
inline const typename Matrix<Type>::Shape& Matrix<Type>::size() const noexcept
{
    return shape_;
}

template <typename Type>
void Matrix<Type>::resize(size_type m, size_type n)
{
    if(data_ != nullptr)
    {
        for(size_type i = 0; i < shape_.row_; ++i)
            delete[] data_[i];
        delete[] data_;
    }

    shape_.row_ = m;
    shape_.col_ = n;
    data_ = new Type* [shape_.row_];
    for(size_type i = 0; i < shape_.row_; ++i)
        data_[i] = new Type[shape_.col_];
}

template <typename Type>
void Matrix<Type>::resize(const Shape& shape)
{
    if(data_ != nullptr)
    {
        for(size_type i = 0; i < shape_.row_; ++i)
            delete[] data_[i];
        delete[] data_;
    }

    shape_ = shape;
    data_ = new Type* [shape_.row_];
    for(size_type i = 0; i < shape_.row_; ++i)
        data_[i] = new Type[shape_.col_];
}

template <typename Type>
Matrix<Type>& Matrix<Type>::fill(Type (*generator)()) noexcept
{
    for(size_type i = 0; i < shape_.row_; ++i)
        for(size_type j = 0; j < shape_.col_; ++j)
            data_[i][j] = generator();

    return *this;
}

template <typename Type>
Matrix<Type>& Matrix<Type>::fill(Type value) noexcept
{
    for(size_type i = 0; i < shape_.row_; ++i)
        for(size_type j = 0; j < shape_.col_; ++j)
            data_[i][j] = value;

    return *this;
}

template <typename Type>
Matrix<Type> Matrix<Type>::apply(Type (*function)(Type)) const
{
    Matrix new_matrix(shape_);

    for(size_type i = 0; i < shape_.row_; ++i)
        for(size_type j = 0; j < shape_.col_; ++j)
            new_matrix.data_[i][j] = function(data_[i][j]);

    return new_matrix;
}

template <typename Type>
Matrix<Type>& Matrix<Type>::modify(Type (*function)(Type)) noexcept
{
    for(size_type i = 0; i < shape_.row_; ++i)
        for(size_type j = 0; j < shape_.col_; ++j)
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

    for(size_type i = 0; i < shape_.row_; ++i)
    {
        for(size_type j = 0; j <  matrix.shape_.col_; ++j)
        {
            for(size_type r = 0; r < shape_.col_; ++r)
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

    for(size_type i = 0; i < shape_.row_; ++i)
        for(size_type j = 0; j < shape_.col_; ++j)
            new_matrix.data_[i][j] = data_[i][j] * matrix.data_[i][j];

    return new_matrix;
}

template <typename Type>
Matrix<Type>& Matrix<Type>::multiply(const Matrix& matrix) noexcept
{
    for(size_type i = 0; i < shape_.row_; ++i)
        for(size_type j = 0; j < shape_.col_; ++j)
            data_[i][j] *= matrix.data_[i][j];

    return *this;
}

template <typename Type>
Matrix<Type> Matrix<Type>::join(Type value) const
{
    Matrix new_matrix(shape_);

    for(size_type i = 0; i < shape_.row_; ++i)
        for(size_type j = 0; j < shape_.col_; ++j)
            new_matrix.data_[i][j] = data_[i][j] *= value;

    return new_matrix;
}

template <typename Type>
Matrix<Type>& Matrix<Type>::join(Type value) noexcept
{
    for(size_type i = 0; i < shape_.row_; ++i)
        for(size_type j = 0; j < shape_.col_; ++j)
            data_[i][j] *= value;

    return *this;
}

template <typename Type>
Matrix<Type> Matrix<Type>::transpose() const
{
    Matrix new_matrix(shape_.col_, shape_.row_);

    for(size_type i = 0; i < shape_.col_; ++i)
        for(size_type j = 0; j < shape_.row_; ++j)
            new_matrix.data_[i][j] = data_[j][i];

    return new_matrix;
}

template <typename Type>
Matrix<Type> Matrix<Type>::operator+ (const Matrix& matrix) const
{
    Matrix new_matrix(shape_);

    for(size_type i = 0; i < shape_.row_; ++i)
        for(size_type j = 0; j < shape_.col_; ++j)
            new_matrix.data_[i][j] = data_[i][j] + matrix.data_[i][j];

    return new_matrix;
}

template <typename Type>
Matrix<Type> Matrix<Type>::operator- (const Matrix& matrix) const
{
    Matrix new_matrix(shape_);

    for(size_type i = 0; i < shape_.row_; ++i)
        for(size_type j = 0; j < shape_.col_; ++j)
            new_matrix.data_[i][j] = data_[i][j] - matrix.data_[i][j];

    return new_matrix;
}

template <typename Type>
Matrix<Type>& Matrix<Type>::operator+= (const Matrix& matrix) noexcept
{
    for(size_type i = 0; i < shape_.row_; ++i)
        for(size_type j = 0; j < shape_.col_; ++j)
            data_[i][j] += matrix.data_[i][j];

    return *this;
}

template <typename Type>
Matrix<Type>& Matrix<Type>::operator-= (const Matrix& matrix) noexcept
{
    for(size_type i = 0; i < shape_.row_; ++i)
        for(size_type j = 0; j < shape_.col_; ++j)
            data_[i][j] -= matrix.data_[i][j];

    return *this;
}

} // namespace lique

#endif // LIQUE_MATRIX_HPP
