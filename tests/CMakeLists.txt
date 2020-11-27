cmake_minimum_required(VERSION 3.12.4)

if(NOT CMAKE_VERSION VERSION_LESS 3.0)
	cmake_policy(SET CMP0048 NEW)
endif()

project(main_test)

# Find requirements
if(NOT fastcdr_FOUND)
	find_package(fastcdr REQUIRED)
endif()

if(NOT fastrtps_FOUND)
	find_package(fastrtps REQUIRED)
endif()

if(NOT Boost_FOUND)
	find_package(Boost COMPONENTS system filesystem REQUIRED)
endif()

enable_testing()
find_package(GTest REQUIRED)

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

set(MODULES_PATH "../modules")
set(IDL_PATH "idl")
set(UTIL_PATH "../util")
set(DRIVER_PATH "../driver")

# Add / include stuff to test
add_library(pid ${UTIL_PATH}/pid/pid.cpp)

#  Add / include helpers and types used by the modules
add_library(DataLog ${MODULES_PATH}/log/${IDL_PATH}/DataLog.cxx ${MODULES_PATH}/log/${IDL_PATH}/DataLogPubSubTypes.cxx)
add_library(DataAhrs ${MODULES_PATH}/ahrs/${IDL_PATH}/DataAhrs.cxx ${MODULES_PATH}/ahrs/${IDL_PATH}/DataAhrsPubSubTypes.cxx)
add_library(DataAir ${MODULES_PATH}/air/${IDL_PATH}/DataAir.cxx ${MODULES_PATH}/air/${IDL_PATH}/DataAirPubSubTypes.cxx)
add_library(DataCtrl ${MODULES_PATH}/ctrl/${IDL_PATH}/DataCtrl.cxx ${MODULES_PATH}/ctrl/${IDL_PATH}/DataCtrlPubSubTypes.cxx)
add_library(DataDownlink ${MODULES_PATH}/downlink/${IDL_PATH}/DataDownlink.cxx ${MODULES_PATH}/downlink/${IDL_PATH}/DataDownlinkPubSubTypes.cxx)
add_library(DataGps ${MODULES_PATH}/gps/${IDL_PATH}/DataGps.cxx ${MODULES_PATH}/gps/${IDL_PATH}/DataGpsPubSubTypes.cxx)
add_library(DataPsu ${MODULES_PATH}/psu/${IDL_PATH}/DataPsu.cxx ${MODULES_PATH}/psu/${IDL_PATH}/DataPsuPubSubTypes.cxx)
add_library(DataRaiIn ${MODULES_PATH}/raiIn/${IDL_PATH}/DataRaiIn.cxx ${MODULES_PATH}/raiIn/${IDL_PATH}/DataRaiInPubSubTypes.cxx)
add_library(DataRaiOut ${MODULES_PATH}/raiOut/${IDL_PATH}/DataRaiOut.cxx ${MODULES_PATH}/raiOut/${IDL_PATH}/DataRaiOutPubSubTypes.cxx)
add_library(DataSFusion ${MODULES_PATH}/sFusion/${IDL_PATH}/DataSFusion.cxx ${MODULES_PATH}/sFusion/${IDL_PATH}/DataSFusionPubSubTypes.cxx)
add_library(DataWatchdog ${MODULES_PATH}/watchdog/${IDL_PATH}/DataWatchdog.cxx ${MODULES_PATH}/watchdog/${IDL_PATH}/DataWatchdogPubSubTypes.cxx)

# Inlcude Gtest
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${PROJECT_NAME}.cpp)

# Files that include your tests
target_sources(${PROJECT_NAME} PRIVATE util/pid_test.cpp)

# Link against some libraries that are needed
target_link_libraries(${PROJECT_NAME} fastcdr fastrtps)
target_link_libraries(${PROJECT_NAME} ${GTEST_BOTH_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY})

# Link against stuff to test
target_link_libraries(${PROJECT_NAME} pid)

# Link against helpers and types used by the modules
target_link_libraries(${PROJECT_NAME} DataLog)
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
