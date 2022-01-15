#ifndef LIQUE_META_HPP
#define LIQUE_META_HPP

#include <type_traits> // enable_if, is_arithmetic

namespace lique
{

namespace meta
{

template <typename T>
struct use_for_arithmetic : std::enable_if<std::is_arithmetic<T>::value> {};

template <typename T>
using use_for_arithmetic_t = typename use_for_arithmetic<T>::type;

template <typename T>
struct select_if_arithmetic : std::enable_if<std::is_arithmetic<T>::value, int> {};

template <typename T>
using select_if_arithmetic_t = typename select_if_arithmetic<T>::type;

} // namespace meta

} // namespace lique

#endif // LIQUE_META_HPP
