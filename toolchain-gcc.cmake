# DEPRECATED: GCC toolchain configuration moved into CMakeLists.txt
# The project now supports configuring GCC via -DGCC_PATH=<path> or by setting
# CMAKE_CXX_COMPILER before configuration. Keep or remove this file as you prefer.
message(WARNING "Deprecated: toolchain-gcc.cmake moved into CMakeLists.txt — prefer -DGCC_PATH=<path> or set CMAKE_CXX_COMPILER before configuration.")
