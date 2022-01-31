#ifndef FEED_FORWARD_NET_FUNCTIONAL_HPP
#define FEED_FORWARD_NET_FUNCTIONAL_HPP

#include <utility> // forward

#include "Trixy/Neuro/Functional/BaseFunctional.hpp"
#include "Trixy/Neuro/Functional/IdFunctional.hpp"

#include "Trixy/Neuro/Functional/Function/FunctionCore.hpp"
#include "Trixy/Neuro/Functional/Optimizer/OptimizerCore.hpp"

#include "Trixy/Neuro/Detail/TrixyNetMeta.hpp"

#include "Trixy/Neuro/Detail/MacroScope.hpp"

namespace trixy
{

TRIXY_FUNCTIONAL_TPL_DECLARATION
class TRIXY_FUNCTIONAL_TPL(meta::is_feedforward_net)
{
private:
    template <typename T>
    using Container            = typename Functionable::template Container<T>;

    using size_type            = typename Functionable::size_type;
    using byte_type            = typename Functionable::byte_type;

    using ActivationFunction   = typename Functionable::ActivationFunction;
    using LossFunction         = typename Functionable::LossFunction;

    template <class optimizer_type>
    using OptimizationFunction = typename train::Optimizer<Functionable, optimizer_type>;

    template <functional::OptimizationId id>
    using optimizer_type_from  = functional::OptimizerType::type_from<id>;

public:
    ActivationFunction get(functional::ActivationId id) const noexcept
    {
        return set::activation::get_activation_function<ActivationFunction, byte_type>(id);
    }

    Container<ActivationFunction> get(const Container<functional::ActivationId>& all_id) const noexcept
    {
        Container<ActivationFunction> all_activation(all_id.size());
        for(size_type i = 0; i < all_id.size(); ++i)
            all_activation[i] = get(all_id[i]);

        return all_activation;
    }

    LossFunction get(functional::LossId id) const noexcept
    {
        return set::loss::get_loss_function<LossFunction, byte_type>(id);
    }

    template <functional::ActivationId id>
    ActivationFunction get() const noexcept
    {
        return get(id);
    }

    template <functional::LossId id>
    LossFunction get() const noexcept
    {
        return get(id);
    }

    template <functional::OptimizationId id, typename... Args>
    OptimizationFunction<optimizer_type_from<id>> get(Args&&... args) const
    {
        return OptimizationFunction<optimizer_type_from<id>>(std::forward<Args>(args)...);
    }
};

} // namespace trixy

#include "Trixy/Neuro/Detail/MacroUnscope.hpp"

#endif // FEED_FORWARD_NET_FUNCTIONAL_HPP
