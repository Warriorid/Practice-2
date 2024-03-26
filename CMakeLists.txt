cmake_minimum_required(VERSION 3.27)
project(Practice_2)

set(CMAKE_CXX_STANDARD 23)
set(SOURCE main.cpp usersFoo.cpp)
set(HEADERS users.h userFunc.h)
add_executable(Practice_2 ${SOURCE} ${HEADERS})
find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})
add_definitions(${GTKMM_CFLAGS_OTHER})

target_link_libraries(Practice_2 ${GTKMM_LIBRARIES})