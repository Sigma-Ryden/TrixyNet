#ifndef TRIXY_LIQUE_TENSOR_HPP
#define TRIXY_LIQUE_TENSOR_HPP

#include <cstddef> // size_t

#include <Trixy/Lique/Base.hpp>
#include <Trixy/Lique/BaseTensor.hpp>

#include <Trixy/Lique/Detail/MacroScope.hpp>

namespace trixy
{

namespace lique
{

template <typename Precision>
using TensorView = Tensor<Precision, TensorType::tensor, TensorMode::view>;

template <typename Precision>
class Tensor<Precision, TensorType::tensor, TensorMode::own>
    : public BaseTensor<Precision>
    , public TensorType::tensor
{
    LIQUE_BASE_TENSOR_BODY

public:
    Tensor() noexcept = default;
    ~Tensor();

    explicit Tensor(const Shape& shape, const_pointer data);
    explicit Tensor(const Shape& shape, precision_type value);
    explicit Tensor(const Shape& shape);

    Tensor(size_type depth, size_type height, size_type width, const_pointer data);
    Tensor(size_type depth, size_type height, size_type width, precision_type value);
    Tensor(size_type depth, size_type height, size_type width);

    Tensor(const_pointer first, const_pointer last);

    Tensor(const Tensor& tensor);
    Tensor(Tensor&& tensor) noexcept;

    Tensor& operator= (const Tensor& tensor);
    Tensor& operator= (Tensor&& tensor) noexcept;

    reference operator() (size_type i, size_type j, size_type k) noexcept;
    const_reference operator() (size_type i, size_type j, size_type k) const noexcept;

    void resize(const Shape& shape);
    void resize(size_type depth, size_type height, size_type width);

    void reshape(size_type depth, size_type height, size_type width) noexcept;
};

template <typename Precision>
class Tensor<Precision, TensorType::tensor, TensorMode::view>
    : public BaseTensor<Precision>
    , public TensorType::tensor
{
    LIQUE_BASE_TENSOR_BODY

public:
    Tensor() noexcept = default;
    ~Tensor() = default;

    Tensor(const Shape& shape, pointer data) noexcept;
    Tensor(size_type depth, size_type height, size_type width, pointer data) noexcept;
    Tensor(pointer first, pointer last) noexcept;

    Tensor(const Tensor& tensor) noexcept = default;
    Tensor(Tensor&& tensor) noexcept = default;

    Tensor& operator= (const Tensor& tensor) noexcept = default;
    Tensor& operator= (Tensor&& tensor) noexcept = default;

    reference operator() (size_type i, size_type j, size_type k) noexcept;
    const_reference operator() (size_type i, size_type j, size_type k) const noexcept;

    void reshape(size_type depth, size_type height, size_type width) noexcept;
};

LIQUE_TENSOR_TPL_DECLARATION
Tensor<Precision>::~Tensor()
{
    delete[] this->data_;
}

LIQUE_TENSOR_TPL_DECLARATION
Tensor<Precision>::Tensor(const Shape& shape, const_pointer data)
    : Base(shape)
{
    this->data_ = new precision_type [this->shape_.size];

    this->copy(data);
}

LIQUE_TENSOR_TPL_DECLARATION
Tensor<Precision>::Tensor(const Shape& shape, precision_type value)
    : Base(shape)
{
    this->data_ = new precision_type [this->size_];

    this->fill(value);
}

LIQUE_TENSOR_TPL_DECLARATION
Tensor<Precision>::Tensor(const Shape& shape)
    : Base(shape)
{
    this->data_ = new precision_type [this->shape_.size];
}

LIQUE_TENSOR_TPL_DECLARATION
Tensor<Precision>::Tensor(size_type depth, size_type height, size_type width, const_pointer data)
    : Base(depth, height, width)
{
    this->data_ = new precision_type [this->size_];

    this->copy(data);
}

LIQUE_TENSOR_TPL_DECLARATION
Tensor<Precision>::Tensor(size_type depth, size_type height, size_type width, precision_type value)
    : Base(depth, height, width)
{
    this->data_ = new precision_type [this->size_];

    this->fill(value);
}

LIQUE_TENSOR_TPL_DECLARATION
Tensor<Precision>::Tensor(size_type depth, size_type height, size_type width)
    : Base(depth, height, width)
{
    this->data_ = new precision_type [this->size_];
}

LIQUE_TENSOR_TPL_DECLARATION
Tensor<Precision>::Tensor(const_pointer first, const_pointer last)
    : Base(1, 1, last - first)
{
    this->data_ = new precision_type [this->size_];

    this->copy(first);
}

LIQUE_TENSOR_TPL_DECLARATION
Tensor<Precision>::Tensor(const Tensor& tensor)
    : Base(tensor.shape_)
{
    this->data_ = new precision_type [tensor.size_];
    this->shape_ = tensor.shape_;

    this->copy(tensor.data_);
}

LIQUE_TENSOR_TPL_DECLARATION
Tensor<Precision>::Tensor(Tensor&& tensor) noexcept
    : Base(std::move(tensor))
{
}

LIQUE_TENSOR_TPL_DECLARATION
Tensor<Precision>& Tensor<Precision>::operator= (const Tensor& tensor)
{
    if (this != &tensor)
    {
        delete[] this->data_;

        this->data_ = new precision_type [tensor.size_];

        this->copy(tensor.data_);

        this->shape_ = tensor.shape_;
    }

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Tensor<Precision>& Tensor<Precision>::operator= (Tensor&& tensor) noexcept
{
    if (this != &tensor)
    {
        delete[] this->data_;

        this->data_ = tensor.data_;
        this->shape_ = tensor.shape_;

        tensor.data_ = nullptr;
    }

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
typename Tensor<Precision>::reference
    Tensor<Precision>::operator() (size_type i, size_type j, size_type k) noexcept
{
    return this->data_[i * this->shape_.depth + j * this->shape_.width + k];
}

LIQUE_TENSOR_TPL_DECLARATION
typename Tensor<Precision>::const_reference
    Tensor<Precision>::operator() (size_type i, size_type j, size_type k) const noexcept
{
    return this->data_[i * this->shape_.depth + j * this->shape_.width + k];
}

LIQUE_TENSOR_TPL_DECLARATION
void Tensor<Precision>::resize(const Shape& shape)
{
    resize(shape.depth, shape.height, shape.width);
}

LIQUE_TENSOR_TPL_DECLARATION
void Tensor<Precision>::resize(size_type depth, size_type height, size_type width)
{
    delete[] this->data_;

    this->shape_ = Shape(depth, height, width);

    this->data_ = new precision_type [this->shape_.size];
}

LIQUE_TENSOR_TPL_DECLARATION
void Tensor<Precision>::reshape(size_type depth, size_type height, size_type width) noexcept
{
    this->shape_.depth = depth;
    this->shape_.height = height;
    this->shape_.width = width;
}

LIQUE_TENSOR_TPL_DECLARATION
TensorView<Precision>::Tensor(const Shape& shape, pointer data) noexcept
    : Base(shape, data)
{
}

LIQUE_TENSOR_TPL_DECLARATION
TensorView<Precision>::Tensor(size_type depth, size_type height, size_type width, pointer data) noexcept
    : Base(depth, height, width, data)
{
}

LIQUE_TENSOR_TPL_DECLARATION
TensorView<Precision>::Tensor(pointer first, pointer last) noexcept
    : Base(1, 1, last - first, first)
{
}

LIQUE_TENSOR_TPL_DECLARATION
typename TensorView<Precision>::reference
    TensorView<Precision>::operator() (size_type i, size_type j, size_type k) noexcept
{
    return this->data_[i * this->shape_.depth + j * this->shape_.width + k];
}

LIQUE_TENSOR_TPL_DECLARATION
typename TensorView<Precision>::const_reference
    TensorView<Precision>::operator() (size_type i, size_type j, size_type k) const noexcept
{
    return this->data_[i * this->shape_.depth + j * this->shape_.width + k];
}

LIQUE_TENSOR_TPL_DECLARATION
void TensorView<Precision>::reshape(size_type depth, size_type height, size_type width) noexcept
{
    this->shape_.depth = depth;
    this->shape_.height = height;
    this->shape_.width = width;
}

} // namespace lique

} // namespace trixy

#include <Trixy/Lique/Detail/MacroUnscope.hpp>

#endif // TRIXY_LIQUE_TENSOR_HPP
