#ifndef ILIQUE_LINEAR_HPP
#define ILIQUE_LINEAR_HPP

#include <cstddef> // size_t

#include "Detail/ILiqueMeta.hpp"

namespace ilique
{

template <template <typename P, typename...> class Tensor1D,
          template <typename P, typename...> class Tensor2D,
          typename Precision,
          typename enable = void, typename... Args>
class ILinear;

} // namespace ilique

namespace ilique
{

template <template <typename P, typename...> class Tensor1D,
          template <typename P, typename...> class Tensor2D,
          typename Precision,
          typename... Args>
class ILinear<Tensor1D, Tensor2D, Precision,
              meta::use_for_arithmetic_t<Precision>, Args...>
{
protected:
    virtual ~ILinear() = default;

public:
    using size_type    = std::size_t;
    using TensorType1D = Tensor1D<Precision, Args...>;
    using TensorType2D = Tensor2D<Precision, Args...>;

public:
    virtual void dot(TensorType1D& buff,
                     const TensorType1D& row_vector,
                     const TensorType2D& matrix) const noexcept = 0;

    virtual void dot(TensorType1D& buff,
                     const TensorType2D& matrix,
                     const TensorType1D& col_vector) const noexcept = 0;

    virtual void tensordot(TensorType2D& buff,
                           const TensorType1D& col_vector,
                           const TensorType1D& row_vector) const noexcept = 0;

    virtual TensorType1D dot(const TensorType1D& row_vector,
                             const TensorType2D& matrix) const = 0;

    virtual TensorType1D dot(const TensorType2D& matrix,
                             const TensorType1D& col_vector) const = 0;

    virtual TensorType2D tensordot(const TensorType1D& col_vector,
                                   const TensorType1D& row_vector) const = 0;
};

} // namespace ilique

#endif // ILIQUE_LINEAR_HPP
