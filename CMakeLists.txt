cmake_minimum_required(VERSION 3.12)

project(pcapng_converter)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    if(NOT CMAKE_BUILD_TYPE)
      set(CMAKE_BUILD_TYPE Debug CACHE STRING
          "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
          FORCE)
    endif()
endif()

