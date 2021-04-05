find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

# Game of Life executable
set(EXECUTABLE_GAME game-of-life)
add_executable(
  ${EXECUTABLE_GAME} ${CMAKE_CURRENT_SOURCE_DIR}/game-of-life/game.cpp
                     ${CMAKE_CURRENT_SOURCE_DIR}/game-of-life/GameOfLife.cpp
)
target_include_directories(
  ${EXECUTABLE_GAME}
  PRIVATE ${CMAKE_SOURCE_DIR}/src
)
target_link_libraries(${EXECUTABLE_GAME} PUBLIC ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})

# Random dots executable
set(EXECUTABLE_RANDOM random)
add_executable(${EXECUTABLE_RANDOM} ${CMAKE_CURRENT_SOURCE_DIR}/random.cpp)
target_link_libraries(${EXECUTABLE_RANDOM} PUBLIC ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})
