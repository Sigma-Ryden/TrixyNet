#ifndef TRIXY_META_HPP
#define TRIXY_META_HPP

#include <utility> // declval
#include <type_traits>
// enable_if, is_arithmetic, is_same, conditional, true_type, false_type, remove_reference

#include <Trixy/Detail/MacroScope.hpp>

namespace trixy
{

namespace meta
{

template <bool condition, typename T = void>
using when = typename std::enable_if<condition, T>::type;

template <bool condition>
using require = when<condition, int>;

template <typename... Args>
using to_void = void;

template <typename T>
using remove_ptr = typename std::remove_pointer<T>::type;

template <typename T>
using remove_cv = typename std::remove_cv<T>::type;

template <typename T>
using remove_ref = typename std::remove_reference<T>::type;

template <typename T>
using decay = typename std::decay<T>::type;

template <typename...> struct scope;

template <> struct scope<>
{
public:
    template <int I> struct arg { using type = void; };
};

template <typename T, typename... Tn>
struct scope<T, Tn...>
{
public:
    template <int I, typename overload = void> struct arg
    {
        using type = typename scope<Tn...>::template arg<I - 1>::type;
    };

    template <typename overload> struct arg<0, overload>
    {
        using type = T;
    };

public:
    template <int I> using type = typename arg<I>::type;
};

template <bool condition, typename if_true, typename if_false>
using if_ = typename std::conditional<condition, if_true, if_false>::type;

template <class...> struct and_ : std::true_type {};
template <class B1> struct and_<B1> : B1 {};
template <class B1, class... Bn>
struct and_<B1, Bn...>
    : if_<bool(B1::value), and_<Bn...>, B1> {};

template <class...> struct or_ : std::false_type {};
template <class B1> struct or_<B1> : B1 {};
template <class B1, class... Bn>
struct or_<B1, Bn...>
    : if_<bool(B1::value), B1, or_<Bn...>> {};

template <typename... Bn> constexpr bool all() noexcept
{
    return and_<Bn...>::value;
}

template <typename... Bn> constexpr bool one() noexcept
{
    return or_<Bn...>::value;
}

template <class T, template <class> class... Bn>
struct has_true : or_<Bn<T>...> {};

TRIXY_HAS_FUNCTION_HELPER(type);

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
    decltype((*p)(std::declval<Args>()...), std::true_type{});

public:
    static constexpr bool value = decltype(check<F>(nullptr))::value;
};

template <class T, class... Tn>
struct is_same_all: and_<std::is_same<T, Tn>...> {};

namespace detail
{

template <typename T, typename = void>
struct deref_impl { using type = T; };

template <>
struct deref_impl<void*> { using type = void; };

template <typename T>
struct deref_impl<T, to_void<decltype(*std::declval<T>())>>
{
    using type = remove_ref<decltype(*std::declval<T>())>;
};

} // namespace detail

template <typename It>
using dereference = typename detail::deref_impl<It>::type;

} // namespace meta

} // namespace trixy

#include <Trixy/Detail/MacroUnscope.hpp>

#endif // TRIXY_NET_META_HPP
