add_library(mylib-demo
        headers/utils.h src/utils.c
        )

target_include_directories(mylib-demo PUBLIC ./headers)


add_executable(client.out client.c)
target_link_libraries(client.out mylib-demo)

add_executable(comiple_time_macto.out comiple_time_macto.c)