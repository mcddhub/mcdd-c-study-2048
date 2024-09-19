cmake_minimum_required(VERSION 3.28)
project(mcdd-c-study-2048 C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/.archive)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/.library)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/.runtime)

include_directories(${CMAKE_SOURCE_DIR}/include)
file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/src/*.c)
add_executable(run ${SOURCES})

set(CMOCKA_DIR "C:/Program Files (x86)/cmocka")
file(GLOB TEST_SOURCES ${CMAKE_SOURCE_DIR}/test/*.c ${CMAKE_SOURCE_DIR}/src/game.c)
add_executable(test ${TEST_SOURCES})
target_compile_options(test PRIVATE -std=c99 -g)
include_directories("${CMOCKA_DIR}/include")
target_link_libraries(test PRIVATE "${CMOCKA_DIR}/lib/libcmocka.dll.a")
set_target_properties(test PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/.runtime)
