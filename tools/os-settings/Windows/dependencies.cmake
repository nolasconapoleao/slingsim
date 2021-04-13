# Dependencies
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

# Linking Freeglut dependency
include_directories(external/Freeglut/include)
add_subdirectory(external/Freeglut ${CMAKE_BINARY_DIR}/external/Freeglut)
link_directories("${CMAKE_BINARY_DIR}/external/Freeglut/lib")
target_link_libraries(${PROJECT_NAME} PUBLIC freeglut)
