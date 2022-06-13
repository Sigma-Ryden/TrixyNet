#ifndef TRIXY_NETWORK_LAYER_FULLY_CONNECTED_HPP
#define TRIXY_NETWORK_LAYER_FULLY_CONNECTED_HPP

#include <Trixy/Neuro/Network/Layer/Base.hpp>

#include <Trixy/Detail/TrixyMeta.hpp>

namespace trixy
{

namespace layer
{

template <class Net,
          typename LayerMode = LayerMode::Train>
using FullyConnected = Layer<trixy::LayerType::FullyConnected, Net, LayerMode>;

template <class Net>
using XFullyConnected = FullyConnected<Net, LayerMode::Normal>;

template <class Net>
class Layer<trixy::LayerType::FullyConnected, Net, LayerMode::Train>
    : public ITrainLayer<Net>
{
public:
    using Base = ITrainLayer<Net>;

public:
    using typename Base::Vector;
    using typename Base::Matrix;
    using typename Base::Tensor;

    using typename Base::XVector;
    using typename Base::XMatrix;
    using typename Base::XTensor;

    using typename Base::Linear;

    using typename Base::size_type;
    using typename Base::precision_type;

    using typename Base::Generator;
    using typename Base::IActivation;
    using typename Base::IOptimizer;

private:
    XVector buff_;

    XTensor H_;
    XVector B_;
    XMatrix W_;

    XVector gradB_;
    XMatrix gradW_;

    XVector deltaB_;
    XMatrix deltaW_;

    XTensor delta_;

    size_type in_;
    size_type out_;

    IActivation* activation_;

public:
    Linear linear;

public:
    // maybe change in the future release
    Layer(size_type in, size_type out, IActivation* activation = nullptr)
        : Base()
        , buff_(out), H_(1, 1, out), B_(out), W_(in, out)
        , gradB_(out), gradW_(in, out)
        , deltaB_(out), deltaW_(in, out)
        , delta_(1, 1, in)
        , in_(in), out_(out)
        , activation_(activation)
    {
        this->template initialize<Layer>();
    }

    void connect(IActivation* activation)
    {
        activation_ = activation;
    }

    void init(Generator& gen) noexcept
    {
        B_.fill(gen);
        W_.fill(gen);
    }

    void forward(const Tensor& input) noexcept
    {
        // H - input
        // S - buff

        // S = H . W + B

        linear.dot(buff_, input, W_);
        linear.add(buff_, B_);

        // value = F(S)
        activation_->f(H_, buff_);
    }

    void backward(const Tensor& input, const Tensor& idelta) noexcept
    {
        first_backward(input, idelta);

        // curr_delta - gradB
        // delta = curr_delta . W^T

        linear.dot(delta_, W_, gradB_);
    }

    void first_backward(const Tensor& input, const Tensor& idelta) noexcept
    {
        // curr_delta  - gradB
        // input_delta - idelta
        // S - buff
        // curr_delta = input_delta * F'(S)

        activation_->df(gradB_, buff_);
        linear.mul(gradB_, idelta);

        // H - input
        // gradW = H . delta, where . - tensordot
        // gradB = delta
        linear.tensordot(gradW_, input, gradB_);
    }

    const Tensor& value() noexcept { return H_.base(); }

    XTensor& delta() noexcept { return delta_; }

    void reset_grad() noexcept
    {
        deltaB_.fill(0.);
        deltaW_.fill(0.);
    }

    void normalize_grad(precision_type alpha) noexcept
    {
        linear.join(deltaB_, alpha);
        linear.join(deltaW_, alpha);
    }

    void update(IOptimizer& optimizer) noexcept
    {
        optimizer.update(B_, deltaB_);
        optimizer.update(W_, deltaW_);
    }

    // Maybe be rebuild in the future versions
    void quick_update(IOptimizer& optimizer) noexcept
    {
        optimizer.update(B_, gradB_);
        optimizer.update(W_, gradB_);
    }

    void accumulate_grad() noexcept
    {
        linear.add(deltaB_, gradB_);
        linear.add(deltaW_, gradW_);
    }

    size_type in() const noexcept { return in_; }
    size_type out() const noexcept { return out_; }
};

template <class Net>
class Layer<trixy::LayerType::FullyConnected, Net, LayerMode::Normal>
    : public ILayer<Net>
{
public:
    using Base = ILayer<Net>;

public:
    using typename Base::Vector;
    using typename Base::Matrix;
    using typename Base::Tensor;

    using typename Base::XVector;
    using typename Base::XMatrix;
    using typename Base::XTensor;

    using typename Base::Linear;

    using typename Base::size_type;
    using typename Base::precision_type;

    using typename Base::IActivation;

private:
    XVector buff_;

    XTensor H_;
    XVector B_;
    XMatrix W_;

    size_type in_;
    size_type out_;

    IActivation* activation_;

    Linear linear;

public:
    Layer(size_type in, size_type out, IActivation* activation = nullptr)
        : Base()
        , buff_(out), H_(1, 1, out), B_(out), W_(in, out)
        , in_(in), out_(out)
        , activation_(activation)
    {
        this->template initialize<Layer>();
    }

    void connect(IActivation* activation)
    {
        activation_ = activation;
    }

    void forward(const Tensor& input) noexcept
    {
        // H - input
        // S - buff

        // S = H . W + B
        linear.dot(buff_, input, W_);
        linear.add(buff_, B_);

        // value = F(S)
        activation_->f(H_, buff_);
    }

    const Tensor& value() noexcept { return H_.base(); }

    size_type in() const noexcept { return in_; }
    size_type out() const noexcept { return out_; }
};

} // namespace layer

} // namespace trixy

#endif // TRIXY_NETWORK_LAYER_FULLY_CONNECTED_HPP
