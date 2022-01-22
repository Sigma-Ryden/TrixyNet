#include "Trixy/Neuro/NeuroCore.hpp" // // LinearRegression, PolynomialRegression, Serializer
#include "Trixy/Lique/LiqueCore.hpp" // Vector, Matrix, Linear

#include "Utility/util.hpp" // operator<<

#include <iostream> // cin, cout
#include <iomanip> // setprecision, fixed

namespace tr = trixy;
namespace li = lique;

li::Vector<double> get_sin_idata()
{
    li::Vector<double> x(61);

    double arg = -3.;

    for(std::size_t i = 0; i < x.size(); ++i)
    {
        x(i) = arg;
        arg += .1;
    }

    return x;
}

li::Vector<double> get_sin_odata()
{
    li::Vector<double> y(61);

    double arg = -3.;

    for(std::size_t i = 0; i < y.size(); ++i)
    {
        y(i) = std::sin(arg);
        arg += .1;
    }

    return y;
}

li::Matrix<double> get_linear_idata()
{
    li::Matrix<double> x(101, 1);

    double arg = -1.;

    for(std::size_t i = 0; i < x.shape().row(); ++i)
    {
        x(i, 0) = arg;
        arg    += .02;
    }

    return x;
}

li::Vector<double> get_linear_odata()
{
    li::Vector<double> y(101);

    double arg = -1.;

    for(std::size_t i = 0; i < y.size(); ++i)
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

    auto X = get_sin_idata();
    auto Y = get_sin_odata();

    std::cout << "Weight:\n" << reg.getInnerWeight() << "\n\n";
    std::cout << "Test v:\n" << reg.feedforward(X) << "\n\n";
    std::cout << "Loss:\n" << reg.loss(X, Y) << "\n\n";
}

void polynomial_regression_test()
{
    using util::operator<<;

    using PolynomialReg         = tr::PolynomialRegression<li::Vector, li::Matrix, li::Linear, double>;
    using PolynomialRegTraining = tr::train::Training<PolynomialReg>;

    PolynomialReg reg(6);
    PolynomialRegTraining teach(reg);

    auto X = get_sin_idata();
    auto Y = get_sin_odata();

    teach.train(X, Y);

    std::cout << "Weight:\n" << reg.getInnerWeight() << "\n\n";
    std::cout << "Test v:\n" << reg.feedforward(X) << "\n\n";
    std::cout << "Loss:\n" << reg.loss(X, Y) << "\n\n";

    std::ofstream out("D:\\Serialized\\polynomial_regression_test.bin", std::ios::binary);
    if(!out.is_open()) return;

    tr::Serializer<PolynomialReg> sr;
    sr.prepare(reg);
    sr.serialize(out);
    out.close();

    std::cout << "End of serialization\n";
}

void linear_regression_test_deserialization()
{
    using util::operator<<;

    using LinearReg = tr::LinearRegression<li::Vector, li::Matrix, li::Linear, double>;

    std::ifstream in("D:\\Serialized\\linear_regression_test.bin", std::ios::binary);
    if(!in.is_open()) return;

    tr::Serializer<LinearReg> sr;
    sr.deserialize(in);
    in.close();

    LinearReg reg(sr.getSize());

    reg.initializeInnerStruct(sr.getWeight());

    auto X = get_linear_idata();
    auto Y = get_linear_odata();

    std::cout << "Weight:\n" << reg.getInnerWeight() << "\n\n";
    std::cout << "Test m:\n" << reg.feedforwardBatch(X) << "\n\n";
    std::cout << "Loss:\n" << reg.loss(X, Y) << "\n\n";
}

void linear_regression_test()
{
    using util::operator<<;

    using LinearReg         = tr::LinearRegression<li::Vector, li::Matrix, li::Linear, double>;
    using LinearRegTraining = tr::train::Training<LinearReg>;

    LinearReg reg(1);
    LinearRegTraining teach(reg);

    auto X = get_linear_idata();
    auto Y = get_linear_odata();

    teach.train(X, Y);

    std::cout << "Weight:\n" << reg.getInnerWeight() << "\n\n";
    std::cout << "Test m:\n" << reg.feedforwardBatch(X) << "\n\n";
    std::cout << "Loss:\n" << reg.loss(X, Y) << "\n\n";

    std::ofstream out("D:\\Serialized\\linear_regression_test.bin", std::ios::binary);
    if(!out.is_open()) return;

    tr::Serializer<LinearReg> sr;
    sr.prepare(reg);
    sr.serialize(out);
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
