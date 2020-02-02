cmake_minimum_required(VERSION 3.1.0)

project(PathCAD_Lib)

add_library(${PROJECT_NAME} STATIC
    Path.cpp
    include/Path.h

    LinePath.cpp
    include/LinePath.h
)

target_link_libraries(${PROJECT_NAME}
)

target_include_directories(${PROJECT_NAME}
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include
)
