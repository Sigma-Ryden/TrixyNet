#ifndef CONTAINER_LOCKER_HPP
#define CONTAINER_LOCKER_HPP

#include <utility> // forward
#include <iostream>
#include "BaseLocker.hpp"

namespace trixy
{

template <class Lockable>
using ContainerLocker = Locker<Lockable, LockerType::container, void>;

template <class Lockable>
class Locker<Lockable, LockerType::container, void> : protected Lockable
{
public:
    using size_type       = typename Lockable::size_type;
    using value_type      = typename Lockable::value_type;

    using reference       = typename Lockable::reference;
    using const_reference = typename Lockable::const_reference;

public:
    Locker() noexcept : Lockable() {}
    ~Locker() {}

    explicit Locker(size_type size) : Lockable(size) {}

    Locker(const Locker& container) : Lockable(container) {}
    Locker(Locker&& container) noexcept : Lockable(std::move(container)) {}

    Locker(const Lockable& container) : Lockable(container) {}
    Locker(Lockable&& container) noexcept : Lockable(std::move(container)) {}

    Locker(std::initializer_list<value_type> list) : Lockable(list) {}

    //Locker& operator= (const Locker& vector) = delete;
    Locker& operator= (Locker&& vector) = default;

    const Lockable& base() const { return static_cast<const Lockable&>(*this); }

public:
    using Lockable::size;
    using Lockable::empty;

    using Lockable::begin;
    using Lockable::end;
    using Lockable::cbegin;
    using Lockable::cend;

    using Lockable::front;
    using Lockable::back;

    using Lockable::data;

    using Lockable::operator[];
};

} // namespace trixy

#endif // CONTAINER_LOCKER_HPP
