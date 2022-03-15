#ifndef ILIQUE_VECTOR_HPP
#define ILIQUE_VECTOR_HPP

#include <cstddef> // size_t

#include "Trixy/Lique/LiqueBaseTensor.hpp"

namespace trixy
{

namespace ilique
{

template <template <typename...> class Derived, typename Precision, typename... Args>
class IVector : public lique::TensorType::vector
{
public:
    using Tensor          = Derived<Precision, Args...>;

public:
    using size_type       = std::size_t;
    using precision_type  = Precision;

    using reference       = Precision&;
    using const_reference = const Precision&;

protected:
    virtual ~IVector() = default;

private:
    Tensor& self() { return *static_cast<Tensor*>(this); }
    const Tensor& self() const { return *static_cast<const Tensor*>(this); }

public:
    reference operator() (size_type i) noexcept { return self().operator()(i); }
    const_reference operator() (size_type i) const noexcept { return self().operator()(i); }

    void resize(size_type size) { self().resize(size); }
    void resize(size_type size, precision_type value) { self().resize(size, value); }

    precision_type dot(const Tensor& tensor) const { return self().dot(tensor); }
};

} // namespace ilique

} // namespace trixy

#endif // ILIQUE_VECTOR_HPP
