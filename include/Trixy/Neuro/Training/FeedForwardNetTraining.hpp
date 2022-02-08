#ifndef FEED_FORWARD_NET_TRAINING_HPP
#define FEED_FORWARD_NET_TRAINING_HPP

#include "BaseTraining.hpp"

#include "Trixy/Neuro/Functional/Optimizer/BaseOptimizer.hpp"

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
    using Container                 = typename Trainable::template Container<T...>;

    using LVector                   = typename Trainable::LVector;
    using LMatrix                   = typename Trainable::LMatrix;

    using Vector                    = typename Trainable::Vector;
    using Matrix                    = typename Trainable::Matrix;

    template <class... T>
    using LContainer                = typename Trainable::template LContainer<T...>;

    using precision_type            = typename Trainable::precision_type;
    using size_type                 = typename Trainable::size_type;

    using InnerBuffer               = typename Trainable::InnerBuffer;

private:
    Trainable& net;                 ///< reference to network prevent her copying

public:
    FeedForwardData feedforward;    ///< data struct only for feed forward signal
    BackPropData backprop;          ///< data struct only for back propagation signal

private:
    InnerBuffer buff;               ///< 1D buffer for handle

public:
    Training(Trainable& network);

    Training(const Training&) = default;
    Training(Training&&) noexcept = default;

    void innerFeedForward(const Vector& sample) noexcept;

    void innerBackProp(const Vector& sample,
                       const Vector& target) noexcept;

    template <class GeneratorInteger>
    void trainStochastic(const Container<Vector>& idata,
                         const Container<Vector>& odata,
                         size_type iteration_scale,
                         GeneratorInteger generator,
                         IOptimizer& optimizer) noexcept;

    void trainBatch(const Container<Vector>& idata,
                    const Container<Vector>& odata,
                    size_type epoch_scale,
                    IOptimizer& optimizer) noexcept;

    void trainMiniBatch(const Container<Vector>& idata,
                        const Container<Vector>& odata,
                        size_type epoch_scale,
                        size_type mini_batch_size,
                        IOptimizer& optimizer) noexcept;

    long double accuracy(const Container<Vector>& idata,
                         const Container<Vector>& odata) const noexcept;

    long double accuracyf(const Container<Vector>& idata,
                          const Container<Vector>& odata,
                          precision_type range_rate) const noexcept;

    long double accuracyg(const Container<Vector>& idata,
                          const Container<Vector>& odata,
                          precision_type range_rate) const noexcept;

    long double loss(const Container<Vector>& idata,
                     const Container<Vector>& odata) const noexcept;
};

TRIXY_TRAINING_TPL_DECLARATION
struct TRIXY_TRAINING_TPL(meta::is_feedforward_net)::FeedForwardData
{
public:
    LContainer<LVector> S;          ///< non-activated value for hidden layer
    LContainer<LVector> H;          ///< hidden layer storage

    const size_type size;           ///< Number of functional layer (same as net_topology_size - 1)

public:
    FeedForwardData(const Container<size_type>& topology);

    FeedForwardData(const FeedForwardData&) = default;
    FeedForwardData(FeedForwardData&&) noexcept = default;
};

TRIXY_TRAINING_TPL_DECLARATION
struct TRIXY_TRAINING_TPL(meta::is_feedforward_net)::BackPropData
{
public:
    LContainer<LVector> derivedB;   ///< derived bias storage (using for inner updates)
    LContainer<LMatrix> derivedW;   ///< derived weight storage (using for inner updates)

    LContainer<LVector> deltaB;     ///< delta bias is accumulator of derived bias
    LContainer<LMatrix> deltaW;     ///< delta weight is accumulator of derived weight

    const size_type size;           ///< Number of functional layer (same as net_topology_size - 1)

public:
    BackPropData(const Container<size_type>& topology);

    BackPropData(const BackPropData&) = default;
    BackPropData(BackPropData&&) noexcept = default;

    void resetDelta() noexcept;
    void updateDelta() noexcept;

    void normalizeDelta(precision_type alpha) noexcept;
};

TRIXY_TRAINING_TPL_DECLARATION
TRIXY_TRAINING_TPL(meta::is_feedforward_net)::FeedForwardData::FeedForwardData(
    const Container<size_type>& topology)
    : S(Trainable::init1D(topology))
    , H(Trainable::init1D(topology))
    , size(topology.size() - 1)
{
}

TRIXY_TRAINING_TPL_DECLARATION
TRIXY_TRAINING_TPL(meta::is_feedforward_net)::BackPropData::BackPropData(
    const Container<size_type>& topology)
    : derivedB(Trainable::init1D(topology))
    , derivedW(Trainable::init2D(topology))
    , deltaB(Trainable::init1D(topology))
    , deltaW(Trainable::init2D(topology))
    , size(topology.size() - 1)
{
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
        deltaB[i].add(derivedB[i].base());
        deltaW[i].add(derivedW[i].base());
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
    , buff(Trainable::init1D(network.inner.topology))
{
}

TRIXY_TRAINING_TPL_DECLARATION
template <class GeneratorInteger>
void TRIXY_TRAINING_TPL(meta::is_feedforward_net)::trainStochastic(
    const Container<Vector>& idata,
    const Container<Vector>& odata,
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
    const Container<Vector>& idata,
    const Container<Vector>& odata,
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
    const Container<Vector>& idata,
    const Container<Vector>& odata,
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
    const Container<Vector>& idata,
    const Container<Vector>& odata) const noexcept
{
    return net.accuracy(idata, odata);
}

TRIXY_TRAINING_TPL_DECLARATION
long double TRIXY_TRAINING_TPL(meta::is_feedforward_net)::accuracyf(
    const Container<Vector>& idata,
    const Container<Vector>& odata,
    precision_type range_rate) const noexcept
{
    return net.accuracyf(idata, odata, range_rate);
}

TRIXY_TRAINING_TPL_DECLARATION
long double TRIXY_TRAINING_TPL(meta::is_feedforward_net)::accuracyg(
    const Container<Vector>& idata,
    const Container<Vector>& odata,
    precision_type range_rate) const noexcept
{
    return net.accuracyg(idata, odata, range_rate);
}

TRIXY_TRAINING_TPL_DECLARATION
long double TRIXY_TRAINING_TPL(meta::is_feedforward_net)::loss(
    const Container<Vector>& idata,
    const Container<Vector>& odata) const noexcept
{
    return net.loss(idata, odata);
}

TRIXY_TRAINING_TPL_DECLARATION
void TRIXY_TRAINING_TPL(meta::is_feedforward_net)::innerFeedForward(
    const Vector& sample) noexcept
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
    net.linear.add(feedforward.S[0], net.inner.B[0]);

    for(i = 0, j = 1; j < net.inner.N; ++i, ++j)
    {
        net.function.activation[i].f(feedforward.H[i], feedforward.S[i]);

        net.linear.dot(feedforward.S[j], feedforward.H[i], net.inner.W[j]);
        net.linear.add(feedforward.S[j], net.inner.B[j]);
    }

    net.function.activation[i].f(feedforward.H[i], feedforward.S[i]);
}

TRIXY_TRAINING_TPL_DECLARATION
void TRIXY_TRAINING_TPL(meta::is_feedforward_net)::innerBackProp(
    const Vector& sample,
    const Vector& target) noexcept
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
        net.linear.mul(backprop.derivedB[i], buff[i]);

        net.linear.tensordot(backprop.derivedW[i], feedforward.H[j], backprop.derivedB[i]);

        net.linear.dot(buff[j], net.inner.W[i], backprop.derivedB[i]);
    }

    net.function.activation[0].df(backprop.derivedB[0], feedforward.S[0]);
    net.linear.mul(backprop.derivedB[0], buff[0]);

    net.linear.tensordot(backprop.derivedW[0], sample, backprop.derivedB[0]);
}

} // namespace train

} // namespace trixy

#include "Trixy/Neuro/Detail/MacroUnscope.hpp"

#endif // FEED_FORWARD_NET_TRAINING_HPP
