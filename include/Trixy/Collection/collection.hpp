#ifndef COLLECTION_HPP
#define COLLECTION_HPP

#include <cstddef> // size_t
#include <initializer_list> // initializer_list

template <typename T>
class Collection
{
public:
    using reference = T&;
    using const_reference = const T&;
    using size_type = std::size_t;

    class iterator;

private:
    T* data_;
    std::size_t size_;

public:
    Collection() noexcept;
    explicit Collection(std::size_t size);
    Collection(const Collection<T>&);
    Collection(Collection<T>&&) noexcept;
    Collection(const std::initializer_list<T>&);

    Collection<T>& operator= (const Collection<T>&);
    Collection<T>& operator= (Collection<T>&&) noexcept;

    size_type size() const noexcept;
    void resize(std::size_t new_size);

    iterator begin() const noexcept;
    iterator end() const noexcept;

    reference operator[] (std::size_t i) noexcept;
    const_reference operator[] (std::size_t i) const noexcept;
};

template <typename T>
class Collection<T>::iterator
{
private:
    T* ptr_;

public:
    explicit iterator(T* ptr) noexcept : ptr_(ptr) {}

    T& operator* () noexcept { return *ptr_; }
    T* operator-> () noexcept { return ptr_; }

    bool operator!= (const iterator& it) const noexcept { return ptr_ != it.ptr_; }

    iterator operator++ () noexcept { ++ptr_; return *this; }
    iterator operator-- () noexcept { --ptr_; return *this; }
};

template <typename T>
inline Collection<T>::Collection() noexcept : data_(nullptr), size_(0)
{
}

template <typename T>
inline Collection<T>::Collection(std::size_t size) : data_(new T [size]), size_(size)
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
Collection<T>::Collection(Collection<T>&& collection) noexcept
{
    size_ = collection.size_;
    data_ = collection.data_;

    collection.data_ = nullptr;
}

template <typename T>
Collection<T>::Collection(const std::initializer_list<T>& list)
    : data_(new T[list.size()]), size_(list.size())
{
    std::size_t i = 0;
    for(const auto& arg: list)
    {
        data_[i] = arg;
        ++i;
    }
}

template <typename T>
Collection<T>& Collection<T>::operator= (const Collection<T>& collection)
{
    if(this == &collection)
        return *this;

    delete[] data_;

    size_ = collection.size_;
    data_ = new T[size_];

    for(std::size_t i = 0; i < size_; ++i)
        data_[i] = collection.data_[i];

    return *this;
}

template <typename T>
Collection<T>& Collection<T>::operator= (Collection<T>&& collection) noexcept
{
    if(this == &collection)
        return *this;

    delete[] data_;

    size_ = collection.size_;
    data_ = collection.data_;

    collection.data_ = nullptr;

    return *this;
}

template <typename T>
inline std::size_t Collection<T>::size() const noexcept
{
    return size_;
}

template <typename T>
void Collection<T>::resize(std::size_t new_size)
{
    delete[] data_;

    size_ = new_size;
    data_ = new T[size_];
}

template <typename T>
inline typename Collection<T>::iterator Collection<T>::begin() const noexcept
{
    return iterator(data_);
}

template <typename T>
inline typename Collection<T>::iterator Collection<T>::end() const noexcept
{
    return iterator(data_ + size_);
}

template <typename T>
inline T& Collection<T>::operator[] (std::size_t i) noexcept
{
    return data_[i];
}

template <typename T>
inline const T& Collection<T>::operator[] (std::size_t i) const noexcept
{
    return data_[i];
}

#endif // COLLECTION_HPP
