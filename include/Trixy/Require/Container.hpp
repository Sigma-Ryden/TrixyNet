#ifndef TRIXY_REQUIRE_CONTAINER_HPP
#define TRIXY_REQUIRE_CONTAINER_HPP

#include "Base.hpp"

namespace trixy
{

template <class Container>
using ContainerRequire = Require<Container, RequireType::container>;

template <class Container>
struct Require<Container, RequireType::container> : protected Container
{
public:
    using type = RequireType::container;

protected:
    using require = Container;

protected:
    using typename require::iterator;
    using typename require::const_iterator;

protected:
    using typename require::size_type;
    using typename require::value_type;
    using typename require::difference_type;

    using typename require::pointer;
    using typename require::const_pointer;

    using typename require::reference;
    using typename require::const_reference;

protected:
    using require::capacity;
    using require::size;
    using require::max_size;

    using require::resize;
    using require::reserve;

    using require::emplace_back;
    using require::pop_back;

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

#endif // TRIXY_REQUIRE_CONTAINER_HPP
