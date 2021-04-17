# Test 1
set(EXECUTABLE_NAME unit_Collision)
add_executable(${EXECUTABLE_NAME} unit_Collision.cpp)

create_test(${EXECUTABLE_NAME})

target_link_libraries(${EXECUTABLE_NAME} PUBLIC Geometry::geometry)

# Test 2
set(EXECUTABLE_NAME unit_Transformation)
add_executable(${EXECUTABLE_NAME} unit_Transformation.cpp)

create_test(${EXECUTABLE_NAME})

target_link_libraries(${EXECUTABLE_NAME} PUBLIC Geometry::geometry)

# Test 3
set(EXECUTABLE_NAME unit_basicmath)
add_executable(${EXECUTABLE_NAME} unit_basicmath.cpp)

create_test(${EXECUTABLE_NAME})

target_link_libraries(${EXECUTABLE_NAME} PUBLIC Geometry::geometry)
