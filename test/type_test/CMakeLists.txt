
add_executable(TypeTest TypeTest.cpp)

target_include_directories(TypeTest
        PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(TypeTest CBuilderLib)
