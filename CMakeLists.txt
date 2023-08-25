cmake_minimum_required(VERSION 3.23.0 FATAL_ERROR)

project (
    cpp-svglib
    VERSION 0.0
    DESCRIPTION "A C++ compile-time svg library"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src/svglib)
add_subdirectory(src/example)

set_target_properties(svglib PROPERTIES LINKER_LANGUAGE CXX)