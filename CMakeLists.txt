cmake_minimum_required(VERSION 3.9)
project(MPI)

set(CMAKE_CXX_STANDARD 11)

add_executable(MPI main.cpp main.cpp)

include_directories(../../mpich-install/include/)
set(CMAKE_CXX_COMPILER "../../../mpich-install/bin/mpic++")