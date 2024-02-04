cmake_minimum_required(VERSION 3.0.0)
project(14.10.23_Logic_schemes VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(14.10.23_Logic_schemes main.cpp logic_elements.h logic_elements.cpp scheme.cpp scheme.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
