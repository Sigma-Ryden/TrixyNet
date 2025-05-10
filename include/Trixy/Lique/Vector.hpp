#ifndef TRIXY_LIQUE_VECTOR_HPP
#define TRIXY_LIQUE_VECTOR_HPP

#include <cstddef> // size_t
#include <initializer_list> // initializer_list

#include <Trixy/Lique/Base.hpp>
#include <Trixy/Lique/TensorBase.hpp>

#include <Trixy/Detail/TrixyMeta.hpp>

#include <Trixy/Lique/Detail/MacroScope.hpp>

namespace trixy
{

namespace lique
{

template <typename Precision, typename TensorMode = TensorMode::own>
using Vector = Tensor<Precision, TensorType::vector, TensorMode>;

template <typename Precision>
using VectorView = Vector<Precision, TensorMode::view>;

template <typename Precision>
class Tensor<Precision, TensorType::vector, TensorMode::own>
    : public TensorBase<Precision>
    , public TensorType::vector
{
    LIQUE_TENSOR_BASE_BODY()

public:
    Tensor() noexcept = default;
    ~Tensor()
    {
        delete[] this->data_;
    }

    explicit Tensor(const shape_type& shape, const_pointer data)
        : Base(shape.width)
    {
        this->data = new precision_type [shape.size];
        this->copy(data);
    }

    explicit Tensor(const shape_type& shape, precision_type value)
        : Base(shape.width)
    {
        this->data = new precision_type [shape.size];
        this->fill(value);
    }

    explicit Tensor(const shape_type& shape)
        : Base(shape.width)
    {
        this->data = new precision_type [shape.size];
    }

    Tensor(std::initializer_list<precision_type> init)
        : Base(init.size())
    {
        this->data_ = new precision_type [this->shape_.size];
        this->copy(init.begin());
    }

    Tensor(size_type width, const_pointer data)
        : Base(width)
    {
        this->data_ = new precision_type [this->shape_.size];
        this->copy(data);
    }

    Tensor(size_type width, precision_type value)
        : Base(width)
    {
        this->data_ = new precision_type [this->shape_.size];
        this->fill(value);
    }

    Tensor(size_type width)
        : Base(width)
    {
        this->data_ = new precision_type [this->shape_.size];
    }

    Tensor(const_pointer first, const_pointer last)
        : Base(last - first)
    {
        this->data_ = new precision_type [this->shape_.size];
        this->copy(first);
    }

    Tensor(const Tensor& tensor)
    {
        this->data_ = new precision_type [tensor.shape_.size];
        this->copy(tensor.data_);
    }

    Tensor(Tensor&& tensor) noexcept
        : Base(std::move(tensor))
    {
    }

    Tensor& operator= (const Tensor& tensor)
    {
        if (this != &tensor)
        {
            delete[] this->data_;

            this->data_ = new precision_type [tensor.shape_.size];
            this->shape_.width = tensor.shape_.width;
            this->shape_.size = tensor.shape_.size;
            this->copy(tensor.data_);
        }

        return *this;
    }

    Tensor& operator= (Tensor&& tensor) noexcept
    {
        if (this != &tensor)
        {
            delete[] this->data_;

            this->data_ = tensor.data_;
            this->shape_.width = tensor.shape_.width;
            this->shape_.size = tensor.shape_.size;
            tensor.data_ = nullptr;
        }

        return *this;
    }

    Tensor& resize(const shape_type& shape)
    {
        resize(shape.width);
        return *this;
    }

    Tensor& resize(size_type width)
    {
        delete[] this->data_;

        this->shape_ = shape_type(1, width, 1);
        this->data_ = new precision_type [width];

        return *this;
    }

    Tensor& reshape(size_type width) noexcept
    {
        this->shape_.width = width;
        return *this;
    }
};

template <typename Precision>
class Tensor<Precision, TensorType::vector, TensorMode::view>
    : public TensorBase<Precision>
    , public TensorType::vector
{
    LIQUE_TENSOR_BASE_BODY()

public:
    Tensor() noexcept = default;
    ~Tensor() = default;

    Tensor(const shape_type& shape, pointer data) noexcept
        : Base(shape.width, data)
    {
    }

    Tensor(size_type width, pointer data) noexcept
        : Base(width, data)
    {
    }

    Tensor(pointer first, pointer last) noexcept
        : Base(last - first, first)
    {
    }

    Tensor(const Tensor& tensor) noexcept = default;
    Tensor(Tensor&& tensor) noexcept = default;

    Tensor& operator= (const Tensor& tensor) noexcept
    {
        if (this != &tensor)
        {
            this->data_ = tensor.data_;
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
            this->shape_.width = tensor.shape_.width;
            this->shape_.size = tensor.shape_.size;
            tensor.data_ = nullptr;
        }

        return *this;
    }

    Tensor& reshape(size_type width) noexcept
    {
        this->shape_.width = width;
        return *this;
    }
};

} // namespace lique

} // namespace trixy

#endif // TRIXY_LIQUE_VECTOR_HPP
