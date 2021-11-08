#ifndef LIQUE_LINEAR_HPP
#define LIQUE_LINEAR_HPP

#include <cstddef> // size_t

namespace lique
{

template <class Vector, class Matrix>
class Linear
{
public:
    using size_type = std::size_t;

public:
    Linear()                  = default;
    Linear(const Linear&)     = default;
    Linear(Linear&&) noexcept = default;
    ~Linear()                 = default;
    Linear& operator= (const Linear&)     = default;
    Linear& operator= (Linear&&) noexcept = default;

    Vector get(const Matrix& matrix,
               size_type row_number) const; // deprecated

    Vector& multiply(Vector& buff,
                     const Vector& lsh,
                     const Vector& rsh) const;

    Vector& dot(Vector& buff,
                const Vector& vector,
                const Matrix& matrix,
                bool transpose_dot_matrix = false) const;

    Matrix& tensordot(Matrix& buff,
                      const Vector& left_side_vector,
                      const Vector& right_side_vector) const;
};

template <class Vector, class Matrix>
Vector Linear<Vector, Matrix>::get(
    const Matrix& matrix,
    std::size_t row_number) const
{
    Vector new_vector(matrix.size().col());

    for(size_type i = 0; i < matrix.size().col(); ++i)
        new_vector(i) = matrix(row_number, i);

    return new_vector;
}
template <class Vector, class Matrix>
Vector& Linear<Vector, Matrix>::multiply(
    Vector& buff,
    const Vector& lsh,
    const Vector& rsh) const
{
    for(size_type i = 0; i < buff.size(); ++i)
        buff(i) = lsh(i) * rsh(i);

    return buff;
}

template <class Vector, class Matrix>
Vector& Linear<Vector, Matrix>::dot(
    Vector& buff,
    const Vector& vector,
    const Matrix& matrix,
    bool transpose_dot_matrix) const
{
    double result = 0.0;
    if(transpose_dot_matrix)
    {
        for(size_type i = 0; i < matrix.size().row(); ++i)
        {
            for(size_type j = 0; j <  matrix.size().col(); ++j)
                result += vector(j) * matrix(i, j);

            buff(i) = result;
            result = 0.0;
        }
    }
    else
    {
        for(size_type i = 0; i < matrix.size().col(); ++i)
        {
            for(size_type j = 0; j <  matrix.size().row(); ++j)
                result += vector(j) * matrix(j, i);

            buff(i) = result;
            result = 0.0;
        }
    }

    return buff;
}

template <class Vector, class Matrix>
Matrix& Linear<Vector, Matrix>::tensordot(
    Matrix& buff,
    const Vector& left_side_vector,
    const Vector& right_side_vector) const
{
    for(size_type i = 0; i < right_side_vector.size(); ++i)
        for(size_type j = 0; j < left_side_vector.size(); ++j)
            buff(i, j) = left_side_vector(j) * right_side_vector(i);

    return buff;
}

} // namespace lique

#endif // LIQUE_LINEAR_HPP
