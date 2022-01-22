#ifndef BASE_OPTIMIZER_HPP
#define BASE_OPTIMIZER_HPP

namespace trixy
{

namespace train
{

template <class Optimizeriable, class OptimizationType, typename enable = void>
class Optimizer;

template <class Optimizeriable>
class IOptimizer
{
private:
    template <class T>
    using Container        = typename Optimizeriable::template ContainerType<T>;

    using Tensor1D         = typename Optimizeriable::Tensor1D;
    using Tensor2D         = typename Optimizeriable::Tensor2D;

    using precision_type   = typename Optimizeriable::precision_type; 

private:
    void (*ptr_derived_set_learning_rate)(
        void *const,
        precision_type
    );

    void (*ptr_derived_update)(
        void *const,
        Container<Tensor1D>&,
        Container<Tensor2D>&,
        const Container<Tensor1D>&,
        const Container<Tensor2D>&
    );

protected:
    virtual ~IOptimizer() {}

    template <class Derived>
    void initialize() noexcept
    {
        ptr_derived_set_learning_rate = &derived_set_learning_rate<Derived>;
        ptr_derived_update            = &derived_update<Derived>;
    }

private:
    template <class Derived>
    static void derived_update(
        void *const self,
        Container<Tensor1D>& B,
        Container<Tensor2D>& W,
        const Container<Tensor1D>& gradB,
        const Container<Tensor2D>& gradW) noexcept
    {
        static_cast<Derived*>(self)->update(B, W, gradB, gradW);
    }

    template <class Derived>
    static void derived_set_learning_rate(
        void *const self,
        precision_type new_learning_rate) noexcept
    {
        static_cast<Derived*>(self)->set_learning_rate(new_learning_rate);
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

    void update(Container<Tensor1D>& B,
                Container<Tensor2D>& W,
                const Container<Tensor1D>& gradB,
                const Container<Tensor2D>& gradW) noexcept
    {
        ptr_derived_update(this, B, W, gradB, gradW);
    }
};

} // namespace train

} // namespace trixy

#endif // BASE_OPTIMIZER_HPP
