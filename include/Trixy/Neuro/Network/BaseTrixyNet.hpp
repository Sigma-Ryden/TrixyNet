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
          template <typename P> class LinearType,
          template <typename...> class ContainerType,
          typename PrecisionType,
          typename... Args>
class TrixyNet;

} // namespace trixy

#endif // BASE_TRIXY_NET_HPP
