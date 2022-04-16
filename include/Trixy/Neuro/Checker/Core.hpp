#ifndef TRIXY_NEURO_CHECKER_HPP
#define TRIXY_NEURO_CHECKER_HPP

#include <cmath> // fabs

#include <Trixy/Detail/TrixyMeta.hpp>
#include <Trixy/Neuro/Detail/TrixyNetMeta.hpp>

namespace trixy
{

template <class Checkable>
class Checker
{
public:
    class Accuracy;
    class Guide;

public:
    using size_type      = typename Checkable::size_type;
    using precision_type = typename Checkable::precision_type;

private:
    const Checkable& net;

public:
    Accuracy accuracy;
    Guide guide;

public:
    explicit Checker(const Checkable& network)
    : net(network), accuracy(network), guide() {}

    template <template <typename, typename...> class Container,
              class Sample, class Target, class LossFunction>
    long double loss(const Container<Sample>& idata,
                     const Container<Target>& odata,
                     LossFunction func) const noexcept;

    template <class Sample, class Target, class LossFunction>
    long double loss(const Sample& idata,
                     const Target& odata,
                     LossFunction func) const noexcept;
};

template <class Checkable>
class Checker<Checkable>::Accuracy
{
private:
    const Checkable& net;

public:
    explicit Accuracy(const Checkable& network) : net(network) {}

public:
    template <template <typename, typename...> class Container,
              class Sample, class Target>
    long double normal(const Container<Sample>& idata,
                       const Container<Target>& odata) const noexcept; // repair

    template <template <typename, typename...> class Container,
              class Sample, class Target>
    long double full(const Container<Sample>& idata,
                     const Container<Target>& odata,
                     precision_type range_rate) const noexcept; // repair

    template <template <typename, typename...> class Container,
              class Sample, class Target>
    long double global(const Container<Sample>& idata,
                       const Container<Target>& odata,
                       precision_type range_rate) const noexcept; // repair

    template <template <typename, typename...> class Container,
              class Sample, class Target>
    long double operator() (const Container<Sample>& idata,
                            const Container<Target>& odata) const noexcept
    { return normal(idata, odata); }
};

template <class Checkable>
class Checker<Checkable>::Guide
{
public:
    template <class Target, class Prediction>
    static bool normal(const Target& target,
                       const Prediction& prediction) noexcept;

    template <class Target, class Prediction>
    bool static full(const Target& target,
                     const Prediction& prediction,
                     precision_type range_rate) noexcept;

    template <class Target, class Prediction>
    static size_type global(const Target& target,
                            const Prediction& prediction,
                            precision_type range_rate) noexcept;

    template <class Target, class Prediction>
    bool operator() (const Target& target,
                     const Prediction& prediction) const noexcept
    { return normal(target, prediction); }
};

template <class Checkable>
template <template <typename, typename...> class Container,
          class Sample, class Target>
long double Checker<Checkable>::Accuracy::normal(
    const Container<Sample>& idata,
    const Container<Target>& odata) const noexcept
{
    size_type count = 0;

    for(size_type i = 0; i < odata.size(); ++i)
        if(Guide::normal(odata[i], net.feedforward(idata[i])))
            ++count;

    return static_cast<long double>(count) / odata.size();
}

template <class Checkable>
template <template <typename, typename...> class Container,
          class Sample, class Target>
long double Checker<Checkable>::Accuracy::full(
    const Container<Sample>& idata,
    const Container<Target>& odata,
    precision_type range_rate) const noexcept
{
    size_type count = 0;

    for(size_type i = 0; i < odata.size(); ++i)
        if(Guide::full(odata[i], net.feedforward(idata[i]), range_rate))
            ++count;

    return static_cast<long double>(count) / odata.size();
}

template <class Checkable>
template <template <typename, typename...> class Container,
          class Sample, class Target>
long double Checker<Checkable>::Accuracy::global(
    const Container<Sample>& idata,
    const Container<Target>& odata,
    precision_type range_rate) const noexcept
{
    size_type count = 0;

    for(size_type i = 0; i < odata.size(); ++i)
        count += Guide::global(odata[i], net.feedforward(idata[i]), range_rate);

    return static_cast<long double>(count) / (odata.size() * odata.front().size());
}

template <class Checkable>
template <class Target, class Prediction>
bool Checker<Checkable>::Guide::normal(
    const Target& target,
    const Prediction& prediction) noexcept
{
    size_type max_true_out;
    size_type max_pred_out;

    max_true_out = 0;
    max_pred_out = 0;

    for(size_type j = 1; j < target.size(); ++j)
        if(target(max_true_out) < target(j))
            max_true_out = j;

    for(size_type j = 1; j < target.size(); ++j)
        if(prediction(max_pred_out) < prediction(j))
            max_pred_out = j;

    return max_true_out == max_pred_out;
}

template <class Checkable>
template <class Target, class Prediction>
bool Checker<Checkable>::Guide::full(
    const Target& target,
    const Prediction& prediction,
    precision_type range_rate) noexcept
{
    for(size_type j = 0; j < target.size(); ++j)
        if(std::fabs(target(j) - prediction(j)) > range_rate)
            return false;

    return true;
}

template <class Checkable>
template <class Target, class Prediction>
typename Checker<Checkable>::size_type Checker<Checkable>::Guide::global(
    const Target& target,
    const Prediction& prediction,
    precision_type range_rate) noexcept
{
    size_type count = 0;
    for(size_type i = 0; i < target.size(); ++i)
        if(std::fabs(target(i) - prediction(i)) < range_rate)
            ++count;

    return count;
}

template <class Checkable>
template <template <typename, typename...> class Container,
          class Sample, class Target, class LossFunction>
long double Checker<Checkable>::loss(
    const Container<Sample>& idata,
    const Container<Target>& odata,
    LossFunction func) const noexcept
{
    precision_type result = 0.;
    precision_type error  = 0.;

    for(size_type i = 0; i < odata.size(); ++i)
    {
        func(error, odata[i], net.feedforward(idata[i]));
        result += error;
    }

    return result / static_cast<long double>(odata.size());
}

template <class Checkable>
template <class Sample, class Target, class LossFunction>
long double Checker<Checkable>::loss(
    const Sample& idata,
    const Target& odata,
    LossFunction func) const noexcept
{
    precision_type error = 0.;

    func(error, odata, net.feedforward(idata));

    return error;
}

} // namespace trixy

#endif // TRIXY_NEURO_CHECKER_HPP
