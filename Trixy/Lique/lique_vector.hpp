#ifndef LIQUE_VECTOR_HPP
#define LIQUE_VECTOR_HPP

#include <cstddef>
#include <initializer_list>

namespace lique
{

template <typename Type>
class Vector
{
protected:
    Type* data_;
    std::size_t size_;

public:
    Vector();
    ~Vector();
    Vector(std::size_t size);
    Vector(const Vector&);
    Vector(Vector&&);
    Vector(const std::initializer_list<Type>&); // deprecated

    Vector& operator= (const Vector&);
    Vector& operator= (Vector&&);

    std::size_t size() const;
    Vector& resize(std::size_t new_size);

    Type& operator() (std::size_t i);
    const Type& operator() (std::size_t i) const;

    Vector& fill(Type (*generator)());
    Vector& fill(Type value);

    Vector apply(Type (*function)(Type)) const;
    Vector& modify(Type (*function)(Type));

    Type dot(const Vector&) const;
    Vector multiply(const Vector&) const;
    Vector join(Type value) const;

    Vector operator+ (const Vector&) const;
    Vector operator- (const Vector&) const;
    Vector& operator+= (const Vector&);
    Vector& operator-= (const Vector&);
};

template <typename Type>
Vector<Type>::Vector() : data_(nullptr), size_(0)
{
}

template <typename Type>
Vector<Type>::~Vector()
{
    delete[] data_;
}

template <typename Type>
Vector<Type>::Vector(std::size_t size)
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
Vector<Type>::Vector(Vector&& vector)
    : data_(vector.data_), size_(vector.size_)
{
    vector.data_ = nullptr;
}

template <typename Type>
Vector<Type>::Vector(const std::initializer_list<Type>& list)
    : data_(new Type[list.size()]), size_(list.size())
{
    std::size_t i = 0;
    for(const auto& arg: list)
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
Vector<Type>& Vector<Type>::operator= (Vector&& vector)
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
std::size_t Vector<Type>::size() const
{
    return size_;
}

template <typename Type>
Vector<Type>& Vector<Type>::resize(std::size_t new_size)
{
    delete[] data_;

    size_ = new_size;
    data_ = new Type[size_];

    return *this;
}

template <typename Type>
Type& Vector<Type>::operator() (std::size_t i)
{
    return data_[i];
}

template <typename Type>
const Type& Vector<Type>::operator() (std::size_t i) const
{
    return data_[i];
}

template <typename Type>
Vector<Type>& Vector<Type>::fill(Type (*generator)())
{
    for(std::size_t i = 0; i < size_; ++i)
        data_[i] = generator();

    return *this;
}

template <typename Type>
Vector<Type>& Vector<Type>::fill(Type value)
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
Vector<Type>& Vector<Type>::modify(Type (*function)(Type))
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
Vector<Type>& Vector<Type>::operator+= (const Vector& vector)
{
    for(std::size_t i = 0; i < size_; ++i)
        data_[i] += vector.data_[i];

    return *this;
}

template <typename Type>
Vector<Type>& Vector<Type>::operator-= (const Vector& vector)
{
     for(std::size_t i = 0; i < size_; ++i)
        data_[i] -= vector.data_[i];

    return *this;
}

} // namespace lique

#endif // LIQUE_VECTOR_HPP
