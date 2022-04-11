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
              typename = meta::when_is_vector<Vector1>,
              typename = meta::when_is_vector<Vector2>,
              typename = meta::when_is_matrix<Matrix>>
    void dot(
        Vector1& buff,
        const Vector2& row_vector,
        const Matrix& matrix) const noexcept
    {
        precision_type temp;

        detail::assign(first(buff), last(buff), detail::cpy(), precision_type(0.));

        for(size_type i = 0; i < row_vector.size(); ++i)
        {
            temp = row_vector(i);
            for(size_type j = 0; j < buff.size(); ++j)
               buff(j) += temp * matrix(i, j);
        }
    }

    template <class Vector1, class Vector2, class Matrix,
              typename = meta::when_is_vector<Vector1>,
              typename = meta::when_is_vector<Vector2>,
              typename = meta::when_is_matrix<Matrix>>
    void dot(
        Vector1& buff,
        const Matrix& matrix,
        const Vector2& col_vector) const noexcept
    {
        detail::assign(first(buff), last(buff), detail::cpy(), precision_type(0.));

        for(size_type i = 0; i < buff.size(); ++i)
            for(size_type j = 0; j < col_vector.size(); ++j)
                buff(i) += matrix(i, j) * col_vector(j);
    }

    template <class Vector1, class Vector2, class Matrix,
              typename = meta::when_is_vector<Vector1>,
              typename = meta::when_is_vector<Vector2>,
              typename = meta::when_is_matrix<Matrix>>
    void tensordot(
        Matrix& buff,
        const Vector1& col_vector,
        const Vector2& row_vector) const noexcept
    {
        /*
        precision_type temp;

        for(size_type i = 0; i < col_vector.size(); ++i)
        {
            temp = col_vector(i);
            for(size_type j = 0; j < row_vector.size(); ++j)
                buff(i, j) = temp * row_vector(j);
        }
        */
        const size_type block_size = row_vector.size();

        auto dst = first(buff);

        auto c_first = first(col_vector);
        auto c_last = last(col_vector);

        auto r_first = first(row_vector);

        while(c_first != c_last)
        {
            detail::assign(dst, dst + block_size, detail::mul(), *c_first, r_first);

            dst += block_size;
            ++c_first;
        }
    }

    template <class Vector, class Matrix,
              typename = meta::when_is_vector<Vector> ,
              typename = meta::when_is_matrix<Matrix>>
    Vector dot(
        const Vector& row_vector,
        const Matrix& matrix) const
    {
        Vector buff(matrix.shape().col());

        dot(buff, row_vector, matrix);

        return buff;
    }

    template <class Vector, class Matrix,
              typename = meta::when_is_vector<Vector>,
              typename = meta::when_is_matrix<Matrix>>
    Vector dot(
        const Matrix& matrix,
        const Vector& col_vector) const
    {
        Vector buff(matrix.shape().row());

        dot(buff, matrix, col_vector);

        return buff;
    }

    template <class Matrix, class Vector,
              typename = meta::when_is_matrix<Matrix>,
              typename = meta::when_is_vector<Vector>>
    Matrix tensordot(
        const Vector& col_vector,
        const Vector& row_vector) const
    {
        Matrix buff2(col_vector.size(), row_vector.size());

        tensordot(buff2, col_vector, row_vector);

        return buff2;
    }

    template <class Tensor1, class Tensor2,
              typename = meta::when_is_tensor<Tensor1>,
              typename = meta::when_is_tensor<Tensor2>>
    void add(
        Tensor1& buff,
        const Tensor2& rhs) const noexcept
    {
        detail::assign(first(buff), last(buff), detail::add(), first(rhs));
    }

    template <class Tensor1, class Tensor2, class Tensor3,
              typename = meta::when_is_tensor<Tensor1>,
              typename = meta::when_is_tensor<Tensor2>,
              typename = meta::when_is_tensor<Tensor3>>
    void add(
        Tensor1& buff,
        const Tensor2& lhs,
        const Tensor3& rhs) const noexcept
    {
        detail::assign(first(buff), last(buff), detail::add(), first(lhs), first(rhs));
    }

    template <class Tensor1, class Tensor2,
              typename = meta::when_is_tensor<Tensor1>,
              typename = meta::when_is_tensor<Tensor2>>
    void sub(
        Tensor1& buff,
        const Tensor2& rhs) const noexcept
    {
        detail::assign(first(buff), last(buff), detail::sub(), first(rhs));
    }

    template <class Tensor1, class Tensor2, class Tensor3,
              typename = meta::when_is_tensor<Tensor1>,
              typename = meta::when_is_tensor<Tensor2>,
              typename = meta::when_is_tensor<Tensor3>>
    void sub(
        Tensor1& buff,
        const Tensor2& lhs,
        const Tensor3& rhs) const noexcept
    {
        detail::assign(first(buff), last(buff), detail::sub(), first(lhs), first(rhs));
    }

    template <class Tensor1, class Tensor2,
              typename = meta::when_is_tensor<Tensor1>,
              typename = meta::when_is_tensor<Tensor2>>
    void mul(
        Tensor1& buff,
        const Tensor2& rhs) const noexcept
    {
        detail::assign(first(buff), last(buff), detail::mul(), first(rhs));
    }

    template <class Tensor1, class Tensor2, class Tensor3,
              typename = meta::when_is_tensor<Tensor1>,
              typename = meta::when_is_tensor<Tensor2>,
              typename = meta::when_is_tensor<Tensor3>>
    void mul(
        Tensor1& buff,
        const Tensor2& lhs,
        const Tensor3& rhs) const noexcept
    {
        detail::assign(first(buff), last(buff), detail::mul(), first(lhs), first(rhs));
    }

    template <class Tensor1,
              typename = meta::when_is_tensor<Tensor1>>
    void join(
        Tensor1& buff,
        precision_type value) const noexcept
    {
        detail::assign(first(buff), last(buff), detail::mul(), value);
    }

    template <class Tensor1, class Tensor2,
              typename = meta::when_is_tensor<Tensor1>,
              typename = meta::when_is_tensor<Tensor2>>
    void join(
        Tensor1& buff,
        precision_type value,
        const Tensor2& rhs) const noexcept
    {
        detail::assign(first(buff), last(buff), detail::mul(), value, first(rhs));
    }

    template <class Tensor, class Function,
              typename = meta::when_is_tensor<Tensor>>
    void apply(
        Tensor& buff,
        Function func) const noexcept
    {
        detail::apply(first(buff), last(buff), func);
    }

    template <class Tensor1, class Tensor2, class Function,
              typename = meta::when_is_tensor<Tensor1>,
              typename = meta::when_is_tensor<Tensor2>>
    void apply(
        Tensor1& buff,
        Function func,
        const Tensor2& rhs) const noexcept
    {
        detail::apply(first(buff), last(buff), func, first(rhs));
    }

    template <class Tensor, class Function,
              typename = meta::when_is_tensor<Tensor>>
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
