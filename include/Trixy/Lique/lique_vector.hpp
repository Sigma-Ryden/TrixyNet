#ifndef LIQUE_VECTOR_HPP
#define LIQUE_VECTOR_HPP

#include <cstddef> // size_t
#include <initializer_list> // initializer_list

namespace lique
{

template <typename Type>
class Vector
{
public:
    using size_type       = std::size_t;
    using reference       = Type&;
    using const_reference = const Type&;

protected:
    Type*     data_;
    size_type size_;

public:
    Vector() noexcept;
    ~Vector();
    explicit Vector(size_type n);
    Vector(const Vector&);
    Vector(Vector&&) noexcept;
    Vector(const std::initializer_list<Type>&);

    Vector& operator= (const Vector&);
    Vector& operator= (Vector&&) noexcept;

    Vector& copy(const Vector&) noexcept;
    Vector& copy(const std::initializer_list<Type>&) noexcept;

    size_type size() const noexcept;
    void resize(size_type new_size);

    reference operator() (size_type i) noexcept;
    const_reference operator() (size_type i) const noexcept;

    Vector& fill(Type (*generator)()) noexcept;
    Vector& fill(Type value) noexcept;

    Vector apply(Type (*function)(Type)) const;
    Vector& apply(Type (*function)(Type)) noexcept;
    Vector& apply(Type (*function)(Type), const Vector&) noexcept;

    Type dot(const Vector&) const;

    Vector& add(const Vector&) noexcept;
    Vector& sub(const Vector&) noexcept;

    Vector multiply(const Vector&) const;
    Vector& multiply(const Vector&) noexcept;
    Vector& multiply(const Vector&, const Vector&) noexcept;

    Vector join(Type value) const;
    Vector& join(Type value) noexcept;
    Vector& join(Type value, const Vector&) noexcept;

    Type* data() noexcept;
    const Type* data() const noexcept;

    Vector operator+ (const Vector&) const;
    Vector operator- (const Vector&) const;
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
inline Vector<Type>::Vector(std::size_t n)
    : data_(new Type[n]), size_(n)
{
}

template <typename Type>
Vector<Type>::Vector(const Vector& vector)
    : data_(new Type[vector.size_]), size_(vector.size_)
{
    for(size_type i = 0; i < size_; ++i)
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
    size_type i = 0;
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

    for(size_type i = 0; i < size_; ++i)
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
Vector<Type>& Vector<Type>::copy(const Vector& vector) noexcept
{
    if(this == &vector)
        return *this;

    for(size_type i = 0; i < size_; ++i)
        data_[i] = vector.data_[i];

    return *this;
}

template <typename Type>
Vector<Type>& Vector<Type>::copy(const std::initializer_list<Type>& data) noexcept
{
    auto it = data.begin();

    for(size_type i = 0; i < size_; ++i, ++it)
        data_[i] = *it;

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
    for(size_type i = 0; i < size_; ++i)
        data_[i] = generator();

    return *this;
}

template <typename Type>
Vector<Type>& Vector<Type>::fill(Type value) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] = value;

    return *this;
}

template <typename Type>
Vector<Type> Vector<Type>::apply(Type (*function)(Type)) const
{
    Vector new_vector(size_);

    for(size_type i = 0; i < size_; ++i)
        new_vector.data_[i] = function(data_[i]);

    return new_vector;
}

template <typename Type>
Vector<Type>& Vector<Type>::apply(Type (*function)(Type)) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] = function(data_[i]);

    return *this;
}

template <typename Type>
Vector<Type>& Vector<Type>::apply(Type (*function)(Type), const Vector& vector) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] = function(vector.data_[i]);

    return *this;
}

template <typename Type>
Type Vector<Type>::dot(const Vector& vector) const
{
    double result = 0.0;

    for(size_type i = 0; i < size_; ++i)
        result += data_[i] * vector.data_[i];

    return result;
}

template <typename Type>
Vector<Type>& Vector<Type>::add(const Vector& vector) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] += vector.data_[i];

    return *this;
}

template <typename Type>
Vector<Type>& Vector<Type>::sub(const Vector& vector) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] -= vector.data_[i];

    return *this;
}

template <typename Type>
Vector<Type> Vector<Type>::multiply(const Vector& vector) const
{
    Vector new_vector(size_);

    for(size_type i = 0; i < size_; ++i)
        new_vector.data_[i] = data_[i] * vector.data_[i];

    return new_vector;
}

template <typename Type>
Vector<Type>& Vector<Type>::multiply(const Vector& vector) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] *= vector.data_[i];

    return *this;
}

template <typename Type>
Vector<Type>& Vector<Type>::multiply(const Vector& lsh, const Vector& rsh) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] = lsh.data_[i] * rsh.data_[i];

    return *this;
}

template <typename Type>
Vector<Type> Vector<Type>::join(Type value) const
{
    Vector new_vector(size_);

    for(size_type i = 0; i < size_; ++i)
        new_vector.data_[i] = value * data_[i];

    return new_vector;
}

template <typename Type>
Vector<Type>& Vector<Type>::join(Type value) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] *= value;

    return *this;
}

template <typename Type>
Vector<Type>& Vector<Type>::join(Type value, const Vector& vector) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] = value * vector.data_[i];

    return *this;
}

template <typename Type>
inline Type* Vector<Type>::data() noexcept
{
    return data_;
}

template <typename Type>
inline const Type* Vector<Type>::data() const noexcept
{
    return data_;
}

template <typename Type>
Vector<Type> Vector<Type>::operator+ (const Vector& vector) const
{
    Vector new_vector(size_);

    for(size_type i = 0; i < size_; ++i)
        new_vector.data_[i] = data_[i] + vector.data_[i];

    return new_vector;
}

template <typename Type>
Vector<Type> Vector<Type>::operator- (const Vector& vector) const
{
    Vector new_vector(size_);

    for(size_type i = 0; i < size_; ++i)
        new_vector.data_[i] = data_[i] - vector.data_[i];

    return new_vector;
}

} // namespace lique

#endif // LIQUE_VECTOR_HPP
