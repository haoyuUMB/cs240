file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.c include/*.h)
add_library(cs240-lib ${srcs})
set_target_properties(cs240-lib PROPERTIES LINKER_LANGUAGE C)
target_include_directories(cs240-lib PUBLIC include)