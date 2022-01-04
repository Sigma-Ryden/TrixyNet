#ifndef LIQUE_LINEAR_HPP
#define LIQUE_LINEAR_HPP

#include <cstddef> // size_t
#include <type_traits> // enable_if, is_arithmetic

#include "Trixy/Lique/Detail/macro_scope.hpp"

namespace lique
{

template <template <typename, typename...> class Vector,
          template <typename, typename...> class Matrix,
          typename Precision,
          typename enable = void, typename... Args>
class Linear;

} // namespace lique

namespace lique
{

LIQUE_LINEAR_TPL_DECLARATION
class LIQUE_LINEAR_TPL
{
public:
    using Tensor1D  = Vector<Precision, Args...>;
    using Tensor2D  = Matrix<Precision, Args...>;
    using size_type = std::size_t;

public:
    void dot(Tensor1D& buff,
             const Tensor1D& row_vector,
             const Tensor2D& matrix) const noexcept;

    void dot(Tensor1D& buff,
             const Tensor2D& matrix,
             const Tensor1D& col_vector) const noexcept;

    void dottranspose(Tensor1D& buff,
                      const Tensor1D& row_vector,
                      const Tensor2D& matrix) const noexcept;

    void tensordot(Tensor2D& buff,
                   const Tensor1D& col_vector,
                   const Tensor1D& row_vector) const noexcept;

    Tensor1D dot(const Tensor1D& row_vector,
                 const Tensor2D& matrix) const;

    Tensor1D dot(const Tensor2D& matrix,
                 const Tensor1D& col_vector) const;

    Tensor2D tensordot(const Tensor1D& col_vector,
                       const Tensor1D& row_vector) const;

    Tensor1D reshape(const Tensor2D& matrix) const;
    Tensor2D reshape(const Tensor1D& vector, size_type row, size_type col) const;
};

LIQUE_LINEAR_TPL_DECLARATION
void LIQUE_LINEAR_TPL::dot(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& row_vector,
    const Matrix<Precision, Args...>& matrix) const noexcept
{
    Precision result;
    for(size_type i = 0; i < matrix.size().col(); ++i)
    {
        result = 0.;
        for(size_type j = 0; j < row_vector.size(); ++j)
           result += row_vector(j) * matrix(j, i);

        buff(i) = result;
    }
}

LIQUE_LINEAR_TPL_DECLARATION
void LIQUE_LINEAR_TPL::dot(
    Vector<Precision, Args...>& buff,
    const Matrix<Precision, Args...>& matrix,
    const Vector<Precision, Args...>& col_vector) const noexcept
{
    Precision result;
    for(size_type i = 0; i < buff.size(); ++i)
    {
        result = 0.;
        for(size_type j = 0; j < col_vector.size(); ++j)
            result += matrix(i, j) * col_vector(j);

        buff(i) = result;
    }
}

LIQUE_LINEAR_TPL_DECLARATION
void LIQUE_LINEAR_TPL::dottranspose(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& row_vector,
    const Matrix<Precision, Args...>& matrix) const noexcept
{
    Precision result;
    for(size_type i = 0; i < buff.size(); ++i)
    {
        result = 0.;
        for(size_type j = 0; j < row_vector.size(); ++j)
            result += row_vector(j) * matrix(i, j);

        buff(i) = result;
    }
}

LIQUE_LINEAR_TPL_DECLARATION
void LIQUE_LINEAR_TPL::tensordot(
    Matrix<Precision, Args...>& buff,
    const Vector<Precision, Args...>& col_vector,
    const Vector<Precision, Args...>& row_vector) const noexcept
{
    for(size_type i = 0; i < col_vector.size(); ++i)
        for(size_type j = 0; j < row_vector.size(); ++j)
            buff(i, j) = row_vector(j) * col_vector(i);
}

LIQUE_LINEAR_TPL_DECLARATION
Vector<Precision, Args...> LIQUE_LINEAR_TPL::dot(
    const Vector<Precision, Args...>& row_vector,
    const Matrix<Precision, Args...>& matrix) const
{
    Tensor1D buff(matrix.size().col());

    Precision result;
    for(size_type i = 0; i < buff.size(); ++i)
    {
        result = 0.;
        for(size_type j = 0; j < row_vector.size(); ++j)
           result += row_vector(j) * matrix(j, i);

        buff(i) = result;
    }

    return buff;
}

LIQUE_LINEAR_TPL_DECLARATION
Vector<Precision, Args...> LIQUE_LINEAR_TPL::dot(
    const Matrix<Precision, Args...>& matrix,
    const Vector<Precision, Args...>& col_vector) const
{
    Tensor1D buff(matrix.size().row());

    Precision result;
    for(size_type i = 0; i < buff.size(); ++i)
    {
        result = 0.;
        for(size_type j = 0; j < col_vector.size(); ++j)
            result += matrix(i, j) * col_vector(j);

        buff(i) = result;
    }

    return buff;
}

LIQUE_LINEAR_TPL_DECLARATION
Matrix<Precision, Args...> LIQUE_LINEAR_TPL::tensordot(
    const Vector<Precision, Args...>& col_vector,
    const Vector<Precision, Args...>& row_vector) const
{
    Tensor2D buff(col_vector.size(), row_vector.size());

    for(size_type i = 0; i < col_vector.size(); ++i)
        for(size_type j = 0; j < row_vector.size(); ++j)
            buff(i, j) = col_vector(i) * row_vector(j);

    return buff;
}

LIQUE_LINEAR_TPL_DECLARATION
Vector<Precision, Args...> LIQUE_LINEAR_TPL::reshape(
    const Matrix<Precision, Args...>& matrix) const
{
    Tensor1D vector(matrix.size().row() * matrix.size().col());

    for(size_type i = 0, k = 0; i < matrix.size().row(); ++i)
        for(size_type j = 0; j < matrix.size().col(); ++j, ++k)
            vector(k) = matrix(i, j);

    return vector;
}

LIQUE_LINEAR_TPL_DECLARATION
Matrix<Precision, Args...> LIQUE_LINEAR_TPL::reshape(
    const Vector<Precision, Args...>& vector,
    size_type row, size_type col) const
{
    Tensor2D matrix(row, col);

    for(size_type i = 0, k = 0; i < row; ++i)
        for(size_type j = 0; j < col; ++j, ++k)
            matrix(i, j) = vector(k);

    return matrix;
}

} // namespace lique

#include "Trixy/Lique/Detail/macro_unscope.hpp"

#endif // LIQUE_LINEAR_HPP
