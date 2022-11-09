add_library(cs240-lib
        src/utils.c header/utils.h
        src/comparator.c header/comparator.h
        src/resizing_array.c header/resizing_array.h
        src/list.c header/list.h
        src/fixed_data_types.c header/fixed_data_types.h
        )
target_include_directories(cs240-lib PUBLIC ./header)
add_subdirectory(client)
