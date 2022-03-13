#ifndef ILIQUE_VECTOR_HPP
#define ILIQUE_VECTOR_HPP

#include <cstddef> // size_t

#include "Trixy/Lique/LiqueBaseTensor.hpp"

#include "Detail/MacroScope.hpp"

namespace trixy
{

namespace ilique
{

template <template <typename...> class Derived, typename Precision, typename... Args>
class ILVector : public lique::TensorType::vector
{
public:
    using Tensor            = Derived<Precision, Args...>;

public:
    using size_type         = std::size_t;
    using precision_type    = Precision;

    using pointer           = Precision*;
    using const_pointer     = const Precision*;

    using reference         = Precision&;
    using const_reference   = const Precision&;

protected:
    pointer data_;
    size_type size_;

protected:
    virtual ~ILVector();

private:
    Tensor& self() noexcept
    { return *static_cast<Tensor*>(this); }

    const Tensor& self() const noexcept
    { return *static_cast<const Tensor*>(this); }

public:
    ILVector() noexcept;
    explicit ILVector(size_type size);
    explicit ILVector(size_type size, precision_type value);
    explicit ILVector(size_type size, const_pointer ptr);

    ILVector(const ILVector&);
    ILVector(ILVector&&) noexcept;

    ILVector& operator= (const ILVector&);
    ILVector& operator= (ILVector&&) noexcept;

    reference operator() (size_type i) noexcept { return data_[i]; }
    const_reference operator() (size_type i) const noexcept { return data_[i]; }

    size_type size() const noexcept { return size_; }

    void resize(size_type new_size);
    void resize(size_type new_size, precision_type value);

    precision_type dot(const Tensor& tensor) const { return self().dot(tensor); }
};

ILIQUE_TENSOR_TPL_DECLARATION
inline ILIQUE_VECTOR_TPL::ILVector() noexcept : data_(nullptr), size_(0)
{
}

ILIQUE_TENSOR_TPL_DECLARATION
inline ILIQUE_VECTOR_TPL::~ILVector()
{
    delete[] data_;
}

ILIQUE_TENSOR_TPL_DECLARATION
inline ILIQUE_VECTOR_TPL::ILVector(size_type size)
    : data_(new precision_type [size]), size_(size)
{
}

ILIQUE_TENSOR_TPL_DECLARATION
ILIQUE_VECTOR_TPL::ILVector(size_type size, precision_type fill_value)
    : data_(new precision_type [size]), size_(size)
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] = fill_value;
}

ILIQUE_TENSOR_TPL_DECLARATION
ILIQUE_VECTOR_TPL::ILVector(size_type size, const precision_type* ptr)
    : data_(new precision_type [size]), size_(size)
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] = ptr[i];
}

ILIQUE_TENSOR_TPL_DECLARATION
ILIQUE_VECTOR_TPL::ILVector(const ILVector& vector)
    : data_(new precision_type [vector.size_]), size_(vector.size_)
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] = vector.data_[i];
}

ILIQUE_TENSOR_TPL_DECLARATION
inline ILIQUE_VECTOR_TPL::ILVector(ILVector&& vector) noexcept
    : data_(vector.data_), size_(vector.size_)
{
    vector.data_ = nullptr;
}

ILIQUE_TENSOR_TPL_DECLARATION
ILIQUE_VECTOR_TPL& ILIQUE_VECTOR_TPL::operator= (const ILVector& vector)
{
    if(this != &vector)
    {
        delete[] data_;

        size_ = vector.size_;
        data_ = new precision_type [size_];

        for(size_type i = 0; i < size_; ++i)
            data_[i] = vector.data_[i];
    }

    return *this;
}

ILIQUE_TENSOR_TPL_DECLARATION
ILIQUE_VECTOR_TPL& ILIQUE_VECTOR_TPL::operator= (ILVector&& vector) noexcept
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

ILIQUE_TENSOR_TPL_DECLARATION
void ILIQUE_VECTOR_TPL::resize(size_type size)
{
    delete[] data_;

    size_ = size;
    data_ = new precision_type [size_];
}

ILIQUE_TENSOR_TPL_DECLARATION
void ILIQUE_VECTOR_TPL::resize(size_type size, precision_type value)
{
    resize(size);
    fill(value);
}

} // namespace ilique

} // namespace trixy

#include "Detail/MacroUnscope.hpp"

#endif // ILIQUE_VECTOR_HPP
