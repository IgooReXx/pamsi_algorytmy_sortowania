cmake_minimum_required(VERSION 3.16)
project(PAMSIproj2)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall -Wextra -pedantic)
add_executable(PAMSIproj2 main.cpp read.cpp read.h movieEntry.cpp movieEntry.h get_key.cpp get_key.h shuffle.cpp shuffle.h merge_sort.cpp merge_sort.h bucket_sort.cpp bucket_sort.h quick_sort.cpp quick_sort.h)
