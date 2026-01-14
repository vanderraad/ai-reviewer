cmake_minimum_required(VERSION 3.15)

# Use a modern C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER g++)

project(ai-reviewer VERSION 0.1 LANGUAGES CXX)

# Print compiler info and recommend / validate GCC toolchain
message(STATUS "C++ compiler: ${CMAKE_CXX_COMPILER_ID} (${CMAKE_CXX_COMPILER})")

# Collect all .cpp files under src/ (recursively). CONFIGURE_DEPENDS makes
# CMake re-scan the directory when files are added/removed (CMake >= 3.12).
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.cpp")

if(NOT SOURCES)
  message(FATAL_ERROR "No source files found in ${CMAKE_SOURCE_DIR}/src")
endif()

# Create an executable with the project name and all sources
add_executable(${PROJECT_NAME} ${SOURCES})

# Ensure the project can find headers in src/
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/src")

# Ensure C++17 features are available
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

# Optional: install rule
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

# Helpful message on how to build
message(STATUS "Project: ${PROJECT_NAME}")
message(STATUS "Sources (${SOURCES})")
message(STATUS "Configure with: mkdir build && cmake -S . -B build && cmake --build build --config Release")
