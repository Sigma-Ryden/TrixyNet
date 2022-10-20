#ifndef TRIXY_CORE_HPP
#define TRIXY_CORE_HPP

#include <cstddef> // size_t
#include <cstdint>
// size_t, int8_t, int16_t, int32_t, int64_t
// uint8_t, uint16_t, uint32_t, uint64_t

#include <Trixy/Base.hpp>

#include <Trixy/Container/Core.hpp>

#include <Trixy/Lique/Core.hpp>
#include <Trixy/ILique/Core.hpp>

#include <Trixy/Neuro/Core.hpp>

#include <Trixy/Locker/Core.hpp>
#include <Trixy/Require/Core.hpp>

#include <Trixy/Buffer/Core.hpp>

#include <Trixy/Random/Core.hpp>

namespace trixy
{

namespace let
{

using i8   = std::int8_t;
using i16  = std::int16_t;
using i32  = std::int32_t;
using i64  = std::int64_t;

using u8   = std::uint8_t;
using u16  = std::uint16_t;
using u32  = std::uint32_t;
using u64  = std::uint64_t;

using f32  = float;
using f64  = double;
using f128 = long double;

} // namespace let

// Special struct for types alias
template <typename Precision>
struct TypeSet
{
    template <typename T>
    using Container         = utility::Container<T>;

    using Vector            = lique::Vector<Precision>;
    using Matrix            = lique::Matrix<Precision>;
    using Tensor            = lique::Tensor<Precision>;

    using Linear            = lique::Linear<Precision>;

    using precision_type    = Precision;
    using size_type         = std::size_t;
};

} // namespace trixy

#endif // TRIXY_CORE_HPP
