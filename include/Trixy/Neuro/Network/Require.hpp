#ifndef TRIXY_NETWORK_REQUIRE_HPP
#define TRIXY_NETWORK_REQUIRE_HPP

#include <Trixy/Neuro/Network/Base.hpp>

#include <Trixy/Require/Core.hpp>

#include <Trixy/Neuro/Detail/MacroScope.hpp>

namespace trixy
{

namespace guard
{

TRIXY_NET_TPL_DECLARATION
struct TRIXY_NET_REQUIRE_TPL(TrixyNetType::Unified)
{
public:
    using type = TrixyNetType::FeedForward;

protected:
    using precision_type    = typename TypeSet::precision_type;

    using Vector            = typename TypeSet::Vector;
    using Matrix            = typename TypeSet::Matrix;

    using Linear            = typename TypeSet::Linear;

    using Container         = typename TypeSet::template Container<precision_type>;

protected:
    using require_precision = typename PrecisionRequire<precision_type>::type;

    using require_vector    = typename VectorRequire<Vector>::type;
    using require_matrix    = typename MatrixRequire<Matrix>::type;

    using require_linear    = typename LinearRequire<Linear>::type;

    using require_container = typename ContainerRequire<Container>::type;
};

TRIXY_NET_TPL_DECLARATION
struct TRIXY_NET_REQUIRE_TPL(TrixyNetType::FeedForward)
{
public:
    using type = TrixyNetType::FeedForward;

protected:
    using precision_type    = typename TypeSet::precision_type;

    using Vector            = typename TypeSet::Vector;
    using Matrix            = typename TypeSet::Matrix;
    using Tensor            = typename TypeSet::Tensor;

    using Linear            = typename TypeSet::Linear;

    using Container         = typename TypeSet::template Container<precision_type>;

protected:
    using require_precision = typename PrecisionRequire<precision_type>::type;

    using require_vector    = typename VectorRequire<Vector>::type;
    using require_matrix    = typename MatrixRequire<Matrix>::type;
    using require_tensor    = typename TensorRequire<Tensor>::type;

    using require_linear    = typename LinearRequire<Linear>::type;

    using require_container = typename ContainerRequire<Container>::type;
};

} // namespace guard

} // namespace trixy

#include <Trixy/Neuro/Detail/MacroUnscope.hpp>

#endif // TRIXY_NETWORK_REQUIRE_HPP
