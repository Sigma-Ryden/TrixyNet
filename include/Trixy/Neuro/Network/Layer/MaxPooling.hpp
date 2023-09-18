#ifndef TRIXY_NETWORK_LAYER_MAX_POOLING_HPP
#define TRIXY_NETWORK_LAYER_MAX_POOLING_HPP

#include <Trixy/Neuro/Network/Layer/Base.hpp>
#include <Trixy/Neuro/Network/Layer/Volume.hpp>

#include <Trixy/Neuro/Functional/Function/Activation.hpp>

#include <Trixy/Serializer/Core.hpp>

#include <Trixy/Detail/TrixyMeta.hpp>

#include <Trixy/Neuro/Network/Layer/Detail/MacroScope.hpp>

namespace trixy
{

namespace layer
{

template <class Net,
          typename LayerMode = LayerMode::Train>
using MaxPooling = Layer<trixy::LayerType::MaxPooling, Net, LayerMode>;

template <class Net>
using XMaxPooling = MaxPooling<Net, LayerMode::Raw>;

template <class Net>
class Layer<trixy::LayerType::MaxPooling, Net, LayerMode::Raw>
    : public ILayer<Net>
{
    TRIXY_LAYER_BODY(ILayer<Net>)
    SERIALIZABLE(Layer<trixy::LayerType::MaxPooling, Net, LayerMode::Raw>)

protected:
    shape_type isize_;
    shape_type osize_;

    size_type vertical_stride_;
    size_type horizontal_stride_;

    IActivation* activation_;

protected:
    // cache
    Tensor value_;

public:
    Linear linear;

public:
    Layer() : activation_(nullptr) {}

    Layer(const set::Input& input,
          const set::Stride& stride = set::Stride(1),
          IActivation* activation = new Identity)
        : Layer(input.depth, input.height, input.width,
                stride.height, stride.width,
                activation)
    {
    }

public:
    Layer(size_type channel_depth, size_type in_height, size_type in_width,
          size_type vertical_stride, size_type horizontal_stride,
          IActivation* activation = new Identity)
        : Base()
        , isize_(channel_depth, in_height, in_width)
        , osize_(channel_depth,
                 in_height / vertical_stride,
                 in_width / horizontal_stride)
        , vertical_stride_(vertical_stride)
        , horizontal_stride_(horizontal_stride)
        , activation_(activation)
    {
        value_.resize(osize_).fill(0.f);

        prepare();
    }

protected:
    void prepare() { /*pass*/ }

public:
    virtual ~Layer() { delete activation_; }

    void connect(IActivation* activation) override
    {
        delete activation_;
        activation_ = activation;
    }

    void forward(const Tensor& input) noexcept override
    {
        for (size_type d = 0; d < isize_.depth; ++d)
        {
            for (size_type i = 0; i < isize_.height; i += vertical_stride_)
            {
                for (size_type j = 0; j < isize_.width; j += horizontal_stride_)
                {
                    precision_type max = input(d, i, j);

                    for (size_type y = i; y < i + vertical_stride_; ++y)
                    {
                        for (size_type x = j; x < j + horizontal_stride_; ++x)
                        {
                            precision_type value = input(d, y, x);
                            if (value > max) max = value;
                        }
                    }

                    value_(d, i / vertical_stride_, j / horizontal_stride_) = max;
                }
            }
        }

        activation_->f(value_, value_);
    }

    const Tensor& value() const noexcept override { return value_; }

    const shape_type& isize() const noexcept override { return isize_; }
    const shape_type& osize() const noexcept override { return osize_; }
};

template <class Net>
class Layer<trixy::LayerType::MaxPooling, Net, LayerMode::Train>
    : public ITrainLayer<Net>
{
    TRIXY_LAYER_BODY(ITrainLayer<Net>)
    SERIALIZABLE(Layer<trixy::LayerType::MaxPooling, Net, LayerMode::Train>)

protected:

    shape_type isize_;
    shape_type osize_;

    size_type vertical_stride_;
    size_type horizontal_stride_;

    IActivation* activation_;

protected:
    // cache
    Tensor value_;
    Tensor buff_;
    Tensor mask_;

    Tensor delta_;

public:
    Linear linear;

public:
    Layer() : activation_(nullptr) {}

    Layer(const set::Input& input,
          const set::Stride& stride = set::Stride(1),
          IActivation* activation = new Identity)
        : Layer(input.depth, input.height, input.width,
                stride.height, stride.width,
                activation)
    {
    }

public:
    Layer(size_type channel_depth, size_type in_height, size_type in_width,
          size_type vertical_stride, size_type horizontal_stride,
          IActivation* activation = new Identity)
        : Base()
        , isize_(channel_depth, in_height, in_width)
        , osize_(channel_depth,
                 in_height / vertical_stride,
                 in_width / horizontal_stride)
        , vertical_stride_(vertical_stride)
        , horizontal_stride_(horizontal_stride)
        , activation_(activation)
    {
        value_.resize(osize_).fill(0.f);

        prepare();
    }

protected:
    void prepare()
    {
        delta_.resize(isize_).fill(0.f);
        mask_.resize(isize_).fill(0.f);
        buff_.resize(osize_).fill(0.f);
    }

public:
    virtual ~Layer() { delete activation_; }

    void connect(IActivation* activation) override
    {
        delete activation_;
        activation_ = activation;
    }

    void init(Generator&) noexcept override { /*pass*/ }

    void forward(const Tensor& input) noexcept override
    {
        mask_.fill(0.f);

        for (size_type d = 0; d < isize_.depth; ++d)
        {
            for (size_type i = 0; i < isize_.height; i += vertical_stride_)
            {
                for (size_type j = 0; j < isize_.width; j += horizontal_stride_)
                {
                    size_type imax = i;
                    size_type jmax = j;

                    precision_type max = input(d, i, j);

                    for (size_type y = i; y < i + vertical_stride_; ++y)
                    {
                        for (size_type x = j; x < j + horizontal_stride_; ++x)
                        {
                            precision_type value = input(d, y, x);
                            mask_(d, y, x) = 0.f;

                            if (value > max)
                            {
                                max = value;
                                imax = y;
                                jmax = x;
                            }
                        }
                    }

                    value_(d, i / vertical_stride_, j / horizontal_stride_) = max;
                    mask_(d, imax, jmax) = 1.f;
                }
            }
        }

        activation_->f(value_, buff_);
    }

    void backward(const Tensor& /*input*/, const Tensor& idelta, bool full = true/*unused*/) noexcept override
    {
        activation_->df(buff_, buff_);
        linear.mul(buff_, idelta);

        for (size_type d = 0; d < isize_.depth; ++d)
            for (size_type i = 0; i < isize_.height; ++i)
                for (size_type j = 0; j < isize_.width; ++j)
                    delta_(d, i, j) = buff_(d, i / vertical_stride_, j / horizontal_stride_) * mask_(d, i, j);
    }

    const Tensor& value() const noexcept override { return value_; }
    const Tensor& delta() const noexcept override { return delta_; }

    const shape_type& isize() const noexcept override { return isize_; }
    const shape_type& osize() const noexcept override { return osize_; }
};

} // namespace layer

namespace meta
{

template <typename T> struct is_max_polling_layer : std::false_type {};
template <class Net, typename LayerMode>
struct is_max_polling_layer<layer::Layer<LayerType::MaxPooling, Net, LayerMode>> : std::true_type {};

} // namespace meta

} // namespace trixy

CONDITIONAL_SERIALIZATION(SaveLoad, trixy::meta::is_max_polling_layer<T>::value)
{
    archive & self.isize_ & self.osize_
            & self.vertical_stride_ & self.horizontal_stride_
            & self.activation_;

    if (trixy::meta::is_iarchive(archive)) self.prepare();
}

#endif // TRIXY_NETWORK_LAYER_MAX_POOLING_HPP
