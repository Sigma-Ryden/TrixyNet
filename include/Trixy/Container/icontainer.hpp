#ifndef ICONTAINER_HPP
#define ICONTAINER_HPP

#include <cstddef> // size_t

namespace trixy
{

template <typename Type, typename... Args>
class IContainer
{
protected:
    virtual ~IContainer() = default;

public:
    class iterator;
    class const_iterator;

    using size_type       = std::size_t;
    using value_type      = Type;
    using difference_type = std::ptrdiff_t;

    using reference       = Type&;
    using const_reference = const Type&;

public:
    virtual size_type size() const noexcept = 0;
    virtual void resize(size_type new_size) = 0;

    virtual void empty() const noexcept = 0;

    virtual iterator begin() noexcept = 0;
    virtual iterator end() noexcept = 0;

    virtual const_iterator begin() const noexcept = 0;
    virtual const_iterator end() const noexcept = 0;

    virtual const_iterator cbegin() const noexcept = 0;
    virtual const_iterator cend() const noexcept = 0;

    virtual reference front() noexcept = 0;
    virtual const_reference front() const noexcept = 0;

    virtual reference back() noexcept = 0;
    virtual const_reference back() const noexcept = 0;

    virtual Type* data() noexcept = 0;
    virtual const Type* data() const noexcept = 0;

    virtual reference operator[] (size_type i) noexcept = 0;
    virtual const_reference operator[] (size_type i) const noexcept = 0;
};

template <typename Type, typename... Args>
class IContainer<Type, Args...>::iterator
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

template <typename Type, typename... Args>
class IContainer<Type, Args...>::const_iterator
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

} // namespace trixy

#endif // ICONTAINER_HPP
