file(GLOB SOURCES ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp)
add_library(math STATIC IMPORTED)



set_target_properties(math PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/build/libmath.a)

# add_library(math STATIC ${CMAKE_CURRENT_LIST_DIR}/build)
# target_link_directories(math PUBLIC ${CMAKE_CURRENT_LIST_DIR}/build)
target_include_directories(math PUBLIC  ${CMAKE_CURRENT_LIST_DIR}/include)

set(math_libs math)