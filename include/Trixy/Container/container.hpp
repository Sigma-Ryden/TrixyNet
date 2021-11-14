#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <cstddef> // size_t
#include <initializer_list> // initializer_list

template <typename T>
class Container
{
public:
    class iterator;

    using size_type       = std::size_t;
    using reference       = T&;
    using const_reference = const T&;

private:
    T* data_;
    std::size_t size_;

public:
    Container() noexcept;
    explicit Container(std::size_t size);
    Container(const Container<T>&);
    Container(Container<T>&&) noexcept;
    Container(const std::initializer_list<T>&);

    Container<T>& operator= (const Container<T>&);
    Container<T>& operator= (Container<T>&&) noexcept;

    size_type size() const noexcept;
    void resize(std::size_t new_size);

    iterator begin() const noexcept;
    iterator end() const noexcept;

    reference operator[] (std::size_t i) noexcept;
    const_reference operator[] (std::size_t i) const noexcept;
};

template <typename T>
class Container<T>::iterator
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
inline Container<T>::Container() noexcept : data_(nullptr), size_(0)
{
}

template <typename T>
inline Container<T>::Container(std::size_t size) : data_(new T [size]), size_(size)
{
}

template <typename T>
Container<T>::Container(const Container<T>& container)
    : data_(new T[container.size_]), size_(container.size_)
{
    for(std::size_t i = 0; i < size_; ++i)
        data_[i] = container.data_[i];
}

template <typename T>
Container<T>::Container(Container<T>&& container) noexcept
{
    size_ = container.size_;
    data_ = container.data_;

    container.data_ = nullptr;
}

template <typename T>
Container<T>::Container(const std::initializer_list<T>& list)
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
Container<T>& Container<T>::operator= (const Container<T>& container)
{
    if(this == &container)
        return *this;

    delete[] data_;

    size_ = container.size_;
    data_ = new T[size_];

    for(std::size_t i = 0; i < size_; ++i)
        data_[i] = container.data_[i];

    return *this;
}

template <typename T>
Container<T>& Container<T>::operator= (Container<T>&& container) noexcept
{
    if(this == &container)
        return *this;

    delete[] data_;

    size_ = container.size_;
    data_ = container.data_;

    container.data_ = nullptr;

    return *this;
}

template <typename T>
inline std::size_t Container<T>::size() const noexcept
{
    return size_;
}

template <typename T>
void Container<T>::resize(std::size_t new_size)
{
    delete[] data_;

    size_ = new_size;
    data_ = new T[size_];
}

template <typename T>
inline typename Container<T>::iterator Container<T>::begin() const noexcept
{
    return iterator(data_);
}

template <typename T>
inline typename Container<T>::iterator Container<T>::end() const noexcept
{
    return iterator(data_ + size_);
}

template <typename T>
inline T& Container<T>::operator[] (std::size_t i) noexcept
{
    return data_[i];
}

template <typename T>
inline const T& Container<T>::operator[] (std::size_t i) const noexcept
{
    return data_[i];
}

#endif // CONTAINER_HPP
