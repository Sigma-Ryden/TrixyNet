#ifndef ICONTAINER_HPP
#define ICONTAINER_HPP

#include <cstddef> // size_t, ptrdiff_t
#include <utility> // forward

namespace trixy
{

template <template <typename...> class Derived, typename Type, typename... Pack>
class IContainer
{
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

protected:
    using DerivedType     = Derived<Type, Pack...>;

protected:
    virtual ~IContainer() = default;

private:
    DerivedType& self() noexcept
    { return *static_cast<DerivedType*>(this); }

    const DerivedType& self() const noexcept
    { return *static_cast<const DerivedType*>(this); }

public:
    size_type capacity() const noexcept { return self().capacity(); }
    size_type size() const noexcept { return self().size(); }
    size_type max_size() const noexcept { return self().max_size(); }

    void reserve(size_type n) { self().reserve(n); }

    template <typename... Args>
    void resize(size_type n, Args&&... args) { self().resize(n, std::forward<Args>(args)...); }

    template <typename... Args>
    void emplace_back(Args&&... args)
    { self().emplace_back(std::forward<Args>(args)...); }

    void pop_back() { self().pop_back(); }

    void empty() const noexcept { self().empty(); }

    iterator begin() noexcept { return self().begin(); }
    iterator end() noexcept { return self().end(); }

    const_iterator begin() const noexcept { return self().begin(); }
    const_iterator end() const noexcept { return self().end(); }

    const_iterator cbegin() const noexcept { return self().cbegin(); }
    const_iterator cend() const noexcept { return self().cend(); }

    reference front() noexcept { return self().front(); }
    const_reference front() const noexcept { return self().front(); }

    reference back() noexcept { return self().back(); }
    const_reference back() const noexcept { return self().back(); }

    pointer data() noexcept { return self().data(); }
    const_pointer data() const noexcept { return self().data(); }

    reference operator[] (size_type i) noexcept { return self().operator[](i); }
    const_reference operator[] (size_type i) const noexcept { return self().operator[](i); }
};

template <template <typename...> class Derived, typename Type, typename... Pack>
class IContainer<Derived, Type, Pack...>::iterator
{
private:
    pointer ptr_;

public:
    explicit iterator(pointer ptr) noexcept : ptr_(ptr) {}

    const pointer& base() const noexcept { return ptr_; }

    reference operator* () const noexcept { return *ptr_; }
    pointer operator-> () const noexcept { return ptr_; }

    bool operator!= (const iterator& it) const noexcept { return ptr_ != it.ptr_; }

    iterator operator++ () noexcept { ++ptr_; return *this; }
    iterator operator-- () noexcept { --ptr_; return *this; }

    iterator operator+ (difference_type n) noexcept { ptr_ + n; return *this; }
    iterator operator- (difference_type n) noexcept { ptr_ - n; return *this; }

    reference operator[] (size_type i) noexcept { return ptr_[i]; }
};

template <template <typename...> class Derived, typename Type, typename... Pack>
class IContainer<Derived, Type, Pack...>::const_iterator
{
private:
    pointer ptr_;

public:
    explicit const_iterator(pointer ptr) noexcept : ptr_(ptr) {}

    const const_pointer& base() const noexcept { return ptr_; }

    const_reference operator* () const noexcept { return *ptr_; }
    const_pointer operator-> () const noexcept { return ptr_; }

    bool operator!= (const const_iterator& it) const noexcept { return ptr_ != it.ptr_; }

    const_iterator operator++ () noexcept { ++ptr_; return *this; }
    const_iterator operator-- () noexcept { --ptr_; return *this; }

    const_iterator operator+ (difference_type n) noexcept { ptr_ + n; return *this; }
    const_iterator operator- (difference_type n) noexcept { ptr_ - n; return *this; }

    const_reference operator[] (size_type i) const noexcept { return ptr_[i]; }
};

} // namespace trixy

#endif // ICONTAINER_HPP
