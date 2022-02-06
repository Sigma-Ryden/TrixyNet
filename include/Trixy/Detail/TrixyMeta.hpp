#ifndef TRIXY_META_HPP
#define TRIXY_META_HPP

#include <utility> // declval
#include <type_traits> // enable_if, is_arithmetic, is_same, conditional, true_type, false_type

namespace trixy
{

namespace meta
{

template <class T, typename Ret = void, typename... Args>
struct is_callable
{
private:
    template <class U>
    static auto check(U* p) -> typename std::enable_if<
        std::is_same<decltype((*p)(std::declval<Args>()...)), Ret>::value, std::true_type>::type;

    template <class>
    static std::false_type check(...);

public:
    static constexpr bool value = decltype(check<T>(nullptr))::value;
};

template <class...> struct conjunction : std::true_type {};
template <class B1> struct conjunction<B1> : B1 {};
template <class B1, class... Bn>
struct conjunction<B1, Bn...> : std::conditional<bool(B1::value), conjunction<Bn...>, B1>::type {};

template <class...> struct disjunction : std::true_type {};
template <class B1> struct disjunction<B1> : B1 {};
template <class B1, class... Bn>
struct disjunction<B1, Bn...> : std::conditional<bool(B1::value), B1, disjunction<Bn...>>::type {};

template <class Class, template <class T> class... Bn>
struct has_true : disjunction<Bn<Class>...> {};

template <typename T> struct enable_for_arithmetic : std::enable_if<std::is_arithmetic<T>::value> {};
template <typename T> using enable_for_arithmetic_t = typename enable_for_arithmetic<T>::type;

template <typename T> struct use_for_arithmetic : std::enable_if<std::is_arithmetic<T>::value, int> {};
template <typename T> using use_for_arithmetic_t = typename use_for_arithmetic<T>::type;

template <bool condition, typename T>
struct select_for : std::enable_if<condition, T>
{
    static constexpr bool value = condition;
};

template <class T, class... Tn>
struct is_same_types: meta::conjunction<std::is_same<T, Tn>...> {};

template <bool condition, class T = void>
using enable_if_t = typename std::enable_if<condition, T>::type;

} // namespace meta

} // namespace trixy

#endif // TRIXY_NET_META_HPP
