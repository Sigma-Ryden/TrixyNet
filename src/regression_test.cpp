#include "Trixy/Lique/lique_core.hpp" // Vector, Matrix, Linear
#include "Trixy/Neuro/Regression/polynomial_regression.hpp" // PolynomialRegression
#include "Trixy/Neuro/Regression/linear_regression.hpp" // LinearRegression

#include "Utility/util.hpp" // Timer

#include <iostream> // cin, cout
#include <iomanip> // setprecision, fixed

namespace tr = trixy;
namespace li = lique;

void polynomial_regression_test()
{
    using util::operator<<;

    tr::PolynomialRegression<li::Vector, li::Matrix, li::Linear, double> reg(3);

    li::Vector<double> X
    {
        75,
        78,
        81,
        93,
        86,
        77,
        85,
        77,
        89,
        95,
        72,
        115
    };

    li::Vector<double> Y
    {
        133,
        125,
        129,
        153,
        140,
        135,
        135,
        132,
        161,
        159,
        120,
        160
    };

    reg.train(X, Y);

    std::cout << "Weight:\n" << reg.getInnerWeight() << "\n\n";
    std::cout << "Test v:\n" << reg.feedforward(X) << "\n\n";
    std::cout << "Test s:\n" << reg.feedforward(83.5) << "\n\n";
    std::cout << "Loss:\n" << reg.loss(X, Y) << "\n\n";
}


void linear_regression_test()
{
    using util::operator<<;

    tr::LinearRegression<li::Vector, li::Matrix, li::Linear, double> reg(2);

    li::Matrix<double> X(12, 2);
    li::Vector<double> Y(12);

    X.copy
    ({
        75, 87,
        78, 85,
        81, 81,
        93, 96,
        86, 83,
        77, 71,
        85, 90,
        77, 73,
        89, 86,
        95, 100,
        72, 80,
        115, 110
    });

    Y.copy
    ({
        133,
        125,
        129,
        153,
        140,
        135,
        135,
        132,
        161,
        159,
        120,
        160
    });

    reg.train(X, Y);

    std::cout << "Weight:\n" << reg.getInnerWeight() << "\n\n";
    std::cout << "Test m:\n" << reg.feedforwardBatch(X) << "\n\n";
    std::cout << "Test v:\n" << reg.feedforwardSample({83., 79.}) << "\n\n";
    std::cout << "Loss:\n" << reg.loss(X, Y) << "\n\n";
}

/*
int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::cout << std::fixed << std::setprecision(6);

    //polynomial_regression_test();
    linear_regression_test();

    return 0;
}
*/
