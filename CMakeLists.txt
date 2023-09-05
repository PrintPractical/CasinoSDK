cmake_minimum_required (VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project (CasinoSDK
         VERSION 0.0.1
         DESCRIPTION "An SDK which provides utilities for simulating casino games and strategies."
         LANGUAGES CXX)

find_package(GTest REQUIRED)

add_subdirectory (src)
add_subdirectory (test)