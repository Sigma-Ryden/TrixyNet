#ifndef LINEAR_REGRESSION_HPP
#define LINEAR_REGRESSION_HPP

#include <cstddef> // size_t

#include "Trixy/Neuro/Regression/BaseRegression.hpp"
#include "Trixy/Neuro/Detail/TrixyNetMeta.hpp"

#include "Trixy/Neuro/Detail/MacroScope.hpp"

namespace trixy
{

TRIXY_REGRESSION_TPL_DECLARATION
class TRIXY_LINEAR_REGRESSION_TPL
{
friend train::Training<TRIXY_LINEAR_REGRESSION_TPL>;

public:
    using Tensor1D        = Vector<Precision, Args...>;
    using Tensor2D        = Matrix<Precision, Args...>;

    using TensorOperation = Linear<Vector, Matrix, Precision, Args...>;

    using precision_type  = Precision;
    using size_type       = std::size_t;

private:
    Tensor1D  W;          ///< Inner weight
    size_type N;          ///< Size of weight vector (same as sample size + 1)

    TensorOperation linear;

public:
    explicit LinearRegression(size_type sample_size);

    void initializeInnerStruct(Tensor1D weight) noexcept;

    void reset(size_type new_sample_size);

    Precision feedforwardSample(const Tensor1D& sample) const;
    Tensor1D feedforwardBatch(const Tensor2D& idata) const;

    long double loss(const Tensor2D& idata,
                     const Tensor1D& odata) const;

    const Tensor1D& getInnerWeight() const noexcept;
    size_type getInnerSize() const noexcept;
};

TRIXY_REGRESSION_TPL_DECLARATION
TRIXY_LINEAR_REGRESSION_TPL::LinearRegression(size_type sample_size)
    : W(sample_size + 1), N(sample_size + 1)
{
}

TRIXY_REGRESSION_TPL_DECLARATION
void TRIXY_LINEAR_REGRESSION_TPL::initializeInnerStruct(Tensor1D weight) noexcept
{
    W.copy(weight);
}

TRIXY_REGRESSION_TPL_DECLARATION
void TRIXY_LINEAR_REGRESSION_TPL::reset(size_type new_sample_size)
{
    W.resize(new_sample_size + 1);
    N = new_sample_size + 1;
}

TRIXY_REGRESSION_TPL_DECLARATION
Precision TRIXY_LINEAR_REGRESSION_TPL::feedforwardSample(
    const Vector<Precision, Args...>& sample) const
{
    Precision result = W(0);

    for(size_type i = 1; i < N; ++i)
    {
        result += sample(i - 1) * W(i);
    }

    return result;
}

TRIXY_REGRESSION_TPL_DECLARATION
Vector<Precision, Args...> TRIXY_LINEAR_REGRESSION_TPL::feedforwardBatch(
    const Matrix<Precision, Args...>& idata) const
{
    Tensor2D X(idata.shape().row(), N);

    for(size_type i = 0; i < X.shape().row(); ++i)
    {
        X(i, 0) = 1.;
        for(size_type j = 1; j < N; ++j)
            X(i, j) = idata(i, j - 1);
    }

    return linear.dot(X, W);
}

TRIXY_REGRESSION_TPL_DECLARATION
long double TRIXY_LINEAR_REGRESSION_TPL::loss(
    const Matrix<Precision, Args...>& idata,
    const Vector<Precision, Args...>& odata) const
{
    Tensor1D r = feedforwardBatch(idata);
    r.sub(odata);

    return r.dot(r) / static_cast<long double>(r.size());
}

TRIXY_REGRESSION_TPL_DECLARATION
inline const Vector<Precision, Args...>& TRIXY_LINEAR_REGRESSION_TPL::getInnerWeight() const noexcept
{
    return W;
}

TRIXY_REGRESSION_TPL_DECLARATION
inline std::size_t TRIXY_LINEAR_REGRESSION_TPL::getInnerSize() const noexcept
{
    return N - 1;
}

} // namespace trixy

#include "Trixy/Neuro/Detail/MacroUnscope.hpp"

#endif // LINEAR_REGRESSION_HPP
