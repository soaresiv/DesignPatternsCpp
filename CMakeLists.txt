cmake_minimum_required(VERSION 3.12)

# project has both C and CPP sources
project(vxdrm C CXX)

# define compilers
set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)

add_subdirectory(SOLID-DesignPrinciples)
