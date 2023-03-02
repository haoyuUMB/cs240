
set(CMAKE_CXX_STANDARD 14)
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()
include(GoogleTest)


set(CUR ${CMAKE_CURRENT_SOURCE_DIR})
file(GLOB_RECURSE files CONFIGURE_DEPENDS RELATIVE ${CUR} *.c *.cpp)
foreach (file IN LISTS files)
    STRING(REPLACE "/" "_" LIB_NAME ${file})
    STRING(REPLACE ".cpp" ".out" LIB_NAME ${LIB_NAME})
    message(STATUS ${LIB_NAME} ${file})
    add_executable(${LIB_NAME} ${file})
    target_link_libraries(${LIB_NAME} GTest::gtest_main)
    target_link_libraries(${LIB_NAME} cs240-lib)
    gtest_discover_tests(${LIB_NAME})
endforeach (file)
