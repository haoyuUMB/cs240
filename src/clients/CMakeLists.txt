set(CUR ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE files CONFIGURE_DEPENDS RELATIVE ${CUR} *.c *.cpp)
foreach (file IN LISTS files)
    #    message(${file})
    STRING(REPLACE "/" "_" LIB_NAME ${file})
    STRING(REPLACE ".c" ".out" LIB_NAME ${LIB_NAME})
    #    message(STATUS ${LIB_NAME})
    add_executable(${LIB_NAME} ${file})
    target_link_libraries(${LIB_NAME} cs240-lib)
endforeach (file)

