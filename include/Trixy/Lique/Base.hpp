#ifndef TRIXY_LIQUE_BASE_HPP
#define TRIXY_LIQUE_BASE_HPP

#include <Trixy/Base.hpp> // TensorType, TensorMode

namespace trixy
{

namespace lique
{

template <typename Precision,
          typename TensorType = TensorType::tensor,
          typename TensorMode = TensorMode::own>
class Tensor;

} // namespace lique

} // namespace trixy

#endif // TRIXY_LIQUE_BASE_HPP
