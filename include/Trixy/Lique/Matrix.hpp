#ifndef TRIXY_LIQUE_MATRIX_HPP
#define TRIXY_LIQUE_MATRIX_HPP

#include <cstddef> // size_t

#include <Trixy/Lique/Base.hpp>
#include <Trixy/Lique/BaseTensor.hpp>

#include <Trixy/Detail/TrixyMeta.hpp>

#include <Trixy/Lique/Detail/MacroScope.hpp>

namespace trixy
{

namespace lique
{

template <typename Precision, typename TensorMode = TensorMode::own>
using Matrix = Tensor<Precision, TensorType::matrix, TensorMode>;

template <typename Precision>
using MatrixView = Matrix<Precision, TensorMode::view>;

template <typename Precision>
class Tensor<Precision, TensorType::matrix, TensorMode::own>
    : public BaseTensor<Precision>
    , public TensorType::matrix
{
    LIQUE_BASE_TENSOR_BODY

public:
    Tensor() noexcept = default;
    ~Tensor();

    explicit Tensor(const Shape& shape, const_pointer data);
    explicit Tensor(const Shape& shape, precision_type value);
    explicit Tensor(const Shape& shape);

    Tensor(size_type height, size_type width, const_pointer data);
    Tensor(size_type height, size_type width, precision_type value);
    Tensor(size_type height, size_type width);

    Tensor(const_pointer first, const_pointer last);

    Tensor(const Tensor& tensor);
    Tensor(Tensor&& tensor) noexcept;

    Tensor& operator= (const Tensor& tensor);
    Tensor& operator= (Tensor&& tensor) noexcept;

    reference operator() (size_type i, size_type j) noexcept;
    const_reference operator() (size_type i, size_type j) const noexcept;

    void resize(const Shape& shape);
    void resize(size_type height, size_type width);

    void reshape(size_type height, size_type width) noexcept;
};

LIQUE_TENSOR_TPL_DECLARATION
class Tensor<Precision, TensorType::matrix, TensorMode::view>
    : public BaseTensor<Precision>
    , public TensorType::matrix
{
    LIQUE_BASE_TENSOR_BODY

public:
    Tensor() noexcept = default;
    ~Tensor() = default;

    Tensor(const Shape& shape, pointer data) noexcept;
    Tensor(size_type height, size_type width, pointer data) noexcept;
    Tensor(pointer first, pointer last) noexcept;

    Tensor(const Tensor& tensor) noexcept = default;
    Tensor(Tensor&& tensor) noexcept = default;

    Tensor& operator= (const Tensor& tensor) noexcept;
    Tensor& operator= (Tensor&& tensor) noexcept;

    reference operator() (size_type i, size_type j) noexcept;
    const_reference operator() (size_type i, size_type j) const noexcept;

    void reshape(size_type height, size_type width) noexcept;
};

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>::~Tensor()
{
    delete[] this->data_;
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>::Tensor(const Shape& shape, const_pointer data)
    : Base(shape.depth * shape.height, shape.width)
{
    this->data_ = new precision_type [this->shape_.size];

    this->copy(data);
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>::Tensor(const Shape& shape, precision_type value)
    : Base(shape.depth * shape.height, shape.width)
{
    this->data_ = new precision_type [this->shape_.size];

    this->fill(value);
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>::Tensor(const Shape& shape)
    : Base(shape.depth * shape.height, shape.width)
{
    this->data_ = new precision_type [this->shape_.size];
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>::Tensor(size_type height, size_type width, const_pointer data)
    : Base(height, width)
{
    this->data_ = new precision_type [this->shape_.size];

    this->copy(data);
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>::Tensor(size_type height, size_type width, precision_type value)
    : Base(height, width)
{
    this->data_ = new precision_type [this->shape_.size];

    this->fill(value);
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>::Tensor(size_type height, size_type width)
    : Base(height, width)
{
    this->data_ = new precision_type [this->shape_.size];
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>::Tensor(const_pointer first, const_pointer last)
    : Base(1, last - first)
{
    this->data_ = new precision_type [this->shape_.size];

    this->copy(first);
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>::Tensor(const Tensor& tensor)
    : Base(tensor.shape_.depth * tensor.shape_.height, tensor.shape_.width)
{
    this->data_ = new precision_type [tensor.shape_.size];

    this->copy(tensor.data_);
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>::Tensor(Tensor&& tensor) noexcept
    : Base(std::move(tensor))
{
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>& Matrix<Precision>::operator= (const Tensor& tensor)
{
    if (this != &tensor)
    {
        delete[] this->data_;

        this->data_ = new precision_type [tensor.shape_.size];

        this->copy(tensor.data_);

        this->shape_.height = tensor.shape_.height;
        this->shape_.width = tensor.shape_.width;

        this->shape_.size = tensor.shape_.size;
    }

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Matrix<Precision>& Matrix<Precision>::operator= (Tensor&& tensor) noexcept
{
    if (this != &tensor)
    {
        delete[] this->data_;

        this->data_ = tensor.data_;

        this->shape_.height = tensor.shape_.height;
        this->shape_.width = tensor.shape_.width;

        this->shape_.size = tensor.shape_.size;

        tensor.data_ = nullptr;
    }

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
typename Matrix<Precision>::reference
    Matrix<Precision>::operator() (size_type i, size_type j) noexcept
{
    return this->data_[i * this->shape_.width + j];
}

LIQUE_TENSOR_TPL_DECLARATION
typename Matrix<Precision>::const_reference
    Matrix<Precision>::operator() (size_type i, size_type j) const noexcept
{
    return this->data_[i * this->shape_.width + j];
}

LIQUE_TENSOR_TPL_DECLARATION
void Matrix<Precision>::resize(const Shape& shape)
{
    resize(shape.height, shape.width);
}

LIQUE_TENSOR_TPL_DECLARATION
void Matrix<Precision>::resize(size_type height, size_type width)
{
    delete[] this->data_;

    this->shape_.height = height;
    this->shape_.width = width;

    this->shape_.size = height * width;

    this->data_ = new precision_type [this->shape_.size];
}

LIQUE_TENSOR_TPL_DECLARATION
void Matrix<Precision>::reshape(size_type height, size_type width) noexcept
{
    this->shape_.height = height;
    this->shape_.width = width;
}

LIQUE_TENSOR_TPL_DECLARATION
MatrixView<Precision>::Tensor(const Shape& shape, pointer data) noexcept
    : Base(shape.depth * shape.height, shape.width, data)
{
}

LIQUE_TENSOR_TPL_DECLARATION
MatrixView<Precision>::Tensor(size_type height, size_type width, pointer data) noexcept
    : Base(height, width, data)
{
}

LIQUE_TENSOR_TPL_DECLARATION
MatrixView<Precision>::Tensor(pointer first, pointer last) noexcept
    : Base(1, last - first, first)
{
}

LIQUE_TENSOR_TPL_DECLARATION
MatrixView<Precision>& MatrixView<Precision>::operator= (const Tensor& tensor) noexcept
{
    if (this != &tensor)
    {
        this->data_ = tensor.data_;

        this->shape_.height = tensor.shape_.height;
        this->shape_.width = tensor.shape_.width;

        this->shape_.size = tensor.shape_.size;
    }

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
MatrixView<Precision>& MatrixView<Precision>::operator= (Tensor&& tensor) noexcept
{
    if (this != &tensor)
    {
        this->data_ = tensor.data_;

        this->shape_.height = tensor.shape_.height;
        this->shape_.width = tensor.shape_.width;

        this->shape_.size = tensor.shape_.size;

        tensor.data_ = nullptr;
    }

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
typename MatrixView<Precision>::reference
    MatrixView<Precision>::operator() (size_type i, size_type j) noexcept
{
    return this->data_[i * this->shape_.width + j];
}

LIQUE_TENSOR_TPL_DECLARATION
typename MatrixView<Precision>::const_reference
    MatrixView<Precision>::operator() (size_type i, size_type j) const noexcept
{
    return this->data_[i * this->shape_.width + j];
}

LIQUE_TENSOR_TPL_DECLARATION
void MatrixView<Precision>::reshape(size_type height, size_type width) noexcept
{
    this->shape_.height = height;
    this->shape_.width = width;
}

} // namespace lique

} // namespace trixy

#include <Trixy/Lique/Detail/MacroUnscope.hpp>

#endif // TRIXY_LIQUE_MATRIX_HPP
