cmake_minimum_required(VERSION 3.10)

set(COMMON_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../../common)
message("COMMON_DIRECTORY:" ${COMMON_DIRECTORY})
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRCS)


add_library(core ${SRCS})

target_include_directories(core PUBLIC ${COMMON_DIRECTORY})
target_link_libraries(core PUBLIC avformat PUBLIC avutil PUBLIC avcodec)
