cmake_minimum_required(VERSION 3.20)

project(lt-test)

set(CMAKE_CXX_STANDARD 20)

add_executable(main main.cpp)

set_target_properties(main PROPERTIES OUTPUT_NAME "fincalc")