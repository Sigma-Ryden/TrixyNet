#include <Trixy/Core.hpp>
// TrixyNet, Functional, Optimizer, Training
// Serializer, Tensor, Linear, Container, Random

#include <Utility/Core.hpp> // operator<<

#include <fstream> // ifstream, ofstream
#include <iostream> // cin, cout
#include <iomanip> // setprecision, fixed

using Core = trixy::TypeSet<float>;
using PolynomialRegression = trixy::PolynomialRegression<Core>;
using LinearRegression = trixy::LinearRegression<Core>;

using MSE = trixy::functional::loss::MSE<Core::precision_type>;

Core::Vector get_sin_idata()
{
    Core::Vector x(61);

    Core::precision_type arg = -3.;
    for (Core::size_type i = 0; i < x.size(); ++i)
    {
        x(i) = arg;
        arg += .1;
    }

    return x;
}

Core::Vector get_sin_odata()
{
    Core::Vector y(61);

    Core::precision_type arg = -3.;
    for (Core::size_type i = 0; i < y.size(); ++i)
    {
        y(i) = std::sin(arg);
        arg += .1;
    }

    return y;
}

Core::Matrix get_linear_idata()
{
    Core::Matrix x(101, 1);

    Core::precision_type arg = -1.;
    for (Core::size_type i = 0; i < x.shape().height; ++i)
    {
        x(i, 0) = arg;
        arg    += .02;
    }

    return x;
}

Core::Vector get_linear_odata()
{
    Core::Vector y(101);

    Core::precision_type arg = -1.;
    for (Core::size_type i = 0; i < y.size(); ++i)
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

    PolynomialRegression reg;

    trixy::Serializer<PolynomialRegression> sr;
    sr.deserialize(file, reg);

    file.close();

    auto X = get_sin_idata();
    auto Y = get_sin_odata();

    trixy::Checker<PolynomialRegression> check(reg);

    std::cout << "Weight:\n" << reg.weight() << "\n\n"
              << "Test:\n" << reg(X) << "\n\n"
              << "Accuracy:\n" << check.guide.global(Y, reg(X), 0.1) << '/' << Y.size() << "\n\n";
}

void polynomial_regression_test()
{
    PolynomialRegression reg(6);
    trixy::train::Training<PolynomialRegression> teach(reg);

    auto X = get_sin_idata();
    auto Y = get_sin_odata();

    trixy::Checker<PolynomialRegression> check(reg);

    teach.train(X, Y);
    std::cout << reg.power() << '\n'
              << "Weight:\n" << reg.weight() << "\n\n"
              << "Test:\n" << reg.feedforward(X) << "\n\n"
              << "Loss:\n" << check.loss(X, Y, MSE()) << '\n';

    std::ofstream file("D:\\Serialized\\polynomial_regression_test.bin", std::ios::binary);
    if (not file.is_open()) return;

    trixy::Serializer<PolynomialRegression> sr;
    sr.serialize(file, reg);

    file.close();

    std::cout << "End of serialization\n";
}

void linear_regression_test_deserialization()
{
    std::ifstream file("D:\\Serialized\\linear_regression_test.bin", std::ios::binary);
    if (not file.is_open()) return;

    LinearRegression reg;

    trixy::Serializer<LinearRegression> sr;
    sr.deserialize(file, reg);

    file.close();

    auto X = get_linear_idata();
    auto Y = get_linear_odata();

    trixy::Checker<LinearRegression> check(reg);

    std::cout << "Weight:\n" << reg.weight() << "\n\n"
              << "Test:\n" << reg(X) << "\n\n"
              << "Accuracy:\n" << check.guide.full(Y, reg(X), 0.1) << "\n\n";
}

void linear_regression_test()
{
    LinearRegression reg(1);
    trixy::train::Training<LinearRegression> teach(reg);
    trixy::Checker<LinearRegression> check(reg);

    auto X = get_linear_idata();
    auto Y = get_linear_odata();

    teach.train(X, Y);
    std::cout << reg.size() << '\n';

    std::cout << "Weight:\n" << reg.weight() << "\n\n"
              << "Test:\n" << reg.feedforward(X) << "\n\n"
              << "Loss:\n" << check.loss(X, Y, MSE()) << '\n';

    std::ofstream file("D:\\Serialized\\linear_regression_test.bin", std::ios::binary);
    if (not file.is_open()) return;

    trixy::Serializer<LinearRegression> sr;
    sr.serialize(file, reg);

    file.close();

    std::cout << "End of serialization\n";
}

int main()
{
    std::cout << std::fixed << std::setprecision(6);

    //polynomial_regression_test();
    //linear_regression_test();
    polynomial_regression_test_deserialization();
    linear_regression_test_deserialization();

    return 0;
}
