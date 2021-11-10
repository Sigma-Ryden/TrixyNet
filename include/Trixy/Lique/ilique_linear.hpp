#ifndef ILIQUE_LINEAR_HPP
#define ILIQUE_LINEAR_HPP

#include <cstddef> // size_t

namespace ilique
{

template <class Tensor1D, class Tensor2D>
class ILinear
{
public:
    using size_type = std::size_t;

protected:
    virtual ~ILinear() = default;

public:
    virtual void multiply(Tensor1D& buff,
                          const Tensor1D& lsh,
                          const Tensor1D& rsh) const = 0;

    virtual void multiply(Tensor2D& buff,
                          const Tensor2D& lsh,
                          const Tensor2D& rsh) const = 0;

    virtual void dot(Tensor1D& buff,
                     const Tensor1D& vector,
                     const Tensor2D& matrix) const = 0;

    virtual void dottranspose(Tensor1D& buff,
                              const Tensor1D& vector,
                              const Tensor2D& matrix) const = 0;

    virtual void tensordot(Tensor2D& buff,
                           const Tensor1D& lsh,
                           const Tensor1D& rsh) const = 0;
};

} // namespace ilique

#endif // ILIQUE_LINEAR_HPP
