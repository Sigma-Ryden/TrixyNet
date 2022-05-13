#ifndef TRIXY_LOCKER_CONTAINER_HPP
#define TRIXY_LOCKER_CONTAINER_HPP

#include <utility> // move, forward
#include <initializer_list> // initializer_list

#include <Trixy/Locker/Base.hpp>
#include <Trixy/Detail/TrixyMeta.hpp>

#include <Trixy/Detail/MacroScope.hpp>

namespace trixy
{

template <class Container>
using ContainerLocker = Locker<Container, LockerType::container>;

template <class Container>
class Locker<Container, LockerType::container> : protected Container
{
protected:
    using require = Container;

public:
    using typename require::size_type;
    using typename require::value_type;

    using typename require::reference;
    using typename require::const_reference;

public:
    template <typename U = Container,
              meta::as<std::is_constructible<U>::value> = 0>
    Locker() : Container() {}

    // We MUST define explicit copy and move constructors
    // to prevent EATING args by constructor with perfect forwarding
    template <typename T, typename... Tn,
        meta::as<not std::is_base_of<meta::decay_t<T>, Locker>::value> = 0,
        meta::as<std::is_constructible<Container, T, Tn...>::value> = 0>
    explicit Locker(T&& t, Tn&&... tn)
        : Container(std::forward<T>(t), std::forward<Tn>(tn)...) {}

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

#include <Trixy/Detail/MacroUnscope.hpp>

#endif // TRIXY_LOCKER_CONTAINER_HPP
