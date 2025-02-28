# CMakeLists.txt
cmake_minimum_required(VERSION 3.16)

project(o_kurwa_CURSACH)

# Specify the C++ standard.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the output directories for built binaries and libraries.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

# Include directories.
include_directories(
    "${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_SOURCE_DIR}/external/SDL3/include/SDL3"
    "${PROJECT_SOURCE_DIR}/external/SDL3_ttf/include/SDL3"
)

# Link directories.
link_directories(
    "${PROJECT_SOURCE_DIR}/external/SDL3/lib"
    "${PROJECT_SOURCE_DIR}/external/SDL3_ttf/lib"
)

# Add the executable target.
add_executable(o_kurwa_CURSACH
    src/main.cpp
    src/Game.cpp
    src/Player.cpp
    src/Enemy.cpp
    src/Map.cpp
    src/Menu.cpp
    src/Utilities.cpp
)

# Link SDL3 and SDL3_ttf libraries.
target_link_libraries(o_kurwa_CURSACH PRIVATE SDL3 SDL3_ttf)

# For Windows: Define main as SDL_main.
if (WIN32)
    target_compile_definitions(o_kurwa_CURSACH PRIVATE -DSDL_MAIN_HANDLED)
endif()
