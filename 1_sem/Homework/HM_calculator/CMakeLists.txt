cmake_minimum_required(VERSION 3.0.0)
project(HM_calculator VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(HM_calculator main.cpp ierarchy.cpp token.cpp variables.cpp input_stream.cpp)

# target_compile_definitions(${target} PRIVATE RESOURCES_DIR=\${CMAKE_SOURCE_DIR})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
