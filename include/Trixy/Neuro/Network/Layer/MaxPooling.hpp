#ifndef TRIXY_NETWORK_LAYER_MAX_POOLING_HPP
#define TRIXY_NETWORK_LAYER_MAX_POOLING_HPP

#include <Trixy/Neuro/Network/Layer/Base.hpp>
#include <Trixy/Neuro/Network/Layer/Volume.hpp>

#include <Trixy/Neuro/Network/Layer/Detail/FunctionDetail.hpp>

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
    TRIXY_TRAIN_LAYER_BODY

private:
    Tensor value_;
    Tensor buff_;
    Tensor mask_;

    XTensor delta_;

    shape_type in_;
    shape_type out_;
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
        , in_(channel_depth, in_height, in_width)
        , out_(channel_depth, 1 + (in_height - pooling_height) / vertical_stride,
                        1 + (in_width - pooling_width) / horizontal_stride)
        , pooling_(channel_depth, pooling_height, pooling_width)
        , horizontal_stride_(horizontal_stride)
        , vertical_stride_(vertical_stride)
        , activation_(activation)
    {
        this->template initialize<Layer>();

        value_.resize(out_);
        mask_.resize(in_);
        buff_.resize(out_);
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

    ~Layer()
    {
        delete activation_;
    }

    void connect(IActivation* activation)
    {
        delete activation_;
        activation_ = activation;
    }

    void init(Generator&) noexcept { /*pass*/ }

    void forward(const Tensor& input) noexcept
    {
        mask_.fill(0.);

        auto result = buff_.data();

        const size_type height = in_.height - pooling_.height + 1;
        const size_type width  = in_.width - pooling_.width + 1;

        for (size_type d = 0; d < in_.depth; ++d)
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
    void backward(const Tensor& /*input*/, const Tensor& idelta) noexcept
    {
        activation_->df(buff_, buff_);
        linear.mul(buff_, idelta);

        for (size_type d = 0; d < in_.depth; ++d)
            for (size_type i = 0; i < in_.height; ++i)
                for (size_type j = 0; j < in_.width; ++j)
                    delta_(d, i, j) =
                        buff_(d, i / vertical_stride_, j / horizontal_stride_) * mask_(d, i, j);
    }

    void backwardFirst(const Tensor&, const Tensor&) noexcept { /*pass*/ }

    const Tensor& value() noexcept { return value_; }
    XTensor& delta() noexcept { return delta_; }

    void resetGrad() noexcept { /*pass*/ }

    void normalizeGrad(precision_type) noexcept { /*pass*/ }

    void update(IOptimizer&) noexcept { /*pass*/ }
    void quickUpdate(IOptimizer&) noexcept {/*pass*/ }

    void accumulateGrad() noexcept { /*pass*/ }

    const shape_type& input() const noexcept { return in_; }
    const shape_type& output() const noexcept { return out_; }
};

template <class Net>
class Layer<trixy::LayerType::MaxPooling, Net, LayerMode::Raw>
    : public ILayer<Net>
{
    TRIXY_RAW_LAYER_BODY

private:
    Tensor value_;

    shape_type in_;
    shape_type out_;
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
        , in_(channel_depth, in_height, in_width)
        , out_(channel_depth, 1 + (in_height - pooling_height) / vertical_stride,
                        1 + (in_width - pooling_width) / horizontal_stride)
        , pooling_(channel_depth, pooling_height, pooling_width)
        , horizontal_stride_(horizontal_stride)
        , vertical_stride_(vertical_stride)
        , activation_(activation)
    {
        this->template initialize<Layer>();

        value_.resize(out_);
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

    ~Layer()
    {
        delete activation_;
    }

    void connect(IActivation* activation)
    {
        delete activation_;
        activation_ = activation;
    }

    void init(Generator&) noexcept { /*pass*/ }

    void forward(const Tensor& input) noexcept
    {
        auto result = value_.data();

        const size_type height = in_.height - pooling_.height + 1;
        const size_type width  = in_.width - pooling_.width + 1;

        for (size_type d = 0; d < in_.depth; ++d)
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

    const Tensor& value() noexcept { return value_; }

    const shape_type& input() const noexcept { return in_; }
    const shape_type& output() const noexcept { return out_; }
};

} // namespace layer

} // namespace trixy

#include <Trixy/Neuro/Network/Layer/Detail/MacroUnscope.hpp>

#endif // TRIXY_NETWORK_LAYER_MAX_POOLING_HPP
