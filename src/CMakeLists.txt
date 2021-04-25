# Project executable
target_sources(
  ${PROJECT_NAME}
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/config/simulation.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/entity/Ball.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/entity/Particle.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/entity/Planetes.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/entity/Portal.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/entity/Seesaw.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/engine/Engine.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/database/InputDb.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/database/Scene.cpp
)

target_include_directories(
  ${PROJECT_NAME}
  PRIVATE ${CMAKE_SOURCE_DIR}/external ${CMAKE_SOURCE_DIR}/src
)
