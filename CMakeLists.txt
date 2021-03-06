cmake_minimum_required(VERSION 2.8)
#name of the project
project (networkSPICE)

find_package (Threads)

add_subdirectory(${CMAKE_SOURCE_DIR}/messages ${CMAKE_SOURCE_DIR}/build/messages)

#represent the files
file(GLOB SPICELIB_SOURCES "src/spiceLib/*.cpp")

file(GLOB SIMULATIONNODE_SOURCES "src/simulationNode/src/*.cpp")

SET(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/bin)


add_library(netSpiceShared SHARED ${SPICELIB_SOURCES})
add_library(netSpiceStatic STATIC ${SPICELIB_SOURCES})
add_executable(netSpice ${SPICELIB_SOURCES})
add_executable(simulationNode ${SIMULATIONNODE_SOURCES})


target_include_directories(netSpice PRIVATE ${CMAKE_SOURCE_DIR}/include/spiceLib)
target_include_directories(netSpiceShared PRIVATE ${CMAKE_SOURCE_DIR}/include/spiceLib)
target_include_directories(netSpiceStatic PRIVATE ${CMAKE_SOURCE_DIR}/include/spiceLib)
target_include_directories(simulationNode PRIVATE ${CMAKE_SOURCE_DIR}/include/spiceLib)
target_include_directories(simulationNode PRIVATE ${CMAKE_SOURCE_DIR}/include/zmq)
target_include_directories(simulationNode PRIVATE ${CMAKE_SOURCE_DIR}/src/simulationNode/include)
target_include_directories(simulationNode PRIVATE ${CMAKE_SOURCE_DIR}/build/messages)



MESSAGE( STATUS "CMAKE_SOURCE_DIR: " ${CMAKE_SOURCE_DIR})

Target_Link_Libraries(simulationNode netSpiceStatic messages ${CMAKE_THREAD_LIBS_INIT} ${CMAKE_SOURCE_DIR}/lib/libzmq-static.a ${PROTOBUF_LIBRARY} ${CMAKE_THREAD_LIBS_INIT})
