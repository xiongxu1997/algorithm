cmake_minimum_required(VERSION 3.24)
project(project1)

set(CMAKE_CXX_STANDARD 17)

add_executable(project1 main.cpp "link_operations.cpp" binary_tree_operations.cpp)
