#ifndef LIQUE_LINEAR_HPP
#define LIQUE_LINEAR_HPP

#include <cstddef> // size_t

namespace lique
{

template <template <typename, typename...> class Vector,
          template <typename, typename...> class Matrix,
          typename Precision,
          typename... Args>
class Linear
{
public:
    using size_type = std::size_t;

public:
    void dot(Vector<Precision, Args...>& buff,
             const Vector<Precision, Args...>& vector,
             const Matrix<Precision, Args...>& matrix) const noexcept;

    void dottranspose(Vector<Precision, Args...>& buff,
                      const Vector<Precision, Args...>& vector,
                      const Matrix<Precision, Args...>& matrix) const noexcept;

    void tensordot(Matrix<Precision, Args...>& buff,
                   const Vector<Precision, Args...>& col_vector,
                   const Vector<Precision, Args...>& row_vector) const noexcept;
};

template <template <typename, typename...> class Vector,
          template <typename, typename...> class Matrix,
          typename Precision,
          typename... Args>
void Linear<Vector, Matrix, Precision, Args...>::dot(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& vector,
    const Matrix<Precision, Args...>& matrix) const noexcept
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

template <template <typename, typename...> class Vector,
          template <typename, typename...> class Matrix,
          typename Precision,
          typename... Args>
void Linear<Vector, Matrix, Precision, Args...>::dottranspose(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& vector,
    const Matrix<Precision, Args...>& matrix) const noexcept
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

template <template <typename, typename...> class Vector,
          template <typename, typename...> class Matrix,
          typename Precision,
          typename... Args>
void Linear<Vector, Matrix, Precision, Args...>::tensordot(
    Matrix<Precision, Args...>& buff,
    const Vector<Precision, Args...>& col_vector,
    const Vector<Precision, Args...>& row_vector) const noexcept
{
    for(size_type i = 0; i < col_vector.size(); ++i)
        for(size_type j = 0; j < row_vector.size(); ++j)
            buff(i, j) = row_vector(j) * col_vector(i);
}

} // namespace lique

#endif // LIQUE_LINEAR_HPP
