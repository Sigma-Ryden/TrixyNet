#include <Trixy/Core.hpp>
// TrixyNet, Functional, Optimizer, Training
// Serializer, Tensor, Linear, Container, Random

#include <Utility/Core.hpp> // operator<<

#include <fstream> // ifstream, ofstream
#include <iostream> // cin, cout
#include <iomanip> // setprecision, fixed

namespace tr = trixy;
namespace li = trixy::lique;

using namespace tr;
using namespace tr::functional;
using namespace tr::train;

using precision_type = float;
using size_type      = std::size_t;

using Core           = TypeSet<precision_type>;

using PolynomialReg  = PolynomialRegression<Core>;
using LinearReg      = LinearRegression<Core>;

template <class Reg, class Vector = typename Reg::Vector>
Vector get_sin_idata()
{
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
    std::ifstream file("D:\\Serialized\\polynomial_regression_test.bin", std::ios::binary);
    if (not file.is_open()) return;

    Serializer<PolynomialReg> sr;
    sr.deserialize(file);
    file.close();

    PolynomialReg reg(sr.getPower());
    reg.initializeInnerStruct(sr.getWeight());

    auto X = get_sin_idata<PolynomialReg>();
    auto Y = get_sin_odata<PolynomialReg>();

    Checker<PolynomialReg> check(reg);

    std::cout << "Weight:\n" << reg.getInnerWeight() << "\n\n"
              << "Test:\n" << reg(X) << "\n\n"
              << "Accuracy:\n" << check.guide.global(Y, reg(X), 0.1) << '/' << Y.size() << "\n\n";
}

void polynomial_regression_test()
{
    PolynomialReg reg(6);
    Training<PolynomialReg> teach(reg);

    auto X = get_sin_idata<PolynomialReg>();
    auto Y = get_sin_odata<PolynomialReg>();

    Checker<PolynomialReg> check(reg);

    teach.train(X, Y);
    std::cout << reg.getInnerPower() << '\n'
              << "Weight:\n" << reg.getInnerWeight() << "\n\n"
              << "Test:\n" << reg.feedforward(X) << "\n\n"
              << "Loss:\n" << check.loss(X, Y, loss::MSE<precision_type>()) << '\n';

    std::ofstream file("D:\\Serialized\\polynomial_regression_test.bin", std::ios::binary);
    if (not file.is_open()) return;

    Serializer<PolynomialReg> sr;

    sr.serialize(file, reg);
    file.close();

    std::cout << "End of serialization\n";
}

void linear_regression_test_deserialization()
{
    std::ifstream file("D:\\Serialized\\linear_regression_test.bin", std::ios::binary);
    if (not file.is_open()) return;

    Serializer<LinearReg> sr;
    sr.deserialize(file);
    file.close();

    LinearReg reg(sr.getSize());

    reg.initializeInnerStruct(sr.getWeight());

    auto X = get_linear_idata<LinearReg>();
    auto Y = get_linear_odata<LinearReg>();

    Checker<LinearReg> check(reg);

    std::cout << "Weight:\n" << reg.getInnerWeight() << "\n\n"
              << "Test:\n" << reg(X) << "\n\n"
              << "Accuracy:\n" << check.guide.full(Y, reg(X), 0.1) << "\n\n";
}

void linear_regression_test()
{
    LinearReg reg(1);
    Training<LinearReg> teach(reg);
    Checker<LinearReg> check(reg);

    auto X = get_linear_idata<LinearReg>();
    auto Y = get_linear_odata<LinearReg>();

    teach.train(X, Y);
    std::cout << reg.getInnerSize() << '\n';

    std::cout << "Weight:\n" << reg.getInnerWeight() << "\n\n"
              << "Test:\n" << reg.feedforward(X) << "\n\n"
              << "Loss:\n" << check.loss(X, Y, loss::MSE<precision_type>()) << '\n';

    std::ofstream file("D:\\Serialized\\linear_regression_test.bin", std::ios::binary);
    if (not file.is_open()) return;

    Serializer<LinearReg> sr;

    sr.serialize(file, reg);
    file.close();

    std::cout << "End of serialization\n";
}
//
int main()
{
    std::cout << std::fixed << std::setprecision(6);

    //polynomial_regression_test();
    //linear_regression_test();
    polynomial_regression_test_deserialization();
    linear_regression_test_deserialization();

    return 0;
}
//
