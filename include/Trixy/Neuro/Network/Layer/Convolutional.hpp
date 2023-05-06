#ifndef TRIXY_NETWORK_LAYER_CONVOLUTIONAL_HPP
#define TRIXY_NETWORK_LAYER_CONVOLUTIONAL_HPP

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
using Convolutional = Layer<trixy::LayerType::Convolutional, Net, LayerMode>;

template <class Net>
using XConvolutional = Convolutional<Net, LayerMode::Raw>;

template <class Net>
class Layer<trixy::LayerType::Convolutional, Net, LayerMode::Raw>
    : public ILayer<Net>
{
    TRIXY_LAYER_BODY(ILayer<Net>)
    SERIALIZABLE(Layer<trixy::LayerType::Convolutional, Net, LayerMode::Raw>)

protected:
    shape_type isize_;
    shape_type osize_;

    size_type padding_;
    size_type stride_;

    size_type filter_count_;
    shape_type filter_size_;

    Vector B_;
    Container<Tensor> Ws_;

    Tensor value_;

public:
    Layer() {}

    Layer(const set::Input& input,
          const set::Filter& filter,
          const set::Padding& padding = set::Padding(0),
          const set::Stride& stride = set::Stride(1))
        : Layer(input,
                filter.depth, filter.height, filter.width,
                padding.height,
                stride.height) {}

    Layer(shape_type size,
          size_type filter_count, size_type filter_height, size_type filter_width,
          size_type padding, size_type stride)
        : Base()
        , isize_(size)
        , osize_(filter_count,
                 (size.height - filter_height + 2 * padding) / stride + 1,
                 (size.width - filter_width + 2 * padding) / stride + 1)
        , padding_(padding)
        , stride_(stride)
        , filter_count_(filter_count)
        , filter_size_(size.depth, filter_height, filter_width)
    {
        B_.resize(filter_count_).fill(0.f);

        Ws_.resize(filter_count_);
        for (auto& W : Ws_) W.resize(filter_size_).fill(0.f);

        prepare();
    }

protected:
    void prepare()
    {
        value_.resize(osize_).fill(0.f);
    }

    void init(Generator& gen) noexcept override
    {
        for (auto& W : Ws_) W.fill(gen);
        B_.fill(gen);
    }

    void connect(IActivation* activation) override { /*pass*/ }

    void forward(const Tensor& input) noexcept override
    {
        for (size_type f = 0; f < filter_count_; ++f)
        {
            for (size_type y = 0; y < osize_.height; ++y)
            {
                for (size_type x = 0; x < osize_.width; ++x)
                {
                    precision_type sum = B_(f);

                    for (size_type i = 0; i < filter_size_.height; ++i)
                    {
                        for (size_type j = 0; j < filter_size_.width; ++j)
                        {
                            size_type i0 = stride_ * y + i - padding_;
                            size_type j0 = stride_ * x + j - padding_;

                            // negative value will be bigger than bounds
                            if (i0 >= isize_.height || j0 >= isize_.width)
                                continue;

                            for (size_type c = 0; c < filter_size_.depth; ++c)
                                sum += input(c, i0, j0) * Ws_[f](c, i, j);
                        }
                    }

                    value_(f, y, x) = sum;
                }
            }
        }
    }

    const Tensor& value() const noexcept override { return value_; }

    const shape_type& isize() const noexcept override { return isize_; }
    const shape_type& osize() const noexcept override { return osize_; }
};

template <class Net>
class Layer<trixy::LayerType::Convolutional, Net, LayerMode::Train>
    : public ITrainLayer<Net>
{
    TRIXY_LAYER_BODY(ITrainLayer<Net>)
    SERIALIZABLE(Layer<trixy::LayerType::Convolutional, Net, LayerMode::Train>)

protected:
    shape_type isize_;
    shape_type osize_;

    size_type padding_;
    size_type stride_;

    size_type filter_count_;
    shape_type filter_size_;

    Vector B_;
    Container<Tensor> Ws_;

    Tensor value_;

    Container<Tensor> gradWs_;
    Vector gradB_;

    Tensor delta_;
    Tensor buff_;


public:
    Linear linear;

public:
    Layer() {}

    Layer(const set::Input& input,
          const set::Filter& filter,
          const set::Padding& padding = set::Padding(0),
          const set::Stride& stride = set::Stride(1))
        : Layer(input,
                filter.depth, filter.height, filter.width,
                padding.height,
                stride.height) {}

    Layer(shape_type size,
          size_type filter_count, size_type filter_height, size_type filter_width,
          size_type padding, size_type stride)
        : Base()
        , isize_(size)
        , osize_(filter_count,
                 (size.height - filter_height + 2 * padding) / stride + 1,
                 (size.width - filter_width + 2 * padding) / stride + 1)
        , padding_(padding)
        , stride_(stride)
        , filter_count_(filter_count)
        , filter_size_(size.depth, filter_height, filter_width)
    {
        B_.resize(filter_count_).fill(0.f);

        Ws_.resize(filter_count_);
        for (auto& W : Ws_) W.resize(filter_size_).fill(0.f);

        prepare();
    }

protected:
    void prepare()
    {
        value_.resize(osize_).fill(0.f);

        gradWs_.resize(filter_count_);
        for (auto& gradW : gradWs_) gradW.resize(filter_size_).fill(0.f);

        gradB_.resize(filter_count_).fill(0.f);

        delta_.resize(isize_).fill(0.f);

        auto buff_size = shape_type
        (
            osize_.depth,
            stride_ * (osize_.height - 1) + 1,
            stride_ * (osize_.width - 1) + 1
        );

        buff_.resize(buff_size).fill(0.f);
    }

public:
    void init(Generator& generation) noexcept override
    {
        for (auto& W : Ws_) W.fill(generation);
        B_.fill(generation);
    }

    void connect(IActivation* activation) override { /*pass*/ }

    void forward(const Tensor& input) noexcept override
    {
        for (size_type f = 0; f < filter_count_; ++f)
        {
            for (size_type y = 0; y < osize_.height; ++y)
            {
                for (size_type x = 0; x < osize_.width; ++x)
                {
                    precision_type sum = B_(f);

                    for (size_type i = 0; i < filter_size_.height; ++i)
                    {
                        for (size_type j = 0; j < filter_size_.width; ++j)
                        {
                            size_type i0 = stride_ * y + i - padding_;
                            size_type j0 = stride_ * x + j - padding_;

                            // negative value will be bigger than bounds
                            if (i0 >= isize_.height || j0 >= isize_.width)
                                continue;

                            for (size_type c = 0; c < filter_size_.depth; ++c)
                                sum += input(c, i0, j0) * Ws_[f](c, i, j);
                        }
                    }

                    value_(f, y, x) = sum;
                }
            }
        }
    }

    void backward(const Tensor& input, const Tensor& idelta, bool full = true/*unused*/) noexcept override
    {
        auto& size = buff_.shape();

        for (size_type d = 0; d < size.depth; d++)
            for (size_type i = 0; i < osize_.height; ++i)
                for (size_type j = 0; j < osize_.width; ++j)
                    buff_(d, i * stride_, j * stride_) = idelta(d, i, j);

        for (size_type f = 0; f < filter_count_; ++f)
        {
            for (size_type y = 0; y < size.height; ++y)
            {
                for (size_type x = 0; x < size.width; ++x)
                {
                    precision_type delta_value = buff_(f, y, x);

                    for (size_type i = 0; i < filter_size_.height; ++i)
                    {
                        for (size_type j = 0; j < filter_size_.width; ++j)
                        {
                            size_type i0 = i + y - padding_;
                            size_type j0 = j + x - padding_;

                            if (i0 >= isize_.height || j0 >= isize_.width)
                                continue;

                            for (size_type c = 0; c < filter_size_.depth; ++c)
                                gradWs_[f](c, i, j) += delta_value * input(c, i0, j0);
                        }
                    }

                    gradB_(f) += delta_value;
                }
            }
        }

        size_type pad_i = filter_size_.height - 1 - padding_;
        size_type pad_j = filter_size_.width - 1 - padding_;

        for (size_type y = 0; y < isize_.height; ++y)
        {
            for (size_type x = 0; x < isize_.width; ++x)
            {
                for (size_type c = 0; c < filter_size_.depth; ++c)
                {
                    precision_type sum = 0;
                    for (size_type i = 0; i < filter_size_.height; ++i)
                    {
                        for (size_type j = 0; j < filter_size_.width; ++j)
                        {
                            size_type i0 = y + i - pad_i;
                            size_type j0 = x + j - pad_j;

                            if (i0 >= size.height || j0 >= size.width)
                                continue;

                            for (size_type f = 0; f < filter_count_; ++f)
                                sum += Ws_[f](c, filter_size_.height - 1 - i, filter_size_.width - 1 - j) * buff_(f, i0, j0);
                        }
                    }

                    delta_(c, y, x) = sum;
                }
            }
        }
    }

    void update(IOptimizer& optimizer, precision_type alpha) noexcept override
    {
        for (auto& gradW : gradWs_) linear.join(gradW, alpha);
        linear.join(gradB_, alpha);

        for (size_type i = 0; i < Ws_.size(); ++i) optimizer.update(Ws_[i], gradWs_[i]);
        optimizer.update(B_, gradB_);
    }

    const Tensor& value() const noexcept override { return value_; }
    const Tensor& delta() const noexcept override { return delta_; }

    const shape_type& isize() const noexcept override { return isize_; }
    const shape_type& osize() const noexcept override { return osize_; }
};

} // namespace layer

namespace meta
{

template <typename T> struct is_convolutional_layer : std::false_type {};
template <class Net, typename LayerMode>
struct is_convolutional_layer<layer::Layer<LayerType::Convolutional, Net, LayerMode>> : std::true_type {};

} // namespace meta

} // namespace trixy

CONDITIONAL_SERIALIZATION(SaveLoad, trixy::meta::is_convolutional_layer<T>::value)
{
    archive & self.isize_ & self.osize_
            & self.padding_ & self.stride_
            & self.filter_count_
            & self.filter_size_
            & self.B_ & self.Ws_;

    self.prepare();
}

#endif // TRIXY_NETWORK_LAYER_CONVOLUTIONAL_HPP
