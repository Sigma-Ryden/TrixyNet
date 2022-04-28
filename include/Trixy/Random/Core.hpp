#ifndef TRIXY_RANDOM_HPP
#define TRIXY_RANDOM_HPP

#include <cstddef> // size_t
#include <ctime> // time
#include <random> // srand, rand

#include <Trixy/Detail/TrixyMeta.hpp>

namespace trixy
{

struct RandomType
{
    struct Integral { using type = Integral; };
    struct Floating { using type = Floating; };
};

namespace meta
{

template <typename> struct is_integral_random_type : std::false_type {};
template <> struct is_integral_random_type<RandomType::Integral> : std::true_type {};

template <typename> struct is_floating_random_type : std::false_type {};
template <> struct is_floating_random_type<RandomType::Floating> : std::true_type {};

} // namespace meta

template <typename random_type, typename Generator = int (*)(), typename enable = void>
class Random;

template <typename random_type, typename Generator>
class Random<random_type, Generator, meta::when<meta::is_callable<Generator>::value>>
{
public:
    using integral_type = long long;
    using floating_type = double;

    using size_type     = std::size_t;

private:
    Generator generator_;

public:
    Random() : generator_(static_cast<size_type>(std::time(nullptr))) {}
    Random(size_type seed) : generator_(seed) {}

    void seed(size_type seed)
    { generator_.seed(seed); }

    template <typename U = random_type,
              meta::as<meta::is_integral_random_type<U>::value> = 0>
    integral_type operator() () noexcept
    {
        return static_cast<integral_type>(generator_());
    }

    template <typename U = random_type,
              meta::as<meta::is_integral_random_type<U>::value> = 0>
    integral_type operator() (integral_type min, integral_type max) noexcept
    {
        return (*this)() % (max - min + 1) + min;
    }

    template <typename U = random_type,
              meta::as<meta::is_floating_random_type<U>::value> = 0>
    floating_type operator() () noexcept
    {
        return static_cast<floating_type>(generator_()) / static_cast<floating_type>(generator_.max());
    }

    template <typename U = random_type,
              meta::as<meta::is_floating_random_type<U>::value> = 0>
    floating_type operator() (floating_type min, floating_type max) noexcept
    {
        return (max - min) * (*this)() + min;
    }
};

template <typename random_type>
class Random<random_type>
{
public:
    using integral_type = long long;
    using floating_type = double;

    using size_type  = std::size_t;

private:
    using Generator = int (*)();

private:
    Generator generator_;

public:
    Random() : generator_(std::rand)
    { std::srand(static_cast<unsigned>(std::time(nullptr))); }

    Random(size_type seed) : generator_(std::rand)
    { std::srand(seed); }

    void seed(size_type seed)
    { std::srand(seed); }

    template <typename U = random_type,
              meta::as<meta::is_integral_random_type<U>::value> = 0>
    integral_type operator() () noexcept
    {
        return static_cast<integral_type>(generator_());
    }

    template <typename U = random_type,
              meta::as<meta::is_integral_random_type<U>::value> = 0>
    integral_type operator() (integral_type min, integral_type max) noexcept
    {
        return (*this)() % (max - min + 1) + min;
    }

    template <typename U = random_type,
              meta::as<meta::is_floating_random_type<U>::value> = 0>
    floating_type operator() () noexcept
    {
        return static_cast<floating_type>(generator_()) / static_cast<floating_type>(RAND_MAX);
    }

    template <typename U = random_type,
              meta::as<meta::is_floating_random_type<U>::value> = 0>
    floating_type operator() (floating_type min, floating_type max) noexcept
    {
        return (max - min) * (*this)() + min;
    }
};

template <typename Generator = int (*)()>
using RandomIntegral = Random<RandomType::Integral, Generator>;

template <typename Generator = int (*)()>
using RandomFloating = Random<RandomType::Floating, Generator>;

} // namespace trixy

#endif // TRIXY_RANDOM_HPP
