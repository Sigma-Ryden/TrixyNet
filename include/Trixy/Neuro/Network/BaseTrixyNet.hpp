#ifndef BASE_TRIXY_NET_HPP
#define BASE_TRIXY_NET_HPP

namespace trixy
{

struct TrixyNetType
{
    struct FeedForward { using type = FeedForward; };
};

template <class TrixyNetType,
          template <typename P, typename...> class VectorType,
          template <typename P, typename...> class MatrixType,
          template <typename P, typename...> class LinearType,
          template <typename T, typename...> class ContainerType,
          typename PrecisionType,
          typename... Args>
class TrixyNet;

template <class TrixyNetType,
          template <typename P, typename...> class VectorType,
          template <typename P, typename...> class MatrixType,
          template <typename P, typename...> class LinearType,
          template <typename T, typename...> class ContainerType,
          typename PrecisionType,
          typename... Args>
struct TrixyNetRequire;

} // namespace trixy

#endif // BASE_TRIXY_NET_HPP
