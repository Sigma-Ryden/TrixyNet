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
    include/Trixy/Neuro/Function/neuro_function_id.hpp
    include/Trixy/Neuro/Function/neuro_activation.hpp
    include/Trixy/Neuro/Function/neuro_loss.hpp
    include/Trixy/Neuro/Function/neuro_optimization.hpp
    include/Trixy/Neuro/neuro_serializer.hpp
    include/Trixy/Neuro/Detail/neuro_meta.hpp

)
set(MNIST_MASTER
    include/MnistMaster/mnist_reader.hpp
    include/MnistMaster/mnist_reader_common.hpp
)
set(TIMER
    include/Timer/timer.h
)

set(UTILS
    include/Utility/util.hpp
)

add_executable(${PROJECT_NAME}
    ${TRIXY_COLLECTION}
    ${TRIXY_LIQUE}
    ${TRIXY_NEURO}
    ${MNIST_MASTER}
    ${TIMER}
    ${UTILS}
    ${TESTING}
)
