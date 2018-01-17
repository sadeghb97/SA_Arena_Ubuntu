cmake_minimum_required(VERSION 2.6)
project(arenacpp)

add_executable(arenacpp main.cpp generals.cpp input.cpp match.cpp print.cpp)

install(TARGETS arenacpp RUNTIME DESTINATION bin)
