cmake_minimum_required(VERSION 3.10)

# set the project name
project(Tutorial)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Base)

# add the executable
add_executable(Tutorial main.cpp)

target_link_libraries(Tutorial PUBLIC Base)

target_include_directories(Tutorial PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/Base"
                          )