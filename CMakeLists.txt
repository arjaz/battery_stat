cmake_minimum_required(VERSION 3.0.0)

project(battery_stat)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(tool_dest, "bin")

add_executable(
    ${PROJECT_NAME}
    src/BatStat.cpp
    src/options.cpp
    src/main.cpp
)

add_custom_command(TARGET ${PROJECT_NAME}
    PRE_BUILD
    COMMAND ${CMAKE_COMMAND}
    -Dlocal_dir="${CMAKE_CURRENT_SOURCE_DIR}"
    -Doutput_dir="${CMAKE_CURRENT_BINARY_DIR}"
    -P "${CMAKE_CURRENT_SOURCE_DIR}/cmake/gitversion.cmake"
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_BINARY_DIR})

install(TARGETS ${PROJECT_NAME} DESTINATION "bin")
