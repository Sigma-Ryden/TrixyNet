#ifndef TRIXY_NETWORK_LAYER_FULLY_CONNECTED_HPP
#define TRIXY_NETWORK_LAYER_FULLY_CONNECTED_HPP

#include <Trixy/Neuro/Network/Layer/Base.hpp>
#include <Trixy/Neuro/Network/Layer/Volume.hpp>

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
    TRIXY_TRAIN_LAYER_BODY()

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

    shape_type isize_;
    shape_type osize_;

    IActivation* activation_;

public:
    Linear linear;

public:
    // maybe change in the future release
    Layer(size_type isize, size_type osize, IActivation* activation = nullptr)
        : Base()
        , buff_(osize), value_(1, 1, osize), B_(osize), W_(isize, osize)
        , gradB_(osize), gradW_(isize, osize)
        , deltaB_(osize), deltaW_(isize, osize), delta_(1, 1, isize)
        , isize_(1, 1, isize), osize_(1, 1, osize)
        , activation_(activation)
    {
    }

    Layer(const set::Input& input, IActivation* activation = nullptr)
        : Layer(input.width(), input.height(), activation)
    {
    }

    virtual ~Layer() { delete activation_; }

    void init(Generator& gen) noexcept override
    {
        B_.fill(gen);
        W_.fill(gen);
    }

    void connect(IActivation* activation) override
    {
        delete activation_;
        activation_ = activation;
    }

    void forward(const Tensor& input) noexcept override
    {
        // H - input
        // S - buff

        // S = H . W + B

        linear.dot(buff_, input, W_);
        linear.add(buff_, B_);

        // value = F(S)
        activation_->f(value_, buff_);
    }

    void backward(const Tensor& input, const Tensor& idelta) noexcept override
    {
        first_backward(input, idelta);

        // curr_delta - gradB
        // delta = curr_delta . W^T

        linear.dot(delta_, W_, gradB_);
    }

    void first_backward(const Tensor& input, const Tensor& idelta) noexcept override
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

    const Tensor& value() const noexcept override { return value_; }

    XTensor& delta() noexcept override { return delta_; }

    void grad_reset() noexcept override
    {
        deltaB_.fill(0.);
        deltaW_.fill(0.);
    }

    void grad_normalize(precision_type alpha) noexcept override
    {
        linear.join(deltaB_, alpha);
        linear.join(deltaW_, alpha);
    }

    void grad_accumulate() noexcept override
    {
        linear.add(deltaB_, gradB_);
        linear.add(deltaW_, gradW_);
    }

    void update(IOptimizer& optimizer) noexcept override
    {
        optimizer.update(B_, deltaB_);
        optimizer.update(W_, deltaW_);
    }

    void fast_update(IOptimizer& optimizer) noexcept override
    {
        optimizer.update(B_, gradB_);
        optimizer.update(W_, gradB_);
    }

    const shape_type& isize() const noexcept override { return isize_; }
    const shape_type& osize() const noexcept override { return osize_; }
};

template <class Net>
class Layer<trixy::LayerType::FullyConnected, Net, LayerMode::Raw>
    : public ILayer<Net>
{
    TRIXY_RAW_LAYER_BODY()

private:
    Tensor value_;
    Vector B_;
    Matrix W_;

    shape_type isize_;
    shape_type osize_;

    IActivation* activation_;

    Linear linear;

public:
    Layer(size_type isize, size_type osize, IActivation* activation = nullptr)
        : Base()
        , value_(1, 1, osize), B_(osize), W_(isize, osize)
        , isize_(1, 1, isize), osize_(1, 1, osize)
        , activation_(activation)
    {
    }

    Layer(const set::Input& input, IActivation* activation = nullptr)
        : Layer(input.width(), input.height(), activation)
    {
    }

    virtual ~Layer() { delete activation_; }

    void connect(IActivation* activation) override
    {
        delete activation_;
        activation_ = activation;
    }

    void forward(const Tensor& input) noexcept override
    {
        // H - input
        // S - buff

        // S = H . W + B
        linear.dot(value_, input, W_);
        linear.add(value_, B_);

        // value = F(S)
        activation_->f(value_, value_);
    }

    const Tensor& value() const noexcept override { return value_; }

    const shape_type& isize() const noexcept override { return isize_; }
    const shape_type& osize() const noexcept override { return osize_; }
};

} // namespace layer

} // namespace trixy

#endif // TRIXY_NETWORK_LAYER_FULLY_CONNECTED_HPP
