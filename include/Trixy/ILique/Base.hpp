#ifndef TRIXY_ILIQUE_BASE_HPP
#define TRIXY_ILIQUE_BASE_HPP

#include <cstddef> // size_t

#include <Trixy/Detail/TrixyMeta.hpp>

namespace trixy
{

namespace ilique
{

template <typename tensor_type,
          template <typename, typename...> class Derived,
          typename Precision, typename... Pack>
class ITensor;

template <template <typename, typename...> class Derived,
          typename Precision, typename... Pack>
class ITensorBase
{
public:
    using Tensor            = Derived<Precision, Pack...>;

public:
    using size_type         = std::size_t;
    using precision_type    = Precision;

    using pointer           = Precision*;
    using const_pointer     = const Precision*;

    using reference         = Precision&;
    using const_reference   = const Precision&;

private:
    Tensor& self() noexcept
    { return *static_cast<Tensor*>(this); }

    const Tensor& self() const noexcept
    { return *static_cast<const Tensor*>(this); }

public:
    Tensor& copy(const Tensor& tensor) noexcept { return self().copy(tensor); }

    Tensor& fill(Precision value) noexcept { return self().fill(value); }

    template <class Generator, trixy::meta::as_callable_t<Generator> = 0>
    Tensor& fill(Generator gen) noexcept { return self().fill(gen); }

    size_type size() const noexcept { return self().size(); }

    template <class Function>
    Tensor  apply(Function func) const { return self().apply(func); }

    template <class Function>
    Tensor& apply(Function func) noexcept { return self().apply(func); }

    template <class Function>
    Tensor& apply(Function func, const Tensor& tensor) noexcept
    { return self().apply(func, tensor); }

    template <class Function>
    Tensor& apply(Function func, const_pointer src) noexcept
    { return self().apply(func, src); }

    Tensor  mul(const Tensor& tensor) const { return self().mul(tensor); }
    Tensor& mul(const Tensor& tensor) noexcept { return self().mul(tensor); }

    Tensor& mul(const Tensor& lhs, const Tensor& rhs) noexcept
    { return self().mul(lhs, rhs); }

    Tensor  join(Precision value) const { return self().join(value); }
    Tensor& join(Precision value) noexcept { return self().join(value); }

    Tensor& join(Precision value, const Tensor& tensor) noexcept
    { return self().join(value, tensor); }

    Tensor  add(const Tensor& tensor) const { return self().add(tensor); }
    Tensor& add(const Tensor& tensor) noexcept { return self().add(tensor); }

    Tensor& add(const Tensor& lhs, const Tensor& rhs) noexcept
    { return self().add(lhs, rhs); }

    Tensor  sub(const Tensor& tensor) const { return self().sub(tensor); }
    Tensor& sub(const Tensor& tensor) noexcept { return self().sub(tensor); }

    Tensor& sub(const Tensor& lhs, const Tensor& rhs) noexcept
    { return self().sub(lhs, rhs); }

    pointer data() noexcept { return self().data(); }
    const_pointer data() const noexcept { return self().data(); }
};

} // namespace ilique

} // namespace trixy

#endif // TRIXY_ILIQUE_BASE_HPP
