#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <cstddef> // size_t
#include <initializer_list> // initializer_list
#include <new> // operator new[], operator delete[]
#include <utility> // forward

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

    using pointer         = Type*;
    using const_pointer   = const Type*;

    using reference       = Type&;
    using const_reference = const Type&;

private:
    pointer data_;
    size_type capacity_;
    size_type size_;

public:
    Container() noexcept;
    ~Container();

    explicit Container(size_type size);
    Container(const Container&);
    Container(Container&&) noexcept;
    Container(std::initializer_list<value_type>);

    Container& operator= (const Container&);
    Container& operator= (Container&&) noexcept;

    size_type capacity() const noexcept { return capacity_; }
    size_type size() const noexcept { return size_; }
    size_type max_size() const noexcept { return size_type(-1) / sizeof(value_type); }

    void reserve(size_type n);

    void resize(size_type n);
    void resize(size_type n, value_type&& fill);

    template <typename... Args>
    void emplace_back(Args&&... args);

    void pop_back();

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
    static pointer allocate(size_type n);
    static void deallocate(pointer ptr);

    static void destroy(pointer beg, pointer end);
};

template <typename Type>
class Container<Type>::iterator
{
private:
    pointer ptr_;

public:
    explicit iterator(pointer ptr) noexcept : ptr_(ptr) {}

    Type* const& base() const noexcept { return ptr_; }

    reference operator* () const noexcept { return *ptr_; }
    pointer operator-> () const noexcept { return ptr_; }

    bool operator!= (const iterator& it) const noexcept { return ptr_ != it.ptr_; }

    iterator operator++ () noexcept { ++ptr_; return *this; }
    iterator operator-- () noexcept { --ptr_; return *this; }

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

    const Type* const& base() const noexcept { return ptr_; }

    const_reference operator* () const noexcept { return *ptr_; }
    const_pointer operator-> () const noexcept { return ptr_; }

    bool operator!= (const const_iterator& it) const noexcept { return ptr_ != it.ptr_; }

    const_iterator operator++ () noexcept { ++ptr_; return *this; }
    const_iterator operator-- () noexcept { --ptr_; return *this; }

    const_iterator operator+ (difference_type n) noexcept { ptr_ + n; return *this; }
    const_iterator operator- (difference_type n) noexcept { ptr_ - n; return *this; }

    const_reference operator[] (size_type i) const noexcept { return ptr_[i]; }
};

template <typename Type>
inline Container<Type>::Container() noexcept
    : data_(nullptr), capacity_(0), size_(0)
{
}

template <typename Type>
Container<Type>::~Container()
{
    Container::destroy(data_, data_ + size_);
    Container::deallocate(data_);
}

template <typename Type>
Container<Type>::Container(size_type size)
    : data_(Container::allocate(size))
    , capacity_(size)
    , size_(size)
{
    for(size_type i = 0; i < size_; ++i)
        new (data_ + i) value_type();
}

template <typename Type>
Container<Type>::Container(const Container& container)
    : data_(Container::allocate(container.size_))
    , capacity_(container.capacity_)
    , size_(container.size_)
{
    for(std::size_t i = 0; i < size_; ++i)
        new (data_ + i) value_type(container.data_[i]);
}

template <typename Type>
Container<Type>::Container(Container&& container) noexcept
{
    capacity_ = container.capacity_;

    size_ = container.size_;
    data_ = container.data_;

    container.data_ = nullptr;
}

template <typename Type>
Container<Type>::Container(std::initializer_list<value_type> list)
    : data_(Container::allocate(list.size()))
    , capacity_(list.size())
    , size_(list.size())
{
    size_type i = 0;
    for(const auto& arg: list)
    {
        new (data_ + i) value_type(arg);
        ++i;
    }
}

template <typename Type>
Container<Type>& Container<Type>::operator= (const Container& container)
{
    if(this == &container)
        return *this;

    Container::destroy(data_, data_ + size_);
    Container::deallocate(data_);

    capacity_ = container.capacity_;

    size_ = container.size_;
    data_ = Container::allocate(size_);

    for(size_type i = 0; i < size_; ++i)
        new (data_ + i) value_type(container.data_[i]);

    return *this;
}

template <typename Type>
Container<Type>& Container<Type>::operator= (Container&& container) noexcept
{
    if(this == &container)
        return *this;

    Container::destroy(data_, data_ + size_);
    Container::deallocate(data_);

    capacity_ = container.capacity_;

    size_ = container.size_;
    data_ = container.data_;

    container.data_ = nullptr;

    return *this;
}

template <typename Type>
void Container<Type>::resize(size_type n)
{
    // capacity is always more than or equal to size
    if(n > capacity_)
    {
        reserve(n);

        for(; size_ < n; ++size_)
            new (data_ + size_) value_type();

        capacity_ = size_;

        return;
    }

    if(n < size_)
    {
        Container::destroy(data_ + n, data_ + size_);
        size_ = n;
    }
    else
    {
        for(; size_ < n; ++size_)
            new (data_ + size_) value_type();
    }
}

template <typename Type>
void Container<Type>::resize(size_type n, value_type&& fill)
{
    // capacity is always more than or equal to size
    if(n > capacity_)
    {
        reserve(n);

        for(; size_ < n; ++size_)
            new (data_ + size_) value_type(std::forward<value_type>(fill));

        capacity_ = size_;

        return;
    }

    if(n < size_)
    {
        Container::destroy(data_ + n, data_ + size_);
        size_ = n;
    }
    else
    {
        for(; size_ < n; ++size_)
            new (data_ + size_) value_type(std::forward<value_type>(fill));
    }
}

template <typename Type>
void Container<Type>::reserve(size_type n)
{
    if(n > capacity_)
    {
        pointer buff = Container::allocate(n);

        for(size_type i = 0; i < size_; ++i)
            new (buff + i) value_type(std::move(data_[i]));

        std::swap(buff, data_);

        Container::destroy(buff, buff + size_);
        Container::deallocate(buff);

        capacity_ = n;
    }
}

template <typename Type>
template <typename... Args>
void Container<Type>::emplace_back(Args&&... args)
{
    if(size_ >= capacity_)
        reserve(size_ * 2);

    new (data_ + size_) Type(std::forward<Args>(args)...);

    ++size_;
}

template <typename Type>
void Container<Type>::pop_back()
{
    data_[size_ - 1].~value_type();

    --size_;
}

template <typename Type>
inline typename Container<Type>::pointer Container<Type>::allocate(size_type n)
{
    return static_cast<pointer>(::operator new[] (sizeof(value_type) * n));
}

template <typename Type>
inline void Container<Type>::deallocate(pointer ptr)
{
    ::operator delete[] (ptr);
}

template <typename Type>
void Container<Type>::destroy(pointer beg, pointer end)
{
    if(beg == nullptr) return;

    while(beg != end)
    {
        beg->~Type();
        ++beg;
    }
}

} // namespace trixy

#endif // CONTAINER_HPP