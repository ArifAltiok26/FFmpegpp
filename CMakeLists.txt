cmake_minimum_required(VERSION 3.22)

get_filename_component(PROJECT_ID ${CMAKE_CURRENT_SOURCE_DIR} NAME)

project(${PROJECT_ID} VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wno-unused-parameter")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS_DEBUG "-g")

add_compile_definitions("DEBUG=$<CONFIG:Debug>")


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake_modules")

find_package(FFmpeg REQUIRED)

include_directories(${FFmpeg_INCLUDE_DIRS})
include_directories(src)

file(GLOB SrcFiles
    src/allocators/*.cpp
    src/executors/*.cpp
    src/data_types/.*cpp
)

set(
    PROJECT_LIBS
    ${FFmpeg_LIBS}
)

if(BUILD_SHARED_LIBS)
    add_library(${PROJECT_NAME} SHARED ${SrcFiles})
else()
    add_library(${PROJECT_NAME} ${SrcFiles})
endif()

target_link_libraries(${PROJECT_NAME} ${PROJECT_LIBS})