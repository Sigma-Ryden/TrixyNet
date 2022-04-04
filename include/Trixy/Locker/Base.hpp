#ifndef TRIXY_LOCKER_BASE_HPP
#define TRIXY_LOCKER_BASE_HPP

namespace trixy
{

struct LockerType
{
    struct container { using type = container; };
    struct vector { using type = vector; };
    struct matrix { using type = matrix; };
};

template <class Lockable, typename LockerType>
class Locker;

} // namespace trixy

#endif // TRIXY_LOCKER_BASE_HPP

