

if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/build/libmath.a)

add_library(math STATIC IMPORTED)

set_target_properties(math PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/build/libmath.a)

else()

file(GLOB SOURCES ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp)

add_library(math STATIC ${SOURCES})

endif()
target_include_directories(math INTERFACE  ${CMAKE_CURRENT_LIST_DIR}/include)
target_link_directories(math INTERFACE ${CMAKE_CURRENT_LIST_DIR}/build)

set(math_libs math)