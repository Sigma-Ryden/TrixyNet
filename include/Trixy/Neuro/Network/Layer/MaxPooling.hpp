#ifndef TRIXY_NETWORK_LAYER_MAX_POOLING_HPP
#define TRIXY_NETWORK_LAYER_MAX_POOLING_HPP

#include <Trixy/Neuro/Network/Layer/Base.hpp>
#include <Trixy/Neuro/Network/Layer/Volume.hpp>

#include <Trixy/Neuro/Network/Layer/Detail/FunctionDetail.hpp>

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
class Layer<trixy::LayerType::MaxPooling, Net, LayerMode::Train>
    : public ITrainLayer<Net>
{
    TRIXY_TRAIN_LAYER_BODY()
    SERIALIZABLE(Layer<trixy::LayerType::MaxPooling, Net, LayerMode::Train>)

private:
    Tensor value_;
    Tensor buff_;
    Tensor mask_;

    XTensor delta_;

    shape_type isize_;
    shape_type osize_;
    shape_type pooling_;

    size_type horizontal_stride_;
    size_type vertical_stride_;

    IActivation* activation_;

public:
    Linear linear;

public:
    Layer(size_type in_width, size_type in_height, size_type channel_depth,
          size_type pooling_width, size_type pooling_height,
          size_type horizontal_stride, size_type vertical_stride,
          IActivation* activation = nullptr)
        : Base()
        , delta_(channel_depth, in_height, in_width)
        , isize_(channel_depth, in_height, in_width)
        , osize_(channel_depth,
               1 + (in_height - pooling_height) / vertical_stride,
               1 + (in_width - pooling_width) / horizontal_stride)
        , pooling_(channel_depth, pooling_height, pooling_width)
        , horizontal_stride_(horizontal_stride)
        , vertical_stride_(vertical_stride)
        , activation_(activation)
    {
        value_.resize(osize_);
        mask_.resize(isize_);
        buff_.resize(osize_);
    }

    Layer(const set::Input& input,
          const set::Pool& pooling,
          const set::Stride& stride,
          IActivation* activation = nullptr)
        : Layer(input.width(), input.height(), input.depth(),
                pooling.width(), pooling.height(),
                stride.width(), stride.height(),
                activation)
    {
    }

    Layer(const set::Input& input,
          const set::Pool& pooling,
          IActivation* activation = nullptr)
        : Layer(input, pooling, set::Stride(1, 1), activation)
    {
    }

    virtual ~Layer() { delete activation_; }

    void connect(IActivation* activation) override
    {
        delete activation_;
        activation_ = activation;
    }

    void init(Generator&) noexcept override { /*pass*/ }

    void forward(const Tensor& input) noexcept override
    {
        mask_.fill(0.);

        auto result = buff_.data();

        const size_type height = isize_.height - pooling_.height + 1;
        const size_type width  = isize_.width - pooling_.width + 1;

        for (size_type d = 0; d < isize_.depth; ++d)
        {
            for (size_type i = 0; i < height; i += vertical_stride_)
            {
                for (size_type j = 0; j < width; j += horizontal_stride_)
                {
                    auto position = utility::find(
                        input, d, i, j,
                        pooling_.width,
                        pooling_.height,
                        utility::is_less<precision_type>
                    );

                    *result++ = input(d, position.i, position.j);
                    mask_(d, position.i, position.j) = 1.;
                }
            }
        }

        activation_->f(value_, buff_);
    }

    void backward(const Tensor& /*input*/, const Tensor& idelta) noexcept override
    {
        activation_->df(buff_, buff_);
        linear.mul(buff_, idelta);

        for (size_type d = 0; d < isize_.depth; ++d)
            for (size_type i = 0; i < isize_.height; ++i)
                for (size_type j = 0; j < isize_.width; ++j)
                    delta_(d, i, j) =
                        buff_(d, i / vertical_stride_, j / horizontal_stride_) * mask_(d, i, j);
    }

    const Tensor& value() const noexcept override { return value_; }
    XTensor& delta() noexcept override { return delta_; }

    const shape_type& isize() const noexcept override { return isize_; }
    const shape_type& osize() const noexcept override { return osize_; }
};

template <class Net>
class Layer<trixy::LayerType::MaxPooling, Net, LayerMode::Raw>
    : public ILayer<Net>
{
    TRIXY_RAW_LAYER_BODY()
    SERIALIZABLE(Layer<trixy::LayerType::MaxPooling, Net, LayerMode::Raw>)

private:
    Tensor value_;

    shape_type isize_;
    shape_type osize_;
    shape_type pooling_;

    size_type horizontal_stride_;
    size_type vertical_stride_;

    IActivation* activation_;

public:
    Linear linear;

public:
    Layer(size_type in_width, size_type in_height, size_type channel_depth,
          size_type pooling_width, size_type pooling_height,
          size_type horizontal_stride, size_type vertical_stride,
          IActivation* activation = nullptr)
        : Base()
        , isize_(channel_depth, in_height, in_width)
        , osize_(channel_depth,
               1 + (in_height - pooling_height) / vertical_stride,
               1 + (in_width - pooling_width) / horizontal_stride)
        , pooling_(channel_depth, pooling_height, pooling_width)
        , horizontal_stride_(horizontal_stride)
        , vertical_stride_(vertical_stride)
        , activation_(activation)
    {
        value_.resize(osize_);
    }

    Layer(const set::Input& input,
          const set::Pool& pooling,
          const set::Stride& stride,
          IActivation* activation = nullptr)
        : Layer(input.width(), input.height(), input.depth(),
                pooling.width(), pooling.height(),
                stride.width(), stride.height(),
                activation)
    {
    }

    Layer(const set::Input& input,
          const set::Pool& pooling,
          IActivation* activation = nullptr)
        : Layer(input, pooling, set::Stride(1, 1), activation)
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
        auto result = value_.data();

        const size_type height = isize_.height - pooling_.height + 1;
        const size_type width  = isize_.width - pooling_.width + 1;

        for (size_type d = 0; d < isize_.depth; ++d)
        {
            for (size_type i = 0; i < height; i += vertical_stride_)
            {
                for (size_type j = 0; j < width; j += horizontal_stride_)
                {
                    auto position = utility::find(
                        input, d, i, j,
                        pooling_.width,
                        pooling_.height,
                        utility::is_less<precision_type>
                    );

                    *result++ = input(d, position.i, position.j);
                }
            }
        }

        activation_->f(value_, value_);
    }

    const Tensor& value() const noexcept override { return value_; }

    const shape_type& isize() const noexcept override { return isize_; }
    const shape_type& osize() const noexcept override { return osize_; }
};

} // namespace layer

namespace meta
{

template <typename T> struct is_max_polling_layer : std::false_type {};
template <class Net>
struct is_max_polling_layer<layer::Layer<LayerType::MaxPooling, Net, LayerMode::Train>> : std::true_type {};

template <typename T> struct is_xmax_polling_layer : std::false_type {};
template <class Net>
struct is_xmax_polling_layer<layer::Layer<LayerType::MaxPooling, Net, LayerMode::Raw>> : std::true_type {};

} // namespace meta

} // namespace trixy

CONDITIONAL_SERIALIZATION(SaveLoad, trixy::meta::is_max_polling_layer<T>::value)
{
    archive & self.value_ & self.buff_ & self.mask_ & self.delta_
            & self.isize_ & self.osize_ & self.pooling_
            & self.horizontal_stride_ & self.horizontal_stride_
            & self.activation_;
}

CONDITIONAL_SERIALIZATION(SaveLoad, trixy::meta::is_xmax_polling_layer<T>::value)
{
    archive & self.value_
            & self.isize_ & self.osize_ & self.pooling_
            & self.horizontal_stride_ & self.horizontal_stride_
            & self.activation_;
}

#endif // TRIXY_NETWORK_LAYER_MAX_POOLING_HPP
