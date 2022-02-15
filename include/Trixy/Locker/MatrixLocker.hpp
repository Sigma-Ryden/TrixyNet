#ifndef MATRIX_LOCKER_HPP
#define MATRIX_LOCKER_HPP

#include <utility> // move, forward

#include "BaseLocker.hpp"
#include "Trixy/Detail/TrixyMeta.hpp"

#include "Trixy/Detail/MacroScope.hpp"

namespace trixy
{

template <class Lockable>
using MatrixLocker = Locker<Lockable, LockerType::matrix, void>;

template <class Lockable>
class Locker<Lockable, LockerType::matrix, void> : protected Lockable
{
public:
    using type           = typename Lockable::type;

    using size_type      = typename Lockable::size_type;
    using precision_type = typename Lockable::precision_type;

    using pointer        = typename Lockable::pointer;
    using const_pointer  = typename Lockable::const_pointer;

    using Shape          = typename Lockable::Shape;

    using Function       = typename Lockable::Function;

public:
    template <typename... Args,
        typename = TRIXY_ENABLE(meta::is_not_base_of<meta::decay_t<Args>, Locker>...),
        typename = TRIXY_ENABLE(std::is_constructible<Lockable, Args...>)>
    Locker(Args&&... args) : Lockable(std::forward<Args>(args)...) {}

    ~Locker() = default;

    Locker(const Locker& container) : Lockable(container) {}
    Locker(Locker&& container) noexcept : Lockable(std::move(container)) {}

    Locker(const Lockable& container) : Lockable(container) {}
    Locker(Lockable&& container) noexcept : Lockable(std::move(container)) {}

    const Lockable& base() const { return static_cast<const Lockable&>(*this); }

public:
    using Lockable::operator();

    using Lockable::copy;
    using Lockable::size;
    using Lockable::shape;

    using Lockable::fill;
    using Lockable::apply;

    using Lockable::dot;

    using Lockable::add;
    using Lockable::sub;
    using Lockable::join;

    using Lockable::transpose;
    using Lockable::inverse;

    using Lockable::data;
};

} // namespace trixy

#include "Trixy/Detail/MacroUnscope.hpp"

#endif // MATRIX_LOCKER_HPP
