#project(
#    example
#    LANGUAGES CXX)

#set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)

#find_package(svglib REQUIRED CONFIG)

#add_executable(${PROJECT_NAME})
#target_sources(${PROJECT_NAME} PRIVATE main.cpp)

#target_link_libraries(${PROJECT_NAME}
#                      PUBLIC svglib::svglib)

#if(WIN32)
#    # copy the .dll file to the same folder as the executable
#    add_custom_command(
#        TARGET ${PROJECT_NAME}
#        POST_BUILD
#        COMMAND
#            ${CMAKE_COMMAND} -E copy_directory
#            $<TARGET_FILE_DIR:svglib::svglib>
#            $<TARGET_FILE_DIR:${PROJECT_NAME}>
#        VERBATIM)
#endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(example main.cpp)
target_link_libraries(example PUBLIC svglib)