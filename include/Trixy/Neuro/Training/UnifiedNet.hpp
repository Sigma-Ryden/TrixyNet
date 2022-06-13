#ifndef TRIXY_TRAINING_UNIFIED_NET_HPP
#define TRIXY_TRAINING_UNIFIED_NET_HPP

#include <Trixy/Neuro/Training/Base.hpp>

#include <Trixy/Neuro/Functional/Function/Base.hpp>
#include <Trixy/Neuro/Functional/Optimizer/Base.hpp>

#include <Trixy/Neuro/Detail/TrixyNetMeta.hpp>

#include <Trixy/Neuro/Detail/MacroScope.hpp>

namespace trixy
{

namespace train
{

TRIXY_TRAINING_TPL_DECLARATION
class TRIXY_TRAINING_TPL(meta::is_unified_net)
{
public:
    using Net = Trainable;

    template <class T>
    using Container                 = typename Net::template Container<T>;

    using Vector                    = typename Net::Vector;
    using Matrix                    = typename Net::Matrix;
    using Tensor                    = typename Net::Tensor;

    template <class T>
    using XContainer                = typename Net::template XContainer<T>;

    using XVector                   = typename Net::XVector;
    using XMatrix                   = typename Net::XMatrix;
    using XTensor                   = typename Net::XTensor;

    using precision_type            = typename Net::precision_type;
    using size_type                 = typename Net::size_type;

    using ITrainLayer               = typename Net::ITrainLayer;

    using ILoss                     = functional::loss::ILoss<precision_type>;
    using IOptimizer                = train::IOptimizer<Net>;

private:
    Net& net;                       ///< reference to network prevent her copying

    Tensor delta;                   ///< back propogation delta tensor

    ILoss* loss_;

public:
    explicit Training(Net& network);

    // operator= for copy and move Training object will not implicit generate
    Training(const Training&) = default;
    Training(Training&&) noexcept = default;

    template <class GeneratorInteger>
    void trainStochastic(const Container<Tensor>& idata,
                         const Container<Tensor>& odata,
                         IOptimizer& optimizer,
                         size_type iteration_scale,
                         GeneratorInteger generator) noexcept;

    void trainBatch(const Container<Tensor>& idata,
                    const Container<Tensor>& odata,
                    IOptimizer& optimizer,
                    size_type number_of_epochs) noexcept;

    void trainMiniBatch(const Container<Tensor>& idata,
                        const Container<Tensor>& odata,
                        IOptimizer& optimizer,
                        size_type number_of_epochs,
                        size_type mini_batch_size) noexcept;

    void feedforward(const Tensor& sample) noexcept;

    void backprop(const Tensor& sample,
                  const Tensor& target) noexcept;

    void loss(ILoss* loss);

    long double loss(const Container<Tensor>& idata,
                     const Container<Tensor>& odata) const noexcept;

private:
    ITrainLayer& layer(size_type i) noexcept;

    void reset_grad() noexcept;
    void accumulate_grad() noexcept;
    void normalize_grad(precision_type alpha) noexcept;

    void model_update(IOptimizer& optimizer) noexcept;
    void quick_model_update(IOptimizer& optimizer) noexcept;
};

TRIXY_TRAINING_TPL_DECLARATION
TRIXY_TRAINING_TPL(meta::is_unified_net)::Training(Trainable& network)
    : net(network), loss_(nullptr)
{
}

TRIXY_TRAINING_TPL_DECLARATION
void TRIXY_TRAINING_TPL(meta::is_unified_net)::loss(ILoss* loss)
{
    loss_ = loss;

    // will be change in the future release
    delta.resize(1, 1, net.layer(net.size() - 1).out());
}

TRIXY_TRAINING_TPL_DECLARATION
template <class GeneratorInteger>
void TRIXY_TRAINING_TPL(meta::is_unified_net)::trainStochastic(
    const Container<Tensor>& idata,
    const Container<Tensor>& odata,
    IOptimizer& optimizer,
    size_type iteration_scale,
    GeneratorInteger generator) noexcept
{
    for (size_type iteration = 0, sample; iteration < iteration_scale; ++iteration)
    {
        sample = generator() % idata.size();

        feedforward(idata[sample]);
        backprop(idata[sample], odata[sample]);

        // Updating the model with dynamic gradients, without their accumulation
        quick_model_update(optimizer);
    }
}

TRIXY_TRAINING_TPL_DECLARATION
void TRIXY_TRAINING_TPL(meta::is_unified_net)::trainBatch(
    const Container<Tensor>& idata,
    const Container<Tensor>& odata,
    IOptimizer& optimizer,
    size_type number_of_epochs) noexcept
{
    precision_type alpha = 1. / static_cast<precision_type>(idata.size());

    for (size_type epoch = 0, sample; epoch < number_of_epochs; ++epoch)
    {
        reset_grad();

        for (sample = 0; sample < idata.size(); ++sample)
        {
            feedforward(idata[sample]);
            backprop(idata[sample], odata[sample]);

            accumulate_grad();
        }

        normalize_grad(alpha);
        model_update(optimizer);
    }
}

TRIXY_TRAINING_TPL_DECLARATION
void TRIXY_TRAINING_TPL(meta::is_unified_net)::trainMiniBatch(
    const Container<Tensor>& idata,
    const Container<Tensor>& odata,
    IOptimizer& optimizer,
    size_type number_of_epochs,
    size_type mini_batch_size) noexcept
{
    precision_type alpha = 1. / static_cast<precision_type>(mini_batch_size);

    // number of iterations per full batch
    size_type iteration_scale = idata.size() / mini_batch_size; // implicit drop floating part

    size_type sample;
    size_type sample_limit;

    for (size_type epoch = 0, iteration; epoch < number_of_epochs; ++epoch)
    {
        sample = 0;
        sample_limit = 0;

        for (iteration = 0; iteration < iteration_scale; ++iteration)
        {
            sample_limit += mini_batch_size;

            reset_grad();

            // accumulating deltas for one mini-batch
            while (sample < sample_limit)
            {
                feedforward(idata[sample]);
                backprop(idata[sample], odata[sample]);

                accumulate_grad();

                ++sample;
            }
            // averaging deltas for one mini-batch
            normalize_grad(alpha);
            model_update(optimizer);
        }
    }
}

TRIXY_TRAINING_TPL_DECLARATION
void TRIXY_TRAINING_TPL(meta::is_unified_net)::feedforward(
    const Tensor& sample) noexcept
{
    net.feedforward(sample);
}

TRIXY_TRAINING_TPL_DECLARATION
void TRIXY_TRAINING_TPL(meta::is_unified_net)::backprop(
    const Tensor& sample,
    const Tensor& target) noexcept
{
    const size_type N = net.size();

    loss_->df(delta, target, layer(N - 1).value());

    layer(N - 1).backward(layer(N - 2).value(), delta);

    for (int i = N - 2; i > 0; --i)
        layer(i).backward(layer(i - 1).value(), layer(i + 1).delta().base());

    layer(0).first_backward(sample, layer(1).delta().base());
}

TRIXY_TRAINING_TPL_DECLARATION
long double TRIXY_TRAINING_TPL(meta::is_unified_net)::loss(
    const Container<Tensor>& idata,
    const Container<Tensor>& odata) const noexcept
{
    precision_type result = 0.;
    precision_type error  = 0.;

    for (size_type i = 0; i < odata.size(); ++i)
    {
        loss_->f(error, odata[i], net.feedforward(idata[i]));
        result += error;
    }

    return result / static_cast<long double>(odata.size());
}

TRIXY_TRAINING_TPL_DECLARATION
typename TRIXY_TRAINING_TPL(meta::is_unified_net)::ITrainLayer&
    TRIXY_TRAINING_TPL(meta::is_unified_net)::layer(size_type i) noexcept
{
    // Provides access to the layer's training interface
    return static_cast<ITrainLayer&>(net.layer(i));
}

TRIXY_TRAINING_TPL_DECLARATION
void TRIXY_TRAINING_TPL(meta::is_unified_net)::reset_grad() noexcept
{
    for (size_type i = 0; i < net.size(); ++i)
        layer(i).reset_grad();
}

TRIXY_TRAINING_TPL_DECLARATION
void TRIXY_TRAINING_TPL(meta::is_unified_net)::accumulate_grad() noexcept
{
    for (size_type i = 0; i < net.size(); ++i)
        layer(i).accumulate_grad();
}

TRIXY_TRAINING_TPL_DECLARATION
void TRIXY_TRAINING_TPL(meta::is_unified_net)::normalize_grad(
    precision_type alpha) noexcept
{
    for (size_type i = 0; i < net.size(); ++i)
        layer(i).normalize_grad(alpha);
}

TRIXY_TRAINING_TPL_DECLARATION
void TRIXY_TRAINING_TPL(meta::is_unified_net)::model_update(
    IOptimizer& optimizer) noexcept
{
    for (size_type i = 0; i < net.size(); ++i)
        layer(i).update(optimizer);
}

TRIXY_TRAINING_TPL_DECLARATION
void TRIXY_TRAINING_TPL(meta::is_unified_net)::quick_model_update(
    IOptimizer& optimizer) noexcept
{
    // Quick update is best used to update a layer with simple gradients
    for (size_type i = 0; i < net.size(); ++i)
        layer(i).quick_update(optimizer);
}

} // namespace train

} // namespace trixy

#include <Trixy/Neuro/Detail/MacroUnscope.hpp>

#endif // TRIXY_TRAINING_UNIFIED_NET_HPP
