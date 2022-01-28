#ifndef LINEAR_REGRESSION_TRAINING_HPP
#define LINEAR_REGRESSION_TRAINING_HPP

#include "BaseTraining.hpp"
#include "Trixy/Neuro/Detail/TrixyNetMeta.hpp"

#include "Trixy/Neuro/Detail/MacroScope.hpp"

namespace trixy
{

namespace train
{

TRIXY_TRAINING_TPL_DECLARATION
class TRIXY_TRAINING_TPL(meta::is_linear_regression)
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

    void train(const Tensor2D& idata,
               const Tensor1D& odata);

    long double loss(const Tensor2D& idata,
                     const Tensor1D& odata) const;
};


TRIXY_TRAINING_TPL_DECLARATION
void TRIXY_TRAINING_TPL(meta::is_linear_regression)::train(
    const Tensor2D& idata,
    const Tensor1D& odata)
{
    Tensor2D X(idata.shape().row(), reg.N);

    for(size_type i = 0; i < X.shape().row(); ++i)
    {
        X(i, 0) = 1.;
        for(size_type j = 1; j < reg.N; ++j)
            X(i, j) = idata(i, j - 1);
    }

    Tensor2D X_T = X.transpose();

    // W = (X^T . X)^(-1) . X^T . Y

    reg.linear.dot(reg.W, X_T.dot(X).inverse().dot(X_T), odata);
}

TRIXY_TRAINING_TPL_DECLARATION
long double TRIXY_TRAINING_TPL(meta::is_linear_regression)::loss(
    const Tensor2D& idata,
    const Tensor1D& odata) const
{
    return reg.loss(idata, odata);
}

} // namespace train

} // namespace trixy

#endif // LINEAR_REGRESSION_TRAINING_HPP
