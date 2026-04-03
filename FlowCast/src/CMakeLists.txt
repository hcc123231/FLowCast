cmake_minimum_required(VERSION 3.10)

set(CORE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/core)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRCS)



add_executable(fc ${SRCS})

target_include_directories(fc PRIVATE ${CORE_DIRECTORY})
target_link_directories(fc PRIVATE ${CORE_DIRECTORY})
target_link_libraries(fc PRIVATE core)
add_subdirectory(${CORE_DIRECTORY})