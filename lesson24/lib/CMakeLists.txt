cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(DTLib)

set(INCLUDE_PATH "./")
include_directories(${INCLUDE_PATH})

aux_source_directory("." M_SRC)
file(GLOB H_FILE "${INCLUDE_PATH}/*.h")

add_library(${PROJECT_NAME} STATIC ${M_SRC} ${H_FILE})
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_PATH})
