#ifndef LIQUE_MATRIX_HPP
#define LIQUE_MATRIX_HPP

#include <cstddef> // size_t
#include <cmath> // fabs
#include <initializer_list> // initializer_list

#include "LiqueBaseTensor.hpp"

#include "Detail/FunctionDetail.hpp"
#include "Detail/LiqueMeta.hpp"

#include "Detail/MacroScope.hpp"

namespace trixy
{

namespace lique
{

LIQUE_TENSOR_TPL_DECLARATION
using Matrix = LIQUE_TENSOR_TPL(TensorType::matrix);

LIQUE_TENSOR_TPL_DECLARATION
class LIQUE_TENSOR_TPL(TensorType::matrix) : public TensorType::matrix
{
protected:
    class Shape;

public:
    using size_type         = std::size_t;
    using precision_type    = Precision;

    using pointer           = Precision*;
    using const_pointer     = const Precision*;

    using reference         = Precision&;
    using const_reference   = const Precision&;

    using Generator         = Precision (*)();
    using Function          = Precision (*)(Precision);

protected:
    pointer data_;
    Shape  shape_;

public:
    Tensor() noexcept;
    ~Tensor();

    explicit Tensor(size_type size);
    Tensor(size_type size, const_pointer ptr);

    explicit Tensor(size_type m, size_type n);
    explicit Tensor(size_type m, size_type n, precision_type value);
    Tensor(size_type m, size_type n, const_pointer ptr);

    explicit Tensor(const Shape& shape);
    Tensor(const Shape& shape, precision_type value);
    Tensor(const Shape& shape, const_pointer ptr);

    Tensor(const Tensor&);
    Tensor(Tensor&&) noexcept;

    Tensor& operator= (const Tensor&);
    Tensor& operator= (Tensor&&) noexcept;

    Tensor& copy(const_pointer ptr) noexcept;
    Tensor& copy(const Tensor&) noexcept;
    Tensor& copy(std::initializer_list<precision_type>) noexcept;

    const Shape& shape() const noexcept;
    size_type size() const noexcept;

    void resize(size_type size);
    void resize(size_type m, size_type n);
    void resize(const Shape& shape);

    void resize(size_type m, size_type n, precision_type value);
    void resize(const Shape& shape, precision_type value);

    void resize(size_type m, size_type n, const_pointer src);
    void resize(const Shape& shape, const_pointer src);

    void reshape(size_type m, size_type n) noexcept;

    Tensor& fill(Generator gen) noexcept;
    Tensor& fill(precision_type value) noexcept;

    Tensor apply(Function func) const;
    Tensor& apply(Function func) noexcept;
    Tensor& apply(Function func, const Tensor&) noexcept;

    reference operator() (size_type i, size_type j) noexcept;
    const_reference operator() (size_type i, size_type j) const noexcept;

    reference operator() (size_type i) noexcept;
    const_reference operator() (size_type i) const noexcept;

    Tensor dot(const Tensor&) const;

    Tensor add(const Tensor&) const;
    Tensor& add(const Tensor&) noexcept;
    Tensor& add(const Tensor&, const Tensor&) noexcept;

    Tensor sub(const Tensor&) const;
    Tensor& sub(const Tensor&) noexcept;
    Tensor& sub(const Tensor&, const Tensor&) noexcept;

    Tensor multiply(const Tensor&) const;
    Tensor& multiply(const Tensor&) noexcept;
    Tensor& multiply(const Tensor&, const Tensor&) noexcept;

    Tensor join(precision_type value) const;
    Tensor& join(precision_type value) noexcept;
    Tensor& join(precision_type value, const Tensor&) noexcept;

    Tensor transpose() const;

    Tensor inverse() const;
    Tensor& inverse();

    pointer data() noexcept;
    const_pointer data() const noexcept;
};

LIQUE_TENSOR_TPL_DECLARATION
class Matrix<Precision>::Shape
{
friend Matrix<Precision>;

protected:
    size_type row_;
    size_type col_;

    size_type size_;

public:
    explicit Shape(size_type m, size_type n) noexcept
    : row_(m), col_(n), size_(m * n) {}

    Shape(const Shape& shape) noexcept
    : row_(shape.row_), col_(shape.col_), size_(shape.size_) {}

    size_type row() const noexcept { return row_; }
    size_type col() const noexcept { return col_; }

protected:
    Shape& operator= (const Shape& shape) = default;
};

LIQUE_TENSOR_TPL_DECLARATION
inline Matrix<Precision>::Tensor() noexcept : data_(nullptr), shape_(0, 0)
{
}

LIQUE_TENSOR_TPL_DECLARATION
inline Matrix<Precision>::~Tensor()
{
    delete[] data_;
}

LIQUE_TENSOR_TPL_DECLARATION
inline Matrix<Precision>::Tensor(size_type size)
    : data_(new precision_type [size]), shape_(1, size)
{
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>::Tensor(size_type size, const_pointer src)
    : data_(new precision_type [size]), shape_(1, size)
{
     detail::copy(data_, data_ + shape_.size_, src);
}

LIQUE_TENSOR_TPL_DECLARATION
inline Matrix<Precision>::Tensor(size_type m, size_type n)
    : data_(new precision_type [m * n]), shape_(m, n)
{
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>::Tensor(size_type m, size_type n, precision_type value)
    : data_(new precision_type [m * n]), shape_(m, n)
{
    fill(value);
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>::Tensor(size_type m, size_type n, const_pointer src)
    : data_(new precision_type [m * n]), shape_(m, n)
{
     detail::copy(data_, data_ + shape_.size_, src);
}

LIQUE_TENSOR_TPL_DECLARATION
inline Matrix<Precision>::Tensor(const Shape& shape)
    : data_(new precision_type [shape.size_]), shape_(shape)
{
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>::Tensor(const Shape& shape, precision_type value)
    : data_(new precision_type [shape.size_]), shape_(shape)
{
    fill(value);
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>::Tensor(const Shape& shape, const_pointer src)
    : data_(new precision_type [shape.size_]), shape_(shape)
{
     detail::copy(data_, data_ + shape_.size_, src);
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>::Tensor(const Tensor& matrix)
    : data_(new precision_type [matrix.shape_.size_]), shape_(matrix.shape_)
{
     detail::copy(data_, data_ + shape_.size_, matrix.data_);
}

LIQUE_TENSOR_TPL_DECLARATION
inline Matrix<Precision>::Tensor(Tensor&& matrix) noexcept
    : data_(matrix.data_), shape_(matrix.shape_)
{
    matrix.data_ = nullptr;
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>& Matrix<Precision>::operator= (const Tensor& matrix)
{
    if(this != &matrix)
    {
        delete[] data_;

        shape_ = matrix.shape_;
        data_  = new precision_type [shape_.size_];

         detail::copy(data_, data_ + shape_.size_, matrix.data_);
    }

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>& Matrix<Precision>::operator= (Tensor&& matrix) noexcept
{
    if(this != &matrix)
    {
        delete[] data_;

        data_  = matrix.data_;
        shape_ = matrix.shape_;

        matrix.data_ = nullptr;
    }

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>& Matrix<Precision>::copy(const_pointer src) noexcept
{
    copy(data_, data_ + shape_.size_, src);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>& Matrix<Precision>::copy(const Tensor& matrix) noexcept
{
    if(this != &matrix)
         detail::copy(data_, data_ + shape_.size_, matrix.data_);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>& Matrix<Precision>::copy(
    std::initializer_list<precision_type> data) noexcept
{
     detail::copy(data_, data_ + shape_.size_, data.begin());

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
inline const typename Matrix<Precision>::Shape& Matrix<Precision>::shape() const noexcept
{
    return shape_;
}

LIQUE_TENSOR_TPL_DECLARATION
inline typename Matrix<Precision>::size_type Matrix<Precision>::size() const noexcept
{
    return shape_.size_;
}

LIQUE_TENSOR_TPL_DECLARATION
void Matrix<Precision>::resize(size_type size)
{
    delete[] data_;

    shape_.row_  = 1;
    shape_.col_  = size;
    shape_.size_ = size;

    data_ = new precision_type [shape_.size_];
}

LIQUE_TENSOR_TPL_DECLARATION
void Matrix<Precision>::resize(size_type m, size_type n)
{
    delete[] data_;

    shape_.row_  = m;
    shape_.col_  = n;
    shape_.size_ = m * n;

    data_ = new precision_type [shape_.size_];
}

LIQUE_TENSOR_TPL_DECLARATION
void Matrix<Precision>::resize(const Shape& shape)
{
    delete[] data_;

    shape_ = shape;
    data_  = new precision_type [shape_.size_];
}

LIQUE_TENSOR_TPL_DECLARATION
void Matrix<Precision>::resize(size_type m, size_type n, precision_type value)
{
    resize(m, n);
    fill(value);
}

LIQUE_TENSOR_TPL_DECLARATION
void Matrix<Precision>::resize(const Shape& shape, precision_type value)
{
    resize(shape);
    fill(value);
}

LIQUE_TENSOR_TPL_DECLARATION
void Matrix<Precision>::resize(size_type m, size_type n, const_pointer src)
{
    resize(m, n);

    detail::copy(data_, data_ + shape_.size_, src);
}

LIQUE_TENSOR_TPL_DECLARATION
void Matrix<Precision>::resize(const Shape& shape, const_pointer src)
{
    resize(shape);

    detail::copy(data_, data_ + shape_.size_, src);
}

LIQUE_TENSOR_TPL_DECLARATION
void Matrix<Precision>::reshape(size_type m, size_type n) noexcept
{
    shape_.row_ = m;
    shape_.col_ = n;
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>& Matrix<Precision>::fill(Generator gen) noexcept
{
    for(size_type i = 0; i < shape_.size_; ++i)
        data_[i] = gen();

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>& Matrix<Precision>::fill(precision_type value) noexcept
{
    for(size_type i = 0; i < shape_.size_; ++i)
        data_[i] = value;

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision> Matrix<Precision>::apply(Function func) const
{
    Tensor new_matrix(shape_);

    for(size_type i = 0; i < shape_.size_; ++i)
        new_matrix.data_[i] = func(data_[i]);

    return new_matrix;
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>& Matrix<Precision>::apply(Function func) noexcept
{
    for(size_type i = 0; i < shape_.size_; ++i)
        data_[i] = func(data_[i]);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>& Matrix<Precision>::apply(Function func, const Tensor& matrix) noexcept
{
    for(size_type i = 0; i < shape_.size_; ++i)
        data_[i] = function(matrix.data_[i]);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
inline typename Matrix<Precision>::reference
    Matrix<Precision>::operator() (size_type i, size_type j) noexcept
{
    return data_[i * shape_.col_ + j];
}

LIQUE_TENSOR_TPL_DECLARATION
inline typename Matrix<Precision>::const_reference
    Matrix<Precision>::operator() (size_type i, size_type j) const noexcept
{
    return data_[i * shape_.col_ + j];
}

LIQUE_TENSOR_TPL_DECLARATION
inline typename Matrix<Precision>::reference
    Matrix<Precision>::operator() (size_type i) noexcept
{
    return data_[i];
}

LIQUE_TENSOR_TPL_DECLARATION
inline typename Matrix<Precision>::const_reference
    Matrix<Precision>::operator() (size_type i) const noexcept
{
    return data_[i];
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision> Matrix<Precision>::dot(const Tensor& matrix) const
{
    size_type col = matrix.shape_.col_;

    Tensor new_matrix(shape_.row_, col, 0.);

    precision_type buff;
    for(size_type i = 0; i < shape_.row_; ++i)
    {
        for(size_type r = 0; r < shape_.col_; ++r)
        {
            buff = data_[i * shape_.col_ + r];

            for(size_type j = 0; j <  col; ++j)
                new_matrix.data_[i * col + j] += buff * matrix.data_[r *col + j];
        }
    }

    return new_matrix;
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision> Matrix<Precision>::add(const Tensor& matrix) const
{
    Tensor new_matrix(shape_.size_);

    for(size_type i = 0; i < shape_.size_; ++i)
        new_matrix.data_[i] = data_[i] + matrix.data_[i];

    return new_matrix;
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>& Matrix<Precision>::add(const Tensor& matrix) noexcept
{
    for(size_type i = 0; i < shape_.size_; ++i)
        data_[i] += matrix.data_[i];

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>& Matrix<Precision>::add(const Tensor& lhs, const Tensor& rhs) noexcept
{
    for(size_type i = 0; i < shape_.size_; ++i)
        data_[i] = lhs.data_[i] + rhs.data_[i];

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision> Matrix<Precision>::sub(const Tensor& matrix) const
{
    Tensor new_matrix(shape_);

    for(size_type i = 0; i < shape_.size_; ++i)
        new_matrix.data_[i] = data_[i] - matrix.data_[i];

    return new_matrix;
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>& Matrix<Precision>::sub(const Tensor& matrix) noexcept
{
    for(size_type i = 0; i < shape_.size_; ++i)
        data_[i] -= matrix.data_[i];

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>& Matrix<Precision>::sub(const Tensor& lhs, const Tensor& rhs) noexcept
{
    for(size_type i = 0; i < shape_.size_; ++i)
        data_[i] = lhs.data_[i] - rhs.data_[i];

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision> Matrix<Precision>::multiply(const Tensor& matrix) const
{
    Tensor new_matrix(shape_);

    for(size_type i = 0; i < shape_.size_; ++i)
        new_matrix.data_[i] = data_[i] * matrix.data_[i];

    return new_matrix;
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>& Matrix<Precision>::multiply(const Tensor& matrix) noexcept
{
    for(size_type i = 0; i < shape_.size_; ++i)
        data_[i] *= matrix.data_[i];

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>& Matrix<Precision>::multiply(const Tensor& lsh, const Tensor& rsh) noexcept
{
    for(size_type i = 0; i < shape_.size_; ++i)
        data_[i] = lsh.data_[i] * rsh.data_[i];

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision> Matrix<Precision>::join(precision_type value) const
{
    Tensor new_matrix(shape_);

    for(size_type i = 0; i < shape_.size_; ++i)
        new_matrix.data_[i] = value * data_[i];

    return new_matrix;
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>& Matrix<Precision>::join(precision_type value) noexcept
{
    for(size_type i = 0; i < shape_.size_; ++i)
        data_[i] *= value;

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>& Matrix<Precision>::join(precision_type value, const Tensor& matrix) noexcept
{
    for(size_type i = 0; i < shape_.size_; ++i)
        data_[i] = value * matrix.data_[i];

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision> Matrix<Precision>::transpose() const
{
    Tensor new_matrix(shape_.col_, shape_.row_);

    for(size_type i = 0; i < shape_.col_; ++i)
        for(size_type j = 0; j < shape_.row_; ++j)
            new_matrix.data_[i * shape_.row_ + j] = data_[j * shape_.col_ + i];

    return new_matrix;
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision> Matrix<Precision>::inverse() const
{
    size_type N = shape_.row_;

    size_type i;
    size_type j;

    precision_type buff;

    Tensor A(*this);
    Tensor I(shape_);

    for(i = 0; i < N; ++i)
        for(j = 0; j < N; ++j)
            I.data_[i * N + j] = (i == j) ? 1. : 0.;

    for(size_type k = 0, p; k < N; ++k)
    {
        p = k;
        for(i = k + 1; i < N; ++i)
            if(std::fabs(A.data_[p * N + k]) < std::fabs(A.data_[i * N + k]))
                p = i;

        if(p != k)
        {
            for(j = k; j < N; ++j)
            {
                buff = A.data_[k * N + j];
                A.data_[k * N + j] = A.data_[p * N + j];
                A.data_[p * N + j] = buff;
            }

            for(j = 0; j < N; ++j)
            {
                buff = I.data_[k * N + j];
                I.data_[k * N + j] = I.data_[p * N + j];
                I.data_[p * N + j] = buff;
            }
        }

        buff = 1. / A.data_[k * N + k];

        for(j = k; j < N; ++j) A.data_[k * N + j] *= buff;
        for(j = 0; j < N; ++j) I.data_[k * N + j] *= buff;

        for(i = 0; i < N; ++i)
        {
            if(i == k) continue;

            buff = A.data_[i * N + k];

            for(j = k; j < N; ++j) A.data_[i * N + j] -= A.data_[k * N + j] * buff;
            for(j = 0; j < N; ++j) I.data_[i * N + j] -= I.data_[k * N + j] * buff;
        }
    }

    return I;
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>& Matrix<Precision>::inverse()
{
    size_type N = shape_.row_;

    size_type i;
    size_type j;

    precision_type buff;

    Tensor I(shape_);

    for(i = 0; i < N; ++i)
        for(j = 0; j < N; ++j)
            I.data_[i * N + j] = (i == j) ? 1. : 0.;

    for(size_type k = 0, p; k < N; ++k)
    {
        p = k;
        for(i = k + 1; i < N; ++i)
            if(std::fabs(data_[p * N + k]) < std::fabs(data_[i * N + k]))
                p = i;

        if(p != k)
        {
            for(j = k; j < N; ++j)
            {
                buff = data_[k * N + j];
                data_[k * N + j] = data_[p * N + j];
                data_[p * N + j] = buff;
            }

            for(j = 0; j < N; ++j)
            {
                buff = I.data_[k * N + j];
                I.data_[k * N + j] = I.data_[p * N + j];
                I.data_[p * N + j] = buff;
            }
        }

        buff = 1. / data_[k * N + k];

        for(j = k; j < N; ++j)   data_[k * N + j] *= buff;
        for(j = 0; j < N; ++j) I.data_[k * N + j] *= buff;

        for(i = 0; i < N; ++i)
        {
            if(i == k) continue;

            buff = data_[i * N + k];

            for(j = k; j < N; ++j)   data_[i * N + j] -=   data_[k * N + j] * buff;
            for(j = 0; j < N; ++j) I.data_[i * N + j] -= I.data_[k * N + j] * buff;
        }
    }

    delete[] data_;

    data_   = I.data_;
    I.data_ = nullptr;

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
inline typename Matrix<Precision>::pointer Matrix<Precision>::data() noexcept
{
    return data_;
}

LIQUE_TENSOR_TPL_DECLARATION
inline typename Matrix<Precision>::const_pointer Matrix<Precision>::data() const noexcept
{
    return data_;
}

} // namespace lique

} // namespace trixy

#include "Detail/MacroUnscope.hpp"

#endif // LIQUE_MATRIX_HPP
