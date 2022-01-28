#ifndef FEED_FORWARD_NET_TRAINING_HPP
#define FEED_FORWARD_NET_TRAINING_HPP

#include "BaseTraining.hpp"

#include "Trixy/Neuro/Functional/Optimizer/BaseOptimizer.hpp"
#include "Trixy/Locker/ContainerLocker.hpp"

#include "Trixy/Neuro/Detail/TrixyNetMeta.hpp"

#include "Trixy/Neuro/Detail/MacroScope.hpp"

namespace trixy
{

namespace train
{

TRIXY_TRAINING_TPL_DECLARATION
class TRIXY_TRAINING_TPL(meta::is_feedforward_net)
{
public:
    struct FeedForwardData;
    struct BackPropData;

private:
    using IOptimizer                = typename train::IOptimizer<Trainable>;

    template <class... T>
    using Container                 = typename Trainable::template ContainerType<T...>;

    using Tensor1D                  = typename Trainable::Tensor1D;
    using Tensor2D                  = typename Trainable::Tensor2D;

    using precision_type            = typename Trainable::precision_type;
    using size_type                 = typename Trainable::size_type;

private:
    template <class... T>
    using ContainerLock             = ContainerLocker<Container<T...>>;

private:
    Trainable& net;                 ///< reference to network prevent her copying

public:
    FeedForwardData feedforward;    ///< data struct only for feed forward signal
    BackPropData backprop;          ///< data struct only for back propagation signal

private:
    Container<Tensor1D> buff;       ///< 1D buffer for handle

public:
    Training(Trainable& network);

    Training& operator= (const Training&) = delete;
    Training& operator= (Training&&) = delete;

    void innerFeedForward(const Tensor1D& sample) noexcept;

    void innerBackProp(const Tensor1D& sample,
                       const Tensor1D& target) noexcept;

    template <class GeneratorInteger>
    void trainStochastic(const Container<Tensor1D>& idata,
                         const Container<Tensor1D>& odata,
                         size_type iteration_scale,
                         GeneratorInteger generator,
                         IOptimizer& optimizer) noexcept;

    void trainBatch(const Container<Tensor1D>& idata,
                    const Container<Tensor1D>& odata,
                    size_type epoch_scale,
                    IOptimizer& optimizer) noexcept;

    void trainMiniBatch(const Container<Tensor1D>& idata,
                        const Container<Tensor1D>& odata,
                        size_type epoch_scale,
                        size_type mini_batch_size,
                        IOptimizer& optimizer) noexcept;

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
};

TRIXY_TRAINING_TPL_DECLARATION
struct TRIXY_TRAINING_TPL(meta::is_feedforward_net)::FeedForwardData
{
public:
    const size_type size;               ///< Number of functional layer (same as net_topology_size - 1)

    ContainerLock<Tensor1D> S;          ///< non-activated value for hidden layer
    ContainerLock<Tensor1D> H;          ///< hidden layer storage

public:
    FeedForwardData(const Container<size_type>& topology);

    FeedForwardData& operator= (const FeedForwardData&) = delete;
    FeedForwardData& operator= (FeedForwardData&&) = delete;
};

TRIXY_TRAINING_TPL_DECLARATION
struct TRIXY_TRAINING_TPL(meta::is_feedforward_net)::BackPropData
{
public:
    const size_type size;               ///< Number of functional layer (same as net_topology_size - 1)

    ContainerLock<Tensor1D> derivedB;   ///< derived bias storage (using for inner updates)
    ContainerLock<Tensor2D> derivedW;   ///< derived weight storage (using for inner updates)

    ContainerLock<Tensor1D> deltaB;     ///< delta bias is accumulator of derived bias
    ContainerLock<Tensor2D> deltaW;     ///< delta weight is accumulator of derived weight

public:
    BackPropData(const Container<size_type>& topology);

    BackPropData& operator= (const BackPropData&) = delete;
    BackPropData& operator= (BackPropData&&) = delete;

    void resetDelta() noexcept;
    void updateDelta() noexcept;

    void normalizeDelta(precision_type alpha) noexcept;
};

TRIXY_TRAINING_TPL_DECLARATION
TRIXY_TRAINING_TPL(meta::is_feedforward_net)::FeedForwardData::FeedForwardData(
    const Container<size_type>& topology)
    : size(topology.size() - 1)
    , S(topology.size() - 1)
    , H(topology.size() - 1)
{
    for(size_type i = 0; i < size; ++i)
    {
        H[i].resize(topology[i + 1]);
        S[i].resize(topology[i + 1]);
    }
}

TRIXY_TRAINING_TPL_DECLARATION
TRIXY_TRAINING_TPL(meta::is_feedforward_net)::BackPropData::BackPropData(
    const Container<size_type>& topology)
    : size(topology.size() - 1)
    , derivedB(topology.size() - 1)
    , derivedW(topology.size() - 1)
    , deltaB(topology.size() - 1)
    , deltaW(topology.size() - 1)
{
    for(size_type i = 0; i < size; ++i)
    {
        derivedB[i].resize(topology[i + 1]);
        derivedW[i].resize(topology[i], topology[i + 1]);

        deltaB[i].resize(topology[i + 1]);
        deltaW[i].resize(topology[i], topology[i + 1]);
    }
}

TRIXY_TRAINING_TPL_DECLARATION
void TRIXY_TRAINING_TPL(meta::is_feedforward_net)::BackPropData::resetDelta() noexcept
{
    for(size_type i = 0; i < size; ++i)
    {
        deltaB[i].fill(0.0);
        deltaW[i].fill(0.0);
    }
}

TRIXY_TRAINING_TPL_DECLARATION
void TRIXY_TRAINING_TPL(meta::is_feedforward_net)::BackPropData::updateDelta() noexcept
{
    for(size_type i = 0; i < size; ++i)
    {
        deltaB[i].add(derivedB[i]);
        deltaW[i].add(derivedW[i]);
    }
}

TRIXY_TRAINING_TPL_DECLARATION
void TRIXY_TRAINING_TPL(meta::is_feedforward_net)::BackPropData::normalizeDelta(
    precision_type alpha) noexcept
{
    for(size_type i = 0; i < size; ++i)
    {
        deltaB[i].join(alpha);
        deltaW[i].join(alpha);
    }
}

TRIXY_TRAINING_TPL_DECLARATION
TRIXY_TRAINING_TPL(meta::is_feedforward_net)::Training(Trainable& network)
    : net(network)
    , feedforward(network.inner.topology)
    , backprop(network.inner.topology)
    , buff(network.inner.N)
{
    for(size_type i = 0; i < net.inner.N; ++i)
        buff[i].resize(net.inner.topology[i + 1]);
}

TRIXY_TRAINING_TPL_DECLARATION
template <class GeneratorInteger>
void TRIXY_TRAINING_TPL(meta::is_feedforward_net)::trainStochastic(
    const Container<Tensor1D>& idata,
    const Container<Tensor1D>& odata,
    size_type iteration_scale,
    GeneratorInteger generator,
    IOptimizer& optimizer) noexcept
{
    for(size_type i = 0, sample; i < iteration_scale; ++i)
    {
        sample = generator() % idata.size();

        innerFeedForward(idata[sample]);
        innerBackProp(idata[sample], odata[sample]);

        optimizer.update(backprop.derivedB.base(), backprop.derivedW.base());
    }
}

TRIXY_TRAINING_TPL_DECLARATION
void TRIXY_TRAINING_TPL(meta::is_feedforward_net)::trainBatch(
    const Container<Tensor1D>& idata,
    const Container<Tensor1D>& odata,
    size_type epoch_scale,
    IOptimizer& optimizer) noexcept
{
    precision_type alpha = 1. / static_cast<precision_type>(idata.size());

    for(size_type epoch = 0, sample; epoch < epoch_scale; ++epoch)
    {
        backprop.resetDelta();

        for(sample = 0; sample < idata.size(); ++sample)
        {
            innerFeedForward(idata[sample]);
            innerBackProp(idata[sample], odata[sample]);
            backprop.updateDelta();
        }

        backprop.normalizeDelta(alpha);

        optimizer.update(backprop.deltaB.base(), backprop.deltaW.base());
    }
}

TRIXY_TRAINING_TPL_DECLARATION
void TRIXY_TRAINING_TPL(meta::is_feedforward_net)::trainMiniBatch(
    const Container<Tensor1D>& idata,
    const Container<Tensor1D>& odata,
    size_type epoch_scale,
    size_type mini_batch_size,
    IOptimizer& optimizer) noexcept
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

            backprop.resetDelta();

            while(sample < sample_limit)
            {
                innerFeedForward(idata[sample]);
                innerBackProp(idata[sample], odata[sample]);
                backprop.updateDelta();

                ++sample;
            }

            backprop.normalizeDelta(alpha);

            optimizer.update(backprop.deltaB.base(), backprop.deltaW.base());
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
    /*
    Operations:
    . - dot
    Processing:
    S = H' . W + B, H' - previous
    H = activation(S)
    */
    size_type i;
    size_type j;

    net.linear.dot(feedforward.S[0], sample, net.inner.W[0]);
    feedforward.S[0].add(net.inner.B[0]);

    for(i = 0, j = 1; j < net.inner.N; ++i, ++j)
    {
        net.function.activation[i].f(feedforward.H[i], feedforward.S[i]);

        net.linear.dot(feedforward.S[j], feedforward.H[i], net.inner.W[j]);
        feedforward.S[j].add(net.inner.B[j]);
    }

    net.function.activation[i].f(feedforward.H[i], feedforward.S[i]);
}

TRIXY_TRAINING_TPL_DECLARATION
void TRIXY_TRAINING_TPL(meta::is_feedforward_net)::innerBackProp(
    const Tensor1D& sample,
    const Tensor1D& target) noexcept
{
    /*
    Operations:
    * - mul
    x - tensordot
    . - dot
    Processing:
    Z* = DE,        Z* - initial value of Z, DE - cost function derived
    DB = DH * Z,    DH - such as DH = activation_derived(S)
    DW = H x DB,    since DW = H x (Z * DH)
    Z' = W . DB^T,  Z' - previous Z in container
    */
    size_type i;
    size_type j;

    i = net.inner.N - 1;
    net.function.loss.df(buff[i], target, feedforward.H[i]);

    for(j = i - 1; i > 0; --i, --j)
    {
        net.function.activation[i].df(backprop.derivedB[i], feedforward.S[i]);
        backprop.derivedB[i].multiply(buff[i]);

        net.linear.tensordot(backprop.derivedW[i], feedforward.H[j], backprop.derivedB[i]);

        net.linear.dot(buff[j], net.inner.W[i], backprop.derivedB[i]);
    }

    net.function.activation[0].df(backprop.derivedB[0], feedforward.S[0]);
    backprop.derivedB[i].multiply(buff[0]);

    net.linear.tensordot(backprop.derivedW[0], sample, backprop.derivedB[0]);
}

} // namespace train

} // namespace trixy

#include "Trixy/Neuro/Detail/MacroUnscope.hpp"

#endif // FEED_FORWARD_NET_TRAINING_HPP
