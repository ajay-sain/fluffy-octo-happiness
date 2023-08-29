cmake_minimum_required(VERSION 3.27.3)

project(EDITOR VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SRC_FILES 
        "./include/*.hpp" 
        "./src/*.cpp"
    )

configure_file(EditorConfig.h.in EditorConfig.h)

add_executable(${PROJECT_NAME}
        ${SRC_FILES}
    )

include_directories(${CMAKE_CURRENT_BINARY_DIR})
