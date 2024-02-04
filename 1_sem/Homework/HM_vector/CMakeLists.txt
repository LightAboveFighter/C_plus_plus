cmake_minimum_required(VERSION 3.0.0)
project(hm_vector VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(hm_vector main.cpp vector.h vector.cpp actual2.h actual.cpp)

add_compile_options( -Wall -Wextra -pedantic -Og -o)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
