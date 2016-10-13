cmake_minimum_required(VERSION 2.6)
project(systeme_expert)

add_definitions(-std=c++1y -ggdb -O3)
add_executable(systeme_expert Variable.cpp Predicat.cpp Regle.cpp main.cpp)

install(TARGETS systeme_expert RUNTIME DESTINATION bin)

SET(CMAKE_CXX_FLAGS "-std=c++1y")