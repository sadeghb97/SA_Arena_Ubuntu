cmake_minimum_required(VERSION 2.6)
project(arenacpp)

add_executable(arenacpp main.cpp generals.cpp input.cpp print.cpp match.cpp team.cpp)

install(TARGETS arenacpp RUNTIME DESTINATION bin)
