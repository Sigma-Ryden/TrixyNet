#ifndef LIQUE_LINEAR_HPP
#define LIQUE_LINEAR_HPP

#include <cstddef> // size_t

namespace lique
{

template <class Matrix, class Vector>
class Linear
{
public:
    Linear() = default;
    Linear(const Linear&) = default;
    Linear(Linear&&) noexcept = default;
    Linear& operator= (const Linear&) = default;
    Linear& operator= (Linear&&) noexcept = default;
    ~Linear() = default;

    Vector get(
        const Matrix& matrix, std::size_t row_number) const; // deprecated
    Vector dot(
        const Vector& vector, const Matrix& matrix,
        bool transpose_dot_matrix = false) const;
    Matrix tensordot(
        const Vector& left_side_vector, const Vector& right_side_vector,
        bool return_transpose_matrix = false) const;
};

template <class Matrix, class Vector>
Vector Linear<Matrix, Vector>::get(const Matrix& matrix, std::size_t row_number) const
{
    Vector new_vector(matrix.size().col());

    for(std::size_t i = 0; i < matrix.size().col(); ++i)
        new_vector(i) = matrix(row_number, i);

    return new_vector;
}

template <class Matrix, class Vector>
Vector Linear<Matrix, Vector>::dot(
    const Vector& vector, const Matrix& matrix, bool transpose_dot_matrix) const
{
    double result = 0.0;
    if(transpose_dot_matrix)
    {
        Vector new_vector(matrix.size().row());

        for(std::size_t i = 0; i < matrix.size().row(); ++i)
        {
            for(std::size_t j = 0; j <  matrix.size().col(); ++j)
                result += vector(j) * matrix(i, j);

            new_vector(i) = result;
            result = 0.0;
        }

        return new_vector;
    }
    else
    {
        Vector new_vector(matrix.size().col());

        for(std::size_t i = 0; i < matrix.size().col(); ++i)
        {
            for(std::size_t j = 0; j <  matrix.size().row(); ++j)
                result += vector(j) * matrix(j, i);

            new_vector(i) = result;
            result = 0.0;
        }

        return new_vector;
    }
}

template <class Matrix, class Vector>
Matrix Linear<Matrix, Vector>::tensordot(
    const Vector& left_side_vector, const Vector& right_side_vector,
    bool return_transpose_matrix) const
{
    if(return_transpose_matrix)
    {
        Matrix new_matrix(left_side_vector.size(), right_side_vector.size());

        for(std::size_t i = 0; i < left_side_vector.size(); ++i)
            for(std::size_t j = 0; j < right_side_vector.size(); ++j)
                new_matrix(i, j) = left_side_vector(i) * right_side_vector(j);

        return new_matrix;
    }
    else
    {
        Matrix new_matrix(right_side_vector.size(), left_side_vector.size());

        for(std::size_t i = 0; i < right_side_vector.size(); ++i)
            for(std::size_t j = 0; j < left_side_vector.size(); ++j)
                new_matrix(i, j) = left_side_vector(j) * right_side_vector(i);

        return new_matrix;
    }
}

} // namespace lique

#endif // LIQUE_LINEAR_HPP
