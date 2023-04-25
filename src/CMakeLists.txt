
add_library(CBuilderLib
        CBType.cpp
        CModule.cpp
        CSymbolTable.cpp
        CValue.cpp)

target_include_directories(CBuilderLib
        PUBLIC ${PROJECT_SOURCE_DIR}/include)




