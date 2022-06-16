#ifndef TRIXY_NETWORK_LAYER_FUNCTION_DETAIL_HPP
#define TRIXY_NETWORK_LAYER_FUNCTION_DETAIL_HPP

#include <Trixy/Detail/TrixyMeta.hpp>
#include <Trixy/Lique/Detail/LiqueMeta.hpp>

#include <Trixy/Detail/MacroScope.hpp>

namespace trixy
{

namespace utility
{

template <typename T>
struct IndexPair
{
private:
    static constexpr bool require = std::is_integral<T>::value;

    static_assert(require, "'T' should be an integral type.");

public:
    T i;
    T j;

    IndexPair(T i, T j) : i(i), j(j) {}
    IndexPair() : IndexPair(0, 0) {}
};

template <class Tensor, class Predicate,
          typename size_type = typename Tensor::size_type,
          lique::meta::as_tensor<Tensor> = 0>
IndexPair<size_type> find(
    Tensor& tensor, size_type d, size_type i, size_type j,
    size_type block_width, size_type block_height,
    Predicate predicate) TRIXY_NOEXCEPT_IF(noexcept(predicate))
{
    const size_type i_end = i + block_height;
    const size_type j_end = j + block_width;

    IndexPair<size_type> position(i, j);

    for (auto i_ = i; i_ < i_end; ++i_)
    {
        for (auto j_ = j; j_ < j_end; ++j_)
        {
            if (predicate(tensor(d, position.i, position.j),  tensor(d, i_, j_)))
            {
                position.i = i_;
                position.j = j_;
            }
        }
    }

    return position;
}

} // namespace utility

} // namespace trixy

#include <Trixy/Detail/MacroUnscope.hpp>

#endif // TRIXY_NETWORK_LAYER_FUNCTION_DETAIL_HPP
