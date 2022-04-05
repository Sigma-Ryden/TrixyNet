#ifndef TRIXY_TRAINING_LINEAR_REGRESSION_HPP
#define TRIXY_TRAINING_LINEAR_REGRESSION_HPP

#include <Trixy/Neuro/Training/Base.hpp>
#include <Trixy/Neuro/Detail/TrixyNetMeta.hpp>

#include <Trixy/Neuro/Detail/MacroScope.hpp>

namespace trixy
{

namespace train
{

TRIXY_TRAINING_TPL_DECLARATION
class TRIXY_TRAINING_TPL(meta::is_linear_regression)
{
public:
    using Vector          = typename Trainable::Vector;
    using Matrix          = typename Trainable::Matrix;

    using TensorOperation = typename Trainable::TensorOperation;

    using precision_type  = typename Trainable::precision_type;
    using size_type       = typename Trainable::size_type;

private:
    Trainable& reg;

public:
    explicit Training(Trainable& regression) : reg(regression) {}

    void train(const Matrix& idata,
               const Vector& odata);

    long double loss(const Matrix& idata,
                     const Vector& odata) const;
};

TRIXY_TRAINING_TPL_DECLARATION
void TRIXY_TRAINING_TPL(meta::is_linear_regression)::train(
    const Matrix& idata,
    const Vector& odata)
{
    Matrix X(idata.shape().row(), reg.N);

    for(size_type i = 0; i < X.shape().row(); ++i)
    {
        X(i, 0) = 1.;
        for(size_type j = 1; j < reg.N; ++j)
            X(i, j) = idata(i, j - 1);
    }

    Matrix X_T = const_cast<const Matrix&>(X).transpose();

    // W = (X^T . X)^(-1) . X^T . Y

    reg.linear.dot(reg.W, X_T.dot(X).inverse().dot(X_T), odata);
}

TRIXY_TRAINING_TPL_DECLARATION
long double TRIXY_TRAINING_TPL(meta::is_linear_regression)::loss(
    const Matrix& idata,
    const Vector& odata) const
{
    return reg.loss(idata, odata);
}

} // namespace train

} // namespace trixy

#include <Trixy/Neuro/Detail/MacroUnscope.hpp>

#endif // TRIXY_TRAINING_LINEAR_REGRESSION_HPP
