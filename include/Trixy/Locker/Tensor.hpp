#ifndef TRIXY_LOCKER_TENSOR_HPP
#define TRIXY_LOCKER_TENSOR_HPP

#include <utility> // move, forward

#include <Trixy/Locker/Base.hpp>
#include <Trixy/Detail/TrixyMeta.hpp>

#include <Trixy/Detail/MacroScope.hpp>

namespace trixy
{

template <class Tensor>
using TensorLocker = Locker<Tensor, LockerType::tensor>;

template <class Tensor>
class Locker<Tensor, LockerType::tensor> : protected Tensor
{
protected:
    using require = Tensor;

public:
    using typename require::size_type;
    using typename require::precision_type;

    using typename require::pointer;
    using typename require::const_pointer;

    //using typename require::Shape; // deprecated

public:
    template <typename U = Tensor,
              meta::require<std::is_constructible<U>::value> = 0>
    Locker() : Tensor() {}

    // We MUST define explicit copy and move constructors
    // to prevent EATING args by constructor with perfect forwarding
    template <typename T, typename... Tn,
        meta::require<not std::is_base_of<meta::decay_t<T>, Locker>::value and
                      std::is_constructible<Tensor, T, Tn...>::value> = 0>
    explicit Locker(T&& t, Tn&&... tn)
        : Tensor(std::forward<T>(t), std::forward<Tn>(tn)...) {}

    // operator= for copy and move Locker object will not implicit generate
    Locker(const Locker& tensor) : Tensor(tensor) {}
    Locker(Locker&& tensor) noexcept : Tensor(std::move(tensor)) {}

    Locker(const Tensor& tensor) : Tensor(tensor) {}
    Locker(Tensor&& tensor) noexcept : Tensor(std::move(tensor)) {}

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

    using require::add;
    using require::sub;
    using require::mul;
    using require::join;

    using require::data;
};

} // namespace trixy

#include <Trixy/Detail/MacroUnscope.hpp>

#endif // TRIXY_LOCKER_TENSOR_HPP
