#ifndef ILIQUE_LINEAR_HPP
#define ILIQUE_LINEAR_HPP

#include <cstddef> // size_t

namespace ilique
{

template <template <typename, typename...> class Tensor1D,
          template <typename, typename...> class Tensor2D,
          typename Precision,
          typename... Args>
class ILinear
{
protected:
    virtual ~ILinear() = default;

public:
    virtual void dot(Tensor1D<Precision, Args...>& buff,
                     const Tensor1D<Precision, Args...>& vector,
                     const Tensor2D<Precision, Args...>& matrix) const noexcept = 0;

    virtual void dottranspose(Tensor1D<Precision, Args...>& buff,
                              const Tensor1D<Precision, Args...>& vector,
                              const Tensor2D<Precision, Args...>& matrix) const noexcept = 0;

    virtual void tensordot(Tensor2D<Precision, Args...>& buff,
                           const Tensor1D<Precision, Args...>& col_vector,
                           const Tensor1D<Precision, Args...>& row_vector) const noexcept = 0;
};

} // namespace ilique

#endif // ILIQUE_LINEAR_HPP
