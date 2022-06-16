#ifndef TRIXY_LIQUE_TENSOR_BASE_HPP
#define TRIXY_LIQUE_TENSOR_BASE_HPP

#include <cstddef> // size_t
#include <initializer_list> // initializer_list

#include <Trixy/Lique/Base.hpp>

#include <Trixy/Lique/Shape.hpp>

#include <Trixy/Range/View.hpp>

#include <Trixy/Lique/Detail/FunctionDetail.hpp>

#include <Trixy/Detail/TrixyMeta.hpp>
#include <Trixy/Lique/Detail/LiqueMeta.hpp>

#include <Trixy/Detail/MacroScope.hpp>
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
using as_view_tensor_mode = trixy::meta::require<is_view_tensor_mode<T>::value>;

template <typename T>
using as_own_tensor_mode = trixy::meta::require<is_own_tensor_mode<T>::value>;

} // namespace meta

template <typename Precision>
using TensorBase = Tensor<Precision, TensorType::base, TensorMode::view>;

template <typename Precision>
class Tensor<Precision, TensorType::base, TensorMode::view> : public TensorType::base
{
    static constexpr bool require = std::is_arithmetic<Precision>::value;

    static_assert(require, "'Precision' should be an arithmetic type.");

public:
    using size_type         = std::size_t;
    using precision_type    = Precision;
    using value_type        = Precision;
    using shape_type        = Shape<std::size_t>;

    using pointer           = Precision*;
    using const_pointer     = const Precision*;

    using reference         = Precision&;
    using const_reference   = const Precision&;

    using range_view        = utility::Range<Precision>;

protected:
    pointer data_;
    shape_type shape_;

public:
    Tensor() noexcept;
    ~Tensor();

    explicit Tensor(const shape_type& shape, pointer data = nullptr) noexcept;

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

    template <class Generator,
              trixy::meta::require<trixy::meta::is_callable<Generator>::value> = 0>
    Tensor& fill(Generator gen) TRIXY_NOEXCEPT_IF(noexcept(gen));

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
    const shape_type& shape() const noexcept;

    void swap(Tensor& tensor) noexcept;

    operator range_view() const noexcept;

    pointer at(size_type i) noexcept;
    const_pointer at(size_type i) const noexcept;

    reference operator() (size_type i) noexcept;
    const_reference operator() (size_type i) const noexcept;
};

LIQUE_TENSOR_TPL_DECLARATION
TensorBase<Precision>::Tensor() noexcept : data_(nullptr), shape_(0, 0, 0) {}

LIQUE_TENSOR_TPL_DECLARATION
TensorBase<Precision>::~Tensor() {}

LIQUE_TENSOR_TPL_DECLARATION
TensorBase<Precision>::Tensor(const shape_type& shape, pointer data) noexcept
: data_(data), shape_(shape) {}

LIQUE_TENSOR_TPL_DECLARATION
TensorBase<Precision>::Tensor(size_type d, size_type h, size_type w, pointer data) noexcept
: data_(data), shape_(d, h, w) {}

LIQUE_TENSOR_TPL_DECLARATION
TensorBase<Precision>::Tensor(size_type h, size_type w, pointer data) noexcept
: data_(data), shape_(h, w) {}

LIQUE_TENSOR_TPL_DECLARATION
TensorBase<Precision>::Tensor(size_type w, pointer data) noexcept
: data_(data), shape_(w) {}

LIQUE_TENSOR_TPL_DECLARATION
TensorBase<Precision>::Tensor(const Tensor& tensor) noexcept
{
    data_ = tensor.data_;
    shape_ = tensor.shape_;
}

LIQUE_TENSOR_TPL_DECLARATION
TensorBase<Precision>::Tensor(Tensor&& tensor) noexcept
{
    data_ = tensor.data_;
    shape_ = tensor.shape_;

    tensor.data_ = nullptr;
}

LIQUE_TENSOR_TPL_DECLARATION
TensorBase<Precision>& TensorBase<Precision>::operator= (const Tensor& tensor) noexcept
{
    if (this != &tensor)
    {
        data_ = tensor.data_;
        shape_ = tensor.shape_;
    }

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
TensorBase<Precision>& TensorBase<Precision>::operator= (Tensor&& tensor) noexcept
{
    if (this != &tensor)
    {
        data_ = tensor.data_;
        shape_ = tensor.shape_;

        tensor.data_ = nullptr;
    }

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
TensorBase<Precision>& TensorBase<Precision>::copy(const_pointer src) noexcept
{
    lique::detail::copy(data_, data_ + shape_.size, src);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
TensorBase<Precision>& TensorBase<Precision>::copy(const Tensor& vector) noexcept
{
    if (this != &vector)
        lique::detail::copy(data_, data_ + shape_.size, vector.data_);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
TensorBase<Precision>& TensorBase<Precision>::copy(
    std::initializer_list<precision_type> init) noexcept
{
    lique::detail::copy(data_, data_ + shape_.size, init.begin());

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
template <class Generator, trixy::meta::require<trixy::meta::is_callable<Generator>::value>>
TensorBase<Precision>& TensorBase<Precision>::fill(Generator gen)
    TRIXY_NOEXCEPT_IF(noexcept(gen))
{
    lique::detail::fill(data_, data_ + shape_.size, gen);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
TensorBase<Precision>& TensorBase<Precision>::fill(precision_type value) noexcept
{
    lique::detail::assign(data_, data_ + shape_.size, lique::detail::cpy(), value);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
template <class Function>
TensorBase<Precision> TensorBase<Precision>::apply(Function func) const
{
    Tensor vector(shape_.size);

    vector.apply(func, data_);

    return vector;
}

LIQUE_TENSOR_TPL_DECLARATION
template <class Function>
TensorBase<Precision>& TensorBase<Precision>::apply(Function func) noexcept
{
    lique::detail::apply(data_, data_ + shape_.size, func);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
template <class Function>
TensorBase<Precision>& TensorBase<Precision>::apply(Function func, const_pointer src) noexcept
{
    lique::detail::apply(data_, data_ + shape_.size, func, src);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
template <class Function>
TensorBase<Precision>& TensorBase<Precision>::apply(Function func, const Tensor& vector) noexcept
{
    return apply(func, vector.data_);
}

LIQUE_TENSOR_TPL_DECLARATION
TensorBase<Precision> TensorBase<Precision>::add(const Tensor& rhs) const
{
    Tensor vector(shape_.size);

    vector.add(*this, rhs);

    return vector;
}

LIQUE_TENSOR_TPL_DECLARATION
TensorBase<Precision>& TensorBase<Precision>::add(const Tensor& rhs) noexcept
{
    lique::detail::assign(data_, data_ + shape_.size, lique::detail::add(), rhs.data_);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
TensorBase<Precision>& TensorBase<Precision>::add(const Tensor& lhs, const Tensor& rhs) noexcept
{
    lique::detail::assign(data_, data_ + shape_.size, lique::detail::add(), lhs.data_, rhs.data_);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
TensorBase<Precision> TensorBase<Precision>::sub(const Tensor& rhs) const
{
    Tensor vector(shape_.size);

    vector.sub(*this, rhs);

    return vector;
}

LIQUE_TENSOR_TPL_DECLARATION
TensorBase<Precision>& TensorBase<Precision>::sub(const Tensor& rhs) noexcept
{
    lique::detail::assign(data_, data_ + shape_.size, lique::detail::sub(), rhs.data_);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
TensorBase<Precision>& TensorBase<Precision>::sub(const Tensor& lhs, const Tensor& rhs) noexcept
{
    lique::detail::assign(data_, data_ + shape_.size, lique::detail::sub(), lhs.data_, rhs.data_);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
TensorBase<Precision> TensorBase<Precision>::mul(const Tensor& rhs) const
{
    Tensor vector(shape_.size);

    vector.mul(*this, rhs);

    return vector;
}

LIQUE_TENSOR_TPL_DECLARATION
TensorBase<Precision>& TensorBase<Precision>::mul(const Tensor& rhs) noexcept
{
    lique::detail::assign(data_, data_ + shape_.size, lique::detail::mul(), rhs.data_);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
TensorBase<Precision>& TensorBase<Precision>::mul(const Tensor& lhs, const Tensor& rhs) noexcept
{
    lique::detail::assign(data_, data_ + shape_.size, lique::detail::mul(), lhs.data_, rhs.data_);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
TensorBase<Precision> TensorBase<Precision>::join(precision_type value) const
{
    Tensor tensor(shape_.size);

    tensor.join(value, *this);

    return tensor;
}

LIQUE_TENSOR_TPL_DECLARATION
TensorBase<Precision>& TensorBase<Precision>::join(precision_type value) noexcept
{
    lique::detail::assign(data_, data_ + shape_.size, lique::detail::mul(), value);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
TensorBase<Precision>& TensorBase<Precision>::join(precision_type value, const Tensor& rhs) noexcept
{
    lique::detail::assign(data_, data_ + shape_.size, lique::detail::mul(), value, rhs.data_);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
inline auto TensorBase<Precision>::data() noexcept -> pointer
{
    return data_;
}

LIQUE_TENSOR_TPL_DECLARATION
inline auto TensorBase<Precision>::data() const noexcept -> const_pointer
{
    return data_;
}

LIQUE_TENSOR_TPL_DECLARATION
inline auto TensorBase<Precision>::size() const noexcept -> size_type
{
    return shape_.size;
}

LIQUE_TENSOR_TPL_DECLARATION
inline auto TensorBase<Precision>::shape() const noexcept -> const shape_type&
{
    return shape_;
}

LIQUE_TENSOR_TPL_DECLARATION
void TensorBase<Precision>::swap(Tensor& tensor) noexcept
{
    std::swap(data_, tensor.data_);
    std::swap(shape_, tensor.shape_);
}

LIQUE_TENSOR_TPL_DECLARATION
inline TensorBase<Precision>::operator range_view() const noexcept
{
    return range_view(data_, data_ + shape_.size);
}

LIQUE_TENSOR_TPL_DECLARATION
inline auto TensorBase<Precision>::at(size_type i) noexcept -> pointer
{
    return data_ + i;
}

LIQUE_TENSOR_TPL_DECLARATION
inline auto TensorBase<Precision>::at(size_type i) const noexcept -> const_pointer
{
    return data_ + i;
}

LIQUE_TENSOR_TPL_DECLARATION
inline auto TensorBase<Precision>::operator() (size_type i) noexcept -> reference
{
    return *at(i); // dereferencing
}

LIQUE_TENSOR_TPL_DECLARATION
inline auto TensorBase<Precision>::operator() (size_type i) const noexcept -> const_reference
{
    return *at(i); // dereferencing
}

} // namespace lique

} // namespace trixy

#include <Trixy/Detail/MacroUnscope.hpp>
#include <Trixy/Lique/Detail/MacroUnscope.hpp>

#endif // TRIXY_LIQUE_BASE_TENSOR_HPP
