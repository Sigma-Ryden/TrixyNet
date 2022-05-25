// This file contains all internal type definitions
// You MUST NOT include here any files
#ifndef TRIXY_BASE_HPP
#define TRIXY_BASE_HPP

namespace trixy
{

struct TrixyNetType
{
    struct FeedForward {};
    struct Convolutional {};
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

namespace memory
{

struct LockerType
{
    struct container {};
    struct vector {};
    struct matrix {};
    struct tensor {};
};

} // namespace memory

namespace guard
{

struct RequireType
{
    struct precision {};

    struct vector {};
    struct matrix {};
    struct tensor {};

    struct linear {};

    struct container {};
};

} // namespace guard

} // namespace trixy

#endif // TRIXY_BASE_HPP
