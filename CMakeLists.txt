cmake_minimum_required(VERSION 3.5.1)
#name of the project
project (networkSPICE)

include(FindProtobuf)
find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIR})

#represent the files
file(GLOB SPICELIB_SOURCES "src/spiceLib/*.cpp")

file(GLOB SIMULATIONNODE_SOURCES "src/simulationNode/*.cpp")

file(GLOB MESSAGES_SOURCES "src/messages/*.cc")

SET(CMAKE_CXX_FLAGS "-std=c++11")

add_executable(netSpice ${SPICELIB_SOURCES})
add_library(netSpiceShared SHARED ${SPICELIB_SOURCES})
add_library(netSpiceStatic STATIC ${SPICELIB_SOURCES})


target_include_directories(netSpice PRIVATE include/spiceLib)

target_include_directories(netSpiceShared PRIVATE include/spiceLib)

target_include_directories(netSpiceStatic PRIVATE include/spiceLib)


add_executable(simulationNode ${SIMULATIONNODE_SOURCES} ${MESSAGES_SOURCES})
target_include_directories(simulationNode PRIVATE include/spiceLib)
target_include_directories(simulationNode PRIVATE src/messages)

Target_Link_Libraries(simulationNode ${CMAKE_SOURCE_DIR}/build/libnetSpiceStatic.a ${CMAKE_THREAD_LIBS_INIT} ${PROTOBUF_LIBRARY})
