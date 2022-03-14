#ifndef TRIXY_META_HPP
#define TRIXY_META_HPP

#include <utility> // declval
#include <type_traits> // enable_if, is_arithmetic, is_same, conditional, true_type, false_type

namespace trixy
{

namespace meta
{

template <bool condition, typename T = void>
using enable_if_t = typename std::enable_if<condition, T>::type;

template <typename T>
using decay_t = typename std::decay<T>::type;

template <bool condition, typename if_true, typename if_false>
using conditional_t = typename std::conditional<condition, if_true, if_false>::type;

template <class B, class D>
struct is_not_base_of :
    std::integral_constant<bool, !std::is_base_of<B, D>::value> {};

template <class...> struct conjunction : std::true_type {};
template <class B1> struct conjunction<B1> : B1 {};
template <class B1, class... Bn>
struct conjunction<B1, Bn...>
    : conditional_t<bool(B1::value), conjunction<Bn...>, B1> {};

template <class...> struct disjunction : std::false_type {};
template <class B1> struct disjunction<B1> : B1 {};
template <class B1, class... Bn>
struct disjunction<B1, Bn...>
    : conditional_t<bool(B1::value), B1, disjunction<Bn...>> {};

template <class T, template <class> class... Bn>
struct has_true : disjunction<Bn<T>...> {};

template <bool condition, typename T = void>
struct select_for : std::false_type
{
private:
    using std::false_type::type;
};

template <typename T>
struct select_for<true, T> : std::true_type
{
    using type = T;
};

template <class C, typename Ret = void, typename... Args>
struct is_callable
{
private:
    template <class U>
    static auto check(U* p) ->
    enable_if_t<
        std::is_same<decltype((*p)(std::declval<Args>()...)), Ret>::value,
        std::true_type
        >;

    template <class>
    static std::false_type check(...);

public:
    static constexpr bool value = decltype(check<C>(nullptr))::value;
};

template <class C, typename Ret = void, typename... Args>
struct use_for_callable : std::enable_if<is_callable<C, Ret, Args...>::value, int> {};

template <class T, class... Tn>
struct is_same_all: conjunction<std::is_same<T, Tn>...> {};

template <typename T> struct enable_for_arithmetic : std::enable_if<std::is_arithmetic<T>::value> {};
template <typename T> using enable_for_arithmetic_t = typename enable_for_arithmetic<T>::type;

template <class C, typename Ret = void, typename... Args>
using use_for_callable_t = typename use_for_callable<C, Ret, Args...>::type;

template <typename T> struct use_for_arithmetic : std::enable_if<std::is_arithmetic<T>::value, int> {};
template <typename T> using use_for_arithmetic_t = typename use_for_arithmetic<T>::type;

} // namespace meta

} // namespace trixy

#endif // TRIXY_NET_META_HPP
