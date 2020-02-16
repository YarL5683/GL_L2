cmake_minimum_required(VERSION 3.0) #Check Cmake version

project(Calculator) # Project name

#Set variable
set(SOURCE_EXE Main.cpp)
set(SOURCE_LIB Calculator.cpp)

#Add executable file & library
add_executable(Main ${SOURCE_EXE})
add_library(Calc STATIC ${SOURCE_LIB})

set(CMAKE_CXX_STANDARD 11) #Set C++ version

#Link program & library
target_link_libraries(Main Calc)