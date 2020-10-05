cmake_minimum_required(VERSION 3.12.4)

if(NOT CMAKE_VERSION VERSION_LESS 3.0)
    cmake_policy(SET CMP0048 NEW)
endif()

project(DOWNLINK)

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

# message(STATUS "CONFIGURING DOWNLINK...")

add_library(topic_ahrs  ../ahrs/idl/topic_ahrs.cxx
                        ../ahrs/idl/topic_ahrsPubSubTypes.cxx)
add_library(topic_air   ../air/idl/topic_air.cxx
                        ../air/idl/topic_airPubSubTypes.cxx)
add_library(topic_gps   ../gps/idl/topic_gps.cxx
                        ../gps/idl/topic_gpsPubSubTypes.cxx)
add_library(topic_ctrl  ../ctrl/idl/topic_ctrl.cxx
                        ../ctrl/idl/topic_ctrlPubSubTypes.cxx)
add_library(topic_mainin    ../mainin/idl/topic_mainin.cxx
                            ../mainin/idl/topic_maininPubSubTypes.cxx)
add_library(topic_mainout   ../mainout/idl/topic_mainout.cxx
                            ../mainout/idl/topic_mainoutPubSubTypes.cxx)
add_library(topic_sfusion  ../sfusion/idl/topic_sfusion.cxx
                        ../sfusion/idl/topic_sfusionPubSubTypes.cxx)
add_library(drv_serial  ../../driver/drv_serial/drv_serial.cpp)
add_library(drv_timer   ../../driver/drv_timer/drv_timer.cpp)


add_executable(fcc_downlink downlink_subscriber.cpp main.cpp  )
target_link_libraries(fcc_downlink  fastcdr
                                fastrtps
                                topic_ahrs
                                topic_air
                                topic_gps
                                topic_ctrl
                                topic_mainin
                                topic_mainout
                                topic_sfusion
                                drv_serial
                                drv_timer)