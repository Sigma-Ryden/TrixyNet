#ifndef TRIXY_REQUIRE_BASE_HPP
#define TRIXY_REQUIRE_BASE_HPP

namespace trixy
{

struct RequireType
{
    struct precision { using type = precision; };

    struct vector { using type = vector; };
    struct matrix { using type = matrix; };

    struct linear { using type = linear; };

    struct container { using type = container; };
};

template <class Requirable, typename RequireType>
struct Require;

} // namespace trixy

#endif // TRIXY_REQUIRE_BASE_HPP
