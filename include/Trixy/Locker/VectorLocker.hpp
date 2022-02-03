#ifndef VECTOR_LOCKER_HPP
#define VECTOR_LOCKER_HPP

#include <utility> // move

#include "BaseLocker.hpp"

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

    using Function       = typename Lockable::Function;

public:
    Locker() : Lockable() {}
    ~Locker() {}

    explicit Locker(size_type size) : Lockable(size) {}
    Locker(size_type size, precision_type fill_value) : Lockable(size, fill_value) {}
    Locker(size_type size, const precision_type* ptr) : Lockable(size, ptr) {}

    Locker(const Locker& tensor) : Lockable(tensor) {}
    Locker(Locker&& tensor) noexcept : Lockable(std::move(tensor)) {}

    Locker(const Lockable& tensor) : Lockable(tensor) {}
    Locker(Lockable&& tensor) noexcept : Lockable(std::move(tensor)) {}

    Locker(std::initializer_list<precision_type> list) : Lockable(list) {}

    Locker& operator= (const Locker& vector) = delete;
    Locker& operator= (Locker&& vector) = delete;

    const Lockable& base() const { return *static_cast<const Lockable*>(this); }

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

#endif // VECTOR_LOCKER_HPP
