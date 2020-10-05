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

add_library(dataAhrs  ../ahrs/idl/DataAhrs.cxx
                        ../ahrs/idl/DataAhrsPubSubTypes.cxx)
add_library(dataAir   ../air/idl/DataAir.cxx
                        ../air/idl/DataAirPubSubTypes.cxx)
#add_library(topic_gps   ../gps/idl/topic_gps.cxx
#                        ../gps/idl/topic_gpsPubSubTypes.cxx)
add_library(dataCtrl  ../ctrl/idl/DataCtrl.cxx
                        ../ctrl/idl/DataCtrlPubSubTypes.cxx)
add_library(dataRaiIn    ../raiIn/idl/DataRaiIn.cxx
                            ../raiIn/idl/DataRaiInPubSubTypes.cxx)
add_library(dataRaiOut   ../raiOut/idl/DataRaiOut.cxx
                            ../raiOut/idl/DataRaiOutPubSubTypes.cxx)
add_library(dataSFusion  ../sFusion/idl/DataSFusion.cxx
                        ../sFusion/idl/DataSFusionPubSubTypes.cxx)
add_library(serial  ../../driver/drv_serial/drv_serial.cpp)
add_library(timer   ../../util/timer/timer.cpp)


add_executable(fcc_downlink downlink.cpp main.cpp  )
target_link_libraries(fcc_downlink  fastcdr
                                fastrtps
                                dataAhrs
                                dataAir
                                dataCtrl
                                dataRaiIn
                                dataRaiOut
                                dataSFusion
                                serial
                                timer)