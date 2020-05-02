cmake_minimum_required (VERSION 3.16.0)

#指定用C++ 11编译
set(CMAKE_CXX_STANDARD 11)
#增加调试选项
add_definitions("-Wall -g")

project (20-valid-parentheses)
# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# find_file(SDL2_INCLUDE_DIR NAME SDL.h HINTS SDL)
# find_library(SDL2_LIBRARY NAME SDL)
find_package(GTest REQUIRED)
if(GTest_FOUND)
    message("GTest found")
endif(GTest_FOUND)

message("GTest_LIBRARIES"${GTEST_LIBRARIES})
message("GTest_INCLUDE_DIR"${GTEST_INCLUDE_DIRS})

add_executable(20-valid-parentheses ${DIR_SRCS})

# 添加依赖的头文件目录
target_include_directories(20-valid-parentheses PRIVATE 
            ${GTEST_INCLUDE_DIRS})
            
# 添加链接库
target_link_libraries(20-valid-parentheses 
        ${GTEST_LIBRARIES})    