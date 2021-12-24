#ifndef LINEAR_REGRESSION_HPP
#define LINEAR_REGRESSION_HPP

#include <cstddef> // size_t
#include <type_traits> // enable_if, is_arithmetic

namespace trixy
{

template <template <typename P, typename...> class Vector,
          template <typename P, typename...> class Matrix,
          template <template <typename, typename...> class V,
                    template <typename, typename...> class M,
                    typename P, typename...>
          class Linear,
          typename Precision,
          typename enable = void,
          typename... Args>
class LinearRegression;

} // namespace trixy

#define TRIXY_LINEAR_REGRESSION_TPL_DECLARATION                                          \
    template <template <typename P, typename...> class Vector,                           \
              template <typename P, typename...> class Matrix,                           \
              template <template <typename, typename...> class V,                        \
                        template <typename, typename...> class M,                        \
                        typename P, typename...>                                         \
              class Linear,                                                              \
              typename Precision,                                                        \
              typename... Args>

#define TRIXY_LINEAR_REGRESSION_TPL                                                      \
    LinearRegression<Vector, Matrix, Linear, Precision,                                  \
           typename std::enable_if<std::is_arithmetic<Precision>::value>::type, Args...>

namespace trixy
{

TRIXY_LINEAR_REGRESSION_TPL_DECLARATION
class LinearRegression<Vector, Matrix, Linear, Precision,
    typename std::enable_if<std::is_arithmetic<Precision>::value>::type, Args...>
{
public:
    using Tensor1D        = Vector<Precision, Args...>;
    using Tensor2D        = Matrix<Precision, Args...>;

    using TensorOperation = Linear<Vector, Matrix, Precision, Args...>;

    using size_type       = std::size_t;

private:
    Tensor1D  W;            ///< Inner weight
    size_type N;            ///< Size of weight vector (same as sample size + 1)

    TensorOperation linear;

public:
    LinearRegression(size_type sample_size);

    void train(const Tensor2D& idata,
               const Tensor1D& odata);

    Precision feedforwardSample(const Tensor1D& idata) const;
    Tensor1D feedforwardBatch(const Tensor2D& idata) const;

    long double loss(const Tensor2D& idata,
                     const Tensor1D& odata) const;

    const Tensor1D& getInnerWeight() const noexcept;
    const size_type getInnerSize() const noexcept;
};

TRIXY_LINEAR_REGRESSION_TPL_DECLARATION
TRIXY_LINEAR_REGRESSION_TPL::LinearRegression(size_type sample_size)
    : W(sample_size + 1), N(sample_size + 1)
{
}

TRIXY_LINEAR_REGRESSION_TPL_DECLARATION
void TRIXY_LINEAR_REGRESSION_TPL::train(
    const Matrix<Precision, Args...>& idata,
    const Vector<Precision, Args...>& odata)
{
    Tensor2D X(idata.size().row(), N);

    for(size_type i = 0; i < X.size().row(); ++i)
    {
        X(i, 0) = 1.;
        for(size_type j = 1; j < N; ++j)
            X(i, j) = idata(i, j - 1);
    }

    Tensor2D X_T = X.transpose();

    // W = (X^T . X)^(-1) . X^T . Y

    linear.dot(W, X_T.dot(X).inverse().dot(X_T), odata);
}

TRIXY_LINEAR_REGRESSION_TPL_DECLARATION
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

TRIXY_LINEAR_REGRESSION_TPL_DECLARATION
Vector<Precision, Args...> TRIXY_LINEAR_REGRESSION_TPL::feedforwardBatch(
    const Matrix<Precision, Args...>& idata) const
{
    Tensor2D X(idata.size().row(), N);

    for(size_type i = 0; i < X.size().row(); ++i)
    {
        X(i, 0) = 1.;
        for(size_type j = 1; j < N; ++j)
            X(i, j) = idata(i, j - 1);
    }

    return linear.dot(X, W);
}

TRIXY_LINEAR_REGRESSION_TPL_DECLARATION
long double TRIXY_LINEAR_REGRESSION_TPL::loss(
    const Matrix<Precision, Args...>& idata,
    const Vector<Precision, Args...>& odata) const
{
    Tensor1D r = feedforwardBatch(idata) - odata;

    return r.dot(r) / static_cast<long double>(r.size());
}

TRIXY_LINEAR_REGRESSION_TPL_DECLARATION
inline const Vector<Precision, Args...>& TRIXY_LINEAR_REGRESSION_TPL::getInnerWeight() const noexcept
{
    return W;
}

TRIXY_LINEAR_REGRESSION_TPL_DECLARATION
inline const std::size_t TRIXY_LINEAR_REGRESSION_TPL::getInnerSize() const noexcept
{
    return N - 1;
}

} // namespace trixy

// clean up
#undef TRIXY_LINEAR_REGRESSION_TPL_DECLARATION
#undef TRIXY_LINEAR_REGRESSION_TPL

#endif // LINEAR_REGRESSION_HPP
