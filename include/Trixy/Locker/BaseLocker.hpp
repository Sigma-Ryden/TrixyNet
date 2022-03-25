#ifndef BASE_LOCKER_HPP
#define BASE_LOCKER_HPP

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

#endif // BASE_LOCKER_HPP

