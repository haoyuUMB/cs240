
add_library(
        cs240-lib
        src/Integer.c headers/Integer.h
        src/ArrayList.c headers/ArrayList.h
        src/utils.c headers/utils.h
        src/string/substring.c headers/substring.h
        src/ArrayQueue.c headers/ArrayStack.h
)

target_include_directories(cs240-lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(clients)