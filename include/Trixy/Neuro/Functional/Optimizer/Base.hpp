#ifndef TRIXY_OPTIMIZER_BASE_HPP
#define TRIXY_OPTIMIZER_BASE_HPP

#include <unordered_map> // unordered_map

#include <Trixy/Detail/TrixyMeta.hpp>
#include <Trixy/Neuro/Functional/Id.hpp>

#define _TRIXY_DEF_OPTIMIZER_HELPER(id_type, T)                                                         \
    struct T {                                                                                          \
        template <id_type id>                                                                           \
        using type = ::trixy::meta::select_for<id == id_type::T, T>;                                    \
    };

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
    _TRIXY_DEF_OPTIMIZER_HELPER(id_type, undefined)
    _TRIXY_DEF_OPTIMIZER_HELPER(id_type, grad_descent)
    _TRIXY_DEF_OPTIMIZER_HELPER(id_type, stograd_descent)
    _TRIXY_DEF_OPTIMIZER_HELPER(id_type, momentum)
    _TRIXY_DEF_OPTIMIZER_HELPER(id_type, nestorov)
    _TRIXY_DEF_OPTIMIZER_HELPER(id_type, ada_grad)
    _TRIXY_DEF_OPTIMIZER_HELPER(id_type, rms_prop)
    _TRIXY_DEF_OPTIMIZER_HELPER(id_type, adam)

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

// clean up
#undef _TRIXY_DEF_OPTIMIZER_HELPER

#endif // TRIXY_OPTIMIZER_BASE_HPP
