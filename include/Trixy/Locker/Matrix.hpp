#ifndef TRIXY_LOCKER_MATRIX_HPP
#define TRIXY_LOCKER_MATRIX_HPP

#include <utility> // move, forward

#include <Trixy/Locker/Base.hpp>
#include <Trixy/Detail/TrixyMeta.hpp>

#include <Trixy/Detail/MacroScope.hpp>

namespace trixy
{

namespace memory
{

template <class Tensor>
using MatrixLocker = Locker<Tensor, LockerType::matrix>;

template <class Tensor>
class Locker<Tensor, LockerType::matrix> : protected Tensor
{
protected:
    using require = Tensor;

public:
    using typename require::size_type;
    using typename require::precision_type;
    using typename require::value_type;

    using typename require::pointer;
    using typename require::const_pointer;

    using typename require::unified_range;

public:
    template <typename U = Tensor,
              trixy::meta::require<std::is_constructible<U>::value> = 0>
    Locker() : Tensor() {}

    // We MUST define explicit copy and move constructors
    // to prevent EATING args by constructor with perfect forwarding
    template <typename T, typename... Tn,
        trixy::meta::require<not std::is_base_of<trixy::meta::decay_t<T>, Locker>::value and
                             std::is_constructible<Tensor, T, Tn...>::value> = 0>
    explicit Locker(T&& t, Tn&&... tn)
        : Tensor(std::forward<T>(t), std::forward<Tn>(tn)...) {}

    // operator= for copy and move Locker object will not implicit generate
    Locker(const Locker& matrix) : Tensor(matrix) {}
    Locker(Locker&& matrix) noexcept : Tensor(std::move(matrix)) {}

    Locker(const Tensor& matrix) : Tensor(matrix) {}
    Locker(Tensor&& matrix) noexcept : Tensor(std::move(matrix)) {}

    ~Locker() = default;

    const Tensor& base() const noexcept
    { return static_cast<const Tensor&>(*this); }

public:
    using require::operator();
    using require::operator unified_range;

    using require::copy;

    using require::size;
    using require::shape;

    using require::fill;
    using require::apply;

    using require::add;
    using require::sub;
    using require::mul;
    using require::join;

    using require::data;
};

} // namespace memory

} // namespace trixy

#include <Trixy/Detail/MacroUnscope.hpp>

#endif // TRIXY_LOCKER_MATRIX_HPP
