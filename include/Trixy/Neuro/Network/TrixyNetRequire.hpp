#ifndef TRIXY_NET_REQUIRE_HPP
#define TRIXY_NET_REQUIRE_HPP

#include "Trixy/Neuro/Network/BaseTrixyNet.hpp"

#include "Trixy/Require/PrecisionRequire.hpp"

#include "Trixy/Require/VectorRequire.hpp"
#include "Trixy/Require/MatrixRequire.hpp"

#include "Trixy/Require/LinearRequire.hpp"

#include "Trixy/Require/ContainerRequire.hpp"

#include "Trixy/Neuro/Detail/MacroScope.hpp"

namespace trixy
{

TRIXY_NET_TPL_DECLARATION
struct TRIXY_NET_REQUIRE_TPL(TrixyNetType::FeedForward)
{
public:
    using type = TrixyNetType::FeedForward;

protected:
    using Precision         = PrecisionType;

    using Vector            = VectorType<Precision, Args...>;
    using Matrix            = MatrixType<Precision, Args...>;

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

#include "Trixy/Neuro/Detail/MacroUnscope.hpp"

#endif // TRIXY_NET_REQUIRE_HPP
