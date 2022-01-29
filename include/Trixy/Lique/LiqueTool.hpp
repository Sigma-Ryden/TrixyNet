#ifndef LIQUE_TOOL_HPP
#define LIQUE_TOOL_HPP

#include <cstddef> // size_t
#include <initializer_list> // initializer_list
#include <utility> // forward

#include "LiqueVector.hpp"
#include "LiqueMatrix.hpp"

#include "Detail/FunctionDetail.hpp"
#include "Detail/LiqueMeta.hpp"

#include "Detail/MacroScope.hpp"

namespace trixy
{

namespace lique
{

enum class Axis
{
    X,
    Y,
    None
};

template <typename Type>
using Binary = bool (*)(Type, Type);

namespace comp
{

LIQUE_FUNCTION_TPL
inline bool is_bigger(Precision previous, Precision next)
{
    return previous > next;
}

LIQUE_FUNCTION_TPL
inline bool is_less(Precision previous, Precision next)
{
    return previous < next;
}

} // namespace comp

template <class T>
inline T sum(T&& t1)
{
    return t1;
}

template <class T, class... Tn,
          typename std::enable_if<meta::is_same_types<T, Tn...>::value, int>::type = 0>
inline T sum(T&& t1, Tn&&... tn)
{
    return t1 + sum(std::forward<T>(tn)...);
}

template <class Tensor1D,
          typename size_type = typename Tensor1D::size_type,
          Binary<typename Tensor1D::precision_type> compare,
          meta::use_for_tensor_1d_t<Tensor1D> = 0>
size_type find(const Tensor1D& vector)
{
    size_type arg = 0;
    for(size_type i = 1; i < vector.size(); ++i)
        if(compare(vector(arg), vector(i)))
            arg = i;

    return arg;
}

template <typename Precision,
          Binary<Precision> compare,
          meta::use_for_arithmetic_t<Precision> = 0>
Vector<std::size_t> find(
    const Matrix<Precision>& matrix,
    Axis axis = Axis::None)
{
    Vector<std::size_t> vector;
    std::size_t arg;

    switch(axis)
    {
    case Axis::X:
        vector.resize(matrix.shape().col(), 0);

        for(std::size_t i = 1; i < matrix.shape().row(); ++i)
            for(std::size_t n = 0; n < vector.size(); ++n)
                if(compare(matrix(vector(n), n), matrix(i, n)))
                    vector(n) = i;

        break;

    case Axis::Y:
        vector.resize(matrix.shape().row());

        for(std::size_t n = 0; n < vector.size(); ++n)
        {
            for(std::size_t min = 0, i = 1; i < matrix.shape().col(); ++i)
                if(compare(matrix(n, arg), matrix(n, i)))
                    arg = i;

            vector(n) = arg;
        }
        break;

    default:
        vector.resize(1);

        arg = 0;
        for(std::size_t i = 1; i < matrix.size(); ++i)
            if(compare(matrix(arg), matrix(i)))
                arg = i;

        vector(0) = arg;
        break;
    }

    return vector;
}

template <class Tensor1D,
          typename size_type = typename Tensor1D::size_type,
          meta::use_for_tensor_1d_t<Tensor1D> = 0>
size_type argmin(const Tensor1D& vector)
{
    return find<typename Tensor1D::precision_type, comp::is_bigger>(vector);
}

template <class Tensor1D,
          typename size_type = typename Tensor1D::size_type,
          meta::use_for_tensor_1d_t<Tensor1D> = 0>
size_type argmax(const Tensor1D& vector)
{
    return find<typename Tensor1D::precision_type, comp::is_less>(vector);
}

LIQUE_FUNCTION_TPL
Vector<std::size_t> argmin(
    const Matrix<Precision>& matrix,
    Axis axis = Axis::None)
{
    return find<Precision, comp::is_bigger>(matrix, axis);
}

LIQUE_FUNCTION_TPL
Vector<std::size_t> argmax(
    const Matrix<Precision>& matrix,
    Axis axis = Axis::None)
{
    return find<Precision, comp::is_less>(matrix, axis);
}

template <class Tensor1D, typename precision_type = typename Tensor1D::precision_type,
          meta::use_for_tensor_1d_t<Tensor1D> = 0>
precision_type min(const Tensor1D& vector)
{
    return vector(find<precision_type, comp::is_bigger>(vector));
}

template <class Tensor1D, typename precision_type = typename Tensor1D::precision_type,
          meta::use_for_tensor_1d_t<Tensor1D> = 0>
precision_type max(const Tensor1D& vector)
{
    return vector(find<precision_type, comp::is_less>(vector));
}

template <class Tensor1D,
          typename size_type = typename Tensor1D::size_type,
          typename precision_type = typename Tensor1D::precision_type,
          meta::use_for_tensor_1d_t<Tensor1D> = 0>
precision_type mean(const Tensor1D& vector)
{
    size_type mean_value = 0.;

    for(size_type i = 0; i < vector.size(); ++i)
        mean_value += vector(i);

    return mean_value / static_cast<precision_type>(vector.size());
}

template <class Tensor1D,
          typename size_type = typename Tensor1D::size_type,
          typename precision_type = typename Tensor1D::precision_type,
          meta::use_for_tensor_1d_t<Tensor1D> = 0>
precision_type std(
    const Tensor1D& vector,
    bool unbiased = false)
{
    precision_type mean_value = mean(vector);
    precision_type std_value;
    precision_type buff;

    for(size_type i = 0; i < vector.size(); ++i)
    {
        buff = vector(i) - mean_value;
        std_value += buff * buff;
    }

    std_value /= static_cast<precision_type>(vector.size() - unbiased);

    return std::sqrt(std_value);
}

LIQUE_FUNCTION_TPL
Vector<Precision> mean(
    const Matrix<Precision>& matrix,
    Axis axis = Axis::None)
{
    Vector<Precision> vector;
    Precision alpha;

    switch(axis)
    {
    case Axis::X:
        vector.resize(matrix.shape().col(), 0.);
        alpha = 1. / static_cast<Precision>(matrix.shape().row());

        for(std::size_t n = 0; n < matrix.shape().row(); ++n)
            for(std::size_t i = 0; i < vector.size(); ++i)
                vector(i) += matrix(n, i);

        for(std::size_t i = 0; i < vector.size(); ++i)
            vector(i) *= alpha;

        break;

    case Axis::Y:
        vector.resize(matrix.shape().row(), 0.);
        alpha = 1. / static_cast<Precision>(matrix.shape().col());

        for(std::size_t i = 0; i < vector.size(); ++i)
            for(std::size_t n = 0; n < matrix.shape().col(); ++n)
                vector(i) += matrix(i, n);

        for(std::size_t i = 0; i < vector.size(); ++i)
            vector(i) *= alpha;

        break;

    default:
        vector.resize(1, 0.);
        alpha = 1. / static_cast<Precision>(matrix.size());

        for(std::size_t i = 0; i < matrix.size(); ++i)
            vector(0) += matrix(i);

        vector(0) *= alpha;
        break;
    }

    return vector;
}

LIQUE_FUNCTION_TPL
Vector<Precision> std(
    const Matrix<Precision>& matrix,
    Axis axis = Axis::None,
    bool unbiased = false)
{
    Vector<Precision> vector = mean(matrix, axis);

    Precision std_value;
    Precision alpha;
    Precision buff;

    switch(axis)
    {
    case Axis::X:
        alpha = 1. / static_cast<Precision>(matrix.shape().row() - unbiased);

        for(std::size_t i = 0; i < vector.size(); ++i)
        {
            std_value = 0.;
            for(std::size_t n = 0; n < matrix.shape().row(); ++n)
            {
                buff = matrix(n, i) - vector(i);
                std_value += buff * buff;
            }

            vector(i) = std_value;
        }

        for(std::size_t i = 0; i < vector.size(); ++i)
        {
            vector(i) *= alpha;
            vector(i)  = std::sqrt(vector(i));
        }

        break;

    case Axis::Y:
        alpha = 1. / static_cast<Precision>(matrix.shape().col() - unbiased);

        for(std::size_t i = 0; i < vector.size(); ++i)
        {
            std_value = 0.;
            for(std::size_t n = 0; n < matrix.shape().col(); ++n)
            {
                buff = matrix(i, n) - vector(i);
                std_value += buff * buff;
            }

            vector(i) = std_value;
        }

        for(std::size_t i = 0; i < vector.size(); ++i)
        {
            vector(i) *= alpha;
            vector(i)  = std::sqrt(vector(i));
        }

        break;

    default:
        alpha = 1. / static_cast<Precision>(matrix.size() - unbiased);
        std_value = 0.;
        for(std::size_t i = 0; i < matrix.size(); ++i)
        {
            buff = matrix(i) - vector(0);
            std_value += buff * buff;
        }

        vector(0) = std::sqrt(std_value * alpha);
        break;
    }

    return vector;
}

template <class Tensor1D, class Tensor2D,
          meta::use_for_tensor_1d_t<Tensor1D> = 0,
          meta::use_for_tensor_2d_t<Tensor2D> = 0>
void dot(
    Tensor1D& buff,
    const Tensor1D& row_vector,
    const Tensor2D& matrix) noexcept
{
    using size_type      = typename Tensor1D::size_type;
    using precision_type = typename Tensor1D::precision_type;

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
    const Tensor1D& col_vector) noexcept
{
    using size_type = typename Tensor1D::size_type;

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
    const Tensor1D& row_vector) noexcept
{
    using size_type = typename Tensor1D::size_type;

    for(size_type i = 0; i < col_vector.size(); ++i)
        for(size_type j = 0; j < row_vector.size(); ++j)
            buff2(i, j) = row_vector(j) * col_vector(i);
}

template <class Tensor1D, class Tensor2D,
          meta::use_for_tensor_1d_t<Tensor1D> = 0,
          meta::use_for_tensor_2d_t<Tensor2D> = 0>
Tensor1D dot(
    const Tensor1D& row_vector,
    const Tensor2D& matrix)
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
    const Tensor1D& col_vector)
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
    const Tensor1D& row_vector)
{
    Tensor2D buff2(col_vector.size(), row_vector.size());

    tensordot(buff2, col_vector, row_vector);

    return buff2;
}

template <class Tensor, class Function,
          meta::use_for_tensor_nd_t<Tensor> = 0>
void for_each(Tensor& tensor, Function func)
{
    using size_type = typename Tensor::size_type;

    for(size_type i = 0; i < tensor.size(); ++i)
        func(tensor(i));
}

namespace detail
{

template <class T, meta::use_for_tensor_nd_t<T> = 0>
void concat(T& out, std::size_t& at, const T& tensor)
{
    detail::copy(out.data() + at, out.data() + at + tensor.size(), tensor.data());
}

template <class T, class... Tn,
          meta::use_for_tensor_nd_t<T> = 0,
          typename std::enable_if<meta::is_same_types<T, Tn...>::value, int>::type = 0>
void concat(T& out, std::size_t& at, const T& tensor, const Tn&... tensor_n)
{
    detail::copy(out.data() + at, out.data() + at + tensor.size(), tensor.data());
    at += tensor.size();

    concat(out, at, tensor_n...);
}

} // namespace detail

template <class Tensor, template <typename...> class Container,
          meta::use_for_tensor_nd_t<Tensor> = 0>
Tensor concat(const Container<Tensor>& list)
{
    using size_type = typename Tensor::size_type;

    size_type accumulate_size = 0;

    for(const auto& it : list)
        accumulate_size += it.size();

    Tensor tensor(accumulate_size);

    size_type at = 0;
    for(const auto& it : list)
    {
        detail::copy(tensor.data() + at, tensor.data() + at + it.size(), it.data());
        at += it.size();
    }

    return tensor;
}

template <class T, class... Tn,
          meta::use_for_tensor_nd_t<T> = 0,
          typename std::enable_if<meta::is_same_types<T, Tn...>::value, int>::type = 0>
T concat(const T& tensor, const Tn&... tensor_n)
{
    using size_type = typename T::size_type;

    T out(sum(tensor.size(), tensor_n.size()...));

    size_type position = 0;
    detail::concat(out, position, tensor, tensor_n...);

    return out;
}

} // namespace lique

} // namespace trixy

#include "Detail/MacroUnscope.hpp"

#endif // LIQUE_TOOL_HPP
