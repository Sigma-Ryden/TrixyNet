#ifndef COLLECTION_HPP
#define COLLECTION_HPP

#include <cstddef>

template <typename T>
class Collection
{
private:
    T* data_;
    std::size_t size_;

public:
    Collection();
    Collection(std::size_t size_);
    Collection(const Collection<T>&);
    Collection(Collection<T>&&);

    Collection<T>& operator= (const Collection<T>&);
    Collection<T>& operator= (Collection<T>&&);

    std::size_t size() const;

    T& operator[] (std::size_t i);
    const T& operator[] (std::size_t i) const;
};

template <typename T>
Collection<T>::Collection() : data_(nullptr), size_(0)
{
}

template <typename T>
Collection<T>::Collection(std::size_t size) : data_(new T [size]), size_(size)
{
}

template <typename T>
Collection<T>::Collection(const Collection<T>& collection)
    : data_(new T[collection.size_]), size_(collection.size_)
{
    for(std::size_t i = 0; i < size_; ++i)
        data_[i] = collection.data_[i];
}

template <typename T>
Collection<T>::Collection(Collection<T>&& collection)
{
    size_ = collection.size_;
    data_ = collection.data_;

    collection.data_ = nullptr;
}

template <typename T>
Collection<T>& Collection<T>::operator= (const Collection<T>& collection)
{
    if(this == &collection)
        return *this;

    size_ = collection.size_;
    data_ = new T[size_];

    for(std::size_t i = 0; i < size_; ++i)
        data_[i] = collection.data_[i];

    return *this;
}

template <typename T>
Collection<T>& Collection<T>::operator= (Collection<T>&& collection)
{
    if(this == &collection)
        return *this;

    size_ = collection.size_;
    data_ = collection.data_;

    collection.data_ = nullptr;

    return *this;
}

template <typename T>
std::size_t Collection<T>::size() const
{
    return size_;
}

template <typename T>
T& Collection<T>::operator[] (std::size_t i)
{
    return data_[i];
}
template <typename T>
const T& Collection<T>::operator[] (std::size_t i) const
{
    return data_[i];
}

#endif // COLLECTION_HPP
