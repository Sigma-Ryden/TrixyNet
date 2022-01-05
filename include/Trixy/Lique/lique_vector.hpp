#ifndef LIQUE_VECTOR_HPP
#define LIQUE_VECTOR_HPP

#include <cstddef> // size_t
#include <initializer_list> // initializer_list
#include <type_traits> // enable_if, is_arithmetic

#include "Trixy/Lique/lique_tensor_base.hpp"
#include "Trixy/Lique/lique_tensor_id.hpp"

#include "Trixy/Lique/Detail/macro_scope.hpp"

namespace lique
{

LIQUE_TENSOR_TPL_DECLARATION
class LIQUE_TENSOR_TPL(detail::TensorType::_1D)
{
public:
    using size_type = std::size_t;

protected:
    Precision* data_;
    size_type  size_;

public:
    Tensor() noexcept;
    ~Tensor();

    explicit Tensor(size_type size);
    explicit Tensor(size_type size, const Precision* ptr);

    Tensor(const Tensor&);
    Tensor(Tensor&&) noexcept;
    Tensor(const std::initializer_list<Precision>&);

    Tensor& operator= (const Tensor&);
    Tensor& operator= (Tensor&&) noexcept;

    Tensor& copy(const Tensor&) noexcept;
    Tensor& copy(const std::initializer_list<Precision>&) noexcept;

    size_type size() const noexcept;

    void resize(size_type new_size);
    void resize(size_type new_size, Precision fill_value);

    Precision& operator() (size_type i) noexcept;
    const Precision& operator() (size_type i) const noexcept;

    Tensor& fill(Precision (*generator)()) noexcept;
    Tensor& fill(Precision value) noexcept;

    Tensor apply(Precision (*function)(Precision)) const;
    Tensor& apply(Precision (*function)(Precision)) noexcept;
    Tensor& apply(Precision (*function)(Precision), const Tensor&) noexcept;

    Precision dot(const Tensor&) const;

    Tensor& add(const Tensor&) noexcept;
    Tensor& sub(const Tensor&) noexcept;

    Tensor multiply(const Tensor&) const;
    Tensor& multiply(const Tensor&) noexcept;
    Tensor& multiply(const Tensor&, const Tensor&) noexcept;

    Tensor join(Precision value) const;
    Tensor& join(Precision value) noexcept;
    Tensor& join(Precision value, const Tensor&) noexcept;

    Precision* data() noexcept;
    const Precision* data() const noexcept;

    Tensor operator+ (const Tensor&) const;
    Tensor operator- (const Tensor&) const;
};

LIQUE_TENSOR_TPL_DECLARATION
inline LIQUE_TENSOR_TPL(detail::TensorType::_1D)::Tensor() noexcept
    : data_(nullptr), size_(0)
{
}

LIQUE_TENSOR_TPL_DECLARATION
inline LIQUE_TENSOR_TPL(detail::TensorType::_1D)::~Tensor()
{
    delete[] data_;
}

LIQUE_TENSOR_TPL_DECLARATION
inline LIQUE_TENSOR_TPL(detail::TensorType::_1D)::Tensor(std::size_t size)
    : data_(new Precision[size]), size_(size)
{
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_1D)::Tensor(std::size_t size, const Precision* ptr)
    : data_(new Precision[size]), size_(size)
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] = ptr[i];
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_1D)::Tensor(const Tensor& vector)
    : data_(new Precision[vector.size_]), size_(vector.size_)
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] = vector.data_[i];
}

LIQUE_TENSOR_TPL_DECLARATION
inline LIQUE_TENSOR_TPL(detail::TensorType::_1D)::Tensor(Tensor&& vector) noexcept
    : data_(vector.data_), size_(vector.size_)
{
    vector.data_ = nullptr;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_1D)::Tensor(const std::initializer_list<Precision>& init)
    : data_(new Precision[init.size()]), size_(init.size())
{
    size_type i = 0;
    for(const auto& arg: init)
    {
        data_[i] = arg;
        ++i;
    }
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_1D)& LIQUE_TENSOR_TPL(detail::TensorType::_1D)::operator= (
    const Tensor& vector)
{
    if(this == &vector)
        return *this;

    delete[] data_;

    size_ = vector.size_;
    data_ = new Precision[size_];

    for(size_type i = 0; i < size_; ++i)
        data_[i] = vector.data_[i];

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_1D)& LIQUE_TENSOR_TPL(detail::TensorType::_1D)::operator= (
    Tensor&& vector) noexcept
{
    if(this == &vector)
        return *this;

    delete[] data_;

    size_ = vector.size_;
    data_ = vector.data_;

    vector.data_ = nullptr;

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_1D)& LIQUE_TENSOR_TPL(detail::TensorType::_1D)::copy(
    const Tensor& vector) noexcept
{
    if(this == &vector)
        return *this;

    for(size_type i = 0; i < size_; ++i)
        data_[i] = vector.data_[i];

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_1D)& LIQUE_TENSOR_TPL(detail::TensorType::_1D)::copy(
    const std::initializer_list<Precision>& data) noexcept
{
    auto it = data.begin();

    for(size_type i = 0; i < size_; ++i, ++it)
        data_[i] = *it;

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
inline std::size_t LIQUE_TENSOR_TPL(detail::TensorType::_1D)::size() const noexcept
{
    return size_;
}

LIQUE_TENSOR_TPL_DECLARATION
void LIQUE_TENSOR_TPL(detail::TensorType::_1D)::resize(
    std::size_t new_size)
{
    delete[] data_;

    size_ = new_size;
    data_ = new Precision[size_];
}

LIQUE_TENSOR_TPL_DECLARATION
void LIQUE_TENSOR_TPL(detail::TensorType::_1D)::resize(
    std::size_t new_size,
    Precision fill_value)
{
    resize(new_size);
    fill(fill_value);
}

LIQUE_TENSOR_TPL_DECLARATION
inline Precision& LIQUE_TENSOR_TPL(detail::TensorType::_1D)::operator() (
    std::size_t i) noexcept
{
    return data_[i];
}

LIQUE_TENSOR_TPL_DECLARATION
inline const Precision& LIQUE_TENSOR_TPL(detail::TensorType::_1D)::operator() (
    std::size_t i) const noexcept
{
    return data_[i];
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_1D)& LIQUE_TENSOR_TPL(detail::TensorType::_1D)::fill(
    Precision (*generator)()) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] = generator();

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_1D)& LIQUE_TENSOR_TPL(detail::TensorType::_1D)::fill(
    Precision value) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] = value;

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_1D) LIQUE_TENSOR_TPL(detail::TensorType::_1D)::apply(
    Precision (*function)(Precision)) const
{
    Tensor new_vector(size_);

    for(size_type i = 0; i < size_; ++i)
        new_vector.data_[i] = function(data_[i]);

    return new_vector;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_1D)& LIQUE_TENSOR_TPL(detail::TensorType::_1D)::apply(
    Precision (*function)(Precision)) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] = function(data_[i]);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_1D)& LIQUE_TENSOR_TPL(detail::TensorType::_1D)::apply(
    Precision (*function)(Precision),
    const Tensor& vector) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] = function(vector.data_[i]);

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
Precision LIQUE_TENSOR_TPL(detail::TensorType::_1D)::dot(
    const Tensor& vector) const
{
    double result = 0.0;

    for(size_type i = 0; i < size_; ++i)
        result += data_[i] * vector.data_[i];

    return result;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_1D)& LIQUE_TENSOR_TPL(detail::TensorType::_1D)::add(
    const Tensor& vector) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] += vector.data_[i];

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_1D)& LIQUE_TENSOR_TPL(detail::TensorType::_1D)::sub(
    const Tensor& vector) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] -= vector.data_[i];

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_1D) LIQUE_TENSOR_TPL(detail::TensorType::_1D)::multiply(
    const Tensor& vector) const
{
    Tensor new_vector(size_);

    for(size_type i = 0; i < size_; ++i)
        new_vector.data_[i] = data_[i] * vector.data_[i];

    return new_vector;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_1D)& LIQUE_TENSOR_TPL(detail::TensorType::_1D)::multiply(
    const Tensor& vector) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] *= vector.data_[i];

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_1D)& LIQUE_TENSOR_TPL(detail::TensorType::_1D)::multiply(
    const Tensor& lsh,
    const Tensor& rsh) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] = lsh.data_[i] * rsh.data_[i];

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_1D) LIQUE_TENSOR_TPL(detail::TensorType::_1D)::join(
    Precision value) const
{
    Tensor new_vector(size_);

    for(size_type i = 0; i < size_; ++i)
        new_vector.data_[i] = value * data_[i];

    return new_vector;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_1D)& LIQUE_TENSOR_TPL(detail::TensorType::_1D)::join(
    Precision value) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] *= value;

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_1D)& LIQUE_TENSOR_TPL(detail::TensorType::_1D)::join(
    Precision value,
    const Tensor& vector) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] = value * vector.data_[i];

    return *this;
}

LIQUE_TENSOR_TPL_DECLARATION
inline Precision* LIQUE_TENSOR_TPL(detail::TensorType::_1D)::data() noexcept
{
    return data_;
}

LIQUE_TENSOR_TPL_DECLARATION
inline const Precision* LIQUE_TENSOR_TPL(detail::TensorType::_1D)::data() const noexcept
{
    return data_;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_1D) LIQUE_TENSOR_TPL(detail::TensorType::_1D)::operator+ (
    const Tensor& vector) const
{
    Tensor new_vector(size_);

    for(size_type i = 0; i < size_; ++i)
        new_vector.data_[i] = data_[i] + vector.data_[i];

    return new_vector;
}

LIQUE_TENSOR_TPL_DECLARATION
LIQUE_TENSOR_TPL(detail::TensorType::_1D) LIQUE_TENSOR_TPL(detail::TensorType::_1D)::operator- (
    const Tensor& vector) const
{
    Tensor new_vector(size_);

    for(size_type i = 0; i < size_; ++i)
        new_vector.data_[i] = data_[i] - vector.data_[i];

    return new_vector;
}

LIQUE_TENSOR_TPL_DECLARATION
using Vector = LIQUE_TENSOR_TPL(detail::TensorType::_1D);

} // namespace lique

#include "Trixy/Lique/Detail/macro_unscope.hpp"

#endif // LIQUE_VECTOR_HPP
