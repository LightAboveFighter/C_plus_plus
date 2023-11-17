cmake_minimum_required(VERSION 3.27.6)
set(TARGET FLTK_GRAPH )

set(FLTK_DIR D:/MIPT/C_plus-plus/add_libraries/fltk-1.3.8/CMake)

find_package(FLTK 1.3.8 EXACT REQUIRED)
find_package(OpenGL REQUIRED)

set(LIB_DIR ${CMAKE_CURRENT_PROJECT_PATH})

project(${TARGET})

set( HEADERS
    ${LIB_DIR}/Graph_lib/fltk.h
    ${LIB_DIR}/Graph_lib/Graph.h
    ${LIB_DIR}/Graph_lib/GUI.h
    ${LIB_DIR}/Graph_lib/Point.h
    ${LIB_DIR}/Graph_lib/Simple_window.h
    ${LIB_DIR}/Graph_lib/Window.h
)

set( SOURCES
    ${LIB_DIR}/Graph_lib/Graph.cpp
    ${LIB_DIR}/Graph_lib/GUI.cpp
    ${LIB_DIR}/Graph_lib/Window.cpp
)

add_executable(${TARGET} ${SOURCES} S{HEADERS} )
