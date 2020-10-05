cmake_minimum_required(VERSION 3.12.4)

if(NOT CMAKE_VERSION VERSION_LESS 3.0)
	cmake_policy(SET CMP0048 NEW)
endif()

project(air)

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

set(IDL_PATH "idl")
set(UTIL_PATH "../../util")
set(DRIVER_PATH "../../driver")

add_library(timer ${UTIL_PATH}/timer/timer.cpp)
add_library(drv_can ${DRIVER_PATH}/drv_can/drv_can.cpp)
add_library(airCom ${UTIL_PATH}/airCom/airCom.cpp)
target_link_libraries(airCom drv_can)

add_library(DataAir ./idl/DataAir.cxx ./idl/DataAirPubSubTypes.cxx)

add_executable(${PROJECT_NAME} ${PROJECT_NAME}.cpp main.cpp)
target_link_libraries(${PROJECT_NAME} fastcdr fastrtps DataAir drv_can airCom timer)