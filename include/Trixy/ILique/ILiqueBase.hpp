#ifndef ILIQUE_BASE_HPP
#define ILIQUE_BASE_HPP

#include <cstddef> // size_t

#include "Trixy/Detail/TrixyMeta.hpp"

namespace trixy
{

namespace ilique
{

template <template <typename...> class Derived, typename Precision, typename... Args>
class ITensor
{
public:
    using Tensor            = Derived<Precision, Args...>;

public:
    using size_type         = std::size_t;
    using precision_type    = Precision;

    using pointer           = Precision*;
    using const_pointer     = const Precision*;

    using reference         = Precision&;
    using const_reference   = const Precision&;

protected:
    virtual ~ITensor() = default;

private:
    Tensor& self() noexcept
    { return *static_cast<Tensor*>(this); }

    const Tensor& self() const noexcept
    { return *static_cast<const Tensor*>(this); }

public:
    Tensor& copy(const Tensor& tensor) noexcept { return self().copy(tensor); }

    Tensor& fill(Precision value) noexcept { return self().fill(value); }

    template <class Generator,
              trixy::meta::as_callable_t<Generator, precision_type> = 0>
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

    Tensor  multiply(const Tensor& tensor) const { return self().multiply(tensor); }
    Tensor& multiply(const Tensor& tensor) noexcept { return self().multiply(tensor); }

    Tensor& multiply(const Tensor& lhs, const Tensor& rhs) noexcept
    { return self().multiply(lhs, rhs); }

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
};

} // namespace ilique

} // namespace trixy

#endif // ILIQUE_BASE_HPP
