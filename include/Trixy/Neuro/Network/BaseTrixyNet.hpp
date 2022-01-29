#ifndef BASE_TRIXY_NET_HPP
#define BASE_TRIXY_NET_HPP

namespace trixy
{

template <template <typename P, typename...> class Tensor1D,
          template <typename P, typename...> class Tensor2D,
          template <typename P> class Linear,
          template <typename...> class Container,
          typename Precision,
          typename... Args>
class FeedForwardNet;

} // namespace trixy

#endif // BASE_TRIXY_NET_HPP
