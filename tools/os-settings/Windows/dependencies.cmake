##Freeglut
set(FETCHCONTENT_BASE_DIR
    "${CMAKE_BINARY_DIR}/external/Freeglut"
    CACHE STRING "Overrides FETCHCONTENT_BASE_DIR variable"
)
include(FetchContent)
FetchContent_Declare(
  Freeglut
  SOURCE_DIR "${CMAKE_HOME_DIRECTORY}/external/Freeglut"
  SVN_REPOSITORY "http://svn.code.sf.net/p/freeglut/code/trunk/freeglut/freeglut"
)

FetchContent_GetProperties(Freeglut POPULATED FREEGLUT_POPULATED)
if(NOT FREEGLUT_POPULATED)
  FetchContent_Populate(Freeglut)
endif()

include_directories(external/Freeglut/include)
add_subdirectory(external/Freeglut ${CMAKE_BINARY_DIR}/external/Freeglut)
link_directories("${CMAKE_BINARY_DIR}/external/Freeglut/lib")
target_link_libraries(${PROJECT_NAME} PUBLIC freeglut)

## GLEW
add_subdirectory(external/glew ${CMAKE_BINARY_DIR}/external/glew)
include_directories(external/glew/include)
link_directories("${CMAKE_BINARY_DIR}/external/glew/lib")
target_link_libraries(${PROJECT_NAME} PUBLIC libglew_shared)

## GLM
set(FETCHCONTENT_BASE_DIR
    "${CMAKE_BINARY_DIR}/external/Glm"
    CACHE STRING "Overrides FETCHCONTENT_BASE_DIR variable"
)
include(FetchContent)
FetchContent_Declare(
  Glm
  SOURCE_DIR "${CMAKE_HOME_DIRECTORY}/external/Glm"
  GIT_REPOSITORY "https://github.com/g-truc/glm.git"
)

FetchContent_GetProperties(Glm POPULATED FREEGLUT_POPULATED)
if(NOT FREEGLUT_POPULATED)
  FetchContent_Populate(Glm)
endif()

include_directories(external/Glm)