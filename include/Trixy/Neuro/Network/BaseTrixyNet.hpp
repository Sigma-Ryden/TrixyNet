#ifndef BASE_TRIXY_NET_HPP
#define BASE_TRIXY_NET_HPP

namespace trixy
{

template <template <typename, typename...> class Vector,
          template <typename, typename...> class Matrix,
          template <template <typename, typename...> class V,
                    template <typename, typename...> class M,
                    typename P, typename...>
          class Linear,
          template <typename Type> class Container,
          typename Precision,
          typename... Args>
class FeedForwardNet;

} // namespace trixy

#endif // BASE_TRIXY_NET_HPP
