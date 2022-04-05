#ifndef TRIXY_NETWORK_REQUIRE_HPP
#define TRIXY_NETWORK_REQUIRE_HPP

#include <Trixy/Require/Base.hpp>

#include <Trixy/Require/Precision.hpp>

#include <Trixy/Require/Vector.hpp>
#include <Trixy/Require/Matrix.hpp>

#include <Trixy/Require/Linear.hpp>

#include <Trixy/Require/Container.hpp>

#include <Trixy/Neuro/Detail/MacroScope.hpp>

namespace trixy
{

TRIXY_NET_TPL_DECLARATION
struct TRIXY_NET_REQUIRE_TPL(TrixyNetType::FeedForward)
{
public:
    using type = TrixyNetType::FeedForward;

protected:
    using Precision         = PrecisionType;

    using Vector            = VectorType<Precision, Pack...>;
    using Matrix            = MatrixType<Precision, Pack...>;

    using Linear            = LinearType<Precision>;

    using Container         = ContainerType<Precision>;

protected:
    using precision_require = typename PrecisionRequire<Precision>::type;

    using vector_require    = typename VectorRequire<Vector>::type;
    using matrix_require    = typename MatrixRequire<Matrix>::type;

    using linear_require    = typename LinearRequire<Linear>::type;

    using container_require = typename ContainerRequire<Container>::type;
};

} // namespace trixy

#include <Trixy/Neuro/Detail/MacroUnscope.hpp>

#endif // TRIXY_NETWORK_REQUIRE_HPP
