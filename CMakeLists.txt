cmake_minimum_required(VERSION 3.13)
project(CBase)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CBase
        CBase.cpp
        CPlusBase.cpp CPlusBase1.cpp CPlusBase1.h)
