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
    void dot(Vector& buff,
             const Vector& vector,
             const Matrix& matrix) const noexcept;

    void dottranspose(Vector& buff,
                      const Vector& vector,
                      const Matrix& matrix) const noexcept;

    void tensordot(Matrix& buff,
                   const Vector& lsh,
                   const Vector& rsh) const noexcept;
};

template <class Vector, class Matrix>
void Linear<Vector, Matrix>::dot(
    Vector& buff, const Vector& vector, const Matrix& matrix) const noexcept
{
    double result = 0.0;
    for(size_type i = 0; i < matrix.size().col(); ++i)
    {
        for(size_type j = 0; j <  matrix.size().row(); ++j)
            result += vector(j) * matrix(j, i);

        buff(i) = result;
        result = 0.0;
    }
}

template <class Vector, class Matrix>
void Linear<Vector, Matrix>::dottranspose(
    Vector& buff, const Vector& vector, const Matrix& matrix) const noexcept
{
    double result = 0.0;
    for(size_type i = 0; i < matrix.size().row(); ++i)
    {
        for(size_type j = 0; j <  matrix.size().col(); ++j)
            result += vector(j) * matrix(i, j);

        buff(i) = result;
        result = 0.0;
    }
}

template <class Vector, class Matrix>
void Linear<Vector, Matrix>::tensordot(
    Matrix& buff, const Vector& lsh, const Vector& rsh) const noexcept
{
    for(size_type i = 0; i < rsh.size(); ++i)
        for(size_type j = 0; j < lsh.size(); ++j)
            buff(i, j) = lsh(j) * rsh(i);
}

} // namespace lique

#endif // LIQUE_LINEAR_HPP
