#ifndef TRIXY_TRAINING_FEED_FORWARD_NET_HPP
#define TRIXY_TRAINING_FEED_FORWARD_NET_HPP

#include <cmath> // fabs

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
    struct Accuracy;

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

    using InnerBuffer               = typename Net::InnerBuffer;

private:
    Net& net;                       ///< reference to network prevent her copying

public:
    FeedForwardData feedforward;    ///< data struct only for feed forward signal
    BackPropData backprop;          ///< data struct only for back propagation signal
    Accuracy accuracy;              ///< object for information of different accuracy types

private:
    InnerBuffer buff;               ///< 1D buffer for handle

public:
    explicit Training(Net& network);

    // operator= for copy and move Training object will not implicit generate
    Training(const Training&) = default;
    Training(Training&&) noexcept = default;

    template <class GeneratorInteger, class Derived>
    void trainStochastic(const Container<Vector>& idata,
                         const Container<Vector>& odata,
                         size_type iteration_scale,
                         GeneratorInteger generator,
                         IOptimizer<Derived>& optimizer) noexcept;

    template <class Derived>
    void trainBatch(const Container<Vector>& idata,
                    const Container<Vector>& odata,
                    size_type epoch_scale,
                    IOptimizer<Derived>& optimizer) noexcept;

    template <class Derived>
    void trainMiniBatch(const Container<Vector>& idata,
                        const Container<Vector>& odata,
                        size_type epoch_scale,
                        size_type mini_batch_size,
                        IOptimizer<Derived>& optimizer) noexcept;

    void innerFeedForward(const Vector& sample) noexcept;

    void innerBackProp(const Vector& sample,
                       const Vector& target) noexcept;

    long double loss(const Container<Vector>& idata,
                     const Container<Vector>& odata) const noexcept;
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
    XContainer<XVector> derivedB;   ///< derived bias storage (using for inner updates)
    XContainer<XMatrix> derivedW;   ///< derived weight storage (using for inner updates)

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
struct TRIXY_TRAINING_TPL(meta::is_feedforward_net)::Accuracy
{
private:
    const Net& net;

public:
    explicit Accuracy(Net& network) : net(network) {}

    // operator= for copy and move BackPropData object will not implicit generate
    Accuracy(const Accuracy&) = default;
    Accuracy(Accuracy&&) noexcept = default;

public:
    long double normal(const Container<Vector>& idata,
                       const Container<Vector>& odata) const noexcept; // repair & replace

    long double full(const Container<Vector>& idata,
                     const Container<Vector>& odata,
                     precision_type range_rate) const noexcept; // repair

    long double global(const Container<Vector>& idata,
                       const Container<Vector>& odata,
                       precision_type range_rate) const noexcept; // repair

private:
    bool check_normal(const Vector& target,
                      const Vector& prediction) const noexcept; // repair & replace

    bool check_full(const Vector& target,
                    const Vector& prediction,
                    precision_type range_rate) const noexcept; // maybe repair

    void check_global(const Vector& target,
                      const Vector& prediction,
                      precision_type range_rate,
                      size_type& count) const noexcept; // maybe repair
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
    , derivedB(Builder::getlock1d(network.inner.topology))
    , derivedW(Builder::getlock2d(network.inner.topology))
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
        net.linear.add(deltaB[i], derivedB[i]);
        net.linear.add(deltaW[i], derivedW[i]);
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
long double TRIXY_TRAINING_TPL(meta::is_feedforward_net)::Accuracy::normal(
    const Container<Vector>& idata,
    const Container<Vector>& odata) const noexcept
{
    return net.accuracy(idata, odata);
}

TRIXY_TRAINING_TPL_DECLARATION
long double TRIXY_TRAINING_TPL(meta::is_feedforward_net)::Accuracy::full(
    const Container<Vector>& idata,
    const Container<Vector>& odata,
    precision_type range_rate) const noexcept
{
    size_type count = 0;

    for(size_type i = 0; i < odata.size(); ++i)
        if(check_full(odata[i], net.feedforward(idata[i]), range_rate))
            ++count;

    return static_cast<long double>(count) / odata.size();
}

TRIXY_TRAINING_TPL_DECLARATION
long double TRIXY_TRAINING_TPL(meta::is_feedforward_net)::Accuracy::global(
    const Container<Vector>& idata,
    const Container<Vector>& odata,
    precision_type range_rate) const noexcept
{
    size_type count = 0;

    for(size_type i = 0; i < odata.size(); ++i)
        check_global(odata[i], net.feedforward(idata[i]), range_rate, count);

    return static_cast<long double>(count) / (odata.size() * odata.front().size());
}

TRIXY_TRAINING_TPL_DECLARATION
bool TRIXY_TRAINING_TPL(meta::is_feedforward_net)::Accuracy::check_normal(
    const Vector& target,
    const Vector& prediction) const noexcept
{
    return net.check(target, prediction);
}

TRIXY_TRAINING_TPL_DECLARATION
bool TRIXY_TRAINING_TPL(meta::is_feedforward_net)::Accuracy::check_full(
    const Vector& target,
    const Vector& prediction,
    precision_type range_rate) const noexcept
{
    for(size_type j = 0; j < target.size(); ++j)
        if(std::fabs(target(j) - prediction(j)) > range_rate)
            return false;

    return true;
}

TRIXY_TRAINING_TPL_DECLARATION
void TRIXY_TRAINING_TPL(meta::is_feedforward_net)::Accuracy::check_global(
    const Vector& target,
    const Vector& prediction,
    precision_type range_rate,
    size_type& count) const noexcept
{
    for(size_type i = 0; i < target.size(); ++i)
        if(std::fabs(target(i) - prediction(i)) < range_rate)
            ++count;
}

TRIXY_TRAINING_TPL_DECLARATION
TRIXY_TRAINING_TPL(meta::is_feedforward_net)::Training(Trainable& network)
    : net(network)
    , feedforward(network)
    , backprop(network)
    , accuracy(network)
    , buff(Builder::getlock1d(network.inner.topology))
{
}

TRIXY_TRAINING_TPL_DECLARATION
template <class GeneratorInteger, class Derived>
void TRIXY_TRAINING_TPL(meta::is_feedforward_net)::trainStochastic(
    const Container<Vector>& idata,
    const Container<Vector>& odata,
    size_type iteration_scale,
    GeneratorInteger generator,
    IOptimizer<Derived>& optimizer) noexcept
{
    for(size_type iteration = 0, sample; iteration < iteration_scale; ++iteration)
    {
        sample = generator() % idata.size();

        innerFeedForward(idata[sample]);
        innerBackProp(idata[sample], odata[sample]);

        optimizer.update(backprop.derivedB.base(), backprop.derivedW.base());
    }
}

TRIXY_TRAINING_TPL_DECLARATION
template <class Derived>
void TRIXY_TRAINING_TPL(meta::is_feedforward_net)::trainBatch(
    const Container<Vector>& idata,
    const Container<Vector>& odata,
    size_type epoch_scale,
    IOptimizer<Derived>& optimizer) noexcept
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
template <class Derived>
void TRIXY_TRAINING_TPL(meta::is_feedforward_net)::trainMiniBatch(
    const Container<Vector>& idata,
    const Container<Vector>& odata,
    size_type epoch_scale,
    size_type mini_batch_size,
    IOptimizer<Derived>& optimizer) noexcept
{
    precision_type alpha = 1. / static_cast<precision_type>(mini_batch_size);

    size_type iteration_scale = idata.size() / mini_batch_size; // implicit drop floating part

    size_type sample;
    size_type sample_limit;

    for(size_type epoch = 0, iteration; epoch < epoch_scale; ++epoch)
    {
        sample = 0;
        sample_limit = 0;

        for(iteration = 0; iteration < iteration_scale; ++iteration)
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

    // current and forward numbers of layer in network
    size_type curr = 0;
    size_type fwd  = 1;

    net.linear.dot(feedforward.S[curr], sample, net.inner.W[curr]);
    net.linear.add(feedforward.S[curr], net.inner.B[curr]);

    for(; fwd < net.inner.N; ++curr, ++fwd)
    {
        net.function.activation[curr].f(feedforward.H[curr], feedforward.S[curr]);

        net.linear.dot(feedforward.S[fwd], feedforward.H[curr], net.inner.W[fwd]);
        net.linear.add(feedforward.S[fwd], net.inner.B[fwd]);
    }

    net.function.activation[curr].f(feedforward.H[curr], feedforward.S[curr]);
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

    // current and back numbers of layer in network
    size_type curr = net.inner.N - 1;
    size_type back = curr - 1;

    net.function.loss.df(buff[curr], target, feedforward.H[curr]);

    for(; curr > 0; --curr, --back)
    {
        net.function.activation[curr].df(backprop.derivedB[curr], feedforward.S[curr]);
        net.linear.mul(backprop.derivedB[curr], buff[curr]);

        net.linear.tensordot(backprop.derivedW[curr], feedforward.H[back], backprop.derivedB[curr]);

        net.linear.dot(buff[back], net.inner.W[curr], backprop.derivedB[curr]);
    }

    net.function.activation[curr].df(backprop.derivedB[curr], feedforward.S[curr]);
    net.linear.mul(backprop.derivedB[curr], buff[curr]);

    net.linear.tensordot(backprop.derivedW[curr], sample, backprop.derivedB[curr]);
}

TRIXY_TRAINING_TPL_DECLARATION
long double TRIXY_TRAINING_TPL(meta::is_feedforward_net)::loss(
    const Container<Vector>& idata,
    const Container<Vector>& odata) const noexcept
{
    return net.loss(idata, odata);
}

} // namespace train

} // namespace trixy

#include <Trixy/Neuro/Detail/MacroUnscope.hpp>

#endif // TRIXY_TRAINING_FEED_FORWARD_NET_HPP
