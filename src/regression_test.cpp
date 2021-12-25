#include "Trixy/Lique/lique_core.hpp" // Vector, Matrix, Linear
#include "Trixy/Neuro/Regression/polynomial_regression.hpp" // PolynomialRegression
#include "Trixy/Neuro/Regression/linear_regression.hpp" // LinearRegression

#include "Trixy/Neuro/Serialization/polynomial_regression_serializer.hpp" // Serializer
#include "Trixy/Neuro/Serialization/linear_regression_serializer.hpp" // Serializer

#include "Utility/util.hpp" // operator<<

#include <iostream> // cin, cout
#include <iomanip> // setprecision, fixed

namespace tr = trixy;
namespace li = lique;

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

    li::Vector<double> X
    {
        75., 78., 81., 93., 86., 77., 85., 77., 89., 95., 72., 115.
    };

    li::Vector<double> Y
    {
        133., 125., 129., 153., 140., 135., 135., 132., 161., 159., 120., 160.
    };

    std::cout << "Weight:\n" << reg.getInnerWeight() << "\n\n";
    std::cout << "Test v:\n" << reg.feedforward(X) << "\n\n";
    std::cout << "Test s:\n" << reg.feedforward(83.5) << "\n\n";
    std::cout << "Loss:\n" << reg.loss(X, Y) << "\n\n";
}

void polynomial_regression_test()
{
    using util::operator<<;

    using PolynomialReg = tr::PolynomialRegression<li::Vector, li::Matrix, li::Linear, double>;

    std::ofstream out("D:\\Serialized\\polynomial_regression_test.bin", std::ios::binary);

    if(!out.is_open()) return;

    PolynomialReg reg(3);

    li::Vector<double> X
    {
        75., 78., 81., 93., 86., 77., 85., 77., 89., 95., 72., 115.
    };

    li::Vector<double> Y
    {
        133., 125., 129., 153., 140., 135., 135., 132., 161., 159., 120., 160.
    };

    reg.train(X, Y);

    std::cout << "Weight:\n" << reg.getInnerWeight() << "\n\n";
    std::cout << "Test v:\n" << reg.feedforward(X) << "\n\n";
    std::cout << "Test s:\n" << reg.feedforward(83.5) << "\n\n";
    std::cout << "Loss:\n" << reg.loss(X, Y) << "\n\n";

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

    li::Matrix<double> X(12, 2);
    li::Vector<double> Y(12);

    X.copy
    ({
        75., 87.,
        78., 85.,
        81., 81.,
        93., 96.,
        86., 83.,
        77., 71.,
        85., 90.,
        77., 73.,
        89., 86.,
        95., 100.,
        72., 80.,
        115., 110.
    });

    Y.copy
    ({
        133.,
        125.,
        129.,
        153.,
        140.,
        135.,
        135.,
        132.,
        161.,
        159.,
        120.,
        160.
    });

    reg.train(X, Y);

    std::cout << "Weight:\n" << reg.getInnerWeight() << "\n\n";
    std::cout << "Test m:\n" << reg.feedforwardBatch(X) << "\n\n";
    std::cout << "Test v:\n" << reg.feedforwardSample({83., 79.}) << "\n\n";
    std::cout << "Loss:\n" << reg.loss(X, Y) << "\n\n";
}

void linear_regression_test()
{
    using util::operator<<;

    using LinearReg = tr::LinearRegression<li::Vector, li::Matrix, li::Linear, double>;

    std::ofstream out("D:\\Serialized\\linear_regression_test.bin", std::ios::binary);

    if(!out.is_open()) return;

    LinearReg reg(2);

    li::Matrix<double> X(12, 2);
    li::Vector<double> Y(12);

    X.copy
    ({
        75., 87.,
        78., 85.,
        81., 81.,
        93., 96.,
        86., 83.,
        77., 71.,
        85., 90.,
        77., 73.,
        89., 86.,
        95., 100.,
        72., 80.,
        115., 110.
    });

    Y.copy
    ({
        133.,
        125.,
        129.,
        153.,
        140.,
        135.,
        135.,
        132.,
        161.,
        159.,
        120.,
        160.
    });

    reg.train(X, Y);

    std::cout << "Weight:\n" << reg.getInnerWeight() << "\n\n";
    std::cout << "Test m:\n" << reg.feedforwardBatch(X) << "\n\n";
    std::cout << "Test v:\n" << reg.feedforwardSample({83., 79.}) << "\n\n";
    std::cout << "Loss:\n" << reg.loss(X, Y) << "\n\n";

    tr::Serializer<LinearReg> sr;

    sr.prepare(reg);
    sr.serialize(out);
    out.close();

    std::cout << "End of serialization\n";
}
/*
int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::cout << std::fixed << std::setprecision(6);

    //polynomial_regression_test();
    //linear_regression_test();
    polynomial_regression_test_deserialization();
    linear_regression_test_deserialization();

    return 0;
}
*/
