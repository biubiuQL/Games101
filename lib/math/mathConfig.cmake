

# 通过当前CmakeLists.txt文件目录构建的
if(${CMAKE_SOURCE_DIR} STREQUAL  ${CMAKE_CURRENT_LIST_DIR})
message(111)
file(GLOB SOURCES ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp)
add_library(math STATIC ${SOURCES})

# 不是通过当前CmakeLists.txt文件目录构建的（表示别人引用当前库）
else()

if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/build/libmath.a)

add_library(math STATIC IMPORTED)
set_target_properties(math PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/build/libmath.a)
target_link_directories(math INTERFACE ${CMAKE_CURRENT_LIST_DIR}/build)

else()

file(GLOB SOURCES ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp)
add_library(math STATIC ${SOURCES})
# 设置生成的库的输出目录
set_target_properties(math PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/math)

endif()

target_include_directories(math INTERFACE  ${CMAKE_CURRENT_LIST_DIR}/include)
set(math_libs math)

endif()


