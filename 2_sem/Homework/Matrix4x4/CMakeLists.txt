cmake_minimum_required(VERSION 3.0.0)
project(Matrix4x4 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(Matrix4x4 main.cpp Matrix4x4.cpp Matrix4x4.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
