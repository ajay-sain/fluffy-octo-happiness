cmake_minimum_required(VERSION 3.27.3)

project(EDITOR VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)

configure_file(EditorConfig.h.in EditorConfig.h)

add_executable(${PROJECT_NAME}
        ./src/Application.cpp 
    )

include_directories(${CMAKE_CURRENT_BINARY_DIR})
