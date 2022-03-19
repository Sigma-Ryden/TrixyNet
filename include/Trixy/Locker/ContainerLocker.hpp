#ifndef CONTAINER_LOCKER_HPP
#define CONTAINER_LOCKER_HPP

#include <utility> // move, forward
#include <initializer_list> // initializer_list

#include "BaseLocker.hpp"
#include "Trixy/Detail/TrixyMeta.hpp"

#include "Trixy/Detail/MacroScope.hpp"

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
    // We MUST define explicit copy and move constructors
    // to prevent EATING args by constructor with perfect forwarding
    template <typename... Args,
        typename = TRIXY_ENABLE(meta::is_not_base_of<meta::decay_t<Args>, Locker>...),
        typename = TRIXY_ENABLE(std::is_constructible<Lockable, Args...>)>
    explicit Locker(Args&&... args) : Lockable(std::forward<Args>(args)...) {}

    // operator= for copy and move Locker object will not implicit generate
    Locker(const Locker& container) : Lockable(container) {}
    Locker(Locker&& container) noexcept : Lockable(std::move(container)) {}

    Locker(const Lockable& container) : Lockable(container) {}
    Locker(Lockable&& container) noexcept : Lockable(std::move(container)) {}

    Locker(std::initializer_list<value_type> list) : Lockable(list) {}

    ~Locker() = default;

    const Lockable& base() const noexcept
    { return static_cast<const Lockable&>(*this); }

public:
    using Lockable::size;
    using Lockable::max_size;

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

#include "Trixy/Detail/MacroUnscope.hpp"

#endif // CONTAINER_LOCKER_HPP
