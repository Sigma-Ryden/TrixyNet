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

#include <Trixy/Serializer/Core.hpp>

#include <Trixy/Detail/MetaMacro.hpp>
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
    SERIALIZABLE_ACCESS()

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
    Tensor() noexcept : data_(nullptr), shape_(0, 0, 0) {}
    ~Tensor() {}

    explicit Tensor(const shape_type& shape, pointer data = nullptr) noexcept
        : data_(data), shape_(shape) {}

    Tensor(size_type d, size_type h, size_type w, pointer data = nullptr) noexcept
        : data_(data), shape_(d, h, w) {}

    Tensor(size_type h, size_type w, pointer data = nullptr) noexcept
        : data_(data), shape_(h, w) {}

    Tensor(size_type w, pointer data = nullptr) noexcept
        : data_(data), shape_(w) {}

    Tensor(const Tensor& tensor) noexcept
    {
        data_ = tensor.data_;
        shape_ = tensor.shape_;
    }

    Tensor(Tensor&& tensor) noexcept
    {
        data_ = tensor.data_;
        shape_ = tensor.shape_;
        tensor.data_ = nullptr;
    }

    Tensor& operator= (const Tensor& tensor) noexcept
    {
        if (this != &tensor)
        {
            data_ = tensor.data_;
            shape_ = tensor.shape_;
        }

        return *this;
    }

    Tensor& operator= (Tensor&& tensor) noexcept
    {
        if (this != &tensor)
        {
            data_ = tensor.data_;
            shape_ = tensor.shape_;
            tensor.data_ = nullptr;
        }

        return *this;
    }

    Tensor& copy(const_pointer src) noexcept
    {
        lique::detail::copy(data_, data_ + shape_.size, src);
        return *this;
    }

    Tensor& copy(const Tensor& tensor) noexcept
    {
        if (this != &tensor)
            lique::detail::copy(data_, data_ + shape_.size, tensor.data_);

        return *this;
    }

    Tensor& copy(std::initializer_list<precision_type> list) noexcept
    {
        lique::detail::copy(data_, data_ + shape_.size, list.begin());
        return *this;
    }

    template <class Generator,
              TRREQUIRE(trixy::meta::is_callable<Generator>::value)>
    Tensor& fill(Generator generator) noexcept
    {
        lique::detail::fill(data_, data_ + shape_.size, generator);
        return *this;
    }

    Tensor& fill(precision_type value) noexcept
    {
        lique::detail::assign(data_, data_ + shape_.size, lique::detail::cpy(), value);
        return *this;
    }

    template <class Function>
    Tensor apply(Function func) const
    {
        Tensor vector(shape_.size);
        vector.apply(func, data_);
        return vector;
    }

    template <class Function>
    Tensor& apply(Function func) noexcept
    {
        lique::detail::apply(data_, data_ + shape_.size, func);
        return *this;
    }

    template <class Function>
    Tensor& apply(Function func, const_pointer src) noexcept
    {
        lique::detail::apply(data_, data_ + shape_.size, func, src);
        return *this;
    }

    template <class Function>
    Tensor& apply(Function func, const Tensor& rhs) noexcept
    {
        return apply(func, rhs.data_);
    }

    Tensor add(const Tensor& rhs) const
    {
        Tensor vector(shape_.size);
        vector.add(*this, rhs);
        return vector;
    }

    Tensor& add(const Tensor& rhs) noexcept
    {
        lique::detail::assign(data_, data_ + shape_.size, lique::detail::add(), rhs.data_);
        return *this;
    }

    Tensor& add(const Tensor& lhs, const Tensor& rhs) noexcept
    {
        lique::detail::assign(data_, data_ + shape_.size, lique::detail::add(), lhs.data_, rhs.data_);
        return *this;
    }

    Tensor sub(const Tensor& rhs) const
    {
        Tensor vector(shape_.size);
        vector.sub(*this, rhs);
        return vector;
    }

    Tensor& sub(const Tensor& rhs) noexcept
    {
        lique::detail::assign(data_, data_ + shape_.size, lique::detail::sub(), rhs.data_);
        return *this;
    }

    Tensor& sub(const Tensor& lhs, const Tensor& rhs) noexcept
    {
        lique::detail::assign(data_, data_ + shape_.size, lique::detail::sub(), lhs.data_, rhs.data_);
        return *this;
    }

    Tensor mul(const Tensor& rhs) const
    {
        Tensor vector(shape_.size);
        vector.mul(*this, rhs);
        return vector;
    }

    Tensor& mul(const Tensor& rhs) noexcept
    {
        lique::detail::assign(data_, data_ + shape_.size, lique::detail::mul(), rhs.data_);
        return *this;
    }

    Tensor& mul(const Tensor& lhs, const Tensor& rhs) noexcept
    {
        lique::detail::assign(data_, data_ + shape_.size, lique::detail::mul(), lhs.data_, rhs.data_);
        return *this;
    }

    Tensor join(precision_type value) const
    {
        Tensor tensor(shape_.size);
        tensor.join(value, *this);
        return tensor;
    }

    Tensor& join(precision_type value) noexcept
    {
        lique::detail::assign(data_, data_ + shape_.size, lique::detail::mul(), value);
        return *this;
    }

    Tensor& join(precision_type value, const Tensor& rhs) noexcept
    {
        lique::detail::assign(data_, data_ + shape_.size, lique::detail::mul(), value, rhs.data_);
        return *this;
    }

    pointer data() noexcept { return data_; }
    const_pointer data() const noexcept { return data_; }

    size_type size() const noexcept { return shape_.size; }
    const shape_type& shape() const noexcept { return shape_; }

    void swap(Tensor& tensor) noexcept
    {
        std::swap(data_, tensor.data_);
        std::swap(shape_, tensor.shape_);
    }

    operator range_view() const noexcept
    {
        return range_view(data_, data_ + shape_.size);
    }

    pointer at(size_type i) noexcept
    {
        return data_ + i;
    }

    const_pointer at(size_type i) const noexcept
    {
        return data_ + i;
    }

    reference operator() (size_type i) noexcept
    {
        return *at(i); // dereferencing
    }

    const_reference operator() (size_type i) const noexcept
    {
        return *at(i); // dereferencing
    }
};

} // namespace lique

} // namespace trixy

CONDITIONAL_SERIALIZABLE_DECLARATION(trixy::lique::meta::is_tensor_type<S>::value)
SERIALIZABLE_DECLARATION_INIT()

CONDITIONAL_SERIALIZABLE(saveload, tensor, trixy::lique::meta::is_tensor_type<S>::value)
    SERIALIZATION
    (
        archive & tensor.shape_;
        archive & sf::span(tensor.data_, tensor.shape_.size);
    )
SERIALIZABLE_INIT()

#endif // TRIXY_LIQUE_BASE_TENSOR_HPP
