#ifndef LIQUE_MATRIX_HPP
#define LIQUE_MATRIX_HPP

#include <cstddef> // size_t
#include <cmath> // fabs
#include <initializer_list> // initializer_list
#include <type_traits> // enable_if, is_arithmetic

#include "Trixy/Lique/lique_tensor_base.hpp"
#include "Trixy/Lique/lique_tensor_id.hpp"

#include "Trixy/Lique/Detail/macro_scope.hpp"

namespace lique
{

LIQUE_TENSOR_TPL_DECLARATION
class LIQUE_TENSOR_TPL(detail::TensorType::_2D)
{
protected:
    class Shape;

public:
    using size_type       = std::size_t;
    using reference       = Precision&;
    using const_reference = const Precision&;

protected:
    Precision** data_;
    Shape shape_;

public:
    Tensor() noexcept;
    ~Tensor();
    explicit Tensor(size_type m, size_type n);
    explicit Tensor(const Shape& shape);

    Tensor(const Tensor&);
    Tensor(Tensor&&) noexcept;

    Tensor& operator= (const Tensor&);
    Tensor& operator= (Tensor&&) noexcept;

    Tensor& copy(const Tensor&) noexcept;
    Tensor& copy(const std::initializer_list<Precision>&) noexcept;

    const Shape& size() const noexcept;

    void resize(size_type m, size_type n);
    void resize(const Shape& new_shape);

    Tensor& fill(Precision (*generator)()) noexcept;
    Tensor& fill(Precision value) noexcept;

    Tensor apply(Precision (*function)(Precision)) const;
    Tensor& apply(Precision (*function)(Precision)) noexcept;
    Tensor& apply(Precision (*function)(Precision), const Tensor&) noexcept;

    reference operator() (size_type i, size_type j) noexcept;
    const_reference operator() (size_type i, size_type j) const noexcept;

    Tensor dot(const Tensor&) const;

    Tensor& add(const Tensor&) noexcept;
    Tensor& sub(const Tensor&) noexcept;

    Tensor multiply(const Tensor&) const;
    Tensor& multiply(const Tensor&) noexcept;
    Tensor& multiply(const Tensor&, const Tensor&) noexcept;

    Tensor join(Precision value) const;
    Tensor& join(Precision value) noexcept;
    Tensor& join(Precision value, const Tensor&) noexcept;

    Tensor transpose() const;

    Tensor inverse() const;
    Tensor& inverse();

    Precision** data() noexcept;
    const Precision** data() const noexcept;

    Tensor operator+ (const Tensor&) const;
    Tensor operator- (const Tensor&) const;
};

LIQUE_TENSOR_TPL_DECLARATION
class LIQUE_TENSOR_TPL(detail::TensorType::_2D)::Shape
{
friend LIQUE_TENSOR_TPL(detail::TensorType::_2D);

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

protected:
    Shape& operator= (const Shape& shape) = default;
};

LIQUE_TENSOR_TPL_DECLARATION
inline LIQUE_TENSOR_TPL(detail::TensorType::_2D)::Tensor() noexcept
    : data_(nullptr), shape_(0, 0)
{
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_2D)::~Tensor()
{
    if(data_ != nullptr)
    {
        for(size_type i = 0; i < shape_.row_; ++i)
            delete[] data_[i];
        delete[] data_;
    }
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_2D)::Tensor(std::size_t m, std::size_t n)
    : data_(new Precision* [m]), shape_(m, n)
{
    for(size_type i = 0; i < shape_.row_; ++i)
        data_[i] = new Precision[shape_.col_];
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_2D)::Tensor(const Tensor::Shape& shape)
    : data_(new Precision* [shape.row_]), shape_(shape)
{
    for(size_type i = 0; i < shape_.row_; ++i)
        data_[i] = new Precision[shape_.col_];
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_2D)::Tensor(const Tensor& matrix)
    : data_(new Precision* [matrix.shape_.row_]), shape_(matrix.shape_)
{
    for(size_type i = 0; i < shape_.row_; ++i)
        data_[i] = new Precision[shape_.col_];

    for(size_type i = 0; i < shape_.row_; ++i)
        for(size_type j = 0; j < shape_.col_; ++j)
            data_[i][j] = matrix.data_[i][j];
}

LIQUE_TENSOR_TPL_DECLARATION
inline LIQUE_TENSOR_TPL(detail::TensorType::_2D)::Tensor(Tensor&& matrix) noexcept
    : data_(matrix.data_), shape_(matrix.shape_)
{
    matrix.data_ = nullptr;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_2D)& LIQUE_TENSOR_TPL(detail::TensorType::_2D)::operator= (
    const Tensor& matrix)
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

    data_ = new Precision* [shape_.row_];
    for(size_type i = 0; i < shape_.row_; ++i)
        data_[i] = new Precision[shape_.col_];

    for(size_type i = 0; i < shape_.row_; ++i)
        for(size_type j = 0; j < shape_.col_; ++j)
            data_[i][j] = matrix.data_[i][j];

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_2D)& LIQUE_TENSOR_TPL(detail::TensorType::_2D)::operator= (
    Tensor&& matrix) noexcept
{
    if(this == &matrix)
        return *this;

    if(data_ != nullptr)
    {
        for(size_type i = 0; i < shape_.row_; ++i)
            delete[] data_[i];
        delete[] data_;
    }

    data_  = matrix.data_;
    shape_ = matrix.shape_;

    matrix.data_ = nullptr;

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_2D)& LIQUE_TENSOR_TPL(detail::TensorType::_2D)::copy(
    const Tensor& matrix) noexcept
{
    if(this == &matrix)
        return *this;

    for(size_type i = 0; i < shape_.row_; ++i)
        for(size_type j = 0; j < shape_.col_; ++j)
            data_[i][j] = matrix.data_[i][j];

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_2D)& LIQUE_TENSOR_TPL(detail::TensorType::_2D)::copy(
    const std::initializer_list<Precision>& data) noexcept
{
    auto it = data.begin();

    for(size_type i = 0; i < shape_.row_; ++i)
        for(size_type j = 0; j < shape_.col_; ++j, ++it)
            data_[i][j] = *it;

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
inline const typename LIQUE_TENSOR_TPL(detail::TensorType::_2D)::Shape& LIQUE_TENSOR_TPL(
    detail::TensorType::_2D)::size() const noexcept
{
    return shape_;
}

LIQUE_TENSOR_TPL_DECLARATION
void LIQUE_TENSOR_TPL(detail::TensorType::_2D)::resize(
    size_type m,
    size_type n)
{
    if(data_ != nullptr)
    {
        for(size_type i = 0; i < shape_.row_; ++i)
            delete[] data_[i];
        delete[] data_;
    }

    shape_.row_ = m;
    shape_.col_ = n;
    data_ = new Precision* [shape_.row_];
    for(size_type i = 0; i < shape_.row_; ++i)
        data_[i] = new Precision[shape_.col_];
}

LIQUE_TENSOR_TPL_DECLARATION
void LIQUE_TENSOR_TPL(detail::TensorType::_2D)::resize(
    const Tensor::Shape& shape)
{
    if(data_ != nullptr)
    {
        for(size_type i = 0; i < shape_.row_; ++i)
            delete[] data_[i];
        delete[] data_;
    }

    shape_ = shape;
    data_ = new Precision* [shape_.row_];
    for(size_type i = 0; i < shape_.row_; ++i)
        data_[i] = new Precision[shape_.col_];
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_2D)& LIQUE_TENSOR_TPL(detail::TensorType::_2D)::fill(
    Precision (*generator)()) noexcept
{
    for(size_type i = 0; i < shape_.row_; ++i)
        for(size_type j = 0; j < shape_.col_; ++j)
            data_[i][j] = generator();

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_2D)& LIQUE_TENSOR_TPL(detail::TensorType::_2D)::fill(
    Precision value) noexcept
{
    for(size_type i = 0; i < shape_.row_; ++i)
        for(size_type j = 0; j < shape_.col_; ++j)
            data_[i][j] = value;

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_2D) LIQUE_TENSOR_TPL(detail::TensorType::_2D)::apply(
    Precision (*function)(Precision)) const
{
    Tensor new_matrix(shape_);

    for(size_type i = 0; i < shape_.row_; ++i)
        for(size_type j = 0; j < shape_.col_; ++j)
            new_matrix.data_[i][j] = function(data_[i][j]);

    return new_matrix;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_2D)& LIQUE_TENSOR_TPL(detail::TensorType::_2D)::apply(
    Precision (*function)(Precision)) noexcept
{
    for(size_type i = 0; i < shape_.row_; ++i)
        for(size_type j = 0; j < shape_.col_; ++j)
            data_[i][j] = function(data_[i][j]);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_2D)& LIQUE_TENSOR_TPL(detail::TensorType::_2D)::apply(
    Precision (*function)(Precision),
    const Tensor& matrix) noexcept
{
    for(size_type i = 0; i < shape_.row_; ++i)
        for(size_type j = 0; j < shape_.col_; ++j)
            data_[i][j] = function(matrix.data_[i][j]);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
inline Precision& LIQUE_TENSOR_TPL(detail::TensorType::_2D)::operator() (
    std::size_t i,
    std::size_t j) noexcept
{
    return data_[i][j];
}

LIQUE_TENSOR_TPL_DECLARATION
inline const Precision& LIQUE_TENSOR_TPL(detail::TensorType::_2D)::operator() (
    std::size_t i,
    std::size_t j) const noexcept
{
    return data_[i][j];
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_2D) LIQUE_TENSOR_TPL(detail::TensorType::_2D)::dot(
    const Tensor& matrix) const
{
    Tensor new_matrix(shape_.row_, matrix.shape_.col_);
    Precision result = 0.0;

    for(size_type i = 0; i < shape_.row_; ++i)
    {
        for(size_type j = 0; j <  matrix.shape_.col_; ++j)
        {
            result = 0.0;
            for(size_type r = 0; r < shape_.col_; ++r)
                result += data_[i][r] * matrix.data_[r][j];

            new_matrix.data_[i][j] = result;

        }
    }

    return new_matrix;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_2D)& LIQUE_TENSOR_TPL(detail::TensorType::_2D)::add(
    const Tensor& matrix) noexcept
{
    for(size_type i = 0; i < shape_.row_; ++i)
        for(size_type j = 0; j < shape_.col_; ++j)
            data_[i][j] += matrix.data_[i][j];

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_2D)& LIQUE_TENSOR_TPL(detail::TensorType::_2D)::sub(
    const Tensor& matrix) noexcept
{
    for(size_type i = 0; i < shape_.row_; ++i)
        for(size_type j = 0; j < shape_.col_; ++j)
            data_[i][j] -= matrix.data_[i][j];

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_2D) LIQUE_TENSOR_TPL(detail::TensorType::_2D)::multiply(
    const Tensor& matrix) const
{
    Tensor new_matrix(matrix.shape_);

    for(size_type i = 0; i < shape_.row_; ++i)
        for(size_type j = 0; j < shape_.col_; ++j)
            new_matrix.data_[i][j] = data_[i][j] * matrix.data_[i][j];

    return new_matrix;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_2D)& LIQUE_TENSOR_TPL(detail::TensorType::_2D)::multiply(
    const Tensor& matrix) noexcept
{
    for(size_type i = 0; i < shape_.row_; ++i)
        for(size_type j = 0; j < shape_.col_; ++j)
            data_[i][j] *= matrix.data_[i][j];

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_2D)& LIQUE_TENSOR_TPL(detail::TensorType::_2D)::multiply(
    const Tensor& lsh, const Tensor& rsh) noexcept
{
    for(size_type i = 0; i < shape_.row_; ++i)
        for(size_type j = 0; j < shape_.col_; ++j)
            data_[i][j] = lsh.data_[i][j] * rsh.data_[i][j];

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_2D) LIQUE_TENSOR_TPL(detail::TensorType::_2D)::join(
    Precision value) const
{
    Tensor new_matrix(shape_);

    for(size_type i = 0; i < shape_.row_; ++i)
        for(size_type j = 0; j < shape_.col_; ++j)
            new_matrix.data_[i][j] = value * data_[i][j];

    return new_matrix;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_2D)& LIQUE_TENSOR_TPL(detail::TensorType::_2D)::join(
    Precision value) noexcept
{
    for(size_type i = 0; i < shape_.row_; ++i)
        for(size_type j = 0; j < shape_.col_; ++j)
            data_[i][j] *= value;

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_2D)& LIQUE_TENSOR_TPL(detail::TensorType::_2D)::join(
    Precision value,
    const Tensor& matrix) noexcept
{
    for(size_type i = 0; i < shape_.row_; ++i)
        for(size_type j = 0; j < shape_.col_; ++j)
            data_[i][j] = value * matrix.data_[i][j];

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_2D) LIQUE_TENSOR_TPL(detail::TensorType::_2D)::transpose() const
{
    Tensor new_matrix(shape_.col_, shape_.row_);

    for(size_type i = 0; i < shape_.col_; ++i)
        for(size_type j = 0; j < shape_.row_; ++j)
            new_matrix.data_[i][j] = data_[j][i];

    return new_matrix;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_2D) LIQUE_TENSOR_TPL(detail::TensorType::_2D)::inverse() const
{
    size_type N = shape_.row_;

    size_type i;
    size_type j;

    Precision buff;

    Tensor A(*this);
    Tensor I(shape_);

    for(i = 0; i < N; ++i)
        for(j = 0; j < N; ++j)
            I.data_[i][j] = (i == j) ? 1. : 0.;

    for(size_type k = 0, p; k < N; ++k)
    {
        p = k;
        for(i = k + 1; i < N; ++i)
            if(std::fabs(A.data_[p][k]) < std::fabs(A.data_[i][k]))
                p = i;

        if(p != k)
        {
            for(j = k; j < N; ++j)
            {
                buff = A.data_[k][j];
                A.data_[k][j] = A.data_[p][j];
                A.data_[p][j] = buff;
            }

            for(j = 0; j < N; ++j)
            {
                buff = I.data_[k][j];
                I.data_[k][j] = I.data_[p][j];
                I.data_[p][j] = buff;
            }
        }

        buff = 1. / A.data_[k][k];

        for(j = k; j < N; ++j) A.data_[k][j] *= buff;
        for(j = 0; j < N; ++j) I.data_[k][j] *= buff;

        for(i = 0; i < N; ++i)
        {
            if(i == k) continue;

            buff = A.data_[i][k];

            for(j = k; j < N; ++j) A.data_[i][j] -= A.data_[k][j] * buff;
            for(j = 0; j < N; ++j) I.data_[i][j] -= I.data_[k][j] * buff;
        }
    }

    return I;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_2D)& LIQUE_TENSOR_TPL(detail::TensorType::_2D)::inverse()
{
    size_type N = shape_.row_;

    size_type i;
    size_type j;

    Precision buff;

    Tensor I(shape_);

    for(i = 0; i < N; ++i)
        for(j = 0; j < N; ++j)
            I.data_[i][j] = (i == j) ? 1. : 0.;

    for(size_type k = 0, p; k < N; ++k)
    {
        p = k;
        for(i = k + 1; i < N; ++i)
            if(std::fabs(data_[p][k]) < std::fabs(data_[i][k]))
                p = i;

        if(p != k)
        {
            for(j = k; j < N; ++j)
            {
                buff = data_[k][j];
                data_[k][j] = data_[p][j];
                data_[p][j] = buff;
            }

            for(j = 0; j < N; ++j)
            {
                buff = I.data_[k][j];
                I.data_[k][j] = I.data_[p][j];
                I.data_[p][j] = buff;
            }
        }

        buff = 1. / data_[k][k];

        for(j = k; j < N; ++j)   data_[k][j] *= buff;
        for(j = 0; j < N; ++j) I.data_[k][j] *= buff;

        for(i = 0; i < N; ++i)
        {
            if(i == k) continue;

            buff = data_[i][k];

            for(j = k; j < N; ++j)   data_[i][j] -=   data_[k][j] * buff;
            for(j = 0; j < N; ++j) I.data_[i][j] -= I.data_[k][j] * buff;
        }
    }

    for(i = 0; i < N; ++i)
        delete[] data_[i];
    delete data_;

    data_   = I.data_;
    I.data_ = nullptr;

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
inline Precision** LIQUE_TENSOR_TPL(detail::TensorType::_2D)::data() noexcept
{
    return data_;
}

LIQUE_TENSOR_TPL_DECLARATION
inline const Precision** LIQUE_TENSOR_TPL(detail::TensorType::_2D)::data() const noexcept
{
    return data_;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_2D) LIQUE_TENSOR_TPL(detail::TensorType::_2D)::operator+ (
    const Tensor& matrix) const
{
    Tensor new_matrix(shape_);

    for(size_type i = 0; i < shape_.row_; ++i)
        for(size_type j = 0; j < shape_.col_; ++j)
            new_matrix.data_[i][j] = data_[i][j] + matrix.data_[i][j];

    return new_matrix;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_2D) LIQUE_TENSOR_TPL(detail::TensorType::_2D)::operator- (
    const Tensor& matrix) const
{
    Tensor new_matrix(shape_);

    for(size_type i = 0; i < shape_.row_; ++i)
        for(size_type j = 0; j < shape_.col_; ++j)
            new_matrix.data_[i][j] = data_[i][j] - matrix.data_[i][j];

    return new_matrix;
}

LIQUE_TENSOR_TPL_DECLARATION
using Matrix = LIQUE_TENSOR_TPL(detail::TensorType::_2D);

} // namespace lique

#include "Trixy/Lique/Detail/macro_unscope.hpp"

#endif // LIQUE_MATRIX_HPP
