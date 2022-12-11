#ifndef TRIXY_LIQUE_TENSOR_HPP
#define TRIXY_LIQUE_TENSOR_HPP

#include <cstddef> // size_t

#include <Trixy/Lique/Base.hpp>
#include <Trixy/Lique/TensorBase.hpp>

#include <Trixy/Lique/Detail/MacroScope.hpp>

namespace trixy
{

namespace lique
{

template <typename Precision>
using TensorView = Tensor<Precision, TensorType::tensor, TensorMode::view>;

template <typename Precision>
class Tensor<Precision, TensorType::tensor, TensorMode::own>
    : public TensorBase<Precision>
    , public TensorType::tensor
{
    LIQUE_TENSOR_BASE_BODY()

public:
    Tensor() noexcept = default;
    ~Tensor();

    explicit Tensor(const shape_type& shape, const_pointer data);
    explicit Tensor(const shape_type& shape, precision_type value);
    explicit Tensor(const shape_type& shape);

    Tensor(size_type depth, size_type height, size_type width, const_pointer data);
    Tensor(size_type depth, size_type height, size_type width, precision_type value);
    Tensor(size_type depth, size_type height, size_type width);

    Tensor(const_pointer first, const_pointer last);

    Tensor(std::initializer_list<precision_type> list);

    Tensor(const Tensor& tensor);
    Tensor(Tensor&& tensor) noexcept;

    Tensor& operator= (const Tensor& tensor);
    Tensor& operator= (Tensor&& tensor) noexcept;

    pointer at(size_type i, size_type j, size_type k) noexcept;
    const_pointer at(size_type i , size_type j, size_type k) const noexcept;

    reference operator() (size_type i, size_type j, size_type k) noexcept;
    const_reference operator() (size_type i, size_type j, size_type k) const noexcept;

    void resize(const shape_type& shape);
    void resize(size_type depth, size_type height, size_type width);

    void reshape(size_type depth, size_type height, size_type width) noexcept;
};

template <typename Precision>
class Tensor<Precision, TensorType::tensor, TensorMode::view>
    : public TensorBase<Precision>
    , public TensorType::tensor
{
    LIQUE_TENSOR_BASE_BODY()

public:
    Tensor() noexcept = default;
    ~Tensor() = default;

    Tensor(const shape_type& shape, pointer data) noexcept;
    Tensor(size_type depth, size_type height, size_type width, pointer data) noexcept;
    Tensor(pointer first, pointer last) noexcept;

    Tensor(const Tensor& tensor) noexcept = default;
    Tensor(Tensor&& tensor) noexcept = default;

    Tensor& operator= (const Tensor& tensor) noexcept = default;
    Tensor& operator= (Tensor&& tensor) noexcept = default;

    pointer at(size_type i, size_type j, size_type k) noexcept;
    const_pointer at(size_type i , size_type j, size_type k) const noexcept;

    reference operator() (size_type i, size_type j, size_type k) noexcept;
    const_reference operator() (size_type i, size_type j, size_type k) const noexcept;

    void reshape(size_type depth, size_type height, size_type width) noexcept;
};

LIQUE_TENSOR_TEMPLATE()
Tensor<Precision>::~Tensor()
{
    delete[] this->data_;
}

LIQUE_TENSOR_TEMPLATE()
Tensor<Precision>::Tensor(const shape_type& shape, const_pointer data)
    : Base(shape)
{
    this->data_ = new precision_type [this->shape_.size];

    this->copy(data);
}

LIQUE_TENSOR_TEMPLATE()
Tensor<Precision>::Tensor(const shape_type& shape, precision_type value)
    : Base(shape)
{
    this->data_ = new precision_type [this->shape_.size];

    this->fill(value);
}

LIQUE_TENSOR_TEMPLATE()
Tensor<Precision>::Tensor(const shape_type& shape)
    : Base(shape)
{
    this->data_ = new precision_type [this->shape_.size];
}

LIQUE_TENSOR_TEMPLATE()
Tensor<Precision>::Tensor(size_type depth, size_type height, size_type width, const_pointer data)
    : Base(depth, height, width)
{
    this->data_ = new precision_type [this->shape_.size];

    this->copy(data);
}

LIQUE_TENSOR_TEMPLATE()
Tensor<Precision>::Tensor(size_type depth, size_type height, size_type width, precision_type value)
    : Base(depth, height, width)
{
    this->data_ = new precision_type [this->shape_.size];

    this->fill(value);
}

LIQUE_TENSOR_TEMPLATE()
Tensor<Precision>::Tensor(size_type depth, size_type height, size_type width)
    : Base(depth, height, width)
{
    this->data_ = new precision_type [this->shape_.size];
}

LIQUE_TENSOR_TEMPLATE()
Tensor<Precision>::Tensor(const_pointer first, const_pointer last)
    : Base(1, 1, last - first)
{
    this->data_ = new precision_type [this->shape_.size];

    this->copy(first);
}

LIQUE_TENSOR_TEMPLATE()
Tensor<Precision>::Tensor(std::initializer_list<precision_type> list)
    : Base(1, 1, list.size())
{
    this->data_ = new precision_type [this->shape_.size];

    this->copy(list.begin());
}

LIQUE_TENSOR_TEMPLATE()
Tensor<Precision>::Tensor(const Tensor& tensor)
    : Base(tensor.shape_)
{
    this->data_ = new precision_type [tensor.shape_.size];
    this->shape_ = tensor.shape_;

    this->copy(tensor.data_);
}

LIQUE_TENSOR_TEMPLATE()
Tensor<Precision>::Tensor(Tensor&& tensor) noexcept
    : Base(std::move(tensor))
{
}

LIQUE_TENSOR_TEMPLATE()
Tensor<Precision>& Tensor<Precision>::operator= (const Tensor& tensor)
{
    if (this != &tensor)
    {
        delete[] this->data_;

        this->data_ = new precision_type [tensor.shape_.size];

        this->copy(tensor.data_);

        this->shape_ = tensor.shape_;
    }

    return *this;
}

LIQUE_TENSOR_TEMPLATE()
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

LIQUE_TENSOR_TEMPLATE()
inline auto Tensor<Precision>::at(
    size_type i, size_type j, size_type k) noexcept -> pointer
{
    return this->data_ + i * this->shape_.depth + j * this->shape_.width + k;
}

LIQUE_TENSOR_TEMPLATE()
inline auto Tensor<Precision>::at(
    size_type i, size_type j, size_type k) const noexcept -> const_pointer
{
    return this->data_ + i * this->shape_.depth + j * this->shape_.width + k;
}

LIQUE_TENSOR_TEMPLATE()
inline auto Tensor<Precision>::operator() (
    size_type i, size_type j, size_type k) noexcept -> reference
{
    return *at(i, j, k); // dereferencing
}

LIQUE_TENSOR_TEMPLATE()
inline auto Tensor<Precision>::operator() (
    size_type i, size_type j, size_type k) const noexcept -> const_reference
{
    return *at(i, j, k); // dereferencing
}

LIQUE_TENSOR_TEMPLATE()
void Tensor<Precision>::resize(const shape_type& shape)
{
    resize(shape.depth, shape.height, shape.width);
}

LIQUE_TENSOR_TEMPLATE()
void Tensor<Precision>::resize(size_type depth, size_type height, size_type width)
{
    delete[] this->data_;

    this->shape_ = shape_type(depth, height, width);

    this->data_ = new precision_type [this->shape_.size];
}

LIQUE_TENSOR_TEMPLATE()
void Tensor<Precision>::reshape(size_type depth, size_type height, size_type width) noexcept
{
    this->shape_.depth = depth;
    this->shape_.height = height;
    this->shape_.width = width;
}

LIQUE_TENSOR_TEMPLATE()
TensorView<Precision>::Tensor(const shape_type& shape, pointer data) noexcept
    : Base(shape, data)
{
}

LIQUE_TENSOR_TEMPLATE()
TensorView<Precision>::Tensor(
    size_type depth, size_type height, size_type width, pointer data) noexcept
    : Base(depth, height, width, data)
{
}

LIQUE_TENSOR_TEMPLATE()
TensorView<Precision>::Tensor(pointer first, pointer last) noexcept
    : Base(1, 1, last - first, first)
{
}

LIQUE_TENSOR_TEMPLATE()
inline auto TensorView<Precision>::at(
    size_type i, size_type j, size_type k) noexcept -> pointer
{
    return this->data_ + i * this->shape_.depth + j * this->shape_.width + k;
}

LIQUE_TENSOR_TEMPLATE()
inline auto TensorView<Precision>::at(
    size_type i, size_type j, size_type k) const noexcept -> const_pointer
{
    return this->data_ + i * this->shape_.depth + j * this->shape_.width + k;
}

LIQUE_TENSOR_TEMPLATE()
inline auto TensorView<Precision>::operator() (
    size_type i, size_type j, size_type k) noexcept -> reference
{
    return *at(i, j, k); // dereferencing
}

LIQUE_TENSOR_TEMPLATE()
inline auto TensorView<Precision>::operator() (
    size_type i, size_type j, size_type k) const noexcept -> const_reference
{
    return *at(i, j, k); // dereferencing
}

LIQUE_TENSOR_TEMPLATE()
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
