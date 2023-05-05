#include <Auto/TestingCore.hpp>

int main()
{
    TRY_CATCH(EXECUTE_ALL());
    TESTING_STAT();

    return 0;
}

#define protected public

#include <Trixy/Core.hpp>

using Core = trixy::TypeSet<float>;
using Net = trixy::TrixyNet<Core>;

TEST(TestLique, TestMatrix)
{
    {
        Core::Matrix x(3, 4);
        x.copy({
            0, 1, 2, 3,
            4, 5, 6, 7,
            8, 9, 10, 11
        });

        EXPECT("value",
            x(0, 0) == 0 && x(0, 1) == 1 && x(0, 2) == 2 && x(0, 3) == 3 &&
            x(1, 0) == 4 && x(1, 1) == 5 && x(1, 2) == 6 && x(1, 3) == 7 &&
            x(2, 0) == 8 && x(2, 1) == 9 && x(2, 2) == 10 && x(2, 3) == 11
        );
    }
}

TEST(TestLique, TestTensor)
{
    {
        Core::Tensor x(2, 2, 3);
        x.copy({
            0, 1, 2,
            3, 4, 5,

            6, 7, 8,
            9, 10, 11
        });

        EXPECT("value",
            x(0, 0, 0) == 0 && x(0, 0, 1) == 1 && x(0, 0, 2) == 2 &&
            x(0, 1, 0) == 3 && x(0, 1, 1) == 4 && x(0, 1, 2) == 5 &&

            x(1, 0, 0) == 6 && x(1, 0, 1) == 7 && x(1, 0, 2) == 8 &&
            x(1, 1, 0) == 9 && x(1, 1, 1) == 10 && x(1, 1, 2) == 11
        );
    }
}

using Shape = trixy::lique::Shape<Core::size_type>;

using XConvolutional = trixy::layer::XConvolutional<Net>;
using Convolutional = trixy::layer::Convolutional<Net>;

TEST(TestNeuro, TestConvolution)
{
    {
        auto shape = Shape(3, 5, 5);
        auto layer = new XConvolutional(shape, 2, 3, 1, 2);

        layer->Ws_[0].copy({
            -1, 1, 1,
            -1, 1, 1,
             0, 0, 1,

             0, -1, 1,
             -1, 0, -1,
             1, 0, 0,

             1, -1, 0,
             -1, 0, -1,
             0, 1, -1
        });

        layer->Ws_[1].copy({
            0, 0, -1,
            1, 0, 0,
            0, -1, 0,

            1, -1, 0,
            -1, 1, 0,
            -1, 1, 1,

            1, 0, 1,
            1, -1, 1,
            -1, 0, 0
        });

        layer->B_(0) = 1;
        layer->B_(1) = 0;

        Core::Tensor input(shape);
        input.copy({
            1, 2, 0, 1, 0,
            2, 0, 0, 0, 1,
            1, 2, 2, 0, 2,
            2, 2, 2, 0, 1,
            2, 0, 1, 0, 1,

            1, 2, 2, 1, 2,
            0, 2, 2, 0, 2,
            1, 2, 2, 1, 1,
            2, 2, 0, 1, 0,
            2, 2, 1, 0, 0,

            0, 2, 0, 1, 1,
            2, 0, 2, 1, 1,
            2, 0, 1, 2, 1,
            0, 1, 0, 1, 2,
            1, 0, 1, 2, 1
        });

        layer->forward(input);

        auto& x = layer->value();

        EXPECT("value raw",
            x(0, 0, 0) == 2 && x(0, 0, 1) == -3 && x(0, 0, 2) == -1 &&
            x(0, 1, 0) == 5 && x(0, 1, 1) == -7 && x(0, 1, 2) == 2 &&
            x(0, 2, 0) == 5 && x(0, 2, 1) == 0 && x(0, 2, 2) == 0 &&

            x(1, 0, 0) == 3 && x(1, 0, 1) == 5 && x(1, 0, 2) == 2 &&
            x(1, 1, 0) == 1 && x(1, 1, 1) == 0 && x(1, 1, 2) == -3 &&
            x(1, 2, 0) == -2 && x(1, 2, 1) == 4 && x(1, 2, 2) == 3
        );
    }

    {
        auto shape = Shape(1, 4, 4);
        auto layer = new Convolutional(shape, 1, 3, 0, 1);

        layer->Ws_[0].copy({
            1, 4, 1,
            1, 4, 3,
            3, 3, 1
        });

        layer->B_(0) = 0;

        Core::Tensor input(shape);
        input.copy({
            4, 5, 8, 7,
            1, 8, 8, 8,
            3, 6, 6, 4,
            6, 5, 7, 8
        });

        layer->forward(input);

        auto& x = layer->value();

        EXPECT("train.value",
            x(0, 0, 0) == 122 && x(0, 0, 1) == 148 &&
            x(0, 1, 0) == 126 && x(0, 1, 1) == 134
        );

        Core::Tensor idelta(1, 2, 2);
        idelta.copy({
            2, 1,
            4, 4
        });

        layer->backward(input, idelta);

        auto& d = layer->delta();

        EXPECT("train.delta",
            d(0, 0, 0) == 2 && d(0, 0, 1) == 9 && d(0, 0, 2) == 6 && d(0, 0, 3) == 1 &&
            d(0, 1, 0) == 6 && d(0, 1, 1) == 29 && d(0, 1, 2) == 30 && d(0, 1, 3) == 7 &&
            d(0, 2, 0) == 10 && d(0, 2, 1) == 29 && d(0, 2, 2) == 33 && d(0, 2, 3) == 13 &&
            d(0, 3, 0) == 12 && d(0, 3, 1) == 24 && d(0, 3, 2) == 16 && d(0, 3, 3) == 4
        );
    }
}
