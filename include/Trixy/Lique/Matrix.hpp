#ifndef TRIXY_LIQUE_MATRIX_HPP
#define TRIXY_LIQUE_MATRIX_HPP

#include <cstddef> // size_t

#include <Trixy/Lique/Base.hpp>
#include <Trixy/Lique/TensorBase.hpp>

#include <Trixy/Detail/TrixyMeta.hpp>

#include <Trixy/Lique/Detail/MacroScope.hpp>

namespace trixy
{

namespace lique
{

template <typename Precision, typename TensorMode = TensorMode::own>
using Matrix = Tensor<Precision, TensorType::matrix, TensorMode>;

LIQUE_TENSOR_TEMPLATE()
using MatrixView = Matrix<Precision, TensorMode::view>;

LIQUE_TENSOR_TEMPLATE()
class Tensor<Precision, TensorType::matrix, TensorMode::own>
    : public TensorBase<Precision>
    , public TensorType::matrix
{
    LIQUE_TENSOR_BASE_BODY()

public:
    Tensor() noexcept = default;
    ~Tensor()
    {
        delete[] this->data_;
    }

    explicit Tensor(const shape_type& shape, const_pointer data)
        : Base(shape.depth * shape.height, shape.width)
    {
        this->data_ = new precision_type [this->shape_.size];
        this->copy(data);
    }

    explicit Tensor(const shape_type& shape, precision_type value)
        : Base(shape.depth * shape.height, shape.width)
    {
        this->data_ = new precision_type [this->shape_.size];
        this->fill(value);
    }

    explicit Tensor(const shape_type& shape)
        : Base(shape.depth * shape.height, shape.width)
    {
        this->data_ = new precision_type [this->shape_.size];
    }

    Tensor(size_type height, size_type width, const_pointer data)
        : Base(height, width)
    {
        this->data_ = new precision_type [this->shape_.size];
        this->copy(data);
    }

    Tensor(size_type height, size_type width, precision_type value)
        : Base(height, width)
    {
        this->data_ = new precision_type [this->shape_.size];
        this->fill(value);
    }

    Tensor(size_type height, size_type width)
        : Base(height, width)
    {
        this->data_ = new precision_type [this->shape_.size];
    }

    Tensor(const_pointer first, const_pointer last)
        : Base(1, last - first)
    {
        this->data_ = new precision_type [this->shape_.size];
        this->copy(first);
    }

    Tensor(const Tensor& tensor)
        : Base(tensor.shape_.depth * tensor.shape_.height, tensor.shape_.width)
    {
        this->data_ = new precision_type [tensor.shape_.size];
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
            this->shape_.height = tensor.shape_.height;
            this->shape_.width = tensor.shape_.width;
            this->shape_.size = tensor.shape_.size;
        }

        return *this;
    }

    Tensor& operator= (Tensor&& tensor) noexcept
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

    pointer at(size_type i, size_type j) noexcept
    {
        return this->data_ + i * this->shape_.width + j;
    }

    const_pointer at(size_type i , size_type j) const noexcept
    {
        return this->data_ + i * this->shape_.width + j;
    }

    reference operator() (size_type i, size_type j) noexcept
    {
        return *at(i, j); // dereferencing
    }

    const_reference operator() (size_type i, size_type j) const noexcept
    {
        return *at(i, j); // dereferencing
    }

    Tensor& resize(const shape_type& shape)
    {
        resize(shape.height, shape.width);
        return *this;
    }

    Tensor& resize(size_type height, size_type width)
    {
        delete[] this->data_;

        this->shape_.height = height;
        this->shape_.width = width;
        this->shape_.size = height * width;
        this->data_ = new precision_type [this->shape_.size];

        return *this;
    }

    Tensor& reshape(size_type height, size_type width) noexcept
    {
        this->shape_.height = height;
        this->shape_.width = width;

        return *this;
    }
};

LIQUE_TENSOR_TEMPLATE()
class Tensor<Precision, TensorType::matrix, TensorMode::view>
    : public TensorBase<Precision>
    , public TensorType::matrix
{
    LIQUE_TENSOR_BASE_BODY()

public:
    Tensor() noexcept = default;
    ~Tensor() = default;

    Tensor(const shape_type& shape, pointer data) noexcept
        : Base(shape.depth * shape.height, shape.width, data)
    {
    }

    Tensor(size_type height, size_type width, pointer data) noexcept
        : Base(height, width, data)
    {
    }

    Tensor(pointer first, pointer last) noexcept
    : Base(1, last - first, first)
    {
    }

    Tensor(const Tensor& tensor) noexcept = default;
    Tensor(Tensor&& tensor) noexcept = default;

    Tensor& operator= (const Tensor& tensor) noexcept
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

    Tensor& operator= (Tensor&& tensor) noexcept
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

    pointer at(size_type i, size_type j) noexcept
    {
        return this->data_ + i * this->shape_.width + j;
    }

    const_pointer at(size_type i , size_type j) const noexcept
    {
        return this->data_ + i * this->shape_.width + j;
    }

    reference operator() (size_type i, size_type j) noexcept
    {
        return *at(i, j); // dereferencing
    }

    const_reference operator() (size_type i, size_type j) const noexcept
    {
        return *at(i, j); // dereferencing
    }

    Tensor& reshape(size_type height, size_type width) noexcept
    {
        this->shape_.height = height;
        this->shape_.width = width;

        return *this;
    }
};

} // namespace lique

} // namespace trixy

#endif // TRIXY_LIQUE_MATRIX_HPP
