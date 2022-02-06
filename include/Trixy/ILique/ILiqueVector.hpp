#ifndef ILIQUE_VECTOR_HPP
#define ILIQUE_VECTOR_HPP

#include <cstddef> // size_t

#include "Trixy/Detail/TrixyMeta.hpp"

#include "Detail/MacroScope.hpp"

namespace ilique
{

template <template <typename P> class Tensor1D, typename Precision, typename enable = void>
class Vector;

} // namespace ilique

namespace ilique
{

template <template <typename P> class Tensor1D, typename Precision>
class Vector<Tensor1D, Precision,
             meta::enable_for_arithmetic_t<Precision>>
{
public:
    using TensorType      = Tensor1D<Precision>;
    using size_type       = std::size_t;
    using reference       = Precision&;
    using const_reference = const Precision&;

protected:
    Precision* data_;
    size_type  size_;

protected:
    virtual ~Vector();

public:
    Vector() noexcept;
    explicit Vector(size_type size);
    explicit Vector(size_type size, Precision fill_value);
    explicit Vector(size_type size, const Precision* ptr);

    Vector(const Vector&);
    Vector(Vector&&) noexcept;

    Vector& operator= (const Vector&);
    Vector& operator= (Vector&&) noexcept;

    reference operator() (size_type i) noexcept;
    const_reference operator() (size_type i) const noexcept;

    size_type size() const noexcept;

    virtual void resize(size_type new_size) = 0;
    virtual void resize(size_type new_size, Precision fill_value) = 0;

    virtual Precision dot(const TensorType&) const = 0;
};

ILIQUE_VECTOR_TPL_DECLARATION
inline ILIQUE_VECTOR_TPL::Vector() noexcept : data_(nullptr), size_(0)
{
}

ILIQUE_VECTOR_TPL_DECLARATION
inline ILIQUE_VECTOR_TPL::~Vector()
{
    delete[] data_;
}

ILIQUE_VECTOR_TPL_DECLARATION
inline ILIQUE_VECTOR_TPL::Vector(std::size_t size)
    : data_(new Precision[size]), size_(size)
{
}

ILIQUE_VECTOR_TPL_DECLARATION
ILIQUE_VECTOR_TPL::Vector(std::size_t size, Precision fill_value)
    : data_(new Precision[size]), size_(size)
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] = fill_value;
}

ILIQUE_VECTOR_TPL_DECLARATION
ILIQUE_VECTOR_TPL::Vector(std::size_t size, const Precision* ptr)
    : data_(new Precision[size]), size_(size)
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] = ptr[i];
}

ILIQUE_VECTOR_TPL_DECLARATION
ILIQUE_VECTOR_TPL::Vector(const Vector& vector)
    : data_(new Precision[vector.size_]), size_(vector.size_)
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] = vector.data_[i];
}

ILIQUE_VECTOR_TPL_DECLARATION
inline ILIQUE_VECTOR_TPL::Vector(Vector&& vector) noexcept
    : data_(vector.data_), size_(vector.size_)
{
    vector.data_ = nullptr;
}

ILIQUE_VECTOR_TPL_DECLARATION
ILIQUE_VECTOR_TPL& ILIQUE_VECTOR_TPL::operator= (const Vector& vector)
{
    if(this != &vector)
    {
        delete[] data_;

        size_ = vector.size_;
        data_ = new Precision[size_];

        for(size_type i = 0; i < size_; ++i)
            data_[i] = vector.data_[i];
    }

    return *this;
}

ILIQUE_VECTOR_TPL_DECLARATION
ILIQUE_VECTOR_TPL& ILIQUE_VECTOR_TPL::operator= (Vector&& vector) noexcept
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

ILIQUE_VECTOR_TPL_DECLARATION
inline Precision& ILIQUE_VECTOR_TPL::operator() (std::size_t i) noexcept
{
    return data_[i];
}

ILIQUE_VECTOR_TPL_DECLARATION
inline const Precision& ILIQUE_VECTOR_TPL::operator() (std::size_t i) const noexcept
{
    return data_[i];
}

ILIQUE_VECTOR_TPL_DECLARATION
inline std::size_t ILIQUE_VECTOR_TPL::size() const noexcept
{
    return size_;
}

} // namespace ilique

#include "Detail/MacroUnscope.hpp"

#endif // ILIQUE_VECTOR_HPP
