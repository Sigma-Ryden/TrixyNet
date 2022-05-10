#ifndef TRIXY_TRAINING_POLYNOMIAL_REGRESSION_HPP
#define TRIXY_TRAINING_POLYNOMIAL_REGRESSION_HPP

#include <Trixy/Neuro/Training/Base.hpp>
#include <Trixy/Neuro/Detail/TrixyNetMeta.hpp>

#include <Trixy/Neuro/Detail/MacroScope.hpp>

namespace trixy
{

namespace train
{

TRIXY_TRAINING_TPL_DECLARATION
class TRIXY_TRAINING_TPL(meta::is_polynomial_regression)
{
public:
    using Vector          = typename Trainable::Vector;
    using Matrix          = typename Trainable::Matrix;

    using precision_type  = typename Trainable::precision_type;
    using size_type       = typename Trainable::size_type;

private:
    Trainable& reg;

public:
    explicit Training(Trainable& regression) : reg(regression) {}

    void train(const Vector& idata,
               const Vector& odata);

    long double loss(const Vector& idata,
                     const Vector& odata) const;
};

TRIXY_TRAINING_TPL_DECLARATION
void TRIXY_TRAINING_TPL(meta::is_polynomial_regression)::train(
    const Vector& idata,
    const Vector& odata)
{
    Matrix X(idata.size(), reg.N);

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

    Matrix X_T = reg.linear.transpose(X);
    Matrix X_T_X = reg.linear.dot(X_T, X);

    // W = (X^T . X)^(-1) . X^T . Y
    reg.linear.dot(
        reg.W,
        // (X^T . X)^(-1) . X^T
        reg.linear.dot(reg.linear.inverse(X_T_X), X_T),
        odata
    );
}

TRIXY_TRAINING_TPL_DECLARATION
long double TRIXY_TRAINING_TPL(meta::is_polynomial_regression)::loss(
    const Vector& idata,
    const Vector& odata) const
{
    return reg.loss(idata, odata);
}

} // namespace train

} // namespace trixy

#include <Trixy/Neuro/Detail/MacroUnscope.hpp>

#endif // TRIXY_TRAINING_POLYNOMIAL_REGRESSION_HPP
