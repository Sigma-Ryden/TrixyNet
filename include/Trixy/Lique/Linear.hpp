#ifndef TRIXY_LIQUE_LINEAR_HPP
#define TRIXY_LIQUE_LINEAR_HPP

#include <cstddef> // size_t

#include <Trixy/Lique/Detail/FunctionDetail.hpp>

#include <Trixy/Lique/Detail/LiqueMeta.hpp>

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
    template <class Tensor, lique::meta::as_tensor<Tensor> = 0>
    auto first(Tensor& tensor) const noexcept -> decltype(tensor.data())
    {
        return tensor.data();
    }

    template <class Tensor, lique::meta::as_tensor<Tensor> = 0>
    auto last(Tensor& tensor) const noexcept -> decltype(tensor.data() + tensor.size())
    {
        return tensor.data() + tensor.size();
    }

    template <class Vector1, class Vector2, class Matrix,
              meta::as_vector<Vector1> = 0,
              meta::as_vector<Vector2> = 0,
              meta::as_matrix<Matrix> = 0>
    void dot(
        Vector1& result,
        const Vector2& row_vector,
        const Matrix& matrix) const noexcept
    {
        precision_type temp;

        detail::assign(first(result), last(result), detail::cpy(), precision_type(0.));

        for (size_type i = 0; i < row_vector.size(); ++i)
        {
            temp = row_vector(i);
            for (size_type j = 0; j < result.size(); ++j)
                result(j) += temp * matrix(i, j);
        }
    }

    template <class Vector1, class Vector2, class Matrix,
              meta::as_vector<Vector1> = 0,
              meta::as_vector<Vector2> = 0,
              meta::as_matrix<Matrix> = 0>
    void dot(
        Vector1& result,
        const Matrix& matrix,
        const Vector2& col_vector) const noexcept
    {
        detail::assign(first(result), last(result), detail::cpy(), precision_type(0.));

        for (size_type i = 0; i < result.size(); ++i)
            for (size_type j = 0; j < col_vector.size(); ++j)
                result(i) += matrix(i, j) * col_vector(j);
    }

    template <class Matrix1, class Matrix2, class Matrix3,
              meta::as_matrix<Matrix1> = 0,
              meta::as_matrix<Matrix2> = 0,
              meta::as_matrix<Matrix3> = 0>
    void dot(
        Matrix1& result,
        const Matrix2& lhs,
        const Matrix3& rhs) const noexcept
    {
        precision_type buff;
        for (size_type i = 0; i < lhs.shape().height; ++i)
        {
            for (size_type r = 0; r < lhs.shape().width; ++r)
            {
                buff = lhs(i, r);

                for (size_type j = 0; j < rhs.shape().width; ++j)
                    result(i, j) += buff * rhs(r, j);
            }
        }
    }

    template <class Vector1, class Vector2, class Matrix,
              meta::as_vector<Vector1> = 0,
              meta::as_vector<Vector2> = 0,
              meta::as_matrix<Matrix> = 0>
    void tensordot(
        Matrix& result,
        const Vector1& col_vector,
        const Vector2& row_vector) const noexcept
    {
        /*
        precision_type temp;

        for(size_type i = 0; i < col_vector.size(); ++i)
        {
            temp = col_vector(i);
            for(size_type j = 0; j < row_vector.size(); ++j)
                result(i, j) = temp * row_vector(j);
        }
        */
        const size_type block_size = row_vector.size();

        auto dst = first(result);

        auto c_first = first(col_vector);
        auto c_last = last(col_vector);

        auto r_first = first(row_vector);

        while (c_first != c_last)
        {
            detail::assign(dst, dst + block_size, detail::mul(), *c_first, r_first);

            dst += block_size;
            ++c_first;
        }
    }

    template <class Matrix1, class Matrix2,
              meta::as_matrix<Matrix1> = 0,
              meta::as_matrix<Matrix2> = 0>
    void transpose(
        Matrix1& result,
        const Matrix2& matrix) const noexcept
    {
        for (size_type i = 0; i < result.shape().height; ++i)
            for (size_type j = 0; j < result.shape().width; ++j)
                result(i, j) = matrix(j, i);
    }

    template <class Matrix1, class Matrix2,
              meta::as_matrix<Matrix1> = 0,
              meta::as_matrix<Matrix2> = 0>
    void inverse(
        Matrix1& result,
        Matrix2& matrix) const noexcept
    {
        size_type N = matrix.shape().height;

        size_type i;
        size_type j;

        precision_type buff;

        for (i = 0; i < N; ++i)
            for (j = 0; j < N; ++j)
                result(i, j) = (i == j) ? 1. : 0.;

        for (size_type k = 0, p; k < N; ++k)
        {
            p = k;
            for (i = k + 1; i < N; ++i)
                if (std::fabs(matrix(p, k)) < std::fabs(matrix(i, k)))
                    p = i;

            if (p != k)
            {
                for (j = k; j < N; ++j)
                {
                    buff = matrix(k, j);
                    matrix(k, j) = matrix(p, j);
                    matrix(p, j) = buff;
                }

                for (j = 0; j < N; ++j)
                {
                    buff = result(k, j);
                    result(k, j) = result(p, j);
                    result(p, j) = buff;
                }
            }

            buff = 1. / matrix(k, k);

            for (j = k; j < N; ++j) matrix(k, j) *= buff;
            for (j = 0; j < N; ++j) result(k, j) *= buff;

            for (i = 0; i < N; ++i)
            {
                if (i == k) continue;

                buff = matrix(i, k);

                for (j = k; j < N; ++j) matrix(i, j) -= matrix(k, j) * buff;
                for (j = 0; j < N; ++j) result(i, j) -= result(k, j) * buff;
            }
        }
    }

    template <class Vector1, class Vector2,
              meta::as_vector<Vector1> = 0,
              meta::as_vector<Vector2> = 0>
    precision_type dot(
        const Vector1& lhs,
        const Vector2& rhs) const noexcept
    {
        precision_type result = 0.0;

        auto first = lhs.data();
        auto last  = lhs.data() + lhs.size();

        auto data = rhs.data();

        while (first != last)
        {
            result += (*first) * (*data);

            ++first;
            ++data;
        }

        return result;
    }

    template <class Vector, class Matrix, class VectorRet = Vector,
              meta::as_vector<Vector> = 0,
              meta::as_matrix<Matrix> = 0,
              meta::as_vector<VectorRet> = 0>
    VectorRet dot(
        const Vector& row_vector,
        const Matrix& matrix) const
    {
        Vector result(matrix.shape().width);

        dot(result, row_vector, matrix);

        return result;
    }

    template <class Vector, class Matrix, class VectorRet = Vector,
              meta::as_vector<Vector> = 0,
              meta::as_matrix<Matrix> = 0,
              meta::as_vector<VectorRet> = 0>
    VectorRet dot(
        const Matrix& matrix,
        const Vector& col_vector) const
    {
        Vector result(matrix.shape().height);

        dot(result, matrix, col_vector);

        return result;
    }

    template <class Matrix1, class Matrix2, class MatrixRet = Matrix1,
              meta::as_matrix<Matrix1> = 0,
              meta::as_matrix<Matrix2> = 0,
              meta::as_matrix<MatrixRet> = 0>
    MatrixRet dot(
        const Matrix1& lhs,
        const Matrix2& rhs) const
    {
        MatrixRet matrix(lhs.shape().height, rhs.shape().width, 0.);

        dot(matrix, lhs, rhs);

        return matrix;
    }

    template <class MatrixRet, class Vector,
              meta::as_matrix<MatrixRet> = 0,
              meta::as_vector<Vector> = 0>
    MatrixRet tensordot(
        const Vector& col_vector,
        const Vector& row_vector) const
    {
        MatrixRet result(col_vector.size(), row_vector.size());

        tensordot(result, col_vector, row_vector);

        return result;
    }

    template <class Matrix, class MatrixRet = Matrix,
              meta::as_matrix<Matrix> = 0,
              meta::as_matrix<MatrixRet> = 0>
    MatrixRet transpose(const Matrix& matrix) const
    {
        MatrixRet result(matrix.shape().width, matrix.shape().height);

        transpose(result, matrix);

        return result;
    }

    template <class Matrix, class MatrixRet = Matrix,
              meta::as_matrix<Matrix> = 0,
              meta::as_matrix<MatrixRet> = 0>
    MatrixRet inverse(Matrix& matrix) const
    {
        MatrixRet result(matrix.shape());

        inverse(result, matrix);

        return result;
    }

    template <class Tensor1, class Tensor2,
              meta::as_tensor<Tensor1> = 0,
              meta::as_tensor<Tensor2> = 0>
    void add(
        Tensor1& result,
        const Tensor2& rhs) const noexcept
    {
        detail::assign(first(result), last(result), detail::add(), first(rhs));
    }

    template <class Tensor1, class Tensor2, class Tensor3,
              meta::as_tensor<Tensor1> = 0,
              meta::as_tensor<Tensor2> = 0,
              meta::as_tensor<Tensor3> = 0>
    void add(
        Tensor1& result,
        const Tensor2& lhs,
        const Tensor3& rhs) const noexcept
    {
        detail::assign(first(result), last(result), detail::add(), first(lhs), first(rhs));
    }

    template <class Tensor1, class Tensor2,
              meta::as_tensor<Tensor1> = 0,
              meta::as_tensor<Tensor2> = 0>
    void sub(
        Tensor1& result,
        const Tensor2& rhs) const noexcept
    {
        detail::assign(first(result), last(result), detail::sub(), first(rhs));
    }

    template <class Tensor1, class Tensor2, class Tensor3,
              meta::as_tensor<Tensor1> = 0,
              meta::as_tensor<Tensor2> = 0,
              meta::as_tensor<Tensor3> = 0>
    void sub(
        Tensor1& result,
        const Tensor2& lhs,
        const Tensor3& rhs) const noexcept
    {
        detail::assign(first(result), last(result), detail::sub(), first(lhs), first(rhs));
    }

    template <class Tensor1, class Tensor2,
              meta::as_tensor<Tensor1> = 0,
              meta::as_tensor<Tensor2> = 0>
    void mul(
        Tensor1& result,
        const Tensor2& rhs) const noexcept
    {
        detail::assign(first(result), last(result), detail::mul(), first(rhs));
    }

    template <class Tensor1, class Tensor2, class Tensor3,
              meta::as_tensor<Tensor1> = 0,
              meta::as_tensor<Tensor2> = 0,
              meta::as_tensor<Tensor3> = 0>
    void mul(
        Tensor1& result,
        const Tensor2& lhs,
        const Tensor3& rhs) const noexcept
    {
        detail::assign(first(result), last(result), detail::mul(), first(lhs), first(rhs));
    }

    template <class Tensor1,
              typename = meta::when_is_tensor<Tensor1>>
    void join(
        Tensor1& result,
        precision_type value) const noexcept
    {
        detail::assign(first(result), last(result), detail::mul(), value);
    }

    template <class Tensor1, class Tensor2,
              meta::as_tensor<Tensor1> = 0,
              meta::as_tensor<Tensor2> = 0>
    void join(
        Tensor1& result,
        precision_type value,
        const Tensor2& rhs) const noexcept
    {
        detail::assign(first(result), last(result), detail::mul(), value, first(rhs));
    }

    template <class Tensor, class Function,
              meta::as_tensor<Tensor> = 0>
    void apply(
        Tensor& result,
        Function func) const noexcept
    {
        detail::apply(first(result), last(result), func);
    }

    template <class Tensor1, class Tensor2, class Function,
              meta::as_tensor<Tensor1> = 0,
              meta::as_tensor<Tensor2> = 0>
    void apply(
        Tensor1& result,
        Function func,
        const Tensor2& rhs) const noexcept
    {
        detail::apply(first(result), last(result), func, first(rhs));
    }

    template <class Tensor1, class Tensor2,
              meta::as_tensor<Tensor1> = 0,
              meta::as_tensor<Tensor2> = 0>
    void assign(
        Tensor1& lhs,
        const Tensor2& rhs) const noexcept
    {
        detail::copy(first(lhs), last(lhs), first(rhs));
    }

    template <class Tensor, class Function,
              meta::as_tensor<Tensor> = 0>
    void for_each(
        Tensor& tensor,
        Function func) const noexcept
    {
        detail::for_each(first(tensor), last(tensor), func);
    }
};

} // namespace lique

} // namespace trixy

#endif // TRIXY_LIQUE_LINEAR_HPP
