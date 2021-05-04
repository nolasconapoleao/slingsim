find_package(GLUT REQUIRED)

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} PUBLIC ${GLUT_LIBRARIES} ${GLEW_LIBRARIES})