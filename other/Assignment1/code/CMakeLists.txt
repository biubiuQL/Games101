cmake_minimum_required(VERSION 3.10)
project(main)

set(OpenCV_DIR "../../../Library/compile-opencv/install/x64/mingw/lib")
find_package(OpenCV 4.9.0 REQUIRED)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE Debug)
include_directories(${OpenCV_INCLUDE_DIRS} "../../../Library/eigen-3.4.0")

add_executable(main main.cpp )

link_directories("C:\\Program Files\\mingw64\\lib")

target_link_libraries(main ${OpenCV_LIBRARIES})
