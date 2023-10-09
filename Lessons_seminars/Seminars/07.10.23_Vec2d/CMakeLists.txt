cmake_minimum_required(VERSION 3.0.0)
project(07.10.23_Vec2d VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(07.10.23_Vec2d 07.10.23_Vec2d.cpp Vec2d.cpp Vec2d.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
