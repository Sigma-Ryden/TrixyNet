/*__DEPRECATED__*/
#ifndef ILIQUE_MATRIX_HPP
#define ILIQUE_MATRIX_HPP

#include <cstddef> // size_t

#include "Trixy/Lique/LiqueBaseTensor.hpp"

#include "Detail/MacroScope.hpp"

namespace ilique
{

template <template <typename...> class Derived, typename Precision, typename... Args>
class ILMatrix : public lique::TensorType::matrix
{
public:
    class Shape;

public:
    using Tensor            = Derived<Precision, Args...>;

public:
    using size_type         = std::size_t;
    using precision_type    = Precision;

    using pointer           = Precision*;
    using const_pointer     = const Precision*;

    using reference         = Precision&;
    using const_reference   = const Precision&;

protected:
    pointer data_;
    Shape shape_;

protected:
    virtual ~ILMatrix();

private:
    Tensor& self() { return *static_cast<Tensor*>(this); }
    const Tensor& self() const { return *static_cast<const Tensor*>(this); }

public:
    ILMatrix() noexcept;

    explicit ILMatrix(size_type m, size_type n);
    explicit ILMatrix(size_type m, size_type n, precision_type value);

    explicit ILMatrix(const Shape& shape);
    explicit ILMatrix(const Shape& shape, precision_type value);

    ILMatrix(const ILMatrix&);
    ILMatrix(ILMatrix&&) noexcept;

    ILMatrix& operator= (const ILMatrix&);
    ILMatrix& operator= (ILMatrix&&) noexcept;

    reference operator() (size_type i, size_type j) noexcept;
    const_reference operator() (size_type i, size_type j) const noexcept;

    reference operator() (size_type i) noexcept { return data_[i]; }
    const_reference operator() (size_type i) const noexcept { return data_[i]; }

    const Shape& shape() const noexcept { return shape_; }
    size_type size() const noexcept { return shape_.size_; }

    void resize(size_type m);
    void resize(size_type m, size_type n);
    void resize(const Shape& new_shape);

    void resize(size_type m, size_type n, precision_type value);
    void resize(const Shape& new_shape, precision_type value);

    void reshape(size_type m, size_type n);

    Tensor dot(const Tensor& tensor) const { return self().dot(tensor); }
    Tensor transpose() const { return self().transpose(); }

    Tensor inverse() const { return self().inverse(); }
    Tensor& inverse() { return self().inverse(); }
};

ILIQUE_TENSOR_TPL_DECLARATION
class ILIQUE_MATRIX_TPL::Shape
{
friend ILMatrix;
friend Tensor;

protected:
    size_type size_;
    size_type row_;
    size_type col_;

public:
    explicit Shape(size_type m, size_type n) noexcept
    : size_(m * n), row_(m), col_(n) {}

    Shape(const Shape& shape) noexcept
    : size_(shape.size_), row_(shape.row_), col_(shape.col_) {}

    size_type row() const noexcept { return row_; }
    size_type col() const noexcept { return col_; }

protected:
    Shape& operator= (const Shape& shape) = default;
};

ILIQUE_TENSOR_TPL_DECLARATION
inline ILIQUE_MATRIX_TPL::ILMatrix() noexcept : data_(nullptr), shape_(0, 0)
{
}

ILIQUE_TENSOR_TPL_DECLARATION
ILIQUE_MATRIX_TPL::~ILMatrix()
{
    delete[] data_;
}

ILIQUE_TENSOR_TPL_DECLARATION
inline ILIQUE_MATRIX_TPL::ILMatrix(size_type m, size_type n)
    : data_(new precision_type [m * n]), shape_(m, n)
{
}

ILIQUE_TENSOR_TPL_DECLARATION
ILIQUE_MATRIX_TPL::ILMatrix(size_type m, size_type n, precision_type fill_value)
    : data_(new precision_type [m * n]), shape_(m, n)
{
    for(size_type i = 0; i < shape_.size_; ++i)
        data_[i] = fill_value;
}

ILIQUE_TENSOR_TPL_DECLARATION
inline ILIQUE_MATRIX_TPL::ILMatrix(const ILMatrix::Shape& shape)
    : data_(new precision_type [shape.size_]), shape_(shape)
{
}

ILIQUE_TENSOR_TPL_DECLARATION
ILIQUE_MATRIX_TPL::ILMatrix(const ILMatrix::Shape& shape, precision_type fill_value)
    : data_(new precision_type [shape.size_]), shape_(shape)
{
    for(size_type i = 0; i < shape_.size_; ++i)
        data_[i] = fill_value;
}

ILIQUE_TENSOR_TPL_DECLARATION
ILIQUE_MATRIX_TPL::ILMatrix(const ILMatrix& matrix)
    : data_(new precision_type [matrix.shape_.size_]), shape_(matrix.shape_)
{
    for(size_type i = 0; i < shape_.size_; ++i)
        data_[i] = matrix.data_[i];
}

ILIQUE_TENSOR_TPL_DECLARATION
inline ILIQUE_MATRIX_TPL::ILMatrix(ILMatrix&& matrix) noexcept
    : data_(matrix.data_), shape_(matrix.shape_)
{
    matrix.data_ = nullptr;
}

ILIQUE_TENSOR_TPL_DECLARATION
ILIQUE_MATRIX_TPL& ILIQUE_MATRIX_TPL::operator= (const ILMatrix& matrix)
{
    if(this != &matrix)
    {
        delete[] data_;

        shape_ = matrix.shape_;

        data_ = new precision_type [shape_.size_];

        for(size_type i = 0; i < shape_.size_; ++i)
            data_[i] = matrix.data_[i];
    }

    return *this;
}

ILIQUE_TENSOR_TPL_DECLARATION
ILIQUE_MATRIX_TPL& ILIQUE_MATRIX_TPL::operator= (ILMatrix&& matrix) noexcept
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

ILIQUE_TENSOR_TPL_DECLARATION
inline typename ILIQUE_MATRIX_TPL::reference ILIQUE_MATRIX_TPL::operator() (
    size_type i, size_type j) noexcept
{
    return data_[i * shape_.col_ + j];
}

ILIQUE_TENSOR_TPL_DECLARATION
inline typename ILIQUE_MATRIX_TPL::const_reference ILIQUE_MATRIX_TPL::operator() (
    size_type i, size_type j) const noexcept
{
    return data_[i * shape_.col_ + j];
}

ILIQUE_TENSOR_TPL_DECLARATION
void ILIQUE_MATRIX_TPL::resize(size_type size)
{
    delete[] data_;

    shape_.row_  = 1;
    shape_.col_  = size;
    shape_.size_ = size;

    data_ = new precision_type [shape_.size_];
}

ILIQUE_TENSOR_TPL_DECLARATION
void ILIQUE_MATRIX_TPL::resize(size_type m, size_type n)
{
    delete[] data_;

    shape_.row_  = m;
    shape_.col_  = n;
    shape_.size_ = m * n;

    data_ = new precision_type [shape_.size_];
}

ILIQUE_TENSOR_TPL_DECLARATION
void ILIQUE_MATRIX_TPL::resize(const Shape& shape)
{
    delete[] data_;

    shape_ = shape;
    data_  = new precision_type [shape_.size_];
}

ILIQUE_TENSOR_TPL_DECLARATION
void ILIQUE_MATRIX_TPL::resize(size_type m, size_type n, precision_type value)
{
    resize(m, n);
    fill(value);
}

ILIQUE_TENSOR_TPL_DECLARATION
void ILIQUE_MATRIX_TPL::resize(const Shape& shape, precision_type value)
{
    resize(shape);
    fill(value);
}

ILIQUE_TENSOR_TPL_DECLARATION
void ILIQUE_MATRIX_TPL::reshape(size_type m, size_type n) noexcept
{
    shape_.row_ = m;
    shape_.col_ = n;
}

} // namespace ilique

#include "Detail/MacroUnscope.hpp"

#endif // ILIQUE_MATRIX_HPP

