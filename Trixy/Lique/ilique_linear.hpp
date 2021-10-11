#ifndef ILIQUE_LINEAR_HPP
#define ILIQUE_LINEAR_HPP

#include <cstddef>

namespace ilique
{

template <class Matrix, class Vector>
class ILinear
{
protected:
    virtual ~ILinear() {}

public:
    virtual Vector get(
        const Matrix& matrix, std::size_t row_number) const = 0;
    virtual Vector dot(
        const Vector& vector, const Matrix& matrix,
        bool transpose_dot_matrix = false) const = 0;

    virtual Matrix tensordot(
        const Vector& left_side_vector, const Vector& right_side_vector,
        bool return_transpose_matrix = false) const = 0;
};

} // namespace ilique

#endif // ILIQUE_LINEAR_HPP
