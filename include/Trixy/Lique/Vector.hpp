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
    ~Tensor();

    explicit Tensor(const shape_type& shape, const_pointer data);
    explicit Tensor(const shape_type& shape, precision_type value);
    explicit Tensor(const shape_type& shape);

    Tensor(std::initializer_list<precision_type> init);

    Tensor(size_type width, const_pointer data);
    Tensor(size_type width, precision_type value);
    Tensor(size_type width);

    Tensor(const_pointer first, const_pointer last);

    Tensor(const Tensor& tensor);
    Tensor(Tensor&& tensor) noexcept;

    Tensor& operator= (const Tensor& tensor);
    Tensor& operator= (Tensor&& tensor) noexcept;

    void resize(const shape_type& shape);
    void resize(size_type width);

    void reshape(size_type width) noexcept;
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

    Tensor(const shape_type& shape, pointer data) noexcept;
    Tensor(size_type width, pointer data) noexcept;
    Tensor(pointer first, pointer last) noexcept;

    Tensor(const Tensor& tensor) noexcept = default;
    Tensor(Tensor&& tensor) noexcept = default;

    Tensor& operator= (const Tensor& tensor) noexcept;
    Tensor& operator= (Tensor&& tensor) noexcept;

    void reshape(size_type width) noexcept;
};

LIQUE_TENSOR_TEMPLATE()
Vector<Precision>::~Tensor()
{
    delete[] this->data_;
}

LIQUE_TENSOR_TEMPLATE()
Vector<Precision>::Tensor(const shape_type& shape, const_pointer data)
    : Base(shape.width)
{
    this->data = new precision_type [shape.size];

    this->copy(data);
}

LIQUE_TENSOR_TEMPLATE()
Vector<Precision>::Tensor(const shape_type& shape, precision_type value)
    : Base(shape.width)
{
    this->data = new precision_type [shape.size];

    this->fill(value);
}

LIQUE_TENSOR_TEMPLATE()
Vector<Precision>::Tensor(const shape_type& shape)
    : Base(shape.width)
{
    this->data = new precision_type [shape.size];
}

LIQUE_TENSOR_TEMPLATE()
Vector<Precision>::Tensor(std::initializer_list<precision_type> init)
    : Base(init.size())
{
    this->data_ = new precision_type [this->shape_.size];

    this->copy(init.begin());
}

LIQUE_TENSOR_TEMPLATE()
Vector<Precision>::Tensor(size_type width, const_pointer data)
    : Base(width)
{
    this->data_ = new precision_type [this->shape_.size];

    this->copy(data);
}

LIQUE_TENSOR_TEMPLATE()
Vector<Precision>::Tensor(size_type width, precision_type value)
    : Base(width)
{
    this->data_ = new precision_type [this->shape_.size];

    this->fill(value);
}

LIQUE_TENSOR_TEMPLATE()
Vector<Precision>::Tensor(size_type width)
    : Base(width)
{
    this->data_ = new precision_type [this->shape_.size];
}

LIQUE_TENSOR_TEMPLATE()
Vector<Precision>::Tensor(const_pointer first, const_pointer last)
    : Base(last - first)
{
    this->data_ = new precision_type [this->shape_.size];

    this->copy(first);
}

LIQUE_TENSOR_TEMPLATE()
Vector<Precision>::Tensor(const Tensor& tensor) : Base(tensor.shape_.width)
{
    this->data_ = new precision_type [tensor.shape_.size];

    this->copy(tensor.data_);
}

LIQUE_TENSOR_TEMPLATE()
Vector<Precision>::Tensor(Tensor&& tensor) noexcept
    : Base(std::move(tensor))
{
}

LIQUE_TENSOR_TEMPLATE()
Vector<Precision>& Vector<Precision>::operator= (const Tensor& tensor)
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

LIQUE_TENSOR_TEMPLATE()
Vector<Precision>& Vector<Precision>::operator= (Tensor&& tensor) noexcept
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

LIQUE_TENSOR_TEMPLATE()
void Vector<Precision>::resize(const shape_type& shape)
{
    resize(shape.width);
}

LIQUE_TENSOR_TEMPLATE()
void Vector<Precision>::resize(size_type width)
{
    delete[] this->data_;

    this->shape_.width = width;
    this->shape_.size = width;

    this->data_ = new precision_type [width];
}

LIQUE_TENSOR_TEMPLATE()
void Vector<Precision>::reshape(size_type width) noexcept
{
    this->shape_.width = width;
}

LIQUE_TENSOR_TEMPLATE()
VectorView<Precision>::Tensor(const shape_type& shape, pointer data) noexcept
    : Base(shape.width, data)
{
}

LIQUE_TENSOR_TEMPLATE()
VectorView<Precision>::Tensor(size_type width, pointer data) noexcept
    : Base(width, data)
{
}

LIQUE_TENSOR_TEMPLATE()
VectorView<Precision>::Tensor(pointer first, pointer last) noexcept
    : Base(last - first, first)
{
}

LIQUE_TENSOR_TEMPLATE()
VectorView<Precision>& VectorView<Precision>::operator= (const Tensor& tensor) noexcept
{
    if (this != &tensor)
    {
        this->data_ = tensor.data_;

        this->shape_.width = tensor.shape_.width;
        this->shape_.size = tensor.shape_.size;
    }

    return *this;
}

LIQUE_TENSOR_TEMPLATE()
VectorView<Precision>& VectorView<Precision>::operator= (Tensor&& tensor) noexcept
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

LIQUE_TENSOR_TEMPLATE()
void VectorView<Precision>::reshape(size_type width) noexcept
{
    this->shape_.width = width;
}

} // namespace lique

} // namespace trixy

#include <Trixy/Lique/Detail/MacroUnscope.hpp>

#endif // TRIXY_LIQUE_VECTOR_HPP
