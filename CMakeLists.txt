cmake_minimum_required(VERSION 3.13)
project(CBase)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CBase
        CBase.cpp
        CPlusBase.cpp CPlusBase1.cpp ArrayList.cpp Instance.cpp StructAndClass.cpp StructAndClass.h FrendTest.cpp FrendTest.h FirendParent.cpp FirendParent.h FirendTest2.cpp FirendTest2.h)
