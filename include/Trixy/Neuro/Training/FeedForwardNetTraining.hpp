#ifndef FEED_FORWARD_NET_TRAINING_HPP
#define FEED_FORWARD_NET_TRAINING_HPP

#include "BaseTraining.hpp"
#include "Trixy/Neuro/Detail/TrixyNetMeta.hpp"

#include "Trixy/Neuro/Detail/MacroScope.hpp"

namespace trixy
{

namespace train
{

TRIXY_TRAINING_TPL_DECLARATION
class TRIXY_TRAINING_TPL(meta::is_feedforward_net)
{
private:
    template <class T>
    using Container                 = typename Trainable::template ContainerType<T>;

    using Tensor1D                  = typename Trainable::Tensor1D;
    using Tensor2D                  = typename Trainable::Tensor2D;

    using precision_type            = typename Trainable::precision_type;
    using size_type                 = typename Trainable::size_type;

private:
    Trainable& net;

    Container<Tensor1D> H;          ///< hidden layer storage
    Container<Tensor1D> derivedH;   ///< derived hidden layer storage

    Container<Tensor1D> derivedB;   ///< derived bias storage (using for inner updates)
    Container<Tensor2D> derivedW;   ///< derived weight storage (using for inner updates)

    Container<Tensor1D> deltaB;     ///< delta bias storage (using with derived bias and for inner updates)
    Container<Tensor2D> deltaW;     ///< delta weight storage (using with derived weight and for inner updates)

    Container<Tensor1D> buff;       ///< 1D buffer for handle

public:
    Training(Trainable& network);

    template <class GeneratorInteger, class Optimizer>
    void trainStochastic(const Container<Tensor1D>& idata,
                         const Container<Tensor1D>& odata,
                         size_type iteration_scale,
                         GeneratorInteger generator,
                         Optimizer&& optimizer) noexcept;

    template <class Optimizer>
    void trainBatch(const Container<Tensor1D>& idata,
                    const Container<Tensor1D>& odata,
                    size_type epoch_scale,
                    Optimizer&& optimizer) noexcept;

    template <class Optimizer>
    void trainMiniBatch(const Container<Tensor1D>& idata,
                        const Container<Tensor1D>& odata,
                        size_type epoch_scale,
                        size_type mini_batch_size,
                        Optimizer&& optimizer) noexcept;

    long double accuracy(const Container<Tensor1D>& idata,
                         const Container<Tensor1D>& odata) const noexcept;

    long double accuracyf(const Container<Tensor1D>& idata,
                          const Container<Tensor1D>& odata,
                          precision_type range_rate) const noexcept;

    long double accuracyg(const Container<Tensor1D>& idata,
                          const Container<Tensor1D>& odata,
                          precision_type range_rate) const noexcept;

    long double loss(const Container<Tensor1D>& idata,
                     const Container<Tensor1D>& odata) const noexcept;

private:
    void innerFeedForward(const Tensor1D& sample) noexcept;

    void innerBackPropagation(const Tensor1D& sample,
                              const Tensor1D& target) noexcept;

    void resetDelta() noexcept;
    void updateDelta() noexcept;

    void normalizeDelta(precision_type alpha) noexcept; ///< alpha should be in range (0, 1)
};

TRIXY_TRAINING_TPL_DECLARATION
TRIXY_TRAINING_TPL(meta::is_feedforward_net)::Training(Trainable& network) : net(network)
{
    H.resize(net.N);
    derivedH.resize(net.N);

    derivedB.resize(net.N);
    derivedW.resize(net.N);

    deltaB.resize(net.N);
    deltaW.resize(net.N);

    buff.resize(net.N);

    for(size_type i = 0; i < net.N; ++i)
    {
        H[i].resize(net.topology[i + 1]);
        derivedH[i].resize(net.topology[i + 1]);

        derivedB[i].resize(net.topology[i + 1]);
        derivedW[i].resize(net.topology[i], net.topology[i + 1]);

        deltaB[i].resize(net.topology[i + 1]);
        deltaW[i].resize(net.topology[i], net.topology[i + 1]);

        buff[i].resize(net.topology[i + 1]);
    }
}

TRIXY_TRAINING_TPL_DECLARATION
template <class GeneratorInteger, class Optimizer>
void TRIXY_TRAINING_TPL(meta::is_feedforward_net)::trainStochastic(
    const Container<Tensor1D>& idata,
    const Container<Tensor1D>& odata,
    size_type iteration_scale,
    GeneratorInteger generator,
    Optimizer&& optimizer) noexcept
{
    for(size_type i = 0, sample; i < iteration_scale; ++i)
    {
        sample = generator() % idata.size();

        innerFeedForward(idata[sample]);
        innerBackPropagation(idata[sample], odata[sample]);

        optimizer.update(net.B, net.W, derivedB, derivedW);
    }
}

TRIXY_TRAINING_TPL_DECLARATION
template <class Optimizer>
void TRIXY_TRAINING_TPL(meta::is_feedforward_net)::trainBatch(
    const Container<Tensor1D>& idata,
    const Container<Tensor1D>& odata,
    size_type epoch_scale,
    Optimizer&& optimizer) noexcept
{
    precision_type alpha = 1. / static_cast<precision_type>(idata.size());

    for(size_type epoch = 0, sample; epoch < epoch_scale; ++epoch)
    {
        resetDelta();

        for(sample = 0; sample < idata.size(); ++sample)
        {
            innerFeedForward(idata[sample]);
            innerBackPropagation(idata[sample], odata[sample]);
            updateDelta();
        }

        normalizeDelta(alpha);

        optimizer.update(net.B, net.W, deltaB, deltaW);
    }
}

TRIXY_TRAINING_TPL_DECLARATION
template <class Optimizer>
void TRIXY_TRAINING_TPL(meta::is_feedforward_net)::trainMiniBatch(
    const Container<Tensor1D>& idata,
    const Container<Tensor1D>& odata,
    size_type epoch_scale,
    size_type mini_batch_size,
    Optimizer&& optimizer) noexcept
{
    precision_type alpha = 1. / static_cast<precision_type>(mini_batch_size);

    size_type iteration_scale = idata.size() / mini_batch_size;

    size_type sample;
    size_type sample_limit;

    for(size_type epoch = 0, i; epoch < epoch_scale; ++epoch)
    {
        sample = 0;
        sample_limit = 0;

        for(i = 0; i < iteration_scale; ++i)
        {
            sample_limit += mini_batch_size;

            resetDelta();

            while(sample < sample_limit)
            {
                innerFeedForward(idata[sample]);
                innerBackPropagation(idata[sample], odata[sample]);
                updateDelta();

                ++sample;
            }

            normalizeDelta(alpha);

            optimizer.update(net.B, net.W, deltaB, deltaW);
        }
    }
}

TRIXY_TRAINING_TPL_DECLARATION
long double TRIXY_TRAINING_TPL(meta::is_feedforward_net)::accuracy(
    const Container<Tensor1D>& idata,
    const Container<Tensor1D>& odata) const noexcept
{
    return net.accuracy(idata, odata);
}

TRIXY_TRAINING_TPL_DECLARATION
long double TRIXY_TRAINING_TPL(meta::is_feedforward_net)::accuracyf(
    const Container<Tensor1D>& idata,
    const Container<Tensor1D>& odata,
    precision_type range_rate) const noexcept
{
    return net.accuracyf(idata, odata, range_rate);
}

TRIXY_TRAINING_TPL_DECLARATION
long double TRIXY_TRAINING_TPL(meta::is_feedforward_net)::accuracyg(
    const Container<Tensor1D>& idata,
    const Container<Tensor1D>& odata,
    precision_type range_rate) const noexcept
{
    return net.accuracyg(idata, odata, range_rate);
}

TRIXY_TRAINING_TPL_DECLARATION
long double TRIXY_TRAINING_TPL(meta::is_feedforward_net)::loss(
    const Container<Tensor1D>& idata,
    const Container<Tensor1D>& odata) const noexcept
{
    return net.loss(idata, odata);
}

TRIXY_TRAINING_TPL_DECLARATION
void TRIXY_TRAINING_TPL(meta::is_feedforward_net)::innerFeedForward(
    const Tensor1D& sample) noexcept
{
    size_type i;
    size_type j;

    net.linear.dot(buff[0], sample, net.W[0]);
    buff[0].add(net.B[0]);

    for(i = 0, j = 1; j < net.N; ++i, ++j)
    {
        net.function.activation[i]. f(H[i],        buff[i]);
        net.function.activation[i].df(derivedH[i], buff[i]);

        net.linear.dot(buff[j], H[i], net.W[j]);
        buff[j].add(net.B[j]);
    }

    net.function.activation[i]. f(H[i],        buff[i]);
    net.function.activation[i].df(derivedH[i], buff[i]);
}

TRIXY_TRAINING_TPL_DECLARATION
void TRIXY_TRAINING_TPL(meta::is_feedforward_net)::innerBackPropagation(
    const Tensor1D& sample,
    const Tensor1D& target) noexcept
{
    size_type i;
    size_type j;

    i = net.N - 1;
    net.function.loss.df(buff[i], target, H[i]);

    for(j = i - 1; i > 0; --i, --j)
    {
        derivedB[i].multiply(buff[i], derivedH[i]);
        net.linear.tensordot(derivedW[i], H[j], derivedB[i]);
        net.linear.dot(buff[j], net.W[i], derivedB[i]);
    }

    derivedB[0].multiply(buff[0], derivedH[0]);
    net.linear.tensordot(derivedW[0], sample, derivedB[0]);
}

TRIXY_TRAINING_TPL_DECLARATION
void TRIXY_TRAINING_TPL(meta::is_feedforward_net)::resetDelta() noexcept
{
    for(size_type i = 0; i < net.N; ++i)
    {
        deltaB[i].fill(0.0);
        deltaW[i].fill(0.0);
    }
}

TRIXY_TRAINING_TPL_DECLARATION
void TRIXY_TRAINING_TPL(meta::is_feedforward_net)::updateDelta() noexcept
{
    for(size_type i = 0; i < net.N; ++i)
    {
        deltaB[i].add(derivedB[i]);
        deltaW[i].add(derivedW[i]);
    }
}

TRIXY_TRAINING_TPL_DECLARATION
void TRIXY_TRAINING_TPL(meta::is_feedforward_net)::normalizeDelta(
    precision_type alpha) noexcept
{
    for(size_type i = 0; i < net.N; ++i)
    {
        deltaB[i].join(alpha);
        deltaW[i].join(alpha);
    }
}

} // namespace train

} // namespace trixy

#include "Trixy/Neuro/Detail/MacroUnscope.hpp"

#endif // FEED_FORWARD_NET_TRAINING_HPP
