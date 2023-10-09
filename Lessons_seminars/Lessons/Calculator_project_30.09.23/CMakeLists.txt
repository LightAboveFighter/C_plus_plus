cmake_minimum_required(VERSION 3.0.0)
project(Calculator_project_30.09.23 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(Calculator_project_30.09.23 
                Lesson_30.09.23_calculator.cpp 
                Token.cpp 
                Token.h
                std_lib_facilities.h
                )
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
