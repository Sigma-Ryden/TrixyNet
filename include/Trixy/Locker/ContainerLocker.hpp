#ifndef CONTAINER_LOCKER_HPP
#define CONTAINER_LOCKER_HPP

#include <utility> // move, forward
#include <initializer_list> // initializer_list

#include "BaseLocker.hpp"
#include "Trixy/Detail/TrixyMeta.hpp"

#include "Trixy/Detail/MacroScope.hpp"

namespace trixy
{

template <class Container>
using ContainerLocker = Locker<Container, LockerType::container>;

template <class Container>
class Locker<Container, LockerType::container> : protected Container
{
protected:
    using require         = Container;

public:
    using size_type       = typename Container::size_type;
    using value_type      = typename Container::value_type;

    using reference       = typename Container::reference;
    using const_reference = typename Container::const_reference;

public:
    // We MUST define explicit copy and move constructors
    // to prevent EATING args by constructor with perfect forwarding
    template <typename... Args,
        typename = TRIXY_ENABLE(meta::is_not_base_of<meta::decay_t<Args>, Locker>...),
        typename = TRIXY_ENABLE(std::is_constructible<Container, Args...>)>
    explicit Locker(Args&&... args) : Container(std::forward<Args>(args)...) {}

    // operator= for copy and move Locker object will not implicit generate
    Locker(const Locker& container) : Container(container) {}
    Locker(Locker&& container) noexcept : Container(std::move(container)) {}

    Locker(const Container& container) : Container(container) {}
    Locker(Container&& container) noexcept : Container(std::move(container)) {}

    Locker(std::initializer_list<value_type> list) : Container(list) {}

    ~Locker() = default;

    const Container& base() const noexcept
    { return static_cast<const Container&>(*this); }

public:
    using require::size;
    using require::max_size;

    using require::empty;

    using require::begin;
    using require::end;
    using require::cbegin;
    using require::cend;

    using require::front;
    using require::back;

    using require::data;

    using require::operator[];
};

} // namespace trixy

#include "Trixy/Detail/MacroUnscope.hpp"

#endif // CONTAINER_LOCKER_HPP
