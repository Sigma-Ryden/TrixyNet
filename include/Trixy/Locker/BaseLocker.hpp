#ifndef BASE_LOCKER_HPP
#define BASE_LOCKER_HPP

namespace trixy
{

struct LockerType
{
    struct container;
    struct vector;
    struct matrix;
};

template <class Lockable, typename locker_type, typename enable = void>
class Locker;

} // namespace trixy

#endif // BASE_LOCKER_HPP

