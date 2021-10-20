cmake_minimum_required(VERSION 3.5)

project(Trixy LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCES src/test.cpp)
set(TRIXY_COLLECTION include/Trixy/Collection/collection.hpp)
set(TRIXY_LIQUE
    include/Trixy/Lique/ilique_base.hpp
    include/Trixy/Lique/ilique_linear.hpp
    include/Trixy/Lique/ilique_matrix.hpp
    include/Trixy/Lique/ilique_vector.hpp
    include/Trixy/Lique/lique_linear.hpp
    include/Trixy/Lique/lique_matrix.hpp
    include/Trixy/Lique/lique_vector.hpp
)
set(TRIXY_NEURO
    include/Trixy/Neuro/neuro_core.hpp
    include/Trixy/Neuro/neuro_functional.hpp
    include/Trixy/Neuro/neuro_optimizer.hpp
)
set(MNIST_MASTER
    include/MnistMaster/mnist_reader.hpp
    include/MnistMaster/mnist_reader_common.hpp
    include/MnistMaster/mnist_utils.hpp
)
set(TIMER include/Timer/timer.h)

add_executable(Trixy
    ${SOURCES}
    ${TRIXY_COLLECTION}
    ${TRIXY_LIQUE}
    ${TRIXY_NEURO}
    ${MNIST_MASTER}
    ${TIMER}
)
