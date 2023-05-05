#ifndef TRIXY_NETWORK_LAYER_CONVOLUTIONAL_HPP
#define TRIXY_NETWORK_LAYER_CONVOLUTIONAL_HPP

#include <Trixy/Neuro/Network/Layer/Base.hpp>

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
class Layer<trixy::LayerType::Convolutional, Net, LayerMode::Train>
    : public ITrainLayer<Net>
{
    TRIXY_TRAIN_LAYER_BODY()
    SERIALIZABLE(Layer<trixy::LayerType::Convolutional, Net, LayerMode::Train>)

protected:
    shape_type isize_;
    shape_type osize_;

    Tensor value_;

    Container<Tensor> Ws_;
    Vector B_;

    Container<Tensor> gradWs_;
    Vector gradB_;

    Tensor delta_;

    size_type pooling_;
    size_type stride_;

    size_type filter_count_;
    size_type filter_size_;
    size_type filter_depth_;

public:
    Linear linear;

public:
    Layer() {}

    Layer(shape_type size, size_type filter_count, size_type filter_size,
          size_type pooling, size_type stride) : Base()
    {
        pooling_ = pooling;
        stride_ = stride;

        filter_count_ = filter_count;
        filter_size_ = filter_size;
        filter_depth_ = size.depth;

        isize_ = size;

        osize_.width = (size.width - filter_size_ + 2 * pooling_) / stride_ + 1;
        osize_.height = (size.height - filter_size_ + 2 * pooling_) / stride_ + 1;
        osize_.depth = filter_count_;
        osize_.size = osize_.width * osize_.height * osize_.depth;

        Ws_.resize(filter_count_);
        for (auto& W : Ws_)
        {
            W.resize(filter_depth_, filter_size_, filter_size_);
            W.fill(0);
        }

        gradWs_.resize(filter_count_);
        for (auto& gradW : gradWs_)
        {
            gradW.resize(filter_depth_, filter_size_, filter_size_);
            gradW.fill(0);
        }

        gradB_.resize(filter_count_);
        gradB_.fill(0);

        delta_.resize(isize_);
        delta_.fill(0);

        B_.resize(filter_count_);
        B_.fill(0);

        value_.resize(osize_);
        value_.fill(0);
    }

    void init(Generator& generation) noexcept override
    {
        for (auto& W : Ws_) W.fill(generation);
        B_.fill(generation);
    }

    void connect(IActivation* activation) override { /*pass*/ }

    void forward(const Tensor& input) noexcept override
    {
        // проходимся по каждому из фильтров
        for (int f = 0; f < filter_count_; f++) {
            for (int y = 0; y < osize_.height; y++) {
                for (int x = 0; x < osize_.width; x++) {
                    double sum = B_(f); // сразу прибавляем смещение

                    // проходимся по фильтрам
                    for (int i = 0; i < filter_size_; i++) {
                        for (int j = 0; j < filter_size_; j++) {
                            int i0 = stride_ * y + i - pooling_;
                            int j0 = stride_ * x + j - pooling_;

                            // поскольку вне границ входного тензора элементы нулевые, то просто игнорируем их
                            if (i0 < 0 || i0 >= isize_.height || j0 < 0 || j0 >= isize_.width)
                                continue;

                            // проходимся по всей глубине тензора и считаем сумму
                            for (int c = 0; c < filter_depth_; c++)
                                sum += input(c, i0, j0) * Ws_[f](c, i, j);
                        }
                    }

                    value_(f, y, x) = sum; // записываем результат свёртки в выходной тензор
                }
            }
        }
    }

    void backward(const Tensor& input, const Tensor& idelta, bool full = true/*unused*/) noexcept override
    {
        shape_type size; // размер дельт

        // расчитываем размер для дельт
        size.height = stride_ * (osize_.height - 1) + 1;
        size.width = stride_ * (osize_.width - 1) + 1;
        size.depth = osize_.depth;

        Tensor deltas(size); // создаём тензор для дельт

        // расчитываем значения дельт
        for (int d = 0; d < size.depth; d++)
            for (int i = 0; i < osize_.height; i++)
                for (int j = 0; j < osize_.width; j++)
                    deltas(d, i * stride_, j * stride_) = idelta(d, i, j);

        // расчитываем градиенты весов фильтров и смещений
        for (int f = 0; f < filter_count_; f++) {
            for (int y = 0; y < size.height; y++) {
                for (int x = 0; x < size.width; x++) {
                    double delta = deltas(f, y, x); // запоминаем значение градиента

                    for (int i = 0; i < filter_size_; i++) {
                        for (int j = 0; j < filter_size_; j++) {
                            int i0 = i + y - pooling_;
                            int j0 = j + x - pooling_;

                            // игнорируем выходящие за границы элементы
                            if (i0 < 0 || i0 >= isize_.height || j0 < 0 || j0 >= isize_.width)
                                continue;

                            // наращиваем градиент фильтра
                            for (int c = 0; c < filter_depth_; c++)
                                gradWs_[f](c, i, j) += delta * input(c, i0, j0);
                        }
                    }

                    gradB_(f) += delta; // наращиваем градиент смещения
                }
            }
        }

        int pad = filter_size_ - 1 - pooling_; // заменяем величину дополнения

        // расчитываем значения градиента
        for (int y = 0; y < isize_.height; y++) {
            for (int x = 0; x < isize_.width; x++) {
                for (int c = 0; c < filter_depth_; c++) {
                    double sum = 0; // сумма для градиента

                    // идём по всем весовым коэффициентам фильтров
                    for (int i = 0; i < filter_size_; i++) {
                        for (int j = 0; j < filter_size_; j++) {
                            int i0 = y + i - pad;
                            int j0 = x + j - pad;

                            // игнорируем выходящие за границы элементы
                            if (i0 < 0 || i0 >= size.height || j0 < 0 || j0 >= size.width)
                                continue;

                            // суммируем по всем фильтрам
                            for (int f = 0; f < filter_count_; f++)
                                sum += Ws_[f](c, filter_size_ - 1 - i, filter_size_ - 1 - j) * deltas(f, i0, j0); // добавляем произведение повёрнутых фильтров на дельты
                        }
                    }

                    delta_(c, y, x) = sum; // записываем результат в тензор градиента
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

template <class Net>
class Layer<trixy::LayerType::Convolutional, Net, LayerMode::Raw>
    : public ILayer<Net>
{
    TRIXY_RAW_LAYER_BODY()
    SERIALIZABLE(Layer<trixy::LayerType::Convolutional, Net, LayerMode::Raw>)

protected:
    shape_type isize_;
    shape_type osize_;

    Tensor value_;

    Container<Tensor> Ws_;
    Vector B_;

    size_type pooling_;
    size_type stride_;

    size_type filter_count_;
    size_type filter_size_;
    size_type filter_depth_;

public:
    Layer() {}

    Layer(shape_type size, size_type filter_count, size_type filter_size,
          size_type pooling, size_type stride) : Base()
    {
        pooling_ = pooling;
        stride_ = stride;

        filter_count_ = filter_count;
        filter_size_ = filter_size;
        filter_depth_ = size.depth;

        isize_ = size;

        osize_.width = (size.width - filter_size_ + 2 * pooling_) / stride_ + 1;
        osize_.height = (size.height - filter_size_ + 2 * pooling_) / stride_ + 1;
        osize_.depth = filter_count_;
        osize_.size = osize_.width * osize_.height * osize_.depth;

        Ws_.resize(filter_count_);
        for (auto& W : Ws_)
        {
            W.resize(filter_depth_, filter_size_, filter_size_);
            W.fill(0);
        }

        B_.resize(filter_count_);
        B_.fill(0);

        value_.resize(osize_);
        value_.fill(0);
    }

    void init(Generator& gen) noexcept override
    {
        for (auto& W : Ws_) W.fill(gen);
        B_.fill(gen);
    }

    void connect(IActivation* activation) override { /*pass*/ }

    void forward(const Tensor& input) noexcept override
    {
        // проходимся по каждому из фильтров
        for (int f = 0; f < filter_count_; f++) {
            for (int y = 0; y < osize_.height; y++) {
                for (int x = 0; x < osize_.width; x++) {
                    double sum = B_(f); // сразу прибавляем смещение

                    // проходимся по фильтрам
                    for (int i = 0; i < filter_size_; i++) {
                        for (int j = 0; j < filter_size_; j++) {
                            int i0 = stride_ * y + i - pooling_;
                            int j0 = stride_ * x + j - pooling_;

                            // поскольку вне границ входного тензора элементы нулевые, то просто игнорируем их
                            if (i0 < 0 || i0 >= isize_.height || j0 < 0 || j0 >= isize_.width)
                                continue;

                            // проходимся по всей глубине тензора и считаем сумму
                            for (int c = 0; c < filter_depth_; c++)
                                sum += input(c, i0, j0) * Ws_[f](c, i, j);
                        }
                    }

                    value_(f, y, x) = sum; // записываем результат свёртки в выходной тензор
                }
            }
        }
    }

    const Tensor& value() const noexcept override { return value_; }

    const shape_type& isize() const noexcept override { return isize_; }
    const shape_type& osize() const noexcept override { return osize_; }
};

} // namespace layer

} // namespace trixy

#endif // TRIXY_NETWORK_LAYER_CONVOLUTIONAL_HPP
