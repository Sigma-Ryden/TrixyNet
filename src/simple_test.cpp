#include <cstdlib> // rand, srand, size_t
#include <ctime> // time
#include <iostream> // cin, cout
#include <iomanip> // setprecision, fixed

#include "Trixy/Lique/lique_linear.hpp" // Linear
#include "Trixy/Lique/lique_matrix.hpp" // Matrix
#include "Trixy/Lique/lique_vector.hpp" // Vector

#include "Trixy/Neuro/neuro_core.hpp" // Neuro, Activation, Loss
#include "Trixy/Neuro/neuro_functional.hpp" // get

#include "Trixy/Collection/collection.hpp" // Collection

#include "MnistMaster/mnist_reader.hpp" // read_dataset
#include "Timer/timer.h" // Timer
#include "UtilityMaster/utils.hpp" // testNeuro

/*
#include "Trixy/Lique/ilique_base.hpp"
#include "Trixy/Lique/ilique_linear.hpp"
#include "Trixy/Lique/ilique_matrix.hpp"
#include "Trixy/Lique/ilique_vector.hpp"
*/

namespace tr = trixy;
namespace li = lique;

template <typename Precision>
Precision random_real()
{
    static int within = 1000;
    return static_cast<Precision>(std::rand() % (2 * within + 1) - within) / within;
}
template <typename Precision>
Precision random_normal()
{
    static int within = 1000;
    static double pi = 3.14159265;
    Precision x = static_cast<Precision>(std::rand() % (2 * within + 1) - within) / within;

    return std::exp(- x * x) / std::sqrt(2 * pi);
}

template <typename Precision>
void simple_test()
{
    using NeuralFeedForward
         = trixy::Neuro<li::Vector, li::Matrix, li::Linear, Collection, Precision>;

    NeuralFeedForward network = {4, 4, 5, 4, 3};

    network.initializeInnerStruct(random_real);

    network.setActivationFunction(tr::get<tr::function::Activation, li::Vector, Precision>("relu"));
    network.setNormalizationFunction(tr::get<tr::function::Activation, li::Vector, Precision>("softmax"));
    network.setLossFunction(tr::get<tr::function::Loss, li::Vector, Precision>("CCE"));

    //old_softmax: 7.209624 - deprecated
    //stable_softmax: 6.841548 - for ActFunc like RELU -> new 6.700982
    //softmax: 6.904061 - for ActFunc within [-a, a]
    Collection<li::Vector<Precision>> train_in_set
    {
        {1, 0, 1, 1},
        {1, 1, 1, 0},
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {1, 0, 1, 0},
        {0, 0, 1, 1}
    };
    Collection<li::Vector<Precision>> train_out_set
    {
        {1, 0, 0},
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 1},
        {0, 1, 0},
        {1, 0, 0}
    };

    std::cout << "Before train\n";
    testNeuro(network, train_in_set, train_out_set);

    Timer t;

    network.trainStochastic(train_in_set, train_out_set, 0.1, 100000, std::rand);
    network.trainBatch(train_in_set, train_out_set, 0.15, 100000);
    network.trainMiniBatch(train_in_set, train_out_set, 0.15, 100000, 2, std::rand);
    std::cout << t.elapsed() << '\n';

    std::cout << "After train\n";
    testNeuro(network, train_in_set, train_out_set);
    std::cout << "Normal accuracy: " << network.accuracy(train_in_set, train_out_set) << '\n';
    std::cout << "Global accuracy: " << network.globalAccuracy(train_in_set, train_out_set, 0.05) << '\n';
    std::cout << "Full accuracy: " << network.fullAccuracy(train_in_set, train_out_set, 0.05) << '\n';
    std::cout << "Loss: " << network.loss(train_in_set, train_out_set) << '\n';
}
//
int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout << std::fixed << std::setprecision(6);

    simple_test<double>();

    std::cin.get();

    return 0;
}
//
/*
template <typename T>
class MyVector : public il::ILiqueBase<MyVector, T>, public il::IVector<MyVector, T>
{
public:
    MyVector(std::size_t size) : il::IVector<MyVector, T>(size){}
    T dot(const MyVector& a) const override { return 0; }
    MyVector& fill(T value) override
    {
        for(std::size_t i = 0; i < this->size_; ++i)
            this->data_[i] = value;

        return *this;
    }
    MyVector& resize (std::size_t new_size) override
    {
        delete[] this->data_;

        this->size_ = new_size;
        this->data_ = new T[new_size];

        return *this;
    }
    void show()
    {
        for(std::size_t i = 0; i < this->size_; ++i)
            std::cout << this->data_[i] << ' ';
        std::cout << '\n';
    }
};

template <typename T>
class MyMatrix : public il::ILiqueBase<MyMatrix, T>, public il::IMatrix<MyMatrix, T>
{
public:
    MyMatrix(const typename il::IMatrix<MyMatrix, T>::Shape& shape)
        : il::IMatrix<MyMatrix, T>(shape)
    {
        std::cout << "SHAPE\n";
    }
    MyMatrix(std::size_t m, std::size_t n) : il::IMatrix<MyMatrix, T>(m, n)
    {
        std::cout << "MN\n";
    }
    MyMatrix& resize(
        const typename il::IMatrix<MyMatrix, T>::Shape& new_shape) override
    {

        return *this;
    }
    MyMatrix& resize(std::size_t m, std::size_t n) override
    {
        return *this;
    }
    MyMatrix& fill(T value) override
    {
        for(std::size_t i = 0; i < this->shape_.row(); ++i)
            for(std::size_t j = 0; j < this->shape_.col(); ++j)
                this->data_[i][j] = value;

        return *this;
    }
    void show()
    {
        this->shape_.col_ = 2;
        this->shape_.row_ = 2;
        for(std::size_t i = 0; i < this->shape_.row_; ++i)
        {
            for(std::size_t j = 0; j < this->shape_.col_; ++j)
            {
                std::cout << this->data_[i][j] << ' ';
            }
            std::cout << '\n';
        }
    }
};

void print(const char* str)
{
    std::cout << str;
}

void test21()
{
    MyMatrix<int> a(3, 3);
    MyMatrix<int> b(3, 3);
    a.fill(0);
    b.fill(1);
    a.show();
    b.show();
    a = b;
    a.show();
    b.show();
}

void test22()
{
    MyVector<int> a(3);
    a.fill(0).show();
    a.show();
    a.resize(5).fill(1).show();
    a.resize(7);
    a.fill(2);
    a.show();
    std::cout << "GOOD";
    MyMatrix<int> w(3, 3);
    w.fill(0);
    w.fill(1);
    w.show();
}
*/

/*
template <class Matrix, class Vector>
class MyLinear : public il::ILinear<Matrix, Vector>
{
public:
    MyLinear() : il::ILinear<Matrix, Vector>() {}

    Vector get(const Matrix& matrix, std::size_t row_number) const override
    {
        Vector new_vector(matrix.size().col());

        for(std::size_t i = 0; i < matrix.size().col(); ++i)
            new_vector(i) = matrix(row_number, i);

        return new_vector;
    }

    Vector dot (
        const Vector& vector, const Matrix& matrix, bool transpose_dot_matrix = false) const override
    {
        double result = 0.0;
        if(transpose_dot_matrix)
        {
            Vector new_vector(matrix.size().row());

            for(std::size_t i = 0; i < matrix.size().row(); ++i)
            {
                for(std::size_t j = 0; j <  matrix.size().col(); ++j)
                    result += vector(j) * matrix(i, j);

                new_vector(i) = result;
                result = 0.0;
            }

            return new_vector;
        }
        else
        {
            Vector new_vector(matrix.size().col());

            for(std::size_t i = 0; i < matrix.size().col(); ++i)
            {
                for(std::size_t j = 0; j <  matrix.size().row(); ++j)
                    result += vector(j) * matrix(j, i);

                new_vector(i) = result;
                result = 0.0;
            }

            return new_vector;
        }
    }

    Matrix tensordot (
        const Vector& left_side_vector, const Vector& right_side_vector,
        bool return_transpose_matrix = false) const override
    {
        if(return_transpose_matrix)
        {
            Matrix new_matrix(left_side_vector.size(), right_side_vector.size());

            for(std::size_t i = 0; i < left_side_vector.size(); ++i)
                for(std::size_t j = 0; j < right_side_vector.size(); ++j)
                    new_matrix(i, j) = left_side_vector(i) * right_side_vector(j);

            return new_matrix;
        }
        else
        {
            Matrix new_matrix(right_side_vector.size(), left_side_vector.size());

            for(std::size_t i = 0; i < right_side_vector.size(); ++i)
                for(std::size_t j = 0; j < left_side_vector.size(); ++j)
                    new_matrix(i, j) = left_side_vector(j) * right_side_vector(i);

            return new_matrix;
        }
    }
};
*/
/*
template <bool condition, typename T>
struct enable_if;

template <typename T>
struct enable_if<true, T>
{
    using type = T;
};

template <typename T, typename U>
struct is_same
{
    constexpr static bool value = false;
};

template <typename T>
struct is_same<T, T>
{
    constexpr static bool value = true;
};

template <typename Precision>
void test10()
{
// Creating Neural Network
    tr::Neuro<li::Matrix, li::Vector, li::Linear, Collection, Precision> network = {2, 2, 2};

    network.initializeInnerStruct(random_real);

    network.setActivationFunction(tr::get<tr::function::Activation, li::Vector, Precision>("gelu"));
    network.setNormalizationFunction(tr::get<tr::function::Activation, li::Vector, Precision>("softmax"));
    network.setLossFunction(tr::get<tr::function::Loss, li::Vector, Precision>("CCE"));

// Train set (in/out)
    Collection<li::Vector<Precision>> train_in
    {
        {-2, -1},
        {23, 6},
        {10, 4},
        {-15, -6}
    };

    Collection<li::Vector<Precision>> train_out
    {
        {1, 0},
        {0, 1},
        {0, 1},
        {1, 0}
    };
    for(std::size_t i = 0; i < train_in.size(); ++i)
        train_in[i].modify([] (Precision x) -> Precision { return x / 25.0; });
// Full processing
    Timer t;
    network.trainBatch(train_in, train_out, 0.1, 1'000);
    std::cout << t.elapsed() << '\n';
    testNeuro(network, train_in, train_out);
    std::cout << "NNetwork tarin global accuracy: " << network.accuracy(train_in, train_out, 0.05) << '\n';
    std::cout << "NNetwork tarin normal accuracy: " << network.normalAccuracy(train_in, train_out) << '\n';
    std::cout << "NNetwork tarin full accuracy: " << network.fullAccuracy(train_in, train_out, 0.05) << '\n';
}
*/
