target_sources(
  geometry
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/transformation/misc.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/transformation/rotation.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/transformation/scale.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/transformation/translation.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/collision/border.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/collision/object.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/basic-math.cpp
)
