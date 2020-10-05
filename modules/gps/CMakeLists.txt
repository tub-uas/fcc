cmake_minimum_required(VERSION 3.12.4)

if(NOT CMAKE_VERSION VERSION_LESS 3.0)
    cmake_policy(SET CMP0048 NEW)
endif()

project(GPS)

if(NOT fastcdr_FOUND)
    find_package(fastcdr REQUIRED)
endif()

if(NOT fastrtps_FOUND)
    find_package(fastrtps REQUIRED)
endif()

# SET C++11
include(CheckCXXCompilerFlag)
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANG OR
    CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    check_cxx_compiler_flag(-std=c++11 SUPPORTS_CXX11)
    if(SUPPORTS_CXX11)
        add_compile_options(-std=c++11)
        add_compile_options(-Wno-reorder)
        add_compile_options(-Wall)
        add_compile_options(-Wextra)
    else()
        message(FATAL_ERROR "Compiler doesn't support C++11")
    endif()
endif()

# message(STATUS "CONFIGURING GPS...")


add_library(topic_gps      ./idl/topic_gps.cxx
                            ./idl/topic_gpsPubSubTypes.cxx)
add_library(drv_timer       ../../driver/drv_timer/drv_timer.cpp)
add_library(drv_can         ../../driver/drv_scktCan/drv_scktCan.cpp)

add_executable(fcc_gps gps_publisher.cpp main.cpp)
target_link_libraries(fcc_gps  fastcdr
                                fastrtps
                                drv_timer
                                drv_can
                                topic_gps)