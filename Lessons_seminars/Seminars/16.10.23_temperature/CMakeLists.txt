cmake_minimum_required(VERSION 3.0.0)
project(16.10.23_temperature VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(16.10.23_temperature main.cpp randtemp.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
