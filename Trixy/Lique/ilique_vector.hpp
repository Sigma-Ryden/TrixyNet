#ifndef ILIQUE_VECTOR_HPP
#define ILIQUE_VECTOR_HPP

#include <cstddef>

namespace ilique
{

template <template <typename T> class Tensor, typename Type>
class IVector
{
protected:
    Type* data_;
    std::size_t size_;

protected:
    virtual ~IVector();

public:
    IVector();
    IVector(std::size_t size);
    IVector(const IVector&);
    IVector(IVector&&);

    IVector& operator= (const IVector&);
    IVector& operator= (IVector&&);

    Type& operator() (std::size_t i);
    const Type& operator() (std::size_t i) const;

    std::size_t size() const;
    virtual Tensor<Type>& resize(std::size_t new_size) = 0;
    virtual Type dot(const Tensor<Type>&) const = 0;
};

template <template <typename T> class Tensor, typename Type>
IVector<Tensor, Type>::IVector() : data_(nullptr), size_(0)
{
}

template <template <typename T> class Tensor, typename Type>
IVector<Tensor, Type>::~IVector()
{
    delete[] data_;
}

template <template <typename T> class Tensor, typename Type>
IVector<Tensor, Type>::IVector(std::size_t size)
    : data_(new Type[size]), size_(size)
{
}

template <template <typename T> class Tensor, typename Type>
IVector<Tensor, Type>::IVector(const IVector& vector)
    : data_(new Type[vector.size_]), size_(vector.size_)
{
    for(std::size_t i = 0; i < size_; ++i)
        data_[i] = vector.data_[i];
}

template <template <typename T> class Tensor, typename Type>
IVector<Tensor, Type>::IVector(IVector&& vector)
    : data_(vector.data_), size_(vector.size_)
{
    vector.data_ = nullptr;
}

template <template <typename T> class Tensor, typename Type>
IVector<Tensor, Type>& IVector<Tensor, Type>::operator= (const IVector& vector)
{
    if(this == &vector)
        return *this;

    delete[] data_;

    size_ = vector.size_;
    data_ = new Type[size_];

    for(std::size_t i = 0; i < size_; ++i)
        data_[i] = vector.data_[i];

    return this;
}

template <template <typename T> class Tensor, typename Type>
IVector<Tensor, Type>& IVector<Tensor, Type>::operator= (IVector&& vector)
{
    if(this == &vector)
        return *this;

    delete[] data_;

    size_ = vector.size_;
    data_ = vector.data_;

    vector.data_ = nullptr;

    return *this;
}

template <template <typename T> class Tensor, typename Type>
Type& IVector<Tensor, Type>::operator() (std::size_t i)
{
    return data_[i];
}

template <template <typename T> class Tensor, typename Type>
const Type& IVector<Tensor, Type>::operator() (std::size_t i) const
{
    return data_[i];
}

template <template <typename T> class Tensor, typename Type>
std::size_t IVector<Tensor, Type>::size() const
{
    return size_;
}

} // namespace ilique

#endif // ILIQUE_VECTOR_HPP
