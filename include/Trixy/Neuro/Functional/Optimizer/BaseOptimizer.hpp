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

template <class Optimizeriable>
class IOptimizer
{
private:
    template <class... T>
    using Container         = typename Optimizeriable::template Container<T...>;

    using LVector           = typename Optimizeriable::LVector;
    using LMatrix           = typename Optimizeriable::LMatrix;

    using precision_type    = typename Optimizeriable::precision_type;

public:
    template <typename Ret = void, typename... Args>
    using Func = Ret (*)(Args...);

private:
    TRIXY_HAS_FUNCTION_HELPER(set_learning_rate);
    TRIXY_HAS_FUNCTION_HELPER(update);

private:
    Func<void, void *const,
         precision_type> ptr_derived_set_learning_rate;

    Func<void, void *const,
         const Container<LVector>&,
         const Container<LMatrix>&> ptr_derived_update;

protected:
    virtual ~IOptimizer() {}

    template <class Derived>
    TRIXY_ENABLE(
        has_set_learning_rate<Derived, void, precision_type>,
        has_update<Derived, void, const Container<LVector>&, const Container<LMatrix>&>)
    initialize() noexcept
    {
        ptr_derived_set_learning_rate = [] (
            void *const self,
            precision_type value) noexcept
        {
            static_cast<Derived*>(self)->set_learning_rate(value);
        };

        ptr_derived_update = [] (
            void *const self,
            const Container<LVector>& gradB,
            const Container<LMatrix>& gradW) noexcept
        {
            static_cast<Derived*>(self)->update(gradB, gradW);
        };
    }

public:
    IOptimizer() noexcept
        : ptr_derived_set_learning_rate(nullptr)
        , ptr_derived_update(nullptr)
    {
    }

    void set_learning_rate(precision_type value) noexcept
    {
        ptr_derived_set_learning_rate(this, value);
    }

    void update(const Container<LVector>& gradB,
                const Container<LMatrix>& gradW) noexcept
    {
        ptr_derived_update(this, gradB, gradW);
    }
};

struct OptimizerType
{
private:
    template <class... Bn>
    using disjunction_t = typename meta::disjunction<Bn...>::type;

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
    template <id_type id> using type_from = disjunction_t
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
