cmake_minimum_required(VERSION 3.1.0)

project(PathCAD_Lib)

set(SRC_FILES
    src/GenericPath.cpp
    src/ScaledPath.cpp
    src/LinePath.cpp
    src/PathGroup.cpp
)

set(PUBLIC_HEADERS
    include/GenericPath.h
    include/ScaledPath.h
    include/LinePath.h
    include/PathGroup.h
)

set(PRIVATE_HEADERS
    # Currently Empty
)

add_library(${PROJECT_NAME} STATIC ${SRC_FILES} ${PUBLIC_HEADERS} ${PRIVATE_HEADERS})

#target_link_libraries(${PROJECT_NAME}
#)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include
)

install(TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)

install(FILES ${PUBLIC_HEADERS}
        DESTINATION include/${PROJECT_NAME}
)
