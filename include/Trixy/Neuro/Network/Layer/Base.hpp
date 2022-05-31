#ifndef TRIXY_NETWORK_LAYER_BASE_HPP
#define TRIXY_NETWORK_LAYER_BASE_HPP

#include <functional> // function

#include <Trixy/Base.hpp> // LayerType, LayerMode

#include <Trixy/Neuro/Functional/Function/Base.hpp>
#include <Trixy/Neuro/Functional/Optimizer/Base.hpp>

#include <Trixy/Detail/MacroScope.hpp>

namespace trixy
{

namespace layer
{

template <typename LayerType, class Net, typename LayerMode>
class Layer;

template <class Net>
class ILayer
{
public:
    using Linear                = typename Net::Linear;

    using Vector                = typename Net::Vector;
    using Matrix                = typename Net::Matrix;
    using Tensor                = typename Net::Tensor;

    using XVector               = typename Net::XVector;
    using XMatrix               = typename Net::XMatrix;
    using XTensor               = typename Net::XTensor;

    using size_type             = typename Net::size_type;
    using precision_type        = typename Net::precision_type;

    using Generator             = std::function<precision_type()>; // type erasing

    using IActivation           = functional::activation::IActivation<precision_type>;

private:
    template <typename Ret, typename... Args>
    using Func = Ret (*)(void* const, Args...);

private:
    Func<void, Generator&> f_init = nullptr;

    Func<void, const Vector&> f_forward = nullptr; // will repair

    Func<void, IActivation*> f_connect = nullptr;

    Func<const Vector&> f_value = nullptr; // will repair

    Func<size_type> f_in = nullptr;
    Func<size_type> f_out = nullptr;

protected:
    template <class Derived>
    void initialize() noexcept
    {
        f_init = [](void *const self, Generator& gen) { TRIXY_DERIVED.init(gen); };
        f_forward = [](void *const self, const Vector& input)
        { TRIXY_DERIVED.forward(input); };

        f_connect = [](void *const self, IActivation* activation)
        { TRIXY_DERIVED.connect(activation); };

        f_value = [](void *const self) -> const Vector& { return TRIXY_DERIVED.value(); };

        f_in = [](void *const self) -> size_type { return TRIXY_DERIVED.in(); };
        f_out = [](void *const self) -> size_type { return TRIXY_DERIVED.out(); };
    }

public:
    virtual ~ILayer() = default;

    void init(Generator& generator) { f_init(this, generator); }

    void forward(const Vector& input) { f_forward(this, input); }

    void connect(IActivation* activation) { f_connect(this, activation); }

    const Vector& value() { return f_value(this); }

    size_type in() { return f_in(this); }
    size_type out() { return f_out(this); }
};

template <class Net>
class ITrainLayer : public ILayer<Net>
{
    using Base = ILayer<Net>;

public:
    using typename Base::Linear;

    using typename Base::Vector;
    using typename Base::Matrix;
    using typename Base::Tensor;

    using typename Base::XVector;
    using typename Base::XMatrix;
    using typename Base::XTensor;

    using typename Base::size_type;
    using typename Base::precision_type;

    using typename Base::Generator;

    using IOptimizer  = train::IOptimizer_<Net>;

private:
    template <typename Ret, typename... Args>
    using Func = Ret (*)(void* const, Args...);

private:
    Func<void, const Vector&, const Vector&> f_backward = nullptr;
    Func<void, const Vector&, const Vector&> f_first_backward = nullptr;

    Func<void> f_reset_grad = nullptr;

    Func<void, precision_type> f_normalize_grad = nullptr;

    Func<void, IOptimizer&> f_update = nullptr;
    Func<void, IOptimizer&> f_quick_update = nullptr;

    Func<void> f_accumulate_grad = nullptr;

    Func<XVector&> f_delta = nullptr;

protected:
    template <class Derived>
    void initialize() noexcept
    {
        // You should call ILayer::initialize function
        this->ILayer<Net>::template initialize<Derived>();

        f_backward = [](void *const self, const Vector& input,  const Vector& idelta)
        { TRIXY_DERIVED.backward(input, idelta); };

        f_first_backward = [](void *const self, const Vector& input, const Vector& idelta)
        { TRIXY_DERIVED.first_backward(input, idelta); };

        f_reset_grad = [](void *const self) { TRIXY_DERIVED.reset_grad(); };

        f_normalize_grad = [](void *const self, precision_type alpha)
        { TRIXY_DERIVED.normalize_grad(alpha); };

        f_update = [](void *const self, IOptimizer& optimizer)
        { TRIXY_DERIVED.update(optimizer); };

        f_quick_update = [](void *const self, IOptimizer& optimizer)
        { TRIXY_DERIVED.quick_update(optimizer); };

        f_accumulate_grad = [](void *const self) { TRIXY_DERIVED.accumulate_grad(); };

        f_delta = [](void *const self) -> XVector& { return TRIXY_DERIVED.delta(); };
    }

public:
    virtual ~ITrainLayer() = default;

    void backward(const Vector& input, const Vector& idelta)
    { f_backward(this, input, idelta); }

    void first_backward(const Vector& input, const Vector& idelta)
    { f_first_backward(this, input, idelta); }

    void reset_grad() { f_reset_grad(this); }
    void normalize_grad(precision_type alpha) { f_normalize_grad(this, alpha); }

    void update(IOptimizer& optimizer) { f_update(this, optimizer); }
    void quick_update(IOptimizer& optimizer) { f_quick_update(this, optimizer); }

    void accumulate_grad() { f_accumulate_grad(this); }

    XVector& delta() { return f_delta(this); }
};

} // namespace layer

} // namespace trixy

#include <Trixy/Detail/MacroUnscope.hpp>

#endif // TRIXY_NETWORK_LAYER_BASE_HPP
