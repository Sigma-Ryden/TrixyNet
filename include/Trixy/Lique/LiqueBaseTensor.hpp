#ifndef LIQUE_BASE_TENSOR_HPP
#define LIQUE_BASE_TENSOR_HPP

namespace trixy
{

namespace lique
{

struct TensorType
{
    struct vector { using type = vector; };
    struct matrix { using type = matrix; };
};

template <typename Precision, typename tensor_type, typename enable = void>
class Tensor;

} // namespace lique

} // namespace trixy

#endif // LIQUE_BASE_TENSOR_HPP
