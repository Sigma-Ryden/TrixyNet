#ifndef BASE_REQUIRE_HPP
#define BASE_REQUIRE_HPP

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

#endif // BASE_REQUIRE_HPP
