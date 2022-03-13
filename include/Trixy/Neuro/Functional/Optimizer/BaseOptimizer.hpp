#ifndef BASE_OPTIMIZER_HPP
#define BASE_OPTIMIZER_HPP

#include "Trixy/Detail/TrixyMeta.hpp"
#include "Trixy/Neuro/Functional/IdFunctional.hpp"

#include "Trixy/Detail/MacroScope.hpp"

namespace trixy
{

namespace train
{

template <class Optimizeriable, class OptimizerType, typename enable = void>
class Optimizer;

template <class Derived, class Optimizeriable, typename enable = void>
class IOptimizer;

struct OptimizerType
{
private:
    template <class... Bn>
    using switch_type = typename meta::disjunction<Bn...>::type;

    using id_type = trixy::functional::OptimizationId;

public:
    TRIXY_DEF_OPT_HELPER(id_type, undefined);
    TRIXY_DEF_OPT_HELPER(id_type, grad_descent);
    TRIXY_DEF_OPT_HELPER(id_type, momentum);
    TRIXY_DEF_OPT_HELPER(id_type, nestorov);
    TRIXY_DEF_OPT_HELPER(id_type, ada_grad);
    TRIXY_DEF_OPT_HELPER(id_type, rms_prop);
    TRIXY_DEF_OPT_HELPER(id_type, adam);

public:
    template <id_type id> using type_from = switch_type
    <
        undefined::def<id>,
        grad_descent::def<id>,
        momentum::def<id>,
        nestorov::def<id>,
        ada_grad::def<id>,
        rms_prop::def<id>,
        adam::def<id>
    >;
};

} // namespace train

} // namespace trixy

#include "Trixy/Detail/MacroUnscope.hpp"

#endif // BASE_OPTIMIZER_HPP
