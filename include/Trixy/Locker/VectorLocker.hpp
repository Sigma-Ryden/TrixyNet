#ifndef VECTOR_LOCKER_HPP
#define VECTOR_LOCKER_HPP

#include <utility> // move, forward

#include "BaseLocker.hpp"
#include "Trixy/Detail/TrixyMeta.hpp"

#include "Trixy/Detail/MacroScope.hpp"

namespace trixy
{

template <class Vector>
using VectorLocker = Locker<Vector, LockerType::vector>;

template <class Vector>
class Locker<Vector, LockerType::vector> : protected Vector
{
protected:
    using require        = Vector;

public:
    using type           = typename Vector::type;

    using size_type      = typename Vector::size_type;
    using precision_type = typename Vector::precision_type;

    using pointer        = typename Vector::pointer;
    using const_pointer  = typename Vector::const_pointer;

public:
    // We MUST define explicit copy and move constructors
    // to prevent EATING args by constructor with perfect forwarding
    template <typename... Args,
        typename = TRIXY_ENABLE(meta::is_not_base_of<meta::decay_t<Args>, Locker>...),
        typename = TRIXY_ENABLE(std::is_constructible<Vector, Args...>)>
    explicit Locker(Args&&... args) : Vector(std::forward<Args>(args)...) {}

    // operator= for copy and move Locker object will not implicit generate
    Locker(const Locker& vector) : Vector(vector) {}
    Locker(Locker&& vector) noexcept : Vector(std::move(vector)) {}

    Locker(const Vector& vector) : Vector(vector) {}
    Locker(Vector&& vector) noexcept : Vector(std::move(vector)) {}

    ~Locker() = default;

    const Vector& base() const noexcept
    { return static_cast<const Vector&>(*this); }

public:
    using require::operator();

    using require::copy;
    using require::size;

    using require::fill;
    using require::apply;

    using require::dot;
    using require::add;
    using require::sub;
    using require::join;

    using require::data;
};

} // namespace trixy

#include "Trixy/Detail/MacroUnscope.hpp"

#endif // VECTOR_LOCKER_HPP
