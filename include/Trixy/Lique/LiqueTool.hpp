#ifndef LIQUE_TOOL_HPP
#define LIQUE_TOOL_HPP

#include <cstddef> // size_t
#include <initializer_list> // initializer_list

#include "LiqueVector.hpp"
#include "LiqueMatrix.hpp"

#include "Detail/LiqueMeta.hpp"

#include "Detail/MacroScope.hpp"

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

template <typename Precision,
          Binary<Precision> compare,
          meta::select_if_arithmetic_t<Precision> = 0>
std::size_t find(const Vector<Precision>& vector)
{
    std::size_t arg = 0;
    for(std::size_t i = 1; i < vector.size(); ++i)
        if(compare(vector(arg), vector(i)))
            arg = i;

    return arg;
}

template <typename Precision,
          Binary<Precision> compare,
          meta::select_if_arithmetic_t<Precision> = 0>
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

LIQUE_FUNCTION_TPL
std::size_t argmin(const Vector<Precision>& vector)
{
    return find<Precision, comp::is_bigger>(vector);
}

LIQUE_FUNCTION_TPL
std::size_t argmax(const Vector<Precision>& vector)
{
    return find<Precision, comp::is_less>(vector);
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

LIQUE_FUNCTION_TPL
Precision min(const Vector<Precision>& vector)
{
    return vector(find<Precision, comp::is_bigger>(vector));
}

LIQUE_FUNCTION_TPL
Precision max(const Vector<Precision>& vector)
{
    return vector(find<Precision, comp::is_less>(vector));
}

LIQUE_FUNCTION_TPL
Precision mean(const Vector<Precision>& vector)
{
    Precision mean_value = 0.;

    for(std::size_t i = 0; i < vector.size(); ++i)
        mean_value += vector(i);

    return mean_value / static_cast<Precision>(vector.size());
}

LIQUE_FUNCTION_TPL
Precision std(
    const Vector<Precision>& vector,
    bool unbiased = false)
{
    Precision mean_value = mean(vector);
    Precision std_value;
    Precision buff;

    for(std::size_t i = 0; i < vector.size(); ++i)
    {
        buff = vector(i) - mean_value;
        std_value += buff * buff;
    }

    std_value /= static_cast<Precision>(vector.size() - unbiased);

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

LIQUE_FUNCTION_TPL
void dot(
    Vector<Precision>& buff,
    const Vector<Precision>& row_vector,
    const Matrix<Precision>& matrix)
{
    Precision temp;

    buff.fill(0.);

    for(std::size_t j = 0; j < row_vector.size(); ++j)
    {
        temp = row_vector(j);
        for(std::size_t i = 0; i < buff.size(); ++i)
           buff(i) += temp * matrix(j, i);
    }
}

LIQUE_FUNCTION_TPL
void dot(
    Vector<Precision>& buff,
    const Matrix<Precision>& matrix,
    const Vector<Precision>& col_vector)
{
    buff.fill(0.);

    for(std::size_t i = 0; i < buff.size(); ++i)
        for(std::size_t j = 0; j < col_vector.size(); ++j)
            buff(i) += matrix(i, j) * col_vector(j);
}

LIQUE_FUNCTION_TPL
void tensordot(
    Matrix<Precision>& buff2,
    const Vector<Precision>& col_vector,
    const Vector<Precision>& row_vector)
{
    for(std::size_t i = 0; i < col_vector.size(); ++i)
        for(std::size_t j = 0; j < row_vector.size(); ++j)
            buff2(i, j) = row_vector(j) * col_vector(i);
}

LIQUE_FUNCTION_TPL
Vector<Precision> dot(
    const Vector<Precision>& row_vector,
    const Matrix<Precision>& matrix)
{
    Vector<Precision> buff(matrix.shape().col());

    dot(buff, row_vector, matrix);

    return buff;
}

LIQUE_FUNCTION_TPL
Vector<Precision> dot(
    const Matrix<Precision>& matrix,
    const Vector<Precision>& col_vector)
{
    Vector<Precision> buff(matrix.shape().row());

    dot(buff, matrix, col_vector);

    return buff;
}

LIQUE_FUNCTION_TPL
Matrix<Precision> tensordot(
    const Vector<Precision>& col_vector,
    const Vector<Precision>& row_vector)
{
    Matrix<Precision> buff2(col_vector.size(), row_vector.size());

    tensordot(buff2, col_vector, row_vector);

    return buff2;
}

template <typename Precision, typename Function,
          meta::select_if_arithmetic_t<Precision> = 0>
void for_each(const Vector<Precision>& vector, Function func)
{
    for(std::size_t i = 0; i < vector.size(); ++i)
        func(vector(i));
}

template <typename Precision, typename Function,
          meta::select_if_arithmetic_t<Precision> = 0>
void for_each(const Matrix<Precision>& matrix, Function func)
{
    for(std::size_t i = 0; i < matrix.size(); ++i)
        func(matrix(i));
}

template <typename Precision,
          template <typename...> class Container,
          meta::select_if_arithmetic_t<Precision> = 0>
Vector<Precision> concate(const Container<Vector<Precision>>& list)
{
    std::size_t n = 0;

    for(const auto& it : list)
        n += it.size();

    Vector<Precision> vector(n);

    std::size_t i = 0;
    for(const auto& it : list)
        for(n = 0; n < it.size(); ++n, ++i)
            vector(i) = it(n);

    return vector;
}

LIQUE_FUNCTION_TPL
Vector<Precision> concate(std::initializer_list<Vector<Precision>> list)
{
    return concate<Precision, std::initializer_list>(list);
}

} // namespace lique

#include "Detail/MacroUnscope.hpp"

#endif // LIQUE_TOOL_HPP
