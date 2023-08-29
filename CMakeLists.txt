cmake_minimum_required(VERSION 3.20.0...3.27.0 FATAL_ERROR)

project(
    svglib
    VERSION 0.0.1
    LANGUAGES CXX)

#include(CheckCXXCompilerFlag)
#CHECK_CXX_COMPILER_FLAG("-std=c++20" COMPILER_SUPPORTS_CXX20)
#if(COMPILER_SUPPORTS_CXX20)
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
#elseif(COMPILER_SUPPORTS_CXX0X)
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
#else()
#        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++20 support. Please use a different C++ compiler.")
#endif()

#set (CMAKE_CXX_FLAGS "-std=c++20 ${CMAKE_CXX_FLAGS}")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME} PRIVATE src/color.cpp)

include(GNUInstallDirs)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

target_compile_definitions(${PROJECT_NAME} PRIVATE -D_EXPORT)

set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "d")

install(
    TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}-config
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(
    EXPORT ${PROJECT_NAME}-config
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})

install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/${PROJECT_NAME}/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})

option(SVGLIB_BUILD_EXAMPLES "examples should be built" ON)
if(SVGLIB_BUILD_EXAMPLES)
    add_subdirectory(example)
endif()