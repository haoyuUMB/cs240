add_library(cs240-lib
        src/utils.c header/utils.h
        src/comparator.c header/comparator.h
        src/resizing_array.c header/resizing_array.h
        src/linked.c header/linked.h
        src/fixed_data_types.c header/fixed_data_types.h
        src/hash_table.c header/hash_table.h
        src/bt.c header/bt.h)
target_include_directories(cs240-lib PUBLIC ./header)
add_subdirectory(client)
