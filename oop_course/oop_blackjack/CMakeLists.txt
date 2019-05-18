cmake_minimum_required(VERSION 3.14)
project(oop_blackjack)

set(CMAKE_CXX_STANDARD 11)

add_executable(oop_blackjack main.cpp card.h player.h game.h card.cpp game.cpp player.cpp)