#ifndef LIQUE_BASE_TENSOR_HPP
#define LIQUE_BASE_TENSOR_HPP

namespace lique
{

struct TensorType
{
    struct vector;
    struct matrix;
};

struct LockerType
{
    struct lock;
    struct free;
};

template <typename Precision, typename tensor_type,
          typename locker_type = LockerType::free,
          typename enable = void>
class Tensor;

} // namespace lique

#endif // LIQUE_BASE_TENSOR_HPP
