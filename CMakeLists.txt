cmake_minimum_required(VERSION 3.8)
project(jnp1_Christmass_tree)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        ChristmasTree.cc
        decoration.cc
        decoration.h
        person.cc
        person.h
        helper.cc
        helper.h)

add_executable(jnp1_Christmass_tree ${SOURCE_FILES})
add_executable(main main.cpp)