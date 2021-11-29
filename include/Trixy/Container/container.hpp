#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <cstddef> // size_t
#include <initializer_list> // initializer_list

namespace trixy
{

template <typename Type>
class Container
{
public:
    class iterator;

    using size_type       = std::size_t;
    using reference       = Type&;
    using const_reference = const Type&;

private:
    Type* data_;
    size_type size_;

public:
    Container() noexcept;
    explicit Container(size_type size);
    Container(const Container&);
    Container(Container&&) noexcept;
    Container(const std::initializer_list<Type>&);

    Container<Type>& operator= (const Container&);
    Container<Type>& operator= (Container&&) noexcept;

    size_type size() const noexcept;
    void resize(size_type new_size);

    iterator begin() const noexcept;
    iterator end() const noexcept;

    Type* data() noexcept;
    const Type* data() const noexcept;

    reference operator[] (size_type i) noexcept;
    const_reference operator[] (size_type i) const noexcept;
};

template <typename Type>
class Container<Type>::iterator
{
private:
    Type* ptr_;

public:
    explicit iterator(Type* ptr) noexcept : ptr_(ptr) {}

    Type& operator* () noexcept { return *ptr_; }
    Type* operator-> () noexcept { return ptr_; }

    bool operator!= (const iterator& it) const noexcept { return ptr_ != it.ptr_; }

    iterator operator++ () noexcept { ++ptr_; return *this; }
    iterator operator-- () noexcept { --ptr_; return *this; }
};

template <typename Type>
inline Container<Type>::Container() noexcept : data_(nullptr), size_(0)
{
}

template <typename Type>
inline Container<Type>::Container(std::size_t size) : data_(new Type[size]), size_(size)
{
}

template <typename Type>
Container<Type>::Container(const Container& container)
    : data_(new Type[container.size_]), size_(container.size_)
{
    for(std::size_t i = 0; i < size_; ++i)
        data_[i] = container.data_[i];
}

template <typename Type>
Container<Type>::Container(Container&& container) noexcept
{
    size_ = container.size_;
    data_ = container.data_;

    container.data_ = nullptr;
}

template <typename Type>
Container<Type>::Container(const std::initializer_list<Type>& list)
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
Container<Type>& Container<Type>::operator= (const Container& container)
{
    if(this == &container)
        return *this;

    delete[] data_;

    size_ = container.size_;
    data_ = new Type[size_];

    for(std::size_t i = 0; i < size_; ++i)
        data_[i] = container.data_[i];

    return *this;
}

template <typename Type>
Container<Type>& Container<Type>::operator= (Container&& container) noexcept
{
    if(this == &container)
        return *this;

    delete[] data_;

    size_ = container.size_;
    data_ = container.data_;

    container.data_ = nullptr;

    return *this;
}

template <typename Type>
inline std::size_t Container<Type>::size() const noexcept
{
    return size_;
}

template <typename Type>
void Container<Type>::resize(std::size_t new_size)
{
    delete[] data_;

    size_ = new_size;
    data_ = new Type[size_];
}

template <typename Type>
inline typename Container<Type>::iterator Container<Type>::begin() const noexcept
{
    return iterator(data_);
}

template <typename Type>
inline typename Container<Type>::iterator Container<Type>::end() const noexcept
{
    return iterator(data_ + size_);
}

template <typename Type>
inline Type* Container<Type>::data() noexcept
{
    return data_;
}

template <typename Type>
inline const Type* Container<Type>::data() const noexcept
{
    return data_;
}

template <typename Type>
inline Type& Container<Type>::operator[] (std::size_t i) noexcept
{
    return data_[i];
}

template <typename Type>
inline const Type& Container<Type>::operator[] (std::size_t i) const noexcept
{
    return data_[i];
}

} // namespace trixy

#endif // CONTAINER_HPP
