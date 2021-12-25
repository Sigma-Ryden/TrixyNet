#ifndef FEEDFORWARD_NEURO_BASE_HPP
#define FEEDFORWARD_NEURO_BASE_HPP

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
class FeedForwardNeuro;

/*__EXPERIMENTAL__*/
template <template <typename, typename...> class Vector,
          template <typename, typename...> class Matrix,
          template <template <typename, typename...> class V,
                    template <typename, typename...> class M,
                    typename P, typename...>
          class Linear,
          template <typename Type> class Container,
          typename Precision,
          typename... Args>
class FeedForwardNeuroLess;

} // namespace trixy

#endif // FEEDFORWARD_NEURO_BASE_HPP
