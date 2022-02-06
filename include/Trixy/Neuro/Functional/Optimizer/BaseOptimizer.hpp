#ifndef BASE_OPTIMIZER_HPP
#define BASE_OPTIMIZER_HPP

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
    Func<void, void *const,
         precision_type> ptr_derived_set_learning_rate;

    Func<void, void *const,
         const Container<LVector>&,
         const Container<LMatrix>&> ptr_derived_update;

protected:
    virtual ~IOptimizer() {}

    template <class Derived> void initialize() noexcept
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

} // namespace train

} // namespace trixy

#endif // BASE_OPTIMIZER_HPP
