target_sources(
  geometry
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/transformation/misc.h
         ${CMAKE_CURRENT_SOURCE_DIR}/transformation/rotation.h
         ${CMAKE_CURRENT_SOURCE_DIR}/transformation/scale.h
         ${CMAKE_CURRENT_SOURCE_DIR}/transformation/translation.h
         ${CMAKE_CURRENT_SOURCE_DIR}/collision/border.h
         ${CMAKE_CURRENT_SOURCE_DIR}/collision/object.h
         ${CMAKE_CURRENT_SOURCE_DIR}/basic-math.h
         ${CMAKE_CURRENT_SOURCE_DIR}/types.h
)
