 
cmake_minimum_required (VERSION 2.6)

project (lesson4)

include_directories(include)

file(GLOB sources src/*.cpp)

add_executable(lesson4 ${sources})
