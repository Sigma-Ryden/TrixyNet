#ifndef LOCKER_META_HPP
#define LOCKER_META_HPP

#include <type_traits> // enable_if, true_type, false_type

#include "Trixy/Locker/BaseLocker.hpp"

namespace trixy
{

namespace meta
{

template <typename> struct is_locker : std::false_type {};
template <class Lockable>
struct is_locker<Locker<Lockable>> : std::true_type {};

} // namespace meta

} // namespace trixy

#endif // LOCKER_META_HPP
