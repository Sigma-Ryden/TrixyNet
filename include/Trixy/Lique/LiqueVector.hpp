#ifndef LIQUE_VECTOR_HPP
#define LIQUE_VECTOR_HPP

#include <cstddef> // size_t
#include <initializer_list> // initializer_list

#include "LiqueBaseTensor.hpp"

#include "Trixy/Detail/TrixyMeta.hpp"
#include "Detail/FunctionDetail.hpp"

#include "Detail/MacroScope.hpp"

namespace trixy
{

namespace lique
{

LIQUE_TENSOR_TPL_DECLARATION
using Vector = LIQUE_TENSOR_TPL(TensorType::vector);

LIQUE_TENSOR_TPL_DECLARATION
class LIQUE_TENSOR_TPL(TensorType::vector) : public TensorType::vector
{
public:
    using size_type         = std::size_t;
    using precision_type    = Precision;

    using pointer           = Precision*;
    using const_pointer     = const Precision*;

    using reference         = Precision&;
    using const_reference   = const Precision&;

protected:
    pointer   data_;
    size_type size_;

public:
    Tensor() noexcept;
    ~Tensor();

    explicit Tensor(size_type size);
    explicit Tensor(const_pointer first, const_pointer last);

    Tensor(size_type size, precision_type value);
    Tensor(size_type size, const_pointer src);

    Tensor(const Tensor&);
    Tensor(Tensor&&) noexcept;
    Tensor(std::initializer_list<precision_type>);

    Tensor& operator= (const Tensor&);
    Tensor& operator= (Tensor&&) noexcept;

    Tensor& copy(const_pointer src) noexcept;
    Tensor& copy(const Tensor&) noexcept;
    Tensor& copy(std::initializer_list<precision_type>) noexcept;

    size_type size() const noexcept;

    void resize(size_type size);
    void resize(size_type size, precision_type value);
    void resize(size_type size, const_pointer src);

    reference operator() (size_type i) noexcept;
    const_reference operator() (size_type i) const noexcept;

    template <class Generator, trixy::meta::as_callable_t<Generator> = 0>
    Tensor& fill(Generator gen) noexcept;

    Tensor& fill(precision_type value) noexcept;

    template <class Function>
    Tensor apply(Function func) const;

    template <class Function>
    Tensor& apply(Function func) noexcept;

    template <class Function>
    Tensor& apply(Function func, const_pointer src) noexcept;

    template <class Function>
    Tensor& apply(Function func, const Tensor&) noexcept;

    precision_type dot(const Tensor&) const;

    Tensor add(const Tensor&) const;
    Tensor& add(const Tensor&) noexcept;
    Tensor& add(const Tensor&, const Tensor&) noexcept;

    Tensor sub(const Tensor&) const;
    Tensor& sub(const Tensor&) noexcept;
    Tensor& sub(const Tensor&, const Tensor&) noexcept;

    Tensor mul(const Tensor&) const;
    Tensor& mul(const Tensor&) noexcept;
    Tensor& mul(const Tensor&, const Tensor&) noexcept;

    Tensor join(precision_type value) const;
    Tensor& join(precision_type value) noexcept;
    Tensor& join(precision_type value, const Tensor&) noexcept;

    pointer data() noexcept;
    const_pointer data() const noexcept;
};

LIQUE_TENSOR_TPL_DECLARATION
inline Vector<Precision>::Tensor() noexcept
    : data_(nullptr), size_(0)
{
}

LIQUE_TENSOR_TPL_DECLARATION
inline Vector<Precision>::~Tensor()
{
    delete[] data_;
}

LIQUE_TENSOR_TPL_DECLARATION
inline Vector<Precision>::Tensor(size_type size)
    : data_(new precision_type [size]), size_(size)
{
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision>::Tensor(const_pointer first, const_pointer last)
    : data_(new precision_type [last - first]), size_(last - first)
{
     detail::copy(data_, data_ + size_, first);
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision>::Tensor(size_type size, precision_type value)
    : data_(new precision_type [size]), size_(size)
{
    fill(value);
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision>::Tensor(size_type size, const_pointer src)
    : data_(new precision_type [size]), size_(size)
{
     detail::copy(data_, data_ + size_, src);
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision>::Tensor(const Tensor& vector)
    : data_(new precision_type [vector.size_]), size_(vector.size_)
{
     detail::copy(data_, data_ + size_, vector.data_);
}

LIQUE_TENSOR_TPL_DECLARATION
inline Vector<Precision>::Tensor(Tensor&& vector) noexcept
    : data_(vector.data_), size_(vector.size_)
{
    vector.data_ = nullptr;
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision>::Tensor(std::initializer_list<precision_type> init)
    : data_(new precision_type [init.size()]), size_(init.size())
{
     detail::copy(data_, data_ + size_, init.begin());
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision>& Vector<Precision>::operator= (const Tensor& vector)
{
    if(this != &vector)
    {
        delete[] data_;

        size_ = vector.size_;
        data_ = new precision_type [size_];

        detail::copy(data_, data_ + size_, vector.data_);
    }

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision>& Vector<Precision>::operator= (Tensor&& vector) noexcept
{
    if(this != &vector)
    {
        delete[] data_;

        size_ = vector.size_;
        data_ = vector.data_;

        vector.data_ = nullptr;
    }

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision>& Vector<Precision>::copy(const_pointer src) noexcept
{
     detail::copy(data_, data_ + size_, src);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision>& Vector<Precision>::copy(const Tensor& vector) noexcept
{
    if(this != &vector)
         detail::copy(data_, data_ + size_, vector.data_);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision>& Vector<Precision>::copy(
    std::initializer_list<precision_type> init) noexcept
{
    detail::copy(data_, data_ + size_, init.begin());

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
inline typename Vector<Precision>::size_type Vector<Precision>::size() const noexcept
{
    return size_;
}

LIQUE_TENSOR_TPL_DECLARATION
void Vector<Precision>::resize(size_type size)
{
    delete[] data_;

    size_ = size;
    data_ = new precision_type [size_];
}

LIQUE_TENSOR_TPL_DECLARATION
void Vector<Precision>::resize(size_type size, precision_type value)
{
    resize(size);
    fill(value);
}

LIQUE_TENSOR_TPL_DECLARATION
void Vector<Precision>::resize(size_type size, const_pointer src)
{
    resize(size);

    detail::copy(data_, data_ + size_, src);
}

LIQUE_TENSOR_TPL_DECLARATION
inline typename Vector<Precision>::reference
    Vector<Precision>::operator() (size_type i) noexcept
{
    return data_[i];
}

LIQUE_TENSOR_TPL_DECLARATION
inline typename Vector<Precision>::const_reference
    Vector<Precision>::operator() (size_type i) const noexcept
{
    return data_[i];
}

LIQUE_TENSOR_TPL_DECLARATION
template <class Generator, trixy::meta::as_callable_t<Generator>>
Vector<Precision>& Vector<Precision>::fill(Generator gen) noexcept
{
    detail::fill(data_, data_ + size_, gen);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision>& Vector<Precision>::fill(precision_type value) noexcept
{
    detail::assign(data_, data_ + size_, detail::cpy(), value);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
template <class Function>
Vector<Precision> Vector<Precision>::apply(Function func) const
{
    Tensor vector(size_);

    vector.apply(func, data_);

    return vector;
}

LIQUE_TENSOR_TPL_DECLARATION
template <class Function>
Vector<Precision>& Vector<Precision>::apply(Function func) noexcept
{
    detail::apply(data_, data_ + size_, func);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
template <class Function>
Vector<Precision>& Vector<Precision>::apply(Function func, const_pointer src) noexcept
{
    detail::apply(data_, data_ + size_, func, src);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
template <class Function>
Vector<Precision>& Vector<Precision>::apply(Function func, const Tensor& vector) noexcept
{
    return apply(func, vector.data_);
}

LIQUE_TENSOR_TPL_DECLARATION
typename Vector<Precision>::precision_type Vector<Precision>::dot(const Tensor& rhs) const
{
    precision_type result = 0.0;

    auto first = data_;
    auto last  = data_ + size_;

    auto src = rhs.data_;

    while(first != last)
    {
        result += (*first) * (*src);

        ++first;
        ++src;
    }

    return result;
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision> Vector<Precision>::add(const Tensor& rhs) const
{
    Tensor vector(size_);

    vector.add(*this, rhs);

    return vector;
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision>& Vector<Precision>::add(const Tensor& rhs) noexcept
{
    detail::assign(data_, data_ + size_, detail::add(), rhs.data_);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision>& Vector<Precision>::add(const Tensor& lhs, const Tensor& rhs) noexcept
{
    detail::assign(data_, data_ + size_, detail::add(), lhs.data_, rhs.data_);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision> Vector<Precision>::sub(const Tensor& rhs) const
{
    Tensor vector(size_);

    vector.sub(*this, rhs);

    return vector;
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision>& Vector<Precision>::sub(const Tensor& rhs) noexcept
{
    detail::assign(data_, data_ + size_, detail::sub(), rhs.data_);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision>& Vector<Precision>::sub(const Tensor& lhs, const Tensor& rhs) noexcept
{
    detail::assign(data_, data_ + size_, detail::sub(), lhs.data_, rhs.data_);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision> Vector<Precision>::mul(const Tensor& rhs) const
{
    Tensor vector(size_);

    vector.mul(*this, rhs);

    return vector;
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision>& Vector<Precision>::mul(const Tensor& rhs) noexcept
{
    detail::assign(data_, data_ + size_, detail::mul(), rhs.data_);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision>& Vector<Precision>::mul(const Tensor& lhs, const Tensor& rhs) noexcept
{
    detail::assign(data_, data_ + size_, detail::mul(), lhs.data_, rhs.data_);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision> Vector<Precision>::join(precision_type value) const
{
    Tensor tensor(size_);

    tensor.join(value, *this);

    return tensor;
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision>& Vector<Precision>::join(precision_type value) noexcept
{
    detail::assign(data_, data_ + size_, detail::mul(), value);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision>& Vector<Precision>::join(precision_type value, const Tensor& rhs) noexcept
{
    detail::assign(data_, data_ + size_, detail::mul(), value, rhs.data_);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
inline typename Vector<Precision>::pointer Vector<Precision>::data() noexcept
{
    return data_;
}

LIQUE_TENSOR_TPL_DECLARATION
inline typename Vector<Precision>::const_pointer Vector<Precision>::data() const noexcept
{
    return data_;
}

} // namespace lique

} // namespace trixy

#include "Detail/MacroUnscope.hpp"

#endif // LIQUE_VECTOR_HPP
