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

    using Function       = Precision (*)(Precision);

public:
    template <class Tensor1D, class Tensor2D,
              meta::use_for_tensor_1d_t<Tensor1D> = 0,
              meta::use_for_tensor_2d_t<Tensor2D> = 0>
    void dot(
        Tensor1D& buff,
        const Tensor1D& row_vector,
        const Tensor2D& matrix) const noexcept
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

    template <class Tensor1D, class Tensor2D,
              meta::use_for_tensor_1d_t<Tensor1D> = 0,
              meta::use_for_tensor_2d_t<Tensor2D> = 0>
    void dot(
        Tensor1D& buff,
        const Tensor2D& matrix,
        const Tensor1D& col_vector) const noexcept
    {
        buff.fill(0.);

        for(size_type i = 0; i < buff.size(); ++i)
            for(size_type j = 0; j < col_vector.size(); ++j)
                buff(i) += matrix(i, j) * col_vector(j);
    }

    template <class Tensor1D, class Tensor2D,
              meta::use_for_tensor_1d_t<Tensor1D> = 0,
              meta::use_for_tensor_2d_t<Tensor2D> = 0>
    void tensordot(
        Tensor2D& buff2,
        const Tensor1D& col_vector,
        const Tensor1D& row_vector) const noexcept
    {
        for(size_type i = 0; i < col_vector.size(); ++i)
            for(size_type j = 0; j < row_vector.size(); ++j)
                buff2(i, j) = row_vector(j) * col_vector(i);
    }

    template <class Tensor1D, class Tensor2D,
              meta::use_for_tensor_1d_t<Tensor1D> = 0,
              meta::use_for_tensor_2d_t<Tensor2D> = 0>
    Tensor1D dot(
        const Tensor1D& row_vector,
        const Tensor2D& matrix) const
    {
        Tensor1D buff(matrix.shape().col());

        dot(buff, row_vector, matrix);

        return buff;
    }

    template <class Tensor1D, class Tensor2D,
              meta::use_for_tensor_1d_t<Tensor1D> = 0,
              meta::use_for_tensor_2d_t<Tensor2D> = 0>
    Tensor1D dot(
        const Tensor2D& matrix,
        const Tensor1D& col_vector) const
    {
        Tensor1D buff(matrix.shape().row());

        dot(buff, matrix, col_vector);

        return buff;
    }

    template <class Tensor1D, class Tensor2D,
              meta::use_for_tensor_1d_t<Tensor1D> = 0,
              meta::use_for_tensor_2d_t<Tensor2D> = 0>
    Tensor2D tensordot(
        const Tensor1D& col_vector,
        const Tensor1D& row_vector) const
    {
        Tensor2D buff2(col_vector.size(), row_vector.size());

        tensordot(buff2, col_vector, row_vector);

        return buff2;
    }

    template <class Tensor1, class Tensor2,
              meta::use_for_tensor_nd_t<Tensor1> = 0,
              meta::use_for_tensor_nd_t<Tensor2> = 0>
    void add(
        Tensor1& buff,
        const Tensor2& tensor) const noexcept
    {
        for(size_type i = 0; i < buff.size(); ++i)
            buff(i) += tensor(i);
    }

    template <class Tensor1, class Tensor2, class Tensor3,
              meta::use_for_tensor_nd_t<Tensor1> = 0,
              meta::use_for_tensor_nd_t<Tensor2> = 0,
              meta::use_for_tensor_nd_t<Tensor3> = 0>
    void add(
        Tensor1& buff,
        const Tensor2& lhs,
        const Tensor3& rhs) const noexcept
    {
        for(size_type i = 0; i < buff.size(); ++i)
            buff(i) = lhs(i) + rhs(i);
    }

    template <class Tensor1, class Tensor2,
              meta::use_for_tensor_nd_t<Tensor1> = 0,
              meta::use_for_tensor_nd_t<Tensor2> = 0>
    void sub(
        Tensor1& buff,
        const Tensor2& tensor) const noexcept
    {
        for(size_type i = 0; i < buff.size(); ++i)
            buff(i) -= tensor(i);
    }

    template <class Tensor1, class Tensor2, class Tensor3,
              meta::use_for_tensor_nd_t<Tensor1> = 0,
              meta::use_for_tensor_nd_t<Tensor2> = 0,
              meta::use_for_tensor_nd_t<Tensor3> = 0>
    void sub(
        Tensor1& buff,
        const Tensor2& lhs,
        const Tensor3& rhs) const noexcept
    {
        for(size_type i = 0; i < buff.size(); ++i)
            buff(i) = lhs(i) - rhs(i);
    }

    template <class Tensor1, class Tensor2,
              meta::use_for_tensor_nd_t<Tensor1> = 0,
              meta::use_for_tensor_nd_t<Tensor2> = 0>
    void mul(
        Tensor1& buff,
        const Tensor2& tensor) const noexcept
    {
        for(size_type i = 0; i < buff.size(); ++i)
            buff(i) *= tensor(i);
    }

    template <class Tensor1, class Tensor2, class Tensor3,
              meta::use_for_tensor_nd_t<Tensor1> = 0,
              meta::use_for_tensor_nd_t<Tensor2> = 0,
              meta::use_for_tensor_nd_t<Tensor3> = 0>
    void mul(
        Tensor1& buff,
        const Tensor2& lhs,
        const Tensor3& rhs) const noexcept
    {
        for(size_type i = 0; i < buff.size(); ++i)
            buff(i) = lhs(i) * rhs(i);
    }

    template <class Tensor1,
              meta::use_for_tensor_nd_t<Tensor1> = 0>
    void join(
        Tensor1& buff,
        precision_type value) const noexcept
    {
        for(size_type i = 0; i < buff.size(); ++i)
            buff(i) *= value;
    }

    template <class Tensor1, class Tensor2,
              meta::use_for_tensor_nd_t<Tensor1> = 0,
              meta::use_for_tensor_nd_t<Tensor2> = 0>
    void join(
        Tensor1& buff,
        precision_type value,
        const Tensor2& tensor) const noexcept
    {
        for(size_type i = 0; i < buff.size(); ++i)
            buff(i) = value * tensor(i);
    }

    template <class Tensor,// class Function,
              meta::use_for_tensor_nd_t<Tensor> = 0>
    void apply(
        Tensor& buff,
        Function func) const noexcept
    {
        for(size_type i = 0; i < buff.size(); ++i)
            buff(i) = func(buff(i));
    }

    template <class Tensor1, class Tensor2,// class Function,
              meta::use_for_tensor_nd_t<Tensor1> = 0,
              meta::use_for_tensor_nd_t<Tensor2> = 0>
    void apply(
        Tensor1& buff,
        Function func,
        const Tensor2& tensor) const noexcept
    {
        for(size_type i = 0; i < buff.size(); ++i)
            buff(i) = func(tensor(i));
    }

    template <class Tensor, class Function,
              meta::use_for_tensor_nd_t<Tensor> = 0>
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
