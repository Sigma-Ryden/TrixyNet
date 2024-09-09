cmake_minimum_required(VERSION 3.5)

project(TrixyNet LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE TRIXY_NET_HEADERS include/TrixyNet/*.hpp)
file(GLOB_RECURSE AUTOMATION_SOURCES include/Automation/*.cpp)

set(TRIXY_NET_TESTING_SOURCE
   # test/mnist_test.cpp
   # test/regression_test.cpp
   test/simple_test.cpp
   # test/auto_tests.cpp
)

add_executable(${PROJECT_NAME} ${TRIXY_NET_HEADERS} ${AUTOMATION_SOURCES} ${TRIXY_NET_TESTING_SOURCE})
target_include_directories(${PROJECT_NAME} PUBLIC include PRIVATE test)
