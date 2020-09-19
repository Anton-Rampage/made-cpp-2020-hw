add_library(check_double STATIC solution.c)
target_include_directories(check_double PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})