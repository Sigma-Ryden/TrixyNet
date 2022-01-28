#ifndef LIQUE_LINEAR_HPP
#define LIQUE_LINEAR_HPP

#include <cstddef> // size_t

#include "Detail/LiqueMeta.hpp"

#include "Detail/MacroScope.hpp"

namespace trixy
{

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

    void tensordot(Tensor2D& buff2,
                   const Tensor1D& col_vector,
                   const Tensor1D& row_vector) const noexcept;

    Tensor1D dot(const Tensor1D& row_vector,
                 const Tensor2D& matrix) const;

    Tensor1D dot(const Tensor2D& matrix,
                 const Tensor1D& col_vector) const;

    Tensor2D tensordot(const Tensor1D& col_vector,
                       const Tensor1D& row_vector) const;
};

LIQUE_LINEAR_TPL_DECLARATION
void LIQUE_LINEAR_TPL::dot(
    Vector<Precision, Args...>& buff,
    const Vector<Precision, Args...>& row_vector,
    const Matrix<Precision, Args...>& matrix) const noexcept
{
    Precision temp;

    buff.fill(0.);

    for(size_type j = 0; j < row_vector.size(); ++j)
    {
        temp = row_vector(j);
        for(size_type i = 0; i < buff.size(); ++i)
           buff(i) += temp * matrix(j, i);
    }
}

LIQUE_LINEAR_TPL_DECLARATION
void LIQUE_LINEAR_TPL::dot(
    Vector<Precision, Args...>& buff,
    const Matrix<Precision, Args...>& matrix,
    const Vector<Precision, Args...>& col_vector) const noexcept
{
    buff.fill(0.);

    for(size_type i = 0; i < buff.size(); ++i)
        for(size_type j = 0; j < col_vector.size(); ++j)
            buff(i) += matrix(i, j) * col_vector(j);
}

LIQUE_LINEAR_TPL_DECLARATION
void LIQUE_LINEAR_TPL::tensordot(
    Matrix<Precision, Args...>& buff2,
    const Vector<Precision, Args...>& col_vector,
    const Vector<Precision, Args...>& row_vector) const noexcept
{
    for(size_type i = 0; i < col_vector.size(); ++i)
        for(size_type j = 0; j < row_vector.size(); ++j)
            buff2(i, j) = row_vector(j) * col_vector(i);
}

LIQUE_LINEAR_TPL_DECLARATION
Vector<Precision, Args...> LIQUE_LINEAR_TPL::dot(
    const Vector<Precision, Args...>& row_vector,
    const Matrix<Precision, Args...>& matrix) const
{
    Tensor1D buff(matrix.shape().col());

    dot(buff, row_vector, matrix);

    return buff;
}

LIQUE_LINEAR_TPL_DECLARATION
Vector<Precision, Args...> LIQUE_LINEAR_TPL::dot(
    const Matrix<Precision, Args...>& matrix,
    const Vector<Precision, Args...>& col_vector) const
{
    Tensor1D buff(matrix.shape().row());

    dot(buff, matrix, col_vector);

    return buff;
}

LIQUE_LINEAR_TPL_DECLARATION
Matrix<Precision, Args...> LIQUE_LINEAR_TPL::tensordot(
    const Vector<Precision, Args...>& col_vector,
    const Vector<Precision, Args...>& row_vector) const
{
    Tensor2D buff2(col_vector.size(), row_vector.size());

    tensordot(buff2, col_vector, row_vector);

    return buff2;
}

} // namespace lique

} // namespace trixy

#include "Detail/MacroUnscope.hpp"

#endif // LIQUE_LINEAR_HPP
