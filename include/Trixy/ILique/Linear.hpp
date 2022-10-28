#ifndef TRIXY_ILIQUE_LINEAR_HPP
#define TRIXY_ILIQUE_LINEAR_HPP

#include <cstddef> // size_t

#include <Trixy/Lique/Detail/LiqueMeta.hpp>

#include <Trixy/Detail/MetaMacro.hpp>

namespace trixy
{

namespace ilique
{

template <template <typename, typename...> class Derived,
          typename Precision, typename... Pack>
class ILinear
{
private:
    template <class T>
    using as_flat_iterate =
        trixy::meta::require<not lique::meta::is_matrix<T>::value and
                             lique::meta::is_iterate<T>::value>;

public:
    using Linear         = Derived<Precision, Pack...>;

    using size_type      = std::size_t;
    using precision_type = Precision;

private:
    const Linear& self() const { return *static_cast<const Linear*>(this); }

public:
    template <class Vector1, class Vector2, class Matrix,
              as_flat_iterate<Vector1> = 0,
              as_flat_iterate<Vector2> = 0,
              lique::meta::as_matrix<Matrix> = 0>
    void dot(
        Vector1& result,
        const Vector2& row_vector,
        const Matrix& matrix) const noexcept
    {
        self().dot(result, row_vector, matrix);
    }

    template <class Vector1, class Vector2, class Matrix,
              as_flat_iterate<Vector1> = 0,
              as_flat_iterate<Vector2> = 0,
              lique::meta::as_matrix<Matrix> = 0>
    void dot(
        Vector1& result,
        const Matrix& matrix,
        const Vector2& col_vector) const noexcept
    {
        self().dot(result, matrix, col_vector);
    }

    template <class Vector1, class Vector2, class Matrix,
              as_flat_iterate<Vector1> = 0,
              as_flat_iterate<Vector2> = 0,
              lique::meta::as_matrix<Matrix> = 0>
    void tensordot(
        Matrix& buff2,
        const Vector1& col_vector,
        const Vector2& row_vector) const noexcept
    {
        self().tensordot(buff2, col_vector, row_vector);
    }

    template <class Matrix1, class Matrix2, class Matrix3,
              lique::meta::as_matrix<Matrix1> = 0,
              lique::meta::as_matrix<Matrix2> = 0,
              lique::meta::as_matrix<Matrix3> = 0>
    void dot(
        Matrix1& result,
        const Matrix2& lhs,
        const Matrix3& rhs) const noexcept
    {
        self().dot(result, lhs, rhs);
    }

    template <class Matrix1, class Matrix2,
              lique::meta::as_matrix<Matrix1> = 0,
              lique::meta::as_matrix<Matrix2> = 0>
    void transpose(
        Matrix1& result,
        const Matrix2& matrix) const noexcept
    {
        self().transpose(result, matrix);
    }

    template <class Matrix1, class Matrix2,
              lique::meta::as_matrix<Matrix1> = 0,
              lique::meta::as_matrix<Matrix2> = 0>
    void inverse(
        Matrix1& result,
        Matrix2& matrix) const noexcept
    {
        self().inverse(result, matrix);
    }

    template <class Tensor1, class Tensor2,
              lique::meta::as_iterate<Tensor1> = 0,
              lique::meta::as_iterate<Tensor2> = 0>
    void add(
        Tensor1& result,
        const Tensor2& tensor) const noexcept
    {
        self().add(result, tensor);
    }

    template <class Tensor1, class Tensor2, class Tensor3,
              lique::meta::as_iterate<Tensor1> = 0,
              lique::meta::as_iterate<Tensor2> = 0,
              lique::meta::as_iterate<Tensor3> = 0>
    void add(
        Tensor1& result,
        const Tensor2& lhs,
        const Tensor3& rhs) const noexcept
    {
        self().add(result, lhs, rhs);
    }

    template <class Tensor1, class Tensor2,
              lique::meta::as_iterate<Tensor1> = 0,
              lique::meta::as_iterate<Tensor2> = 0>
    void sub(
        Tensor1& result,
        const Tensor2& tensor) const noexcept
    {
        self().sub(result, tensor);
    }

    template <class Tensor1, class Tensor2, class Tensor3,
              lique::meta::as_iterate<Tensor1> = 0,
              lique::meta::as_iterate<Tensor2> = 0,
              lique::meta::as_iterate<Tensor3> = 0>
    void sub(
        Tensor1& result,
        const Tensor2& lhs,
        const Tensor3& rhs) const noexcept
    {
        self().sub(result, lhs, rhs);
    }

    template <class Tensor1, class Tensor2,
              lique::meta::as_iterate<Tensor1> = 0,
              lique::meta::as_iterate<Tensor2> = 0>
    void mul(
        Tensor1& result,
        const Tensor2& tensor) const noexcept
    {
        self().mul(result, tensor);
    }

    template <class Tensor1, class Tensor2, class Tensor3,
              lique::meta::as_iterate<Tensor1> = 0,
              lique::meta::as_iterate<Tensor2> = 0,
              lique::meta::as_iterate<Tensor3> = 0>
    void mul(
        Tensor1& result,
        const Tensor2& lhs,
        const Tensor3& rhs) const noexcept
    {
        self().mul(result, lhs, rhs);
    }

    template <class Tensor1,
              lique::meta::as_iterate<Tensor1> = 0>
    void join(
        Tensor1& result,
        precision_type value) const noexcept
    {
        self().join(result, value);
    }

    template <class Tensor1, class Tensor2,
              lique::meta::as_iterate<Tensor1> = 0,
              lique::meta::as_iterate<Tensor2> = 0>
    void join(
        Tensor1& result,
        precision_type value,
        const Tensor2& tensor) const noexcept
    {
        self().join(result, value, tensor);
    }

    template <class Tensor, class Function,
              lique::meta::as_iterate<Tensor> = 0>
    void apply(
        Tensor& result,
        Function func) const TRNOEXCEPT_IF(noexcept(func))
    {
        self().apply(result, func);
    }

    template <class Tensor1, class Tensor2, class Function,
              lique::meta::as_iterate<Tensor1> = 0,
              lique::meta::as_iterate<Tensor2> = 0>
    void apply(
        Tensor1& result,
        Function func,
        const Tensor2& tensor) const TRNOEXCEPT_IF(noexcept(func))
    {
        self().apply(result, func, tensor);
    }

    template <class Tensor1, class Tensor2,
              lique::meta::as_iterate<Tensor1> = 0,
              lique::meta::as_iterate<Tensor2> = 0>
    void assign(
        Tensor1& lhs,
        const Tensor2& rhs) const noexcept
    {
        self().assign(lhs, rhs);
    }

    template <class Tensor, class Function,
              lique::meta::as_iterate<Tensor> = 0>
    void loop(
        Tensor& tensor,
        Function func) const TRNOEXCEPT_IF(noexcept(func))
    {
        self().loop(tensor, func);
    }
};

} // namespace ilique

} // namespace trixy

#endif // TRIXY_ILIQUE_LINEAR_HPP
