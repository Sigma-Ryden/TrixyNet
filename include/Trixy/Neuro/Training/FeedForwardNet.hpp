#ifndef TRIXY_TRAINING_FEED_FORWARD_NET_HPP
#define TRIXY_TRAINING_FEED_FORWARD_NET_HPP

#include <Trixy/Neuro/Training/Base.hpp>

#include <Trixy/Neuro/Functional/Optimizer/Base.hpp>

#include <Trixy/Neuro/Detail/TrixyNetMeta.hpp>

#include <Trixy/Neuro/Detail/MacroScope.hpp>

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

public:
    using Net = Trainable;

    using Builder                   = typename Net::Builder;

    template <class Derived>
    using IOptimizer                = typename train::IOptimizer<Derived, Net>;

    template <class T>
    using Container                 = typename Net::template Container<T>;

    using XVector                   = typename Net::XVector;
    using XMatrix                   = typename Net::XMatrix;

    using Vector                    = typename Net::Vector;
    using Matrix                    = typename Net::Matrix;

    template <class T>
    using XContainer                = typename Net::template XContainer<T>;

    using precision_type            = typename Net::precision_type;
    using size_type                 = typename Net::size_type;

    using InnerBuffer               = XContainer<XVector>;

private:
    Net& net;                       ///< reference to network prevent her copying

private:
    FeedForwardData feedforward_;   ///< data struct only for feed forward signal
    BackPropData backprop_;         ///< data struct only for back propagation signal

public:
    InnerBuffer buff;               ///< 1D buffer for handle

public:
    explicit Training(Net& network);

    // operator= for copy and move Training object will not implicit generate
    Training(const Training&) = default;
    Training(Training&&) noexcept = default;

    template <class Derived, class GeneratorInteger>
    void trainStochastic(const Container<Vector>& idata,
                         const Container<Vector>& odata,
                         IOptimizer<Derived>& optimizer,
                         size_type iteration_scale,
                         GeneratorInteger generator) noexcept;

    template <class Derived>
    void trainBatch(const Container<Vector>& idata,
                    const Container<Vector>& odata,
                    IOptimizer<Derived>& optimizer,
                    size_type number_of_epochs) noexcept;

    template <class Derived>
    void trainMiniBatch(const Container<Vector>& idata,
                        const Container<Vector>& odata,
                        IOptimizer<Derived>& optimizer,
                        size_type number_of_epochs,
                        size_type mini_batch_size) noexcept;

    FeedForwardData& feedforward() noexcept;
    void feedforward(const Vector& sample) noexcept;

    BackPropData& backprop() noexcept;
    void backprop(const Vector& sample,
                  const Vector& target) noexcept;

    long double loss(const Container<Vector>& idata,
                     const Container<Vector>& odata) const noexcept; // repair
};

TRIXY_TRAINING_TPL_DECLARATION
struct TRIXY_TRAINING_TPL(meta::is_feedforward_net)::FeedForwardData
{
public:
    XContainer<XVector> S;          ///< non-activated value for hidden layer
    XContainer<XVector> H;          ///< hidden layer storage

    const size_type size;           ///< Number of functional layer (same as net_topology_size - 1)

public:
    explicit FeedForwardData(const Net& network);

    // operator= for copy and move FeedForwardData object will not implicit generate
    FeedForwardData(const FeedForwardData&) = default;
    FeedForwardData(FeedForwardData&&) noexcept = default;
};

TRIXY_TRAINING_TPL_DECLARATION
struct TRIXY_TRAINING_TPL(meta::is_feedforward_net)::BackPropData
{
private:
    const Net& net;

public:
    XContainer<XVector> gradB;      ///< derived bias storage (using for inner updates)
    XContainer<XMatrix> gradW;      ///< derived weight storage (using for inner updates)

    XContainer<XVector> deltaB;     ///< delta bias is accumulator of derived bias
    XContainer<XMatrix> deltaW;     ///< delta weight is accumulator of derived weight

    const size_type size;           ///< Number of functional layer (same as net_topology_size - 1)

public:
    explicit BackPropData(Net& network);

    // operator= for copy and move BackPropData object will not implicit generate
    BackPropData(const BackPropData&) = default;
    BackPropData(BackPropData&&) noexcept = default;

    void resetDelta() noexcept;
    void updateDelta() noexcept;

    void normalizeDelta(precision_type alpha) noexcept;
};

TRIXY_TRAINING_TPL_DECLARATION
TRIXY_TRAINING_TPL(meta::is_feedforward_net)::FeedForwardData::FeedForwardData(const Net& network)
    : S(Builder::getlock1d(network.inner.topology))
    , H(Builder::getlock1d(network.inner.topology))
    , size(network.inner.N)
{
}

TRIXY_TRAINING_TPL_DECLARATION
TRIXY_TRAINING_TPL(meta::is_feedforward_net)::BackPropData::BackPropData(Net& network)
    : net(network)
    , gradB(Builder::getlock1d(network.inner.topology))
    , gradW(Builder::getlock2d(network.inner.topology))
    , deltaB(Builder::getlock1d(network.inner.topology))
    , deltaW(Builder::getlock2d(network.inner.topology))
    , size(network.inner.N)
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
        net.linear.add(deltaB[i], gradB[i]);
        net.linear.add(deltaW[i], gradW[i]);
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
    , feedforward_(network)
    , backprop_(network)
    , buff(Builder::getlock1d(network.inner.topology))
{
}

TRIXY_TRAINING_TPL_DECLARATION
template <class Derived, class GeneratorInteger>
void TRIXY_TRAINING_TPL(meta::is_feedforward_net)::trainStochastic(
    const Container<Vector>& idata,
    const Container<Vector>& odata,
    IOptimizer<Derived>& optimizer,
    size_type iteration_scale,
    GeneratorInteger generator) noexcept
{
    for (size_type iteration = 0, sample; iteration < iteration_scale; ++iteration)
    {
        sample = generator() % idata.size();

        feedforward(idata[sample]);
        backprop(idata[sample], odata[sample]);

        optimizer.update(backprop_.gradB.base(), backprop_.gradW.base());
    }
}

TRIXY_TRAINING_TPL_DECLARATION
template <class Derived>
void TRIXY_TRAINING_TPL(meta::is_feedforward_net)::trainBatch(
    const Container<Vector>& idata,
    const Container<Vector>& odata,
    IOptimizer<Derived>& optimizer,
    size_type number_of_epochs) noexcept
{
    precision_type alpha = 1. / static_cast<precision_type>(idata.size());

    for (size_type epoch = 0, sample; epoch < number_of_epochs; ++epoch)
    {
        backprop_.resetDelta();

        for (sample = 0; sample < idata.size(); ++sample)
        {
            feedforward(idata[sample]);
            backprop(idata[sample], odata[sample]);
            backprop_.updateDelta();
        }
        // averaging deltas for one full-batch
        backprop_.normalizeDelta(alpha);

        optimizer.update(backprop_.deltaB.base(), backprop_.deltaW.base());
    }
}

TRIXY_TRAINING_TPL_DECLARATION
template <class Derived>
void TRIXY_TRAINING_TPL(meta::is_feedforward_net)::trainMiniBatch(
    const Container<Vector>& idata,
    const Container<Vector>& odata,
    IOptimizer<Derived>& optimizer,
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

            backprop_.resetDelta();

            // accumulating deltas for one mini-batch
            while (sample < sample_limit)
            {
                feedforward(idata[sample]);
                backprop(idata[sample], odata[sample]);
                backprop_.updateDelta();

                ++sample;
            }
            // averaging deltas for one mini-batch
            backprop_.normalizeDelta(alpha);

            optimizer.update(backprop_.deltaB.base(), backprop_.deltaW.base());
        }
    }
}

TRIXY_TRAINING_TPL_DECLARATION
void TRIXY_TRAINING_TPL(meta::is_feedforward_net)::feedforward(
    const Vector& sample) noexcept
{
    /*
    Operations:
    . - dot
    Processing:
    S = H' . W + B, H' - previous
    H = activation(S)
    */

    // current and forward numbers of layer in network
    size_type curr = 0;
    size_type fwd  = 1;

    net.linear.dot(feedforward_.S[curr], sample, net.inner.W[curr]);
    net.linear.add(feedforward_.S[curr], net.inner.B[curr]);
    net.function.activation(curr).f(feedforward_.H[curr], feedforward_.S[curr]);

    for (; fwd < net.inner.N; ++curr, ++fwd)
    {
        net.linear.dot(feedforward_.S[fwd], feedforward_.H[curr], net.inner.W[fwd]);
        net.linear.add(feedforward_.S[fwd], net.inner.B[fwd]);
        net.function.activation(fwd).f(feedforward_.H[fwd], feedforward_.S[fwd]);
    }
}

TRIXY_TRAINING_TPL_DECLARATION
void TRIXY_TRAINING_TPL(meta::is_feedforward_net)::backprop(
    const Vector& sample,
    const Vector& target) noexcept
{
    /*
    Operations:
    X - mul
    * - tensordot
    . - dot
    Processing:
    Z* = DE,        Z* - initial value of Z, DE - cost function derived
    DB = Z x DH,    DH - such as DH = activation_derived(S)
    DW = H * DB,    since DW = H * (Z x DH)
    Z' = W . DB^T,  Z' - previous Z in container
    */

    // current and back numbers of layer in network
    size_type curr = net.inner.N - 1;
    size_type back = curr - 1;
    //
    net.function.loss().df(buff[curr], target, feedforward_.H[curr]);
    net.function.activation(curr).df(backprop_.gradB[curr], feedforward_.S[curr]);
    net.linear.mul(backprop_.gradB[curr], buff[curr]);

    for (; curr > 0; --curr, --back)
    {
        net.linear.tensordot(backprop_.gradW[curr], feedforward_.H[back], backprop_.gradB[curr]);

        net.linear.dot(buff[back], net.inner.W[curr], backprop_.gradB[curr]);
        net.function.activation(back).df(backprop_.gradB[back], feedforward_.S[back]);
        net.linear.mul(backprop_.gradB[back], buff[back]);
    }

    net.linear.tensordot(backprop_.gradW[curr], sample, backprop_.gradB[curr]);
}

TRIXY_TRAINING_TPL_DECLARATION
long double TRIXY_TRAINING_TPL(meta::is_feedforward_net)::loss(
    const Container<Vector>& idata,
    const Container<Vector>& odata) const noexcept
{
    precision_type result = 0.;
    precision_type error  = 0.;

    for (size_type i = 0; i < odata.size(); ++i)
    {
        net.function.loss().f(error, odata[i], net.feedforward(idata[i]));
        result += error;
    }

    return result / static_cast<long double>(odata.size());
}

} // namespace train

} // namespace trixy

#include <Trixy/Neuro/Detail/MacroUnscope.hpp>

#endif // TRIXY_TRAINING_FEED_FORWARD_NET_HPP
