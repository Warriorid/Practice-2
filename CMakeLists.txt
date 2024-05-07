cmake_minimum_required(VERSION 3.27)
project(Practice_2)

set(CMAKE_CXX_STANDARD 23)
set(SOURCE main.cpp usersFoo.cpp Graphic/Graphic.cpp)
set(HEADERS users.h userFunc.h Graphic/Graphic.h)
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)
add_executable(Practice_2 ${SOURCE} ${HEADERS})
target_link_libraries(Practice_2 sfml-graphics sfml-window sfml-system)
