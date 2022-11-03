add_library(cs240-lib
        src/utils.c header/utils.h
        src/comparator.c header/comparator.h)
target_include_directories(cs240-lib PUBLIC ./header)
add_subdirectory(client)
