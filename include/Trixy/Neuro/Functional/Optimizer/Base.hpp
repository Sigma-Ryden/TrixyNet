#ifndef TRIXY_OPTIMIZER_BASE_HPP
#define TRIXY_OPTIMIZER_BASE_HPP

#include <unordered_map> // unordered_map

#include <Trixy/Detail/TrixyMeta.hpp>
#include <Trixy/Neuro/Functional/Id.hpp>

#include <Trixy/Detail/MacroScope.hpp>

namespace trixy
{

namespace train
{

struct OptimizerTypeSet
{
    template <typename Key, typename Value>
    using Table = std::unordered_map<Key, Value>;
};

template <class OptimizerType,
          class Optimizeriable,
          class TypeSet = OptimizerTypeSet,
          typename enable = void>
class Optimizer;

template <class Optimizeriable, typename enable = void>
class IOptimizer;

struct OptimizerType
{
private:
    template <class... Bn>
    using switch_type = typename meta::or_<Bn...>::type;

    using id_type = trixy::functional::OptimizationId;

public:
    TRIXY_DEF_OPTIMIZER_HELPER(id_type, undefined);
    TRIXY_DEF_OPTIMIZER_HELPER(id_type, grad_descent);
    TRIXY_DEF_OPTIMIZER_HELPER(id_type, stograd_descent);
    TRIXY_DEF_OPTIMIZER_HELPER(id_type, momentum);
    TRIXY_DEF_OPTIMIZER_HELPER(id_type, nestorov);
    TRIXY_DEF_OPTIMIZER_HELPER(id_type, ada_grad);
    TRIXY_DEF_OPTIMIZER_HELPER(id_type, rms_prop);
    TRIXY_DEF_OPTIMIZER_HELPER(id_type, adam);

public:
    template <id_type id> using type_from = switch_type
    <
        undefined::type<id>,
        grad_descent::type<id>,
        stograd_descent::type<id>,
        momentum::type<id>,
        nestorov::type<id>,
        ada_grad::type<id>,
        rms_prop::type<id>,
        adam::type<id>
    >;
};

} // namespace train

} // namespace trixy

#include <Trixy/Detail/MacroUnscope.hpp>

#endif // TRIXY_OPTIMIZER_BASE_HPP
