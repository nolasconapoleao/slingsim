cmake_minimum_required(VERSION 3.12)
project(slingsim)

# Operating system specific settings
set(CMAKE_CXX_STANDARD 20)

# Advanced compilation options
option(ENABLE_TESTS "Compile and run unit tests" ON)
option(ENABLE_DOCUMENTATION "Build documentation target" OFF)
option(ENABLE_COVERAGE "Build coverage target" OFF)
option(ENABLE_DIAGNOSTIC_TOOLS "Build with diagnostic tools" OFF)

# Main target creation
add_executable(${PROJECT_NAME})

include(tools/cmake/Libs.cmake)

if(UNIX)
  message("## Compile for unix operating system")
  include(tools/os-settings/Unix/settings.cmake)
  include(tools/os-settings/Unix/dependencies.cmake)
elseif(WIN32)
  message("## Compile for windows operating system")
  include(tools/os-settings/Windows/settings.cmake)
  include(tools/os-settings/Windows/dependencies.cmake)
endif()

add_subdirectory(libs)
add_subdirectory(src)

# Link project libraries
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC ${OPENGL_LIBRARIES} Graphics::graphics2d Input::input)

if(ENABLE_TESTS)
  message("## Enable unit tests target")
  include(tools/cmake/Tests.cmake)
  enable_testing()
  add_subdirectory(tests)
endif()

# Copying the dependent binaries to the BIN folder
if(WIN32)
  add_custom_target(Copyall ALL DEPENDS "${CMAKE_BINARY_DIR}/Dependencies")

  add_custom_command(
    OUTPUT "${CMAKE_BINARY_DIR}/Dependencies"
    COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:freeglut>"
            "${CMAKE_BINARY_DIR}/bin/$<TARGET_FILE_NAME:freeglut>"
    COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:slingsim>"
            "${CMAKE_BINARY_DIR}/bin/$<TARGET_FILE_NAME:slingsim>"
    DEPENDS freeglut slingsim
    VERBATIM
  )
endif()
