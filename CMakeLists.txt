cmake_minimum_required(VERSION 3.17)

project(MADE)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

include(gtest.cmake)

add_subdirectory("classify double")
add_subdirectory(test)
add_subdirectory(vector_operations)


