cmake_minimum_required(VERSION 3.5)

project(Trixy LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(TESTING
    src/simple_test.cpp
    src/mnist_test.cpp
    src/speed_test.cpp
)
set(TRIXY_COLLECTION
    include/Trixy/Container/container.hpp
    include/Trixy/Container/icontainer.hpp
)
set(TRIXY_LIQUE
    include/Trixy/Lique/lique_linear.hpp
    include/Trixy/Lique/lique_matrix.hpp
    include/Trixy/Lique/lique_vector.hpp
    include/Trixy/Lique/lique_core.hpp
)
set(TRIXY_ILIQUE
    include/Trixy/ILique/ilique_base.hpp
    include/Trixy/ILique/ilique_linear.hpp
    include/Trixy/ILique/ilique_matrix.hpp
    include/Trixy/ILique/ilique_vector.hpp
    include/Trixy/ILique/ilique_core.hpp
)
set(TRIXY_NEURO
    include/Trixy/Neuro/Detail/neuro_meta.hpp
    include/Trixy/Neuro/Detail/neuro_function_id.hpp
    include/Trixy/Neuro/Network/feedforward_neuro.hpp
    include/Trixy/Neuro/Network/feedforward_neuro_less.hpp
    include/Trixy/Neuro/Functional/Function/neuro_activation.hpp
    include/Trixy/Neuro/Functional/Function/neuro_loss.hpp
    include/Trixy/Neuro/Functional/Function/neuro_optimization.hpp
    include/Trixy/Neuro/Functional/feedforward_neuro_functional.hpp
    include/Trixy/Neuro/Functional/base_functional.hpp
    include/Trixy/Neuro/Serialization/feedforward_neuro_serializer.hpp
    include/Trixy/Neuro/Serialization/base_serializer.hpp
    include/Trixy/Neuro/neuro_core.hpp
)
set(MNIST_MASTER
    include/MnistMaster/mnist_reader.hpp
    include/MnistMaster/mnist_reader_common.hpp
)
set(UTILS
    include/Utility/util.hpp
)

add_executable(${PROJECT_NAME}
    ${TRIXY_COLLECTION}
    ${TRIXY_LIQUE}
    ${TRIXY_ILIQUE}
    ${TRIXY_NEURO}
    ${MNIST_MASTER}
    ${TIMER}
    ${UTILS}
    ${TESTING}
)
