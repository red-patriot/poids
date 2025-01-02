cmake_minimum_required(VERSION 3.24)

project(poids
    DESCRIPTION "A generic units and quantities library"
    VERSION 0.3.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_subdirectory("lib")
add_subdirectory("test")