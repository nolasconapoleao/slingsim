find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

# Random dots executable
set(EXECUTABLE main)
add_executable(
  ${EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/config/game-config.cpp
)
target_include_directories(
  ${EXECUTABLE}
  PRIVATE ${CMAKE_SOURCE_DIR}/src
)
target_link_libraries(${EXECUTABLE} PUBLIC ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})
