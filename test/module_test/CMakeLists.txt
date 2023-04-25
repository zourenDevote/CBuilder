add_executable(ModuleTest ModuleTest.cpp)

target_include_directories(ModuleTest
        PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(ModuleTest CBuilderLib)