#project(
#    example
#    LANGUAGES CXX)

#set(CMAKE_CXX_STANDARD 20)

add_executable(example main.cpp)
target_link_libraries(example PUBLIC svglib)