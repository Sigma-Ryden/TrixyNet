#ifndef ILIQUE_LINEAR_HPP
#define ILIQUE_LINEAR_HPP

#include <cstddef> // size_t
#include <type_traits> // enable_if, is_arithmetic

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
              typename std::enable_if<std::is_arithmetic<Precision>::value>::type, Args...>
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
