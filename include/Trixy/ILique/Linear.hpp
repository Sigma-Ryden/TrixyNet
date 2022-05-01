#ifndef TRIXY_ILIQUE_LINEAR_HPP
#define TRIXY_ILIQUE_LINEAR_HPP

#include <cstddef> // size_t

#include <Trixy/Lique/Detail/LiqueMeta.hpp>

namespace trixy
{

namespace ilique
{

template <template <typename, typename...> class Derived,
          typename Precision, typename... Pack>
class ILinear
{
public:
    using Linear         = Derived<Precision, Pack...>;

    using size_type      = std::size_t;
    using precision_type = Precision;

private:
    const Linear& self() const { return *static_cast<const Linear*>(this); }

public:
    template <class Vector1, class Vector2, class Matrix,
              typename = lique::meta::when_is_vector<Vector1>,
              typename = lique::meta::when_is_vector<Vector2>,
              typename = lique::meta::when_is_matrix<Matrix>>
    void dot(
        Vector1& buff,
        const Vector2& row_vector,
        const Matrix& matrix) const noexcept
    {
        self().dot(buff, row_vector, matrix);
    }

    template <class Vector1, class Vector2, class Matrix,
              typename = lique::meta::when_is_vector<Vector1>,
              typename = lique::meta::when_is_vector<Vector2>,
              typename = lique::meta::when_is_matrix<Matrix>>
    void dot(
        Vector1& buff,
        const Matrix& matrix,
        const Vector2& col_vector) const noexcept
    {
        self().dot(buff, matrix, col_vector);
    }

    template <class Vector1, class Vector2, class Matrix,
              typename = lique::meta::when_is_vector<Vector1>,
              typename = lique::meta::when_is_vector<Vector2>,
              typename = lique::meta::when_is_matrix<Matrix>>
    void tensordot(
        Matrix& buff2,
        const Vector1& col_vector,
        const Vector2& row_vector) const noexcept
    {
        self().tensordot(buff2, col_vector, row_vector);
    }

    template <class Tensor1, class Tensor2,
              typename = lique::meta::when_is_tensor<Tensor1>,
              typename = lique::meta::when_is_tensor<Tensor2>>
    void add(
        Tensor1& buff,
        const Tensor2& tensor) const noexcept
    {
        self().add(buff, tensor);
    }

    template <class Tensor1, class Tensor2, class Tensor3,
              typename = lique::meta::when_is_tensor<Tensor1>,
              typename = lique::meta::when_is_tensor<Tensor2>,
              typename = lique::meta::when_is_tensor<Tensor3>>
    void add(
        Tensor1& buff,
        const Tensor2& lhs,
        const Tensor3& rhs) const noexcept
    {
        self().add(buff, lhs, rhs);
    }

    template <class Tensor1, class Tensor2,
              typename = lique::meta::when_is_tensor<Tensor1>,
              typename = lique::meta::when_is_tensor<Tensor2>>
    void sub(
        Tensor1& buff,
        const Tensor2& tensor) const noexcept
    {
        self().sub(buff, tensor);
    }

    template <class Tensor1, class Tensor2, class Tensor3,
              typename = lique::meta::when_is_tensor<Tensor1>,
              typename = lique::meta::when_is_tensor<Tensor2>,
              typename = lique::meta::when_is_tensor<Tensor3>>
    void sub(
        Tensor1& buff,
        const Tensor2& lhs,
        const Tensor3& rhs) const noexcept
    {
        self().sub(buff, lhs, rhs);
    }

    template <class Tensor1, class Tensor2,
              typename = lique::meta::when_is_tensor<Tensor1>,
              typename = lique::meta::when_is_tensor<Tensor2>>
    void mul(
        Tensor1& buff,
        const Tensor2& tensor) const noexcept
    {
        self().mul(buff, tensor);
    }

    template <class Tensor1, class Tensor2, class Tensor3,
              typename = lique::meta::when_is_tensor<Tensor1>,
              typename = lique::meta::when_is_tensor<Tensor2>,
              typename = lique::meta::when_is_tensor<Tensor3>>
    void mul(
        Tensor1& buff,
        const Tensor2& lhs,
        const Tensor3& rhs) const noexcept
    {
        self().mul(buff, lhs, rhs);
    }

    template <class Tensor1,
              typename = lique::meta::when_is_tensor<Tensor1>>
    void join(
        Tensor1& buff,
        precision_type value) const noexcept
    {
        self().join(buff, value);
    }

    template <class Tensor1, class Tensor2,
              typename = lique::meta::when_is_tensor<Tensor1>,
              typename = lique::meta::when_is_tensor<Tensor2>>
    void join(
        Tensor1& buff,
        precision_type value,
        const Tensor2& tensor) const noexcept
    {
        self().join(buff, value, tensor);
    }

    template <class Tensor, class Function,
              typename = lique::meta::when_is_tensor<Tensor>>
    void apply(
        Tensor& buff,
        Function func) const noexcept
    {
        self().apply(buff, func);
    }

    template <class Tensor1, class Tensor2, class Function,
              typename = lique::meta::when_is_tensor<Tensor1>,
              typename = lique::meta::when_is_tensor<Tensor2>>
    void apply(
        Tensor1& buff,
        Function func,
        const Tensor2& tensor) const noexcept
    {
        self().apply(buff, func, tensor);
    }

    template <class Tensor1, class Tensor2,
              typename = lique::meta::when_is_tensor<Tensor1>,
              typename = lique::meta::when_is_tensor<Tensor2>>
    void assign(
        Tensor1& lhs,
        const Tensor2& rhs) const noexcept
    {
        self().assign(lhs, rhs);
    }

    template <class Tensor, class Function,
              typename = lique::meta::when_is_tensor<Tensor>>
    void for_each(
        Tensor& tensor,
        Function func) const noexcept
    {
        self().for_each(tensor, func);
    }
};

} // namespace ilique

} // namespace trixy

#endif // TRIXY_ILIQUE_LINEAR_HPP
