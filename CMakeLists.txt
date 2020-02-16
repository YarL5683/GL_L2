cmake_minimum_required(VERSION 3.0) #Chech Cmake vercion

project(Calc)


set(SOURCE_EXE Main.cpp)

set(SOURCE_LIB Calculator.cpp)

add_library(Calc STATIC ${SOURCE_LIB})
add_executable(Main ${SOURCE_EXE})

target_link_libraries(Main Calc) #Link main&calc lib
