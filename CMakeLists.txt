cmake_minimum_required(VERSION 3.22)
project(Code)

set(CMAKE_CXX_STANDARD  14)
set(CMAKE_BUILD_TYPE Debug)

add_executable(Code main.cpp Movie.cpp personen.cpp test.cpp Wordsequence.h zahlen.cpp)