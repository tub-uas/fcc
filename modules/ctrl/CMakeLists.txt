cmake_minimum_required(VERSION 3.12.4)

if(NOT CMAKE_VERSION VERSION_LESS 3.0)
	cmake_policy(SET CMP0048 NEW)
endif()

project(ctrl)

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

set(CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS} -latomic")

#add_compile_options(-Wall -Wextra -Werror)
add_compile_options(-Wall -Wextra)

set(IDL_PATH "idl")
set(UTIL_PATH "../../util")
set(DRIVER_PATH "../../driver")
set(ECF_LIB_PATH "../../lib/ecf")

add_library(timer ${UTIL_PATH}/timer/timer.cpp)
add_library(ecf_pid ${ECF_LIB_PATH}/ecf_pid/pid.cpp)
add_library(sigGen ${UTIL_PATH}/sigGen/sigGen.cpp)
add_library(ecf_lowpass ${ECF_LIB_PATH}/ecf_lowpass/lowpass.cpp)
add_library(ecf_highpass ${ECF_LIB_PATH}/ecf_highpass/highpass.cpp)

add_library(DataCtrl ./${IDL_PATH}/DataCtrl.cxx ./${IDL_PATH}/DataCtrlPubSubTypes.cxx)
add_library(DataRaiIn ../raiIn/${IDL_PATH}/DataRaiIn.cxx ../raiIn/${IDL_PATH}/DataRaiInPubSubTypes.cxx)
add_library(DataSFusion ../sFusion/${IDL_PATH}/DataSFusion.cxx ../sFusion/${IDL_PATH}/DataSFusionPubSubTypes.cxx)

add_executable(${PROJECT_NAME} ${PROJECT_NAME}.cpp main.cpp)
target_link_libraries(${PROJECT_NAME} fastcdr fastrtps DataCtrl DataRaiIn DataSFusion ecf_pid ecf_lowpass ecf_highpass timer sigGen)
