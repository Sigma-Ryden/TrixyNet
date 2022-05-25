// __EXPERIMENTAL__
#ifndef TRIXY_NETWORK_LAYER_HPP
#define TRIXY_NETWORK_LAYER_HPP

#include <Trixy/Base.hpp> // LayerMode

#define DERIVED (*static_cast<Derived*>(self))

namespace trixy
{

namespace layer
{

template <class Net>
class ILayer
{
public:
    using Vector    = typename Net::Vector;
    using Matrix    = typename Net::Matrix;

    using XVector   = typename Net::XVector;
    using XMatrix   = typename Net::XMatrix;

    using size_type = typename Net::size_type;

private:
    template <typename Ret, typename... Args>
    using Func = Ret (*)(void* const, Args...);

private:
    Func<void, const Vector&> f_forward = nullptr; // will repair

    Func<const Vector&> f_value = nullptr; // will repair

    Func<XVector&> f_bias = nullptr;
    Func<XMatrix&> f_weight = nullptr;

    Func<size_type> f_in = nullptr;
    Func<size_type> f_out = nullptr;

protected:
    template <class Derived>
    void initialize() noexcept
    {
        f_forward = [](void *const self, const Vector& input)
        { DERIVED.forward(input); };

        f_value = [](void *const self) -> const Vector& { return DERIVED.value(); };

        f_bias = [](void *const self) -> XVector& { return DERIVED.B(); };
        f_weight = [](void *const self) -> XMatrix& { return DERIVED.W(); };

        f_in = [](void *const self) -> size_type { return DERIVED.in(); };
        f_out = [](void *const self) -> size_type { return DERIVED.out(); };
    }

public:
    virtual ~ILayer() = default;

    void forward(const Vector& input) { f_forward(this, input); }

    const Vector& value() { return f_value(this); }

    XVector& B() { return f_bias(this); }
    XMatrix& W() { return f_weight(this); }

    size_type in() { return f_in(this); }
    size_type out() { return f_out(this); }
};

template <class Net>
class ITrainLayer : public ILayer<Net>
{
public:
    using Vector    = typename Net::Vector;
    using Matrix    = typename Net::Matrix;

    using XVector   = typename Net::XVector;
    using XMatrix   = typename Net::XMatrix;

    using size_type = typename Net::size_type;

private:
    template <typename Ret, typename... Args>
    using Func = Ret (*)(void* const, Args...);

private:
    Func<void, const Vector&, const Vector&> f_backward = nullptr;
    Func<void, const Vector&, const Vector&> f_backward0 = nullptr;

    Func<XVector&> f_delta = nullptr;
    Func<XVector&> f_grad_bias = nullptr;
    Func<XMatrix&> f_grad_weight = nullptr;

protected:
    template <class Derived>
    void initialize() noexcept
    {
        // You should call ILayer::initialize function
        this->ILayer<Net>::template initialize<Derived>();

        f_backward = [](void *const self, const Vector& input,  const Vector& idelta)
        { DERIVED.backward(input, idelta); };

        f_backward0 = [](void *const self, const Vector& input, const Vector& idelta)
        { DERIVED.backward0(input, idelta); };

        f_delta = [](void *const self) -> XVector& { return DERIVED.delta(); };

        f_grad_bias = [](void *const self) -> XVector& { return DERIVED.gradB(); };
        f_grad_weight = [](void *const self) -> XMatrix& { return DERIVED.gradW(); };
    }

public:
    virtual ~ITrainLayer() = default;

    void backward(const Vector& input, const Vector& idelta) { f_backward(this, input, idelta); }
    void backward0(const Vector& input, const Vector& idelta) { f_backward0(this, input, idelta); }

    XVector& delta() { return f_delta(this); }
    XVector& gradB() { return f_grad_bias(this); }
    XMatrix& gradW() { return f_grad_weight(this); }
};

template <class Net, class Activation, typename LayerMode = LayerMode::Train>
class FullyConnected;

template <class Net, class Activation>
class FullyConnected<Net, Activation, LayerMode::Train> : public ITrainLayer<Net>
{
public:
    using Base = ITrainLayer<Net>;

public:
    using Vector                = typename Net::Vector;
    using Matrix                = typename Net::Matrix;

    using XVector               = typename Net::XVector;
    using XMatrix               = typename Net::XMatrix;

    using Linear                = typename Net::Linear;

    using size_type             = typename Net::size_type;

private:
    XVector buff_;

    XVector H_;
    XVector B_;
    XMatrix W_;

    XVector gradB_;
    XMatrix gradW_;

    XVector delta_;

    size_type in_;
    size_type out_;

    Linear linear;

public:
    FullyConnected(size_type in, size_type out) noexcept
        : Base()
        , buff_(out), H_(out), B_(out), W_(in, out)
        , gradB_(out), gradW_(in, out), delta_(in)
        , in_(in), out_(out)
    {
        this->template initialize<FullyConnected>();
    }

    void forward(const Vector& input) noexcept
    {
        // H - input
        // S - buff

        // S = H . W + B
        linear.dot(buff_, input, W_);
        linear.add(buff_, B_);

        // value = F(S)
        Activation::f(H_, buff_);
    }

    void backward(const Vector& input, const Vector& idelta) noexcept
    {
        backward0(input, idelta);

        // curr_delta - buff
        // delta = curr_delta . W^T
        linear.dot(delta_, W_, buff_);
    }

    void backward0(const Vector& input, const Vector& idelta) noexcept
    {
        // curr_delta  - buff
        // input_delta - idelta
        // S - buff
        // curr_delta = input_delta * F'(S)
        Activation::df(buff_, buff_);
        linear.mul(buff_, idelta);

        // H - input
        // gradW = H . delta
        // gradB = delta
        linear.tensordot(gradW_, input, buff_);
        linear.assign(gradB_, buff_);
    }

    const Vector& value() noexcept { return H_.base(); }

    XVector& B() noexcept { return B_; }
    XMatrix& W() noexcept { return W_; }

    XVector& delta() noexcept { return delta_; }

    XVector& gradB() noexcept { return gradB_; }
    XMatrix& gradW() noexcept { return gradW_; }

    size_type in() const noexcept { return in_; }
    size_type out() const noexcept { return out_; }
};

template <class Net, class Activation>
class FullyConnected<Net, Activation, LayerMode::Normal> : public ILayer<Net>
{
public:
    using Base = ILayer<Net>;

public:
    using Vector                = typename Net::Vector;
    using Matrix                = typename Net::Matrix;

    using XVector               = typename Net::XVector;
    using XMatrix               = typename Net::XMatrix;

    using Linear                = typename Net::Linear;

    using size_type             = typename Net::size_type;

private:
    XVector buff_;

    XVector H_;
    XVector B_;
    XMatrix W_;

    size_type in_;
    size_type out_;

    Linear linear;

public:
    FullyConnected(size_type in, size_type out) noexcept
        : Base()
        , buff_(out), H_(out), B_(out), W_(in, out)
        , in_(in), out_(out)
    {
        this->template initialize<FullyConnected>();
    }

    void forward(const Vector& input) noexcept
    {
        // H - input
        // S - buff

        // S = H . W + B
        linear.dot(buff_, input, W_);
        linear.add(buff_, B_);

        // value = F(S)
        Activation::f(H_, buff_);
    }

    const Vector& value() noexcept { return H_.base(); }

    XVector& B() noexcept { return B_; }
    XMatrix& W() noexcept { return W_; }

    size_type in() const noexcept { return in_; }
    size_type out() const noexcept { return out_; }
};

template <class Net, class Activation>
using XFullyConected = FullyConnected<Net, Activation, LayerMode::Normal>;

} // namespace layer

} // namespace trixy

// clean up
#undef DERIVED

#endif // TRIXY_NETWORK_LAYER_HPP
