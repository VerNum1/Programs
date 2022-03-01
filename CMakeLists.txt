cmake_minimum_required(VERSION 3.20)
project(untitled3 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled3 main.c libs/data_structures/matrix/matrix.c libs/data_structures/matrix/matrix.h libs/string/string_.c libs/string/string_.h)

add_subdirectory(libs)
target_link_libraries(untitled3 data_structures)
target_link_libraries(untitled3 algorithms)
target_link_libraries(untitled3 string)