cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name
project(ca_homework_1 LANGUAGES CXX)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(BINARY_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

set(SOURCE_FILES
        main.cpp

        container.cpp
        container.h

        movie.cpp
        movie.h

        fiction.cpp
        fiction.h

        utils.h
        utils.cpp

        cartoon.cpp
        cartoon.h

        documentary.cpp
        documentary.h)

add_executable(ca_homework_1 ${SOURCE_FILES})
