cmake_minimum_required(VERSION 3.15)
project(PixelGame)

set(CMAKE_CXX_STANDARD 17)

# 添加 raylib 子模块
add_subdirectory(external/raylib)

# 添加源文件
file(GLOB_RECURSE SOURCES
    src/*.cpp
)

add_executable(pixel ${SOURCES})

# 头文件路径（可选）
target_include_directories(pixel PRIVATE src/include)

# 链接 raylib
target_link_libraries(pixel raylib)

# Linux 需要链接这些系统库
if(UNIX AND NOT APPLE)
    target_link_libraries(pixel m pthread dl GL X11)
endif()

