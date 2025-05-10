#ifndef TRIXY_NEURO_CHECKER_HPP
#define TRIXY_NEURO_CHECKER_HPP

#include <Trixy/Neuro/Checker/Accuracy.hpp>

namespace trixy
{

template <class Checkable>
class Checker
{
public:
    using Net = Checkable;

    using precision_type        = typename Net::precision_type;
    using size_type             = typename Net::size_type;

private:
    using Accuracy              = Accuracy<Net>;
    using Guide                 = typename Accuracy::Guide;

private:
    Checkable& net;

public:
    Accuracy accuracy;
    Guide guide;

public:
    explicit Checker(Net& network)
    : net(network), accuracy(network), guide() {}

    // operator= for copy and move Checker object will not implicit generate
    Checker(const Checker&) = default;
    Checker(Checker&&) noexcept = default;

    template <template <typename, typename...> class Container,
              class Sample, class Target, class LossFunction>
    double loss(const Container<Sample>& idata,
                     const Container<Target>& odata,
                     LossFunction loss_function) noexcept
    {
        precision_type result = 0.;
        precision_type error  = 0.;

        for (size_type i = 0; i < odata.size(); ++i)
        {
            loss_function(error, odata[i], net.feedforward(idata[i]));
            result += error;
        }

        return result / static_cast<double>(odata.size());
    }

    template <class Sample, class Target, class LossFunction>
    double loss(const Sample& sample,
                     const Target& target,
                     LossFunction loss_function) noexcept
    {
        precision_type error = 0.;

        loss_function(error, target, net.feedforward(sample));

        return error;
    }
};

} // namespace trixy

#endif // TRIXY_NEURO_CHECKER_HPP
