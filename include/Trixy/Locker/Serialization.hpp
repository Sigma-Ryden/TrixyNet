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

CONDITIONAL_SERIALIZABLE_DECLARATION(trixy::meta::is_locker<S>::value)
SERIALIZABLE_DECLARATION_INIT()

CONDITIONAL_SERIALIZABLE(saveload, self, trixy::meta::is_locker<S>::value)
    SERIALIZATION
    (
        using lockable = typename trixy::meta::locker_trait<S>::lockable;
        archive & sf::base<lockable>(self);
    )
SERIALIZABLE_INIT()

#endif // TRIXY_LOCKER_SERIALIZATION_HPP
