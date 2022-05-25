#ifndef TRIXY_RANDOM_HPP
#define TRIXY_RANDOM_HPP

#include <cstddef> // size_t
#include <ctime> // time
#include <random> // srand, rand

#include <Trixy/Detail/TrixyMeta.hpp>

namespace trixy
{

namespace utility
{

struct RandomType
{
    template <typename T = long long,
              typename = meta::when<std::is_integral<T>::value>>
    struct Integral { using type = T; };

    template <typename T = double,
              typename = meta::when<std::is_floating_point<T>::value>>
    struct Floating { using type = T; };
};

} // namespace utility

namespace meta
{

template <typename>
struct is_integral_random_type : std::false_type {};
template <typename T>
struct is_integral_random_type<utility::RandomType::Integral<T>> : std::true_type {};

template <typename>
struct is_floating_random_type : std::false_type {};
template <typename T>
struct is_floating_random_type<utility::RandomType::Floating<T>> : std::true_type {};

} // namespace meta

namespace utility
{

class DefaultGenerator
{
public:
    using size_type = std::size_t;
    using Generator = int (*)();

public:
    DefaultGenerator() noexcept
    {
        std::srand(DefaultGenerator::seed());
    }

    DefaultGenerator(size_type seed) noexcept { std::srand(seed); }

    void seed(size_type seed) noexcept { std::srand(seed); }

    int operator() () noexcept { return std::rand(); }

    static std::size_t seed() noexcept
    {
        return static_cast<std::size_t>(std::time(nullptr));
    }

    static constexpr int min() noexcept { return 0; }
    static constexpr int max() noexcept { return RAND_MAX; }
};

template <typename RandomType, class Generator = DefaultGenerator, typename enable = void>
class Random;

template <typename RandomType, class Generator>
class Random<RandomType, Generator,
    trixy::meta::when<meta::is_integral_random_type<RandomType>::value and
               trixy::meta::is_callable<Generator>::value>>
{
public:
    using integral_type = typename RandomType::type;
    using size_type = std::size_t;

private:
    Generator gen;

public:
    Random() noexcept : gen(DefaultGenerator::seed()) {}
    Random(size_type seed) noexcept : gen(seed) {}

    void seed(size_type seed) noexcept { gen.seed(seed); }

    integral_type operator() () noexcept
    {
        return static_cast<integral_type>(gen());
    }

    integral_type operator() (integral_type min, integral_type max) noexcept
    {
        return (*this)() % (max - min + 1) + min;
    }
};

template <typename RandomType, class Generator>
class Random<RandomType, Generator,
    trixy::meta::when<meta::is_floating_random_type<RandomType>::value and
               trixy::meta::is_callable<Generator>::value>>
{
public:
    using floating_type = typename RandomType::type;
    using size_type = std::size_t;

private:
    Generator gen;

public:
    Random() noexcept : gen(DefaultGenerator::seed()) {}
    Random(size_type seed) noexcept : gen(seed) {}

    void seed(size_type seed) noexcept { gen.seed(seed); }

    floating_type operator() () noexcept
    {
        return static_cast<floating_type>(gen()) / static_cast<floating_type>(gen.max());
    }

    floating_type operator() (floating_type min, floating_type max) noexcept
    {
        return (max - min) * (*this)() + min;
    }
};

template <typename T = RandomType::Integral<>::type, class Generator = DefaultGenerator>
using RandomIntegral = Random<RandomType::Integral<T>, Generator>;

template <typename T = RandomType::Floating<>::type, class Generator = DefaultGenerator>
using RandomFloating = Random<RandomType::Floating<T>, Generator>;

} // namespace utility

} // namespace trixy

#endif // TRIXY_RANDOM_HPP
