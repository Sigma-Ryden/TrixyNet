#ifndef ILIQUE_MATRIX_HPP
#define ILIQUE_MATRIX_HPP

#include <cstddef> // size_t

#include "Detail/ILiqueMeta.hpp"

#include "Detail/MacroScope.hpp"

namespace ilique
{

template <template <typename P> class Tensor2D, typename Precision, typename enable = void>
class Matrix;

} // namespace ilique

namespace ilique
{

template <template <typename P> class Tensor2D, typename Precision>
class Matrix<Tensor2D, Precision,
             meta::use_for_arithmetic_t<Precision>>
{
protected:
    class Shape;

public:
    using TensorType      = Tensor2D<Precision>;
    using size_type       = std::size_t;
    using reference       = Precision&;
    using const_reference = const Precision&;

protected:
    virtual ~Matrix();

protected:
    Precision* data_;
    Shape      shape_;

public:
    Matrix() noexcept;

    explicit Matrix(size_type m, size_type n);
    explicit Matrix(size_type m, size_type n, Precision fill_value);

    explicit Matrix(const Shape& shape);
    explicit Matrix(const Shape& shape, Precision fill_value);

    Matrix(const Matrix&);
    Matrix(Matrix&&) noexcept;

    Matrix& operator= (const Matrix&);
    Matrix& operator= (Matrix&&) noexcept;

    reference operator() (size_type i, size_type j) noexcept;
    const_reference operator() (size_type i, size_type j) const noexcept;

    reference operator() (size_type i) noexcept;
    const_reference operator() (size_type i) const noexcept;

    const Shape& shape() const noexcept;
    size_type size() const noexcept;

    virtual void resize(size_type m, size_type n) = 0;
    virtual void resize(const Shape& new_shape) = 0;
    virtual void reshape(const Shape& new_shape) = 0;

    virtual TensorType dot(const TensorType&) const = 0;
    virtual TensorType transpose() const = 0;

    virtual TensorType inverse() const = 0;
    virtual TensorType& inverse() = 0;
};

ILIQUE_MATRIX_TPL_DECLARATION
class ILIQUE_MATRIX_TPL::Shape
{
friend ILIQUE_MATRIX_TPL;
friend Tensor2D<Precision>;

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

ILIQUE_MATRIX_TPL_DECLARATION
inline ILIQUE_MATRIX_TPL::Matrix() noexcept : data_(nullptr), shape_(0, 0)
{
}

ILIQUE_MATRIX_TPL_DECLARATION
ILIQUE_MATRIX_TPL::~Matrix()
{
    delete[] data_;
}

ILIQUE_MATRIX_TPL_DECLARATION
inline ILIQUE_MATRIX_TPL::Matrix(std::size_t m, std::size_t n)
    : data_(new Precision [m * n]), shape_(m, n)
{
}

ILIQUE_MATRIX_TPL_DECLARATION
ILIQUE_MATRIX_TPL::Matrix(std::size_t m, std::size_t n, Precision fill_value)
    : data_(new Precision [m * n]), shape_(m, n)
{
    for(size_type i = 0; i < shape_.size_; ++i)
        data_[i] = fill_value;
}

ILIQUE_MATRIX_TPL_DECLARATION
inline ILIQUE_MATRIX_TPL::Matrix(const Matrix::Shape& shape)
    : data_(new Precision [shape.size_]), shape_(shape)
{
}

ILIQUE_MATRIX_TPL_DECLARATION
ILIQUE_MATRIX_TPL::Matrix(const Matrix::Shape& shape, Precision fill_value)
    : data_(new Precision [shape.size_]), shape_(shape)
{
    for(size_type i = 0; i < shape_.size_; ++i)
        data_[i] = fill_value;
}

ILIQUE_MATRIX_TPL_DECLARATION
ILIQUE_MATRIX_TPL::Matrix(const Matrix& matrix)
    : data_(new Precision [matrix.shape_.size_]), shape_(matrix.shape_)
{
    for(size_type i = 0; i < shape_.size_; ++i)
        data_[i] = matrix.data_[i];
}

ILIQUE_MATRIX_TPL_DECLARATION
inline ILIQUE_MATRIX_TPL::Matrix(Matrix&& matrix) noexcept
    : data_(matrix.data_), shape_(matrix.shape_)
{
    matrix.data_ = nullptr;
}

ILIQUE_MATRIX_TPL_DECLARATION
ILIQUE_MATRIX_TPL& ILIQUE_MATRIX_TPL::operator= (const Matrix& matrix)
{
    if(this != &matrix)
    {
        delete[] data_;

        shape_ = matrix.shape_;

        data_ = new Precision [shape_.size_];

        for(size_type i = 0; i < shape_.size_; ++i)
            data_[i] = matrix.data_[i];
    }

    return *this;
}

ILIQUE_MATRIX_TPL_DECLARATION
ILIQUE_MATRIX_TPL& ILIQUE_MATRIX_TPL::operator= (Matrix&& matrix) noexcept
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

ILIQUE_MATRIX_TPL_DECLARATION
inline Precision& ILIQUE_MATRIX_TPL::operator() (std::size_t i, std::size_t j) noexcept
{
    return data_[i * shape_.col_ + j];
}

ILIQUE_MATRIX_TPL_DECLARATION
inline const Precision& ILIQUE_MATRIX_TPL::operator() (std::size_t i, std::size_t j) const noexcept
{
    return data_[i * shape_.col_ + j];
}

ILIQUE_MATRIX_TPL_DECLARATION
inline Precision& ILIQUE_MATRIX_TPL::operator() (std::size_t i) noexcept
{
    return data_[i];
}

ILIQUE_MATRIX_TPL_DECLARATION
inline const Precision& ILIQUE_MATRIX_TPL::operator() (std::size_t i) const noexcept
{
    return data_[i];
}

ILIQUE_MATRIX_TPL_DECLARATION
inline const typename ILIQUE_MATRIX_TPL::Shape& ILIQUE_MATRIX_TPL::shape() const noexcept
{
    return shape_;
}

ILIQUE_MATRIX_TPL_DECLARATION
inline std::size_t ILIQUE_MATRIX_TPL::size() const noexcept
{
    return shape_.size_;
}

} // namespace ilique

#include "Detail/MacroUnscope.hpp"

#endif // ILIQUE_MATRIX_HPP
