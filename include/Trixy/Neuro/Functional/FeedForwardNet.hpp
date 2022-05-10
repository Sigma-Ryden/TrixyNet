#ifndef TRIXY_FUNCTIONAL_FEED_FORWARD_NET_HPP
#define TRIXY_FUNCTIONAL_FEED_FORWARD_NET_HPP

#include <utility> // forward

#include <Trixy/Neuro/Functional/Base.hpp>
#include <Trixy/Neuro/Functional/Optimizer/Base.hpp>

#include <Trixy/Neuro/Functional/Function/Core.hpp>
#include <Trixy/Neuro/Functional/Id.hpp>

#include <Trixy/Neuro/Detail/TrixyNetMeta.hpp>

#include <Trixy/Neuro/Detail/MacroScope.hpp>

namespace trixy
{

TRIXY_FUNCTIONAL_TPL_DECLARATION
class TRIXY_FUNCTIONAL_TPL(meta::is_feedforward_net)
{
public:
    template <typename T>
    using Container                 = typename Functionable::template Container<T>;

    using size_type                 = typename Functionable::size_type;

    using ActivationId              = typename Functionable::ActivationId;
    using LossId                    = typename Functionable::LossId;

    using ActivationFunction        = typename Functionable::ActivationFunction;
    using LossFunction              = typename Functionable::LossFunction;

    template <class optimizer_type>
    using Optimizer = typename train::Optimizer<Functionable, optimizer_type>;

private:
    template <functional::OptimizationId id>
    using optimizer_type_from = train::OptimizerType::type_from<id>;

public:
    ActivationFunction get(ActivationId id) const noexcept
    {
        return functional::activation::get_activation_function<ActivationFunction, ActivationId>(id);
    }

    Container<ActivationFunction> get(const Container<ActivationId>& all_id) const noexcept
    {
        Container<ActivationFunction> all_activation(all_id.size());

        for(size_type i = 0; i < all_id.size(); ++i)
            all_activation[i] = get(all_id[i]);

        return all_activation;
    }

    LossFunction get(LossId id) const noexcept
    {
        return functional::loss::get_loss_function<LossFunction, LossId>(id);
    }

    template <ActivationId id> ActivationFunction get() const noexcept
    { return get(id); }

    template <LossId id> LossFunction get() const noexcept
    { return get(id); }

    template <functional::OptimizationId id, typename... Args>
    Optimizer<optimizer_type_from<id>> get(Args&&... args) const
    {
        return Optimizer<optimizer_type_from<id>>(std::forward<Args>(args)...);
    }
};

} // namespace trixy

#include <Trixy/Neuro/Detail/MacroUnscope.hpp>

#endif // TRIXY_FUNCTIONAL_FEED_FORWARD_NET_HPP
