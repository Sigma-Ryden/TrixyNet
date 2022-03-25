#ifndef MATRIX_LOCKER_HPP
#define MATRIX_LOCKER_HPP

#include <utility> // move, forward

#include "BaseLocker.hpp"
#include "Trixy/Detail/TrixyMeta.hpp"

#include "Trixy/Detail/MacroScope.hpp"

namespace trixy
{

template <class Tensor>
using MatrixLocker = Locker<Tensor, LockerType::matrix>;

template <class Tensor>
class Locker<Tensor, LockerType::matrix> : protected Tensor
{
protected:
    using require        = Tensor;

public:
    using type           = typename Tensor::type;

    using size_type      = typename Tensor::size_type;
    using precision_type = typename Tensor::precision_type;

    using pointer        = typename Tensor::pointer;
    using const_pointer  = typename Tensor::const_pointer;

    using Shape          = typename Tensor::Shape;

public:
    // We MUST define explicit copy and move constructors
    // to prevent EATING args by constructor with perfect forwarding
    template <typename... Args,
        typename = TRIXY_ENABLE(meta::is_not_base_of<meta::decay_t<Args>, Locker>...),
        typename = TRIXY_ENABLE(std::is_constructible<Tensor, Args...>)>
    explicit Locker(Args&&... args) : Tensor(std::forward<Args>(args)...) {}

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

    using require::copy;
    using require::size;
    using require::shape;

    using require::fill;
    using require::apply;

    using require::dot;

    using require::add;
    using require::sub;
    using require::join;

    using require::transpose;
    using require::inverse;

    using require::data;
};

} // namespace trixy

#include "Trixy/Detail/MacroUnscope.hpp"

#endif // MATRIX_LOCKER_HPP
