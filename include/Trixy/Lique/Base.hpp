#ifndef TRIXY_LIQUE_BASE_HPP
#define TRIXY_LIQUE_BASE_HPP

namespace trixy
{

namespace lique
{

struct TensorType
{
    struct base {};

    struct vector {};
    struct matrix {};
    struct tensor {};
};

struct TensorMode
{
    struct view {};
    struct own {};
};

template <typename Precision,
          typename TensorType = TensorType::tensor,
          typename TensorMode = TensorMode::own>
class Tensor;

} // namespace lique

} // namespace trixy

#endif // TRIXY_LIQUE_BASE_HPP
