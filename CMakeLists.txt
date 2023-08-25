cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

project (
    svglib
    VERSION 0.0
    DESCRIPTION "A C++ compile-time svg library"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    ${PROJECT_NAME}
    main.cpp
    src/color.hpp
    src/svglib.hpp
)