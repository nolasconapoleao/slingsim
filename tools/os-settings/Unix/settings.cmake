set(CMAKE_BINARY_DIR ${CMAKE_HOME_DIRECTORY}/build/bin)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
  message("## Compile with ccache")
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
endif(CCACHE_FOUND)

if(ENABLE_DIAGNOSTIC_TOOLS)
  message("## Enable diagnostic tools in compilation")
  include(tools/cmake/Sanitizers.cmake)
  include(tools/cmake/StaticAnalyzers.cmake)
endif()

if(ENABLE_COVERAGE)
  message("## Enable code coverage target")
  include(tools/cmake/Coverage.cmake)
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -fprofile-arcs -ftest-coverage")
endif()

if(ENABLE_DOCUMENTATION)
  message("## Enable documentation target")
  include(tools/cmake/Documentation.cmake)
endif()
