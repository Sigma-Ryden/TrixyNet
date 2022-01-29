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
    class const_iterator;

    using size_type       = std::size_t;
    using value_type      = Type;
    using difference_type = std::ptrdiff_t;

    using reference       = Type&;
    using const_reference = const Type&;

private:
    Type* data_;
    size_type size_;

public:
    Container() noexcept;
    ~Container();

    explicit Container(size_type size);
    Container(const Container&);
    Container(Container&&) noexcept;
    Container(std::initializer_list<Type>);

    Container<Type>& operator= (const Container&);
    Container<Type>& operator= (Container&&) noexcept;

    size_type size() const noexcept;
    void resize(size_type new_size);

    bool empty() const noexcept { return size_ == 0; }

    iterator begin() noexcept { return iterator(data_); }
    iterator end() noexcept { return iterator(data_ + size_); }

    const_iterator begin() const noexcept { return const_iterator(data_); }
    const_iterator end() const noexcept { return const_iterator(data_ + size_); }

    const_iterator cbegin() const noexcept { return const_iterator(data_); }
    const_iterator cend() const noexcept { return const_iterator(data_ + size_); }

    reference front() noexcept { return data_[0]; }
    const_reference front() const noexcept { return data_[0]; }

    reference back() noexcept { return data_[size_ - 1]; }
    const_reference back() const noexcept { return data_[size_ - 1]; }

    Type* data() noexcept { return data_; }
    const Type* data() const noexcept { return data_; }

    reference operator[] (size_type i) noexcept { return data_[i]; }
    const_reference operator[] (size_type i) const noexcept { return data_[i]; }
};

template <typename Type>
class Container<Type>::iterator
{
private:
    Type* ptr_;

public:
    explicit iterator(Type* ptr) noexcept : ptr_(ptr) {}

    Type* const& base() const noexcept { return ptr_; }

    Type& operator* () const noexcept { return *ptr_; }
    Type* operator-> () const noexcept { return ptr_; }

    bool operator!= (const iterator& it) const noexcept { return ptr_ != it.ptr_; }

    iterator operator++ () noexcept { ++ptr_; return *this; }
    iterator operator-- () noexcept { --ptr_; return *this; }

    iterator operator+ (difference_type n) noexcept { ptr_ + n; return *this; }
    iterator operator- (difference_type n) noexcept { ptr_ - n; return *this; }

    Type& operator[] (size_type i) noexcept { return ptr_[i]; }
};

template <typename Type>
class Container<Type>::const_iterator
{
private:
    Type* ptr_;

public:
    explicit const_iterator(Type* ptr) noexcept : ptr_(ptr) {}

    const Type* const& base() const noexcept { return ptr_; }

    const Type& operator* () const noexcept { return *ptr_; }
    const Type* operator-> () const noexcept { return ptr_; }

    bool operator!= (const const_iterator& it) const noexcept { return ptr_ != it.ptr_; }

    const_iterator operator++ () noexcept { ++ptr_; return *this; }
    const_iterator operator-- () noexcept { --ptr_; return *this; }

    const_iterator operator+ (difference_type n) noexcept { ptr_ + n; return *this; }
    const_iterator operator- (difference_type n) noexcept { ptr_ - n; return *this; }

    const Type& operator[] (size_type i) const noexcept { return ptr_[i]; }
};

template <typename Type>
inline Container<Type>::Container() noexcept : data_(nullptr), size_(0)
{
}

template <typename Type>
inline Container<Type>::~Container()
{
    delete[] data_;
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
Container<Type>::Container(std::initializer_list<Type> list)
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

} // namespace trixy

#endif // CONTAINER_HPP
