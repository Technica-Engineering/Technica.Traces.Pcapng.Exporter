cmake_minimum_required(VERSION 3.12)

project(pcapng_exporter)

add_library(pcapng_exporter
    STATIC
    "mapping.cpp"
    "pcapng_exporter.cpp"
)
target_include_directories(pcapng_exporter 
    PUBLIC
    "include"
)
target_link_libraries(pcapng_exporter
    PUBLIC
    light_pcapng
    PRIVATE
    nlohmann_json
)
target_compile_features(pcapng_exporter PUBLIC cxx_std_17)


if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    if(NOT CMAKE_BUILD_TYPE)
      set(CMAKE_BUILD_TYPE Debug CACHE STRING
          "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
          FORCE)
    endif()
endif()

# Configuration

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
include(cmake/pcapng.cmake)
include(cmake/json.cmake)


