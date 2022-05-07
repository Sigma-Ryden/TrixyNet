#ifndef TRIXY_NEURO_CHECKER_ACCURACY_HPP
#define TRIXY_NEURO_CHECKER_ACCURACY_HPP

#include <cmath> // fabs

#include <Trixy/Neuro/Checker/Detail/MacroScope.hpp>

namespace trixy
{

template <class Checkable>
class Accuracy
{
public:
    class Guide;

public:
    using Net = Checkable;

    using precision_type        = typename Net::precision_type;
    using size_type             = typename Net::size_type;

private:
    Net& net;

public:
    explicit Accuracy(Net& network) : net(network) {}

    // operator= for copy and move Accuracy object will not implicit generate
    Accuracy(const Accuracy&) = default;
    Accuracy(Accuracy&&) noexcept = default;

    TRIXY_ACCURACY_TPL_DECLARATION
    long double normal(const Container<Sample>& idata,
                       const Container<Target>& odata) noexcept;

    TRIXY_ACCURACY_TPL_DECLARATION
    long double full(const Container<Sample>& idata,
                     const Container<Target>& odata,
                     precision_type range_rate) noexcept;

    TRIXY_ACCURACY_TPL_DECLARATION
    long double global(const Container<Sample>& idata,
                       const Container<Target>& odata,
                       precision_type range_rate) noexcept;

    TRIXY_ACCURACY_TPL_DECLARATION
    long double operator() (const Container<Sample>& idata,
                            const Container<Target>& odata) noexcept
    { return normal(idata, odata); }
};

template <class Checkable>
class Accuracy<Checkable>::Guide
{
public:
    TRIXY_ACCURACY_GUIDE_TPL_DECLARATION
    static bool normal(const Target& target,
                       const Prediction& prediction) noexcept;

    TRIXY_ACCURACY_GUIDE_TPL_DECLARATION
    static bool full(const Target& target,
                     const Prediction& prediction,
                     precision_type range_rate) noexcept;

    TRIXY_ACCURACY_GUIDE_TPL_DECLARATION
    static size_type global(const Target& target,
                            const Prediction& prediction,
                            precision_type range_rate) noexcept;

    TRIXY_ACCURACY_GUIDE_TPL_DECLARATION
    bool operator() (const Target& target,
                     const Prediction& prediction) const noexcept
    { return normal(target, prediction); }
};

template <class Checkable>
TRIXY_ACCURACY_TPL_DECLARATION
long double Accuracy<Checkable>::normal(
    const Container<Sample>& idata,
    const Container<Target>& odata) noexcept
{
    size_type count = 0;

    for(size_type i = 0; i < odata.size(); ++i)
        if(Guide::normal(odata[i], net.feedforward(idata[i])))
            ++count;

    return static_cast<long double>(count) / odata.size();
}

template <class Checkable>
TRIXY_ACCURACY_TPL_DECLARATION
long double Accuracy<Checkable>::full(
    const Container<Sample>& idata,
    const Container<Target>& odata,
    precision_type range_rate) noexcept
{
    size_type count = 0;

    for(size_type i = 0; i < odata.size(); ++i)
        if(Guide::full(odata[i], net.feedforward(idata[i]), range_rate))
            ++count;

    return static_cast<long double>(count) / odata.size();
}

template <class Checkable>
TRIXY_ACCURACY_TPL_DECLARATION
long double Accuracy<Checkable>::global(
    const Container<Sample>& idata,
    const Container<Target>& odata,
    precision_type range_rate) noexcept
{
    size_type count = 0;

    for(size_type i = 0; i < odata.size(); ++i)
        count += Guide::global(odata[i], net.feedforward(idata[i]), range_rate);

    return static_cast<long double>(count) / (odata.size() * odata.front().size());
}

template <class Checkable>
TRIXY_ACCURACY_GUIDE_TPL_DECLARATION
bool Accuracy<Checkable>::Guide::normal(
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
TRIXY_ACCURACY_GUIDE_TPL_DECLARATION
bool Accuracy<Checkable>::Accuracy::Guide::full(
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
TRIXY_ACCURACY_GUIDE_TPL_DECLARATION
typename Accuracy<Checkable>::size_type Accuracy<Checkable>::Guide::global(
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

} // namespace trixy

#include <Trixy/Neuro/Checker/Detail/MacroUnscope.hpp>

#endif // TRIXY_NEURO_CHECKER_ACCURACY_HPP
