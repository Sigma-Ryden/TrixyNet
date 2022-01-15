#ifndef LIQUE_BASE_TENSOR_HPP
#define LIQUE_BASE_TENSOR_HPP

namespace lique
{

namespace detail
{

struct TensorType
{
    struct _1D;
    struct _2D;
};

} // namespace detail

template <typename Precision, typename tensor_type, typename enable = void>
class Tensor;

} // namespace lique

#endif // LIQUE_BASE_TENSOR_HPP
