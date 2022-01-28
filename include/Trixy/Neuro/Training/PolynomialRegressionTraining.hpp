#ifndef POLYNOMIAL_REGRESSION_TRAINING_HPP
#define POLYNOMIAL_REGRESSION_TRAINING_HPP

#include "BaseTraining.hpp"
#include "Trixy/Neuro/Detail/TrixyNetMeta.hpp"

#include "Trixy/Neuro/Detail/MacroScope.hpp"

namespace trixy
{

namespace train
{

TRIXY_TRAINING_TPL_DECLARATION
class TRIXY_TRAINING_TPL(meta::is_polynomial_regression)
{
public:
    using Tensor1D        = typename Trainable::Tensor1D;
    using Tensor2D        = typename Trainable::Tensor2D;

    using TensorOperation = typename Trainable::TensorOperation;

    using precision_type  = typename Trainable::precision_type;
    using size_type       = typename Trainable::size_type;

private:
    Trainable& reg;

public:
    explicit Training(Trainable& regression) : reg(regression) {}

    void train(const Tensor1D& idata,
               const Tensor1D& odata);

    long double loss(const Tensor1D& idata,
                     const Tensor1D& odata) const;
};

TRIXY_TRAINING_TPL_DECLARATION
void TRIXY_TRAINING_TPL(meta::is_polynomial_regression)::train(
    const Tensor1D& idata,
    const Tensor1D& odata)
{
    Tensor2D X(idata.size(), reg.N);

    precision_type sample;
    precision_type power;

    for(size_type i = 0; i < idata.size(); ++i)
    {
        sample = idata(i);
        power  = 1.;

        for(size_type j = 0; j < reg.N; ++j)
        {
            X(i, j) = power;
            power  *= sample;
        }
    }

    Tensor2D X_T = X.transpose();

    // W = (X^T . X)^(-1) . X^T . Y

    reg.linear.dot(reg.W, X_T.dot(X).inverse().dot(X_T), odata);
}

TRIXY_TRAINING_TPL_DECLARATION
long double TRIXY_TRAINING_TPL(meta::is_polynomial_regression)::loss(
    const Tensor1D& idata,
    const Tensor1D& odata) const
{
    return reg.loss(idata, odata);
}

} // namespace train

} // namespace trixy

#endif // POLYNOMIAL_REGRESSION_TRAINING_HPP
