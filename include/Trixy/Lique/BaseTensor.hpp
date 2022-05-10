#ifndef TRIXY_LIQUE_BASE_TENSOR_HPP
#define TRIXY_LIQUE_BASE_TENSOR_HPP

#include <cstddef> // size_t
#include <initializer_list> // initializer_list

#include <Trixy/Lique/Base.hpp>
#include <Trixy/Lique/Detail/FunctionDetail.hpp>

#include <Trixy/Detail/TrixyMeta.hpp>
#include <Trixy/Lique/Detail/LiqueMeta.hpp>

#include <Trixy/Lique/Detail/MacroScope.hpp>

namespace trixy
{

namespace lique
{

namespace meta
{

template <typename T>
using is_view_tensor_mode = std::is_same<T, TensorMode::view>;

template <typename T>
using is_own_tensor_mode = std::is_same<T, TensorMode::own>;

template <typename T>
using as_view_tensor_mode = trixy::meta::as<is_view_tensor_mode<T>::value>;

template <typename T>
using as_own_tensor_mode = trixy::meta::as<is_own_tensor_mode<T>::value>;

} // namespace meta

struct Shape
{
public:
    using size_type = std::size_t;

public:
    size_type depth;
    size_type height;
    size_type width;

    size_type size;

public:
    Shape() : depth(0), height(0), width(0) {}

    explicit Shape(size_type d, size_type h, size_type w)
    : depth(d), height(h), width(w), size(d * h * w) {}

    explicit Shape(size_type h, size_type w)
    : depth(1), height(h), width(w), size(h * w) {}

    explicit Shape(size_type w)
    : depth(1), height(1), width(w), size(w) {}
};

template <typename Precision>
using BaseTensor = Tensor<Precision, TensorType::base, TensorMode::view>;

template <typename Precision>
class Tensor<Precision, TensorType::base, TensorMode::view> : public TensorType::base
{
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

public:
    Tensor() noexcept;
    ~Tensor();

    explicit Tensor(const Shape& shape, pointer data = nullptr) noexcept;

    Tensor(size_type d, size_type h, size_type w, pointer data = nullptr) noexcept;
    Tensor(size_type h, size_type w, pointer data = nullptr) noexcept;
    Tensor(size_type w, pointer data = nullptr) noexcept;

    Tensor(const Tensor& tensor) noexcept;
    Tensor(Tensor&& tensor) noexcept;

    Tensor& operator= (const Tensor& tensor) noexcept;
    Tensor& operator= (Tensor&& tensor) noexcept;

    Tensor& copy(const_pointer src) noexcept;
    Tensor& copy(const Tensor&) noexcept;
    Tensor& copy(std::initializer_list<precision_type>) noexcept;

    template <class Generator, trixy::meta::as<trixy::meta::is_callable<Generator>::value> = 0>
    Tensor& fill(Generator gen) noexcept;

    Tensor& fill(precision_type value) noexcept;

    template <class Function>
    Tensor apply(Function func) const;

    template <class Function>
    Tensor& apply(Function func) noexcept;

    template <class Function>
    Tensor& apply(Function func, const_pointer src) noexcept;

    template <class Function>
    Tensor& apply(Function func, const Tensor& rhs) noexcept;

    Tensor add(const Tensor& rhs) const;
    Tensor& add(const Tensor& rhs) noexcept;
    Tensor& add(const Tensor& lhs, const Tensor& rhs) noexcept;

    Tensor sub(const Tensor& rhs) const;
    Tensor& sub(const Tensor& rhs) noexcept;
    Tensor& sub(const Tensor& lhs, const Tensor& rhs) noexcept;

    Tensor mul(const Tensor& rhs) const;
    Tensor& mul(const Tensor& rhs) noexcept;
    Tensor& mul(const Tensor& lhs, const Tensor& rhs) noexcept;

    Tensor join(precision_type value) const;
    Tensor& join(precision_type value) noexcept;
    Tensor& join(precision_type value, const Tensor&) noexcept;

    pointer data() noexcept;
    const_pointer data() const noexcept;

    size_type size() const noexcept;
    const Shape& shape() const noexcept;

    void swap(Tensor& tensor) noexcept;

    reference operator() (size_type i) noexcept;
    const_reference operator() (size_type i) const noexcept;
};

LIQUE_TENSOR_TPL_DECLARATION
BaseTensor<Precision>::Tensor() noexcept : data_(nullptr), shape_(0, 0, 0) {}

LIQUE_TENSOR_TPL_DECLARATION
BaseTensor<Precision>::~Tensor() {}

LIQUE_TENSOR_TPL_DECLARATION
BaseTensor<Precision>::Tensor(const Shape& shape, pointer data) noexcept
: data_(data), shape_(shape) {}

LIQUE_TENSOR_TPL_DECLARATION
BaseTensor<Precision>::Tensor(size_type d, size_type h, size_type w, pointer data) noexcept
: data_(data), shape_(d, h, w) {}

LIQUE_TENSOR_TPL_DECLARATION
BaseTensor<Precision>::Tensor(size_type h, size_type w, pointer data) noexcept
: data_(data), shape_(h, w) {}

LIQUE_TENSOR_TPL_DECLARATION
BaseTensor<Precision>::Tensor(size_type w, pointer data) noexcept
: data_(data), shape_(w) {}

LIQUE_TENSOR_TPL_DECLARATION
BaseTensor<Precision>::Tensor(const Tensor& tensor) noexcept
{
    data_ = tensor.data_;
    shape_ = tensor.shape_;
}

LIQUE_TENSOR_TPL_DECLARATION
BaseTensor<Precision>::Tensor(Tensor&& tensor) noexcept
{
    data_ = tensor.data_;
    shape_ = tensor.shape_;

    tensor.data_ = nullptr;
}

LIQUE_TENSOR_TPL_DECLARATION
BaseTensor<Precision>& BaseTensor<Precision>::operator= (const Tensor& tensor) noexcept
{
    if(this != &tensor)
    {
        data_ = tensor.data_;
        shape_ = tensor.shape_;
    }

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
BaseTensor<Precision>& BaseTensor<Precision>::operator= (Tensor&& tensor) noexcept
{
    if(this != &tensor)
    {
        data_ = tensor.data_;
        shape_ = tensor.shape_;

        tensor.data_ = nullptr;
    }

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
BaseTensor<Precision>& BaseTensor<Precision>::copy(const_pointer src) noexcept
{
    lique::detail::copy(data_, data_ + shape_.size, src);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
BaseTensor<Precision>& BaseTensor<Precision>::copy(const Tensor& vector) noexcept
{
    if(this != &vector)
        lique::detail::copy(data_, data_ + shape_.size, vector.data_);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
BaseTensor<Precision>& BaseTensor<Precision>::copy(
    std::initializer_list<precision_type> init) noexcept
{
    lique::detail::copy(data_, data_ + shape_.size, init.begin());

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
template <class Generator, trixy::meta::as<trixy::meta::is_callable<Generator>::value>>
BaseTensor<Precision>& BaseTensor<Precision>::fill(Generator gen) noexcept
{
    lique::detail::fill(data_, data_ + shape_.size, gen);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
BaseTensor<Precision>& BaseTensor<Precision>::fill(precision_type value) noexcept
{
    lique::detail::assign(data_, data_ + shape_.size, lique::detail::cpy(), value);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
template <class Function>
BaseTensor<Precision> BaseTensor<Precision>::apply(Function func) const
{
    Tensor vector(shape_.size);

    vector.apply(func, data_);

    return vector;
}

LIQUE_TENSOR_TPL_DECLARATION
template <class Function>
BaseTensor<Precision>& BaseTensor<Precision>::apply(Function func) noexcept
{
    lique::detail::apply(data_, data_ + shape_.size, func);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
template <class Function>
BaseTensor<Precision>& BaseTensor<Precision>::apply(Function func, const_pointer src) noexcept
{
    lique::detail::apply(data_, data_ + shape_.size, func, src);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
template <class Function>
BaseTensor<Precision>& BaseTensor<Precision>::apply(Function func, const Tensor& vector) noexcept
{
    return apply(func, vector.data_);
}

LIQUE_TENSOR_TPL_DECLARATION
BaseTensor<Precision> BaseTensor<Precision>::add(const Tensor& rhs) const
{
    Tensor vector(shape_.size);

    vector.add(*this, rhs);

    return vector;
}

LIQUE_TENSOR_TPL_DECLARATION
BaseTensor<Precision>& BaseTensor<Precision>::add(const Tensor& rhs) noexcept
{
    lique::detail::assign(data_, data_ + shape_.size, lique::detail::add(), rhs.data_);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
BaseTensor<Precision>& BaseTensor<Precision>::add(const Tensor& lhs, const Tensor& rhs) noexcept
{
    lique::detail::assign(data_, data_ + shape_.size, lique::detail::add(), lhs.data_, rhs.data_);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
BaseTensor<Precision> BaseTensor<Precision>::sub(const Tensor& rhs) const
{
    Tensor vector(shape_.size);

    vector.sub(*this, rhs);

    return vector;
}

LIQUE_TENSOR_TPL_DECLARATION
BaseTensor<Precision>& BaseTensor<Precision>::sub(const Tensor& rhs) noexcept
{
    lique::detail::assign(data_, data_ + shape_.size, lique::detail::sub(), rhs.data_);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
BaseTensor<Precision>& BaseTensor<Precision>::sub(const Tensor& lhs, const Tensor& rhs) noexcept
{
    lique::detail::assign(data_, data_ + shape_.size, lique::detail::sub(), lhs.data_, rhs.data_);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
BaseTensor<Precision> BaseTensor<Precision>::mul(const Tensor& rhs) const
{
    Tensor vector(shape_.size);

    vector.mul(*this, rhs);

    return vector;
}

LIQUE_TENSOR_TPL_DECLARATION
BaseTensor<Precision>& BaseTensor<Precision>::mul(const Tensor& rhs) noexcept
{
    lique::detail::assign(data_, data_ + shape_.size, lique::detail::mul(), rhs.data_);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
BaseTensor<Precision>& BaseTensor<Precision>::mul(const Tensor& lhs, const Tensor& rhs) noexcept
{
    lique::detail::assign(data_, data_ + shape_.size, lique::detail::mul(), lhs.data_, rhs.data_);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
BaseTensor<Precision> BaseTensor<Precision>::join(precision_type value) const
{
    Tensor tensor(shape_.size);

    tensor.join(value, *this);

    return tensor;
}

LIQUE_TENSOR_TPL_DECLARATION
BaseTensor<Precision>& BaseTensor<Precision>::join(precision_type value) noexcept
{
    lique::detail::assign(data_, data_ + shape_.size, lique::detail::mul(), value);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
BaseTensor<Precision>& BaseTensor<Precision>::join(precision_type value, const Tensor& rhs) noexcept
{
    lique::detail::assign(data_, data_ + shape_.size, lique::detail::mul(), value, rhs.data_);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
inline typename BaseTensor<Precision>::pointer BaseTensor<Precision>::data() noexcept
{
    return data_;
}

LIQUE_TENSOR_TPL_DECLARATION
inline typename BaseTensor<Precision>::const_pointer BaseTensor<Precision>::data() const noexcept
{
    return data_;
}

LIQUE_TENSOR_TPL_DECLARATION
inline typename BaseTensor<Precision>::size_type BaseTensor<Precision>::size() const noexcept
{
    return shape_.size;
}

LIQUE_TENSOR_TPL_DECLARATION
inline const Shape& BaseTensor<Precision>::shape() const noexcept
{
    return shape_;
}

LIQUE_TENSOR_TPL_DECLARATION
void BaseTensor<Precision>::swap(Tensor& tensor) noexcept
{
    std::swap(data_, tensor.data_);
    std::swap(shape_, tensor.shape_);
}

LIQUE_TENSOR_TPL_DECLARATION
inline typename BaseTensor<Precision>::reference
    BaseTensor<Precision>::operator() (size_type i) noexcept
{
    return data_[i];
}

LIQUE_TENSOR_TPL_DECLARATION
inline typename BaseTensor<Precision>::const_reference
    BaseTensor<Precision>::operator() (size_type i) const noexcept
{
    return data_[i];
}

} // namespace lique

} // namespace trixy

#include <Trixy/Lique/Detail/MacroUnscope.hpp>

#endif // TRIXY_LIQUE_BASE_TENSOR_HPP
