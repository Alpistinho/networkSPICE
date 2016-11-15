cmake_minimum_required(VERSION 3.5.1)

include(FindProtobuf)
find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIR})

file(GLOB PROTO_DEFINITIONS "../messages/*.proto")

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_DEFINITIONS})

add_library(messages STATIC ${PROTO_SRCS} ${PROTO_HDRS})

set_target_properties(messages PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/messages)

target_link_libraries(messages ${PROTOBUF_LIBRARY})