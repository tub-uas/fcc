cmake_minimum_required(VERSION 3.12.4)

if(NOT CMAKE_VERSION VERSION_LESS 3.0)
    cmake_policy(SET CMP0048 NEW)
endif()

project(RC2SIN)

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


add_library(topic_rc2sin    ./idl/topic_rc2sin.cxx
                            ./idl/topic_rc2sinPubSubTypes.cxx)

add_executable(fcc_rc2sin rc2sin_publisher.cpp main.cpp  )
target_link_libraries(fcc_rc2sin    fastcdr
                                    fastrtps
                                    topic_rc2sin)