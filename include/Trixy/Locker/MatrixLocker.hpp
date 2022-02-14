#ifndef MATRIX_LOCKER_HPP
#define MATRIX_LOCKER_HPP

#include <utility> // move

#include "BaseLocker.hpp"

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
    Locker() : Lockable() {}
    ~Locker() {}

    explicit Locker(size_type size) : Lockable(size) {}
    explicit Locker(size_type m, size_type n) : Lockable(m, n) {}
    explicit Locker(const Shape& shape) : Lockable(shape) {}

    Locker(size_type m, size_type n, precision_type value) : Lockable(m, n, value) {}
    Locker(const Shape& shape, precision_type value) : Lockable(shape, value) {}

    Locker(size_type size, const_pointer ptr) : Lockable(size, ptr) {}
    Locker(size_type m, size_type n, const_pointer ptr) : Lockable(m, n, ptr) {}
    Locker(const Shape& shape, const_pointer ptr) : Lockable(shape, ptr) {}

    Locker(const Lockable& tensor) : Lockable(tensor) {}
    Locker(Lockable&& tensor) noexcept : Lockable(std::move(tensor)) {}

    Locker(const Locker& tensor) : Lockable(tensor) {}
    Locker(Locker&& tensor) noexcept : Lockable(std::move(tensor)) {}

    //Locker& operator= (const Locker& vector) = default;
    Locker& operator= (Locker&& vector) = default;

    const Lockable& base() const { return *static_cast<const Lockable*>(this); }

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

#endif // MATRIX_LOCKER_HPP
