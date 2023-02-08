cmake_minimum_required(VERSION 3.14)
project(ft_containers)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

#include(FetchContent)
#FetchContent_Declare(
#  googletest
#  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
#)
#FetchContent_MakeAvailable(googletest)

# Directories for header files
# include_directories(srcs/iterators)
# include_directories(srcs/utils)
include_directories(./ft_containers/srcs)

# Directories for source files
add_subdirectory(tests)
add_subdirectory(./googletest)