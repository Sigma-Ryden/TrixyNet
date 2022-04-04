#include "Trixy/Neuro/Core.hpp" // // Regression, Training, Serializer
#include "Trixy/Lique/Core.hpp" // Tensor, Linear

#include "Utility/util.hpp" // operator<<

#include <iostream> // cin, cout
#include <iomanip> // setprecision, fixed

namespace tr = trixy;
namespace li = trixy::lique;

template <class Reg, class Vector = typename Reg::Vector>
Vector get_sin_idata()
{
    using size_type      = typename Reg::size_type;
    using precision_type = typename Reg::precision_type;

    Vector x(61);

    precision_type arg = -3.;

    for(size_type i = 0; i < x.size(); ++i)
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

    for(size_type i = 0; i < y.size(); ++i)
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

    for(size_type i = 0; i < x.shape().row(); ++i)
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

    for(size_type i = 0; i < y.size(); ++i)
    {
        y(i) = arg * 8. + 2.;
        arg += .02;
    }

    return y;
}

void polynomial_regression_test_deserialization()
{
    using util::operator<<;

    using PolynomialReg = tr::PolynomialRegression<li::Vector, li::Matrix, li::Linear, double>;

    std::ifstream in("D:\\Serialized\\polynomial_regression_test.bin", std::ios::binary);
    if(!in.is_open()) return;

    tr::Serializer<PolynomialReg> sr;
    sr.deserialize(in);
    in.close();

    PolynomialReg reg(sr.getPower());
    reg.initializeInnerStruct(sr.getWeight());

    auto X = get_sin_idata<PolynomialReg>();
    auto Y = get_sin_odata<PolynomialReg>();

    std::cout << "Weight:\n" << reg.getInnerWeight() << "\n\n";
    std::cout << "Test:\n" << reg.feedforward(X) << "\n\n";
    std::cout << "Loss:\n" << reg.loss(X, Y) << "\n\n";
}

void polynomial_regression_test()
{
    using util::operator<<;

    using PolynomialReg         = tr::PolynomialRegression<li::Vector, li::Matrix, li::Linear, double>;
    using PolynomialRegTraining = tr::train::Training<PolynomialReg>;

    PolynomialReg reg(6);
    PolynomialRegTraining teach(reg);

    auto X = get_sin_idata<PolynomialReg>();
    auto Y = get_sin_odata<PolynomialReg>();

    teach.train(X, Y);
    std::cout << reg.getInnerPower() << '\n';
    std::cout << "Weight:\n" << reg.getInnerWeight() << "\n\n";
    std::cout << "Test:\n" << reg.feedforward(X) << "\n\n";
    std::cout << "Loss:\n" << reg.loss(X, Y) << "\n\n";

    std::ofstream out("D:\\Serialized\\polynomial_regression_test.bin", std::ios::binary);
    if(!out.is_open()) return;

    tr::Serializer<PolynomialReg> sr;

    sr.serialize(out, reg);
    out.close();

    std::cout << "End of serialization\n";
}

void linear_regression_test_deserialization()
{
    using util::operator<<;

    using LinearReg = tr::LinearRegression<li::Vector, li::Matrix, li::Linear, float>;

    std::ifstream in("D:\\Serialized\\linear_regression_test.bin", std::ios::binary);
    if(!in.is_open()) return;

    tr::Serializer<LinearReg> sr;
    sr.deserialize(in);
    in.close();

    LinearReg reg(sr.getSize());

    reg.initializeInnerStruct(sr.getWeight());

    auto X = get_linear_idata<LinearReg>();
    auto Y = get_linear_odata<LinearReg>();

    std::cout << "Weight:\n" << reg.getInnerWeight() << "\n\n";
    std::cout << "Test:\n" << reg.feedforwardBatch(X) << "\n\n";
    std::cout << "Loss:\n" << reg.loss(X, Y) << "\n\n";
}

void linear_regression_test()
{
    using util::operator<<;

    using LinearReg         = tr::LinearRegression<li::Vector, li::Matrix, li::Linear, double>;
    using LinearRegTraining = tr::train::Training<LinearReg>;

    LinearReg reg(1);
    LinearRegTraining teach(reg);

    auto X = get_linear_idata<LinearReg>();
    auto Y = get_linear_odata<LinearReg>();

    teach.train(X, Y);
    std::cout << reg.getInnerSize() << '\n';
    std::cout << "Weight:\n" << reg.getInnerWeight() << "\n\n";
    std::cout << "Test:\n" << reg.feedforwardBatch(X) << "\n\n";
    std::cout << "Loss:\n" << reg.loss(X, Y) << "\n\n";

    std::ofstream out("D:\\Serialized\\linear_regression_test.bin", std::ios::binary);
    if(!out.is_open()) return;

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
