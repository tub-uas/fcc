cmake_minimum_required(VERSION 3.12.4)

if(NOT CMAKE_VERSION VERSION_LESS 3.0)
	cmake_policy(SET CMP0048 NEW)
endif()

project(log)

# Find requirements
if(NOT fastcdr_FOUND)
	find_package(fastcdr REQUIRED)
endif()

if(NOT fastrtps_FOUND)
	find_package(fastrtps REQUIRED)
endif()

if(NOT Boost_FOUND)
	find_package(Boost COMPONENTS system filesystem REQUIRED)
	# include_directories(${Boost_INCLUDE_DIRS})
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
set(DRIVER_PATH "../../driver")

add_library(timer ${UTIL_PATH}/timer/timer.cpp)

add_library(DataLog ./${IDL_PATH}/DataLog.cxx ./${IDL_PATH}/DataLogPubSubTypes.cxx)

###PYTHON_GEN_ADD_LIBRARY
add_library(DataAhrs ../ahrs/${IDL_PATH}/DataAhrs.cxx ../ahrs/${IDL_PATH}/DataAhrsPubSubTypes.cxx)
add_library(DataAir ../air/${IDL_PATH}/DataAir.cxx ../air/${IDL_PATH}/DataAirPubSubTypes.cxx)
add_library(DataCtrl ../ctrl/${IDL_PATH}/DataCtrl.cxx ../ctrl/${IDL_PATH}/DataCtrlPubSubTypes.cxx)
add_library(DataDownlink ../downlink/${IDL_PATH}/DataDownlink.cxx ../downlink/${IDL_PATH}/DataDownlinkPubSubTypes.cxx)
add_library(DataGps ../gps/${IDL_PATH}/DataGps.cxx ../gps/${IDL_PATH}/DataGpsPubSubTypes.cxx)
add_library(DataPsu ../psu/${IDL_PATH}/DataPsu.cxx ../psu/${IDL_PATH}/DataPsuPubSubTypes.cxx)
add_library(DataRaiIn ../raiIn/${IDL_PATH}/DataRaiIn.cxx ../raiIn/${IDL_PATH}/DataRaiInPubSubTypes.cxx)
add_library(DataRaiOut ../raiOut/${IDL_PATH}/DataRaiOut.cxx ../raiOut/${IDL_PATH}/DataRaiOutPubSubTypes.cxx)
add_library(DataSFusion ../sFusion/${IDL_PATH}/DataSFusion.cxx ../sFusion/${IDL_PATH}/DataSFusionPubSubTypes.cxx)
add_library(DataWatchdog ../watchdog/${IDL_PATH}/DataWatchdog.cxx ../watchdog/${IDL_PATH}/DataWatchdogPubSubTypes.cxx)

add_executable(${PROJECT_NAME} ${PROJECT_NAME}.cpp main.cpp)

target_link_libraries(${PROJECT_NAME} fastcdr fastrtps timer)
target_link_libraries(${PROJECT_NAME} DataLog)
target_link_libraries(${PROJECT_NAME} ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY})

###PYTHON_GEN_TARGET_LINK
target_link_libraries(${PROJECT_NAME} DataAhrs)
target_link_libraries(${PROJECT_NAME} DataAir)
target_link_libraries(${PROJECT_NAME} DataCtrl)
target_link_libraries(${PROJECT_NAME} DataDownlink)
target_link_libraries(${PROJECT_NAME} DataGps)
target_link_libraries(${PROJECT_NAME} DataPsu)
target_link_libraries(${PROJECT_NAME} DataRaiIn)
target_link_libraries(${PROJECT_NAME} DataRaiOut)
target_link_libraries(${PROJECT_NAME} DataSFusion)
target_link_libraries(${PROJECT_NAME} DataWatchdog)
