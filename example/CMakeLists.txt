project(
    example
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(example)

target_sources(example 
	PRIVATE 
		main.cpp
)

find_package(svglib)
IF (${svglib})
   MESSAGE(STATUS "Found svglib.")
ELSE (${svglib})
   MESSAGE(STATUS "Could not locate svglib.")
ENDIF (${svglib})

#target_link_libraries(example PUBLIC svglib)