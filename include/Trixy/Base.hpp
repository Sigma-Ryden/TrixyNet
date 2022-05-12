// This file contains all internal type definitions
// You MUST NOT include here any files
#ifndef TRIXY_BASE_HPP
#define TRIXY_BASE_HPP

namespace trixy
{

namespace lique
{

struct TensorType
{
    struct base {};

    struct vector {};
    struct matrix {};
    struct tensor {};
};

struct TensorMode
{
    struct view {};
    struct own {};
};

} // namespace lique

struct TrixyNetType
{
    struct FeedForward {};
};

struct RegressionType
{
    struct Linear {};
    struct Polynomial {};
};

struct LayerMode
{
    struct Normal {};
    struct Train {};
};

struct LockerType
{
    struct container {};
    struct vector {};
    struct matrix {};
    struct tensor {};
};

struct RequireType
{
    struct precision {};

    struct vector {};
    struct matrix {};
    struct tensor {};

    struct linear {};

    struct container {};
};

} // namespace trixy

#endif // TRIXY_BASE_HPP
