cmake_minimum_required(VERSION 3.16)
project(kirsh)

set(CMAKE_CXX_STANDARD 20)

find_package(Threads REQUIRED)

file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/*.cc")
list(FILTER SOURCES EXCLUDE REGEX ".*/CMakeFiles/.*")

add_executable(kirsh ${SOURCES})

target_include_directories(kirsh PRIVATE
    ${CMAKE_SOURCE_DIR}/src/
)
target_link_libraries(kirsh PRIVATE Threads::Threads)
