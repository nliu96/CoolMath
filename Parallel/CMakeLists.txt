add_library(Parallel STATIC gpu_vector.h add.cu)

set_source_files_properties(add.cu gpu_vector.h add.cu PROPERTIES LANGUAGE CUDA)
target_link_libraries(Parallel PUBLIC Base)