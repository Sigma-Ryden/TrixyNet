#ifndef BASE_OPTIMIZER_HPP
#define BASE_OPTIMIZER_HPP

namespace trixy
{

namespace train
{

template <class Optimizeriable, class OptimizationType, typename enable = void>
class Optimizer;

template <class Optimizeriable, template <class> class Derived>
class BaseOptimizer
{
private:
    using DerivedOptimizer = Derived<Optimizeriable>;

    template <class T>
    using Container        = typename Optimizeriable::template ContainerType<T>;

    using Tensor1D         = typename Optimizeriable::Tensor1D;
    using Tensor2D         = typename Optimizeriable::Tensor2D;

    using precision_type   = typename Optimizeriable::precision_type;

public:
    void setLearnRate(precision_type new_learning_rate) noexcept
    {
        static_cast<DerivedOptimizer&>(*this).setLearnRate(new_learning_rate);
    }

    void update(Container<Tensor1D>& bias,
                Container<Tensor2D>& weight,
                const Container<Tensor1D>& gradBias,
                const Container<Tensor2D>& gradWeight) noexcept
    {
        static_cast<DerivedOptimizer&>(*this).update(bias, weight, gradBias, gradWeight);
    }
};

} // namespace train

} // namespace trixy

#endif // BASE_OPTIMIZER_HPP
