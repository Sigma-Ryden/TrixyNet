#ifndef ILIQUE_VECTOR_HPP
#define ILIQUE_VECTOR_HPP

#include <cstddef> // size_t

namespace ilique
{

template <template <typename T> class Tensor, typename Type>
class Vector
{
protected:
    Type* data_;
    std::size_t size_;

protected:
    virtual ~Vector();

public:
    Vector() noexcept;
    explicit Vector(std::size_t size);
    Vector(const Vector&);
    Vector(Vector&&) noexcept;

    Vector& operator= (const Vector&);
    Vector& operator= (Vector&&) noexcept;

    Type& operator() (std::size_t i) noexcept;
    const Type& operator() (std::size_t i) const noexcept;

    std::size_t size() const noexcept;
    virtual void resize(std::size_t new_size) = 0;
    virtual Type dot(const Tensor<Type>&) const = 0;
};

template <template <typename T> class Tensor, typename Type>
inline Vector<Tensor, Type>::Vector() noexcept : data_(nullptr), size_(0)
{
}

template <template <typename T> class Tensor, typename Type>
inline Vector<Tensor, Type>::~Vector()
{
    delete[] data_;
}

template <template <typename T> class Tensor, typename Type>
inline Vector<Tensor, Type>::Vector(std::size_t size)
    : data_(new Type[size]), size_(size)
{
}

template <template <typename T> class Tensor, typename Type>
Vector<Tensor, Type>::Vector(const Vector& vector)
    : data_(new Type[vector.size_]), size_(vector.size_)
{
    for(std::size_t i = 0; i < size_; ++i)
        data_[i] = vector.data_[i];
}

template <template <typename T> class Tensor, typename Type>
inline Vector<Tensor, Type>::Vector(Vector&& vector) noexcept
    : data_(vector.data_), size_(vector.size_)
{
    vector.data_ = nullptr;
}

template <template <typename T> class Tensor, typename Type>
Vector<Tensor, Type>& Vector<Tensor, Type>::operator= (const Vector& vector)
{
    if(this == &vector)
        return *this;

    delete[] data_;

    size_ = vector.size_;
    data_ = new Type[size_];

    for(std::size_t i = 0; i < size_; ++i)
        data_[i] = vector.data_[i];

    return *this;
}

template <template <typename T> class Tensor, typename Type>
Vector<Tensor, Type>& Vector<Tensor, Type>::operator= (Vector&& vector) noexcept
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
inline Type& Vector<Tensor, Type>::operator() (std::size_t i) noexcept
{
    return data_[i];
}

template <template <typename T> class Tensor, typename Type>
inline const Type& Vector<Tensor, Type>::operator() (std::size_t i) const noexcept
{
    return data_[i];
}

template <template <typename T> class Tensor, typename Type>
inline std::size_t Vector<Tensor, Type>::size() const noexcept
{
    return size_;
}

} // namespace ilique

#endif // ILIQUE_VECTOR_HPP
