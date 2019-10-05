cmake_minimum_required(VERSION 3.12)
project(EPLab2_STL_)

set(CMAKE_CXX_STANDARD 14)

include_directories(vectorInt)

add_executable(EPLab2_STL_
        vectorInt/Condition.cpp
        vectorInt/Condition.h
        vectorInt/fileLib.cpp
        vectorInt/fileLib.h
        vectorInt/Numbers.cpp
        vectorInt/Numbers.h
        vectorInt/Source.cpp
        vectorString/Source.cpp)
