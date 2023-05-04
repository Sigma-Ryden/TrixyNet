#ifndef TRIXY_LOCKER_SERIALIZATION_HPP
#define TRIXY_LOCKER_SERIALIZATION_HPP

#include <Trixy/Serializer/Core.hpp>

#include <Trixy/Locker/Detail/LockerMeta.hpp>

namespace trixy
{

namespace meta
{

template <typename T>
struct locker_trait;

template <class Lockable, typename LockerType>
struct locker_trait<memory::Locker<Lockable, LockerType>>
{
    using lockable = Lockable;
};

} // namespace meta

} // namespace trixy

CONDITIONAL_SERIALIZATION(SaveLoad, trixy::meta::is_locker<T>::value)
{
    using lockable = typename trixy::meta::locker_trait<T>::lockable;
    archive & sf::base<lockable>(self);
}

#endif // TRIXY_LOCKER_SERIALIZATION_HPP
