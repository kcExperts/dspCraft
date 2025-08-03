cmake_minimum_required(VERSION 3.17 FATAL_ERROR)

project(dspCraft CXX)

set(HEADER
    src/defines.h
    src/items.h
    src/parser.h
    src/parser.cpp
    src/cli.h
    src/cli.cpp
    src/main.cpp
)

set(SOURCE
)

include_directories(headers)

add_executable(dspCraft ${HEADER} ${SOURCE})
target_link_libraries(dspCraft)