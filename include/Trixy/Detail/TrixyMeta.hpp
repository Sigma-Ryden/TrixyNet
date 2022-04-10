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

template <typename...> struct scope;

template <> struct scope<>
{
private:
    template <int I> struct as_impl
    {
        using type = void;
    };
};

template <typename T, typename... Tn>
struct scope<T, Tn...>
{
private:
    template <int I, typename overload = void> struct as_impl
    {
        using type = typename scope<Tn...>::template as<I - 1>::type;
    };

    template <typename overload> struct as_impl<0, overload>
    {
        using type = T;
    };

public:
    template <int I> using type = typename as_impl<I>::type;
};

template <typename T, typename = std::void_t<>>
struct has_type : std::false_type {};

template <typename T>
struct has_type<T, std::void_t<typename T::type>> : std::true_type {};

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

template <class F, typename... Args>
struct is_callable
{
private:
    template <class> static std::false_type check(...);

    template <class U> static auto check(U* p) ->
    decltype((*p)(std::declval<Args>()...), std::true_type());

public:
    static constexpr bool value = decltype(check<F>(nullptr))::value;
};

template <class F, typename... Args>
struct as_callable : std::enable_if<is_callable<F, Args...>::value, int> {};

template <class F, typename... Args>
using as_callable_t = typename as_callable<F, Args...>::type;

template <class T, class... Tn>
struct is_same_all: conjunction<std::is_same<T, Tn>...> {};

template <typename T> struct enable_for_arithmetic : std::enable_if<std::is_arithmetic<T>::value> {};
template <typename T> using enable_for_arithmetic_t = typename enable_for_arithmetic<T>::type;

template <typename T> struct as_arithmetic : std::enable_if<std::is_arithmetic<T>::value, int> {};
template <typename T> using as_arithmetic_t = typename as_arithmetic<T>::type;

} // namespace meta

} // namespace trixy

#endif // TRIXY_NET_META_HPP
