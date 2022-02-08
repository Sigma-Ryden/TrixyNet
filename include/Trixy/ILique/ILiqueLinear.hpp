#ifndef ILIQUE_LINEAR_HPP
#define ILIQUE_LINEAR_HPP

#include <cstddef> // size_t

#include "Trixy/Lique/Detail/LiqueMeta.hpp"

namespace trixy
{

namespace ilique
{

template <class Derived, typename Precision>
class ILinear
{
public:
    using size_type      = std::size_t;
    using precision_type = Precision;

protected:
    virtual ~ILinear() = default;

private:
    const Derived& self() const { return *static_cast<const Derived*>(this); }

public:
    template <class Vector1, class Vector2, class Matrix,
              lique::meta::use_for_vector_t<Vector1> = 0,
              lique::meta::use_for_vector_t<Vector2> = 0,
              lique::meta::use_for_matrix_t<Matrix> = 0>
    void dot(
        Vector1& buff,
        const Vector2& row_vector,
        const Matrix& matrix) const noexcept
    {
        self().dot(buff, row_vector, matrix);
    }

    template <class Vector1, class Vector2, class Matrix,
              lique::meta::use_for_vector_t<Vector1> = 0,
              lique::meta::use_for_vector_t<Vector2> = 0,
              lique::meta::use_for_matrix_t<Matrix> = 0>
    void dot(
        Vector1& buff,
        const Matrix& matrix,
        const Vector2& col_vector) const noexcept
    {
        self().dot(buff, matrix, col_vector);
    }

    template <class Vector1, class Vector2, class Matrix,
              lique::meta::use_for_vector_t<Vector1> = 0,
              lique::meta::use_for_vector_t<Vector2> = 0,
              lique::meta::use_for_matrix_t<Matrix> = 0>
    void tensordot(
        Matrix& buff2,
        const Vector1& col_vector,
        const Vector2& row_vector) const noexcept
    {
        self().tensordot(buff2, col_vector, row_vector);
    }

    template <class Tensor1, class Tensor2,
              lique::meta::use_for_tensor_t<Tensor1> = 0,
              lique::meta::use_for_tensor_t<Tensor2> = 0>
    void add(
        Tensor1& buff,
        const Tensor2& tensor) const noexcept
    {
        self().add(buff, tensor);
    }

    template <class Tensor1, class Tensor2, class Tensor3,
              lique::meta::use_for_tensor_t<Tensor1> = 0,
              lique::meta::use_for_tensor_t<Tensor2> = 0,
              lique::meta::use_for_tensor_t<Tensor3> = 0>
    void add(
        Tensor1& buff,
        const Tensor2& lhs,
        const Tensor3& rhs) const noexcept
    {
        self().add(buff, lhs, rhs);
    }

    template <class Tensor1, class Tensor2,
              lique::meta::use_for_tensor_t<Tensor1> = 0,
              lique::meta::use_for_tensor_t<Tensor2> = 0>
    void sub(
        Tensor1& buff,
        const Tensor2& tensor) const noexcept
    {
        self().sub(buff, tensor);
    }

    template <class Tensor1, class Tensor2, class Tensor3,
              lique::meta::use_for_tensor_t<Tensor1> = 0,
              lique::meta::use_for_tensor_t<Tensor2> = 0,
              lique::meta::use_for_tensor_t<Tensor3> = 0>
    void sub(
        Tensor1& buff,
        const Tensor2& lhs,
        const Tensor3& rhs) const noexcept
    {
        self().sub(buff, lhs, rhs);
    }

    template <class Tensor1, class Tensor2,
              lique::meta::use_for_tensor_t<Tensor1> = 0,
              lique::meta::use_for_tensor_t<Tensor2> = 0>
    void mul(
        Tensor1& buff,
        const Tensor2& tensor) const noexcept
    {
        self().mul(buff, tensor);
    }

    template <class Tensor1, class Tensor2, class Tensor3,
              lique::meta::use_for_tensor_t<Tensor1> = 0,
              lique::meta::use_for_tensor_t<Tensor2> = 0,
              lique::meta::use_for_tensor_t<Tensor3> = 0>
    void mul(
        Tensor1& buff,
        const Tensor2& lhs,
        const Tensor3& rhs) const noexcept
    {
        self().mul(buff, lhs, rhs);
    }

    template <class Tensor1,
              lique::meta::use_for_tensor_t<Tensor1> = 0>
    void join(
        Tensor1& buff,
        precision_type value) const noexcept
    {
        self().join(buff, value);
    }

    template <class Tensor1, class Tensor2,
              lique::meta::use_for_tensor_t<Tensor1> = 0,
              lique::meta::use_for_tensor_t<Tensor2> = 0>
    void join(
        Tensor1& buff,
        precision_type value,
        const Tensor2& tensor) const noexcept
    {
        self().join(buff, value, tensor);
    }

    template <class Tensor, class Function,
              lique::meta::use_for_tensor_t<Tensor> = 0>
    void apply(
        Tensor& buff,
        Function func) const noexcept
    {
        self().apply(buff, func);
    }

    template <class Tensor1, class Tensor2, class Function,
              lique::meta::use_for_tensor_t<Tensor1> = 0,
              lique::meta::use_for_tensor_t<Tensor2> = 0>
    void apply(
        Tensor1& buff,
        Function func,
        const Tensor2& tensor) const noexcept
    {
        self().apply(buff, func, tensor);
    }

    template <class Tensor, class Function,
              lique::meta::use_for_tensor_t<Tensor> = 0>
    void for_each(
        Tensor& tensor,
        Function func) const noexcept
    {
        self().for_each(tensor, func);
    }
};

} // namespace ilique

} // namespace trixy

#endif // ILIQUE_LINEAR_HPP
