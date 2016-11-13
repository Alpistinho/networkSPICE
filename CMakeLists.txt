cmake_minimum_required(VERSION 3.5.1)

project (networkSPICE)

file(GLOB SPICELIB_SOURCES "src/spiceLib/*.cpp")

file(GLOB SIMULATIONNODE_SOURCES "src/simulationNode/*.cpp")

SET(CMAKE_CXX_FLAGS "-std=c++11 -O3")

add_executable(netSpice ${SPICELIB_SOURCES})
add_library(netSpiceShared SHARED ${SPICELIB_SOURCES})
add_library(netSpiceStatic STATIC ${SPICELIB_SOURCES})

target_include_directories(netSpice PRIVATE include/spiceLib)
target_include_directories(netSpiceShared PRIVATE include/spiceLib)
target_include_directories(netSpiceStatic PRIVATE include/spiceLib)

add_executable(simulationNode ${SIMULATIONNODE_SOURCES})
target_include_directories(simulationNode PRIVATE include/spiceLib)

Target_Link_Libraries(simulationNode ${CMAKE_SOURCE_DIR}/build/libnetSpiceStatic.a)