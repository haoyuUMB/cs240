
add_executable(client main.c utils_test.c utils_test.h)
target_link_libraries(client PRIVATE cs240-lib)

add_executable(string_client string_client.c)
target_link_libraries(string_client PUBLIC cs240-lib)

add_executable(stdio_demo.out stdio_demo.c)
target_link_libraries(stdio_demo.out PUBLIC cs240-lib)