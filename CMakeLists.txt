cmake_minimum_required(VERSION 3.5)

project(Trixy LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(TESTING
    src/simple_test.cpp
    src/mnist_test.cpp
    src/speed_test.cpp
    src/regression_test.cpp
    src/experimental_test.cpp
)
set(TRIXY_CONTAINER
    include/Trixy/Container/Container.hpp
    include/Trixy/Container/IContainer.hpp
    include/Trixy/Container/Core.hpp
)
set(TRIXY_LIQUE
    include/Trixy/Lique/Detail/FunctionDetail.hpp
    include/Trixy/Lique/Detail/LiqueMeta.hpp
    include/Trixy/Lique/Detail/MacroScope.hpp
    include/Trixy/Lique/Detail/MacroUnscope.hpp

    include/Trixy/Lique/Base.hpp
    include/Trixy/Lique/TensorBase.hpp
    include/Trixy/Lique/Linear.hpp
    include/Trixy/Lique/Tensor.hpp
    include/Trixy/Lique/Matrix.hpp
    include/Trixy/Lique/Vector.hpp
    include/Trixy/Lique/Shape.hpp
    include/Trixy/Lique/Tool.hpp
    include/Trixy/Lique/Core.hpp
)
set(TRIXY_ILIQUE
    include/Trixy/ILique/Detail/MacroScope.hpp
    include/Trixy/ILique/Detail/MacroUnscope.hpp

    include/Trixy/ILique/Base.hpp
    include/Trixy/ILique/Linear.hpp
    include/Trixy/ILique/Tensor.hpp
    include/Trixy/ILique/Matrix.hpp
    include/Trixy/ILique/Vector.hpp
    include/Trixy/ILique/Core.hpp
)
set(TRIXY_LOCKER
    include/Trixy/Locker/Detail/LockerMeta.hpp

    include/Trixy/Locker/Base.hpp
    include/Trixy/Locker/Container.hpp
    include/Trixy/Locker/Vector.hpp
    include/Trixy/Locker/Matrix.hpp
    include/Trixy/Locker/Tensor.hpp
    include/Trixy/Locker/Core.hpp
)
set(TRIXY_REQUIRE
    include/Trixy/Require/Base.hpp
    include/Trixy/Require/Vector.hpp
    include/Trixy/Require/Matrix.hpp
    include/Trixy/Require/Tensor.hpp
    include/Trixy/Require/Linear.hpp
    include/Trixy/Require/Container.hpp
    include/Trixy/Require/Precision.hpp
    include/Trixy/Require/Core.hpp
)
set(TRIXY_BUFFER
    include/Trixy/Buffer/Core.hpp
    include/Trixy/Buffer/Detail/MacroScope.hpp
    include/Trixy/Buffer/Detail/MacroUnscope.hpp
)
set(TRIXY_RANGE
    include/Trixy/Range/Detail/Meta.hpp

    include/Trixy/Range/Base.hpp
    include/Trixy/Range/View.hpp
    include/Trixy/Range/Unified.hpp
    include/Trixy/Range/Core.hpp
)
set(TRIXY_RANDOM
    include/Trixy/Random/Core.hpp
)
set(TRIXY_NEURO
    include/Trixy/Base.hpp
    include/Trixy/Core.hpp

    include/Trixy/Detail/TrixyMeta.hpp
    include/Trixy/Detail/FunctionDetail.hpp
    include/Trixy/Detail/MacroScope.hpp
    include/Trixy/Detail/MacroUnscope.hpp

    include/Trixy/Neuro/Detail/TrixyNetMeta.hpp
    include/Trixy/Neuro/Detail/MacroScope.hpp
    include/Trixy/Neuro/Detail/MacroUnscope.hpp

    include/Trixy/Neuro/Network/Base.hpp
    include/Trixy/Neuro/Network/Require.hpp
    include/Trixy/Neuro/Network/FeedForwardNet.hpp
    include/Trixy/Neuro/Network/UnifiedNet.hpp
    include/Trixy/Neuro/Network/Core.hpp

    include/Trixy/Neuro/Network/Layer/Base.hpp
    include/Trixy/Neuro/Network/Layer/Detail/FunctionDetail.hpp
    include/Trixy/Neuro/Network/Layer/Detail/MacroScope.hpp
    include/Trixy/Neuro/Network/Layer/Detail/MacroUnscope.hpp
    include/Trixy/Neuro/Network/Layer/FullyConnected.hpp
    include/Trixy/Neuro/Network/Layer/Convolutional.hpp
    include/Trixy/Neuro/Network/Layer/MaxPooling.hpp
    include/Trixy/Neuro/Network/Layer/Core.hpp

    include/Trixy/Neuro/Checker/Detail/MacroScope.hpp
    include/Trixy/Neuro/Checker/Detail/MacroUnscope.hpp
    include/Trixy/Neuro/Checker/Accuracy.hpp
    include/Trixy/Neuro/Checker/Core.hpp

    include/Trixy/Neuro/Functional/Function/Base.hpp
    include/Trixy/Neuro/Functional/Function/Activation.hpp
    include/Trixy/Neuro/Functional/Function/ActivationLess.hpp
    include/Trixy/Neuro/Functional/Function/Loss.hpp
    include/Trixy/Neuro/Functional/Function/Core.hpp

    include/Trixy/Neuro/Functional/Optimizer/Base.hpp
    include/Trixy/Neuro/Functional/Optimizer/GradDescent.hpp
    include/Trixy/Neuro/Functional/Optimizer/StoGradDescent.hpp
    include/Trixy/Neuro/Functional/Optimizer/Momentum.hpp
    include/Trixy/Neuro/Functional/Optimizer/Nestorov.hpp
    include/Trixy/Neuro/Functional/Optimizer/AdaGrad.hpp
    include/Trixy/Neuro/Functional/Optimizer/RMSProp.hpp
    include/Trixy/Neuro/Functional/Optimizer/Adam.hpp
    include/Trixy/Neuro/Functional/Optimizer/Interface.hpp
    include/Trixy/Neuro/Functional/Optimizer/Core.hpp

    include/Trixy/Neuro/Functional/Base.hpp
    include/Trixy/Neuro/Functional/Id.hpp
    include/Trixy/Neuro/Functional/FeedForwardNet.hpp
    include/Trixy/Neuro/Functional/Core.hpp

    include/Trixy/Neuro/Serializer/Base.hpp
    include/Trixy/Neuro/Serializer/FeedForwardNet.hpp
    include/Trixy/Neuro/Serializer/PolynomialRegression.hpp
    include/Trixy/Neuro/Serializer/LinearRegression.hpp
    include/Trixy/Neuro/Serializer/Core.hpp

    include/Trixy/Neuro/Regression/Base.hpp
    include/Trixy/Neuro/Regression/Require.hpp
    include/Trixy/Neuro/Regression/Linear.hpp
    include/Trixy/Neuro/Regression/Polynomial.hpp
    include/Trixy/Neuro/Regression/Core.hpp

    include/Trixy/Neuro/Training/Base.hpp
    include/Trixy/Neuro/Training/FeedForwardNet.hpp
    include/Trixy/Neuro/Training/UnifiedNet.hpp
    include/Trixy/Neuro/Training/LinearRegression.hpp
    include/Trixy/Neuro/Training/PolynomialRegression.hpp
    include/Trixy/Neuro/Training/Core.hpp

    include/Trixy/Neuro/Core.hpp
)
set(UTILS
    include/Utility/utility.hpp
    include/Utility/mnist_reader.hpp
    include/Utility/mnist_reader_common.hpp
)
add_executable(${PROJECT_NAME}
    ${TESTING}
    ${TRIXY_CONTAINER}
    ${TRIXY_LIQUE}
    ${TRIXY_ILIQUE}
    ${TRIXY_LOCKER}
    ${TRIXY_REQUIRE}
    ${TRIXY_BUFFER}
    ${TRIXY_RANGE}
    ${TRIXY_RANDOM}
    ${TRIXY_NEURO}
    ${UTILS}
)
