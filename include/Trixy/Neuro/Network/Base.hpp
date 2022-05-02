#ifndef TRIXY_NETWORK_BASE_HPP
#define TRIXY_NETWORK_BASE_HPP

namespace trixy
{

struct TrixyNetType
{
    struct FeedForward { using type = FeedForward; };
};


template <typename TrixyNetType, typename TypeSet>
class TrixyNet;

template <typename TrixyNetType, typename TypeSet>
struct TrixyNetRequire;

} // namespace trixy

#endif // TRIXY_NETWORK_BASE_HPP
