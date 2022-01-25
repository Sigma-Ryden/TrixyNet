#ifndef ILIQUE_META_HPP
#define ILIQUE_META_HPP

#include <type_traits> // enable_if, is_arithmetic

namespace ilique
{

namespace meta
{

template <typename T>
struct enable_for_arithmetic : std::enable_if<std::is_arithmetic<T>::value> {};

template <typename T>
using enable_for_arithmetic_t = typename enable_for_arithmetic<T>::type;

} // namespace meta

} // namespace ilique

#endif // ILIQUE_META_HPP
