#ifndef CONTAINER_REQUIRE_HPP
#define CONTAINER_REQUIRE_HPP

namespace trixy
{

template <class Container>
class ContainerRequire : private Container
{
public:
    using Base = Container;

protected:
    using typename Base::iterator;
    using typename Base::const_iterator;

protected:
    using typename Base::size_type;
    using typename Base::value_type;
    using typename Base::difference_type;

    using typename Base::pointer;
    using typename Base::const_pointer;

    using typename Base::reference;
    using typename Base::const_reference;

protected:
    using Base::operator=;

    using Base::capacity;
    using Base::size;
    using Base::max_size;

    using Base::resize;
    using Base::reserve;

    using Base::emplace_back;
    using Base::pop_back;

    using Base::empty;

    using Base::begin;
    using Base::end;
    using Base::cbegin;
    using Base::cend;

    using Base::front;
    using Base::back;

    using Base::data;

    using Base::operator[];
};

} // namespace trixy

#endif // CONTAINER_REQUIRE_HPP
