#ifndef LIQUE_VECTOR_HPP
#define LIQUE_VECTOR_HPP

#include <cstddef> // size_t
#include <initializer_list> // initializer_list

#include "LiqueBaseTensor.hpp"

#include "Detail/FunctionDetail.hpp"
#include "Detail/LiqueMeta.hpp"

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

    using Function          = Precision (*)(Precision);

protected:
    pointer   data_;
    size_type size_;

public:
    Tensor() noexcept;
    ~Tensor();

    explicit Tensor(size_type size);
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

    template <class Generator,
        meta::enable_if_t<meta::is_callable<Generator, Precision>::value, int> = 0>
    Tensor& fill(Generator gen) noexcept;

    Tensor& fill(precision_type value) noexcept;

    Tensor apply(Function func) const;
    Tensor& apply(Function func) noexcept;
    Tensor& apply(Function func, const Tensor&) noexcept;

    precision_type dot(const Tensor&) const;

    Tensor add(const Tensor&) const;
    Tensor& add(const Tensor&) noexcept;
    Tensor& add(const Tensor&, const Tensor&) noexcept;

    Tensor sub(const Tensor&) const;
    Tensor& sub(const Tensor&) noexcept;
    Tensor& sub(const Tensor&, const Tensor&) noexcept;

    Tensor multiply(const Tensor&) const;
    Tensor& multiply(const Tensor&) noexcept;
    Tensor& multiply(const Tensor&, const Tensor&) noexcept;

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
Vector<Precision>::Tensor(size_type size, precision_type value)
    : data_(new precision_type [size]), size_(size)
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] = value;
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
template <class Generator,
          meta::enable_if_t<meta::is_callable<Generator, Precision>::value, int>>
Vector<Precision>& Vector<Precision>::fill(Generator gen) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] = gen();

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision>& Vector<Precision>::fill(precision_type value) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] = value;

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision> Vector<Precision>::apply(Function func) const
{
    Tensor new_vector(size_);

    for(size_type i = 0; i < size_; ++i)
        new_vector.data_[i] = function(data_[i]);

    return new_vector;
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision>& Vector<Precision>::apply(Function func) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] = func(data_[i]);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision>& Vector<Precision>::apply(
    Function func, const Tensor& vector) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] = func(vector.data_[i]);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
typename Vector<Precision>::precision_type Vector<Precision>::dot(const Tensor& vector) const
{
    double result = 0.0;

    for(size_type i = 0; i < size_; ++i)
        result += data_[i] * vector.data_[i];

    return result;
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision> Vector<Precision>::add(const Tensor& vector) const
{
    Tensor new_vector(size_);

    for(size_type i = 0; i < size_; ++i)
        new_vector.data_[i] = data_[i] + vector.data_[i];

    return new_vector;
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision>& Vector<Precision>::add(const Tensor& vector) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] += vector.data_[i];

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision>& Vector<Precision>::add(const Tensor& lhs, const Tensor& rhs) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] = lhs.data_[i] + rhs.data_[i];

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision> Vector<Precision>::sub(const Tensor& vector) const
{
    Tensor new_vector(size_);

    for(size_type i = 0; i < size_; ++i)
        new_vector.data_[i] = data_[i] - vector.data_[i];

    return new_vector;
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision>& Vector<Precision>::sub(const Tensor& vector) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] -= vector.data_[i];

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision>& Vector<Precision>::sub(const Tensor& lhs, const Tensor& rhs) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] = lhs.data_[i] - rhs.data_[i];

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision> Vector<Precision>::multiply(const Tensor& vector) const
{
    Tensor new_vector(size_);

    for(size_type i = 0; i < size_; ++i)
        new_vector.data_[i] = data_[i] * vector.data_[i];

    return new_vector;
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision>& Vector<Precision>::multiply(const Tensor& vector) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] *= vector.data_[i];

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision>& Vector<Precision>::multiply(const Tensor& lsh, const Tensor& rsh) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] = lsh.data_[i] * rsh.data_[i];

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision> Vector<Precision>::join(precision_type value) const
{
    Tensor new_vector(size_);

    for(size_type i = 0; i < size_; ++i)
        new_vector.data_[i] = value * data_[i];

    return new_vector;
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision>& Vector<Precision>::join(precision_type value) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] *= value;

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Vector<Precision>& Vector<Precision>::join(precision_type value, const Tensor& vector) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] = value * vector.data_[i];

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
