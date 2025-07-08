# [[Root]]
cmake_minimum_required(VERSION 3.5)

project(Trixy)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Trixy - header only library, just use target_include_directories


# [[Tests]]
if(PROJECT_IS_TOP_LEVEL)
    add_subdirectory("test")
endif()