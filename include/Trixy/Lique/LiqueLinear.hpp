#ifndef LIQUE_LINEAR_HPP
#define LIQUE_LINEAR_HPP

#include <cstddef> // size_t

#include "Detail/LiqueMeta.hpp"

namespace trixy
{

namespace lique
{

template <typename Precision>
class Linear
{
public:
    using size_type      = std::size_t;
    using precision_type = Precision;

public:
    template <class Vector1, class Vector2, class Matrix,
              typename = meta::enable_for_vector_t<Vector1>,
              typename = meta::enable_for_vector_t<Vector2>,
              typename = meta::enable_for_matrix_t<Matrix>>
    void dot(
        Vector1& buff,
        const Vector2& row_vector,
        const Matrix& matrix) const noexcept
    {
        precision_type temp;

        buff.fill(0.);

        for(size_type j = 0; j < row_vector.size(); ++j)
        {
            temp = row_vector(j);
            for(size_type i = 0; i < buff.size(); ++i)
               buff(i) += temp * matrix(j, i);
        }
    }

    template <class Vector1, class Vector2, class Matrix,
              typename = meta::enable_for_vector_t<Vector1>,
              typename = meta::enable_for_vector_t<Vector2>,
              typename = meta::enable_for_matrix_t<Matrix>>
    void dot(
        Vector1& buff,
        const Matrix& matrix,
        const Vector2& col_vector) const noexcept
    {
        buff.fill(0.);

        for(size_type i = 0; i < buff.size(); ++i)
            for(size_type j = 0; j < col_vector.size(); ++j)
                buff(i) += matrix(i, j) * col_vector(j);
    }

    template <class Vector1, class Vector2, class Matrix,
              typename = meta::enable_for_vector_t<Vector1>,
              typename = meta::enable_for_vector_t<Vector2>,
              typename = meta::enable_for_matrix_t<Matrix>>
    void tensordot(
        Matrix& buff2,
        const Vector1& col_vector,
        const Vector2& row_vector) const noexcept
    {
        for(size_type i = 0; i < col_vector.size(); ++i)
            for(size_type j = 0; j < row_vector.size(); ++j)
                buff2(i, j) = row_vector(j) * col_vector(i);
    }

    template <class Vector, class Matrix,
              typename = meta::enable_for_vector_t<Vector> ,
              typename = meta::enable_for_matrix_t<Matrix>>
    Vector dot(
        const Vector& row_vector,
        const Matrix& matrix) const
    {
        Vector buff(matrix.shape().col());

        dot(buff, row_vector, matrix);

        return buff;
    }

    template <class Vector, class Matrix,
              typename = meta::enable_for_vector_t<Vector>,
              typename = meta::enable_for_matrix_t<Matrix>>
    Vector dot(
        const Matrix& matrix,
        const Vector& col_vector) const
    {
        Vector buff(matrix.shape().row());

        dot(buff, matrix, col_vector);

        return buff;
    }

    template <class Matrix, class Vector,
              typename = meta::enable_for_matrix_t<Matrix>,
              typename = meta::enable_for_vector_t<Vector>>
    Matrix tensordot(
        const Vector& col_vector,
        const Vector& row_vector) const
    {
        Matrix buff2(col_vector.size(), row_vector.size());

        tensordot(buff2, col_vector, row_vector);

        return buff2;
    }

    template <class Tensor1, class Tensor2,
              typename = meta::enable_for_tensor_t<Tensor1>,
              typename = meta::enable_for_tensor_t<Tensor2>>
    void add(
        Tensor1& buff,
        const Tensor2& tensor) const noexcept
    {
        for(size_type i = 0; i < buff.size(); ++i)
            buff(i) += tensor(i);
    }

    template <class Tensor1, class Tensor2, class Tensor3,
              typename = meta::enable_for_tensor_t<Tensor1>,
              typename = meta::enable_for_tensor_t<Tensor2>,
              typename = meta::enable_for_tensor_t<Tensor3>>
    void add(
        Tensor1& buff,
        const Tensor2& lhs,
        const Tensor3& rhs) const noexcept
    {
        for(size_type i = 0; i < buff.size(); ++i)
            buff(i) = lhs(i) + rhs(i);
    }

    template <class Tensor1, class Tensor2,
              typename = meta::enable_for_tensor_t<Tensor1>,
              typename = meta::enable_for_tensor_t<Tensor2>>
    void sub(
        Tensor1& buff,
        const Tensor2& tensor) const noexcept
    {
        for(size_type i = 0; i < buff.size(); ++i)
            buff(i) -= tensor(i);
    }

    template <class Tensor1, class Tensor2, class Tensor3,
              typename = meta::enable_for_tensor_t<Tensor1>,
              typename = meta::enable_for_tensor_t<Tensor2>,
              typename = meta::enable_for_tensor_t<Tensor3>>
    void sub(
        Tensor1& buff,
        const Tensor2& lhs,
        const Tensor3& rhs) const noexcept
    {
        for(size_type i = 0; i < buff.size(); ++i)
            buff(i) = lhs(i) - rhs(i);
    }

    template <class Tensor1, class Tensor2,
              typename = meta::enable_for_tensor_t<Tensor1>,
              typename = meta::enable_for_tensor_t<Tensor2>>
    void mul(
        Tensor1& buff,
        const Tensor2& tensor) const noexcept
    {
        for(size_type i = 0; i < buff.size(); ++i)
            buff(i) *= tensor(i);
    }

    template <class Tensor1, class Tensor2, class Tensor3,
              typename = meta::enable_for_tensor_t<Tensor1>,
              typename = meta::enable_for_tensor_t<Tensor2>,
              typename = meta::enable_for_tensor_t<Tensor3>>
    void mul(
        Tensor1& buff,
        const Tensor2& lhs,
        const Tensor3& rhs) const noexcept
    {
        for(size_type i = 0; i < buff.size(); ++i)
            buff(i) = lhs(i) * rhs(i);
    }

    template <class Tensor1,
              typename = meta::enable_for_tensor_t<Tensor1>>
    void join(
        Tensor1& buff,
        precision_type value) const noexcept
    {
        for(size_type i = 0; i < buff.size(); ++i)
            buff(i) *= value;
    }

    template <class Tensor1, class Tensor2,
              typename = meta::enable_for_tensor_t<Tensor1>,
              typename = meta::enable_for_tensor_t<Tensor2>>
    void join(
        Tensor1& buff,
        precision_type value,
        const Tensor2& tensor) const noexcept
    {
        for(size_type i = 0; i < buff.size(); ++i)
            buff(i) = value * tensor(i);
    }

    template <class Tensor, class Function,
              typename = meta::enable_for_tensor_t<Tensor>>
    void apply(
        Tensor& buff,
        Function func) const noexcept
    {
        for(size_type i = 0; i < buff.size(); ++i)
            buff(i) = func(buff(i));
    }

    template <class Tensor1, class Tensor2, class Function,
              typename = meta::enable_for_tensor_t<Tensor1>,
              typename = meta::enable_for_tensor_t<Tensor2>>
    void apply(
        Tensor1& buff,
        Function func,
        const Tensor2& tensor) const noexcept
    {
        for(size_type i = 0; i < buff.size(); ++i)
            buff(i) = func(tensor(i));
    }

    template <class Tensor, class Function,
              typename = meta::enable_for_tensor_t<Tensor>>
    void for_each(
        Tensor& tensor,
        Function func) const noexcept
    {
        for(size_type i = 0; i < tensor.size(); ++i)
            func(tensor(i));
    }
};

} // namespace lique

} // namespace trixy

#endif // LIQUE_LINEAR_HPP
