cmake_minimum_required(VERSION 3.27)
project(Practice_2)

set(CMAKE_CXX_STANDARD 23)
set(SOURCE main.cpp usersFoo.cpp)
set(HEADERS users.h)
add_executable(Practice_2 ${SOURCE} ${HEADERS})
