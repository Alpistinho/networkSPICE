cmake_minimum_required(VERSION 3.5.1)

project (networkSPICE)

include_directories(include/spiceLib)

file(GLOB SPICELIB_SOURCES "src/spiceLib/*.cpp")

SET(CMAKE_CXX_FLAGS "-std=c++11 -O3")

add_executable(netSpice ${SPICELIB_SOURCES})
add_library(netSpiceShared SHARED ${SPICELIB_SOURCES})
add_library(netSpiceStatic STATIC ${SPICELIB_SOURCES})
