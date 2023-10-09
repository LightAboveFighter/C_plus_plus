cmake_minimum_required(VERSION 3.0.0)
project(25.09-02.09_calculator VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(25.09-02.09_calculator Lesson_25.09.23_04.cpp bitwice.cpp bitwice.h Token.h Token.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
