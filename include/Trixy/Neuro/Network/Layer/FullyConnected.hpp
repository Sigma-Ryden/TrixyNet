#ifndef TRIXY_NETWORK_LAYER_FULLY_CONNECTED_HPP
#define TRIXY_NETWORK_LAYER_FULLY_CONNECTED_HPP

#include <Trixy/Neuro/Network/Layer/Base.hpp>

#include <Trixy/Detail/TrixyMeta.hpp>

#include <Trixy/Neuro/Network/Layer/Detail/MacroScope.hpp>

namespace trixy
{

namespace layer
{

template <class Net,
          typename LayerMode = LayerMode::Train>
using FullyConnected = Layer<trixy::LayerType::FullyConnected, Net, LayerMode>;

template <class Net>
using XFullyConnected = FullyConnected<Net, LayerMode::Raw>;

template <class Net>
class Layer<trixy::LayerType::FullyConnected, Net, LayerMode::Train>
    : public ITrainLayer<Net>
{
    TRIXY_TRAIN_LAYER_BODY

private:
    Tensor value_;
    Vector buff_;

    Vector B_;
    Matrix W_;

    Vector gradB_;
    Matrix gradW_;

    Vector deltaB_;
    Matrix deltaW_;

    XTensor delta_;

    shape_type in_;
    shape_type out_;

    IActivation* activation_;

public:
    Linear linear;

public:
    // maybe change in the future release
    Layer(size_type in, size_type out, IActivation* activation = nullptr)
        : Base()
        , buff_(out), value_(1, 1, out), B_(out), W_(in, out)
        , gradB_(out), gradW_(in, out)
        , deltaB_(out), deltaW_(in, out)
        , delta_(1, 1, in)
        , in_(1, 1, in), out_(1, 1, out)
        , activation_(activation)
    {
        this->template initialize<Layer>();
    }

    ~Layer()
    {
        delete activation_;
    }

    void connect(IActivation* activation)
    {
        delete activation_;
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
        activation_->f(value_, buff_);
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

    const Tensor& value() noexcept { return value_; }

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

    const shape_type& input() const noexcept { return in_; }
    const shape_type& output() const noexcept { return out_; }
};

template <class Net>
class Layer<trixy::LayerType::FullyConnected, Net, LayerMode::Raw>
    : public ILayer<Net>
{
    TRIXY_RAW_LAYER_BODY

private:
    Tensor value_;
    Vector B_;
    Matrix W_;

    shape_type in_;
    shape_type out_;

    IActivation* activation_;

    Linear linear;

public:
    Layer(size_type in, size_type out, IActivation* activation = nullptr)
        : Base()
        , value_(1, 1, out), B_(out), W_(in, out)
        , in_(1, 1, in), out_(1, 1, out)
        , activation_(activation)
    {
        this->template initialize<Layer>();
    }

    ~Layer()
    {
        delete activation_;
    }

    void connect(IActivation* activation)
    {
        delete activation_;
        activation_ = activation;
    }

    void forward(const Tensor& input) noexcept
    {
        // H - input
        // S - buff

        // S = H . W + B
        linear.dot(value_, input, W_);
        linear.add(value_, B_);

        // value = F(S)
        activation_->f(value_, value_);
    }

    const Tensor& value() noexcept { return value_.base(); }

    const shape_type& input() const noexcept { return in_; }
    const shape_type& output() const noexcept { return out_; }
};

} // namespace layer

} // namespace trixy

#include <Trixy/Neuro/Network/Layer/Detail/MacroUnscope.hpp>

#endif // TRIXY_NETWORK_LAYER_FULLY_CONNECTED_HPP
