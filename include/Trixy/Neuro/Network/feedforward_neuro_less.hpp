#ifndef FEEDFORWARD_NEURO_LESS_HPP
#define FEEDFORWARD_NEURO_LESS_HPP

#include <cstddef> // size_t
#include <cstdint> // uint8_t

namespace trixy
{

template <template <typename, typename...> class Vector,
          template <typename, typename...> class Matrix,
          template <template <typename, typename...> class V,
                    template <typename, typename...> class M,
                    typename P, typename...>
          class Linear,
          template <typename Type> class Container,
          typename Precision,
          typename... Args>
class FeedForwardNeuroLess;

} // namespace trixy

#define TRIXY_FEED_FORWARD_NEURO_LESS_TPL_DECLARATION              \
    template <template <typename, typename...> class Vector,       \
              template <typename, typename...> class Matrix,       \
              template <template <typename, typename...> class T1, \
                        template <typename, typename...> class T2, \
                        typename P, typename...>                   \
              class Linear,                                        \
              template <typename Type> class Container,            \
              typename Precision,                                  \
              typename... Args>

#define TRIXY_FEED_FORWARD_NEURO_LESS_TPL                          \
    FeedForwardNeuroLess<Vector, Matrix, Linear, Container,        \
                     Precision, Args...>

namespace trixy
{

TRIXY_FEED_FORWARD_NEURO_LESS_TPL_DECLARATION
class FeedForwardNeuroLess
{
public:
    struct ActivationFunction;
    struct LossFunction;

private:
    class  InnerFunctional;

public:
    using TensorOperation      = Linear<Vector, Matrix, Precision, Args...>;
    using Tensor1D             = Vector<Precision, Args...>;
    using Tensor2D             = Matrix<Precision, Args...>;
    using size_type            = std::size_t;

private:
    Container<Tensor1D>  buff;  ///< 1D buffer for handle
    Container<Tensor1D>  B;     ///< Container of network bias
    Container<Tensor2D>  W;     ///< Container of network weight
    size_type N;                ///< Number of functional layer (same as topology_size - 1)

public:
    InnerFunctional function;   ///< Functional object for set & get each inner network function

private:
    TensorOperation li;         ///< li - linear (class for linear calculate)

public:
    FeedForwardNeuroLess(const Container<Tensor1D>& bias,
                         const Container<Tensor2D>& weight);

    const Tensor1D& feedforward(const Tensor1D& sample) const noexcept;
};

TRIXY_FEED_FORWARD_NEURO_LESS_TPL_DECLARATION
struct TRIXY_FEED_FORWARD_NEURO_LESS_TPL::ActivationFunction
{
public:
    using Tensor    = Vector<Precision, Args...>;
    using byte_type = std::uint8_t;

    using Function        = void (*)(Tensor&, const Tensor&);
    using FunctionDerived = void (*)(Tensor&, const Tensor&);

public:
    Function f;             ///< void (*f)(Tensor& buff, const Tensor& tensor)
    FunctionDerived df;     ///< void (*df)(Tensor& buff, const Tensor& tensor)

    byte_type id;

public:
    ActivationFunction() noexcept : id(0), f(nullptr), df(nullptr) {}

    ActivationFunction(Function function,
                       FunctionDerived function_derived,
                       byte_type function_id = 0) noexcept
    : f(function)
    , df(function_derived)
    , id(function_id) {}
};

TRIXY_FEED_FORWARD_NEURO_LESS_TPL_DECLARATION
class TRIXY_FEED_FORWARD_NEURO_LESS_TPL::InnerFunctional
{
friend class TRIXY_FEED_FORWARD_NEURO_TPL;

private:
    ~InnerFunctional() = default;

private:
    Container<ActivationFunction> activation;

public:
    explicit InnerFunctional(size_type N) : activation(N) {}
    InnerFunctional& operator= (const InnerFunctional&) = delete;

    void setEachActivation(const Container<ActivationFunction>&); // maybe unused
    void setActivation(const ActivationFunction&);
    void setNormalization(const ActivationFunction&);
};

TRIXY_FEED_FORWARD_NEURO_LESS_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_LESS_TPL::InnerFunctional::setEachActivation(
    const Container<TRIXY_FEED_FORWARD_NEURO_LESS_TPL::ActivationFunction>& fs)
{
    for(size_type i = 0; i < activation.size(); ++i)
        activation[i] = fs[i];
}

TRIXY_FEED_FORWARD_NEURO_LESS_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_LESS_TPL::InnerFunctional::setActivation(
    const TRIXY_FEED_FORWARD_NEURO_LESS_TPL::ActivationFunction& f)
{
    for(size_type i = 0; i < activation.size() - 1; ++i)
        activation[i] = f;
}

TRIXY_FEED_FORWARD_NEURO_LESS_TPL_DECLARATION
void TRIXY_FEED_FORWARD_NEURO_LESS_TPL::InnerFunctional::setNormalization(
    const TRIXY_FEED_FORWARD_NEURO_LESS_TPL::ActivationFunction& f)
{
    activation[activation.size() - 1] = f;
}

TRIXY_FEED_FORWARD_NEURO_LESS_TPL_DECLARATION
TRIXY_FEED_FORWARD_NEURO_LESS_TPL::FeedForwardNeuroLess(
    const Container<Tensor1D>& bias,
    const Container<Tensor2D>& weight)
    : buff(bias.size())
    , B(bias.size())
    , W(weight.size())
    , N(bias.size())
{
    for(size_type i = 0; i < N; ++i)
    {
        B[i] = bias[i];
        W[i] = weight[i];
    }
}

TRIXY_FEED_FORWARD_NEURO_LESS_TPL_DECLARATION
const Vector<Precision, Args...>& TRIXY_FEED_FORWARD_NEURO_LESS_TPL::feedforward(
    const Vector<Precision, Args...>& sample) const noexcept
{
    li.dot(buff[0], sample, W[0]);
    function.activation[0].f(buff[0], buff[0].add(B[0]));

    for(size_type i = 1; i < N; ++i)
    {
        li.dot(buff[i], buff[i - 1], W[i]);
        function.activation[i].f(buff[i], buff[i].add(B[i]));
    }

    return buff[N - 1];
}

} // namespace trixy

// clean up
#undef TRIXY_FEED_FORWARD_NEURO_LESS_TPL_DECLARATION
#undef TRIXY_FEED_FORWARD_NEURO_LESS_TPL

#endif // FEEDFORWARD_NEURO_LESS_HPP
