cmake_minimum_required(VERSION 3.12)
project(slingsim)

# Project executable
add_executable(${PROJECT_NAME} 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

target_include_directories(
  ${PROJECT_NAME}
  PRIVATE ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(${PROJECT_NAME}
  PUBLIC
    GL
    GLU 
    glut 
    GLEW
)
