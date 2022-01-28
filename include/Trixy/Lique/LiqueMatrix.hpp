#ifndef LIQUE_MATRIX_HPP
#define LIQUE_MATRIX_HPP

#include <cstddef> // size_t
#include <cmath> // fabs
#include <initializer_list> // initializer_list

#include "LiqueBaseTensor.hpp"

#include "Detail/FunctionDetail.hpp"
#include "Detail/LiqueMeta.hpp"

#include "Detail/MacroScope.hpp"

namespace lique
{

LIQUE_TENSOR_TPL_DECLARATION
using Matrix = LIQUE_TENSOR_TPL(TensorType::matrix, LockerType::free);

LIQUE_TENSOR_TPL_DECLARATION
using LockMatrix = LIQUE_TENSOR_TPL(TensorType::matrix, LockerType::lock);

LIQUE_TENSOR_TPL_DECLARATION
class LIQUE_TENSOR_TPL(TensorType::matrix, LockerType::lock)
{
protected:
    class Shape;

public:
    using size_type       = std::size_t;

    using pointer        = Precision*;
    using const_pointer  = Precision* const;

    using Generator       = Precision (*)();
    using Function        = Precision (*)(Precision);

protected:
    pointer data_;
    Shape  shape_;

public:
    Tensor() noexcept;
    ~Tensor();

    explicit Tensor(size_type size);
    Tensor(size_type size, const Precision* ptr);

    explicit Tensor(size_type m, size_type n);
    explicit Tensor(size_type m, size_type n, Precision value);
    Tensor(size_type m, size_type n, const Precision* ptr);

    explicit Tensor(const Shape& shape);
    Tensor(const Shape& shape, Precision value);
    Tensor(const Shape& shape, const Precision* ptr);

    Tensor(const Tensor&);
    Tensor(Tensor&&) noexcept;

    Tensor& copy(const Precision* ptr) noexcept;
    Tensor& copy(const Tensor&) noexcept;
    Tensor& copy(std::initializer_list<Precision>) noexcept;

    const Shape& shape() const noexcept;
    size_type size() const noexcept;

    Tensor& fill(Generator gen) noexcept;
    Tensor& fill(Precision value) noexcept;

    Tensor apply(Function func) const;
    Tensor& apply(Function func) noexcept;
    Tensor& apply(Function func, const Tensor&) noexcept;

    Precision& operator() (size_type i, size_type j) noexcept;
    const Precision& operator() (size_type i, size_type j) const noexcept;

    Precision& operator() (size_type i) noexcept;
    const Precision& operator() (size_type i) const noexcept;

    Tensor add(const Tensor&) const;
    Tensor& add(const Tensor&) noexcept;
    Tensor& add(const Tensor&, const Tensor&) noexcept;

    Tensor sub(const Tensor&) const;
    Tensor& sub(const Tensor&) noexcept;
    Tensor& sub(const Tensor&, const Tensor&) noexcept;

    Tensor multiply(const Tensor&) const;
    Tensor& multiply(const Tensor&) noexcept;
    Tensor& multiply(const Tensor&, const Tensor&) noexcept;

    Tensor join(Precision value) const;
    Tensor& join(Precision value) noexcept;
    Tensor& join(Precision value, const Tensor&) noexcept;

    Tensor transpose() const;
    Tensor inverse() const;

    Precision* data() noexcept;
    const Precision* data() const noexcept;

protected:
    Tensor& operator= (const Tensor&);
    Tensor& operator= (Tensor&&) noexcept;
};

LIQUE_TENSOR_TPL_DECLARATION
class LIQUE_TENSOR_TPL(TensorType::matrix, LockerType::free) : public LockMatrix<Precision>
{
private:
    using LockTensor = LockMatrix<Precision>;

public:
    using size_type  = typename LockTensor::size_type;
    using Shape      = typename LockTensor::Shape;

public:
    using LockTensor::operator=;

public:
    Tensor() noexcept = default;
    ~Tensor() = default;

    Tensor& operator= (const Tensor& vector) = default;
    Tensor& operator= (Tensor&& vector) noexcept = default;

    explicit Tensor(size_type size) : LockTensor(size) {}
    Tensor(size_type size, const Precision* ptr) : LockTensor(size, ptr) {}

    explicit Tensor(size_type m, size_type n) : LockTensor(m, n) {}
    Tensor(size_type m, size_type n, Precision value) : LockTensor(m, n, value) {}
    Tensor(size_type m, size_type n, const Precision* ptr) : LockTensor(m, n, ptr) {}

    explicit Tensor(const Shape& shape) : LockTensor(shape) {}
    Tensor(const Shape& shape, Precision value) : LockTensor(shape, value) {}
    Tensor(const Shape& shape, const Precision* ptr) : LockTensor(shape, ptr) {}

    Tensor(const Tensor& tensor) = default;
    Tensor(Tensor&& tensor) noexcept = default;

    Tensor(const LockTensor& tensor) : LockTensor(tensor) {}
    Tensor(LockTensor&& tensor) noexcept : LockTensor(tensor) {}

    Tensor dot(const Tensor&) const;

    void resize(size_type new_size);
    void resize(size_type m, size_type n);
    void resize(const Shape& new_shape);

    void resize(size_type new_size, Precision value);
    void resize(size_type m, size_type n, Precision value);
    void resize(const Shape& new_shape, Precision value);

    void reshape(size_type m, size_type n) noexcept;

    Tensor& inverse();
};

LIQUE_TENSOR_TPL_DECLARATION
class LockMatrix<Precision>::Shape
{
friend LockMatrix<Precision>;
friend Matrix<Precision>;

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

protected:
    Shape& operator= (const Shape& shape) = default;
};

LIQUE_TENSOR_TPL_DECLARATION
void Matrix<Precision>::resize(size_type size)
{
    delete[] this->data_;

    this->shape_.row_  = 1;
    this->shape_.col_  = size;
    this->shape_.size_ = size;

    this->data_ = new Precision [this->shape_.size_];
}

LIQUE_TENSOR_TPL_DECLARATION
void Matrix<Precision>::resize(size_type m, size_type n)
{
    delete[] this->data_;

    this->shape_.row_  = m;
    this->shape_.col_  = n;
    this->shape_.size_ = m * n;

    this->data_ = new Precision [this->shape_.size_];
}

LIQUE_TENSOR_TPL_DECLARATION
void Matrix<Precision>::resize(const Tensor::Shape& shape)
{
    delete[] this->data_;

    this->shape_ = shape;
    this->data_  = new Precision [this->shape_.size_];
}

LIQUE_TENSOR_TPL_DECLARATION
void Matrix<Precision>::resize(size_type size, Precision value)
{
    resize(1, size);
    this->fill(value);
}

LIQUE_TENSOR_TPL_DECLARATION
void Matrix<Precision>::resize(size_type m, size_type n, Precision value)
{
    resize(m, n);
    this->fill(value);
}

LIQUE_TENSOR_TPL_DECLARATION
void Matrix<Precision>::resize(const Tensor::Shape& shape, Precision value)
{
    resize(shape);
    this->fill(value);
}

LIQUE_TENSOR_TPL_DECLARATION
void Matrix<Precision>::reshape(size_type m, size_type n) noexcept
{
    this->shape_.row_ = m;
    this->shape_.col_ = n;
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision> Matrix<Precision>::dot(const Tensor& matrix) const
{
    Tensor new_matrix(this->shape_.row_, matrix.shape_.col_, 0.);
    Precision buff;

    for(size_type i = 0; i < this->shape_.row_; ++i)
    {
        for(size_type r = 0; r < this->shape_.col_; ++r)
        {
            buff = this->data_[i * this->shape_.col_ + r];
            for(size_type j = 0; j <  matrix.shape_.col_; ++j)
                new_matrix.data_[i * matrix.shape_.col_ + j] += buff * matrix.data_[r * matrix.shape_.col_ + j];
        }
    }

    return new_matrix;
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>& Matrix<Precision>::inverse()
{
    size_type N = this->shape_.row_;

    size_type i;
    size_type j;

    Precision buff;

    Tensor I(this->shape_);

    for(i = 0; i < N; ++i)
        for(j = 0; j < N; ++j)
            I.data_[i * N + j] = (i == j) ? 1. : 0.;

    for(size_type k = 0, p; k < N; ++k)
    {
        p = k;
        for(i = k + 1; i < N; ++i)
            if(std::fabs(this->data_[p * N + k]) < std::fabs(this->data_[i * N + k]))
                p = i;

        if(p != k)
        {
            for(j = k; j < N; ++j)
            {
                buff = this->data_[k * N + j];
                this->data_[k * N + j] = this->data_[p * N + j];
                this->data_[p * N + j] = buff;
            }

            for(j = 0; j < N; ++j)
            {
                buff = I.data_[k * N + j];
                I.data_[k * N + j] = I.data_[p * N + j];
                I.data_[p * N + j] = buff;
            }
        }

        buff = 1. / this->data_[k * N + k];

        for(j = k; j < N; ++j) this->data_[k * N + j] *= buff;
        for(j = 0; j < N; ++j)     I.data_[k * N + j] *= buff;

        for(i = 0; i < N; ++i)
        {
            if(i == k) continue;

            buff = this->data_[i * N + k];

            for(j = k; j < N; ++j) this->data_[i * N + j] -= this->data_[k * N + j] * buff;
            for(j = 0; j < N; ++j)     I.data_[i * N + j] -=     I.data_[k * N + j] * buff;
        }
    }

    delete[] this->data_;

    this->data_ = I.data_;
    I.data_     = nullptr;

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
inline LockMatrix<Precision>::Tensor() noexcept : data_(nullptr), shape_(0, 0)
{
}

LIQUE_TENSOR_TPL_DECLARATION
inline LockMatrix<Precision>::~Tensor()
{
    delete[] data_;
}

LIQUE_TENSOR_TPL_DECLARATION
inline LockMatrix<Precision>::Tensor(std::size_t size)
    : data_(new Precision [size]), shape_(1, size)
{
}

LIQUE_TENSOR_TPL_DECLARATION
LockMatrix<Precision>::Tensor(std::size_t size, const Precision* ptr)
    : data_(new Precision[size]), shape_(1, size)
{
     detail::copy(data_, data_ + shape_.size_, ptr);
}

LIQUE_TENSOR_TPL_DECLARATION
inline LockMatrix<Precision>::Tensor(std::size_t m, std::size_t n)
    : data_(new Precision [m * n]), shape_(m, n)
{
}

LIQUE_TENSOR_TPL_DECLARATION
LockMatrix<Precision>::Tensor(std::size_t m, std::size_t n, Precision value)
    : data_(new Precision [m * n]), shape_(m, n)
{
    fill(value);
}

LIQUE_TENSOR_TPL_DECLARATION
LockMatrix<Precision>::Tensor(std::size_t m, std::size_t n, const Precision* ptr)
    : data_(new Precision [m * n]), shape_(m, n)
{
     detail::copy(data_, data_ + shape_.size_, ptr);
}

LIQUE_TENSOR_TPL_DECLARATION
inline LockMatrix<Precision>::Tensor(const Tensor::Shape& shape)
    : data_(new Precision [shape.size_]), shape_(shape)
{
}

LIQUE_TENSOR_TPL_DECLARATION
LockMatrix<Precision>::Tensor(const Tensor::Shape& shape, Precision value)
    : data_(new Precision [shape.size_]), shape_(shape)
{
    fill(value);
}

LIQUE_TENSOR_TPL_DECLARATION
LockMatrix<Precision>::Tensor(const Tensor::Shape& shape, const Precision* ptr)
    : data_(new Precision [shape.size_]), shape_(shape)
{
     detail::copy(data_, data_ + shape_.size_, ptr);
}

LIQUE_TENSOR_TPL_DECLARATION
LockMatrix<Precision>::Tensor(const Tensor& matrix)
    : data_(new Precision [matrix.shape_.size_]), shape_(matrix.shape_)
{
     detail::copy(data_, data_ + shape_.size_, matrix.data_);
}

LIQUE_TENSOR_TPL_DECLARATION
inline LockMatrix<Precision>::Tensor(Tensor&& matrix) noexcept
    : data_(matrix.data_), shape_(matrix.shape_)
{
    matrix.data_ = nullptr;
}

LIQUE_TENSOR_TPL_DECLARATION
LockMatrix<Precision>& LockMatrix<Precision>::operator= (const Tensor& matrix)
{
    if(this != &matrix)
    {
        delete[] data_;

        shape_ = matrix.shape_;
        data_  = new Precision [shape_.size_];

         detail::copy(data_, data_ + shape_.size_, matrix.data_);
    }

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LockMatrix<Precision>& LockMatrix<Precision>::operator= (Tensor&& matrix) noexcept
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
LockMatrix<Precision>& LockMatrix<Precision>::copy( const Precision* ptr) noexcept
{
    copy(data_, data_ + shape_.size_, ptr);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LockMatrix<Precision>& LockMatrix<Precision>::copy(const Tensor& matrix) noexcept
{
    if(this != &matrix)
         detail::copy(data_, data_ + shape_.size_, matrix.data_);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LockMatrix<Precision>& LockMatrix<Precision>::copy(
    std::initializer_list<Precision> data) noexcept
{
     detail::copy(data_, data_ + shape_.size_, data.begin());

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
inline const typename LockMatrix<Precision>::Shape& LockMatrix<Precision>::shape() const noexcept
{
    return shape_;
}

LIQUE_TENSOR_TPL_DECLARATION
inline std::size_t LockMatrix<Precision>::size() const noexcept
{
    return shape_.size_;
}

LIQUE_TENSOR_TPL_DECLARATION
LockMatrix<Precision>& LockMatrix<Precision>::fill(Precision (*gen)()) noexcept
{
    for(size_type i = 0; i < shape_.size_; ++i)
        data_[i] = gen();

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LockMatrix<Precision>& LockMatrix<Precision>::fill(Precision value) noexcept
{
    for(size_type i = 0; i < shape_.size_; ++i)
        data_[i] = value;

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LockMatrix<Precision> LockMatrix<Precision>::apply(
    Precision (*func)(Precision)) const
{
    Tensor new_matrix(shape_);

    for(size_type i = 0; i < shape_.size_; ++i)
        new_matrix.data_[i] = func(data_[i]);

    return new_matrix;
}

LIQUE_TENSOR_TPL_DECLARATION
LockMatrix<Precision>& LockMatrix<Precision>::apply(
    Precision (*func)(Precision)) noexcept
{
    for(size_type i = 0; i < shape_.size_; ++i)
        data_[i] = func(data_[i]);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LockMatrix<Precision>& LockMatrix<Precision>::apply(
    Precision (*function)(Precision),
    const Tensor& matrix) noexcept
{
    for(size_type i = 0; i < shape_.size_; ++i)
        data_[i] = function(matrix.data_[i]);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
inline Precision& LockMatrix<Precision>::operator() (std::size_t i, std::size_t j) noexcept
{
    return data_[i * shape_.col_ + j];
}

LIQUE_TENSOR_TPL_DECLARATION
inline const Precision& LockMatrix<Precision>::operator() (std::size_t i, std::size_t j) const noexcept
{
    return data_[i * shape_.col_ + j];
}

LIQUE_TENSOR_TPL_DECLARATION
inline Precision& LockMatrix<Precision>::operator() (std::size_t i) noexcept
{
    return data_[i];
}

LIQUE_TENSOR_TPL_DECLARATION
inline const Precision& LockMatrix<Precision>::operator() (std::size_t i) const noexcept
{
    return data_[i];
}

LIQUE_TENSOR_TPL_DECLARATION
LockMatrix<Precision> LockMatrix<Precision>::add(const Tensor& matrix) const
{
    Tensor new_matrix(shape_.size_);

    for(size_type i = 0; i < shape_.size_; ++i)
        new_matrix.data_[i] = data_[i] + matrix.data_[i];

    return new_matrix;
}

LIQUE_TENSOR_TPL_DECLARATION
LockMatrix<Precision>& LockMatrix<Precision>::add(const Tensor& matrix) noexcept
{
    for(size_type i = 0; i < shape_.size_; ++i)
        data_[i] += matrix.data_[i];

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LockMatrix<Precision>& LockMatrix<Precision>::add(const Tensor& lhs, const Tensor& rhs) noexcept
{
    for(size_type i = 0; i < shape_.size_; ++i)
        data_[i] = lhs.data_[i] + rhs.data_[i];

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LockMatrix<Precision> LockMatrix<Precision>::sub(const Tensor& matrix) const
{
    Tensor new_matrix(shape_);

    for(size_type i = 0; i < shape_.size_; ++i)
        new_matrix.data_[i] = data_[i] - matrix.data_[i];

    return new_matrix;
}

LIQUE_TENSOR_TPL_DECLARATION
LockMatrix<Precision>& LockMatrix<Precision>::sub(const Tensor& matrix) noexcept
{
    for(size_type i = 0; i < shape_.size_; ++i)
        data_[i] -= matrix.data_[i];

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LockMatrix<Precision>& LockMatrix<Precision>::sub(const Tensor& lhs, const Tensor& rhs) noexcept
{
    for(size_type i = 0; i < shape_.size_; ++i)
        data_[i] = lhs.data_[i] - rhs.data_[i];

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LockMatrix<Precision> LockMatrix<Precision>::multiply(const Tensor& matrix) const
{
    Tensor new_matrix(shape_);

    for(size_type i = 0; i < shape_.size_; ++i)
        new_matrix.data_[i] = data_[i] * matrix.data_[i];

    return new_matrix;
}

LIQUE_TENSOR_TPL_DECLARATION
LockMatrix<Precision>& LockMatrix<Precision>::multiply(const Tensor& matrix) noexcept
{
    for(size_type i = 0; i < shape_.size_; ++i)
        data_[i] *= matrix.data_[i];

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LockMatrix<Precision>& LockMatrix<Precision>::multiply(const Tensor& lsh, const Tensor& rsh) noexcept
{
    for(size_type i = 0; i < shape_.size_; ++i)
        data_[i] = lsh.data_[i] * rsh.data_[i];

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LockMatrix<Precision> LockMatrix<Precision>::join(Precision value) const
{
    Tensor new_matrix(shape_);

    for(size_type i = 0; i < shape_.size_; ++i)
        new_matrix.data_[i] = value * data_[i];

    return new_matrix;
}

LIQUE_TENSOR_TPL_DECLARATION
LockMatrix<Precision>& LockMatrix<Precision>::join(Precision value) noexcept
{
    for(size_type i = 0; i < shape_.size_; ++i)
        data_[i] *= value;

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LockMatrix<Precision>& LockMatrix<Precision>::join(Precision value, const Tensor& matrix) noexcept
{
    for(size_type i = 0; i < shape_.size_; ++i)
        data_[i] = value * matrix.data_[i];

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LockMatrix<Precision> LockMatrix<Precision>::transpose() const
{
    Tensor new_matrix(shape_.col_, shape_.row_);

    for(size_type i = 0; i < shape_.col_; ++i)
        for(size_type j = 0; j < shape_.row_; ++j)
            new_matrix.data_[i * shape_.row_ + j] = data_[j * shape_.col_ + i];

    return new_matrix;
}

LIQUE_TENSOR_TPL_DECLARATION
LockMatrix<Precision> LockMatrix<Precision>::inverse() const
{
    size_type N = shape_.row_;

    size_type i;
    size_type j;

    Precision buff;

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
inline Precision* LockMatrix<Precision>::data() noexcept
{
    return data_;
}

LIQUE_TENSOR_TPL_DECLARATION
inline const Precision* LockMatrix<Precision>::data() const noexcept
{
    return data_;
}

} // namespace lique

#include "Detail/MacroUnscope.hpp"

#endif // LIQUE_MATRIX_HPP
