cmake_minimum_required(VERSION 3.28)
project(mcdd-c-study-2048 C CXX)

# 设置 C 和 C++ 标准
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 20)

# 设置输出目录
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/.archive)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/.library)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/.runtime)

# 设置源文件
set(SOURCES game.c main.c)

# 添加可执行文件 run.exe
add_executable(run ${SOURCES})

# 定义 CMocka 库的根目录
set(CMOCKA_DIR "C:/Program Files (x86)/cmocka")

# 添加测试文件的编译和链接
set(TEST_SOURCES test.c game.c)
add_executable(test ${TEST_SOURCES})

# 设置调试选项
target_compile_options(test PRIVATE -std=c99 -g)

# 包含 CMocka 的头文件路径
include_directories("${CMOCKA_DIR}/include")

# 链接 CMocka 库
target_link_libraries(test PRIVATE "${CMOCKA_DIR}/lib/libcmocka.dll.a")

# 设置输出路径
set_target_properties(test PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/.runtime)
