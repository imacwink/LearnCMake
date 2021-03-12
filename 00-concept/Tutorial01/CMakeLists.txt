cmake_minimum_required (VERSION 2.6)
project (Tutorial01)

# The version number.
 set (Tutorial01_VERSION_MAJOR 1)
 set (Tutorial01_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings
# to the source code
 configure_file (
   "${PROJECT_SOURCE_DIR}/Tutorial01Config.h.in"
   "${PROJECT_BINARY_DIR}/Tutorial01Config.h"
   )

# add the binary tree to the search path for include files
# so that we will find Tutorial01Config.h
include_directories("${PROJECT_BINARY_DIR}")

# add the executable
add_executable(Tutorial01 Tutorial01.cxx)
