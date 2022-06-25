cmake_minimum_required(VERSION 3.5.1)

# set the project name
project(Benchmark LANGUAGES CUDA CXX)
set(CMAKE_CXX_STANDARD 17)

set(CUDA_SEPARABLE_COMPILATION ON)

add_subdirectory(Base)
add_subdirectory(Parallel)

# add the executable
add_executable(Benchmark.out main.cpp)
set_source_files_properties(main.cpp PROPERTIES LANGUAGE CUDA)

set_target_properties(Base PROPERTIES LINKER_LANGUAGE CUDA)
set_target_properties(Parallel PROPERTIES LINKER_LANGUAGE CUDA)
target_link_libraries(Benchmark.out PUBLIC Base Parallel)

target_include_directories(Benchmark.out PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/Base"
                          "${PROJECT_SOURCE_DIR}/Parallel"
                          )