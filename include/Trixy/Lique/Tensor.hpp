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
    ~Tensor()
    {
        delete[] this->data_;
    }

    explicit Tensor(const shape_type& shape, const_pointer data)
        : Base(shape)
    {
        this->data_ = new precision_type [this->shape_.size];
        this->copy(data);
    }

    explicit Tensor(const shape_type& shape, precision_type value)
        : Base(shape)
    {
        this->data_ = new precision_type [this->shape_.size];
        this->fill(value);
    }

    explicit Tensor(const shape_type& shape)
        : Base(shape)
    {
        this->data_ = new precision_type [this->shape_.size];
    }

    Tensor(size_type depth, size_type height, size_type width, const_pointer data)
        : Base(depth, height, width)
    {
        this->data_ = new precision_type [this->shape_.size];
        this->copy(data);
    }

    Tensor(size_type depth, size_type height, size_type width, precision_type value)
        : Base(depth, height, width)
    {
        this->data_ = new precision_type [this->shape_.size];
        this->fill(value);
    }

    Tensor(size_type depth, size_type height, size_type width)
        : Base(depth, height, width)
    {
        this->data_ = new precision_type [this->shape_.size];
    }

    Tensor(const_pointer first, const_pointer last)
        : Base(1, 1, last - first)
    {
        this->data_ = new precision_type [this->shape_.size];
        this->copy(first);
    }

    Tensor(std::initializer_list<precision_type> list)
        : Base(1, 1, list.size())
    {
        this->data_ = new precision_type [this->shape_.size];
        this->copy(list.begin());
    }

    Tensor(const Tensor& tensor)
        : Base(tensor.shape_)
    {
        this->data_ = new precision_type [tensor.shape_.size];
        this->shape_ = tensor.shape_;
        this->copy(tensor.data_);
    }

    Tensor(Tensor&& tensor) noexcept : Base(std::move(tensor)) {}

    Tensor& operator= (const Tensor& tensor)
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

    Tensor& operator= (Tensor&& tensor) noexcept
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

    pointer at(size_type i, size_type j, size_type k) noexcept
    {
        return this->data_ + (i * this->shape_.height + j) * this->shape_.width + k;
    }

    const_pointer at(size_type i , size_type j, size_type k) const noexcept
    {
        return this->data_ + (i * this->shape_.height + j) * this->shape_.width + k;
    }

    reference operator() (size_type i, size_type j, size_type k) noexcept
    {
        return *at(i, j, k); // dereferencing
    }

    const_reference operator() (size_type i, size_type j, size_type k) const noexcept
    {
        return *at(i, j, k); // dereferencing
    }

    Tensor& resize(const shape_type& shape)
    {
        resize(shape.depth, shape.height, shape.width);
        return *this;
    }

    Tensor& resize(size_type depth, size_type height, size_type width)
    {
        delete[] this->data_;

        this->shape_ = shape_type(depth, height, width);
        this->data_ = new precision_type [this->shape_.size];

        return *this;
    }

    Tensor& reshape(size_type depth, size_type height, size_type width) noexcept
    {
        this->shape_.depth = depth;
        this->shape_.height = height;
        this->shape_.width = width;

        return *this;
    }
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

    Tensor(const shape_type& shape, pointer data) noexcept
        : Base(shape, data)
    {
    }

    Tensor(size_type depth, size_type height, size_type width, pointer data) noexcept
        : Base(depth, height, width, data)
    {
    }

    Tensor(pointer first, pointer last) noexcept
        : Base(1, 1, last - first, first)
    {
    }

    Tensor(const Tensor& tensor) noexcept = default;
    Tensor(Tensor&& tensor) noexcept = default;

    Tensor& operator= (const Tensor& tensor) noexcept = default;
    Tensor& operator= (Tensor&& tensor) noexcept = default;

    pointer at(size_type i, size_type j, size_type k) noexcept
    {
        return this->data_ + (i * this->shape_.height + j) * this->shape_.width + k;
    }

    const_pointer at(size_type i , size_type j, size_type k) const noexcept
    {
        return this->data_ + (i * this->shape_.height + j) * this->shape_.width + k;
    }

    reference operator() (size_type i, size_type j, size_type k) noexcept
    {
        return *at(i, j, k); // dereferencing
    }

    const_reference operator() (size_type i, size_type j, size_type k) const noexcept
    {
        return *at(i, j, k); // dereferencing
    }

    Tensor& reshape(size_type depth, size_type height, size_type width) noexcept
    {
        this->shape_.depth = depth;
        this->shape_.height = height;
        this->shape_.width = width;

        return *this;
    }
};

} // namespace lique

} // namespace trixy

#endif // TRIXY_LIQUE_TENSOR_HPP
