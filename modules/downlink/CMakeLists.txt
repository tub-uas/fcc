cmake_minimum_required(VERSION 3.12.4)

if(NOT CMAKE_VERSION VERSION_LESS 3.0)
	cmake_policy(SET CMP0048 NEW)
endif()

project(downlink)

# Find requirements
if(NOT fastcdr_FOUND)
	find_package(fastcdr REQUIRED)
endif()

if(NOT fastrtps_FOUND)
	find_package(fastrtps REQUIRED)
endif()

# Set C++11
include(CheckCXXCompilerFlag)
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANG OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	check_cxx_compiler_flag(-std=c++11 SUPPORTS_CXX11)
	if(SUPPORTS_CXX11)
		add_compile_options(-std=c++11)
	else()
		message(FATAL_ERROR "Compiler doesn't support C++11")
	endif()
endif()

message(STATUS "Configuring ${PROJECT_NAME}")

add_compile_options(-Wall -Wextra -Werror)

set(UTIL_PATH "../../util")
set(DRIVER_PATH "../../driver")

add_library(timer ${UTIL_PATH}/timer/timer.cpp)
add_library(serial ${DRIVER_PATH}/drv_serial/drv_serial.cpp)

add_library(DataRaiIn ../raiIn/idl/DataRaiIn.cxx ../raiIn/idl/DataRaiInPubSubTypes.cxx)
add_library(DataRaiOut ../raiOut/idl/DataRaiOut.cxx ../raiOut/idl/DataRaiOutPubSubTypes.cxx)
add_library(DataSFusion ../sFusion/idl/DataSFusion.cxx ../sFusion/idl/DataSFusionPubSubTypes.cxx)
add_library(DataAhrs ../ahrs/idl/DataAhrs.cxx ../ahrs/idl/DataAhrsPubSubTypes.cxx)
add_library(DataAir ../air/idl/DataAir.cxx ../air/idl/DataAirPubSubTypes.cxx)
add_library(DataPsu ../psu/idl/DataPsu.cxx ../psu/idl/DataPsuPubSubTypes.cxx)
add_library(DataCtrl ../ctrl/idl/DataCtrl.cxx ../ctrl/idl/DataCtrlPubSubTypes.cxx)

add_executable(${PROJECT_NAME} ${PROJECT_NAME}.cpp main.cpp)

target_link_libraries(${PROJECT_NAME} fastcdr fastrtps timer serial)
target_link_libraries(${PROJECT_NAME} DataRaiIn)
target_link_libraries(${PROJECT_NAME} DataRaiOut)
target_link_libraries(${PROJECT_NAME} DataSFusion)
target_link_libraries(${PROJECT_NAME} DataAhrs)
target_link_libraries(${PROJECT_NAME} DataAir)
target_link_libraries(${PROJECT_NAME} DataPsu)
target_link_libraries(${PROJECT_NAME} DataCtrl)
