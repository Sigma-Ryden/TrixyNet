#ifndef VECTOR_LOCKER_HPP
#define VECTOR_LOCKER_HPP

#include <utility> // move, forward

#include "BaseLocker.hpp"
#include "Trixy/Detail/TrixyMeta.hpp"

#include "Trixy/Detail/MacroScope.hpp"

namespace trixy
{

template <class Lockable>
using VectorLocker = Locker<Lockable, LockerType::vector, void>;

template <class Lockable>
class Locker<Lockable, LockerType::vector, void> : protected Lockable
{
public:
    using type           = typename Lockable::type;

    using size_type      = typename Lockable::size_type;
    using precision_type = typename Lockable::precision_type;

    using pointer        = typename Lockable::pointer;
    using const_pointer  = typename Lockable::const_pointer;

public:
    // We MUST define explicit copy and move constructors
    // to prevent EATING args by constructor with perfect forwarding
    template <typename... Args,
        typename = TRIXY_ENABLE(meta::is_not_base_of<meta::decay_t<Args>, Locker>...),
        typename = TRIXY_ENABLE(std::is_constructible<Lockable, Args...>)>
    Locker(Args&&... args) : Lockable(std::forward<Args>(args)...) {}

    // operator= for copy and move Locker object will not implicit generate
    Locker(const Locker& container) : Lockable(container) {}
    Locker(Locker&& container) noexcept : Lockable(std::move(container)) {}

    Locker(const Lockable& container) : Lockable(container) {}
    Locker(Lockable&& container) noexcept : Lockable(std::move(container)) {}

    ~Locker() {}

    const Lockable& base() const noexcept
    { return static_cast<const Lockable&>(*this); }

public:
    using Lockable::operator();

    using Lockable::copy;
    using Lockable::size;

    using Lockable::fill;
    using Lockable::apply;

    using Lockable::dot;
    using Lockable::add;
    using Lockable::sub;
    using Lockable::join;

    using Lockable::data;
};

} // namespace trixy

#include "Trixy/Detail/MacroUnscope.hpp"

#endif // VECTOR_LOCKER_HPP
