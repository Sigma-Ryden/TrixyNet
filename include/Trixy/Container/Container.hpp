#ifndef TRIXY_CONTAINER_HPP
#define TRIXY_CONTAINER_HPP

#include <cstddef> // size_t, ptrdiff_t
#include <initializer_list> // initializer_list
#include <new> // operator new[], operator delete[]
#include <utility> // forward

#include <Trixy/Serializer/Core.hpp>

namespace trixy
{

namespace utility
{

template <typename Type>
class Container
{
    SERIALIZABLE_ACCESS()

public:
    class iterator;
    class const_iterator;

public:
    using size_type       = std::size_t;
    using value_type      = Type;
    using difference_type = std::ptrdiff_t;

    using pointer         = Type*;
    using const_pointer   = const Type*;

    using reference       = Type&;
    using const_reference = const Type&;

private:
    pointer data_;
    size_type size_;
    size_type capacity_;

public:
    Container() noexcept : data_(nullptr), size_(0), capacity_(0) {}

    ~Container()
    {
        Container::destroy(data_, data_ + size_);
        Container::deallocate(data_);
    }

    explicit Container(size_type size)
        : data_(Container::allocate(size))
        , size_(size)
        , capacity_(size)
    {
        for (size_type i = 0; i < size_; ++i)
            new (data_ + i) value_type();
    }

    Container(const Container& container)
        : data_(Container::allocate(container.size_))
        , size_(container.size_)
        , capacity_(container.capacity_)
    {
        for (std::size_t i = 0; i < size_; ++i)
            new (data_ + i) value_type(container.data_[i]);
    }

    Container(Container&& container) noexcept
    {
        capacity_ = container.capacity_;

        size_ = container.size_;
        data_ = container.data_;

        container.data_ = nullptr;
    }

    Container(std::initializer_list<value_type> list)
        : data_(Container::allocate(list.size()))
        , size_(list.size())
        , capacity_(list.size())
    {
        size_type i = 0;
        for (const auto& arg: list)
        {
            new (data_ + i) value_type(arg);
            ++i;
        }
    }

    Container& operator= (const Container& container)
    {
        if(this == &container) return *this;

        Container::destroy(data_, data_ + size_);
        Container::deallocate(data_);

        capacity_ = container.capacity_;

        size_ = container.size_;
        data_ = Container::allocate(capacity_);

        for (size_type i = 0; i < size_; ++i)
            new (data_ + i) value_type(container.data_[i]);

        return *this;
    }

    Container& operator= (Container&& container) noexcept
    {
        if(this == &container) return *this;

        Container::destroy(data_, data_ + size_);
        Container::deallocate(data_);

        capacity_ = container.capacity_;

        size_ = container.size_;
        data_ = container.data_;

        container.data_ = nullptr;

        return *this;
    }

    size_type capacity() const noexcept { return capacity_; }
    size_type size() const noexcept { return size_; }
    size_type max_size() const noexcept { return size_type(-1) / sizeof(value_type); }

    template <typename... Args>
    void resize(size_type n, Args&&... args)
    {
        // capacity is always more than or equal to size
        if (n > capacity_)
        {
            reserve(n);

            for (; size_ < n; ++size_)
                new (data_ + size_) value_type(std::forward<Args>(args)...);

            capacity_ = n;

            return;
        }

        if (n < size_)
        {
            Container::destroy(data_ + n, data_ + size_);
            size_ = n;
        }
        else
        {
            for (; size_ < n; ++size_)
                new (data_ + size_) value_type(std::forward<Args>(args)...);
        }
    }

    void reserve(size_type n)
    {
        if (n > capacity_)
        {
            pointer buff = Container::allocate(n);

            for (size_type i = 0; i < size_; ++i)
                new (buff + i) value_type(std::move(data_[i]));

            std::swap(buff, data_);

            Container::destroy(buff, buff + size_);
            Container::deallocate(buff);

            capacity_ = n;
        }
    }

    template <typename... Args>
    void emplace_back(Args&&... args)
    {
        // size is always less than or equal to capacity
        if (size_ == capacity_)
            reserve(capacity_ * 2 + 1);

        new (data_ + size_) value_type(std::forward<Args>(args)...);
        ++size_;
    }

    void pop_back()
    {
        // call destructor of last element in Container
        --size_;
        data_[size_].~value_type();
    }

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

    pointer data() noexcept { return data_; }
    const_pointer data() const noexcept { return data_; }

    reference operator[] (size_type i) noexcept { return data_[i]; }
    const_reference operator[] (size_type i) const noexcept { return data_[i]; }

private:
    static pointer allocate(size_type n)
    {
        // return void pointer to sizeof(value_type) * n bytes in memory
        return static_cast<pointer>
        (
            ::operator new[] (sizeof(value_type) * n)
        );
    }

    static void deallocate(pointer ptr)
    {
        ::operator delete[] (ptr);
    }

    static void destroy(pointer first, pointer last)
    {
        if (first == nullptr) return;

        while (first != last)
        {
            first->~value_type();
            ++first;
        }
    }
};

template <typename Type>
class Container<Type>::iterator
{
private:
    pointer ptr_;

public:
    explicit iterator(pointer ptr) noexcept : ptr_(ptr) {}

    const pointer& base() const noexcept { return ptr_; }

    reference operator* () const noexcept { return *ptr_; }
    pointer operator-> () const noexcept { return ptr_; }

    bool operator!= (const iterator& it) const noexcept { return ptr_ != it.ptr_; }
    bool operator== (const iterator& it) const noexcept { return ptr_ == it.ptr_; }

    iterator operator++ () noexcept { ++ptr_; return *this; }
    iterator operator-- () noexcept { --ptr_; return *this; }

    difference_type operator- (iterator it) noexcept { return ptr_ - it.ptr_; }

    iterator operator+ (difference_type n) noexcept { ptr_ + n; return *this; }
    iterator operator- (difference_type n) noexcept { ptr_ - n; return *this; }

    reference operator[] (size_type i) noexcept { return ptr_[i]; }
};

template <typename Type>
class Container<Type>::const_iterator
{
private:
    pointer ptr_;

public:
    explicit const_iterator(pointer ptr) noexcept : ptr_(ptr) {}

    const const_pointer& base() const noexcept { return ptr_; }

    const_reference operator* () const noexcept { return *ptr_; }
    const_pointer operator-> () const noexcept { return ptr_; }

    bool operator!= (const const_iterator& it) const noexcept { return ptr_ != it.ptr_; }
    bool operator== (const const_iterator& it) const noexcept { return ptr_ == it.ptr_; }

    const_iterator operator++ () noexcept { ++ptr_; return *this; }
    const_iterator operator-- () noexcept { --ptr_; return *this; }

    difference_type operator- (const_iterator it) noexcept { return ptr_ - it.ptr_; }

    const_iterator operator+ (difference_type n) noexcept { ptr_ + n; return *this; }
    const_iterator operator- (difference_type n) noexcept { ptr_ - n; return *this; }

    const_reference operator[] (size_type i) const noexcept { return ptr_[i]; }
};

} // namespace utility

} // namepace trixy

TEMPLATE_SERIALIZABLE_DECLARATION(template <typename Type>, trixy::utility::Container<Type>)
SERIALIZABLE_DECLARATION_INIT()

TEMPLATE_SERIALIZABLE(saveload, tensor, template <typename Type>, trixy::utility::Container<Type>)
    SERIALIZATION
    (
        archive & sf::span(tensor.data_, tensor.size_);
        tensor.capacity_ = tensor.size_;
    )
SERIALIZABLE_INIT()

#endif // TRIXY_CONTAINER_HPP
