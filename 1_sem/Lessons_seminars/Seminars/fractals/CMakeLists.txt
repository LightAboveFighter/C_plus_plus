cmake_minimum_required(VERSION 3.0.0)
project(fractals VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()
find_package(FLTK)
# /home/admin/Documents/MIPT/C_plus_plus/Lessons_seminars/Seminars/fltk_graph
set(LIB_DIR /home/alexunder/Documents/MIPT/C_plus_plus/Lessons_seminars/Seminars/fractals)
set(ADD_LIBS_DIR /home/alexunder/Documents/MIPT/C_plus_plus/add_libraries)
set(TARGET fractals)

set( HEADERS
    ${ADD_LIBS_DIR}/Graph_lib/fltk.h
    ${ADD_LIBS_DIR}/Graph_lib/Graph.h
    ${ADD_LIBS_DIR}/Graph_lib/GUI.h
    ${ADD_LIBS_DIR}/Graph_lib/Point.h
    ${ADD_LIBS_DIR}/Graph_lib/Simple_window.h
    ${ADD_LIBS_DIR}/Graph_lib/Window.h
    ${LIB_DIR}/make_fractal.h
)

set( SOURCES
    ${ADD_LIBS_DIR}/Graph_lib/Graph.cpp
    ${ADD_LIBS_DIR}/Graph_lib/GUI.cpp
    ${ADD_LIBS_DIR}/Graph_lib/Window.cpp
)

set( PROGRAMS
    ${LIB_DIR}/main.cpp
    ${LIB_DIR}/make_fractal.cpp
    )

add_executable(${TARGET} ${HEADERS} ${SOURCES} ${PROGRAMS})

add_compile_options(-I/usr/include/cairo -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/uuid -I/usr/include/freetype2 -I/usr/include/libpng16 -I/usr/include/uuid -I/usr/include/freetype2 -I/usr/include/libpng16 -I/usr/include/cairo -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/uuid -I/usr/include/freetype2 -I/usr/include/libpng16 -lfltk -lX11)
target_link_libraries(fractals -lfltk_images -lfltk -lX11)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
