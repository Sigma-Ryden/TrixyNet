#ifndef TRIXY_NETWORK_LAYER_FULLY_CONNECTED_HPP
#define TRIXY_NETWORK_LAYER_FULLY_CONNECTED_HPP

#include <Trixy/Neuro/Network/Layer/Base.hpp>
#include <Trixy/Neuro/Network/Layer/Volume.hpp>

#include <Trixy/Neuro/Functional/Function/Activation.hpp>

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
class Layer<trixy::LayerType::FullyConnected, Net, LayerMode::Raw>
    : public ILayer<Net>
{
    TRIXY_LAYER_BODY(ILayer<Net>)
    SERIALIZABLE(Layer<trixy::LayerType::FullyConnected, Net, LayerMode::Raw>)

protected:
    shape_type isize_;
    shape_type osize_;

    Vector B_;
    Matrix W_;

    IActivation* activation_;

protected:
    // cache
    Tensor value_;

public:
    Linear linear;

public:
    Layer() : activation_(nullptr) {}

    Layer(const set::Input& input, const set::Output& output, IActivation* activation = new Identity)
        : Layer(input.size, output.size, activation)
    {
    }

    Layer(size_type isize, size_type osize, IActivation* activation = new Identity)
        : Base()
        , isize_(1, 1, isize), osize_(1, 1, osize)
        , activation_(activation)
    {
        B_.resize(osize).fill(0.f);
        W_.resize(isize, osize).fll(0.f);

        prepare();
    }

protected:
    void prepare()
    {
        value_.resize(osize_).fill(0.f);
    }

public:
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

template <class Net>
class Layer<trixy::LayerType::FullyConnected, Net, LayerMode::Train>
    : public ITrainLayer<Net>
{
    TRIXY_LAYER_BODY(ITrainLayer<Net>)
    SERIALIZABLE(Layer<trixy::LayerType::FullyConnected, Net, LayerMode::Train>)

protected:
    shape_type isize_;
    shape_type osize_;

    Vector B_;
    Matrix W_;

    IActivation* activation_;

protected:
    // cache
    Tensor value_;
    Vector buff_;

    Vector gradB_;
    Matrix gradW_;

    Vector gradBs_;
    Matrix gradWs_;

    Tensor delta_;

    bool accumulated_;

public:
    Linear linear;

public:
    Layer() : activation_(nullptr) {}

    Layer(const set::Input& input, const set::Output& output, IActivation* activation = new Identity)
        : Layer(input.size, output.size, activation)
    {
    }

    // maybe change in the future release
    Layer(size_type isize, size_type osize, IActivation* activation = new Identity)
        : Base()
        , isize_(1, 1, isize), osize_(1, 1, osize)
        , activation_(activation)
    {
        B_.resize(osize).fill(0.f);
        W_.resize(isize, osize).fill(0.f);

        prepare();
    }

protected:
    void prepare()
    {
        value_.resize(osize_).fill(0.f);
        buff_.resize(osize_).fill(0.f);
        gradBs_.resize(osize_).fill(0.f);
        gradWs_.resize(isize_.width, osize_.width).fill(0.f);
        gradB_.resize(osize_).fill(0.f);
        gradW_.resize(isize_.width, osize_.width).fill(0.f);
        delta_.resize(isize_).fill(0.f);
        accumulated_ = false;
    }

public:
    virtual ~Layer() { delete activation_; }

    void init(Generator& generation) noexcept override
    {
        B_.fill(generation);
        W_.fill(generation);
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

    void backward(const Tensor& input, const Tensor& idelta, bool full = true) noexcept override
    {
        // curr_delta  - gradB
        // input_delta - idelta
        // S - buff
        // curr_delta = input_delta * F'(S)

        activation_->df(gradB_, buff_);
        linear.mul(gradB_, idelta);

        // H - input
        // gradB - delta
        // gradW = H . delta, where . - tensordot
        linear.tensordot(gradW_, input, gradB_);

        // curr_delta - gradB
        // delta = curr_delta . W^T

        if (full) linear.dot(delta_, W_, gradB_);
    }

    void update(IOptimizer& optimizer, precision_type alpha) noexcept override
    {
        auto& gradB = accumulated_ ? gradBs_ : gradB_;
        auto& gradW = accumulated_ ? gradWs_ : gradW_;

        if (alpha != 1.f)
        {
            linear.join(gradB, alpha);
            linear.join(gradW, alpha);
        }

        optimizer.update(B_, gradB);
        optimizer.update(W_, gradW);
    }

    void reset() noexcept override
    {
        gradBs_.fill(0.f);
        gradWs_.fill(0.f);

        accumulated_ = false;
    }

    void accumulate() noexcept override
    {
        linear.add(gradBs_, gradB_);
        linear.add(gradWs_, gradW_);

        accumulated_ = true;
    }

    const Tensor& value() const noexcept override { return value_; }
    const Tensor& delta() const noexcept override { return delta_; }

    const shape_type& isize() const noexcept override { return isize_; }
    const shape_type& osize() const noexcept override { return osize_; }
};

} // namespace layer

namespace meta
{

template <typename T> struct is_fully_connected_layer : std::false_type {};
template <class Net, typename LayerMode>
struct is_fully_connected_layer<layer::Layer<LayerType::FullyConnected, Net, LayerMode>> : std::true_type {};

} // namespace meta

} // namespace trixy

CONDITIONAL_SERIALIZATION(SaveLoad, trixy::meta::is_fully_connected_layer<T>::value)
{
    archive & self.isize_ & self.osize_
            & self.B_ & self.W_
            & self.activation_;

    if (trixy::meta::is_iarchive(archive)) self.prepare();
}

#endif // TRIXY_NETWORK_LAYER_FULLY_CONNECTED_HPP
