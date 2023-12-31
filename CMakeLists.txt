cmake_minimum_required(VERSION 3.20.0...3.27.0 FATAL_ERROR)

project(
    svglib
    VERSION 0.0.1
    LANGUAGES CXX)

# -----------------------------------------------------------------------------
# Compiler config
# -----------------------------------------------------------------------------

if(NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

#set(CMAKE_CXX_EXTENSIONS OFF)

# -----------------------------------------------------------------------------
# Header only
# -----------------------------------------------------------------------------

add_library(${PROJECT_NAME} INTERFACE)

target_sources(${PROJECT_NAME} INTERFACE)

include(GNUInstallDirs)

target_include_directories(
    ${PROJECT_NAME} INTERFACE 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
        #$<INSTALL_INTERFACE:include/>)

#target_compile_definitions(${PROJECT_NAME} PRIVATE -D_EXPORT)

set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "d")

# -----------------------------------------------------------------------------
# Install
# -----------------------------------------------------------------------------

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

# -----------------------------------------------------------------------------
# Options
# -----------------------------------------------------------------------------

option(SVGLIB_BUILD_EXAMPLES "examples should be built" ON)

if(SVGLIB_BUILD_EXAMPLES)
    add_subdirectory(example)
endif()