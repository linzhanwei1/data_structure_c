cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(main LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

add_subdirectory(./lib)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC DTLib)

