cmake_minimum_required(VERSION 3.10)

project(${ProjectName})

# 库的根目录目录
set(lib_dir ${CMAKE_SOURCE_DIR}/../../../lib)

find_package(OpenCV 4.9.0 REQUIRED)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE Debug)

add_executable(${ProjectName} main.cpp)

# 添加eigen头文件路径
target_include_directories(${ProjectName} PRIVATE ${lib_dir}/eigen-3.4.0 ${lib_dir}/eigen-3.4.0/Eigen)

# OpenCV_LIBRARIES
target_link_libraries(${ProjectName} ${OpenCV_LIBS})
