#ifndef BASE_OPTIMIZER_HPP
#define BASE_OPTIMIZER_HPP

#include "Trixy/Detail/TrixyMeta.hpp"
#include "Trixy/Neuro/Functional/IdFunctional.hpp"

#include "Trixy/Neuro/Detail/MacroScope.hpp"

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

    template <class... T>
    using LContainer        = typename Optimizeriable::template LContainer<T...>;

    using LVector           = typename Optimizeriable::LVector;
    using LMatrix           = typename Optimizeriable::LMatrix;

    using precision_type    = typename Optimizeriable::precision_type;
    using size_type         = typename Optimizeriable::size_type;

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
    typename std::enable_if<
        has_set_learning_rate<Derived, void, precision_type>::value &&
        has_update<Derived, void, const Container<LVector>&, const Container<LMatrix>&>::value>::type
    initialize() noexcept
    {
        ptr_derived_set_learning_rate = [] (
            void *const self,
            precision_type new_learning_rate) noexcept
        {
            static_cast<Derived*>(self)->set_learning_rate(new_learning_rate);
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

    void set_learning_rate(precision_type new_learning_rate) noexcept
    {
        ptr_derived_set_learning_rate(this, new_learning_rate);
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
    using id_type = trixy::functional::OptimizationId;

public:
    TRIXY_CHECK_TYPE_HELPER(id_type, undefined);
    TRIXY_CHECK_TYPE_HELPER(id_type, grad_descent);
    TRIXY_CHECK_TYPE_HELPER(id_type, momentum);
    TRIXY_CHECK_TYPE_HELPER(id_type, nestorov);
    TRIXY_CHECK_TYPE_HELPER(id_type, ada_grad);
    TRIXY_CHECK_TYPE_HELPER(id_type, rms_prop);
    TRIXY_CHECK_TYPE_HELPER(id_type, adam);

private:
    template <id_type id> struct from : meta::disjunction<
        undefined::check<id>,
        grad_descent::check<id>,
        momentum::check<id>,
        nestorov::check<id>,
        ada_grad::check<id>,
        rms_prop::check<id>,
        adam::check<id>>
    {};

public:
    template <id_type id> using type_from = typename from<id>::type;
};

} // namespace train

} // namespace trixy

#include "Trixy/Neuro/Detail/MacroUnscope.hpp"

#endif // BASE_OPTIMIZER_HPP
