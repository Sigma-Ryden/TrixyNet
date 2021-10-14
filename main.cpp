#include <random>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <cstddef>

#include "Trixy/Lique/lique_linear.hpp"
#include "Trixy/Lique/lique_matrix.hpp"
#include "Trixy/Lique/lique_vector.hpp"

#include "Trixy/Neuro/neuro_core_alpha.hpp"
#include "Trixy/Neuro/neuro_functional.hpp"

#include "Trixy/Collection/collection.hpp"

#include "Include/MnistMaster/mnist_reader.hpp"
#include "Include/Timer/timer.h"

#include "Trixy/Lique/ilique_base.hpp"
#include "Trixy/Lique/ilique_matrix.hpp"
#include "Trixy/Lique/ilique_vector.hpp"

#include "Trixy/Neuro/neuro_functional.hpp"

namespace tr = trixy;
namespace li = lique;
namespace il = ilique;

double random_real()
{
    static int within = 1'000;
    return static_cast<double>(rand() % (2 * within + 1) - within) / within;
}
double random_normal()
{
    static int within = 1'000;
    static double pi = 3.14159265;    
    double x = static_cast<double>(rand() % (2 * within + 1) - within) / within;

    return std::exp(- x * x) / std::sqrt(2 * pi);
}
//<
template <typename... Args>
std::ostream& operator<< (std::ostream& out, const li::Matrix<Args...>& matrix)
{
    out << '[';
    for(std::size_t i = 0; i < matrix.size().row() - 1; ++i)
    {
        out << '[';
        for(std::size_t j = 0; j < matrix.size().col() - 1; ++j)
            out << matrix(i, j) << ", ";

        out << matrix(i, matrix.size().col() - 1) << "], ";
    }

    out << '[';
    for(std::size_t j = 0; j < matrix.size().col() - 1; ++j)
        out << matrix(matrix.size().row() - 1, j) << ", ";

    out << matrix(matrix.size().row() - 1, matrix.size().col() - 1) << "]]";

    return out;
}

template <typename... Args>
std::ostream& operator<< (std::ostream& out, const li::Vector<Args...>& vector)
{
    out << '[';
    for(std::size_t i = 0; i < vector.size() - 1; ++i)
        out << vector(i) << ", ";

    out << vector(vector.size() - 1) << ']';

    return out;
}
//>
//<
template <template <typename T, typename...> class Matrix, template <typename T, typename...> class Vector,
     template <class M, class V> class Linear, template <typename...> class Collection, typename... Args>
void showInnerStruct(
    const trixy::Neuro<Matrix, Vector, Linear, Collection, Args...>& neuro)
{
    for(std::size_t i = 0; i < neuro.getInnerWeight().size(); ++i)
        std::cout << "W[" << i << "]: " << neuro.getInnerWeight()[i] << '\n';

    for(std::size_t i = 0; i < neuro.getInnerBias().size(); ++i)
        std::cout << "B[" << i << "]: " << neuro.getInnerBias()[i] << '\n';
}

template <typename Neuro>
void testNeuro(
    const Neuro& network, const li::Matrix<double>& in, const li::Matrix<double>& out)
{
    li::Linear<li::Matrix<double>, li::Vector<double>> li;

    for(std::size_t i = 0; i < in.size().row(); ++i)
        std::cout << "<" << i << "> "
            << network.feedforward(li.get(in, i)) << " : "
                << li.get(out, i) << '\n';
}
//>
//<
li::Matrix<double> initialize_i(
    const std::vector<std::vector<unsigned char>>& data,
    std::size_t batch_size, std::size_t input_size)
{
    li::Matrix<double> input_batch(batch_size, input_size);

    for(std::size_t i = 0; i < batch_size; ++i)
        for(std::size_t j = 0; j < input_size; ++j)
            input_batch(i, j) = data[i][j] / 255.0;

    return input_batch;
}

li::Matrix<double> initialize_o(
    const std::vector<unsigned char>& data, std::size_t batch_size, std::size_t output_size)
{
    li::Matrix<double> output_batch(batch_size, output_size);

    for(std::size_t i = 0; i < batch_size; ++i)
        for(std::size_t j = 0; j < output_size; ++j)
            if(data[i] == j)
                output_batch(i, j) = 1;
            else
                output_batch(i, j) = 0;

    return output_batch;
}

void show_image_batch(const li::Matrix<unsigned char>& data)
{
    for(std::size_t i = 0; i < data.size().row(); ++i)
    {
        for(std::size_t j = 0; j < data.size().col(); ++j)
        {
            if(j % 28 == 0)
                std::cout << '\n';
            std::cout << (data(i, j) != 0.0 ? '#' : '.') << ' ';
        }
        std::cout << '\n';
    }
}
//>

void network_size(const Collection<std::size_t>& topology)
{
    std::size_t count = 0;
    for(std::size_t i = 1; i < topology.size(); ++i)
       count += (topology[i - 1] + 1) * topology[i];

    count += topology.size();

    count *= 8;

    std::cout << (count / 1024) / 1024 << " MByte(s) "
              << (count / 1024) % 1024 << " KByte(s) "
              << count % 1024 << " Byte(s)\n";
}

void test9()
{
    using NeuralFeedForward
         = trixy::Neuro<li::Matrix, li::Vector, li::Linear, Collection>;

    NeuralFeedForward network = {4, 4, 5, 4, 3};

    network.initializeInnerStruct(random_real);

    network.setActivationFunction(tr::get<tr::function::Activation, li::Vector>("relu"));
    network.setNormalizationFunction(tr::get<tr::function::Activation, li::Vector>("stable_softmax"));
    network.setLossFunction(tr::get<tr::function::Loss, li::Vector>("CE"));

    //old_softmax: 7.209624 - deprecated
    //stable_softmax: 6.841548 - for ActFunc like RELU
    //softmax: 6.904061 - for ActFunc within [-a, a]
    li::Matrix<double> train_in_set
    {
        {1, 0, 1, 1},
        {1, 1, 1, 0},
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {1, 0, 1, 0},
        {0, 0, 1, 1}
    };
    li::Matrix<double> train_out_set
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
    network.trainBatch(train_in_set, train_out_set, 0.15, 100'000);
    network.trainMiniBatch(train_in_set, train_out_set, 0.15, 100'000, 2);
    network.trainStochastic(train_in_set, train_out_set, 0.1, 100'000);
    std::cout << t.elapsed() << '\n';

    std::cout << "After train\n";
    testNeuro(network, train_in_set, train_out_set);
    std::cout << "Normal accuracy: " << network.normalAccuracy(train_in_set, train_out_set) << '\n';
    std::cout << "Global accuracy: " << network.globalAccuracy(train_in_set, train_out_set, 0.15) << '\n';
    std::cout << "Full accuracy: " << network.fullAccuracy(train_in_set, train_out_set, 0.15) << '\n';
    std::cout << "Loss: " << network.loss(train_in_set, train_out_set) << '\n';
}

void test13()
{
//  Data preparing:
    auto dataset =
        mnist::read_dataset<std::vector, std::vector, uint8_t, uint8_t>("C:/mnist_data/");

    std::size_t train_batch_size = 10000;
    std::size_t test_batch_size = 10000;
    std::size_t input_size = 784;
    std::size_t out_size = 10;

//  Train batch initialize:
    li::Matrix<double> train_in = initialize_i(dataset.training_images, train_batch_size, input_size);
    li::Matrix<double> train_out = initialize_o(dataset.training_labels, train_batch_size, out_size);

//  Test batch initialize:
    li::Matrix<double> test_in = initialize_i(dataset.test_images, test_batch_size, input_size);
    li::Matrix<double> test_out = initialize_o(dataset.test_labels, test_batch_size, out_size);

//  Show image:
   //show_image_batch(train_in);

//  Neuralnetwork preparing:
    using NeuralFeedForward
         = trixy::Neuro<li::Matrix, li::Vector, li::Linear, Collection>;

    NeuralFeedForward network = { input_size, 350, 150, out_size };

    network.initializeInnerStruct(random_real);

    network.setActivationFunction(tr::get<tr::function::Activation, li::Vector>("sigmoid"));
    network.setNormalizationFunction(tr::get<tr::function::Activation, li::Vector>("softmax"));
    network.setLossFunction(tr::get<tr::function::Loss, li::Vector>("CE"));

//  Train network:
    std::size_t times = 15;
    for(std::size_t i = 0; i < times; ++i)
    {
        std::cout << "start train [" << i + 1 << "]:\n";
        Timer t;
        //network.trainMiniBatch(train_in, train_out, 0.1, 100, 32);
        network.trainStochastic(train_in, train_out, 0.15, 5000);
        std::cout << t.elapsed() << '\n';
        std::cout << "NNetwork train loss: " << network.loss(train_in, train_out) << '\n';
    }
//  Test train_batch aft
    std::cout << "NNetwork tarin normal accuracy: " << network.normalAccuracy(train_in, train_out) << '\n';
    std::cout << "NNetwork tarin global accuracy: " << network.globalAccuracy(train_in, train_out, 0.25) << '\n';
    std::cout << "NNetwork tarin full accuracy: " << network.fullAccuracy(train_in, train_out, 0.25) << '\n';
//  Test test_batch aft
    std::cout << "NNetwork test loss: " << network.loss(test_in, test_out) << '\n';
    std::cout << "NNetwork test normal accuracy: " << network.normalAccuracy(test_in, test_out) << '\n';
    std::cout << "NNetwork test global accuracy: " << network.globalAccuracy(test_in, test_out, 0.25) << '\n';
    std::cout << "NNetwork test full accuracy: " << network.fullAccuracy(test_in, test_out, 0.25) << '\n';
}

void test10()
{
// Creating Neural Network
    tr::Neuro<li::Matrix, li::Vector, li::Linear, Collection> network = {2, 2, 2};

    network.initializeInnerStruct(random_real);

    network.setActivationFunction(tr::get<tr::function::Activation, li::Vector>("relu"));
    network.setNormalizationFunction(tr::get<tr::function::Activation, li::Vector>("stable_softmax"));
    network.setLossFunction(tr::get<tr::function::Loss, li::Vector>("CE"));

// Train set (in/out)
    li::Matrix<double> train_in
    {
        {-2, -1},
        {23, 6},
        {10, 4},
        {-15, -6}
    };

    li::Matrix<double> train_out
    {
        {1, 0},
        {0, 1},
        {0, 1},
        {1, 0}
    };

    train_in.modify([] (double x) { return x / 25.0; });
// Full processing
    Timer t;
    network.trainBatch(train_in, train_out, 0.1, 1'000);
    std::cout << t.elapsed() << '\n';
    testNeuro(network, train_in, train_out);
    std::cout << "NNetwork tarin global accuracy: " << network.globalAccuracy(train_in, train_out, 0.05) << '\n';
    std::cout << "NNetwork tarin normal accuracy: " << network.normalAccuracy(train_in, train_out) << '\n';
    std::cout << "NNetwork tarin full accuracy: " << network.fullAccuracy(train_in, train_out, 0.05) << '\n';
}

int main()
{
    srand(static_cast<unsigned>(time(0)));

    std::cout << std::fixed << std::setprecision(9);
    //std::cout.setf(std::ios::showpos);

    test13();

    return 0;
}

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
*/
