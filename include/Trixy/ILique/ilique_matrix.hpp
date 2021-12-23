#ifndef ILIQUE_MATRIX_HPP
#define ILIQUE_MATRIX_HPP

#include <cstddef> // size_t
#include <type_traits> // enable_if, is_arithmetic

namespace ilique
{

template <template <typename P> class Tensor2D, typename Precision, typename enable = void>
class Matrix;

} // namespace ilique

#define ILIQUE_MATRIX_TPL_DECLARATION                                        \
    template <template <typename P> class Tensor2D, typename Precision>

#define ILIQUE_MATRIX_TPL                                                    \
    Matrix<Tensor2D, Precision,                                              \
        typename std::enable_if<std::is_arithmetic<Precision>::value>::type>

namespace ilique
{

template <template <typename P> class Tensor2D, typename Precision>
class Matrix<Tensor2D, Precision,
             typename std::enable_if<std::is_arithmetic<Precision>::value>::type>
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
    Precision** data_;
    Shape       shape_;

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

    Precision** data() noexcept;
    const Precision** data() const noexcept;

    virtual void resize(size_type m, size_type n) = 0;
    virtual void resize(const Shape& new_shape) = 0;

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

public:
    explicit Shape(size_type m, size_type n) noexcept : row_(m), col_(n) {}
    Shape(const Shape& shape) noexcept : row_(shape.row_), col_(shape.col_) {}

    size_type row() const noexcept { return row_; }
    size_type col() const noexcept { return col_; }
};

ILIQUE_MATRIX_TPL_DECLARATION
inline ILIQUE_MATRIX_TPL::Matrix() noexcept : data_(nullptr), shape_(0, 0)
{
}

ILIQUE_MATRIX_TPL_DECLARATION
ILIQUE_MATRIX_TPL::~Matrix()
{
    if(data_ != nullptr)
    {
        for(size_type i = 0; i < shape_.row_; ++i)
            delete[] data_[i];
        delete[] data_;
    }
}

ILIQUE_MATRIX_TPL_DECLARATION
ILIQUE_MATRIX_TPL::Matrix(std::size_t m, std::size_t n)
    : data_(new Precision* [m]), shape_(m, n)
{
    for(size_type i = 0; i < shape_.row_; ++i)
        data_[i] = new Precision[shape_.col_];
}

ILIQUE_MATRIX_TPL_DECLARATION
ILIQUE_MATRIX_TPL::Matrix(const Matrix::Shape& shape)
    : data_(new Precision* [shape.row_]), shape_(shape)
{
    for(size_type i = 0; i < shape_.row_; ++i)
        data_[i] = new Precision[shape_.col_];
}

ILIQUE_MATRIX_TPL_DECLARATION
ILIQUE_MATRIX_TPL::Matrix(const Matrix& matrix)
    : data_(new Precision* [matrix.shape_.row_]), shape_(matrix.shape_)
{
    for(size_type i = 0; i < shape_.row_; ++i)
        data_[i] = new Precision[shape_.col_];

    for(size_type i = 0; i < shape_.row_; ++i)
        for(size_type j = 0; j < shape_.col_; ++j)
            data_[i][j] = matrix.data_[i][j];
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

ILIQUE_MATRIX_TPL_DECLARATION
ILIQUE_MATRIX_TPL& ILIQUE_MATRIX_TPL::operator= (Matrix&& matrix) noexcept
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

ILIQUE_MATRIX_TPL_DECLARATION
inline Precision& ILIQUE_MATRIX_TPL::operator() (std::size_t i, std::size_t j) noexcept
{
    return data_[i][j];
}

ILIQUE_MATRIX_TPL_DECLARATION
inline const Precision& ILIQUE_MATRIX_TPL::operator() (std::size_t i, std::size_t j) const noexcept
{
    return data_[i][j];
}

ILIQUE_MATRIX_TPL_DECLARATION
inline const typename ILIQUE_MATRIX_TPL::Shape& ILIQUE_MATRIX_TPL::size() const noexcept
{
    return shape_;
}

ILIQUE_MATRIX_TPL_DECLARATION
inline Precision**ILIQUE_MATRIX_TPL::data() noexcept
{
    return data_;
}

ILIQUE_MATRIX_TPL_DECLARATION
inline const Precision** ILIQUE_MATRIX_TPL::data() const noexcept
{
    return data_;
}

} // namespace ilique

// clean up
#undef ILIQUE_MATRIX_TPL_DECLARATION
#undef ILIQUE_MATRIX_TPL

#endif // ILIQUE_MATRIX_HPP
