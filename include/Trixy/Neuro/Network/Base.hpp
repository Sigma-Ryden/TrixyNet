#ifndef TRIXY_NETWORK_BASE_HPP
#define TRIXY_NETWORK_BASE_HPP

#include <Trixy/Base.hpp> // TrixyNetType

namespace trixy
{

template <typename TypeSet, typename TrixyNetType = TrixyNetType::Unified>
class TrixyNet;

namespace guard
{

template <typename TypeSet, typename TrixyNetType>
struct TrixyNetRequire;

} // namespace guard

} // namespace trixy

#endif // TRIXY_NETWORK_BASE_HPP
