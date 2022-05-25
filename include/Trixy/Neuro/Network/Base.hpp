#ifndef TRIXY_NETWORK_BASE_HPP
#define TRIXY_NETWORK_BASE_HPP

#include <Trixy/Base.hpp> // TrixyNetType

namespace trixy
{

template <typename TrixyNetType, typename TypeSet>
class TrixyNet;

namespace guard
{

template <typename TrixyNetType, typename TypeSet>
struct TrixyNetRequire;

} // namespace guard

} // namespace trixy

#endif // TRIXY_NETWORK_BASE_HPP
