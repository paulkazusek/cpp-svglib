cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

project(
    svglib
    VERSION 0.0.1
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

FUNCTION(PREPEND var )
   SET(listVar "")
   FOREACH(f ${${var}})
       LIST(APPEND listVar "${CMAKE_CURRENT_SOURCE_DIR}/${f}")
   ENDFOREACH(f)
   SET(${var} "${listVar}" PARENT_SCOPE)
ENDFUNCTION(PREPEND)

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib")

add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(example)

add_library(svglib STATIC ${svglib_SRC} ${svglib_INC})

set(svglib_INCLUDE_DEST "include")
set(svglib_LIB_DEST "lib")

set_target_properties(svglib PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(svglib 
	PUBLIC
        #$<BUILD_INTERFACE:${svglib_SRC_DIR}/include> 
		#$<INSTALL_INTERFACE:include> 
        $<BUILD_INTERFACE:${CMakeDemo_SOURCE_DIR}/include> 
        $<BUILD_INTERFACE:${CMakeDemo_BINARY_DIR}/include> 
        $<INSTALL_INTERFACE:include> 
)

return()

install(
    # targets to install
    TARGETS svglib 
    # name of the CMake "export group" containing the targets we want to install
    EXPORT svglibTargets
    # Dynamic, static library and include destination locations after running
    # "make install"
    LIBRARY DESTINATION ${svglib_LIB_DEST}
    ARCHIVE DESTINATION ${svglib_LIB_DEST} 
    INCLUDES DESTINATION ${svglib_INCLUDE_DEST}
)

install(
    # The export we want to save (matches name defined above containing the
    # install targets)
    EXPORT svglibTargets
    # CMake file in which to store the export's information
    FILE  svglibTargets.cmake
    # Namespace prepends all targets in the export (when we import later, we
    # will use CMakeDemo::CMakeDemo)
    NAMESPACE svglib::
    # where to place the resulting file (here, we're putting it with the library)
    DESTINATION ${svglib_LIB_DEST}
)

install(FILES ${svglib_INC} DESTINATION ${svglib_INCLUDE_DEST})

include(CMakePackageConfigHelpers)

install(
    FILES 
        "cmake/svglib-config.cmake"
    DESTINATION ${svglib_LIB_DEST}
)

message(STATUS "CMAKE_CURRENT_SOURCE_DIR : ${CMAKE_CURRENT_SOURCE_DIR}")

#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/CMake")

#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${svglib_SOURCE_DIR})

#list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
#list(APPEND CMAKE_PREFIX_PATH "")

#message(STATUS "CMAKE_PREFIX_PATH : ${CMAKE_PREFIX_PATH}")
#message(STATUS "CMAKE_MODULE_PATH : ${CMAKE_MODULE_PATH}")
#message(STATUS "PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")
#message(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
#message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")

#list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

#include(cmake/svglib-config.cmake)
#include(cmake/Findsvglib.cmake)
