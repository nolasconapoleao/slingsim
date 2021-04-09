# Project executable
target_sources(
  ${PROJECT_NAME}
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp ${CMAKE_CURRENT_SOURCE_DIR}/config/game-config.cpp
)

target_include_directories(
  ${PROJECT_NAME}
  PRIVATE ${CMAKE_SOURCE_DIR}/external ${CMAKE_SOURCE_DIR}/src
)
