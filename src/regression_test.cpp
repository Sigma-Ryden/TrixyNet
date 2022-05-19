#include <Trixy/Core.hpp>
// TrixyNet, Functional, Optimizer, Training
// Serializer, Tensor, Linear, Container, Random

#include <Utility/utility.hpp> // operator<<

#include <fstream> // ifstream, ofstream
#include <iostream> // cin, cout
#include <iomanip> // setprecision, fixed

namespace tr = trixy;
namespace li = trixy::lique;

using namespace utility; // Core

using PolynomialReg = tr::PolynomialRegression<tr::TypeSet<double>>;
using LinearReg     = tr::LinearRegression<tr::TypeSet<float>>;

using PolynomialRegTraining = tr::train::Training<PolynomialReg>;
using LinearRegTraining     = tr::train::Training<LinearReg>;

template <class Reg, class Vector = typename Reg::Vector>
Vector get_sin_idata()
{
    using size_type      = typename Reg::size_type;
    using precision_type = typename Reg::precision_type;

    Vector x(61);

    precision_type arg = -3.;

    for (size_type i = 0; i < x.size(); ++i)
    {
        x(i) = arg;
        arg += .1;
    }

    return x;
}

template <class Reg, class Vector = typename Reg::Vector>
Vector get_sin_odata()
{
    using size_type      = typename Reg::size_type;
    using precision_type = typename Reg::precision_type;

    Vector y(61);

    precision_type arg = -3.;

    for (size_type i = 0; i < y.size(); ++i)
    {
        y(i) = std::sin(arg);
        arg += .1;
    }

    return y;
}

template <class Reg, class Matrix = typename Reg::Matrix>
Matrix get_linear_idata()
{
    using size_type      = typename Reg::size_type;
    using precision_type = typename Reg::precision_type;

    Matrix x(101, 1);

    precision_type arg = -1.;

    for (size_type i = 0; i < x.shape().height; ++i)
    {
        x(i, 0) = arg;
        arg    += .02;
    }

    return x;
}

template <class Reg, class Vector = typename Reg::Vector>
Vector get_linear_odata()
{
    using size_type      = typename Reg::size_type;
    using precision_type = typename Reg::precision_type;

    Vector y(101);

    precision_type arg = -1.;

    for (size_type i = 0; i < y.size(); ++i)
    {
        y(i) = arg * 8. + 2.;
        arg += .02;
    }

    return y;
}

void polynomial_regression_test_deserialization()
{
    std::ifstream in("D:\\Serialized\\polynomial_regression_test.bin", std::ios::binary);
    if (not in.is_open()) return;

    tr::Serializer<PolynomialReg> sr;
    sr.deserialize(in);
    in.close();

    PolynomialReg reg(sr.getPower());
    reg.initializeInnerStruct(sr.getWeight());

    auto X = get_sin_idata<PolynomialReg>();
    auto Y = get_sin_odata<PolynomialReg>();

    tr::Checker<PolynomialReg> check(reg);

    std::cout << "Weight:\n" << reg.getInnerWeight() << "\n\n"
              << "Test:\n" << reg(X) << "\n\n"
              << "Accuracy:\n" << check.guide.global(Y, reg(X), 0.1) << '/' << Y.size() << "\n\n";
}

void polynomial_regression_test()
{
    PolynomialReg reg(6);
    PolynomialRegTraining teach(reg);

    auto X = get_sin_idata<PolynomialReg>();
    auto Y = get_sin_odata<PolynomialReg>();

    tr::Checker<PolynomialReg> check(reg);

    teach.train(X, Y);
    std::cout << reg.getInnerPower() << '\n'
              << "Weight:\n" << reg.getInnerWeight() << "\n\n"
              << "Test:\n" << reg.feedforward(X) << "\n\n"
              << "Loss:\n" << check.loss(X, Y, tr::functional::loss::MSE()) << '\n';

    std::ofstream out("D:\\Serialized\\polynomial_regression_test.bin", std::ios::binary);
    if (not out.is_open()) return;

    tr::Serializer<PolynomialReg> sr;

    sr.serialize(out, reg);
    out.close();

    std::cout << "End of serialization\n";
}

void linear_regression_test_deserialization()
{
    std::ifstream in("D:\\Serialized\\linear_regression_test.bin", std::ios::binary);
    if (not in.is_open()) return;

    tr::Serializer<LinearReg> sr;
    sr.deserialize(in);
    in.close();

    LinearReg reg(sr.getSize());

    reg.initializeInnerStruct(sr.getWeight());

    auto X = get_linear_idata<LinearReg>();
    auto Y = get_linear_odata<LinearReg>();

    tr::Checker<LinearReg> check(reg);

    std::cout << "Weight:\n" << reg.getInnerWeight() << "\n\n"
              << "Test:\n" << reg(X) << "\n\n"
              << "Accuracy:\n" << check.guide.full(Y, reg(X), 0.1) << "\n\n";
}

void linear_regression_test()
{
    LinearReg reg(1);
    LinearRegTraining teach(reg);
    tr::Checker<LinearReg> check(reg);

    auto X = get_linear_idata<LinearReg>();
    auto Y = get_linear_odata<LinearReg>();

    teach.train(X, Y);
    std::cout << reg.getInnerSize() << '\n';

    std::cout << "Weight:\n" << reg.getInnerWeight() << "\n\n"
              << "Test:\n" << reg.feedforward(X) << "\n\n"
              << "Loss:\n" << check.loss(X, Y, tr::functional::loss::MSE()) << '\n';

    std::ofstream out("D:\\Serialized\\linear_regression_test.bin", std::ios::binary);
    if (not out.is_open()) return;

    tr::Serializer<LinearReg> sr;

    sr.serialize(out, reg);
    out.close();

    std::cout << "End of serialization\n";
}
/*
int main()
{
    std::cout << std::fixed << std::setprecision(6);

    //polynomial_regression_test();
    //linear_regression_test();
    polynomial_regression_test_deserialization();
    linear_regression_test_deserialization();

    return 0;
}
*/
