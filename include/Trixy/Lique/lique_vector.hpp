#ifndef LIQUE_VECTOR_HPP
#define LIQUE_VECTOR_HPP

#include <cstddef> // size_t
#include <initializer_list> // initializer_list

namespace lique
{

template <typename Type>
class Vector
{
protected:
    Type* data_;
    std::size_t size_;

public:
    Vector() noexcept;
    ~Vector();
    explicit Vector(std::size_t size);
    Vector(const Vector&);
    Vector(Vector&&) noexcept;
    Vector(const std::initializer_list<Type>&);

    Vector& operator= (const Vector&);
    Vector& operator= (Vector&&) noexcept;

    std::size_t size() const noexcept;
    void resize(std::size_t new_size);

    Type& operator() (std::size_t i) noexcept;
    const Type& operator() (std::size_t i) const noexcept;

    Vector& fill(Type (*generator)()) noexcept;
    Vector& fill(Type value) noexcept;

    Vector apply(Type (*function)(Type)) const;
    Vector& modify(Type (*function)(Type)) noexcept;

    Type dot(const Vector&) const;
    Vector multiply(const Vector&) const;
    Vector join(Type value) const;

    Vector operator+ (const Vector&) const;
    Vector operator- (const Vector&) const;
    Vector& operator+= (const Vector&) noexcept;
    Vector& operator-= (const Vector&) noexcept;
};

template <typename Type>
inline Vector<Type>::Vector() noexcept : data_(nullptr), size_(0)
{
}

template <typename Type>
inline Vector<Type>::~Vector()
{
    delete[] data_;
}

template <typename Type>
inline Vector<Type>::Vector(std::size_t size)
    : data_(new Type[size]), size_(size)
{
}

template <typename Type>
Vector<Type>::Vector(const Vector& vector)
    : data_(new Type[vector.size_]), size_(vector.size_)
{
    for(std::size_t i = 0; i < size_; ++i)
        data_[i] = vector.data_[i];
}

template <typename Type>
inline Vector<Type>::Vector(Vector&& vector) noexcept
    : data_(vector.data_), size_(vector.size_)
{
    vector.data_ = nullptr;
}

template <typename Type>
Vector<Type>::Vector(const std::initializer_list<Type>& init)
    : data_(new Type[init.size()]), size_(init.size())
{
    std::size_t i = 0;
    for(const auto& arg: init)
    {
        data_[i] = arg;
        ++i;
    }
}

template <typename Type>
Vector<Type>& Vector<Type>::operator= (const Vector& vector)
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

template <typename Type>
Vector<Type>& Vector<Type>::operator= (Vector&& vector) noexcept
{
    if(this == &vector)
        return *this;

    delete[] data_;

    size_ = vector.size_;
    data_ = vector.data_;

    vector.data_ = nullptr;

    return *this;
}

template <typename Type>
inline std::size_t Vector<Type>::size() const noexcept
{
    return size_;
}

template <typename Type>
void Vector<Type>::resize(std::size_t new_size)
{
    delete[] data_;

    size_ = new_size;
    data_ = new Type[size_];
}

template <typename Type>
inline Type& Vector<Type>::operator() (std::size_t i) noexcept
{
    return data_[i];
}

template <typename Type>
inline const Type& Vector<Type>::operator() (std::size_t i) const noexcept
{
    return data_[i];
}

template <typename Type>
Vector<Type>& Vector<Type>::fill(Type (*generator)()) noexcept
{
    for(std::size_t i = 0; i < size_; ++i)
        data_[i] = generator();

    return *this;
}

template <typename Type>
Vector<Type>& Vector<Type>::fill(Type value) noexcept
{
    for(std::size_t i = 0; i < size_; ++i)
        data_[i] = value;

    return *this;
}

template <typename Type>
Vector<Type> Vector<Type>::apply(Type (*function)(Type)) const
{
    Vector new_vector(size_);

    for(std::size_t i = 0; i < size_; ++i)
        new_vector.data_[i] = function(data_[i]);

    return new_vector;
}

template <typename Type>
Vector<Type>& Vector<Type>::modify(Type (*function)(Type)) noexcept
{
    for(std::size_t i = 0; i < size_; ++i)
        data_[i] = function(data_[i]);

    return *this;
}

template <typename Type>
Type Vector<Type>::dot(const Vector& vector) const
{
    double result = 0.0;

    for(std::size_t i = 0; i < size_; ++i)
        result += data_[i] * vector.data_[i];

    return result;
}

template <typename Type>
Vector<Type> Vector<Type>::multiply(const Vector& vector) const
{
    Vector new_vector(size_);

    for(std::size_t i = 0; i < size_; ++i)
        new_vector.data_[i] = data_[i] * vector.data_[i];

    return new_vector;
}

template <typename Type>
Vector<Type> Vector<Type>::join(Type value) const
{
    Vector new_vector(size_);

    for(std::size_t i = 0; i < size_; ++i)
        new_vector.data_[i] = data_[i] * value;

    return new_vector;
}

template <typename Type>
Vector<Type> Vector<Type>::operator+ (const Vector& vector) const
{
    Vector new_vector(size_);

    for(std::size_t i = 0; i < size_; ++i)
        new_vector.data_[i] = data_[i] + vector.data_[i];

    return new_vector;
}

template <typename Type>
Vector<Type> Vector<Type>::operator- (const Vector& vector) const
{
    Vector new_vector(size_);

    for(std::size_t i = 0; i < size_; ++i)
        new_vector.data_[i] = data_[i] - vector.data_[i];

    return new_vector;
}

template <typename Type>
Vector<Type>& Vector<Type>::operator+= (const Vector& vector) noexcept
{
    for(std::size_t i = 0; i < size_; ++i)
        data_[i] += vector.data_[i];

    return *this;
}

template <typename Type>
Vector<Type>& Vector<Type>::operator-= (const Vector& vector) noexcept
{
     for(std::size_t i = 0; i < size_; ++i)
        data_[i] -= vector.data_[i];

    return *this;
}

} // namespace lique

#endif // LIQUE_VECTOR_HPP
