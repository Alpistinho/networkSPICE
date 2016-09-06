cmake_minimum_required(VERSION 3.5.1)

project (networkSPICE)

include_directories(spiceLib)

file(GLOB SOURCES "spiceLib/*.cpp")

SET(CMAKE_CXX_FLAGS "-std=c++11")

add_executable(netSpice ${SOURCES})
