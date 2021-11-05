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
    virtual Tensor1D get(const Tensor2D& matrix,
                         size_type row_number) const = 0;

    virtual Tensor1D dot(const Tensor1D& vector,
                         const Tensor2D& matrix,
                         bool transpose_dot_matrix) const = 0;

    virtual Tensor2D tensordot(const Tensor1D& left_side_vector,
                               const Tensor1D& right_side_vector,
                               bool return_transpose_matrix) const = 0;
};

} // namespace ilique

#endif // ILIQUE_LINEAR_HPP
