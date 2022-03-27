#ifndef VECTOR_LOCKER_HPP
#define VECTOR_LOCKER_HPP

#include <utility> // move, forward

#include "BaseLocker.hpp"
#include "Trixy/Detail/TrixyMeta.hpp"

#include "Trixy/Detail/MacroScope.hpp"

namespace trixy
{

template <class Tensor>
using VectorLocker = Locker<Tensor, LockerType::vector>;

template <class Tensor>
class Locker<Tensor, LockerType::vector> : protected Tensor
{
protected:
    using require = Tensor;

public:
    using typename require::type;

    using typename require::size_type;
    using typename require::precision_type;

    using typename require::pointer;
    using typename require::const_pointer;

public:
    // We MUST define explicit copy and move constructors
    // to prevent EATING args by constructor with perfect forwarding
    template <typename... Args,
        typename = TRIXY_ENABLE(meta::is_not_base_of<meta::decay_t<Args>, Locker>...),
        typename = TRIXY_ENABLE(std::is_constructible<Tensor, Args...>)>
    explicit Locker(Args&&... args) : Tensor(std::forward<Args>(args)...) {}

    // operator= for copy and move Locker object will not implicit generate
    Locker(const Locker& vector) : Tensor(vector) {}
    Locker(Locker&& vector) noexcept : Tensor(std::move(vector)) {}

    Locker(const Tensor& vector) : Tensor(vector) {}
    Locker(Tensor&& vector) noexcept : Tensor(std::move(vector)) {}

    ~Locker() = default;

    const Tensor& base() const noexcept
    { return static_cast<const Tensor&>(*this); }

public:
    using require::operator();

    using require::copy;
    using require::size;

    using require::fill;
    using require::apply;

    using require::dot;
    using require::add;
    using require::sub;
    using require::join;

    using require::data;
};

} // namespace trixy

#include "Trixy/Detail/MacroUnscope.hpp"

#endif // VECTOR_LOCKER_HPP
