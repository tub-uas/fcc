cmake_minimum_required(VERSION 3.12.4)

if(NOT CMAKE_VERSION VERSION_LESS 3.0)
	cmake_policy(SET CMP0048 NEW)
endif()

project(raiOut)

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

set(CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS} -latomic")

message(STATUS "Configuring ${PROJECT_NAME}")

add_compile_options(-Wall -Wextra -Werror)

set(IDL_PATH "idl")
set(UTIL_PATH "../../util")
if(SITL)
	message(STATUS "--> SITL in use! ")
	add_definitions(-DSITL)
	message(STATUS "--> IP Address ... ${IP} ")
	add_definitions(-DIP="${IP}")
	set(UDP_PATH "../../../udp_util")
	set(SITL_COM_PATH "../../../")
else()
	set(DRIVER_PATH "../../driver")
endif()

add_library(timer ${UTIL_PATH}/timer/timer.cpp)

if(SITL)
	add_library(drv_can ${UDP_PATH}/util_udp.cpp)
	add_library(raiCom ${SITL_COM_PATH}/raiComSitl/raiComSitl.cpp)
else()
	add_library(drv_can ${DRIVER_PATH}/drv_can/drv_can.cpp)
	add_library(raiCom ${UTIL_PATH}/raiCom/raiCom.cpp)
endif()
add_library(mixer ${UTIL_PATH}/mixer/mixer.cpp)
target_link_libraries(raiCom drv_can)

add_library(DataRaiOut ./${IDL_PATH}/DataRaiOut.cxx ./${IDL_PATH}/DataRaiOutPubSubTypes.cxx)
add_library(DataCtrl ../ctrl/${IDL_PATH}/DataCtrl.cxx ../ctrl/${IDL_PATH}/DataCtrlPubSubTypes.cxx)

add_executable(${PROJECT_NAME} ${PROJECT_NAME}.cpp main.cpp)
target_link_libraries(${PROJECT_NAME} fastcdr fastrtps DataRaiOut DataCtrl drv_can raiCom timer mixer)
