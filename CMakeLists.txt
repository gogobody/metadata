cmake_minimum_required(VERSION 3.15)
project(metadata LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11 )
set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -std=c++11 -lpthread -lm")
set(CMAKE_EXE_LINKER_FLAGS "-lpthread -lm")
set(CMAKE_C_FLAGS "-std=c++11 -Wall -Wpointer-arith -fPIC")

include_directories(core)
include_directories(common)
include_directories(src)

AUX_SOURCE_DIRECTORY(core source)
AUX_SOURCE_DIRECTORY(common source)
AUX_SOURCE_DIRECTORY(src source)

# cmake 将所有c文件视为c++文件
file(GLOB_RECURSE CFILES "${CMAKE_SOURCE_DIR}/*.c")
SET_SOURCE_FILES_PROPERTIES(${CFILES} PROPERTIES LANGUAGE CXX )

add_executable(metadata main.cpp ${source}  )