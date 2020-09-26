add_executable(vector_test test/test.cpp)
target_include_directories(vector_test PUBLIC src)

set(CMAKE_CXX_FLAGS "-fconcepts")