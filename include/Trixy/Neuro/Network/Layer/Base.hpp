#ifndef TRIXY_NETWORK_LAYER_BASE_HPP
#define TRIXY_NETWORK_LAYER_BASE_HPP

#include <functional> // function

#include <Trixy/Base.hpp> // LayerType, LayerMode

#include <Trixy/Serializer/Core.hpp>

#include <Trixy/Neuro/Functional/Function/Base.hpp>
#include <Trixy/Neuro/Functional/Optimizer/Base.hpp>

#include <Trixy/Detail/MacroScope.hpp>

namespace trixy
{

namespace layer
{

template <typename LayerType, class Net, typename LayerMode>
class Layer;

template <class Net>
class ILayer : public sf::Instantiable
{
    SERIALIZABLE(ILayer)

public:
    template <typename T>
    using Container             = typename Net::template Container<T>;

    using Vector                = typename Net::Vector;
    using Matrix                = typename Net::Matrix;
    using Tensor                = typename Net::Tensor;

    using XVector               = typename Net::XVector;
    using XMatrix               = typename Net::XMatrix;
    using XTensor               = typename Net::XTensor;

    using size_type             = typename Net::size_type;
    using precision_type        = typename Net::precision_type;
    using shape_type            = typename Net::Tensor::shape_type;

    using Linear                = typename Net::Linear;

    using Generator             = std::function<precision_type()>; // type erasing
    using IActivation           = functional::activation::IActivation<precision_type>;

public:
    virtual ~ILayer() = default;

    virtual void init(Generator& generator) noexcept { /*pass*/ }
    virtual void connect(IActivation* activation) = 0;

    virtual void forward(const Tensor& input) noexcept = 0;
    virtual const Tensor& value() const noexcept = 0;

    virtual const shape_type& isize() const noexcept = 0;
    virtual const shape_type& osize() const noexcept = 0;
};

template <class Net>
class ITrainLayer : public ILayer<Net>
{
    SERIALIZABLE(ITrainLayer)

    using Base = ILayer<Net>;

public:
    template <typename T>
    using Container = typename Base::template Container<T>;

    using typename Base::Vector;
    using typename Base::Matrix;
    using typename Base::Tensor;

    using typename Base::XVector;
    using typename Base::XMatrix;
    using typename Base::XTensor;

    using typename Base::size_type;
    using typename Base::precision_type;
    using typename Base::shape_type;

    using typename Base::Linear;

    using typename Base::Generator;
    using typename Base::IActivation;

    using IOptimizer = train::IOptimizer<Net>;

public:
    virtual ~ITrainLayer() = default;

public:
    virtual void backward(const Tensor& input, const Tensor& idelta, bool full = true) noexcept = 0;
    virtual const Tensor& delta() const noexcept = 0;

    virtual void update(IOptimizer& optimizer, precision_type alpha) noexcept { /*pass*/ }

    virtual void accumulate() noexcept { /*pass*/ }
    virtual void reset() noexcept { /*pass*/ }
};

} // namespace layer

namespace meta
{

template <typename T> struct is_ilayer : std::false_type {};
template <class Net> struct is_ilayer<layer::ILayer<Net>> : std::true_type {};

template <typename T> struct is_itrain_layer : std::false_type {};
template <class Net> struct is_itrain_layer<layer::ITrainLayer<Net>> : std::true_type {};

} // namespace meta

} // namespace trixy

CONDITIONAL_SERIALIZATION(SaveLoad, trixy::meta::is_ilayer<T>::value) {}
CONDITIONAL_SERIALIZATION(SaveLoad, trixy::meta::is_itrain_layer<T>::value) {}

#endif // TRIXY_NETWORK_LAYER_BASE_HPP
