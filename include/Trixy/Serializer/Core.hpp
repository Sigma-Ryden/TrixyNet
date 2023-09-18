#ifndef TRIXY_SERIALIZER_HPP
#define TRIXY_SERIALIZER_HPP

#define SF_GARBAGE_CHECK_DISABLE

#include <Trixy/Serializer/SerializationFixture.hpp>

namespace trixy
{

namespace meta
{

template <class Archive> constexpr bool is_iarchive(Archive& archive) noexcept
{
    return sf::meta::is_iarchive<Archive>::value;
}

template <class Archive> constexpr bool is_oarchive(Archive& archive) noexcept
{
    return sf::meta::is_oarchive<Archive>::value;
}

} // namespace meta

} // namespace trixy

#endif // TRIXY_SERIALIZER_HPP
