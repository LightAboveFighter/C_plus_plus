cmake_minimum_required(VERSION 3.0.0)
project(fltk_classes VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()
find_package(FLTK)
# /home/alexunder/Documents/MIPT/C_plus_plus/Lessons_seminars/Seminars/fltk_graph
set(LIB_DIR /home/alexunder/Documents/MIPT/C_plus_plus/add_libraries)
set(TARGET fltk_classes)

set( HEADERS
    ${LIB_DIR}/Graph_lib/fltk.h
    ${LIB_DIR}/Graph_lib/Graph.h
    ${LIB_DIR}/Graph_lib/GUI.h
    ${LIB_DIR}/Graph_lib/Point.h
    ${LIB_DIR}/Graph_lib/Simple_window.h
    ${LIB_DIR}/Graph_lib/Window.h
    Classes.h
)

set( SOURCES
    ${LIB_DIR}/Graph_lib/Graph.cpp
    ${LIB_DIR}/Graph_lib/GUI.cpp
    ${LIB_DIR}/Graph_lib/Window.cpp
    Classes.cpp
)

set( PROGRAMS
    main.cpp
    )

add_executable(${TARGET} ${HEADERS} ${SOURCES} ${PROGRAMS})

add_compile_options(-I/usr/include/cairo -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/uuid -I/usr/include/freetype2 -I/usr/include/libpng16 -I/usr/include/uuid -I/usr/include/freetype2 -I/usr/include/libpng16 -I/usr/include/cairo -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/uuid -I/usr/include/freetype2 -I/usr/include/libpng16 -lfltk -lX11)
add_compile_options(-o -Wall -Wextra -pedantic -Og)
target_link_libraries(fltk_classes -lfltk_images -lfltk -lX11)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
