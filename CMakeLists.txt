if (POLICY CMP0048)
    cmake_policy(SET CMP0048 NEW)
endif (POLICY CMP0048)

project(cs240 LANGUAGES C CXX)
cmake_minimum_required(VERSION 3.16)

add_subdirectory(src/lib)
add_subdirectory(src/clients)
add_subdirectory(tests)

add_subdirectory(assignments)