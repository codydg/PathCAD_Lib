cmake_minimum_required(VERSION 3.1.0)

project(PathCAD_Lib)

add_library(${PROJECT_NAME} STATIC
    GenericPath.cpp
    include/GenericPath.h

    ScaledPath.cpp
    include/ScaledPath.h

    LinePath.cpp
    include/LinePath.h

    PathGroup.cpp
    include/PathGroup.h
)

#target_link_libraries(${PROJECT_NAME}
#)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include
)
