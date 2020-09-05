cmake_minimum_required (VERSION 2.6)
project (Tutorial02)

# The version number.
set (Tutorial02_VERSION_MAJOR 1)
set (Tutorial02_VERSION_MINOR 0)

# should we use our own math functions
option(USE_MYMATH "Use tutorial provided math implementation" ON)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/Tutorial02Config.h.in"
  "${PROJECT_BINARY_DIR}/Tutorial02Config.h"
  )

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories ("${PROJECT_BINARY_DIR}")

# add the MathFunctions library?
if (USE_MYMATH)
  include_directories ("${PROJECT_SOURCE_DIR}/Math")
  add_subdirectory (Math)
  set (EXTRA_LIBS ${EXTRA_LIBS} Math)
endif ()

# add the executable
add_executable (Tutorial02 Tutorial02.cxx)
target_link_libraries (Tutorial02  ${EXTRA_LIBS})
