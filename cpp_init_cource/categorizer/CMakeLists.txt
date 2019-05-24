CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(categorizer)

set(CMAKE_CXX_FLAGS "-std=c++14")

file(GLOB sources "src/*.cpp")

add_executable(categorizer ${sources})

target_include_directories(categorizer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
