#ifndef TRIXY_CORE_HPP
#define TRIXY_CORE_HPP

#include <cstddef> // size_t

#include <Trixy/Base.hpp>

#include <Trixy/Container/Core.hpp>

#include <Trixy/Lique/Core.hpp>
#include <Trixy/ILique/Core.hpp>

#include <Trixy/Neuro/Core.hpp>

#include <Trixy/Locker/Core.hpp>
#include <Trixy/Require/Core.hpp>

#include <Trixy/Random/Core.hpp>

namespace trixy
{

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
