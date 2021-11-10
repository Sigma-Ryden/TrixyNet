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

    void multiply(Vector& buff,
                  const Vector& lsh,
                  const Vector& rsh) const;

    void multiply(Matrix& buff,
                  const Matrix& lsh,
                  const Matrix& rsh) const;

    void dot(Vector& buff,
             const Vector& vector,
             const Matrix& matrix) const;

    void dottranspose(Vector& buff,
                      const Vector& vector,
                      const Matrix& matrix) const;

    void tensordot(Matrix& buff,
                   const Vector& lsh,
                   const Vector& rsh) const;
};

template <class Vector, class Matrix>
void Linear<Vector, Matrix>::multiply(
    Vector& buff, const Vector& lsh, const Vector& rsh) const
{
    for(size_type i = 0; i < buff.size(); ++i)
        buff(i) = lsh(i) * rsh(i);
}

template <class Vector, class Matrix>
void Linear<Vector, Matrix>::multiply(
    Matrix& buff, const Matrix& lsh, const Matrix& rsh) const
{
    for(size_type i = 0; i < buff.size().row(); ++i)
        for(size_type j = 0; j < buff.size().col(); ++j)
            buff(i, j) = lsh(i, j) * rsh(i, j);
}

template <class Vector, class Matrix>
void Linear<Vector, Matrix>::dot(
    Vector& buff, const Vector& vector, const Matrix& matrix) const
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
    Vector& buff, const Vector& vector, const Matrix& matrix) const
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
    Matrix& buff, const Vector& lsh, const Vector& rsh) const
{
    for(size_type i = 0; i < rsh.size(); ++i)
        for(size_type j = 0; j < lsh.size(); ++j)
            buff(i, j) = lsh(j) * rsh(i);
}

} // namespace lique

#endif // LIQUE_LINEAR_HPP
