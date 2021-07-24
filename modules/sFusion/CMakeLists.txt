cmake_minimum_required(VERSION 3.12.4)

if(NOT CMAKE_VERSION VERSION_LESS 3.0)
	cmake_policy(SET CMP0048 NEW)
endif()

project(sFusion)

# Find requirements
if(NOT fastcdr_FOUND)
	find_package(fastcdr REQUIRED)
endif()

if(NOT foonathan_memory_FOUND)
    find_package(foonathan_memory REQUIRED)
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


include_directories(/usr/local/lib)
include_directories(/usr/local/include)
add_library(DataAhrs ../ahrs/${IDL_PATH}/DataAhrs.cxx ../ahrs/${IDL_PATH}/DataAhrsPubSubTypes.cxx)
add_library(DataAir ../air/${IDL_PATH}/DataAir.cxx ../air/${IDL_PATH}/DataAirPubSubTypes.cxx)
add_library(DataSFusion ./${IDL_PATH}/DataSFusion.cxx ./${IDL_PATH}/DataSFusionPubSubTypes.cxx)
# add_library(DataGps ../gps/${IDL_PATH}/DataGps.cxx ../gps/${IDL_PATH}/DataGpsPubSubTypes.cxx)

add_executable(${PROJECT_NAME} ${PROJECT_NAME}.cpp main.cpp)
target_link_libraries(${PROJECT_NAME} fastrtps fastcdr foonathan_memory DataSFusion DataAhrs DataAir timer)

# target_link_options(${PROJECT_NAME} PRIVATE "-latomic")
# target_link_libraries(${PROJECT_NAME} fastcdr fastrtps DataSFusion DataAhrs
#                                       DataAir DataGps drv_can raiCom timer)
