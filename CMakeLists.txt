cmake_minimum_required(VERSION 3.8)
project(dustbin)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(dustbin ${SOURCE_FILES})

include_directories(waste_recycling)

add_subdirectory(waste_recycling)
add_subdirectory(waste_recycling_tests)

target_link_libraries(dustbin waste_recycling)