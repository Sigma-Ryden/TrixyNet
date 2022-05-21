// __EXPERIMENTAL__
#ifndef TRIXY_NETWORK_EXPERIMENTAL_NET_HPP
#define TRIXY_NETWORK_EXPERIMENTAL_NET_HPP

#include <Trixy/Neuro/Network/Layer/Layer.hpp>
#include <Trixy/Neuro/Functional/Function/Loss.hpp>
#include <Trixy/Locker/Core.hpp>

#include <Trixy/Neuro/Network/Require.hpp>

namespace trixy
{

template <typename TypeSet>
class Ex : public TrixyNetRequire<TrixyNetType::FeedForward, TypeSet>
{
public:
    template <typename T>
    using Container                 = typename TypeSet::template Container<T>;

    using Vector                    = typename TypeSet::Vector;
    using Matrix                    = typename TypeSet::Matrix;

    using precision_type            = typename TypeSet::precision_type;
    using size_type                 = typename TypeSet::size_type;

    using Linear                    = typename TypeSet::Linear;

    template <typename T>
    using XContainer                = ContainerLocker<Container<T>>;

    using XVector                   = VectorLocker<Vector>;
    using XMatrix                   = MatrixLocker<Matrix>;

    using InnerBuffer               = XContainer<XVector>;
    using InnerTopology             = Container<size_type>;

    using Layer                     = layer::ITrainLayer<Ex>;

private:
    Container<Layer*> layer_;
    Vector delta;

    Container<Vector> deltaB;
    Container<Matrix> deltaW;

    Linear linear;

    size_type size;

public:
    Ex() : size(0) {}
    ~Ex()
    {
        for (size_type i = 0; i < size; ++i)
            delete layer_[i];
    }

    void add(Layer* layer)
    {
        layer_.emplace_back(layer);

        deltaB.emplace_back(layer->in());
        deltaW.emplace_back(layer->in(), layer->out());

        delta.resize(layer->out());

        ++size;
    }

    Layer& layer(size_type i) { return *layer_[i]; }

    const Vector& operator() (const Vector& sample) noexcept
    { return feedforward(sample); }

    const Vector& feedforward(const Vector& sample) noexcept
    {
        layer(0).forward(sample);

        for (size_type i = 1; i < size; ++i)
            layer(i).forward(layer(i - 1).value());

        return layer(size - 1).value();
    }

    template <class FloatGenerator,
          meta::require<meta::is_callable<FloatGenerator>::value> = 0>
    void init(FloatGenerator gen) noexcept
    {
        for (size_type i = 0; i < size; ++i)
        {
            layer(i).B().fill(gen);
            layer(i).W().fill(gen);
        }
    }
    template <class Bias, class Weight>
    void init(const Container<Bias>& bias, const Container<Weight>& weight) noexcept
    {
        for (size_type i = 0; i < size; ++i)
        {
            linear.assign(layer(i).B(), bias[i]);
            linear.assign(layer(i).W(), weight[i]);
        }
    }
private:
    void backprop(const Vector& sample, const Vector& target) noexcept
    {
        trixy::functional::loss::CCE::df(delta, target, layer(size - 1).value());

        layer(size - 1).backward(layer(size - 2).value(), delta);

        for (int i = size - 2; i > 0; --i)
            layer(i).backward(layer(i - 1).value(), layer(i + 1).delta().base());

        layer(0).backward0(sample, layer(1).delta().base());
    }
public:
    //
    void train(
        const Container<Vector>& idata,
        const Container<Vector>& odata,
        size_type number_of_epochs,
        precision_type learning_rate)
    {
        precision_type alpha = 1. / static_cast<precision_type>(idata.size());

        for (size_type epoch = 0, sample; epoch < number_of_epochs; ++epoch)
        {
            resetDelta();

            for (sample = 0; sample < idata.size(); ++sample)
            {
                feedforward(idata[sample]);
                backprop(idata[sample], odata[sample]);
                updateDelta();
            }
            // averaging deltas for one full-batch
            normalizeDelta(alpha);
            // B = B - learning_rate * gradB
            for (size_type i = 0; i < size; ++i)
            {
                linear.join(deltaB[i], learning_rate);
                linear.sub(layer(i).B(), deltaB[i]);

                linear.join(deltaW[i], learning_rate);
                linear.sub(layer(i).W(), deltaW[i]);
            }
            //optimizer.update(backprop_.deltaB.base(), backprop_.deltaW.base());
        }
    }
    //
    //
private:
    void resetDelta() noexcept
    {
        for (size_type i = 0; i < size; ++i)
        {
            deltaB[i].fill(0.0);
            deltaW[i].fill(0.0);
        }
    }

    void updateDelta() noexcept
    {
        for (size_type i = 0; i < size; ++i)
        {
            linear.add(deltaB[i], layer(i).gradB());
            linear.add(deltaW[i], layer(i).gradW());
        }
    }

    void normalizeDelta(
        precision_type alpha) noexcept
    {
        for (size_type i = 0; i < size; ++i)
        {
            deltaB[i].join(alpha);
            deltaW[i].join(alpha);
        }
    }
    //
};

} // namespace trixy

#endif // TRIXY_NETWORK_EXPERIMENTAL_NET_HPP
